#include "stdafx.h"
#include "menu/submenus/main/worldMenu.h"
#include "menu/submenus/main/world/worldDrawablesMenu.h"
#include "menu/submenus/main/session/playerList/player/chatCommandMenu.h"
#include "menu/submenus/main/shv/shvMenu.h"
#include "menu/submenus/main/session/nameMenu.h"
#include "menu/submenus/main/protectionMenu.h"
#include "menu\submenus\main\protection\spoofingProtectionMenu.h"
#include "menu\globals.h"


fpGetPlayerAddress		Hooked::GetPlayerAddress;
fpAddressToEntity		Hooked::AddressToEntity;
fpGetPlayerName         Hooked::get_player_name;
fpCreateVehicle			Hooked::create_vehicle;
fpTriggerScriptEvent	Hooked::trigger_script_event;

//fpworldscreen			Hooked::world_screen;

Ped Hooked::get_player_ped(Player player)
{
	const auto addr = Hooked::GetPlayerAddress(player);

	if (addr) {
		return Hooked::AddressToEntity(addr);
	}

	return NULL;
}


__int64					Backend::m_originalRID;
__int64					Backend::m_spoofingRID;

bool					Backend::m_loaded;
bool					Backend::m_isHooking;
bool					Backend::m_cleaning;
HWND					Backend::m_hWindow;
HANDLE					Backend::m_process;
DWORD64					Backend::m_gameBase;
DWORD64					Backend::m_gameSize;
HMODULE					Backend::m_hModule;
vector<char>			Backend::m_modulePE;
vector<uint64_t>		Backend::m_nameAddresses;
HMODULE					Backend::m_NTDLLModule;
uint64_t				Backend::m_moduleBaseAddr;
uint64_t				Backend::m_moduleSize;
uint64_t				Backend::m_worldPtr;
uint64_t				Backend::m_eventPoolPtr;
uint64_t				Backend::m_tunables;
__int64**				Backend::m_globalPtr;
GameState*				Backend::m_gameState;
Script::ScriptTable*	Backend::m_scriptTable;
uint64_t				Backend::m_gameplayCam;
uint64_t				Backend::m_networkPlayerData;
int						Backend::m_networkPlayerIsOnlineOffset;
uint64_t				Backend::m_networkPlayerManager;
DWORD64					Backend::m_applyWindElementsSetup;
float					Backend::m_deltaTime;
DWORD					Backend::m_lastFrameTime;
BYTE					Backend::m_isInSession;
NetCatalog*				Backend::m_netCatalog;
Tunables*				Backend::m_tunableStruct;
void*					Backend::m_getRoutingData;
//typedef BOOL(_cdecl* fpStatGetInt)(Hash statHash, int* outValue, int p2);
//class GETINT
//{
//private:
//public:
//	static fpStatGetInt							stat_get_int;
//};
//fpStatGetInt						GETINT::stat_get_int;

Backend::pGetModelInfo Backend::GetModelInfo;
//Backend::pHandleChat Backend::OriginalHandleChat;
//Backend::pGetStatInt Backend::OriginalGetStatInt;
Backend::pRegisterFileFn Backend::RegisterFileFn;
Backend::pRoadSlipperiness Backend::OriginalRoadSlipperiness;
Backend::pApplyWindElements Backend::OriginalApplyWindElements;
Backend::pProcessChatMessage Backend::OriginalProcessChatMessage;
Backend::pSendIncrementStatEvent Backend::fSendIncrementStatEvent;
Backend::pSendClearTasksEvent Backend::fSendClearTasksEvent;
Backend::pScriptVirtualMachineHook Backend::OriginalScriptVirtualMachine;

//int RandomNumberInRange(int min, int max) {
//	static bool first = true;
//	if (first) {
//		srand(time(NULL));
//		first = false;
//	}
//	return min + rand() % ((max + 1) - min);
//}
//
//#define ARRAY_SIZE(a)                               \
//  ((sizeof(a) / sizeof(*(a))) /                     \
//  static_cast<size_t>(!(sizeof(a) % sizeof(*(a)))))
//
//char* GXTLoadingLabelReplacements[] = {
//	"~BLIP_INFO_ICON~ ",
//	"~BLIP_INFO_ICON~ ",
//	"~BLIP_INFO_ICON~ ",
//	"~BLIP_INFO_ICON~ ",
//	"~BLIP_INFO_ICON~ ",
//	"~BLIP_INFO_ICON~ ",
//	"~BLIP_INFO_ICON~ ",
//	"~BLIP_INFO_ICON~ ",
//	"~BLIP_INFO_ICON~ ",
//};

template<size_t N>
bool checkpattern(const char(&thepattern)[N])
{
	auto getnative = Memory2::pattern(thepattern);
	size_t matchCount = getnative.size();

	if (matchCount == 1)
	{
		void* address = getnative.get(0).get<void*>(0);
		if (address)
		{
			LOG_PRINT("FOUND: %s", thepattern);
			return true;
		}
	}

	LOG_PRINT("NOT FOUND: %s", thepattern);
	return false;
}

/*GXT hook*/
typedef const char*(*pGetGxtText)(uint64_t rcx, const char* gxtLabel);
pGetGxtText OriginalGetGxtText = NULL;
const char* GetGxtTextHook(uint64_t rcx, const char* gxtLabel) {

	/*if (strstr(gxtLabel, "TOOLTIPS_")) {
		return GXTLoadingLabelReplacements[RandomNumberInRange(0, ARRAY_SIZE(GXTLoadingLabelReplacements) - 1)];
	}*/
	if (!strcmp(gxtLabel, "CTALERT_F_1")) {
		return "Game Alert";
	} else if (!strcmp(gxtLabel, "HUD_JOINING")) {
		return "Loading GTA Online with Thunder";
	} else if (!strcmp(gxtLabel, "HUD_QUITTING")) {
		return "Leave Online With Thunder for Singleplayer";
	} else if (!strcmp(gxtLabel, "PM_QUIT_MP")) {
		return "Leave GTA Online with Thunder";
	} else if (!strcmp(gxtLabel, "PM_ENTER_MP")) {
		return "Join Online with Thunder-Menu.com";
	} else if (!strcmp(gxtLabel, "PM_EXIT_GAME")) {
		return "Exit Game with Thunder-Menu.com";
	} else if (!strcmp(gxtLabel, "PM_GO")) {
		return "Launch Online With Thunder";
	} else if (!strcmp(gxtLabel, "PM_GOTO_STORE")) {
		return "GOTO STORE with Thunder-Menu.com";
	} else if (!strcmp(gxtLabel, "PM_FRIEND_FM")) {
		return "Join Friend with Thunder-Menu.com";
	} else if (!strcmp(gxtLabel, "PM_FIND_SESS")) {
		return "Find a new session with Thunder";
	}/* else if (!strcmp(gxtLabel, "LOADING_SPLAYER_L")) {
		return "Loading GTA with Thunder";
	} else if (!strcmp(gxtLabel, "LOADING_MPLAYER_L")) {
		return "Loading GTA Online with Thunder";
	} else if (!strcmp(gxtLabel, "PM_INF_PGOT")) {
		return "Play GTA Online With Thunder";
	} else if (!strcmp(gxtLabel, "PM_INVO_FM")) {
		return "Launch Invite only With Thunder";
	} else if (!strcmp(gxtLabel, "PM_INF_PGOT5")) {
		return "Thunder Invite only session";
	} else if (!strcmp(gxtLabel, "HUD_TRANSP")) {
		return "";
	} else if (!strcmp(gxtLabel, "PM_INF_PGOB0")) {
		return "Head straight into GTA Online with the Thunder Trainer.";
	} else if (!strcmp(gxtLabel, "RADIO_04_PUNK") || !strcmp(gxtLabel, "FMMCRADIO_4")) {
		return "Thunder Radio";
	} else if (!strcmp(gxtLabel, "RADIO_01_CLASS_ROCK")) {
		return "Edgy Memes";
	} else if (!strcmp(gxtLabel, "RADIO_02_POP")) {
		return "Lesbian Elephants Pop Music";
	} else if (!strcmp(gxtLabel, "RADIO_03_HIPHOP_NEW")) {
		return "Thunder HIPHOP";
	} else if (!strcmp(gxtLabel, "RADIO_08_MEXICAN")) {
		return "Mother Talks Radio";
	}*/ else if (Utils::GetHashKey(gxtLabel) == 0x8CC30479) {
		return "Initializing Thunder";
	} else if (Utils::GetHashKey(gxtLabel) == 0x4FA9A3B2) {
		return "You were vote kicked or host kicked by a menu user";
	}
	return OriginalGetGxtText(rcx, gxtLabel);
}

void Backend::RoadSlipperinessHook(WorldManager* worldManager) {
	*(float*)((DWORD64)worldManager + 0xEC0) = WorldMenuVars::vars.slipperiness;
}

int Backend::RegisterCStreamingFile(char *filename, bool appdata) {
	int newIdx;
	char buffer[256];
	if (appdata)
		sprintf(buffer, "%s\\Thunder\\YTD\\%s", GetConfig()->GetPathMyDocuments(), filename);//GetPathAppdata
	else sprintf(buffer, "%s\\Thunder\\YTD\\%s", GetConfig()->GetPathMyDocuments(), filename);
	RegisterFileFn(&newIdx, buffer, true, filename, false);
	return newIdx;
}

//CNetGamePlayer* GetChatSender(rage::netTextMsg* msg) {
//	rage::rlGamerHandle Handle{ msg->m_handle };
//	uint64_t PlatformData{ Handle.m_rockstar_id };
//	for (auto& NetPlayer : ReClass::GetNetworkPlayerManager()->m_players) {
//		if (NetPlayer) {
//			if (auto PlayerInfo = NetPlayer->PlayerInfo; PlayerInfo) {
//				if (*(uint64_t*)((uint64_t)PlayerInfo + 0xC8) == PlatformData) {
//					return NetPlayer;
//				}
//			}
//		}
//	}
//}

//bool Backend::HandleChatHook(rage::netTextMsg* msg, uint64_t buffer) {
//	bool Return = OriginalHandleChat(msg, buffer);
//	if (Return)
//		return Return;
//	char* chatMsg{ msg->m_message };
//	CNetGamePlayer* Cplayer = GetChatSender(msg);
//	if (Cplayer && Cplayer->PlayerInfo && Cplayer->PlayerInfo->Name) {
//		GetWindowManager()->GetPlayerLog(Cplayer->PlayerInfo->Name)->second->addLine(va("~c~%s: ~s~%s", GetLog()->GetTimeAsString(), chatMsg));
//		GetWindowManager()->m_chatComp.addLine(va("~c~%s: ~s~%s: %s", GetLog()->GetTimeAsString(), Cplayer->PlayerInfo->Name, chatMsg));
//
//		if (Cplayer != nullptr) {
//			string msgStr = (string)chatMsg;
//			GetFiberPool()->DoJob([Cplayer, msgStr] { ChatCommandMenuVars::HandleCommand(Cplayer->m_playerID, msgStr); });
//		}
//	}
//	return Return;
//}

/*This could probably be done in a cleaner way...*/
int64_t Backend::ProcessChatMessageHook(int64_t a1, const void *a2, size_t a3, const void *a4, size_t size) {
	string prefix = (String)a2;
	string suffix = (String)a4;
	static string lastMessage;
	int64_t result = OriginalProcessChatMessage(a1, a2, a3, a4, size);
	if ((!prefix.empty() && !suffix.empty())) {
		int pos = prefix.find("[ALL]");
		if (pos != string::npos) {
			string currentMessage = prefix + suffix;
			if (currentMessage.compare(lastMessage) != 0) {
				prefix = prefix.erase(pos, 5);
				prefix.erase(prefix.find_last_not_of(" ") + 1);
				prefix.erase(0, prefix.find_first_not_of(" "));
				prefix.append(": ");
				prefix += suffix;
				LOG_CUSTOM(ConsoleForeground::GREEN, "[Message] %s", prefix.c_str());
				GetWindowManager()->m_chatComp.addLine(va("~c~%s: ~s~%s", GetLog()->GetTimeAsString(), prefix.c_str()));
			}
			lastMessage = currentMessage;
		}
	}
	return result;
}

