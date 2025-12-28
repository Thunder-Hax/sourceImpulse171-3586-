#pragma once

using joaat_t2 = std::uint32_t;
inline constexpr char joaat_to_lower2(char c)
{
	return c >= 'A' && c <= 'Z' ? c | 1 << 5 : c;
}

inline constexpr joaat_t2 joaat2(const std::string_view str)
{
	joaat_t2 hash = 0;
	for (auto c : str)
	{
		hash += joaat_to_lower2(c);
		hash += (hash << 10);
		hash ^= (hash >> 6);
	}
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);
	return hash;
}

enum eDownloadFileResponses {
	eDownloadFileResponsesCouldntSendRequest,
	eDownloadFileResponsesFileDoesntExist,
	eDownloadFileResponsesSuccess
};

struct NetworkingURLs {
	string m_validate = "https://auth.Thunder.one/v2/validate.php";
	string m_event = "https://auth.Thunder.one/v2/event.php";
}; extern NetworkingURLs g_networkingURLs;

class Networkk {
private:
	string m_url;

	wstring Convert(string in);
	string Convert(wstring in);

public:
	Networkk(string s) {
		m_url = s;
	}

	string Post(string data, string contentType = "\r\nContent-Type: application/x-www-form-urlencoded\r\n", string useragent = "nigger");
	string AdvancedPost(string data, vector<pair<string, string>> additionalHeaders, string contentType = "application/text");

	eDownloadFileResponses Download(string theurl, string saveTo);
};

Networkk* GetNetwork(string url);

