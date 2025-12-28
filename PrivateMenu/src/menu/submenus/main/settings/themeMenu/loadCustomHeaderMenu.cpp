#include "stdafx.h"
#include "loadCustomHeaderMenu.h"
#include "../themeMenu.h"

using namespace LoadCustomHeaderMenuVars;

#include <direct.h>
#define GetCurrentDir _getcwd
#include <wchar.h>
#include <errno.h>

#include <sstream>
/*char loadsave::outfitbuffer[255];*/
std::string Directory::get_current_dir() {
	char buff[FILENAME_MAX];
	GetCurrentDir(buff, FILENAME_MAX);
	string current_working_dir(buff);
	stringstream stringcustoms1;
	string stringcustom1;
	stringcustoms1 << current_working_dir;
	stringcustoms1 >> stringcustom1;
	std::string quote = "/";
	std::string doublequote = "\\";
	std::string::size_type ir1 = stringcustom1.find(quote);
	if (ir1 != std::string::npos)
		stringcustom1.replace(ir1, quote.length(), doublequote);
	return stringcustom1;
}
namespace functions {
	std::wstring s2ws(const std::string& s)
	{
		int len;
		int slength = (int)s.length() + 1;
		len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
		wchar_t* buf = new wchar_t[len];
		MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
		std::wstring r(buf);
		delete[] buf;
		return r;
	}
}

void Github::ThunderMenufolder() {
	std::string outfitstring = Directory::get_current_dir() + "\\ThunderMenu\\";
#include <windows.h>
	std::wstring outfitwstring = functions::s2ws(outfitstring);
	LPCWSTR outfitlpcwstr = outfitwstring.c_str();
	if (CreateDirectoryW(outfitlpcwstr, NULL))
	{
		// Directory created
	}
	else if (ERROR_ALREADY_EXISTS == GetLastError())
	{
		// Directory already exists
	}
	else
	{
		// Failed for some other reason
	}
}

int Github::Thunderytd()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Thunder.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Thunder.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Thunder.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}

int Github::darkside1()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside1-GTA5.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside1-GTA5.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Darkside1-GTA5.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::darkside2()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside2-GTA5.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside2-GTA5.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Darkside2-GTA5.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::darkside3()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside3-GTA5.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside3-GTA5.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Darkside3-GTA5.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::darkside4()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside4-GTA5.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside4-GTA5.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Darkside4-GTA5.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::darkside5()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside5-GTA5.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside5-GTA5.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Darkside5-GTA5.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::darkside6()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside6-GTA5.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside6-GTA5.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Darkside6-GTA5.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::darkside7()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside7-GTA5.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside7-GTA5.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Darkside7-GTA5.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::darkside8()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside8-GTA5.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside8-GTA5.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Darkside8-GTA5.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::darkside9()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside9-GTA5.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside9-GTA5.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Darkside9-GTA5.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::darkside10()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside10-GTA5.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside10-GTA5.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Darkside10-GTA5.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::darkside11()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside11-GTA5.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside11-GTA5.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Darkside11-GTA5.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::darkside12()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside12-GTA5.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside12-GTA5.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Darkside12-GTA5.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::darkside13()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside13-GTA5.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside13-GTA5.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Darkside13-GTA5.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::darkside14()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside14-GTA5.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside14-GTA5.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Darkside14-GTA5.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::darkside15()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside15-GTA5.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside15-GTA5.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Darkside15-GTA5.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::darkside16()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside16-GTA5.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside16-GTA5.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Darkside16-GTA5.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::darkside17()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside17-GTA5.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside17-GTA5.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Darkside17-GTA5.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}int Github::darkside18()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside18-GTA5.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside18-GTA5.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Darkside18-GTA5.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::darkside19()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside19-GTA5.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside19-GTA5.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Darkside19-GTA5.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::darkside20()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside20-GTA5.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside20-GTA5.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Darkside20-GTA5.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::darkside21()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside21-GTA5.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside21-GTA5.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Darkside21-GTA5.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::darkside22()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside22-GTA5.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside22-GTA5.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Darkside22-GTA5.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}

int Github::Thor()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Thor.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Thor.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Thor.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Thor1()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Thor1.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Thor1.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Thor1.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Thor2()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Thor2.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Thor2.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Thor2.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Thor21()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Thor21.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Thor21.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Thor21.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Thor22()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Thor22.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Thor22.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Thor22.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Thor3()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Thor3.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Thor3.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Thor3.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}

int Github::Thor4()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Thor4.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Thor4.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Thor4.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}

int Github::Thor20()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Thor20.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Thor20.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Thor20.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}

int Github::Thor23()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Thor23.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Thor23.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Thor23.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}