int Backend::GetStatIntHook(Hash statHash, int* outValue, int p2) {
	static long now;
	static int c_frameCache = 0;
	static once_flag c_init, c_init1;
	if (SCRIPT::GetHashOfThisScriptName() == 0x5700179C) {
		if (c_frameCache < MISC::GetFrameCount()) {
			c_frameCache = MISC::GetFrameCount();


			now = timeGetTime();
			m_deltaTime = (float)(now - m_lastFrameTime) / 1000;
			m_lastFrameTime = now;

			if (!GetAuth()->IsAuthorized() && !m_cleaning) {
				call_once(c_init, [] {
					static float authOpacity = 0;
					GetRenderer()->SetOpacityVariable(authOpacity);
					GetAuthFiberManager()->Init("A"); //Auth
					GetAuthFiberManager()->AddFiber("AO", [] { authOpacity = Utils::Clamp(authOpacity + 1.2f * Backend::GetDeltaTime(), 0.0, 1.0); });
					GetAuthFiberManager()->AddFiber("AI", [] {
						string username = GetConfig()->ReadString("Auth", "username", "", GetConfig()->GetLoginPath());
						string password = GetConfig()->ReadString("Auth", "password", "", GetConfig()->GetLoginPath());
						if (!strcmp(username.c_str(), "") || !strcmp(password.c_str(), "")) GetAuth()->AuthInput(STATUS_NOTHING);
						else GetAuth()->AuthInput(STATUS_AUTOLOGIN, username, password);
					}); //AuthInput
				});
				GetAuthFiberManager()->Tick();
			} else {
				GetAuthFiberManager()->Cleanup();

#ifdef TESTER_ONLY
				if (!GetAuth()->IsTester()) {
					Cleanup();
				}
#endif

				if (m_gameState != nullptr) {
					if (GetGameState() == GameStatePlaying && !m_cleaning && m_loaded) {
						call_once(c_init1, [] {ScriptThreadInit(); });
						if (m_frameCounter++ > 9999999)m_frameCounter = 0;
						GetFiberManager()->Tick();
						GetScriptHookFiberManager()->Tick();
					}
				}
			}
		}
	}
	return OriginalGetStatInt(statHash, outValue, p2);
}

typedef bool(*pIsEntityUpsideDown)(Entity entity);
pIsEntityUpsideDown OriginalIsEntityUpsideDown;

bool Backend::IsEntityUpsideDown(Entity entity) {
	static long now;
	static int c_frameCache = 0;
	static once_flag c_init, c_init1;
	if (SCRIPT::GetHashOfThisScriptName() == 0x5700179C) {
		if (c_frameCache < MISC::GetFrameCount()) {
			c_frameCache = MISC::GetFrameCount();


			now = timeGetTime();
			m_deltaTime = (float)(now - m_lastFrameTime) / 1000;
			m_lastFrameTime = now;

			if (!GetAuth()->IsAuthorized() && !m_cleaning) {
				call_once(c_init, [] {
					static float authOpacity = 0;
					GetRenderer()->SetOpacityVariable(authOpacity);
					GetAuthFiberManager()->Init("A"); //Auth
					GetAuthFiberManager()->AddFiber("AO", [] { authOpacity = Utils::Clamp(authOpacity + 1.2f * Backend::GetDeltaTime(), 0.0, 1.0); });
					GetAuthFiberManager()->AddFiber("AI", [] {
						string username = GetConfig()->ReadString("Auth", "username", "", GetConfig()->GetLoginPath());
						string password = GetConfig()->ReadString("Auth", "password", "", GetConfig()->GetLoginPath());
						if (!strcmp(username.c_str(), "") || !strcmp(password.c_str(), "")) GetAuth()->AuthInput(STATUS_NOTHING);
						else GetAuth()->AuthInput(STATUS_AUTOLOGIN, username, password);
					}); //AuthInput
				});
				GetAuthFiberManager()->Tick();
			} else {
				GetAuthFiberManager()->Cleanup();

#ifdef TESTER_ONLY
				if (!GetAuth()->IsTester()) {
					Cleanup();
				}
#endif

				if (m_gameState != nullptr) {
					if (GetGameState() == GameStatePlaying && !m_cleaning && m_loaded) {
						call_once(c_init1, [] {ScriptThreadInit(); });
						if (m_frameCounter++ > 9999999)m_frameCounter = 0;
						GetFiberManager()->Tick();
						GetScriptHookFiberManager()->Tick();
					}
				}
			}
		}
	}
	return OriginalIsEntityUpsideDown(entity);
}

typedef BOOL(*pSignedOnlineHook)();
pSignedOnlineHook originalSignedOnlineHook;

BOOL Backend::NetworkIsSignedOnlineHook() {
	static long now;
	static int c_frameCache = 0;
	static once_flag c_init, c_init1;
	if (SCRIPT::GetHashOfThisScriptName() == 0x5700179C) {
		if (c_frameCache < MISC::GetFrameCount()) {
			c_frameCache = MISC::GetFrameCount();


			now = timeGetTime();
			m_deltaTime = (float)(now - m_lastFrameTime) / 1000;
			m_lastFrameTime = now;

			if (!GetAuth()->IsAuthorized() && !m_cleaning) {
				call_once(c_init, [] {
					static float authOpacity = 0;
					GetRenderer()->SetOpacityVariable(authOpacity);
					GetAuthFiberManager()->Init("A"); //Auth
					GetAuthFiberManager()->AddFiber("AO", [] { authOpacity = Utils::Clamp(authOpacity + 1.2f * Backend::GetDeltaTime(), 0.0, 1.0); });
					GetAuthFiberManager()->AddFiber("AI", [] {
						string username = GetConfig()->ReadString("Auth", "username", "", GetConfig()->GetLoginPath());
						string password = GetConfig()->ReadString("Auth", "password", "", GetConfig()->GetLoginPath());
						if (!strcmp(username.c_str(), "") || !strcmp(password.c_str(), "")) GetAuth()->AuthInput(STATUS_NOTHING);
						else GetAuth()->AuthInput(STATUS_AUTOLOGIN, username, password);
					}); //AuthInput
				});
				GetAuthFiberManager()->Tick();
			}
			else {
				GetAuthFiberManager()->Cleanup();

#ifdef TESTER_ONLY
				if (!GetAuth()->IsTester()) {
					Cleanup();
				}
#endif

				if (m_gameState != nullptr) {
					if (GetGameState() == GameStatePlaying && !m_cleaning && m_loaded) {
						call_once(c_init1, [] {ScriptThreadInit(); });
						if (m_frameCounter++ > 9999999)m_frameCounter = 0;
						GetFiberManager()->Tick();
						GetScriptHookFiberManager()->Tick();
					}
				}
			}
		}
	}
	return originalSignedOnlineHook();
}

typedef BOOL(*pIsRecordingHook)();
pIsRecordingHook originalIsRecordingHook;

BOOL Backend::IsRecordingHook() {
	static long now;
	static int c_frameCache = 0;
	static once_flag c_init, c_init1;
	if (SCRIPT::GetHashOfThisScriptName() == 0x5700179C) {
		if (c_frameCache < MISC::GetFrameCount()) {
			c_frameCache = MISC::GetFrameCount();


			now = timeGetTime();
			m_deltaTime = (float)(now - m_lastFrameTime) / 1000;
			m_lastFrameTime = now;

			if (!GetAuth()->IsAuthorized() && !m_cleaning) {
				call_once(c_init, [] {
					static float authOpacity = 0;
					GetRenderer()->SetOpacityVariable(authOpacity);
					GetAuthFiberManager()->Init("A"); //Auth
					GetAuthFiberManager()->AddFiber("AO", [] { authOpacity = Utils::Clamp(authOpacity + 1.2f * Backend::GetDeltaTime(), 0.0, 1.0); });
					GetAuthFiberManager()->AddFiber("AI", [] {
						string username = GetConfig()->ReadString("Auth", "username", "", GetConfig()->GetLoginPath());
						string password = GetConfig()->ReadString("Auth", "password", "", GetConfig()->GetLoginPath());
						if (!strcmp(username.c_str(), "") || !strcmp(password.c_str(), "")) GetAuth()->AuthInput(STATUS_NOTHING);
						else GetAuth()->AuthInput(STATUS_AUTOLOGIN, username, password);
					}); //AuthInput
				});
				GetAuthFiberManager()->Tick();
			}
			else {
				GetAuthFiberManager()->Cleanup();

#ifdef TESTER_ONLY
				if (!GetAuth()->IsTester()) {
					Cleanup();
				}
#endif

				if (m_gameState != nullptr) {
					if (GetGameState() == GameStatePlaying && !m_cleaning && m_loaded) {
						call_once(c_init1, [] {ScriptThreadInit(); });
						if (m_frameCounter++ > 9999999)m_frameCounter = 0;
						GetFiberManager()->Tick();
						GetScriptHookFiberManager()->Tick();
					}
				}
			}
		}
	}
	return originalIsRecordingHook();
}

int Backend::m_frameCounter;
bool Backend::DevMode;
void Backend::ScriptThreadInit() {
	m_lastFrameTime = timeGetTime();
	GetScriptHookFiberManager()->Init("M_SHV");

	GetFiberManager()->Init("M"); //Main
	GetFiberManager()->AddFiber("WM", [] {GetWindowManager()->Update(); }); //WindowManager
	GetFiberManager()->AddFiber("WMAS", [] { GetWindowManager()->ASyncUpdate(); }); //WindowManagerASync
	GetFiberManager()->AddFiber("HM", [] {GetHotkeyManager()->Update(); }); //HotkeyManager
	GetFiberManager()->AddFiber("EC", [] {GetEntityControl()->Update(); }); //EntityControl
	GetFiberManager()->AddFiber("FB", [] {GetSubmenuHandler()->ASyncUpdate(); }); //FeatureBackground
	GetFiberManager()->AddFiber("CM", [] {GetContextMenu()->Update(); }); //ContextMenu
	GetFiberManager()->AddFiber("MI", [] {GetMenuInput()->Update(); }); //MenuInput

	//GetThreadPool()->RegisterThread("AT", [] {GetAuth()->OnTick(); }); //AuthorizationTick

	GetFiberPool()->Init();

	GetWindowManager()->Init();

	LOG_PRINT("[Service] Finished loading Thunder");
}

void Backend::IncrementPlayerStat(Player player, Hash stat, int value) {
	CNetworkPlayerManager* players = ReClass::GetNetworkPlayerManager();
	fSendIncrementStatEvent(stat, value, players->m_players[player]);
}

void Backend::SendClearTasksEvent(Entity entity, uint8_t something) {
	fSendClearTasksEvent(PoolManager::GetEntityAddress(entity), something);
}

class CYSC {
	char pad_0x0000[0x60];
	String name;
};

/*Main hook*/
__int64 Backend::ScriptVirtualMachineHook(__int64 rcx, __int64 global, __int64 ysc, __int64 pThread) {
	if (*(int*)(pThread + 0x4) == 0xd1f9d9c5) {
		return 0;
	}

	static long now;
	static int c_frameCache = 0;
	static once_flag c_init, c_init1;
	if (*(int*)(pThread + 0x4) == 0x5700179C) {
		if (c_frameCache < MISC::GetFrameCount()) {
			c_frameCache = MISC::GetFrameCount();


			now = timeGetTime();
			m_deltaTime = (float)(now - m_lastFrameTime) / 1000;
			m_lastFrameTime = now;

			if (!GetAuth()->IsAuthorized() && !m_cleaning) {
				call_once(c_init, [] {
					static float authOpacity = 0;
					GetRenderer()->SetOpacityVariable(authOpacity);
					GetAuthFiberManager()->Init("A"); //Auth
					GetAuthFiberManager()->AddFiber("AO", [] { authOpacity = Utils::Clamp(authOpacity + 1.2f * Backend::GetDeltaTime(), 0.0, 1.0); });
					GetAuthFiberManager()->AddFiber("AI", [] {
						string username = GetConfig()->ReadString("Auth", "username", "", GetConfig()->GetLoginPath());
						string password = GetConfig()->ReadString("Auth", "password", "", GetConfig()->GetLoginPath());
						if (!strcmp(username.c_str(), "") || !strcmp(password.c_str(), "")) GetAuth()->AuthInput(STATUS_NOTHING);
						else GetAuth()->AuthInput(STATUS_AUTOLOGIN, username, password);
					}); //AuthInput
				});
				GetAuthFiberManager()->Tick();
			}
			else {
				GetAuthFiberManager()->Cleanup();

#ifdef TESTER_ONLY
				if (!GetAuth()->IsTester()) {
					Cleanup();
				}
#endif

				if (m_gameState != nullptr) {
					if (GetGameState() == GameStatePlaying && !m_cleaning && m_loaded) {
						call_once(c_init1, [] {ScriptThreadInit(); });
						if (m_frameCounter++ > 9999999)m_frameCounter = 0;
						GetFiberManager()->Tick();
						GetScriptHookFiberManager()->Tick();
					}
				}
			}
		}
		/*if (strstr(SCRIPT::GetThisScriptName(), "valentinerpreward2")) {
			SCRIPT::TerminateThisThread();
		}*/
	}


	//if (*(int*)(pThread + 0x4) == 0x5700179C && GetGameState() == GameStatePlaying && !m_cleaning && m_loaded) { //MAIN_PERSISTENT
	//	if (c_frameCache < MISC::GetFrameCount()) {
	//		c_frameCache = MISC::GetFrameCount();
	//		now = timeGetTime();
	//		m_deltaTime = (float)(now - m_lastFrameTime) / 1000;
	//		m_lastFrameTime = now;
	//		call_once(c_init, [] {ScriptThreadInit(); });
	//		m_frameCounter++;
	//		GetFiberManager()->Tick();
	//	}
	//}

	return OriginalScriptVirtualMachine(rcx, global, ysc, pThread);
}

