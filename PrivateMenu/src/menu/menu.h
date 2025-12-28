#pragma once
#include "menu/submenus/main/settingsMenu.h"

class Menu : public UIWindow {
private:
	bool m_closing = false;
	bool m_draggingSlider = false;
	bool m_inputThisFrame;
public:
	bool m_open = false;


	//Menu() : {}

	int m_maxOptions = 14; //14 is Default
	int m_currentOption = 0;
	int m_scrollOffset;
	int m_breakScroll;

	int m_openKey = VK_F4;
	int m_mouseKey = 'X';

	void update() override;
	bool within(float x, float y) override;
	bool withinHeaderY(float y) override;

	void render() override;
	void ASyncUpdate();
	void scrollEvent(int scroll) override;

	void Open() {
	if (m_isFading) return;
		m_open = true;

		if (!SettingsMenuVars::vars.keeplastpos) {
			GetSubmenuHandler()->SetSubmenuMain();
		}

		AUDIO::PlaySoundFrontend(-1, "FocusIn", "HintCamSounds", 0);
		fadeIn([&] {m_closing = false; });
	}
	void Close() {
		if (!m_isFading) { m_closing = true; fadeOut([&] {m_open = false; }); }
	}
	void ToggleOpen() { if (!m_isFading) { if (m_open) Close(); else Open(); } }
	bool IsOpen() { return m_open && !m_closing; }

	void Initialize();
	void ResetCurrentOption() { m_currentOption = 0; m_scrollOffset = 0; }
};

Menu* GetMenu();

#include "src\menu\submenus\main\session\playerList\player\remoteMenu.h"
#include "src\menu\submenus\main\spawn\vehicle\spawnVehicleSettingsMenu.h"

static Vehicle mCreateVehicle(Hash model, Vector3 pos, float heading, bool networked, bool scriptcheck)
{
	BypassPatch::ModelSpawnBypass(true);
	Vehicle veh = Hooked::create_vehicle(model, &pos, heading, true, true);
	BypassPatch::ModelSpawnBypass(false);
	return veh;
}
//#define VehicleBypass 4540731
//const int VehicleBypassGlobal[] = { 4542730 };//4542146 //Global_4541411 shop_controller.c //4541512 //https://github.com/dwep1337/GTAV-Decompiled-Scripts

static void mVehicle_Bypass()
{
	SpawnVehicleSettingsMenuVars::Vars vars;
	if (vars.sp_vehicle_bypass)
	{
		Global(VehicleBypassGlobal[0]).As<BOOL>() = vars.sp_vehicle_bypass;
		//globalHandle(/*VehicleBypass*/VehicleBypassGlobal[0]).As<BOOL>() = vars.sp_vehicle_bypass;
		//*ScriptGlobal::ScriptGlobal(VehicleBypassGlobal[0]).As<int*>() = vars.sp_vehicle_bypass;
	}
	else {
		Global(VehicleBypassGlobal[0]).As<BOOL>() = vars.sp_vehicle_bypass;
		//globalHandle(/*VehicleBypass*/VehicleBypassGlobal[0]).As<BOOL>() = vars.sp_vehicle_bypass;
		//*ScriptGlobal::ScriptGlobal(VehicleBypassGlobal[0]).As<int*>() = vars.sp_vehicle_bypass;
	}
}