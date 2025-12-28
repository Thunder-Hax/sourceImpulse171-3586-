#include "stdafx.h"
#include "playerMovementMenu.h"
#include "..\localMenu.h"
#include "menu\submenus\main/worldMenu.h"
#include "src\menu\submenu.h"
#include "src\menu\options\buttonOption.h"

#include "DriverMenu.h"

using namespace PlayerMovementMenuVars;
#define VK_NOTHING	0x00				/*NULL*/
#define IsKeyPressed(key) GetAsyncKeyState(key) & 0x8000 && 1

#define VK_LBUTTON 0x01
#define VK_RBUTTON 0x02
#define VK_CANCEL 0x03
#define VK_MBUTTON 0x04
#define VK_XBUTTON1 0x05
#define VK_XBUTTON2 0x06
#define VK_BACK 0x08
#define VK_TAB 0x09
#define VK_CLEAR 0x0C
#define VK_RETURN 0x0D
#define VK_SHIFT 0x10
#define VK_CONTROL 0x11
#define VK_MENU 0x12
#define VK_PAUSE 0x13
#define VK_CAPITAL 0x14
#define VK_KANA 0x15
#define VK_HANGUEL 0x15
#define VK_HANGUL 0x15
#define VK_IME_ON 0x16
#define VK_JUNJA 0x17
#define VK_FINAL 0x18
#define VK_HANJA 0x19
#define VK_KANJI 0x19
#define VK_IME_OFF 0x1A
#define VK_ESCAPE 0x1B
#define VK_CONVERT 0x1C
#define VK_NONCONVERT 0x1D
#define VK_ACCEPT 0x1E
#define VK_MODECHANGE 0x1F
#define VK_SPACE 0x20
#define VK_PRIOR 0x21
#define VK_NEXT 0x22
#define VK_END 0x23
#define VK_HOME 0x24
#define VK_LEFT 0x25
#define VK_UP 0x26
#define VK_RIGHT 0x27
#define VK_DOWN 0x28
#define VK_SELECT 0x29
#define VK_PRINT 0x2A
#define VK_EXECUTE 0x2B
#define VK_SNAPSHOT 0x2C
#define VK_INSERT 0x2D
#define VK_DELETE 0x2E
#define VK_HELP 0x2F
#define VK_KEY_0 0x30
#define VK_KEY_1 0x31
#define VK_KEY_2 0x32
#define VK_KEY_3 0x33
#define VK_KEY_4 0x34
#define VK_KEY_5 0x35
#define VK_KEY_6 0x36
#define VK_KEY_7 0x37
#define VK_KEY_8 0x38
#define VK_KEY_9 0x39
#define VK_KEY_A 0x41
#define VK_KEY_B 0x42
#define VK_KEY_C 0x43
#define VK_KEY_D 0x44
#define VK_KEY_E 0x45
#define VK_KEY_F 0x46
#define VK_KEY_G 0x47
#define VK_KEY_H 0x48
#define VK_KEY_I 0x49
#define VK_KEY_J 0x4A
#define VK_KEY_K 0x4B
#define VK_KEY_L 0x4C
#define VK_KEY_M 0x4D
#define VK_KEY_N 0x4E
#define VK_KEY_O 0x4F
#define VK_KEY_P 0x50
#define VK_KEY_Q 0x51
#define VK_KEY_R 0x52
#define VK_KEY_S 0x53
#define VK_KEY_T 0x54
#define VK_KEY_U 0x55
#define VK_KEY_V 0x56
#define VK_KEY_W 0x57
#define VK_KEY_X 0x58
#define VK_KEY_Y 0x59
#define VK_KEY_Z 0x5A
#define VK_LWIN 0x5B
#define VK_RWIN 0x5C
#define VK_APPS 0x5D
#define VK_SLEEP 0x5F
#define VK_NUMPAD0 0x60
#define VK_NUMPAD1 0x61
#define VK_NUMPAD2 0x62
#define VK_NUMPAD3 0x63
#define VK_NUMPAD4 0x64
#define VK_NUMPAD5 0x65
#define VK_NUMPAD6 0x66
#define VK_NUMPAD7 0x67
#define VK_NUMPAD8 0x68
#define VK_NUMPAD9 0x69
#define VK_MULTIPLY 0x6A
#define VK_ADD 0x6B
#define VK_SEPARATOR 0x6C
#define VK_SUBTRACT 0x6D
#define VK_DECIMAL 0x6E
#define VK_DIVIDE 0x6F
#define VK_F1 0x70
#define VK_F2 0x71
#define VK_F3 0x72
#define VK_F4 0x73
#define VK_F5 0x74
#define VK_F6 0x75
#define VK_F7 0x76
#define VK_F8 0x77
#define VK_F9 0x78
#define VK_F10 0x79
#define VK_F11 0x7A
#define VK_F12 0x7B
#define VK_F13 0x7C
#define VK_F14 0x7D
#define VK_F15 0x7E
#define VK_F16 0x7F
#define VK_F17 0x80
#define VK_F18 0x81
#define VK_F19 0x82
#define VK_F20 0x83
#define VK_F21 0x84
#define VK_F22 0x85
#define VK_F23 0x86
#define VK_F24 0x87
#define VK_NUMLOCK 0x90
#define VK_SCROLL 0x91
#define VK_LSHIFT 0xA0
#define VK_RSHIFT 0xA1
#define VK_LCONTROL 0xA2
#define VK_RCONTROL 0xA3
#define VK_LMENU 0xA4
#define VK_RMENU 0xA5
#define VK_BROWSER_BACK 0xA6
#define VK_BROWSER_FORWARD 0xA7
#define VK_BROWSER_REFRESH 0xA8
#define VK_BROWSER_STOP 0xA9
#define VK_BROWSER_SEARCH 0xAA
#define VK_BROWSER_FAVORITES 0xAB
#define VK_BROWSER_HOME 0xAC
#define VK_VOLUME_MUTE 0xAD
#define VK_VOLUME_DOWN 0xAE
#define VK_VOLUME_UP 0xAF
#define VK_MEDIA_NEXT_TRACK 0xB0
#define VK_MEDIA_PREV_TRACK 0xB1
#define VK_MEDIA_STOP 0xB2
#define VK_MEDIA_PLAY_PAUSE 0xB3
#define VK_LAUNCH_MAIL 0xB4
#define VK_LAUNCH_MEDIA_SELECT 0xB5
#define VK_LAUNCH_APP1 0xB6
#define VK_LAUNCH_APP2 0xB7
#define VK_OEM_1 0xBA
#define VK_OEM_PLUS 0xBB
#define VK_OEM_COMMA 0xBC
#define VK_OEM_MINUS 0xBD
#define VK_OEM_PERIOD 0xBE
#define VK_OEM_2 0xBF
#define VK_OEM_3 0xC0
#define VK_OEM_4 0xDB
#define VK_OEM_5 0xDC
#define VK_OEM_6 0xDD
#define VK_OEM_7 0xDE
#define VK_OEM_8 0xDF
#define VK_OEM_102 0xE2
#define VK_PROCESSKEY 0xE5
#define VK_PACKET 0xE7
#define VK_ATTN 0xF6
#define VK_CRSEL 0xF7
#define VK_EXSEL 0xF8
#define VK_EREOF 0xF9
#define VK_PLAY 0xFA
#define VK_ZOOM 0xFB
#define VK_NONAME 0xFC
#define VK_PA1 0xFD
#define VK_OEM_CLEAR 0xFE