int Backend::StatGetIntHook(NativeContext* cxt) {
	static long now;
	static int c_frameCache = 0;
	static once_flag c_init, c_init1;
	//LOG_PRINT("GetHashOfThisScriptName");
	if (SCRIPT::GetHashOfThisScriptName() == 0x5700179C) {
		if (c_frameCache < MISC::GetFrameCount()) {
			c_frameCache = MISC::GetFrameCount();
		
			now = timeGetTime();
			m_deltaTime = (float)(now - m_lastFrameTime) / 1000;
			m_lastFrameTime = now;
			//LOG_PRINT("GetAuth");
			if (!GetAuth()->IsAuthorized() && !m_cleaning) {
				call_once(c_init, [] {
					static float authOpacity = 0;
					GetRenderer()->SetOpacityVariable(authOpacity);
					GetAuthFiberManager()->Init("A"); //Auth
					GetAuthFiberManager()->AddFiber("AO", [] { authOpacity = Utils::Clamp(authOpacity + 1.2f * Backend::GetDeltaTime(), 0.0, 1.0); });
					GetAuthFiberManager()->AddFiber("AI", [] {
						string username = GetConfig()->ReadString("Auth", "username", "", GetConfig()->GetLoginPath());
						string password = GetConfig()->ReadString("Auth", "password", "", GetConfig()->GetLoginPath());
						if (!strcmp(username.c_str(), "") || !strcmp(password.c_str(), "")) GetAuth()->AuthInput(STATUS_NOTHING);
						else GetAuth()->AuthInput(STATUS_AUTOLOGIN, username, password);
					}); //AuthInput
				});
				//LOG_PRINT("Tick");
				GetAuthFiberManager()->Tick();
			} else {
				GetAuthFiberManager()->Cleanup();

#ifdef TESTER_ONLY
				if (!GetAuth()->IsTester()) {
					Cleanup();
				}
#endif

				if (m_gameState != nullptr) {
					//LOG_PRINT("GameStatePlaying");
					if (GetGameState() == GameStatePlaying && !m_cleaning && m_loaded) {
						//LOG_PRINT("call_once");
						call_once(c_init1, [] { ScriptThreadInit(); GetFiberPool()->DoJob([] { GetSystemdata()->Initialize(); }); });
						if (m_frameCounter++ > 9999999)m_frameCounter = 0;
						GetFiberManager()->Tick();
						GetScriptHookFiberManager()->Tick();
					}
				}
			}
		}
	}

	return STATS::StatGetInt(cxt->getArgument<Hash>(0), cxt->getArgument<int*>(1), cxt->getArgument<int>(2));
}


void Backend::WaitHook(NativeContext* cxt) {
	static long now;
	static int c_frameCache = 0;
	static once_flag c_init, c_init1;

	if (c_frameCache < MISC::GetFrameCount()) {
		c_frameCache = MISC::GetFrameCount();


		now = timeGetTime();
		m_deltaTime = (float)(now - m_lastFrameTime) / 1000;
		m_lastFrameTime = now;

		if (!GetAuth()->IsAuthorized() && !m_cleaning) {
			call_once(c_init, [] {
				static float authOpacity = 0;
				GetRenderer()->SetOpacityVariable(authOpacity);
				GetAuthFiberManager()->Init("A"); //Auth
				GetAuthFiberManager()->AddFiber("AO", [] { authOpacity = Utils::Clamp(authOpacity + 1.2f * Backend::GetDeltaTime(), 0.0, 1.0); });
				GetAuthFiberManager()->AddFiber("AI", [] {
					string username = GetConfig()->ReadString("Auth", "username", "", GetConfig()->GetLoginPath());
					string password = GetConfig()->ReadString("Auth", "password", "", GetConfig()->GetLoginPath());
					if (!strcmp(username.c_str(), "") || !strcmp(password.c_str(), "")) GetAuth()->AuthInput(STATUS_NOTHING);
					else GetAuth()->AuthInput(STATUS_AUTOLOGIN, username, password);
				}); //AuthInput
			});
			GetAuthFiberManager()->Tick();
		} else {
			GetAuthFiberManager()->Cleanup();

#ifdef TESTER_ONLY
			if (!GetAuth()->IsTester()) {
				Cleanup();
			}
#endif
	
			if (m_gameState != nullptr) {
				if (GetGameState() == GameStatePlaying && !m_cleaning && m_loaded) {
					call_once(c_init1, [] { ScriptThreadInit(); });
					if (m_frameCounter++ > 9999999)m_frameCounter = 0;
					GetFiberManager()->Tick();
					GetScriptHookFiberManager()->Tick();
				}
			}
		}
	}
	/*if (strstr(SCRIPT::GetThisScriptName(), "valentinerpreward2")) {
		SCRIPT::TerminateThisThread();
	}*/


	SYSTEM::Wait(cxt->getArgument<int>(0));
}

//using WaitNative = void(*)(int ms);
//WaitNative WaitN = nullptr;
typedef void(*_WAIT)(int timeMS);
_WAIT WAIT_ = nullptr;

#include <sstream>
#include <iomanip>
#include <string>

std::string toHexString(uint64_t value) {
	std::stringstream ss;
	ss << "0x"
		<< std::setfill('0') << std::setw(16)
		<< std::hex << std::uppercase << value;
	return ss.str();
}
//template<size_t N>
//uint64_t getNativeHashFromCallsite(const char(&patternStr)[N], int offsetToHash = 2) {
//	constexpr size_t maxLen = 256;
//	char patternArr[maxLen] = { 0 };
//	strncpy(patternArr, patternStr, maxLen - 1);
//
//	Memory2::pattern pat(patternArr);
//	auto match = pat.get(0);
//
//
//	if (!match) return 0;
//	uint8_t* instructionPtr = match.get<uint8_t>(0);
//	if (!instructionPtr) return 0;
//
//	uint8_t* hashPtr = instructionPtr + offsetToHash;
//
//	uint64_t nativeHash = 0;
//	memcpy(&nativeHash, hashPtr, sizeof(uint64_t));
//
//	return nativeHash;
//}
#include <iomanip>
#include <sstream>

template<size_t N>
uint64_t getHashFromPatternInternall(const char(&pattern)[N]) {
	Memory2::pattern pat(pattern);
	auto match = pat.get(0);
	uint8_t* address = match.get<uint8_t>(2);  // offset +2 bytes
	if (!address) return 0;

	uint64_t val;
	memcpy(&val, address, sizeof(uint64_t));
	return val;
}


//template<size_t N>
//uint64_t getHashFromPatternInternal(const char(&pattern)[N]) {
//	Memory2::pattern pat(pattern);
//	auto match = pat.get(0);
//	//uint8_t* address = match.get<uint8_t>(0);
//	uint8_t* address = match.get<uint8_t>(2);  // <-- offset by 2 bytes
//	if (!address) return 0;
//	uint64_t val;
//	memcpy(&val, address, sizeof(uint64_t));
//	return val;
//}
//
//uint64_t getHashFromPattern(const char* patternStr) {
//	// Copier la chaîne dans un tableau local de taille fixe
//	constexpr size_t maxLen = 256;
//	char patternArr[maxLen] = { 0 };
//	strncpy(patternArr, patternStr, maxLen - 1);
//
//	return getHashFromPatternInternal(patternArr);
//}

void mainScriptArray()
{
	auto start = Memory2::pattern("48 83 EC 28 E8 ? ? ? ? 48 8B 0D ? ? ? ? 4C 8D 0D ? ? ? ? 4C 8D 05 ? ? ? ? BA 03").count(1).get(0).get<uint8_t>(0);

	std::vector<std::string> foundStrings;
	std::vector<std::string> PatternStrings;

	for (int i = 0; i < 0x9F6; ++i)
	{
		// Cherche l’instruction 4C 8D 0D ?? ?? A1 00
		if (start[i + 0] == 0x4C &&
			start[i + 1] == 0x8D &&
			start[i + 2] == 0x0D &&
			start[i + 5] == 0xA1 &&
			start[i + 6] == 0x00)
		{
			int32_t relOffset = *reinterpret_cast<int32_t*>(start + i + 3);
			char* strPtr = reinterpret_cast<char*>(start + i + 7 + relOffset);

			// Sauvegarde le pattern hexadécimal trouvé (sur 7 octets)
			std::ostringstream oss;
			for (int b = 0; b < 7; b++)
			{
				oss << std::uppercase << std::hex << std::setw(2) << std::setfill('0') << (int)start[i + b];
				if (b < 6) oss << " ";
			}
			PatternStrings.push_back(oss.str());

			if (IsBadReadPtr(strPtr, 1) == 0)
			{
				std::string str(strPtr);
				foundStrings.push_back(str);
				LOG_PRINT("[+] Found string at offset 0x%X: %s", i, str.c_str());
			}

			i += 6; // Saute les octets de l'instruction
		}
	}

	LOG_PRINT("==== Toutes les chaînes extraites ====");
	for (size_t idx = 0; idx < foundStrings.size(); ++idx)
	{
		LOG_PRINT("[%zu] %s", idx, foundStrings[idx].c_str());
	}

	LOG_PRINT("==== Tous les patterns extraits ====");
	for (size_t idx = 0; idx < PatternStrings.size(); ++idx)
	{
		LOG_PRINT("[%zu] %s", idx, PatternStrings[idx].c_str());
	}
}

//void mainScriptArray()
//{
//	auto start = Memory2::pattern("48 83 EC 28 E8 ? ? ? ? 48 8B 0D ? ? ? ? 4C 8D 0D ? ? ? ? 4C 8D 05 ? ? ? ? BA 03").count(1).get(0).get<uint8_t>(0);
//
//	std::vector<std::string> foundStrings;
//
//	for (int i = 0; i < 0x9F6; ++i)
//	{
//		// Cherche l’instruction 4C 8D 0D ?? ?? A1 00
//		if (start[i + 0] == 0x4C &&
//			start[i + 1] == 0x8D &&
//			start[i + 2] == 0x0D &&
//			start[i + 5] == 0xA1 &&
//			start[i + 6] == 0x00)
//		{
//			int32_t relOffset = *reinterpret_cast<int32_t*>(start + i + 3);
//			char* strPtr = reinterpret_cast<char*>(start + i + 7 + relOffset);
//
//			if (IsBadReadPtr(strPtr, 1) == 0)
//			{
//				std::string str(strPtr);
//				foundStrings.push_back(str);
//				LOG_PRINT("[+] Found string at offset 0x%X: %s", i, str.c_str());
//			}
//
//			i += 6; // Saute les octets de l'instruction pour éviter de re-trouver la même
//		}
//	}
//
//	// Pour afficher toutes les chaînes (optionnel)
//	LOG_PRINT("==== Toutes les chaînes extraites ====");
//	for (size_t idx = 0; idx < foundStrings.size(); ++idx)
//	{
//		LOG_PRINT("[%zu] %s", idx, foundStrings[idx].c_str());
//	}
//
//}

