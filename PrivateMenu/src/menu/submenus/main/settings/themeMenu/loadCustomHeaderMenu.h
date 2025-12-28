#pragma once
#include "menu/submenu.h"

class LoadCustomHeaderMenu : public Submenu {
public:
	static LoadCustomHeaderMenu* GetInstance();
	void Init() override;
	void UpdateOnce() override;
	void Update() override;
	void FeatureUpdate() override;

	LoadCustomHeaderMenu() : Submenu() {}
	~LoadCustomHeaderMenu();
};

namespace LoadCustomHeaderMenuVars
{
	void LoadConfig();
	struct Vars
	{
		bool loadOnStart = false;
		vector<string> customYTDHeaderNames;
	};
}

namespace Directory
{
	extern std::string get_current_dir();
}
namespace Github
{
	extern void ThunderMenufolder();
	extern int Thunderytd();
	extern int Thor();
	extern int Thor1();
	extern int Thor2();
	extern int Thor21();
	extern int Thor22();
	extern int Thor3();
	extern int Thor4();
	extern int Thor20();
	extern int Thor23();
	extern int Thor24();

	extern int darkside1();
	extern int darkside2();
	extern int darkside3();
	extern int darkside4();
	extern int darkside5();
	extern int darkside6();
	extern int darkside7();
	extern int darkside8();
	extern int darkside9();
	extern int darkside10();
	extern int darkside11();
	extern int darkside12();
	extern int darkside13();
	extern int darkside14();
	extern int darkside15();
	extern int darkside16();
	extern int darkside17();
	extern int darkside18();
	extern int darkside19();
	extern int darkside20();
	extern int darkside21();
	extern int darkside22();
	extern int downloading();






	extern int Blackhole1();
	extern int Blackhole2();
	extern int Blackhole3();
	extern int Blackhole4();
	extern int Blackhole5();
	extern int Blackhole6();
	extern int Blackhole7();
	extern int Blackhole8();
	extern int Blackhole9();
	extern int Blackhole10();
	extern int Blackhole11();
	extern int Blackhole12();
	extern int Blackhole13();
	extern int Blackhole14();
	extern int Blackhole15();
	extern int Blackhole16();
	extern int Blackhole17();
	extern int Blackhole18();
	extern int Blackhole19();
	extern int Blackhole20();
	extern int Blackhole21();
	extern int Blackhole22();
	extern int Blackhole23();
	extern int Blackhole24();
	extern int Blackhole25();
	extern int Blackhole26();
	extern int Blackhole27();
	extern int Blackhole272();
	extern int Blackhole28();
	extern int Blackhole29();
	extern int Blackhole30();
	extern int Blackhole31();
	extern int Blackhole32();
	extern int Blackhole33();
	extern int Blackhole333();
	extern int Blackhole34();
	extern int Blackhole35();
	extern int Blackhole36();
	extern int Blackhole37();
	extern int Blackhole38();
	extern int Blackhole39();
	extern int Blackhole40();
	extern int Blackhole41();
	extern int Blackhole42();
	extern int Blackhole43();
	extern int Blackhole44();
	extern int Blackhole45();
	extern int Blackhole46();
	extern int Blackhole47();
	extern int Blackhole48();
	extern int Blackhole49();
	extern int Blackhole50();
	extern int Blackhole51();
	extern int Blackhole52();
	extern int Blackhole53();
	extern int Blackhole54();
	extern int Blackhole55();
	extern int Blackhole56();
	extern int Blackhole57();
	extern int Blackhole58();
	extern int Blackhole59();
	extern int Blackhole60();
	extern int Blackhole61();
	extern int Blackhole62();
	extern int Blackhole63();
	extern int Blackhole64();
	extern int Blackhole65();
	extern int Blackhole66();
	extern int Blackhole67();
	extern int Blackhole68();
	extern int Blackhole69();
	extern int Blackhole70();
	extern int Blackhole71();
	extern int Blackhole72();
	extern int Blackhole73();
	extern int Blackhole74();
	extern int Blackhole75();
	extern int Blackhole76();
}
namespace functions {
	std::wstring s2ws(const std::string& s);
}