#define A_73 73
#define A_70 70
#define A_21 21
#define A_18 18
#define X_99 99
#define X_22 22
#define Y_75 75
#define Y_56 56
#define Y_53 53
#define Y_49 49
#define Y_23 23
#define B_80 80
#define B_45 45
#define L3_86 86
#define L3_28 28
#define R3_79 79
#define R3_93 93
#define R3_50 50
#define R3_29 29
#define R3_26 26
#define LB_68 68
#define LB_89 89
#define LB_38 38
#define LB_37 37
#define RB_69 69
#define RB_76 76
#define RB_90 90
#define RB_55 55
#define RB_44 44
#define LT_77 77
#define LT_72 72
#define LT_88 88
#define LT_91 91
#define LT_25 25
#define LT_15 15
#define LT_10 10
#define RT_78 78
#define RT_71 71
#define RT_87 87
#define RT_92 92
#define RT_46 46 
#define RT_24 24
#define RT_14 14 
#define RT_11 11
#define DPUP_42 42 
#define DPUP_27 27
#define DPDN_48 48
#define DPDN_43 43 
#define DPDN_20 20
#define DPDN_19 19
#define DPLT_85 85
#define DPLT_58 58
#define DPLT_52 52
#define DPLT_47 47
#define DPRT_74 74
#define DPRT_54 54
#define DPRT_51 51
#define RSRT_66 66
#define RSRT_13 13
#define RSRT_6 6
#define RSLT_5 5
#define RSUP_3 3
#define RSDN_67 67 
#define RSDN_12 12
#define RSDN_4 4
#define RSDN_2 2
#define LSRT_64 64
#define LSRT_59 59
#define LSRT_35 35
#define LSRT_30 30
#define LSRT_9 9
#define LSRT_1 1
#define LSLT_63 63 
#define LSLT_34 34
#define LSUP_61 61
#define LSUP_40 40
#define LSUP_32 32
#define LSDN_60 60
#define LSDN_41 41
#define LSDN_39 39
#define LSDN_33 33
#define LSDN_31 31
#define LSDN_8 8
#define CTRL_62 62 
#define CTRL_36 36

bool helpers::is_key_pressed(int vKey) {
	static bool was_pressed[300];

	bool is_pressed = (GetAsyncKeyState(vKey) & 0x8000) != 0;
	if (!was_pressed[vKey] && is_pressed) {
		was_pressed[vKey] = is_pressed;
		return true;
	}
	was_pressed[vKey] = is_pressed;
	return false;
}

bool helpers::get_key_state(DWORD key, int flag) // from sub1to's gta internal
{
	clock_t	c = clock();
	static BYTE			btKeyState[0x100] = { 0 };
	static clock_t		clockKeyState[0x100] = { c };

	bool	r = false;
	BYTE	btState = (GetAsyncKeyState(key) & 0x8000U) >> 0xF;
	short	wDelay = btKeyState[key] & 2 ? 0x50 : 0x200;
	if (btState) {
		if (flag & 1) {
			if (!(btKeyState[key] & 1) || c - clockKeyState[key] > wDelay)
			{
				if ((btKeyState[key] & 3) == 1)
					btKeyState[key] |= 2;
				r = true;
				clockKeyState[key] = c;
			}
		}
		else
			r = true;
	}
	else
		btKeyState[key] &= ~(2);
	btKeyState[key] ^= (-btState ^ btKeyState[key]) & 1;

	return r;
}

std::string helpers::get_clipboard_text()
{
	if (!OpenClipboard(nullptr))
		return "";

	HANDLE data = GetClipboardData(CF_TEXT);
	if (data == nullptr)
		return "";

	char* pszText = static_cast<char*>(GlobalLock(data));
	if (pszText == nullptr)
		return "";

	std::string text(pszText);
	GlobalUnlock(data);
	CloseClipboard();

	return text;
}
void helpers::request_control(int input) {
	NETWORK::NetworkRequestControlOfEntity(input);
	int tick = 0;
	while (tick <= 50) {
		if (!NETWORK::NetworkHasControlOfEntity(input))
			/*fiber::wait_for(0);*/
			WAIT(0);
		else
			return;
		NETWORK::NetworkRequestControlOfEntity(input);
		tick++;
	}
}

void helpers::request_control_of_id(int netid) {
	int tick = 0;
	while (!NETWORK::NetworkHasControlOfNetworkId(netid) && tick <= 25) {
		NETWORK::NetworkRequestControlOfNetworkId(netid);
		tick++;
	}
}

void helpers::request_control_of_ent(int entity) {
	int tick = 0;
	while (!NETWORK::NetworkHasControlOfEntity(entity) && tick <= 25) {
		NETWORK::NetworkRequestControlOfEntity(entity);
		tick++;
	}
	if (NETWORK::NetworkIsSessionStarted()) {
		int netID = NETWORK::NetworkGetNetworkIdFromEntity(entity);
		request_control_of_id(netID);
		//NETWORK::SET_NETWORK_ID_CAN_MIGRATE(netID, 1);
	}
}

std::string helpers::get_keyboard_input(const char* windowName, int maxInput, const char* defaultText) {
	std::string defaultText_ = defaultText;
	/*hooks::globals::showing_keyboard_input_screen.drawing = true;
	hooks::globals::showing_keyboard_input_screen.title = windowName;*/
start:
	MISC::DisplayOnscreenKeyboard(0, (char*)windowName, "", (char*)defaultText_.c_str(), "", "", "", maxInput);
	while (MISC::UpdateOnscreenKeyboard() == 0) {
		if (GetAsyncKeyState(VK_LCONTROL) && is_key_pressed('V')) {
			auto keybd = get_clipboard_text();
			if (!keybd.empty()) {
				defaultText_ = keybd;
				MISC::/*_CANCEL_ONSCREEN_KEYBOARD*/UpdateOnscreenKeyboard();
				goto start;
			}
		}

		/*fiber::wait_for(0);*/
		WAIT(0);
	}
	if (!MISC::GetOnscreenKeyboardResult()) return "";
	//hooks::globals::showing_keyboard_input_screen.drawing = false;
	return MISC::GetOnscreenKeyboardResult();
}
float Features::objectx = 0.0f;
float Features::objecty = 0.0f;
float Features::objectz = 0.13f;

float Features::objectpitch = 0.0f;
float Features::objectroll = 0.0f;
float Features::objectyaw = 0.0f;
int Features::rotationOrder = 0;

char* Features::walkinairdword = (char*)"stt_prop_stunt_bblock_sml2";
char* Features::Driveinairdword = (char*)"stt_prop_track_start_02";

bool Features::walkinairvisible = 0;

int Features::open22 = R3_79;
int Features::open25 = RB_69;
bool Features::walkinsky = 0;
bool Features::opened_before2 = false;

float Features::Normal = 1.0225;
float Features::Down = 1.55;
float Features::Up = 0.40;
float Features::Vehicular = 10.0;

bool Features::incars = 0;
bool Features::firstwalk = 1;
bool Features::ifwalkorincar = 1;