void Backend::GetModuleInfo() {//tink i know why
	m_process = GetCurrentProcess();
	MODULEINFO module_info;
	memset(&module_info, 0, sizeof(module_info));
	GetModuleInformation(m_process, m_hModule, &module_info, sizeof(module_info));
	m_moduleSize = module_info.SizeOfImage;
	m_moduleBaseAddr = (uint64_t)module_info.lpBaseOfDll;

	memset(&module_info, 0, sizeof(module_info));
	GetModuleInformation(m_process, GetModuleHandleA(0), &module_info, sizeof(module_info));
	m_gameSize = module_info.SizeOfImage;
	m_gameBase = (DWORD64)module_info.lpBaseOfDll;
}

void Backend::Start(HMODULE hModule) {
	/*m_hModule = hModule;
	copy((BYTE*)hModule, (BYTE*)(hModule + 0x1000), back_inserter(m_modulePE));*/

#ifdef HARD_DEV
	// sophisticated
	SetErrorMode(0); // stops gta from exiting instantly - we want to debug
#endif

	//while (!(uint64_t)GetModuleHandleA("ScriptHookV.dll")) {
	//	Sleep(100);
	//}
	GetConfig()->Initialize();
	GetLog()->Initialize();

	GetThreadPool()->Initialize(5);
	//GetServerEvent()->RegisterEvents();

	Pattern::Initialize();

	MODULEINFO shvInfo = {};
	GetModuleInformation(GetCurrentProcess(), GetModuleHandleA("ScriptHookV.dll"), &shvInfo, sizeof(shvInfo));
	ScriptHookV::LoadedModuleMemory.emplace_back((uint64_t)shvInfo.lpBaseOfDll, (uint64_t)shvInfo.SizeOfImage, "ScriptHookV.dll", GetModuleHandleA("ScriptHookV.dll"));

	LOG_DEVPRINT("Added SHV module 0x%llx : 0x%llx", (uint64_t)shvInfo.lpBaseOfDll, (uint64_t)shvInfo.SizeOfImage);

	if (!Hooking::Initialize()) return;
	if (!Security::OnInject(m_hModule)) return;

	while (!m_hWindow)m_hWindow = FindWindow(L"grcWindow", nullptr);
	LOG_DEBUG("[Windows] W initialized");

	if (!Input::Initialize()) return;
	if (!Crossmap::Initialize())return;

	if (!Natives::PreGame()) return;
	//if (!Anticheat::PreAuth()) return;

	/* To allow script native hooking in this section uncomment out the SP hook below and comment out the one in PreGameBackend */

	if (!Hooking::PatternCallback<char>({ "SP", true, 0x0, "48 8B 1D ? ? ? ? 41 83 F8 FF" }, [](char* address) {
		m_scriptTable = (Script::ScriptTable*)GetAddressFromInstruction(address);
	})) return;

	/* Main Hooks (Main is SVM (stable for most) - Backup is GSI (most stable for most) - ScriptNative Hooks (mostly stable for most) - IR is Extreme Backup (slightly unstable for most) */

	/*if (!Hooking::PatternCallback<void>({ "GSI", false, 0, "48 8B C4 48 89 58 10 48 89 70 18 57 48 83 EC 30 48 8B F2" }, [](void* data) {
		return Hooking::HookFunction(data, &GetStatIntHook, &OriginalGetStatInt, "GSI");
	})) return;*/

	/*48 BA A6 67 D9 AD FB 34 DE 4E*/
	//static uint64_t g_hash0x = 0;
	//Script::ScriptTableItem* script = Backend::GetScriptTable()->FindScript("main_persistent");

	//if (IsValidAddress(script, "MPH", false) == STATUS_SUCCESS)
	//{
	//	// Première tentative avec le hash direct
	//	if (script != nullptr)
	//	{
	//		Hooking::HookScriptNative(script, 0x4EDE34FBADD967A6, StatGetIntHook, "MPGSI");
	//	}
	//}
	//else
	//{
	//	LOG_ERROR("[Scripts] MPH scriptTable callback failed, trying fallback...");
	//	g_hash0x = getHashFromPatternInternall("48 BA A6 67 D9 AD FB 34 DE 4E");
	//	LOG_PRINT("Alternative Hash hex: 0x%llX", g_hash0x);

	//	if (IsValidAddress(script, "MPH_Fallback", false) == STATUS_SUCCESS)
	//	{
	//		if (script != nullptr)
	//		{
	//			Hooking::HookScriptNative(script, g_hash0x, StatGetIntHook, "MPGSI");
	//		}
	//	}
	//	else
	//	{
	//		LOG_ERROR("[Scripts] MPH fallback also failed");
	//		Backend::Cleanup();
	//		return;
	//	}
	//}
	//std::thread([] {
	//	DWORD lastCheck = 0;

	//	while (true)
	//	{
	//		DWORD now = GetTickCount();

	//		if (now - lastCheck >= 1000) // vérifie chaque 1 seconde
	//		{
	//			lastCheck = now;

				static uint64_t g_hash0x = 0;

				bool hooked = Hooking::ScriptTableCallback("main_persistent", "MPH", [](Script::ScriptTableItem* script) {
					if (script != nullptr) {
						Hooking::HookScriptNative(script, 0x4EDE34FBADD967A6, StatGetIntHook, "MPGSI");
					}
					});

				if (!hooked)
				{
					g_hash0x = getHashFromPatternInternall("48 BA A6 67 D9 AD FB 34 DE 4E");
					LOG_PRINT("Alternative Hash hex: 0x%llX", g_hash0x);

					Hooking::ScriptTableCallback("main_persistent", "MPH_Fallback", [](Script::ScriptTableItem* script) {
						if (script != nullptr) {
							Hooking::HookScriptNative(script, g_hash0x, StatGetIntHook, "MPGSI");
						}
						});
				}

				mainScriptArray();

		//		break; // Stoppe la boucle après une tentative
		//	}

		//	std::this_thread::yield(); // évite de bloquer inutilement le CPU
		//}
		//}).detach();

	//////GETINT::stat_get_int
	//if (!Hooking::ScriptTableCallback("main_persistent", "MPH", [](Script::ScriptTableItem* script) {
	//	if (script != nullptr) {
	//		//Hooking::HookScriptNative(script, 0x4EDE34FBADD967A6, WaitHook, "MPW");
	//		Hooking::HookScriptNative(script, 0x4EDE34FBADD967A6, StatGetIntHook, "MPGSI");
	//	}
	//})) return;

	//	static uint64_t g_hash0x = 0;
	//	g_hash0x = getHashFromPatternInternall("48 BA A6 67 D9 AD FB 34 DE 4E");
	//	LOG_PRINT("Alternative Hash hex: 0x%llX", g_hash0x);

	//	if (!Hooking::ScriptTableCallback("main_persistent", "MPH", [](Script::ScriptTableItem* script) {
	//		if (script != nullptr) {
	//			Hooking::HookScriptNative(script, g_hash0x, StatGetIntHook, "MPGSI");
	//		}
	//		})) return;

	/*if (!Hooking::PatternCallback<void>({ "IEUD", false, 0, "40 53 48 83 EC 20 33 DB 85 C9 78 10" }, [](void* data) {
		return Hooking::HookFunction(data, &IsEntityUpsideDown, &OriginalIsEntityUpsideDown, "IEUD");
	})) return;*/

	/*if (!Hooking::PatternCallback<void>({ "SVM", false, 0, "48 8B C4 4C 89 40 18 48 89 50 10 48 89 48 08 55 53 56 57 41 54 41 55 41 56 41 57 48 8D 68 A1 48 81 EC ? ? ? ? 4D 8B F9" }, [](void* data) {
		return Hooking::HookFunction(data, &ScriptVirtualMachineHook, &OriginalScriptVirtualMachine, "SVM");
	})) return;*/

	/*if (!Hooking::PatternCallback<void>({ "IR", false, 0, "8A 05 ? ? ? ? C3 90 40 53 48 83 EC 20 48 8B 82 ? ? ? ?" }, [](void* data) {
	return Hooking::HookFunction(data, &IsRecordingHook, &originalIsRecordingHook, "IR");
	})) return;*/
	LOG_PRINT("IsAuthorized");

	while (!GetAuth()->IsAuthorized()) Sleep(500);
	LOG_PRINT("PreGameBackend");
	if (!PreGameBackend())return;
	LOG_PRINT("GameStatePlaying");
	while (GetGameState() != GameStatePlaying) Sleep(500);
	LOG_PRINT("InGameBackend");
	if (!InGameBackend())return;
	LOG_PRINT("Finalize");
	Pattern::Finalize();
	m_loaded = true;
}

typedef void(__cdecl *pPlaySoundProntend)(int soundId, String audioName, String audioRef, bool p3);
static pPlaySoundProntend OriginalPlaySoundFrontend;
void __cdecl PlaySoundFrontendHook(int soundId, String audioName, String audioRef, bool p3) {
	LOG_PRINT("%s, %s", audioName, audioRef);
	//return OriginalPlaySoundFrontend(soundId, audioName, audioRef, p3);
}

//typedef bool(_fastcall *pBGScriptFix)(__int64* rcx, __int64* rdx);
//pBGScriptFix OriginalBGScriptFix;
//bool _fastcall BGScriptFixHook(__int64* rcx, __int64* rdx) {
//	return true;
//}

void Backend::ApplyWindElementsHook(CWorldManager* worldManager) {
	const static auto setup = Pattern::Scan("AWE", "F3 0F 10 81 ? ? ? ? F3 0F 10 25 ? ? ? ? 48 8B D1");
	((void(*)(CWorldManager*))m_applyWindElementsSetup)(worldManager);

	worldManager->WindSpeed = WorldMenuVars::vars.wind;
	*(float*)((DWORD64)worldManager + 0xEB4) = (worldManager->WindSpeed * 12.0f) * *(float*)((DWORD64)GetModuleHandleA(0) + 0x278AEF0);
	*(float*)((DWORD64)worldManager + 0xEB8) = 5.0f;
}

typedef int(_fastcall *pLogMessage)(char *a1, __int64 a2, const char *a3, va_list a4);
static pLogMessage OriginalLogMessage;
int _fastcall LogMessageHook(char *a1, __int64 a2, const char *a3, va_list a4) {
	int ret = OriginalLogMessage(a1, a2, a3, a4);
	string str = a1;
	if (!str.empty() && str.find("minimap") == str.npos)
		LOG_PRINT("%s", a1);
	return ret;
}

typedef bool(*pIsDlcPresent)(Hash hash);
pIsDlcPresent OriginalIsDlcPresent;
bool IsDlcPresentHook(Hash hash) {
	if (Backend::DevMode) //Only DevMode
		return true;
	return OriginalIsDlcPresent(hash);
}

void WarningMessageHook(NativeContext* cxt) {
	return;
}

#pragma region ScriptHook
typedef FARPROC(*pGetProcAddress)(HMODULE hModule, const char* lpProcName);
pGetProcAddress OriginalGetProcAddress;
FARPROC GetProcAddressHook(HMODULE hModule, const char* lpProcName) {
//#pragma warning(push)
//#pragma warning(disable: 4302) // Désactiver l'avertissement C4302 pour cette ligne spécifique

	if ((unsigned int)hModule == 0xf9d38c98) { // penis_enlargement_pills

#ifdef HARD_DEV
		LOG_DEBUG("ScriptHookV module accessing from EAT -> %s", lpProcName);
#endif
		if (strstr(lpProcName, "nativePush64")) {
			return (FARPROC)&ScriptHookV::nativePush64;
		} else if(strstr(lpProcName, "createTexture")) {
			return (FARPROC)&ScriptHookV::createTexture;
		} else if (strstr(lpProcName, "drawTexture")) {
			return (FARPROC)&ScriptHookV::drawTexture;
		} else if (strstr(lpProcName, "getGlobalPtr")) {
			return (FARPROC)&ScriptHookV::getGlobalPtr;
		} else if (strstr(lpProcName, "scriptRegister")) {
			return (FARPROC)&ScriptHookV::scriptRegister;
		} else if (strstr(lpProcName, "keyboardHandlerRegister")) {
			return (FARPROC)&ScriptHookV::keyboardHandlerRegister;
		} else if (strstr(lpProcName, "scriptRegisterAdditionalThread")) {
			return (FARPROC)&ScriptHookV::scriptRegisterAdditionalThread;
		} else if (strstr(lpProcName, "keyboardHandlerUnregister")) {
			return (FARPROC)&ScriptHookV::keyboardHandlerUnregister;
		} else if (strstr(lpProcName, "scriptUnregister")) {
			return (FARPROC)&ScriptHookV::scriptUnregister;
		} else if (strstr(lpProcName, "nativeInit")) {
			return (FARPROC)&ScriptHookV::nativeInit;
		} else if (strstr(lpProcName, "getGameVersion")) {
			return (FARPROC)&ScriptHookV::getGameVersion;
		} else if (strstr(lpProcName, "scriptWait")) {
			return (FARPROC)&ScriptHookV::scriptWait;
		} else if (strstr(lpProcName, "nativeCall")) {
			return (FARPROC)&ScriptHookV::nativeCall;
		} else if (strstr(lpProcName, "getScriptHandleBaseAddress")) {
			return (FARPROC)&ScriptHookV::getScriptHandleBaseAddress;
		} else if (strstr(lpProcName, "presentCallbackRegister")) {
			return (FARPROC)&ScriptHookV::presentCallbackRegister;
		} else if (strstr(lpProcName, "presentCallbackUnregister")) {
			return (FARPROC)&ScriptHookV::presentCallbackUnregister;
		} else if (strstr(lpProcName, "worldGetAllVehicles")) {
			return (FARPROC)&ScriptHookV::worldGetAllVehicles;
		} else if (strstr(lpProcName, "worldGetAllPeds")) {
			return (FARPROC)&ScriptHookV::worldGetAllPeds;
		} else if (strstr(lpProcName, "worldGetAllObjects")) {
			return (FARPROC)&ScriptHookV::worldGetAllObjects;
		} else if (strstr(lpProcName, "worldGetAllPickups")) {
			return (FARPROC)&ScriptHookV::worldGetAllPickups;
		}
	}
//#pragma warning(pop)
	return OriginalGetProcAddress(hModule, lpProcName);
}
#pragma endregion

