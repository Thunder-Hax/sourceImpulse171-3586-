#include "stdafx.h"
#pragma warning(disable:4191) //Fuck FARPROC casting

vector<Memory::UNLINKED_MODULE> Memory::m_unlinkedModules;

void Memory::RelinkModuleToPEB(HMODULE hModule) {
	auto it = find_if(m_unlinkedModules.begin(), m_unlinkedModules.end(), FindModuleHandle(hModule));

	if (it == m_unlinkedModules.end()) {
		LOG_DEBUG("[Memory] Module not unlinked yet!");
		return;
	}

	RELINK((*it).Entry->InLoadOrderLinks, (*it).RealInLoadOrderLinks);
	RELINK((*it).Entry->InInitializationOrderLinks, (*it).RealInInitializationOrderLinks);
	RELINK((*it).Entry->InMemoryOrderLinks, (*it).RealInMemoryOrderLinks);
	m_unlinkedModules.erase(it);
}

Status Memory::UnlinkModuleFromPEB(HMODULE hModule) {
	auto it = find_if(m_unlinkedModules.begin(), m_unlinkedModules.end(), FindModuleHandle(hModule));
	if (it != m_unlinkedModules.end()) {
		LOG_WARN("[Memory] Module already unlinked");
		return STATUS_UNKNOWN;
	}
	PPEB pPEB = (PPEB)__readgsqword(0x60);

	PLIST_ENTRY CurrentEntry = pPEB->Ldr->InLoadOrderModuleList.Flink;
	PLDR_DATA_TABLE_ENTRY Current = NULL;

	while (CurrentEntry != &pPEB->Ldr->InLoadOrderModuleList && CurrentEntry != NULL) {

		Current = CONTAINING_RECORD(CurrentEntry, LDR_DATA_TABLE_ENTRY, InLoadOrderLinks);

		if (Current->DllBase == hModule) {

			UNLINKED_MODULE CurrentModule = { 0 };
			CurrentModule.hModule = hModule;
			CurrentModule.RealInLoadOrderLinks = Current->InLoadOrderLinks.Blink->Flink;
			CurrentModule.RealInInitializationOrderLinks = Current->InInitializationOrderLinks.Blink->Flink;
			CurrentModule.RealInMemoryOrderLinks = Current->InMemoryOrderLinks.Blink->Flink;
			CurrentModule.Entry = Current;
			m_unlinkedModules.push_back(CurrentModule);

			UNLINK(Current->InLoadOrderLinks);
			UNLINK(Current->InInitializationOrderLinks);
			UNLINK(Current->InMemoryOrderLinks);

			break;
		}
		CurrentEntry = CurrentEntry->Flink;
	}
	return STATUS_SUCCESS;
}

static std::map<HMODULE, BYTE[0x1000]> originalHeaderBytes;
void Memory::FakePeHeader(HMODULE hModule) {
	void * pKernel32 = reinterpret_cast<void*>(GetModuleHandleA("kernel32.dll"));
	DWORD dwOriginal = 0;
	HANDLE proc = GetCurrentProcess();
	VirtualProtectEx(proc, hModule, 0x1000, PAGE_EXECUTE_READWRITE, &dwOriginal);
	uint8_t wot[0x1000];
	memcpy(&wot[0], hModule, 0x1000);
	for(auto i = 0; i < 0x1000; i++) {
		wot[i] ^= 0x69;
	}
	WriteProcessMemory(proc, hModule, pKernel32, 0x1000, nullptr);
	VirtualProtectEx(proc, hModule, 0x1000, dwOriginal, &dwOriginal);
}

void Memory::RestorePeHeaders() {
	for(auto& mod : originalHeaderBytes) {
		uint8_t dexor[0x1000];
		for(auto i = 0; i < 0x1000; i++) {
			dexor[i] = mod.second[i] ^ 0x69;
		}

		memcpy(mod.first, dexor, 0x1000);
	}
}


bool Memory::IsScanInOurMemory(uint64_t baseScan, uint64_t endScan, uint64_t moduleBase, uint64_t moduleEnd) {
	return Utils::Within(baseScan, moduleBase, moduleEnd) || Utils::Within(endScan, moduleBase, moduleEnd);
	//return (baseScan >= moduleBase && baseScan <= moduleEnd) || (endScan >= moduleBase && endScan <= moduleEnd);
}