int Features::newcars = 0;
int Features::checkifwalk(char* ObjectName)
{
	Player me = PLAYER::PlayerPedId();
	if (PED::IsPedInAnyVehicle(me, 0))
	{
		incars = 1;
	}
	else
	{
		incars = 0;
	}
	if (ObjectName == "stt_prop_stunt_bblock_sml2")
	{
		objectz = 0.13f;
		objecty = 0.0f;
		objectx = 0.0f;
		if (!incars)
		{
			walkinairdword = "stt_prop_stunt_bblock_sml2";
			Normal = 1.102500f;
			Down = 1.509999f;
			Up = -0.529981f;
			objectroll = 0.0f;
		}
		if (incars)
		{
			Driveinairdword = "stt_prop_stunt_bblock_sml2";
			Hash vehHash = ENTITY::GetEntityModel(PED::GetVehiclePedIsIn(PLAYER::PlayerPedId(), 0));

			//float VehicleHeight = VEHICLE::_GetVehicleSuspensionHeight(PED::GetVehiclePedIsIn(PLAYER::PlayerPedId(), 0));
			//float VehicleHeight = VEHICLE::_GetVehicleSuspensionHeight(vehHash);

			/*string  header021;
			header021 = getenv("appdata");
			ofstream header022122(header021 + "\\ThunderMenu\\VehicleModel2.Thunder");
			header022122 << vehHash;*/
			switch (vehHash)
			{
			case 15214558: //brioso3
			{
				Normal = 0.382501f;
				Down = 1.509999f;
				Up = 0.090019f;
				objectroll = 0.0f;
			}
			break;
			case 40817712: //greenwood
			{
				Normal = 0.502501f;
				Down = 1.509999f;
				Up = 0.270019f;
				objectroll = 0.0f;
			}
			break;
			case 237764926: //buffalo3
			{
				Normal = 0.682501f;
				Down = 2.009999f;
				Up = 0.300019f;
				objectroll = 0.0f;
			}
			break;
			case 274946574: //tenf
			{
				Normal = 0.421501f;
				Down = 2.009999f;
				Up = 0.100019f;
				objectroll = 0.0f;
			}
			break;
			case 340154634: //formula
			{
				Normal = 0.322501f;
				Down = 2.009999f;
				Up = 0.010019f;
				objectroll = 0.0f;
			}
			break;
			case 345756458: //pbus2
			{
				Normal = 1.322500f;
				Down = 2.009999f;
				Up = 0.500019f;
				objectroll = 0.0f;
			}
			break;
			case 410882957: //kuruma2
			{
				Normal = 0.802500f;
				Down = 1.509999f;
				Up = 0.540019f;
				objectroll = 0.0f;
			}
			break;
			case 3078201489: //adder
			{
				Normal = 0.652501f;
				Down = 2.009999f;
				Up = 0.240019f;
				objectroll = 0.0f;
			}
			break;
			case 3963499524: //italigto
			{
				Normal = 0.462501f;
				Down = 2.009999f;
				Up = 0.010019f;
				objectroll = 0.0f;
			}
			break;
			case 4008920556: //rcbandito
			{
				Normal = 0.232501f;
				Down = 2.009999f;
				Up = 0.070019f;
				objectroll = 0.0f;
			}
			break;
			case 562680400: //apc
			{
				Normal = 0.762501f;
				Down = 1.509999f;
				Up = 0.220019f;
				objectroll = 0.0f;
			}
			break;
			case 629969764: //astron
			{
				Normal = 0.452501f;
				Down = 2.009999f;
				Up = 0.200019f;
				objectroll = 0.0f;
			}
			break;
			case 723973206: //duke
			{
				Normal = 0.632501f;
				Down = 1.509999f;
				Up = 0.220019f;
				objectroll = 0.0f;
			}
			break;
			case 775514032: //sm722
			{
				Normal = 0.412501f;
				Down = 2.009999f;
				Up = 0.100019f;
				objectroll = 0.0f;
			}
			break;
			case 886810209: //stromberg
			{
				Normal = 0.322501f;
				Down = 2.009999f;
				Up = 0.010019f;
				objectroll = 0.0f;
			}
			break;
			case 941494461: //ruiner2
			{
				Normal = 0.782500f;
				Down = 1.509999f;
				Up = 0.500019f;
				objectroll = 0.0f;
			}
			break;
			case 989294410: //voltic2
			{
				Normal = 0.632500f;
				Down = 1.509999f;
				Up = 0.220019f;
				objectroll = 0.0f;
			}
			break;
			case 1031562256: //tezeract
			{
				Normal = 0.272501f;
				Down = 1.509999f;
				Up = -0.189981f;
				objectroll = 0.0f;
			}
			break;
			case 1118611807: //asbo
			{
				Normal = 0.462501f;
				Down = 2.009999f;
				Up = 0.180019f;
				objectroll = 0.0f;
			}
			break;
			case 1483171323: //deluxo
			{
				Normal = 0.532501f;
				Down = 2.009999f;
				Up = 0.100019f;
				objectroll = 0.0f;
			}
			break;
			case 1492612435: //openwheel1
			{
				Normal = 0.252501f;
				Down = 2.009999f;
				Up = -0.099981f;
				objectroll = 0.0f;
			}
			break;
			case 1663218586: //t20
			{
				Normal = 0.642501f;
				Down = 2.009999f;
				Up = 0.250019f;
				objectroll = 0.0f;
			}
			break;
			case 1706945532: //ruiner4
			{
				Normal = 0.452501f;
				Down = 2.009999f;
				Up = 0.100019f;
				objectroll = 0.0f;
			}
			break;
			case 2067820283: //tyrus
			{
				Normal = 0.322501f;
				Down = 2.009999f;
				Up = 0.070019f;
				objectroll = 0.0f;
			}
			break;
			case 2071877360: //insurgent2
			{
				Normal = 0.992500f;
				Down = 1.509999f;
				Up = 0.540019f;
				objectroll = 0.0f;
			}
			break;
			case 2246633323: //italigtb
			{
				Normal = 0.362501f;
				Down = 2.009999f;
				Up = 0.070019f;
				objectroll = 0.0f;
			}
			break;
			case 2334210311: //formula2
			{
				Normal = 0.322501f;
				Down = 2.009999f;
				Up = 0.010019f;
				objectroll = 0.0f;
			}
			break;
			case 2370534026: //insurgent3
			{
				Normal = 0.992501f;
				Down = 2.009999f;
				Up = 0.550019f;
				objectroll = 0.0f;
			}
			break;
			case 2434067162: //insurgent
			{
				Normal = 0.982500f;
				Down = 1.509999f;
				Up = 0.540019f;
				objectroll = 0.0f;
			}
			break;
			case 2439462158: //rhinehart
			{
				Normal = 0.812500f;
				Down = 2.009999f;
				Up = 0.500019f;
				objectroll = 0.0f;
			}
			break;
			case 2536587772: //vigero2
			{
				Normal = 0.472501f;
				Down = 2.009999f;
				Up = 0.100019f;
				objectroll = 0.0f;
			}
			break;
			case 2538945576: //everon
			{
				Normal = 1.082500f;
				Down = 2.009999f;
				Up = 0.550019f;
				objectroll = 0.0f;
			}
			break;
			case 2645431192: //phantom2
			{
				Normal = 1.132500f;
				Down = 2.009999f;
				Up = 0.550019f;
				objectroll = 0.0f;
			}
			break;
			case 2802050217: //veto2
			{
				Normal = 0.202501f;
				Down = 2.009999f;
				Up = 0.070019f;
				objectroll = 0.0f;
			}
			break;
			case 2936769864: //tigon
			{
				Normal = 0.402501f;
				Down = 1.509999f;
				Up = 0.270019f;
				objectroll = 0.0f;
			}
			break;
			case 2938086457: //sentinel4
			{
				Normal = 0.492501f;
				Down = 2.009999f;
				Up = 0.100019f;
				objectroll = 0.0f;
			}
			break;
			case 2945871676: //caracara2
			{
				Normal = 0.782501f;
				Down = 2.009999f;
				Up = 0.240019f;
				objectroll = 0.0f;
			}
			break;
			case 2983812512: //cheetah
			{
				Normal = 0.372501f;
				Down = 2.009999f;
				Up = 0.130019f;
				objectroll = 0.0f;
			}
			break;
			case 3223586949: //tampa2
			{
				Normal = 0.432501f;
				Down = 2.009999f;
				Up = 0.010019f;
				objectroll = 0.0f;
			}
			break;
			case 3300595976: //weevil2
			{
				Normal = 0.441501f;
				Down = 2.009999f;
				Up = 0.100019f;
				objectroll = 0.0f;
			}
			break;
			case 3437611258: //veto
			{
				Normal = 0.202501f;
				Down = 2.009999f;
				Up = 0.070019f;
				objectroll = 0.0f;
			}
			break;
			case 3449006043: //monster
			{
				Normal = 1.172500f;
				Down = 1.509999f;
				Up = 0.270019f;
				objectroll = 0.0f;
			}
			break;

			case 3526730918: //draugur
			{
				Normal = 0.842500f;
				Down = 1.509999f;
				Up = 0.270019f;
				objectroll = 0.0f;
			}
			break;
			case 3540279623: //corsita
			{
				Normal = 0.422501f;
				Down = 1.509999f;
				Up = 0.150019f;
				objectroll = 0.0f;
			}
			break;
			case 3789743831: //omnisegt
			{
				Normal = 0.532501f;
				Down = 2.009999f;
				Up = 0.240019f;
				objectroll = 0.0f;
			}
			break;
			case 3918533058: //tyrant
			{
				Normal = 0.312501f;
				Down = 2.009999f;
				Up = 0.010019f;
				objectroll = 0.0f;
			}
			break;
			case 3970348707: //s80
			{
				Normal = 0.272501f;
				Down = 2.009999f;
				Up = 0.010019f;
				objectroll = 0.0f;
			}
			break;
			case 3981782132: //autarch
			{
				Normal = 0.492501f;
				Down = 2.009999f;
				Up = 0.070019f;
				objectroll = 0.0f;
			}
			break;
			case 4000288633: //postlude
			{
				Normal = 0.452501f;
				Down = 2.009999f;
				Up = 0.100019f;
				objectroll = 0.0f;
			}
			break;
			case 4129572538: //torero2
			{
				Normal = 0.432501f;
				Down = 2.009999f;
				Up = 0.100019f;
				objectroll = 0.0f;
			}
			break;
			case 4180339789: //limo2
			{
				Normal = 0.582501f;
				Down = 2.009999f;
				Up = 0.400019f;
				objectroll = 0.0f;
			}
			break;
			case 4230891418: //kanjosj
			{
				Normal = 0.372501f;
				Down = 1.509999f;
				Up = 0.010019f;
				objectroll = 0.0f;
			}
			break;
			case 4284049613: //lm87
			{
				Normal = 0.301501f;
				Down = 1.509999f;
				Up = 0.010019f;
				objectroll = 0.0f;
			}
			break;
			}
			/*newcars = vehHash;*/
		}
	}
	if (ObjectName == "stt_prop_stunt_bblock_lrg3")
	{
		objectz = 0.13f;
		objecty = 0.0f;
		objectx = 0.0f;
		if (!incars)
		{
			walkinairdword = "stt_prop_stunt_bblock_lrg3";
			Normal = 1.102500f;
			Down = 1.509999f;
			Up = -0.529981f;
			objectroll = 0.0f;
		}
		if (incars)
		{
			Driveinairdword = "stt_prop_stunt_bblock_lrg3";
			Normal = 0.272501f;
			Down = 1.509999f;
			Up = -0.189981f;
			objectroll = 0.0f;
		}
	}
	if (ObjectName == "stt_prop_stunt_bblock_mdm3")
	{
		objectz = 0.13f;
		objecty = 0.0f;
		objectx = 0.0f;
		if (!incars)
		{
			walkinairdword = "stt_prop_stunt_bblock_mdm3";
			Normal = 1.102500f;
			Down = 1.509999f;
			Up = -0.529981f;
			objectroll = 0.0f;
		}
		if (incars)
		{
			Driveinairdword = "stt_prop_stunt_bblock_mdm3";
			Normal = 0.272501f;
			Down = 1.509999f;
			Up = -0.189981f;
			objectroll = 0.0f;
		}
	}
	if (ObjectName == "prop_ld_ferris_wheel")
	{
		objectz = 1.5f;
		objecty = 5.0f;
		objectx = 0.0f;
		objectroll = 90.0f;
		if (!incars)
		{
			walkinairdword = "prop_ld_ferris_wheel";
			Normal = 1.562500;
			Down = 4.009997;
			Up = -1.279980f;
		}
		if (incars)
		{
			Driveinairdword = "prop_ld_ferris_wheel";
			Normal = 0.550001f;
			Down = 4.009996f;
			Up = -0.109979f;
		}
	}
	if (ObjectName == "stt_prop_track_start_02")
	{
		objectz = -0.169999f;
		objecty = -1.190000f;
		objectx = -0.120000f;
		objectroll = 0.0f;
		if (!incars)
		{
			walkinairdword = "stt_prop_track_start_02";
			Normal = 1.240000;
			Down = 2.229998;
			Up = -0.249979f;
		}
		if (incars)
		{
			Driveinairdword = "stt_prop_track_start_02";
			Normal = 0.430001f;
			Down = 1.009999f;
			Up = -0.109979f;
		}
	}
	if (ObjectName == "stt_prop_stunt_landing_zone_01")
	{
		objectz = -0.169999f;
		objecty = -1.190000f;
		objectx = -0.120000f;
		objectroll = 0.0f;
		if (!incars)
		{
			walkinairdword = "stt_prop_stunt_landing_zone_01";
			Normal = 3.412498f;
			Down = 0.1000001f;
			Up = -2.500017f;
		}
		if (incars)
		{
			Driveinairdword = "stt_prop_stunt_landing_zone_01";
			Normal = 2.672499f;
			Down = 4.009997f;
			Up = 2.189979f;
		}
	}
	return 0;
}