typedef uint64_t(*pRegisterGlobal)(uint64_t*, int);
pRegisterGlobal OriginalRegisterGlobal;
uint64_t RegisterGlobalHook(uint64_t* pGlobalIndexPtr, int iVarCount) {
	auto resp = OriginalRegisterGlobal(pGlobalIndexPtr, iVarCount);

	// the way the game does it
	//auto ptr = ((uint64_t(*)())Pattern::Scan("nigger faggot", "40 53 48 83 EC 20 E8 ? ? ? ? 48 8B D8 48 85 C0 74 12"))();
	//if (ptr) {
	//	ptr = ((uint64_t(*)())Pattern::Scan("nigger faggot", "40 53 48 83 EC 20 E8 ? ? ? ? 48 8B D8 48 85 C0 74 12"))();
	//	if (ptr) {
	//		ptr = ((uint64_t(*)())Pattern::Scan("nigger faggot", "40 53 48 83 EC 20 E8 ? ? ? ? 48 8B D8 48 85 C0 74 12"))();
	//		if (*(uint64_t*)(ptr + 0x48)) {
	//			LOG_PRINT("Global shit: 0x%llx : %i", pGlobalIndexPtr, iVarCount);
	//			/*static bool titties = false;
	//			if (!titties) {
	//				titties = true;

	//				void* address = &Backend::GetGlobalPtr()[0x41272 >> 18 & 0x3F][0x41272 & 0x3FFFF];
	//				OriginalRegisterGlobal((uint64_t*)address, 1);
	//			}*/
	//		}
	//	}
	//}

	return resp;
}

typedef bool(*tRockstarID)(__int64 rcx, __int64 rdx, int r8d);
tRockstarID OriginalRockstarID;
bool RockstarIDHook(__int64 rcx, __int64 rdx, int r8d) {
	//LOG_DEBUG("Syncing R* ID %i", rdx);
	if (rdx && (rdx == Backend::m_originalRID || rdx == Backend::m_spoofingRID)) {
		if (NetEvent::vars.rockstarid) {
			return OriginalRockstarID(rcx, Backend::m_spoofingRID, r8d);
		}
	}

	return OriginalRockstarID(rcx, rdx, r8d);
}

typedef bool(*tNewRockstartID)(__int64 rcx, __int64 rdx, int r8d, __int64 r9);
tNewRockstartID OriginalNewRockstarID;
bool NewRockstarIDHook(__int64 rcx, __int64 rdx, int r8d, __int64 r9) {
	static char tempBuffer[0x50];

	if (rcx) {
		auto currentID = *(__int64*)rcx;

		if (currentID && (currentID == Backend::m_originalRID || currentID == Backend::m_spoofingRID)) {
			if (NetEvent::vars.rockstarid) {
				memcpy(tempBuffer, (void*)rcx, 0x50);
				*(__int64*)tempBuffer = Backend::m_spoofingRID;
				return OriginalNewRockstarID((__int64)&tempBuffer, rdx, r8d, r9);
			}
		}
	}

	return OriginalNewRockstarID(rcx, rdx, r8d, r9);
}

// can we get cameron to fix this? he wont touch gta i already asked him ok what about g?


//typedef uint64_t(*tUpdatePedSync)(uint64_t rcx, CNetGamePlayer* pPlayer, uint64_t r8, uint64_t r9, uint64_t unk, bool bSendImmediately);
//tUpdatePedSync OriginalUpdatePedSync;
//uint64_t UpdatePedSyncHook(uint64_t rcx, CNetGamePlayer* pPlayer, uint64_t r8, uint64_t r9, uint64_t unk, bool bSendImmediately) {
//	if (SpoofingMenuVars::vars.spoofpedlocation) {
//		if (pPlayer) {
//			if (pPlayer->m_playerID != GetLocalPlayer().m_id) {
//				return 0;
//			}
//		}
//	}
//    return OriginalUpdatePedSync(rcx, pPlayer, r8, r9, unk, bSendImmediately);
//}


void	failPat(const char* name)
{
	LOG_PRINT("Failed to find %s pattern.", name);
	exit(0);
}

template <typename T>
void	setPat
(
	const char* name,
	char* pat,
	char* mask,
	T** out,
	bool		rel,
	int			offset = 0,
	int			deref = 0,
	int			skip = 0
)
{
	T* ptr = nullptr;

	CPattern pattern(pat, mask);
	pattern.find(1 + skip);
	if (rel)
		ptr = pattern.get(skip).get_rel<T>(offset);
	else
		ptr = pattern.get(skip).get<T>(offset);

	while (true)
	{
		if (ptr == nullptr)
			failPat(name);

		if (deref <= 0)
			break;
		ptr = *(T**)ptr;
		--deref;
	}

	*out = ptr;
	return;
}

template <typename T>
void	setFn
(
	const char* name,
	char* pat,
	char* mask,
	T* out,
	int			skip = 0
)
{
	char* ptr = nullptr;

	CPattern pattern(pat, mask);
	pattern.find(1 + skip);
	ptr = pattern.get(skip).get<char>(0);

	if (ptr == nullptr)
		failPat(name);

	*out = (T)ptr;
	return;
}
std::vector<LPVOID> m_hooks;
HMODULE _hmoduleDLL;



#define GXLPARAM(lp) ((short)LOWORD(lp))
#define GYLPARAM(lp) ((short)HIWORD(lp))

InputHook iHook;
WNDPROC	oWndProc;

//using namespace Utility;

static std::set<InputHook::TKeyboardFn> g_keyboardFunctions;

void InputHook::keyboardHandlerRegister(TKeyboardFn function) {

	g_keyboardFunctions.insert(function);
}

void InputHook::keyboardHandlerUnregister(TKeyboardFn function) {

	g_keyboardFunctions.erase(function);
}
const int KEYS_SIZE = 255;
struct {
	DWORD time;
	BOOL isWithAlt;
	BOOL wasDownBefore;
	BOOL isUpNow;
} keyStates[KEYS_SIZE];

void OnKeyboardMessage(DWORD key, WORD repeats, BYTE scanCode, BOOL isExtended, BOOL isWithAlt, BOOL wasDownBefore, BOOL isUpNow)
{
	if (key < KEYS_SIZE)
	{
		keyStates[key].time = GetTickCount();
		keyStates[key].isWithAlt = isWithAlt;
		keyStates[key].wasDownBefore = wasDownBefore;
		keyStates[key].isUpNow = isUpNow;
	}
}

bool InputHook::Initialize() {

	hWindow = NULL;
	while (hWindow == NULL) {

		hWindow = FindWindow(L"grcWindow", NULL);
		Sleep(100);
	}
	oWndProc = (WNDPROC)SetWindowLongPtr(hWindow, GWLP_WNDPROC, (__int3264)(LONG_PTR)WndProc);
	if (oWndProc == NULL) {

		//Log::Error("Failed to attach input hook");
		return false;
	}
	else {

		keyboardHandlerRegister(OnKeyboardMessage);
		//DEBUGMSG("Input hook attached:  WndProc 0x%p", (DWORD_PTR)oWndProc);
		return true;
	}
}

void InputHook::Remove() {

	SetWindowLongPtr(hWindow, GWLP_WNDPROC, (LONG_PTR)oWndProc);
	//DEBUGMSG("Removed input hook");
}

LRESULT APIENTRY WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_SIZE:
		break;
	case WM_LBUTTONDOWN:
		break;
	case WM_LBUTTONUP:
		break;
	case WM_RBUTTONDOWN:
		break;
	case WM_RBUTTONUP:
		break;
	case WM_MBUTTONDOWN:
		break;
	case WM_MBUTTONUP:
		break;
	case WM_MOUSEWHEEL:
		break;
	case WM_MOUSEMOVE:
		break;
	case WM_KEYDOWN: case WM_KEYUP: case WM_SYSKEYDOWN: case WM_SYSKEYUP:
	{
		auto functions = g_keyboardFunctions; for (auto& function : functions) function((DWORD)wParam, lParam & 0xFFFF, (lParam >> 16) & 0xFF, (lParam >> 24) & 1, (uMsg == WM_SYSKEYDOWN || uMsg == WM_SYSKEYUP), (lParam >> 30) & 1, (uMsg == WM_SYSKEYUP || uMsg == WM_KEYUP));
	}
	break;
	case WM_CHAR:
		break;
	}

	return CallWindowProc(oWndProc, hwnd, uMsg, wParam, lParam);

}


DWORD WINAPI CleanupThread(LPVOID lpParam)
{
	for (int i = 0; i < m_hooks.size(); i++)
		MH_QueueDisableHook(m_hooks[i]);
	MH_ApplyQueued();
	MH_Uninitialize();
	iHook.Remove();
	FreeLibraryAndExitThread(_hmoduleDLL, 0);
}

void Cleanup()
{
	CreateThread(nullptr, THREAD_ALL_ACCESS, CleanupThread, nullptr, NULL, nullptr);
}
void FailPatterns(const char* name)
{
	char buf[4096];
	sprintf_s(buf, "finding %s", name);
	//Log::Error(buf);
	Cleanup();
}

__int64** Hooked::m_globalPtr2;

__int64** Hooked::getGlobalPtr2()
{
	return m_globalPtr2;
}
__int64** Hooked::m_globalPtr;
__int64** Hooked::getGlobalPtr()
{
	return Hooked::m_globalPtr;
}
uint64_t Hooked::m_worldPtr;
uint64_t Hooked::getWorldPtr()
{
	return m_worldPtr;
}

fpDrawRect							CHooking::draw_rect;
fpDrawNotification					CHooking::draw_notification;

