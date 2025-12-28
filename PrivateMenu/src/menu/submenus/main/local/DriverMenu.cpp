#include "stdafx.h"
#include "playerMovementMenu.h"
#include "..\localMenu.h"
#include "menu\submenus\main/worldMenu.h"
#include "src\menu\submenu.h"
#include "src\menu\options\buttonOption.h"
#include "DriverMenu.h"

using namespace DriverMenuVars;

char* WalkingOn::walkinginair[] = {
(char*)"stt_prop_stunt_bblock_sml2",
(char*)"stt_prop_stunt_bblock_lrg3",
(char*)"stt_prop_stunt_bblock_mdm3",
(char*)"prop_ld_ferris_wheel",
(char*)"stt_prop_track_start_02",
(char*)"stt_prop_stunt_landing_zone_01"
};

namespace DriverMenuVars
{
	struct Vars vars;
int ii;


void DriveOnair() {
	Features::dowboolair = vars.driveonair;
	if (Features::dowboolair)
	{
		if (Features::incars)
		{
			char* prop = (char*)Features::Driveinairdword;
			if (Features::firstwalk || Features::ifwalkorincar)
			{
				Features::checkifwalk(prop);
				Features::firstwalk = 0;
			}
			if (!Features::opened_before2)
			{
				if (Features::stoptimer)
					Features::getnotify();
				if (Features::stopnotifycar)
					Features::notifyMap("F3 or RB_69 activate walk in sky and in a car \n press q for up, and z for down \n");
				if (helpers::get_key_state(VK_KEY_Z, 1) || helpers::get_key_state(VK_KEY_Q, 1))
				{
					Features::opened_before2 = true;
				}
			}
			bool opencontroller2 = (PAD::IsDisabledControlJustPressed(2, Features::open25) & 1);
			bool openf1 = (GetAsyncKeyState(VK_F3) & 1);
			if (openf1 || opencontroller2)
			{
				Features::Driveinsky = !Features::Driveinsky;
			}
			if (Features::Driveinsky)
			{
				Hash ObjHash = HASH::GET_HASH_KEY(prop);
				Player me = PLAYER::PlayerPedId();
				Vector3 PlayerCoord;
				PlayerCoord = ENTITY::GetEntityCoords(me, 0/*, 0*/);
				float zPlane;
				Object WalkOnAir = OBJECT::GetClosestObjectOfType(PlayerCoord.x, PlayerCoord.y, PlayerCoord.z, 100, ObjHash, 1, 0, 1);
				if (!ENTITY::DoesEntityExist(WalkOnAir) && (Features::dowboolair))
				{
					DWORD ticks = GetTickCount64();
					DWORD milliseconds = ticks % 1000;
					int getTimer = milliseconds;
					if (getTimer % 250 == 0)
					{
						Object WalkOnAir2 = Features::Create_Obj1(prop, PlayerCoord);
						ENTITY::FreezeEntityPosition(WalkOnAir, 1);
					}
				}
				else if (ENTITY::DoesEntityExist(WalkOnAir) && (Features::dowboolair))
				{
					if (PED::GetVehiclePedIsIn(PLAYER::PlayerPedId(), 0))
					{
						if (GetAsyncKeyState(0x5A) || (PAD::IsDisabledControlJustPressed(2, INPUT_SCRIPT_LS)))      //Down Z and L3          
						{
							zPlane = PlayerCoord.z - Features::Down;
						}
						else if (GetAsyncKeyState(0x51) || (PAD::IsDisabledControlJustPressed(2, INPUT_SCRIPT_RS)))      //Up Q and R3  
						{
							zPlane = PlayerCoord.z - Features::Up;
						}
						else                                              //Normal
						{
							zPlane = PlayerCoord.z - Features::Normal;
						}
						Vector3 pRot = ENTITY::GetEntityRotation(me, 0);
						ENTITY::SetEntityRotation(WalkOnAir, 0, 0, pRot.z, 0, 1);
						Vector3 Coord = Features::CombineVector(PlayerCoord.x, PlayerCoord.y, zPlane);
						ENTITY::SetEntityRotation(WalkOnAir, Features::objectpitch, Features::objectroll, Features::objectyaw, Features::rotationOrder, 1);
						ENTITY::/*SET_ENTITY_COORDS_NO_OFFSET*/_SetEntityCoords2(WalkOnAir, Coord.x - Features::objectx, Coord.y - Features::objecty, Coord.z - Features::objectz, 0, 0, 0, 0);
					}
				}
			}
		}
	}
}
}
void DriverMenu::Init() {

	addOption(ToggleOption("Drive on air")
		.addToggle(vars.driveonair)
		.addHotkey().canBeSaved().addTranslation()
		.addTooltip("z to go down, q to go up"));

	addOption(NumberOption<float>(SCROLL, "Normal")
		.addNumber(Features::Normal, "%.1f", 0.1f).addMin(-5.0f).addMax(5.0f).setScrollSpeed(10)
		.addHotkey().canBeSaved().addTranslation()
		.addTooltip("Normal"));
	addOption(NumberOption<float>(SCROLL, "Down")
		.addNumber(Features::Down, "%.1f", 0.1f).addMin(-5.0f).addMax(5.0f).setScrollSpeed(10)
		.addHotkey().canBeSaved().addTranslation()
		.addTooltip("Down"));
	addOption(NumberOption<float>(SCROLL, "Up")
		.addNumber(Features::Up, "%.1f", 0.1f).addMin(-5.0f).addMax(5.0f).setScrollSpeed(10)
		.addHotkey().canBeSaved().addTranslation()
		.addTooltip("Up"));
	addOption(NumberOption<float>(SCROLL, "Vehicular")
		.addNumber(Features::Vehicular, "%.1f", 0.1f).addMin(-5.0f).addMax(5.0f).setScrollSpeed(10)
		.addHotkey().canBeSaved().addTranslation()
		.addTooltip("Vehicular"));
	addOption(NumberOption<float>(SCROLL, "objectx")
		.addNumber(Features::objectx, "%.1f", 0.1f).addMin(-5.0f).addMax(5.0f).setScrollSpeed(10)
		.addHotkey().canBeSaved().addTranslation()
		.addTooltip("objectx"));
	addOption(NumberOption<float>(SCROLL, "objecty")
		.addNumber(Features::objecty, "%.1f", 0.1f).addMin(-5.0f).addMax(5.0f).setScrollSpeed(10)
		.addHotkey().canBeSaved().addTranslation()
		.addTooltip("objecty"));
	addOption(NumberOption<float>(SCROLL, "objectz")
		.addNumber(Features::objectz, "%.1f", 0.1f).addMin(-5.0f).addMax(5.0f).setScrollSpeed(10)
		.addHotkey().canBeSaved().addTranslation()
		.addTooltip("objectz"));
	addOption(NumberOption<float>(SCROLL, "objectpitch")
		.addNumber(Features::objectpitch, "%.1f", 0.1f).addMin(-360.0f).addMax(360.0f).setScrollSpeed(10)
		.addHotkey().canBeSaved().addTranslation()
		.addTooltip("objectpitch"));
	addOption(NumberOption<float>(SCROLL, "objectroll")
		.addNumber(Features::objectroll, "%.1f", 0.1f).addMin(-360.0f).addMax(360.0f).setScrollSpeed(10)
		.addHotkey().canBeSaved().addTranslation()
		.addTooltip("objectroll"));
	addOption(NumberOption<float>(SCROLL, "objectyaw")
		.addNumber(Features::objectyaw, "%.1f", 0.1f).addMin(-360.0f).addMax(360.0f).setScrollSpeed(10)
		.addHotkey().canBeSaved().addTranslation()
		.addTooltip("objectyaw"));
	addOption(NumberOption<int>(SCROLL, "rotationOrder")
		.addNumber(Features::rotationOrder, "%i", 0).addMin(0).addMax(360)
		.addHotkey().canBeSaved().addTranslation()
		.addTooltip("rotationOrder"));

	int sizeOfArray = sizeof(WalkingOn::walkinginair) / sizeof(WalkingOn::walkinginair[0]);

	Submenu Menusub;

	for (ii = 0; ii < (sizeOfArray); ii++)
	{
		//std::shared_ptr<ButtonOption> buttonOptionPtr = std::make_shared<ButtonOption>();
		ButtonOption buttonOptionPtr;
		if (addOption(ButtonOption(WalkingOn::walkinginair[ii])))
		{
			buttonOptionPtr.addFunction([] {
				Features::walkinairdword = WalkingOn::walkinginair[ii];
				if (WalkingOn::walkinginair[ii] == "stt_prop_stunt_bblock_sml2")
				{
					Features::objectz = 0.13f;
					Features::objecty = 0.0f;
					Features::objectx = 0.0f;
					if (Features::featureWalk1)
					{
						Features::walkinairdword = "stt_prop_stunt_bblock_sml2";
						Features::Driveinairdword = "stt_prop_stunt_bblock_sml2";
						Features::Normal = 1.102500f;
						Features::Down = 1.509999f;
						Features::Up = -0.529981f;
						Features::objectroll = 0.0f;
					}
					if (Features::dowboolair)
					{
						Features::Driveinairdword = "stt_prop_stunt_bblock_sml2";
						Features::walkinairdword = "stt_prop_stunt_bblock_sml2";
						Features::Normal = 0.272501f;
						Features::Down = 1.509999f;
						Features::Up = -0.189981f;
						Features::objectroll = 0.0f;
					}
				}
				if (WalkingOn::walkinginair[ii] == "stt_prop_stunt_bblock_lrg3")
				{
					Features::objectz = 0.13f;
					Features::objecty = 0.0f;
					Features::objectx = 0.0f;
					if (Features::featureWalk1)
					{
						Features::walkinairdword = "stt_prop_stunt_bblock_lrg3";
						Features::Driveinairdword = "stt_prop_stunt_bblock_lrg3";
						Features::Normal = 1.102500f;
						Features::Down = 1.509999f;
						Features::Up = -0.529981f;
						Features::objectroll = 0.0f;
					}
					if (Features::dowboolair)
					{
						Features::Driveinairdword = "stt_prop_stunt_bblock_lrg3";
						Features::walkinairdword = "stt_prop_stunt_bblock_lrg3";
						Features::Normal = 0.272501f;
						Features::Down = 1.509999f;
						Features::Up = -0.189981f;
						Features::objectroll = 0.0f;
					}
				}
				});
			buttonOptionPtr.addTranslation().addHotkey();
			buttonOptionPtr.addTooltip("stt_prop_stunt_bblock_").addTranslation();
		}
	}
}

void DriverMenu::UpdateOnce() {}
void DriverMenu::Update() {}
void DriverMenu::FeatureUpdate() {
	if (vars.driveonair)DriveOnair();
}

DriverMenu* _instance;
DriverMenu* DriverMenu::GetInstance() {
	if (_instance == nullptr) {
		_instance = new DriverMenu();
		_instance->Init();
		GetSubmenuHandler()->addSubmenu(_instance);
	}
	return _instance;
}
DriverMenu::~DriverMenu() { delete _instance; }