H HASH::GET_HASH_KEY(char* value)
{
	size_t len = strlen(value);
	DWORD hash, i;
	for (hash = i = 0; i < len; ++i)
	{
		hash += tolower(value[i]);
		hash += (hash << 10);
		hash ^= (hash >> 6);
	}
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);
	return hash; // joaat
}

Object Features::Create_Obj1(char* ObjectName, Vector3 Coordinates)
{
	Object returnObja;
	Hash ObjectHash = HASH::GET_HASH_KEY(ObjectName);
	if (STREAMING::IsModelInCdimage(ObjectHash))
	{
		if (STREAMING::IsModelValid(ObjectHash))
		{
			STREAMING::RequestModel(ObjectHash/*, 0*/);
			if (STREAMING::HasModelLoaded(ObjectHash))
			{
				returnObja = OBJECT::CreateObjectNoOffset(ObjectHash, Coordinates.x - Features::objectx, Coordinates.y - Features::objecty, Coordinates.z - Features::objectz, 1, 1, 0);


				if (Features::walkinairvisible)
				{
					ENTITY::SetEntityVisible(returnObja, 1, 1);
					/*ENTITY::SET_ENTITY_VISIBLE(returnObja, 1, 1);*/
					ENTITY::SetEntityAlpha(returnObja, 255, 1);
					NETWORK::NetworkRegisterEntityAsNetworked(returnObja);
					NETWORK::_NetworkSetEntityVisibleToNetwork(returnObja, false);
					DWORD id = NETWORK::ObjToNet(returnObja);
					if (NETWORK::NetworkDoesNetworkIdExist(id)) {
						ENTITY::_SetEntitySomething(returnObja, true);
						if (NETWORK::NetworkGetEntityIsNetworked(returnObja)) {
							NETWORK::SetNetworkIdExistsOnAllMachines(id, true);
							NETWORK::_0xA1607996431332DF(id);
						}
					}
				}
				else
				{
					ENTITY::SetEntityVisible(returnObja, 0, 0);
					/*ENTITY::SET_ENTITY_VISIBLE(returnObja, 0, 0);*/
					ENTITY::SetEntityAlpha(returnObja, 0, 0);
					NETWORK::NetworkRegisterEntityAsNetworked(returnObja);
					NETWORK::_NetworkSetEntityVisibleToNetwork(returnObja, true);
					DWORD id = NETWORK::ObjToNet(returnObja);
					if (NETWORK::NetworkDoesNetworkIdExist(id)) {
						ENTITY::_SetEntitySomething(returnObja, true);
						if (NETWORK::NetworkGetEntityIsNetworked(returnObja)) {
							NETWORK::SetNetworkIdExistsOnAllMachines(id, true);
							NETWORK::_0xA1607996431332DF(id);
						}
					}
				}
			}
			else
			{
				returnObja = NULL;
			}
		}
	}
	return ObjectHash;
}

Vector3 Features::CombineVector(float x, float y, float z)
{
	Vector3 returnVector;
	returnVector.x = x;
	returnVector.y = y;
	returnVector.z = z;
	return returnVector;
}
bool Features::stopnotifycar = 1;
bool Features::stoptimer = 1;
int Features::getnotify()
{
	DWORD ticks = GetTickCount64();
	DWORD milliseconds = ticks % 1000;
	ticks /= 1000;
	DWORD seconds = ticks % 60;
	int getTimer = seconds;
	if (getTimer % 15 == 0)
	{
		stopnotifycar = 0;
		stoptimer = 0;
	}
	return 0;
}