bool userspoof = 0;
void* OriginalPTR::m_OriginalNetworkInfo = nullptr;
//bool hooks::send_net_info_to_lobby(rage2::rlGamerInfo* player, int64_t a2, int64_t a3, DWORD* a4)
bool Hooks::send_net_info_to_lobby(rage::rlGamerInfo* player, int64_t a2, int64_t a3, DWORD* a4)
{
	/*if (ENTITY::DOES_ENTITY_EXIST(Hooking::get_player_ped(Features::playerme)))
	{
	}
	else
	{*/
	/*if (PLAYER::GetPlayerPedScriptIndex(Features::playerme) == PLAYER::PlayerPedId() && NETWORK::NetworkGetHostOfScript("freemode", -1, 0) == Features::playerme) {
		userspoof = 1;
	}
	else
	{
		userspoof = 0;
	}*/
	//const bool is_local_player = g_local_player->m_player_info->m_net_player_data.m_gamer_handle_2.m_rockstar_id == player->m_gamer_handle_2.m_rockstar_id;

	//// check so we're 100% sure we modify data only for ourselves
	//if (is_local_player)
	//{
	/*if (userspoof)
	{
		if (Hookings::m_Name == "")
		{
			Hookings::m_Name = "Thunder-Menu";
		}
		if (Menu_Settings2::spoof_username)
			memcpy(player->m_name, Hookings::m_Name.c_str(), sizeof(player->m_name));
	}*/
	//memcpy(player->m_name, g_local_player->m_player_info->m_net_player_data.m_name, sizeof(player->m_name));
	//memcpy(player->m_name, "Thunder-Menu", sizeof(player->m_name));/*ggg->spoofing.username.c_str()*/

/*if (ggg->spoofing.spoof_rockstar_id)
{
	player->m_rockstar_id = ggg->spoofing.rockstar_id;
	player->m_rockstar_id = ggg->spoofing.rockstar_id;
}*/
//if (Menu_Settings2::spoof_rockstar_id)
//{
//	if (Hookings::IDSpoof != "")
//	{
//		Menu_Settings2::rockstar_id = atoi(Hookings::IDSpoof.c_str());
//	}
//	if (std::stoull(GetPlayerRID(PLAYER::PLAYER_ID())) == player->m_rockstar_id)
//	{
//		player->m_rockstar_id = Menu_Settings2::rockstar_id;
//		player->m_rockstar_id2 = Menu_Settings2::rockstar_id;
//	}
//	/*if (std::stoull(GetPlayerRID(PLAYER::PLAYER_ID())) == player->m_peer_id)
//	{
//		player->m_peer_id = Menu_Settings2::rockstar_id;
//		player->m_gamer_handle_2 = Menu_Settings2::rockstar_id;
//	}*/
//	
//}
	//if (Menu_Settings2::spoof_ip)
	//{
	//	if (Hookings::IPSpoof != "")
	//	{
	//		/*const char point = '.';
	//		const char virgulespace = ', ';
	//		std::replace(Hookings::IPSpoof.begin(), Hookings::IPSpoof.end(), point, virgulespace);
	//		Hookings::IPSpoofarray[0] = Hookings::IPSpoof;

	//		Menu_Settings2::ip_address[0] = atoi(Hookings::IPSpoofarray[0].c_str());
	//		Menu_Settings2::ip_address[1] = atoi(Hookings::IPSpoofarray[1].c_str());
	//		Menu_Settings2::ip_address[2] = atoi(Hookings::IPSpoofarray[2].c_str());
	//		Menu_Settings2::ip_address[3] = atoi(Hookings::IPSpoofarray[3].c_str());*/
	//		std::string point = ".";
	//		std::string space = " ";
	//		size_t pos = Hookings::IPSpoof.find(point);
	//		while (pos != std::string::npos)
	//		{
	//			Hookings::IPSpoof.replace(pos, point.size(), space);
	//			pos = Hookings::IPSpoof.find(point, pos + space.size());
	//		}
	//		std::vector<std::string> words = split5(Hookings::IPSpoof, ' ');
	//		Menu_Settings2::ip_address[0] = atoi(words[0].c_str());
	//		Menu_Settings2::ip_address[1] = atoi(words[1].c_str());
	//		Menu_Settings2::ip_address[2] = atoi(words[2].c_str());
	//		Menu_Settings2::ip_address[3] = atoi(words[3].c_str());
	//	}
	//	player->m_external_ip.m_field1 = Menu_Settings2::ip_address[0];
	//	player->m_external_ip.m_field2 = Menu_Settings2::ip_address[1];
	//	player->m_external_ip.m_field3 = Menu_Settings2::ip_address[2];
	//	player->m_external_ip.m_field4 = Menu_Settings2::ip_address[3];

	//	player->m_internal_ip.m_field1 = Menu_Settings2::ip_address[0];
	//	player->m_internal_ip.m_field2 = Menu_Settings2::ip_address[1];
	//	player->m_internal_ip.m_field3 = Menu_Settings2::ip_address[2];
	//	player->m_internal_ip.m_field4 = Menu_Settings2::ip_address[3];

	//}
	//if (userspoof)
	//{
	//	if (Hookings::m_Name == "")
	//	{
	//		Hookings::m_Name = "Thunder-Menu";
	//	}
	//	if (Menu_Settings2::spoof_username)
	//		memcpy(player->m_name, Hookings::m_Name.c_str(), sizeof(player->m_name));
	//}
	//if (ggg->notifications.send_net_info_to_lobby.log)
	//{ }
	//	//LOG(INFO) << "Sending spoofed values to session host";
	//if (ggg->notifications.send_net_info_to_lobby.notify)
	//{
	//}
	//	//g_notification_service->push("Player Info Spoofing", "Sent spoofed values to lobby host.");
/*}*/

//const auto result = g_hooking2->/*get_original*/m_OriginalNetworkInfo<hooks::send_net_info_to_lobby>()(player, a2, a3, a4);

// restore player name to prevent detection of spoofed name
/*if (is_local_player && ggg->spoofing.spoof_username)
	memcpy(player->m_name, g_local_player->m_player_info->m_net_player_data.m_name, sizeof(player->m_name));*/
	return static_cast<decltype(&send_net_info_to_lobby)>(OriginalPTR::m_OriginalNetworkInfo)(player, a2, a3, a4);
	/*return result;*/
}

bool GetLabelText_checked = 0;
using fpGetLabelText = const char* (*) (void* this_, const char* label);
fpGetLabelText          GetLabelText = nullptr;

struct LabelTextWrapper {
	fpGetLabelText original;

	LabelTextWrapper(fpGetLabelText ptr) : original(ptr) {}

	operator pGetGxtText() const {
		return reinterpret_cast<pGetGxtText>(original);
	}
};

fpGetLabelText ogGetLabelText = nullptr;
const char* __cdecl hkGetLabelText(void* this_, const char* label)
{
	if (std::strcmp(label, "HUD_JOINING") == 0)
	{
		//Features::onlineplayer = true;
		return "Loading Online With Thunder-Menu.com";
	}
	if (std::strcmp(label, "HUD_QUITTING") == 0)
	{
		//Features::onlineplayer = false;
		return "Leave Online With Thunder-Menu.com";
	}
	if (std::strcmp(label, "PM_QUIT_MP") == 0)
	{
		//Features::onlineplayer = false;
		return "Leave Online with Thunder-Menu.com";
	}
	if (std::strcmp(label, "PM_ENTER_MP") == 0)
	{
		//Features::onlineplayer = true;
		return "Join Online with Thunder-Menu.com";
	}
	if (std::strcmp(label, "PM_EXIT_GAME") == 0)
	{
		//Features::onlineplayer = false;
		return "Exit Game with Thunder-Menu.com";
	}
	if (std::strcmp(label, "PM_GO") == 0)
	{
		//Features::onlineplayer = true;
		return "GO Online with Thunder-Menu.com";
	}
	if (std::strcmp(label, "PM_GOTO_STORE") == 0)
	{
		return "GOTO STORE with Thunder-Menu.com";
	}
	if (std::strcmp(label, "PM_FRIEND_FM") == 0)
	{
		//Features::onlineplayer = true;
		return "Join Friend with Thunder-Menu.com";
	}
	if (std::strcmp(label, "PM_FIND_SESS") == 0)
	{
		//Features::onlineplayer = true;
		return "Find New Session with Thunder-Menu.com";
	}
	return ogGetLabelText(this_, label);
}
bool getLT()
{
	bool GetLabelText_check1 = checkpattern("48 89 5C 24 ? 57 48 83 EC 20 48 8B DA 48 8B F9 48 85 D2 75 44 E8");
	if (GetLabelText_check1)
	{
		GetLabelText_checked = 1;
		GetLabelText = static_cast</*pGetGxtText*/fpGetLabelText>(Memory2::pattern("48 89 5C 24 ? 57 48 83 EC 20 48 8B DA 48 8B F9 48 85 D2 75 44 E8").count(1).get(0).get<void>(0));
		LOG_PRINT("GetLabelText 48 89 5C 24 ? 57 48 83 EC 20 48 8B DA 48 8B F9 48 85 D2 75 44 E8");
		LabelTextWrapper wrapper(GetLabelText);
		OriginalGetGxtText = wrapper; // auto-converted using the operator
	}
	else
	{
		bool GetLabelText_check2 = checkpattern("48 C1 E0 06 48 03 C1 C6 00 00 48 8B 5C 24");
		if (GetLabelText_check2)
		{
			GetLabelText_checked = 1;
			GetLabelText = static_cast</*pGetGxtText*/fpGetLabelText>(Memory2::pattern("48 C1 E0 06 48 03 C1 C6 00 00 48 8B 5C 24 - 0x44").count(1).get(0).get<void>(0));
			LOG_PRINT("Alternative 2 GetLabelText 48 C1 E0 06 48 03 C1 C6 00 00 48 8B 5C 24 - 0x44");
			LabelTextWrapper wrapper(GetLabelText);
			OriginalGetGxtText = wrapper; // auto-converted using the operator
		}
		else
		{
			bool GetLabelText_check3 = checkpattern("48 8D 0D B0 50 96 01");
			if (GetLabelText_check3)
			{
				GetLabelText_checked = 1;
				GetLabelText = static_cast</*pGetGxtText*/fpGetLabelText>(Memory2::pattern("48 8D 0D B0 50 96 01 - 3E").count(1).get(0).get<void>(0));
				LOG_PRINT("Alternative 3 GetLabelText 48 8D 0D B0 50 96 01 - 3E");
				LabelTextWrapper wrapper(GetLabelText);
				OriginalGetGxtText = wrapper; // auto-converted using the operator
			}
		}
	}
	if (GetLabelText_checked)
	{

		MH_STATUS status3 = MH_CreateHook(GetLabelText, &hkGetLabelText, (void**)&ogGetLabelText);
		if ((status3 != MH_OK && status3 != MH_ERROR_ALREADY_CREATED) || MH_EnableHook(GetLabelText) != MH_OK)
		{
			LOG_PRINT("Hook Status3 %s", MH_StatusToString(status3));
			return false;
		}
		LOG_PRINT("Hook Succeed Status3 %s", MH_StatusToString(status3));
		m_hooks.push_back(GetLabelText);
	}
	return 0;
}

