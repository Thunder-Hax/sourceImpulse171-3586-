#include "stdafx.h"
#include <ShellAPI.h>
#include "miscExternalLinks.h"
#include "../miscMenu.h"

using namespace MiscExternalLinksMenuVars;

namespace MiscExternalLinksMenuVars {
	Vars vars;
}

void MiscExternalLinksMenu::Init() {
	setParentSubmenu<MiscMenu>();
	setName("External links", false, true);

	addOption(ButtonOption("Open Thunder site")
		.addFunction([] {
		ShellExecute(NULL, L"open", L"https://Thunder.one", NULL, NULL, SW_SHOWNORMAL);
	})
		.addTooltip("Open Thunder.one").addTranslation());

	addOption(ButtonOption("Open Thunder youtube")
		.addFunction([] {
			ShellExecute(NULL, L"open", L"https://www.youtube.com/channel/UC1Tro0Qg29g9bOwmqiWND3Q", NULL, NULL, SW_SHOWNORMAL);
		})
		.addTooltip("Open Thunder youtube channel").addTranslation());

	addOption(ButtonOption("Open Thunder header creation tutorial")
		.addFunction([] {
		ShellExecute(NULL, L"open", L"https://www.youtube.com/watch?v=b6MqwqdxkBY", NULL, NULL, SW_SHOWNORMAL);
	})
		.addTooltip("Open Thunder header creation tutorial youtube video").addTranslation());

	addOption(ButtonOption("Open Thunder scripthook tutorial")
		.addFunction([] {
		ShellExecute(NULL, L"open", L"https://www.youtube.com/watch?v=xWiTkUk_--Q", NULL, NULL, SW_SHOWNORMAL);
	})
		.addTooltip("Open Thunder scripthook tutorial youtube video").addTranslation());

	addOption(ButtonOption("Open Thunder r* id spoofer tutorial")
		.addFunction([] {
		ShellExecute(NULL, L"open", L"https://www.youtube.com/watch?v=-CebL31BtC8", NULL, NULL, SW_SHOWNORMAL);
	})
		.addTooltip("Open Thunder r* id spoofer tutorial youtube video").addTranslation());
}

/*Update once when submenu is opened*/
void MiscExternalLinksMenu::UpdateOnce() {}

/*Update while submenu is active*/
void MiscExternalLinksMenu::Update() {}

/*Background update*/
void MiscExternalLinksMenu::FeatureUpdate() {}

/*Singleton*/
MiscExternalLinksMenu* _instance;
MiscExternalLinksMenu* MiscExternalLinksMenu::GetInstance() {
	if (_instance == nullptr) {
		_instance = new MiscExternalLinksMenu();
		_instance->Init();
		GetSubmenuHandler()->addSubmenu(_instance);
	}
	return _instance;
}
MiscExternalLinksMenu::~MiscExternalLinksMenu() { delete _instance; }