void Features::notifyMap(char* fmt, ...)
{
	char buf[2048] = { 0 };
	va_list va_alist;

	va_start(va_alist, fmt);
	vsprintf_s(buf, fmt, va_alist);
	va_end(va_alist);

	char buff2[2048] = { 0 };
	sprintf_s(buff2, "%s", buf);

	HUD::SetTextOutline();
	HUD::_SetNotificationTextEntry("STRING");
	HUD::AddTextComponentSubstringPlayerName(buff2);
	CHooking::draw_notification(FALSE, FALSE);
}	
void Features::notifyMap(std::string str) { notifyMap(&str[0]); }

bool Features::featureWalk1 = false;


bool Features::Driveinsky = 0;
float Features::millesfloatair = 10.0f; //1000.0f
float Features::quatrefloatair = 1.0f; //4.0f
float Features::deuxfloatair = 1.0f; //2.0f
float Features::cinquantefloatair = 50.0f;
float Features::unpointcinqfloatair = 1.5f;
bool Features::dowboolair = false;

namespace PlayerMovementMenuVars {
	struct Vars vars;

	void KeyBoost(float speed) {
		if ((vars.boostKeyController && PAD::IsDisabledControlPressed(0, vars.boostKey)) || KeyDown(vars.boostKey))
			Utils::ApplyForceToEntity(GetLocalPlayer().m_ped, 0, speed, 0);
	}

	void FlyMode() {
		WEAPON::GiveDelayedWeaponToPed(PLAYER::PlayerPedId(), Utils::GetHashKey("GADGET_PARACHUTE"), 1, 1);
		PAD::SetInputExclusive(2, INPUT_FRONTEND_ACCEPT);
		PAD::SetInputExclusive(2, INPUT_FRONTEND_CANCEL);
		PAD::SetInputExclusive(2, INPUT_FRONTEND_DOWN);
		PAD::SetInputExclusive(2, INPUT_FRONTEND_UP);
		PAD::SetInputExclusive(2, INPUT_FRONTEND_LEFT);
		PAD::SetInputExclusive(2, INPUT_FRONTEND_RIGHT);
		if (KeyDown(VK_UP) || PAD::IsControlPressed(0, INPUT_FRONTEND_RT)) { // && !HUD::_IsTextChatActive()
			Utils::ApplyForceToEntity(GetLocalPlayer().m_ped, 0, 6, 0);
		}
		if (KeyDown(VK_DOWN) || PAD::IsControlPressed(0, INPUT_FRONTEND_LT)) {
			Utils::ApplyForceToEntity(GetLocalPlayer().m_ped, 0, -6, 0);
		}
		if (KeyDown(VK_SHIFT) || PAD::IsControlPressed(0, INPUT_FRONTEND_ACCEPT)) {
			Utils::ApplyForceToEntity(GetLocalPlayer().m_ped, 0, 0, 6);
		}
		if (KeyDown(VK_CONTROL) || PAD::IsControlPressed(0, INPUT_FRONTEND_X)) {
			Utils::ApplyForceToEntity(GetLocalPlayer().m_ped, 0, 0, -6);
		}
	}

	void Noclip() {
		GetEntityControl()->SimpleRequestControl(GetLocalPlayer().m_entity);
		if (NETWORK::NetworkHasControlOfEntity(GetLocalPlayer().m_entity)) {
			Vector3 camCoords;

			Utils::GetCameraDirection(&camCoords.x, &camCoords.y, &camCoords.z);

			if (KeyDown(0x57) || PAD::IsDisabledControlPressed(0, 208)) {
				vars.noclipCoords = vars.noclipCoords + (camCoords * vars.noclipspeed);
			}

			if (KeyDown('S') || PAD::IsControlPressed(0, INPUT_FRONTEND_LT)) {
				vars.noclipCoords = vars.noclipCoords - (camCoords * vars.noclipspeed);
			}

			ENTITY::SetEntityCoords(GetLocalPlayer().m_entity, vars.noclipCoords.x, vars.noclipCoords.y, vars.noclipCoords.z, 0, 0, 0, 0);
			ENTITY::SetEntityCollision(GetLocalPlayer().m_entity, 1, 1);
		}
	}

	void FastRun() {
		PLAYER::SetRunSprintMultiplierForPlayer(GetLocalPlayer().m_ped, 1.49f);
		/*WEAPON::RemoveWeaponFromPed(GetLocalPlayer().m_ped, Utils::GetHashKey("GADGET_PARACHUTE"));
		if (PED::IsPedJumping(GetLocalPlayer().m_ped)) {
			Utils::ApplyForceToEntity(GetLocalPlayer().m_ped, 0, 0, 2);
		}*/
	}
	int meplayer = 0;
	void idplayer()
	{
		for (int i = 0; i < 32; i++)
		{
			if (PLAYER::GetPlayerPedScriptIndex(i) == PLAYER::PlayerPedId()) {
				meplayer = i;
			}
		}
	}
	void SuperJump() {
		idplayer();
		/*if (vars.classjumpselect == 1) {
			WEAPON::RemoveWeaponFromPed(GetLocalPlayer().m_ped, Utils::GetHashKey("GADGET_PARACHUTE"));
			MISC::SetSuperJumpThisFrame(GetLocalPlayer().m_id);
		} else {*/

			/*static bool wasJumping;
			static int isJumpingTimer;

			bool isJumping = PED::IsPedJumping(GetLocalPlayer().m_ped);
			if (isJumping && wasJumping) {
				wasJumping = true;
				if (isJumpingTimer > 0) {
					isJumpingTimer--;
					PED::SetPedCanRagdoll(GetLocalPlayer().m_ped, false);*/
					WEAPON::RemoveWeaponFromPed(GetLocalPlayer().m_ped, Utils::GetHashKey("GADGET_PARACHUTE"));
					//Utils::ApplyForceToEntity(GetLocalPlayer().m_ped, 0, 2, 4);

					for (int i = 0; i < 32; i++)
					{
						Player playerPed = PLAYER::PlayerPedId();
						MISC::SetSuperJumpThisFrame(meplayer);
						MISC::SetSuperJumpThisFrame(playerPed);

							//auto actual = Memory2::get_value<uint32_t>({ OFFSET_PLAYER, OFFSET_PLAYER_INFO, OFFSET_PLAYER_INFO_FRAMEFLAGS });//OFFSET_PLAYER_INFO_FRAMEFLAGS //value
							//Memory2::set_value<uint32_t>({ OFFSET_PLAYER, OFFSET_PLAYER_INFO, OFFSET_PLAYER_INFO_FRAMEFLAGS }, actual |= 1 << 14);//OFFSET_PLAYER_INFO_FRAMEFLAGS
					}

				/*}
			} else if (isJumping && !wasJumping) {
				wasJumping = true;
				isJumpingTimer = 10;
			} else if (!isJumping) {
				wasJumping = false;
			}*/
		//}
	}

	void UltraJump() {

		/*if (vars.classjumpselect == 1) {
			MISC::SetSuperJumpThisFrame(GetLocalPlayer().m_id);
			WEAPON::RemoveWeaponFromPed(GetLocalPlayer().m_ped, Utils::GetHashKey("GADGET_PARACHUTE"));
			if (PED::IsPedJumping(GetLocalPlayer().m_ped)) {
				ENTITY::ApplyForceToEntity(GetLocalPlayer().m_ped, true, 0, 0, 5, 0, 0, 0, true, true, true, true, false, true);
			}
		} else {*/

			static bool wasJumping;
			static int isJumpingTimer;

			bool isJumping = PED::IsPedJumping(GetLocalPlayer().m_ped);
			if (isJumping && wasJumping) {
				wasJumping = true;
				if (isJumpingTimer > 0) {
					isJumpingTimer--;
					PED::SetPedCanRagdoll(GetLocalPlayer().m_ped, false);
					WEAPON::RemoveWeaponFromPed(GetLocalPlayer().m_ped, Utils::GetHashKey("GADGET_PARACHUTE"));
					Utils::ApplyForceToEntity(GetLocalPlayer().m_ped, 0, 2.5, 20);
				}
			} else if (isJumping && !wasJumping) {
				wasJumping = true;
				isJumpingTimer = 10;
			} else if (!isJumping) {
				wasJumping = false;
			}
		//}
	}