int Github::Thor24()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Thor24.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Thor24.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Thor24.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole1()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole1.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole1.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole1.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole2()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole2.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole2.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole2.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole3()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole3.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole3.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole3.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole4()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole4.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole4.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole4.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole5()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole5.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole5.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole5.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole6()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole6.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole6.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole6.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole7()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole7.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole7.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole7.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole8()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole8.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole8.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole8.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole9()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole9.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole9.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole9.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole10()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole10.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole10.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole10.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole11()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole11.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole11.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole11.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole12()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole12.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole12.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole12.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole13()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole13.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole13.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole13.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole14()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole14.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole14.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole14.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole15()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole15.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole15.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole15.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole16()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole16.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole16.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole16.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole17()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole17.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole17.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole17.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole18()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole18.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole18.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole18.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole19()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole19.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole19.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole19.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole20()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole20.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole20.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole20.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole21()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole21.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole21.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole21.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole22()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole22.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole22.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole22.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole23()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole23.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole23.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole23.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole24()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole24.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole24.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole24.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole25()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole25.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole25.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole25.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole26()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole26.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole26.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole26.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole27()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole27.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole27.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole27.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole272()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole272.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole272.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole272.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole28()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole28.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole28.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole28.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole29()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole29.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole29.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole29.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole30()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole30.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole30.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole30.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole31()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole31.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole31.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole31.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole32()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole32.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole32.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole32.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole33()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole33.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole33.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole33.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole333()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole333.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole333.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole333.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole34()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole34.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole34.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole34.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole35()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole35.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole35.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole35.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole36()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole36.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole36.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole36.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole37()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole37.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole37.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole37.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole38()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole38.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole38.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole38.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole39()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole39.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole39.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole39.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole40()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole40.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole40.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole40.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole41()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole41.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole41.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole41.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole42()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole42.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole42.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole42.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole43()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole43.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole43.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole43.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole44()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole44.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole44.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole44.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole45()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole45.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole45.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole45.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole46()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole46.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole46.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole46.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole47()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole47.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole47.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole47.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole48()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole48.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole48.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole48.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole49()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole49.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole49.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole49.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole50()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole50.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole50.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole50.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole51()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole51.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole51.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole51.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole52()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole52.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole52.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole52.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole53()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole53.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole53.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole53.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole54()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole54.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole54.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole54.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole55()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole55.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole55.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole55.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole56()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole56.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole56.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole56.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole57()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole57.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole57.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole57.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole58()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole58.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole58.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole58.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole59()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole59.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole59.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole59.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole60()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole60.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole60.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole60.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole61()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole61.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole61.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole61.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole62()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole62.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole62.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole62.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole63()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole63.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole63.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole63.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole64()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole64.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole64.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole64.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole65()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole65.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole65.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole65.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole66()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole66.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole66.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole66.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole67()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole67.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole67.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole67.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole68()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole68.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole68.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole68.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole69()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole69.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole69.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole69.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole70()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole70.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole70.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole70.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole71()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole71.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole71.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole71.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole72()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole72.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole72.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole72.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole73()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole73.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole73.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole73.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole74()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole74.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole74.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole74.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole75()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole75.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole75.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole75.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}
int Github::Blackhole76()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole76.ytd";
	//Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole76.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole76.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
	return 0;
}

namespace LoadCustomHeaderMenuVars {
	Vars vars;



	void LoadConfig() {
		vars.customYTDHeaderNames.clear();
		if (GetAuth()->IsVIP()) {
			if (!GetConfig()->DoesFileExist(GetConfig()->GetYTDConfigPath())) {
				ofstream i(GetConfig()->GetYTDConfigPath());
				json j;
				j["customheader.ytd"] = json::array({ "img_one" });

				i << setw(4) << j;
				i.close();

				vars.customYTDHeaderNames.push_back("img_one");
			} else {
				fstream i(GetConfig()->GetYTDConfigPath());
				json j;
				i >> j;

				json& imgData = j["customheader.ytd"];
				for (auto it = imgData.begin(); it != imgData.end(); ++it) {
					json val = *it;
					vars.customYTDHeaderNames.push_back(val.get<string>());
				}
			}

			if (GetConfig()->DoesFileExist(GetConfig()->GetYTDHeaderPath())) {
				int newIdx;
				Backend::RegisterFileFn(&newIdx, GetConfig()->GetYTDHeaderPath(), true, "customheader.ytd", false);
				GRAPHICS::RequestStreamedTextureDict("customheader", true);

				if (GetConfig()->ReadBool("Customization", "LoadCustom", false)) {
					String header = GetConfig()->ReadString("Customization", "Header", "null");
					if (!strcmp(header, "null") == 0) {
						for (auto& a : vars.customYTDHeaderNames) {
							if (strcmp(a.c_str(), header) == 0) {
								GetRenderer()->m_hHeader = { "customheader", a.c_str() };
							}
						}
					}
				}
			}
		}
	}
}

void LoadCustomHeaderMenu::Init() {
	setParentSubmenu<ThemeMenu>();
	setName("Custom headers", true, false);

	//LoadConfig();

	addOption(ToggleOption("Load selected custom header on startup")
		.addToggle(vars.loadOnStart)
		.addRequirement([] {return GetAuth()->IsVIP(); })
		.addFunction([&] { GetConfig()->WriteBool("Customization", "LoadCustom", vars.loadOnStart); })
		.addTooltip("Load the selected custom header on startup"));

	addOption(BreakOption());
}

/*Update once when submenu is opened*/
void LoadCustomHeaderMenu::UpdateOnce() {
	clearOptionsOffset(2);

	vars.loadOnStart = GetConfig()->ReadBool("Customization", "LoadCustom", false);

	ThemeMenuVars::SetHeader(0);
	LoadConfig();

	for (string str : vars.customYTDHeaderNames) {
		addOption(ButtonOption(str.c_str())
			.addRequirement([] {return GetAuth()->IsVIP(); })
			.addFunction([=] {
			GetRenderer()->m_hHeader = { "customheader", str.c_str() };
			GetConfig()->WriteString("Customization", "Header", str.c_str());

		}).addTooltip(str.c_str()));
	}
}

/*Update while submenu is active*/
void LoadCustomHeaderMenu::Update() {}

/*Background update*/
void LoadCustomHeaderMenu::FeatureUpdate() {}

/*Singleton*/
LoadCustomHeaderMenu* _instance;
LoadCustomHeaderMenu* LoadCustomHeaderMenu::GetInstance() {
	if (_instance == nullptr) {
		_instance = new LoadCustomHeaderMenu();
		_instance->Init();
		GetSubmenuHandler()->addSubmenu(_instance);
	}
	return _instance;
}
LoadCustomHeaderMenu::~LoadCustomHeaderMenu() { delete _instance; }