String Memory::BuildStackTrace() {
	string s("[");
	CaptureStackBackTraceType func = (CaptureStackBackTraceType)(GetProcAddress(LoadLibraryA("kernel32.dll"), "RtlCaptureStackBackTrace"));
	if (func != NULL) {
		HMODULE hMods[1024];
		DWORD cbNeeded;
		EnumProcessModules((HANDLE)-1, hMods, sizeof(hMods), &cbNeeded);
		const int kMaxCallers = 62;
		void* callers[kMaxCallers];
		int count = (func)(0, kMaxCallers, callers, NULL);
		for (int i = 1; i < count; i++) {
			DWORD64 callerAddr = (DWORD64)callers[i];
			HMODULE currentCallerModule = NULL;
			for (unsigned int i2 = 0; i2 < (cbNeeded / sizeof(HMODULE)); i2++) {
				MODULEINFO information = { 0 };
				GetModuleInformation((HANDLE)-1, hMods[i2], &information, sizeof(information));
				if (callerAddr >= (DWORD64)information.lpBaseOfDll && callerAddr <= (DWORD64)information.lpBaseOfDll + information.SizeOfImage) {
					currentCallerModule = hMods[i2];
					break;
				}
			}
			if (currentCallerModule != NULL) {
				char moduleName[MAX_PATH];
				GetModuleBaseNameA((HANDLE)-1, currentCallerModule, moduleName, MAX_PATH);
				char buf[512];
				sprintf_s(buf, "0x%08llx [%s]%s", callerAddr - (DWORD64)currentCallerModule, moduleName, i != count - 1 ? ", " : "");
				s += buf;
			} else {
				char buf[512];
				sprintf_s(buf, "0x%016llx %s", callerAddr, i != count - 1 ? ", " : "");
				s += buf;
			}
		}
		s += "]";
		return s.c_str();
	}
	return "failed";
}


static std::multimap<uint64_t, uintptr_t> g_hints;

void Memory2::executable_meta::EnsureInit() {

	if (m_begin) {
		return;
	}

	HMODULE gModule = GetModuleHandle(NULL);

	m_begin = reinterpret_cast<uintptr_t>(gModule);
	const IMAGE_DOS_HEADER* dosHeader = reinterpret_cast<const IMAGE_DOS_HEADER*>(gModule);
	const IMAGE_NT_HEADERS* ntHeader = reinterpret_cast<const IMAGE_NT_HEADERS64*>(reinterpret_cast<const uint8_t*>(dosHeader) + dosHeader->e_lfanew);
	m_end = m_begin + ntHeader->OptionalHeader.SizeOfCode;
	m_size = ntHeader->OptionalHeader.SizeOfImage;
}

void Memory2::TransformPattern(const std::string& pattern, std::string& data, std::string& mask) {

	std::stringstream dataStr;
	std::stringstream maskStr;

	uint8_t tempDigit = 0;
	bool tempFlag = false;

	for (auto& ch : pattern) {

		if (ch == ' ') {
			continue;
		}
		else if (ch == '?') {

			dataStr << '\x00';
			maskStr << '?';
		}
		else if ((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'F') || (ch >= 'a' && ch <= 'f')) {

			char str[] = { ch, 0 };
			int thisDigit = strtol(str, nullptr, 16);

			if (!tempFlag) {

				tempDigit = (thisDigit << 4);
				tempFlag = true;
			}
			else {

				tempDigit |= thisDigit;
				tempFlag = false;

				dataStr << tempDigit;
				maskStr << 'x';
			}
		}
	}

	data = dataStr.str();
	mask = maskStr.str();
}

void Memory2::pattern::Initialize(const char* pattern, size_t length) {

	// get the hash for the base pattern
	std::string baseString(pattern, length);
	m_hash = fnv_1()(baseString);

	m_matched = false;

	// transform the base pattern from IDA format to canonical format
	TransformPattern(baseString, m_bytes, m_mask);

	m_size = m_mask.size();

	// if there's hints, try those first
	auto range = g_hints.equal_range(m_hash);

	if (range.first != range.second) {

		std::for_each(range.first, range.second, [&](const std::pair<uint64_t, uintptr_t>& hint) {
			ConsiderMatch(hint.second);
			});

		// if the hints succeeded, we don't need to do anything more
		if (m_matches.size() > 0) {
			m_matched = true;
			return;
		}
	}
}

uintptr_t Memory2::get_base()
{
	executable_meta executable;
	executable.EnsureInit();
	return executable.begin();
}

DWORD Memory2::get_size()
{
	executable_meta executable;
	executable.EnsureInit();
	return executable.size();
}

uintptr_t Memory2::get_base_offsetted(DWORD offset)
{
	return get_base() + offset;
}