	void WalkOnWater() {
		static float z;
		static Object waterObject;
		if (ENTITY::DoesEntityExist(waterObject)) {
			WATER::GetWaterHeight(GetLocalPlayer().m_coordinates.x, GetLocalPlayer().m_coordinates.y, GetLocalPlayer().m_coordinates.z, &z);
			ENTITY::SetEntityVisible(waterObject, false, true);
			ENTITY::SetEntityCoords(waterObject, GetLocalPlayer().m_coordinates.x, GetLocalPlayer().m_coordinates.y, z - 1.9f, true, false, false, true);
			ENTITY::SetEntityRotation(waterObject, 180, 90, 180, 2, false);
			ENTITY::FreezeEntityPosition(waterObject, true);
		} else {
			GetEntityControl()->SimpleRequestModel(-1003748966);
			waterObject = OBJECT::CreateObject(-1003748966, GetLocalPlayer().m_coordinates.x, GetLocalPlayer().m_coordinates.y, GetLocalPlayer().m_coordinates.z, 1, 1, 0);
			ENTITY::FreezeEntityPosition(waterObject, true);
			ENTITY::SetEntityCollision(waterObject, true, false);
		}
	}

	void WalkThroughWater() {
		float offset[] = { -4, 4 };
		for (int i = 0; i < 5; i++) {
			Vector3 coords = GetLocalPlayer().m_coordinates;
			if (i < 2)  coords.x += offset[(i % 2 == 0)];
			else if (i < 4) coords.y += offset[(i % 2 == 0)];
			WATER::ModifyWater(coords.x, coords.y, -500000.0f, 0.2f);
		}
	}

	void SlowMotion(bool toggle) {
		MISC::SetTimeScale(toggle ? 0.5f : 1);
	}

	void VegetableMode() {
		PED::SetPedToRagdoll(GetLocalPlayer().m_ped, 10, 10, 0, true, true, true);
		if (KeyDown('W')) Utils::ApplyForceToEntity(GetLocalPlayer().m_ped, 0, 2, 0);
		if (KeyDown('S')) Utils::ApplyForceToEntity(GetLocalPlayer().m_ped, 0, -2, 0);
		if (KeyDown('A')) Utils::ApplyForceToEntity(GetLocalPlayer().m_ped, 2, 0, 0);
		if (KeyDown('D')) Utils::ApplyForceToEntity(GetLocalPlayer().m_ped, -2, 0, 0);
	}
			void WalkOnAir() {
				Features::featureWalk1 = vars.walkonair;
				if (Features::featureWalk1)
				{
					char* prop = (char*)Features::walkinairdword;
					if (Features::firstwalk || Features::ifwalkorincar)
					{
						Features::checkifwalk(prop);
						Features::firstwalk = 0;
					}
					if (!Features::incars)
					{
						if (!Features::opened_before2)
						{
							if (Features::stoptimer)
							{
								Features::getnotify();
								if (Features::stopnotifycar)
									Features::notifyMap("F2 or R3_79 activate walk in sky and in a car \n press q for up, and z for down \n");
							}
							if (helpers::get_key_state(VK_KEY_Z, 1) || helpers::get_key_state(VK_KEY_Q, 1))
							{
								Features::opened_before2 = true;
							}
						}
						bool opencontroller = (PAD::IsDisabledControlJustPressed(2, Features::open22) & 1);
						bool openf3 = (GetAsyncKeyState(VK_F2) & 1);
						if (openf3 || opencontroller)
						{
							Features::walkinsky = !Features::walkinsky;
						}
						if (Features::walkinsky)
						{
							Hash ObjHash = HASH::GET_HASH_KEY(prop);
							Player me = PLAYER::PlayerPedId();
							Vector3 PlayerCoord;
							PlayerCoord = ENTITY::GetEntityCoords(me, 0/*, 0*/);
							float zPlane;
							Object WalkOnAir = OBJECT::GetClosestObjectOfType(PlayerCoord.x, PlayerCoord.y, PlayerCoord.z, 100, ObjHash, 1, 0, 1);
							if (!ENTITY::DoesEntityExist(WalkOnAir) && (Features::featureWalk1))
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
							else if (ENTITY::DoesEntityExist(WalkOnAir) && (Features::featureWalk1))
							{
								if (PED::IsPedInAnyVehicle(me, 0))
								{
									zPlane = PlayerCoord.z - Features::Vehicular;
								}
								else
									if (GetAsyncKeyState(0x5A) || (PAD::IsDisabledControlJustPressed(2, INPUT_SCRIPT_LS)))      //Down Z and L3          
									{
										zPlane = PlayerCoord.z - Features::Down;
									}
									else if (GetAsyncKeyState(0x51) || (PAD::IsDisabledControlJustPressed(2, INPUT_SCRIPT_RS)))      //Up Q and R3  
									{
										zPlane = PlayerCoord.z + Features::Up;
									}
									else                                              //Normal
									{
										zPlane = PlayerCoord.z - Features::Normal;
									}
								Vector3 pRot = ENTITY::GetEntityRotation(me, 0);
								ENTITY::SetEntityRotation(WalkOnAir, 0, 0, pRot.z, 0, 1);
								Vector3 Coord = Features::CombineVector(PlayerCoord.x, PlayerCoord.y, zPlane);
								ENTITY::SetEntityRotation(WalkOnAir, Features::objectpitch, Features::objectroll, Features::objectyaw, Features::rotationOrder, 1);
								/*ENTITY::SET_ENTITY_COORDS_NO_OFFSET(WalkOnAir, Coord.x - objectx, Coord.y - objecty, Coord.z - objectz, 1, 0, 1);*/
								ENTITY::/*SET_ENTITY_COORDS_NO_OFFSET*/_SetEntityCoords2(WalkOnAir, Coord.x - Features::objectx, Coord.y - Features::objecty, Coord.z - Features::objectz, 0, 0, 0, 0);
							}
						}
					}
					else if (Features::incars)
					{
						Features::dowboolair = true;
					}
				}
				//return 0;
			/*float zPlane;
			Hash objectHash = Utils::GetHashKey("p_oil_slick_01");
			static Object WalkOnAirHandle;

			if (!ENTITY::DoesEntityExist(WalkOnAirHandle)) {
				if (!STREAMING::HasModelLoaded(objectHash)) {
					STREAMING::RequestModel(objectHash);
				} else {
					WalkOnAirHandle = OBJECT::CreateObject(objectHash, GetLocalPlayer().m_coordinates.x, GetLocalPlayer().m_coordinates.y, GetLocalPlayer().m_coordinates.z, 1, 1, 0);
					ENTITY::FreezeEntityPosition(WalkOnAirHandle, 1);
					ENTITY::SetEntityVisible(WalkOnAirHandle, 0, 0);
				}
			} else {
				if (KeyDown(VK_SHIFT)) {
					zPlane = GetLocalPlayer().m_coordinates.z - 1.60;
				} else if (KeyDown(VK_SPACE)) {
					zPlane = GetLocalPlayer().m_coordinates.z - 0.40;
				} else {
					zPlane = GetLocalPlayer().m_coordinates.z - 1.0225;
				}
				GetScaleform()->DrawInstructional("Up", g_keyNamesInstructional[VK_SPACE]);
				GetScaleform()->DrawInstructional("Down", g_keyNamesInstructional[VK_SHIFT]);

				ENTITY::SetEntityCoords(WalkOnAirHandle, GetLocalPlayer().m_coordinates.x, GetLocalPlayer().m_coordinates.y, zPlane, 1, 0, 0, 0);

			}*/
			}

			const int KEYS_SIZE = 255;
			const int NOW_PERIOD = 100, MAX_DOWN = 5000; // ms

			struct {
				DWORD time;
				BOOL isWithAlt;
				BOOL wasDownBefore;
				BOOL isUpNow;
			} keyStates[KEYS_SIZE];