bool Backend::PreGameBackend() {
	if (!Security::PreGame()) return false;
	if (!Anticheat::PreGame()) return false;
	if (!ModelSwapping::PreGame()) return false;
	if (!Explosions::PreGame()) return false;
	if (!Protection::PreGame()) return false;
	if (!PoolManager::Initialize()) return false;
	if (!NetEvent::Initialize()) return false;

	if (!GetVFX()->Initialize()) return false;

	TransactionManager::Initialize();

	//Pattern::putVP((uint64_t)GetModuleHandleA(0) + 0x11420A4, 0xC3);
	//Pattern::putVP((uint64_t)GetModuleHandleA(0) + 0x161DBE4, 0xC3);

	//Pattern::nop((uint64_t)GetModuleHandleA(0) + 0x1569b44, 3);
	//Hooking::HookFunction(SetAddressTypeForUse<void>(Pattern::Scan("nifnifn", "48 89 5C 24 ? 57 48 83 EC 20 8B DA 48 8B F9 C1 E3 03")), &RegisterGlobalHook, &OriginalRegisterGlobal, "penis saitsfier");

	/*SHV*/
	if (GetAuth()->IsVIP())
		Hooking::HookFunction(&GetProcAddress, &GetProcAddressHook, reinterpret_cast<LPVOID*>(&OriginalGetProcAddress), "SHV-GPA");

	///*Music*/
	//if (!Hooking::ServerPatternCallback<void>("M", [](Hooking::CallbackData<void> data) {
	//	Pattern::returnFunction(data.m_address);
	//})) return false;

	///*Drawable Pool*/
	//if (!Hooking::ServerPatternCallback<char>("NEPP", [](Hooking::CallbackData<char> data) {
	//	WorldDrawablesVars::vars.entityPoolPointer = reinterpret_cast<uintptr_t*>(GetAddressFromInstruction(data.m_address));
	//})) return false;

	///*Drawable Pool Building VTable*/
	//if (!Hooking::ServerPatternCallback<char>("DVTA", [](Hooking::CallbackData<char> data) {
	//	WorldDrawablesVars::vars.entityClasses.push_back(GetAddressFromInstruction(data.m_address));
	//})) return false;

	///*Legals*/
	//if (!Hooking::ServerPatternCallback<void>("L", [](Hooking::CallbackData<void> data) {
	//	Pattern::nop(data.m_address, 2);
	//})) return false;

	getLT();

	/*GXT*/
	/*if (!Hooking::ServerPatternCallback<char>("GXT", [](Hooking::CallbackData<char> data) {
		return Hooking::HookFunction(data, &GetGxtTextHook, &OriginalGetGxtText);
	})) return false;*/

	g_GameFunctions = std::make_unique<GameFunctions1>();
	g_GameVariables = std::make_unique<GameVariables1>();
	/*Game State Pointer*/
	//if (!Hooking::ServerPatternCallback<char>("GSP", [](Hooking::CallbackData<char> data) {
//	/*m_gameState = reinterpret_cast<decltype(m_gameState)>(data.m_address + *reinterpret_cast<int32_t*>(data.m_address) + 5);*/
	//	})) return false;
	/*m_gameState = reinterpret_cast<GameState*>(g_GameVariables->m_GameState);*/
	//m_gameState = g_GameVariables->m_GameState;
	//m_gameState = reinterpret_cast<decltype(m_gameState)>(g_GameVariables->m_GameState + *(int32_t*)g_GameVariables->m_GameState + 5);
	m_gameState = static_cast<GameState*>(g_GameVariables->m_GameState);

	auto p_globalPtr = Memory2::pattern("4C 8D 05 ? ? ? ? 4D 8B 08 4D 85 C9 74 11");
	//auto p_gameState = Memory2::pattern("83 3D ? ? ? ? ? 75 17 8B 43 20 25");


	char* c_location = nullptr;

	/*c_location = p_gameState.count(1).get(0).get<char>(2);
	c_location == nullptr ? FailPatterns("gameState") : m_gameState = reinterpret_cast<decltype(m_gameState)>(c_location + *(int32_t*)c_location + 5);
	std::cout << "m_gameState" << std::endl;*/

	/*Global Pointer*/
	//if (!Hooking::ServerPatternCallback<char>("GP", [](Hooking::CallbackData<char> data) {
	//	m_globalPtr = (_int64**)GetAddressFromInstruction(data.m_address);
	//})) return false;

	c_location = p_globalPtr.count(1).get(0).get<char>(0);
	__int64 patternAddr = NULL;
	c_location == nullptr ? FailPatterns("globalTable") : patternAddr = reinterpret_cast<decltype(patternAddr)>(c_location);
	m_globalPtr = (__int64**)(patternAddr + *(int*)(patternAddr + 3) + 7);

	std::cout << "m_globalPtr" << std::endl;
	/*World Pointer*/
	/*if (!Hooking::ServerPatternCallback<char>("WP", [](Hooking::CallbackData<char> data) {
		m_worldPtr = GetAddressFromInstruction(data.m_address);
	})) return false;*/
	//static uint64_t GetWorldPtr() { return g_GameVariables->m_WorldBase; }
	m_worldPtr = g_GameVariables->m_WorldBase;
	std::cout << "m_worldPtr" << std::endl;
	/*Tunables*/
	if (!Hooking::ServerPatternCallback<char>("T", [](Hooking::CallbackData<char> data) {
		m_tunables = GetAddressFromInstruction(data.m_address);
	})) return false;
	std::cout << "m_tunables" << std::endl;
	///*RoutingData*/
	//if(!Hooking::PatternCallback<char>({"RD", true, -0x16, "BA ? ? ? ? 48 8B D9 E8 ? ? ? ? 48 8B D0" }, [](char *address) {
	//	m_getRoutingData = static_cast<void *>(address);
	//})) return false;

	bool pattern_modelCheck_check = checkpattern("48 85 C0 0F 84 ? ? ? ? 8B 48 50");
	if (pattern_modelCheck_check)
	{
		LOG_PRINT("Model Check..");
		CPattern pattern_modelCheck("\x48\x85\xC0\x0F\x84\x00\x00\x00\x00\x8B\x48\x50", "xxxxx????xxx");
		auto ptr = pattern_modelCheck.find(0).get(0).get<char>(0);
		ptr == nullptr ? LOG_PRINT("Failed to find modelCheck_pattern") : Memory2::nop(ptr, 24);
	}
	else
	{
		LOG_PRINT("Alternative Model Check.. 48 85 C0 74 21 E8 44 - 0x22");
		//48 85 C0 74 21 E8 44 - 0x22
		CPattern pattern_modelCheck("\x48\x85\xC0\x74\x21\xE8\x44 - 0x22", "xxxxxxx");
		auto ptr = pattern_modelCheck.find(0).get(0).get<char>(0);
		ptr == nullptr ? LOG_PRINT("Failed to find modelCheck_pattern") : Memory2::nop(ptr, 24);
	}
	bool pattern_modelSpawn_check = checkpattern("48 8B C8 FF 52 30 84 C0 74 05 48");
	if (pattern_modelSpawn_check)
	{
		LOG_PRINT("Bypassing Object restrictions..");
		CPattern pattern_modelSpawn("\x48\x8B\xC8\xFF\x52\x30\x84\xC0\x74\x05\x48", "xxxxxxxxxxx");
		auto ptr2 = pattern_modelSpawn.find(0).get(0).get<char>(8);
		ptr2 == nullptr ? LOG_PRINT("Failed to find modelSpawn_pattern") : Memory2::nop(ptr2, 2);
	}
	else
	{
		LOG_PRINT("Alternative Bypassing Object restrictions.. 48 83 EC 28 80 3D B1 79 - 0x22");
		CPattern pattern_modelSpawn("\x48\x83\xEC\x28\x80\x3D\xB1\x79 - 0x22", "xxxx?xxx");
		auto ptr2 = pattern_modelSpawn.find(0).get(0).get<char>(8);
		ptr2 == nullptr ? LOG_PRINT("Failed to find modelSpawn_pattern") : Memory2::nop(ptr2, 2);
	}

	////Log::Msg("Model Check..");
	//CPattern pattern_modelCheck("\x48\x85\xC0\x0F\x84\x00\x00\x00\x00\x8B\x48\x50", "xxxxx????xxx");
	//auto ptr = pattern_modelCheck.find(0).get(0).get<char>(0);
	//ptr == nullptr ? LOG_PRINT("Failed to find modelCheck_pattern") : Memory2::nop(ptr, 24);

	////Log::Msg("Bypassing Object restrictions..");
	//CPattern pattern_modelSpawn("\x48\x8B\xC8\xFF\x52\x30\x84\xC0\x74\x05\x48", "xxxxxxxxxxx");
	//ptr = pattern_modelSpawn.find(0).get(0).get<char>(8);
	//ptr == nullptr ? LOG_PRINT("Failed to find modelSpawn_pattern") : Memory2::nop(ptr, 2);
	bool GetPlayerAddress_check = checkpattern("40 53 48 83 EC 20 33 DB 38 1D ? ? ? ? 74 1C");
	if (GetPlayerAddress_check)
	{
		setFn<fpGetPlayerAddress>("GetPlayerAddress",
			"\x40\x53\x48\x83\xEC\x20\x33\xDB\x38\x1D\x00\x00\x00\x00\x74\x1C",
			"xxxxxxxxxx????xx",
			&Hooked::GetPlayerAddress);
	}
	/*48 8B 05 ? ? ? ? 45 ? ? ? ? 48 8B 48 08 48 85 C9 74 07*/

	bool AddressToEntity_check = checkpattern("48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 20 8B 15 ? ? ? ? 48 8B F9 48 83 C1 10 33 DB");
	if (AddressToEntity_check)
	{
		setFn<fpAddressToEntity>("AddressToEntity",
			"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x8B\x15\x00\x00\x00\x00\x48\x8B\xF9\x48\x83\xC1\x10\x33\xDB",
			"xxxx?xxxx?xxxxxxx????xxxxxxxxx",
			&Hooked::AddressToEntity);
	}
	bool get_player_name_check = checkpattern("40 53 48 83 EC 20 80 3D ? ? ? ? ? 8B D9 74 22");
	if (get_player_name_check)
	{
		setFn<fpGetPlayerName>("get_player_name",
			"\x40\x53\x48\x83\xEC\x20\x80\x3D\x00\x00\x00\x00\x00\x8B\xD9\x74\x22",
			"xxxxxxxx?????xxxx",
			&Hooked::get_player_name);
	}

	bool create_vehicle_check = checkpattern("48 89 5C 24 ? 55 56 57 41 54 41 55 41 56 41 57 48 8B EC 48 83 EC 50 F3 0F 10 02");
	if (create_vehicle_check)
	{
		setFn<fpCreateVehicle>("create_vehicle",
			"\x48\x89\x5C\x24\x00\x55\x56\x57\x41\x54\x41\x55\x41\x56\x41\x57\x48\x8B\xEC\x48\x83\xEC\x50\xF3\x0F\x10\x02",
			"xxxx?xxxxxxxxxxxxxxxxxxxxxx",
			&Hooked::create_vehicle);
	}

	//setFn<fpworldscreen>("world_screen",
	//	"\x48\x89\x5C\x24\x00\x55\x56\x57\x48\x83\xEC\x70\x65\x4C\x8B\x0C\x25",
	//	"xxxx?xxxxxxxxxxxx",
	//	&Hooked::world_screen); //48 89 5C 24 ? 55 56 57 48 83 EC 70 65 4C 8B 0C 25
	bool draw_rect_check = checkpattern("48 8B C4 48 89 58 08 57 48 83 EC 70 48 63 0D ? ? ? ? 0F");
	if (draw_rect_check)
	{
		setFn<fpDrawRect>("draw_rect",
			"\x48\x8B\xC4\x48\x89\x58\x08\x57\x48\x83\xEC\x70\x48\x63\x0D\x00\x00\x00\x00\x0F",
			"xxxxxxxxxxxxxxx????x",
			&CHooking::draw_rect);
	}

	bool draw_notification_check = checkpattern("48 89 5C 24 ? 48 89 74 24 ? 57 48 81 EC ? ? ? ? 83 3D ? ? ? ? ? 41 8A D8");
	if (draw_notification_check)
	{
		setFn<fpDrawNotification>("draw_notification",
			"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x81\xEC\x00\x00\x00\x00\x83\x3D\x00\x00\x00\x00\x00\x41\x8A\xD8",
			"xxxx?xxxx?xxxx????xx?????xxx",
			&CHooking::draw_notification);
	}

	bool trigger_script_event_check = checkpattern("48 8B C4 48 89 58 08 48 89 70 10 48 89 78 18 55 41 56 41 57 48 8D A8 68 ? ? ? ? 81 EC 80 02 ? ? 45 8B");
	if (trigger_script_event_check)
	{
		setFn<fpTriggerScriptEvent>("trigger_script_event",
			"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x70\x10\x48\x89\x78\x18\x55\x41\x56\x41\x57\x48\x8D\xA8\x68\x00\x00\x00\x00\x81\xEC\x80\x02\x00\x00\x45\x8B",
			"xxxxxxxxxxxxxxxxxxxxxxxx????xxxx??xx",
			&Hooked::trigger_script_event);
	}

	void* v_location = nullptr;

	auto p_fixVectorResult = Memory2::pattern("83 79 18 00 48 8B D1 74 4A FF 4A 18");
	v_location = p_fixVectorResult.count(1).get(0).get<void>(0);
	if (v_location != nullptr) rage::scrNativeCallContext::SetVectorResults = (void(*)(rage::scrNativeCallContext*))(v_location);

	/*char m_globalPtr2[100];
	sprintf_s(m_globalPtr2, (char*)"0x%#p 0x%llX", (char*)m_globalPtr - Memory2::get_base());*/
	//Log::Msg(m_globalPtr2);

//g_CallbackScript = std::make_shared<CallbackScript>();

	////*Model Check Fixed*/
	//if (!Hooking::ServerPatternCallback<void>("NMCF", [](Hooking::CallbackData<void> data) {
	//	Pattern::putVP(data.m_address, 0x16EB);
	//})) return false;

	///*Model Patch Fixed*/
	//if (!Hooking::ServerPatternCallback<void>("NMPF", [](Hooking::CallbackData<void> data) {
	//	Pattern::putVP(data.m_address, 0x02EB);
	//})) return false;

	/*Model Bypass If Networked*/
	/*if(!Hooking::PatternCallback<char>({"GIN", true, -0x0B, "48 8B D8 48 85 C0 74 12 48 8B 10 48 8B C8 FF 52 30" }, [](char *address) {
		*(BYTE*)address = 0xEB;
		*((BYTE*)address + 1) = 0xDA;
	})) return false;*/

	/////*Is In Spectator check request control event*/
	////if (!Hooking::ServerPatternCallback<char>("IIS", [](Hooking::CallbackData<char> data) {
	////	Pattern::nop(data.m_address, 4);
	////})) return false;

	///*Send increment stat event*/
	///*if (!Hooking::ServerPatternCallback<void>("SISE", [](Hooking::CallbackData<void> data) {
	//	fSendIncrementStatEvent = (pSendIncrementStatEvent)data.m_address;
	//})) return false;*/

	///*Is In Session*/
	//if (!Hooking::ServerPatternCallback<char>("IISS", [](Hooking::CallbackData<char> data) {
	//	m_isInSession = GetAddressFromInstruction(data.m_address, 0, 2, 6);
	//})) return false;

	/*Script Pointer*/
	if (!Hooking::ServerPatternCallback<char>("SP", [](Hooking::CallbackData<char> data) {
		m_scriptTable = (Script::ScriptTable*)GetAddressFromInstruction(data.m_address);
	})) return false;

	/*Register File*/
	if (!Hooking::ServerPatternCallback<char>("RSF", [](Hooking::CallbackData<char> data) {
		RegisterFileFn = (pRegisterFileFn)data.m_address;
	})) return false;

	/*Network Player Manager*/
	if (!Hooking::ServerPatternCallback<char>("NPM", [](Hooking::CallbackData<char> data) {
		m_networkPlayerManager = GetAddressFromInstruction(data.m_address);
	})) return false;

	/*Handle Chat*/
	/*if (!Hooking::ServerPatternCallback<char>("HC", [](Hooking::CallbackData<char> data) {
		return Hooking::HookFunction((char*)GetAddressFromInstruction(data.m_address, 0, 1, 5), &HandleChatHook, &OriginalHandleChat, "HC");
	})) return false;*/

	/*Is DLC Present*/
	if (!Hooking::ServerPatternCallback<char>("IDP", [](Hooking::CallbackData<char> data) {
		return Hooking::HookFunction(data.m_address, &IsDlcPresentHook, &OriginalIsDlcPresent, "IDP");
	})) return false;

	///*GameplayCam*/
	//if (!Hooking::ServerPatternCallback<char>("GPC", [](Hooking::CallbackData<char> data) {
	//	m_gameplayCam = GetAddressFromInstruction(data.m_address);
	//})) return false;

	///*NetCatalog*/
	///*if (!Hooking::ServerPatternCallback<char>("TNC", [](Hooking::CallbackData<char> data) {
	//	m_netCatalog = *reinterpret_cast<NetCatalog **>(GetAddressFromInstruction(data.m_address));
	//})) return false;*/

	///*TunableStruct*/
	//if (!Hooking::ServerPatternCallback<char>("TSS", [](Hooking::CallbackData<char> data) {
	//	m_tunableStruct = *reinterpret_cast<Tunables **>(GetAddressFromInstruction(data.m_address));
	//})) return false;
	MH_CreateHook(g_GameVariables->m_NetworkInfo, &Hooks::send_net_info_to_lobby, (void**)&OriginalPTR::m_OriginalNetworkInfo);

	Session::Initialize();

	Socialclub::Initialize();

	Inventory::Initialize();

	///*Network is online*/
	//if (!Hooking::PatternCallback<char>({ "NIO", false, 0x0, "48 8B 0D ? ? ? ? 33 C0 48 85 C9 74 0D 39 81 ? ? ? ? 74 05 B8 ? ? ? ? C3 48 8B 15 ? ? ? ?" }, [](char* address) {
	//	m_networkPlayerData = GetAddressFromInstruction(address);
	//	m_networkPlayerIsOnlineOffset = 0x7474;
	//})) {
	//	if (!Hooking::PatternCallback<char>({ "NIO_STEAM", true, 0x0, "48 8B 0D ? ? ? ? 33 C0 48 85 C9 74 0D 39 81 ? ? ? ? 74 05 B8 ? ? ? ? C3 33 D2" }, [](char* address) {
	//		m_networkPlayerData = GetAddressFromInstruction(address);
	//		m_networkPlayerIsOnlineOffset = 0x74BC;
	//	})) return false;
	//}

	return true;
}