uintptr_t Memory2::get_multilayer_pointer(uintptr_t base_address, std::vector<DWORD> offsets)
{
	uintptr_t ptr = *(uintptr_t*)(base_address);
	if (!ptr) {

		return NULL;
	}
	auto level = offsets.size();

	for (auto i = 0; i < level; i++)
	{
		if (i == level - 1)
		{
			ptr += offsets[i];
			if (!ptr) return NULL;
			return ptr;
		}
		else
		{
			ptr = *(uint64_t*)(ptr + offsets[i]);
			if (!ptr) return NULL;
		}
	}

	return ptr;
}

static bool compare(const uint8_t* pData, const uint8_t* bMask, const char* sMask)
{
	for (; *sMask; ++sMask, ++pData, ++bMask)
		if (*sMask == 'x' && *pData != *bMask)
			return false;

	return *sMask == NULL;
}

std::vector<DWORD64> Memory2::get_string_addresses(std::string str)
{
	std::string currentMask;
	const char* to_scan = str.c_str();
	for (uint8_t i = 0; i < strlen(to_scan); i++) currentMask += "x";
	const char* mask = currentMask.c_str();
	std::vector<DWORD64> foundAddrs;
	for (uint32_t i = 0; i < get_size(); ++i)
	{
		auto address = get_base() + i;
		if (compare((BYTE*)(address), (BYTE*)to_scan, mask))
		{
			foundAddrs.push_back((address));
		}
	}

	return foundAddrs;

}

bool Memory2::pattern::ConsiderMatch(uintptr_t offset) {

	const char* pattern = m_bytes.c_str();
	const char* mask = m_mask.c_str();

	char* ptr = reinterpret_cast<char*>(offset);

	for (size_t i = 0; i < m_size; i++) {

		if (mask[i] == '?') {
			continue;
		}

		if (pattern[i] != ptr[i]) {
			return false;
		}
	}

	m_matches.push_back(pattern_match(ptr));

	return true;
}

void Memory2::pattern::EnsureMatches(int maxCount) {

	if (m_matched) {
		return;
	}

	// Scan the executable for code
	static executable_meta executable;

	executable.EnsureInit();

	// Check if SSE 4.2 is supported
	int cpuid[4];
	__cpuid(cpuid, 0);

	bool sse42 = false;

	if (m_mask.size() <= 16) {

		if (cpuid[0] >= 1) {

			__cpuidex(cpuid, 1, 0);

			sse42 = (cpuid[2] & (1 << 20)) == 1;
		}
	}

	auto matchSuccess = [&](uintptr_t address) {

		g_hints.insert(std::make_pair(m_hash, address));

		return (m_matches.size() == maxCount);
	};

	LARGE_INTEGER ticks;
	QueryPerformanceCounter(&ticks);

	uint64_t startTicksOld = ticks.QuadPart;

	if (!sse42) {

		for (uintptr_t i = executable.begin(); i <= executable.end(); i++) {

			if (ConsiderMatch(i)) {

				if (matchSuccess(i)) {
					break;
				}
			}
		}
	}
	else {

		__declspec(align(16)) char desiredMask[16] = { 0 };

		for (int i = 0; i < m_mask.size(); i++) {
			desiredMask[i / 8] |= ((m_mask[i] == '?') ? 0 : 1) << (i % 8);
		}

		__m128i mask = _mm_load_si128(reinterpret_cast<const __m128i*>(desiredMask));
		__m128i comparand = _mm_loadu_si128(reinterpret_cast<const __m128i*>(m_bytes.c_str()));

		for (uintptr_t i = executable.begin(); i <= executable.end(); i++) {

			__m128i value = _mm_loadu_si128(reinterpret_cast<const __m128i*>(i));
			__m128i result = _mm_cmpestrm(value, 16, comparand, (int)m_bytes.size(), _SIDD_CMP_EQUAL_EACH);

			// As the result can match more bits than the mask contains
			__m128i matches = _mm_and_si128(mask, result);
			__m128i equivalence = _mm_xor_si128(mask, matches);

			if (_mm_test_all_zeros(equivalence, equivalence)) {

				m_matches.push_back(pattern_match((void*)i));

				if (matchSuccess(i)) {
					break;
				}
			}
		}
	}

	m_matched = true;
}

void Memory2::pattern::hint(uint64_t hash, uintptr_t address) {

	auto range = g_hints.equal_range(hash);

	for (auto it = range.first; it != range.second; it++) {

		if (it->second == address) {
			return;
		}
	}

	g_hints.insert(std::make_pair(hash, address));
}