			bool get_key_pressed(int nVirtKey)
			{
				return (GetAsyncKeyState(nVirtKey) & 0x8000) != 0;
			}

			bool IsKeyDown(DWORD key)
			{
				return (key < KEYS_SIZE) ? ((GetTickCount() < keyStates[key].time + MAX_DOWN) && !keyStates[key].isUpNow) : false;
			}

			float speedmult2 = 0.5f;
			void WalkingNoclip() {
				bool jumping = PED::IsPedJumping(GetLocalPlayer().m_ped);
				bool falling = PED::IsPedFalling(GetLocalPlayer().m_ped);
				bool paraState = PED::GetPedParachuteState(GetLocalPlayer().m_ped);
				float speed = ENTITY::GetEntitySpeed(GetLocalPlayer().m_ped);
				Vector3 velocity = ENTITY::GetEntityVelocity(GetLocalPlayer().m_ped);
				Vector3 rotation = ENTITY::GetEntityRotation(GetLocalPlayer().m_ped, false);
				Vector3 position = ENTITY::GetEntityCoords(GetLocalPlayer().m_ped, true);
				Vector3 direction = ENTITY::GetEntityForwardVector(GetLocalPlayer().m_ped);
				int vehiclerotation = 0;


				{
					ENTITY::SetEntityMaxSpeed(GetLocalPlayer().m_entity, 0);
					if (get_key_pressed(VK_NUMPAD7)) {
						vars.speedmult += 0.5f;
					}
					else if (get_key_pressed(VK_NUMPAD1)) {
						if (!vars.speedmult < 0.01f)
							vars.speedmult -= 0.5f;
					}
					if (!GetLocalPlayer().m_isInVehicle) {
						ENTITY::SetEntityCollision(GetLocalPlayer().m_ped, 0, 0);
						vehiclerotation = 0;
						ENTITY::SetEntityCollision(GetLocalPlayer().m_vehicle, true, true);
						Vector3 weirdRotation = ENTITY::GetEntityRotation(GetLocalPlayer().m_ped, 2);
						float yaw = weirdRotation.z;
						if (get_key_pressed('W') || get_key_pressed('A') || get_key_pressed('D') || get_key_pressed('S') || PAD::IsControlPressed(0, INPUT_FRONTEND_ACCEPT)) {
							if (PAD::IsDisabledControlPressed(0, 25)) {//d=-a=+
								if (get_key_pressed('S')) {
									ENTITY::SetEntityCoords(GetLocalPlayer().m_ped, position.x - ENTITY::GetEntityForwardX(GetLocalPlayer().m_ped) * vars.speedmult, position.y - ENTITY::GetEntityForwardY(GetLocalPlayer().m_ped) * vars.speedmult, (position.z - 1), true, true, true, true);
								}
								else {
									ENTITY::SetEntityCoords(GetLocalPlayer().m_ped, position.x + ENTITY::GetEntityForwardX(GetLocalPlayer().m_ped) * vars.speedmult, position.y + ENTITY::GetEntityForwardY(GetLocalPlayer().m_ped) * vars.speedmult, (position.z - 1), true, true, true, true);
								}
							}
							else {
								if (get_key_pressed('A')) {
									yaw += 2;
									ENTITY::SetEntityRotation(GetLocalPlayer().m_ped, 0, 0, yaw, 0, 0);
								}
								else if (get_key_pressed('D')) {
									yaw -= 2;
									ENTITY::SetEntityRotation(GetLocalPlayer().m_ped, 0, 0, yaw, 0, 0);
								}
								if (IsKeyDown('S')) {
									ENTITY::SetEntityRotation(GetLocalPlayer().m_ped, 0, 0, yaw, 0, 0);
									ENTITY::SetEntityCoords(GetLocalPlayer().m_ped, position.x - ENTITY::GetEntityForwardX(GetLocalPlayer().m_ped) * vars.speedmult, position.y - ENTITY::GetEntityForwardY(GetLocalPlayer().m_ped) * vars.speedmult, (position.z - 1), true, true, true, true);
								}
								else {
									ENTITY::SetEntityCoords(GetLocalPlayer().m_ped, position.x + ENTITY::GetEntityForwardX(GetLocalPlayer().m_ped) * vars.speedmult, position.y + ENTITY::GetEntityForwardY(GetLocalPlayer().m_ped) * vars.speedmult, (position.z - 1), true, true, true, true);
								}
							}
						}
						position = ENTITY::GetEntityCoords(GetLocalPlayer().m_ped, true);
						direction = ENTITY::GetEntityForwardVector(GetLocalPlayer().m_ped);
						if (get_key_pressed(VK_SPACE) || PAD::IsControlPressed(0, INPUT_FRONTEND_RB)) {
							ENTITY::SetEntityCoords(GetLocalPlayer().m_ped, position.x, position.y, ((position.z - 1) + 0.5 * speedmult2), true, true, true, true);
						}
						position = ENTITY::GetEntityCoords(GetLocalPlayer().m_ped, true);
						direction = ENTITY::GetEntityForwardVector(GetLocalPlayer().m_ped);
						if (get_key_pressed(VK_LCONTROL) || PAD::IsControlPressed(0, INPUT_FRONTEND_LT)) {
							ENTITY::SetEntityCoords(GetLocalPlayer().m_ped, position.x, position.y, ((position.z - 1) - 0.5 * speedmult2), true, true, true, true);
						}
					}
					else {
						WorldMenuVars::vars.RequestControlOfEnt(GetLocalPlayer().m_vehicle);
						Vector3 position = ENTITY::GetEntityCoords(GetLocalPlayer().m_vehicle, true);
						ENTITY::SetEntityCollision(GetLocalPlayer().m_ped, 0, 0);
						ENTITY::SetEntityCollision(GetLocalPlayer().m_vehicle, 0, 0);
						vehiclerotation = 0;
						Vector3 weirdRotation = ENTITY::GetEntityRotation(GetLocalPlayer().m_vehicle, 2);
						float roll = ENTITY::GetEntityRoll(GetLocalPlayer().m_vehicle);
						float yaw/*A CHANGE*/ = weirdRotation.z;
						float pitch = ENTITY::GetEntityPitch(GetLocalPlayer().m_vehicle);
						vehiclerotation = yaw;
						if (get_key_pressed('W') || get_key_pressed('A') || get_key_pressed('D') || get_key_pressed('S')) {
							if (get_key_pressed('S')) {
								ENTITY::SetEntityCoordsNoOffset(GetLocalPlayer().m_vehicle, position.x - ENTITY::GetEntityForwardX(GetLocalPlayer().m_ped) * vars.speedmult, position.y - ENTITY::GetEntityForwardY(GetLocalPlayer().m_ped) * vars.speedmult, position.z, 0, 0, 0);

							}
							else {
								ENTITY::SetEntityCoordsNoOffset(GetLocalPlayer().m_vehicle, position.x + ENTITY::GetEntityForwardX(GetLocalPlayer().m_ped) * vars.speedmult, position.y + ENTITY::GetEntityForwardY(GetLocalPlayer().m_ped) * vars.speedmult, position.z, 0, 0, 0);
							}
							if (get_key_pressed('A'))
								yaw += 4;
							if (get_key_pressed('D'))
								yaw -= 4;
							ENTITY::SetEntityRotation(GetLocalPlayer().m_vehicle, 0, 0, yaw, 0, 0);
						}

						position = ENTITY::GetEntityCoords(GetLocalPlayer().m_ped, true);
						if (get_key_pressed(VK_SPACE)) {
							ENTITY::SetEntityCoordsNoOffset(GetLocalPlayer().m_vehicle, position.x, position.y, ((position.z + 1) + 0.5 * speedmult2), 0, 0, 0);
						}
						if (get_key_pressed(VK_LCONTROL)) {
							ENTITY::SetEntityCoordsNoOffset(GetLocalPlayer().m_vehicle, position.x, position.y, ((position.z - 1) - 0.5 * speedmult2), 0, 0, 0);
						}
					}

					if (!GetLocalPlayer().m_isInVehicle) {
						if (jumping || falling || paraState == 0) {
							ENTITY::SetEntityCoords(GetLocalPlayer().m_ped, position.x, position.y, (position.z - 1), 0, 0, 0, 0);
						}

						ENTITY::SetEntityVelocity(GetLocalPlayer().m_ped, 0, 0, 0);
					}
					else {
						ENTITY::SetEntityMaxSpeed(GetLocalPlayer().m_vehicle, 500);
						ENTITY::SetEntityCollision(GetLocalPlayer().m_vehicle, 1, 0);

						vehiclerotation = 0;
						WorldMenuVars::vars.RequestControlOfEnt(GetLocalPlayer().m_vehicle);
						ENTITY::SetEntityCollision(GetLocalPlayer().m_vehicle, true, true);
						ENTITY::SetEntityMaxSpeed(GetLocalPlayer().m_vehicle, 500);
					}
				}
			}