struct Metric {
	virtual ~Metric() = 0;
	virtual int GetMetricType() = 0;
	virtual int GetMetricSubType() = 0;
	virtual const char* GetName() = 0;
};

bool Backend::InGameBackend() {
	if (!Natives::InGame()) return false;
	if (!Security::InGame()) return false;
	/*if (!Anticheat::InGame()) return false;
	if (!Protection::InGame()) return false;*/
	if (!OceanManager::Initialize()) return false;
	//if (!NetEvent::Initialize()) return false;

	/*if (!Hooking::ServerPatternCallback<void>("SRID", [](Hooking::CallbackData<void> data) {
		return Hooking::HookFunction(data.m_address, &RockstarIDHook, &OriginalRockstarID, "SRID");
	})) return false;*/

	//if (!Hooking::ServerPatternCallback<void>("NSRID", [](Hooking::CallbackData<void> data) {
	//	return Hooking::HookFunction(data.m_address, &NewRockstarIDHook, &OriginalNewRockstarID, "NSRID");
	//})) return false;

	//if (!Hooking::ServerPatternCallback<void>("SPLH", [](Hooking::CallbackData<void> data) {
	//	return Hooking::HookFunction(data.m_address, &UpdatePedSyncHook, &OriginalUpdatePedSync, "SPLH");
	//})) return false;

	///*Road Slipperiness*/
	//if (!Hooking::ServerPatternCallback<void>("RS", [](Hooking::CallbackData<void> data) {
	//	return Hooking::HookFunction(data.m_address, &RoadSlipperinessHook, &OriginalRoadSlipperiness, "RS");
	//})) return false;

	///*Apply Wind Elements Setup Function*/
	//if (!Hooking::ServerPatternCallback<void>("AWES", [](Hooking::CallbackData<void> data) {
	//	m_applyWindElementsSetup = (DWORD64)data.m_address;

	///*Apply Wind Elements*/
	//return Hooking::ServerPatternCallback<void>("AWE", [](Hooking::CallbackData<void> data) {
	//	return Hooking::HookFunction(data.m_address, &ApplyWindElementsHook, &OriginalApplyWindElements, "AWE");
	//	});
	//})) return false;

	/*Hooking::ScriptTableCallback("shop_controller", "WMH", [](Script::ScriptTableItem* script) {
		Hooking::HookScriptNative(script, 0xDC38CC1E35B6A5D7, WarningMessageHook, "WMH");
	});*/

	for each (DWORD64 address in Pattern::getStringAddress(PLAYER::GetPlayerName(PlayerId2))) {
		Backend::m_nameAddresses.push_back(address);
	}

	/*for (auto& address : Pattern::getStringAddress(PLAYER::GetPlayerName(PLAYER::PlayerId()))) {
		Backend::m_nameAddresses.push_back(address);
	}*/


	Backend::m_nameAddresses.push_back(Pattern::getMultilayerPointer(GetWorldPtr(), { 0x8, 0x10B8, 0x7c }));
	return true;
}

DWORD WINAPI Backend::CleanupThread(LPVOID lpParam) {
	m_cleaning = true;

	LOG_PRINT("[Service] Starting cleanup");

	Input::Cleanup();
	Natives::Cleanup();
	/*Anticheat::Cleanup();
	Protection::Cleanup();*/
	Security::Cleanup();
	Hooking::Cleanup();
	Memory::Cleanup();

	GetAuthFiberManager()->Cleanup();
	GetFiberManager()->Cleanup();
	GetThreadPool()->Cleanup();
	GetLog()->Cleanup();

	//g_Hooking->Unhook();
	g_GameVariables.reset();
	g_GameFunctions.reset();

	LOG_PRINT("[Service] Cleanup finished");
	Sleep(1000);
	FreeLibraryAndExitThread(m_hModule, 0);
}

/*
//CPatternResult
*/

uint64_t CMetaData::m_begin = 0;
uint64_t CMetaData::m_end = 0;
DWORD CMetaData::m_size = 0;

uint64_t CMetaData::begin()
{
	return m_begin;
}
uint64_t CMetaData::end()
{
	return m_end;
}
DWORD CMetaData::size()
{
	return m_size;
}

void CMetaData::init()
{
	/*if (Hooking::loadmods) {*/
	if (m_begin && m_size)
		return;
	m_begin = (uint64_t)GetModuleHandleA(nullptr);
	const IMAGE_DOS_HEADER* headerDos = (const IMAGE_DOS_HEADER*)m_begin;
	const IMAGE_NT_HEADERS* headerNt = (const IMAGE_NT_HEADERS64*)((const BYTE*)headerDos + headerDos->e_lfanew);
	m_size = headerNt->OptionalHeader.SizeOfCode;
	m_end = m_begin + m_size;
	/*}*/
	return;
}
CPatternResult::CPatternResult(void* pVoid) :
	m_pVoid(pVoid)
{}
CPatternResult::CPatternResult(void* pVoid, void* pBegin, void* pEnd) :
	m_pVoid(pVoid),
	m_pBegin(pBegin),
	m_pEnd(pEnd)
{}
CPatternResult::~CPatternResult() {}

/*
//CPattern Public
*/

CPattern::CPattern(char* szByte, char* szMask) :
	m_szByte(szByte),
	m_szMask(szMask),
	m_bSet(false)
{}
CPattern::~CPattern() {}

CPattern& CPattern::find(int i, uint64_t startAddress)
{
	match(i, startAddress, false);
	if (m_result.size() <= i)
		m_result.push_back(nullptr);
	return *this;
}

CPattern& CPattern::virtual_find(int i, uint64_t startAddress)
{
	match(i, startAddress, true);
	if (m_result.size() <= i)
		m_result.push_back(nullptr);
	return *this;
}

CPatternResult	CPattern::get(int i)
{
	if (m_result.size() > i)
		return m_result[i];
	return nullptr;
}

/*
//CPattern Private
*/
bool	CPattern::match(int i, uint64_t startAddress, bool virt)
{
	if (m_bSet)
		return false;
	uint64_t	begin = 0;
	uint64_t	end = 0;
	if (!virt)
	{
		CMetaData::init();
		begin = CMetaData::begin() + startAddress;
		end = CMetaData::end();
		if (begin >= end)
			return false;
	}
	int		j = 0;
	do
	{
		if (virt)
			begin = virtual_find_pattern(startAddress, (BYTE*)m_szByte, m_szMask) + 1;
		else
			begin = find_pattern(begin, end, (BYTE*)m_szByte, m_szMask) + 1;
		if (begin == NULL)
			break;
		j++;
	} while (j < i);

	m_bSet = true;
	return true;
}

bool	CPattern::byte_compare(const BYTE* pData, const BYTE* btMask, const char* szMask)
{
	for (; *szMask; ++szMask, ++pData, ++btMask)
		if (*szMask == 'x' && *pData != *btMask)
			break;
	if ((*szMask) != 0)
		return false;
	return true;
}


uint64_t	CPattern::find_pattern(uint64_t address, uint64_t end, BYTE* btMask, char* szMask)
{
	size_t len = strlen(szMask) + 1;
	for (uint64_t i = 0; i < (end - address - len); i++)
	{
		BYTE* ptr = (BYTE*)(address + i);
		if (byte_compare(ptr, btMask, szMask))
		{
			m_result.push_back(CPatternResult((void*)(address + i)));
			return address + i;
		}
	}
	return NULL;
}

uint64_t	CPattern::virtual_find_pattern(uint64_t address, BYTE* btMask, char* szMask)
{
	MEMORY_BASIC_INFORMATION mbi;
	char* pStart = nullptr;
	char* pEnd = nullptr;
	char* res = nullptr;
	size_t	maskLen = strlen(szMask);

	while (res == nullptr && sizeof(mbi) == VirtualQuery(pEnd, &mbi, sizeof(mbi)))
	{
		pStart = pEnd;
		pEnd += mbi.RegionSize;
		if (mbi.Protect != PAGE_READWRITE || mbi.State != MEM_COMMIT)
			continue;

		for (int i = 0; pStart < pEnd - maskLen && res == nullptr; ++pStart)
		{
			if (byte_compare((BYTE*)pStart, btMask, szMask))
			{
				m_result.push_back(CPatternResult((void*)pStart, mbi.BaseAddress, pEnd));
				res = pStart;
			}
		}

		mbi = {};
	}
	return (uint64_t)res;
}