			ScrollStruct<int> jumpmode[] = {
				TranslationString("Modified", true), 0,
				TranslationString("Classic", true), 1
			};

		}


void PlayerMovementMenu::Init() {
	setParentSubmenu<LocalMenu>();
	setName("Movement", true, true);

	//addOption(ToggleOption("Fast run")
	//	.addToggle(vars.fastrun)
	//	.addHotkey().canBeSaved()
	//	.addTooltip("Fly using shift, ctrl, up and down"));

	/*addOption(ScrollOption<int>(TOGGLE, "Super jump")
		.addToggle(vars.superjump)
		.addScroll(vars.classjumpselect, 0, NUMOF(jumpmode) - 1, jumpmode)
		.addHotkey().canBeSaved().addTranslation()
		.addTooltip("Super jump"));*/

	addOption(ToggleOption("Super jump")
		.addToggle(vars.superjump)
		.addHotkey().canBeSaved().addTranslation()
		.addTooltip("Super jump"));

	addOption(ToggleOption("Ultra jump")
		.addToggle(vars.ultrajump)
		.addHotkey().canBeSaved().addTranslation()
		.addTooltip("Ultra jump"));

	/*addOption(NumberOption<float>(TOGGLE, "Movement speed multiplier")
		.addToggle(vars.enableMovementSpeed)
		.addNumber(vars.movementSpeed, "%.2f", 0.2f)
		.addHotkey().addTranslation()
		.addFunction([] {ReClass::GetWorld()->LocalPed->PlayerInfo->RunSpeed = vars.enableMovementSpeed ? vars.movementSpeed : 1.0f; })
		.addTooltip("Movement speed multiplier"));

	addOption(NumberOption<float>(TOGGLE, "Swim speed multiplier")
		.addToggle(vars.enableSwimSpeed)
		.addNumber(vars.swimSpeed, "%.2f", 0.2f)
		.addHotkey().addTranslation()
		.addFunction([] {ReClass::GetWorld()->LocalPed->PlayerInfo->SwimSpeed = vars.enableSwimSpeed ? vars.movementSpeed : 1.0f; })
		.addTooltip("Swim speed multiplier"));*/

	addOption(ToggleOption("Flymode")
		.addToggle(vars.flymode)
		.addHotkey().canBeSaved().addTranslation()
		.addTooltip("Fly using shift, ctrl, up and down || RT / LT - A / X"));

	addOption(ToggleOption("Vegetable mode")
		.addToggle(vars.vegetablemode).addTranslation()
		.addHotkey().canBeSaved()
		.addTooltip("Ragdoll! make sure to turn off no ragdoll!"));

	addOption(ToggleOption("Slow motion")
		.addToggle(vars.slowmotion).addTranslation()
		.addFunction([] {SlowMotion(vars.slowmotion); })
		.addHotkey().canBeSaved()
		.addTooltip("Slow time"));

	addOption(BreakOption("Noclip").addTranslation());

	addOption(ToggleOption("Noclip")
		.addToggle(vars.noclip)
		.addFunction([] { vars.noclipCoords = GetLocalPlayer().m_coordinates; })
		.addHotkey().canBeSaved().addTranslation()
		.addTooltip("Aim with mouse/controller then use W or right trigger"));

	addOption(NumberOption<float>(SCROLL, "Noclip speed")
		.addNumber(vars.noclipspeed, "%.1f", 1.0f).addMin(1.0f).addMax(50.0f)
		.addHotkey()
		.addTooltip("Control the speed of your noclip"));

	addOption(ToggleOption("Walking noclip")
		.addToggle(vars.walkingnoclip)
		.addFunction([] {
		ENTITY::SetEntityMaxSpeed(GetLocalPlayer().m_ped, 1000);
		ENTITY::SetEntityCollision(GetLocalPlayer().m_ped, 1, 0);
		if (PED::IsPedInAnyVehicle(GetLocalPlayer().m_ped, 1)) {
			WorldMenuVars::vars.RequestControlOfEnt(GetLocalPlayer().m_vehicle);
			ENTITY::SetEntityCollision(GetLocalPlayer().m_vehicle, 1, 0);
		}
	})
		.addHotkey().canBeSaved().addTranslation()
		.addTooltip("This will allow you to walk and shoot while noclipping (CTRL to go down - Space to go up) || A / RB / LT"));

	addOption(NumberOption<float>(SCROLL, "Walking noclip speed")
		.addNumber(vars.speedmult, "%.1f", 0.5f).addMin(0.5f).addMax(10.0f)
		.addHotkey()
		.addTooltip("Control the speed of your walking noclip"));

	addOption(BreakOption("Super run").addTranslation());

	addOption(NumberOption<float>(TOGGLE, "Super run")
		.addToggle(vars.speedboost)
		.addNumber(vars.speedboostamount, "%.1f", 0.2f).addMin(0).addMax(10)
		.addHotkey().canBeSaved().addTranslation()
		.addTooltip("Use the assigned key to super run"));

	addOption(KeyOption("Super run key")
		.addKeyWithControllerSupport(vars.boostKey, vars.boostKeyController)
		.canBeSaved().addHotkey().addTranslation()
		.addTooltip("Set the key"));

	addOption(BreakOption("Water").addTranslation());

	addOption(ToggleOption("Walk on water")
		.addToggle(vars.walkonwater)
		.addHotkey().canBeSaved().addTranslation()
		.addTooltip("Walk on water"));

	addOption(ToggleOption("Walk through water")
		.addToggle(vars.walkthroughwater)
		.addHotkey().canBeSaved().addTranslation()
		.addTooltip("Walk through water"));


	addOption(ToggleOption("Walk on air")
		.addToggle(vars.walkonair)
		.addHotkey().canBeSaved().addTranslation()
		.addTooltip("z to go down, q to go up"));

	addOption(SubmenuOption("Drive On Air")
		.addSubmenu<DriverMenu>().addHotkey().addTranslation()
		.addTooltip("Drive On Air"));
}

/*Update once when submenu is opened*/
void PlayerMovementMenu::UpdateOnce() {}

/*Update while submenu is active*/
void PlayerMovementMenu::Update() {}

/*Background update*/
void PlayerMovementMenu::FeatureUpdate() {
	if (vars.flymode) FlyMode();
	if (vars.speedboost)KeyBoost(vars.speedboostamount);
	if (vars.noclip) Noclip();
	if (vars.fastrun)FastRun();
	if (vars.superjump)SuperJump();
	if (vars.ultrajump)UltraJump();
	if (vars.walkonwater)WalkOnWater();
	if (vars.walkthroughwater)WalkThroughWater();
	if (vars.walkonair)WalkOnAir();
	if (vars.slowmotion)SlowMotion(true);
	if (vars.vegetablemode)VegetableMode();
	if (vars.walkingnoclip) WalkingNoclip();
}

/*Singleton*/
PlayerMovementMenu* _instance;
PlayerMovementMenu* PlayerMovementMenu::GetInstance() {
	if (_instance == nullptr) {
		_instance = new PlayerMovementMenu();
		_instance->Init();
		GetSubmenuHandler()->addSubmenu(_instance);
	}
	return _instance;
}
PlayerMovementMenu::~PlayerMovementMenu() { delete _instance; }

