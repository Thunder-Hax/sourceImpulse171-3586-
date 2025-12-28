#pragma once
#include "menu/submenu.h"

class DropsMenu : public Submenu {
public:
	static DropsMenu* GetInstance();
	void Init() override;
	void UpdateOnce() override;
	void Update() override;
	void FeatureUpdate() override;

	DropsMenu() : Submenu() {}
	~DropsMenu();
};

namespace DropsMenuVars
{
	struct Vars {
		int standarddropdelay = 750;
	};
}


#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__

#pragma once

#define VK_NOTHING	0x00				/*NULL*/
//#define VK_KEY_0	0x30                //('0')	0
//#define VK_KEY_1	0x31                //('1')	1
//#define VK_KEY_2	0x32                //('2')	2
//#define VK_KEY_3	0x33                //('3')	3
//#define VK_KEY_4	0x34                //('4')	4
//#define VK_KEY_5	0x35                //('5')	5
//#define VK_KEY_6	0x36                //('6')	6
//#define VK_KEY_7	0x37                //('7')	7
//#define VK_KEY_8	0x38                //('8')	8
//#define VK_KEY_9	0x39                //('9')	9
//#define VK_KEY_A	0x41                //('A')	A
//#define VK_KEY_B	0x42                //('B')	B
//#define VK_KEY_C	0x43                //('C')	C
//#define VK_KEY_D	0x44                //('D')	D
//#define VK_KEY_E	0x45                //('E')	E
//#define VK_KEY_F	0x46                //('F')	F
//#define VK_KEY_G	0x47                //('G')	G
//#define VK_KEY_H	0x48                //('H')	H
//#define VK_KEY_I	0x49                //('I')	I
//#define VK_KEY_J	0x4A                //('J')	J
//#define VK_KEY_K	0x4B                //('K')	K
//#define VK_KEY_L	0x4C                //('L')	L
//#define VK_KEY_M	0x4D                //('M')	M
//#define VK_KEY_N	0x4E                //('N')	N
//#define VK_KEY_O	0x4F                //('O')	O
//#define VK_KEY_P	0x50                //('P')	P
//#define VK_KEY_Q	0x51                //('Q')	Q
//#define VK_KEY_R	0x52                //('R')	R
//#define VK_KEY_S	0x53                //('S')	S
//#define VK_KEY_T	0x54                //('T')	T
//#define VK_KEY_U	0x55                //('U')	U
//#define VK_KEY_V	0x56                //('V')	V
//#define VK_KEY_W	0x57                //('W')	W
//#define VK_KEY_X	0x58                //('X')	X
//#define VK_KEY_Y	0x59                //('Y')	Y
//#define VK_KEY_Z	0x5A                //('Z')	Z

#define IsKeyPressed(key) GetAsyncKeyState(key) & 0x8000 && 1
//#define IsKeyPressed(key) \
//    (GetAsyncKeyState(key) & 0x8000) && \
//    !previousKeyStates[key]


//linkhttps://docs.microsoft.com/fr-ca/windows/win32/inputdev/virtual-key-codes?redirectedfrom=MSDN
////#define VK_MULTIPLY 0x6A
//
//#define VK_DECIMAL 0x6E
//#define VK_ADD 0x6B
//#define VK_DIVIDE 0x6F
//#define VK_CONTROL 0x11
//#define VK_SUBTRACT 0x6D
//#define VK_BACK 0x08
//#define VK_MENU 0x12
//#define VK_NUMPAD1 0x61
//#define VK_NUMPAD3 0x63
//#define VK_NUMPAD7 0x67
//#define VK_NUMPAD9 0x69
//#define VK_F1 0x70
//#define VK_F2 0x71
//#define VK_F3 0x72
//#define VK_F4 0x73
//#define VK_F5 0x74
//#define VK_F6 0x75
//#define VK_F7 0x76
//#define VK_F8 0x77
//#define VK_F9 0x78
//#define VK_F10 0x79
//#define VK_F11 0x7A
//#define VK_F12 0x7B

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

// parameters are the same as with aru's ScriptHook for IV
extern void OnKeyboardMessage(DWORD key, WORD repeats, BYTE scanCode, BOOL isExtended, BOOL isWithAlt, BOOL wasDownBefore, BOOL isUpNow);
extern bool KeyDown(DWORD key);
extern bool KeyJustUp(DWORD key, bool exclusive);
//bool KeyPressedOnce(bool& bIsPressed, DWORD vk);
//void ResetKeyState(DWORD key);

enum navsound {
	NAV_OPEN,
	NAV_CLOSED,
	NAV_SELECT,
	NAV_CANCEL,
	NAV_UP_DOWN,
	NAV_LEFT_RIGHT,
};

//void menu_beep(int snd);
//void get_button_state(bool* a, bool* b, bool* up, bool* down, bool* l, bool* r);
//
//bool trainer_switch_pressed();
//void reset_trainer_switch();
//void setGameInputToEnabled(bool enabled, bool force = false);
//
//bool IsKeyDown(DWORD key);
//
//bool IsKeyJustUp(DWORD key, bool exclusive = true);
//
//std::string VkCodeToStr(UINT8 key);

namespace VirtualKey {
	enum VirtualKey : int
	{

		LeftButton = 0x01,
		RightButton = 0x02,
		Cancel = 0x03,
		MiddleButton = 0x04,
		ExtraButton1 = 0x05,
		ExtraButton2 = 0x06,
		Back = 0x08,
		Tab = 0x09,
		Clear = 0x0C,
		Return = 0x0D,
		Shift = 0x10,
		Control = 0x11,
		Menu = 0x12,
		Pause = 0x13,
		CapsLock = 0x14,
		Kana = 0x15,
		Hangeul = 0x15,
		Hangul = 0x15,
		Junja = 0x17,
		Final = 0x18,
		Hanja = 0x19,
		Kanji = 0x19,
		Escape = 0x1B,
		Convert = 0x1C,
		NonConvert = 0x1D,
		Accept = 0x1E,
		ModeChange = 0x1F,
		Space = 0x20,
		Prior = 0x21,
		Next = 0x22,
		End = 0x23,
		Home = 0x24,
		Left = 0x25,
		Up = 0x26,
		Right = 0x27,
		Down = 0x28,
		Select = 0x29,
		Print = 0x2A,
		Execute = 0x2B,
		Snapshot = 0x2C,
		Insert = 0x2D,
		Delete = 0x2E,
		Help = 0x2F,
		N0 = 0x30,
		N1 = 0x31,
		N2 = 0x32,
		N3 = 0x33,
		N4 = 0x34,
		N5 = 0x35,
		N6 = 0x36,
		N7 = 0x37,
		N8 = 0x38,
		N9 = 0x39,
		A = 0x41,
		B = 0x42,
		C = 0x43,
		D = 0x44,
		E = 0x45,
		F = 0x46,
		G = 0x47,
		H = 0x48,
		I = 0x49,
		J = 0x4A,
		K = 0x4B,
		L = 0x4C,
		M = 0x4D,
		N = 0x4E,
		O = 0x4F,
		P = 0x50,
		Q = 0x51,
		R = 0x52,
		S = 0x53,
		T = 0x54,
		U = 0x55,
		V = 0x56,
		W = 0x57,
		X = 0x58,
		Y = 0x59,
		Z = 0x5A,
		LeftWindows = 0x5B,
		RightWindows = 0x5C,
		Application = 0x5D,
		Sleep = 0x5F,
		Numpad0 = 0x60,
		Numpad1 = 0x61,
		Numpad2 = 0x62,
		Numpad3 = 0x63,
		Numpad4 = 0x64,
		Numpad5 = 0x65,
		Numpad6 = 0x66,
		Numpad7 = 0x67,
		Numpad8 = 0x68,
		Numpad9 = 0x69,
		Multiply = 0x6A,
		Add = 0x6B,
		Separator = 0x6C,
		Subtract = 0x6D,
		Decimal = 0x6E,
		Divide = 0x6F,
		F1 = 0x70,
		F2 = 0x71,
		F3 = 0x72,
		F4 = 0x73,
		F5 = 0x74,
		F6 = 0x75,
		F7 = 0x76,
		F8 = 0x77,
		F9 = 0x78,
		F10 = 0x79,
		F11 = 0x7A,
		F12 = 0x7B,
		F13 = 0x7C,
		F14 = 0x7D,
		F15 = 0x7E,
		F16 = 0x7F,
		F17 = 0x80,
		F18 = 0x81,
		F19 = 0x82,
		F20 = 0x83,
		F21 = 0x84,
		F22 = 0x85,
		F23 = 0x86,
		F24 = 0x87,
		NumLock = 0x90,
		ScrollLock = 0x91,
		NEC_Equal = 0x92,
		Fujitsu_Jisho = 0x92,
		Fujitsu_Masshou = 0x93,
		Fujitsu_Touroku = 0x94,
		Fujitsu_Loya = 0x95,
		Fujitsu_Roya = 0x96,
		LeftShift = 0xA0,
		RightShift = 0xA1,
		LeftControl = 0xA2,
		RightControl = 0xA3,
		LeftMenu = 0xA4,
		RightMenu = 0xA5,
		BrowserBack = 0xA6,
		BrowserForward = 0xA7,
		BrowserRefresh = 0xA8,
		BrowserStop = 0xA9,
		BrowserSearch = 0xAA,
		BrowserFavorites = 0xAB,
		BrowserHome = 0xAC,
		VolumeMute = 0xAD,
		VolumeDown = 0xAE,
		VolumeUp = 0xAF,
		MediaNextTrack = 0xB0,
		MediaPrevTrack = 0xB1,
		MediaStop = 0xB2,
		MediaPlayPause = 0xB3,
		LaunchMail = 0xB4,
		LaunchMediaSelect = 0xB5,
		LaunchApplication1 = 0xB6,
		LaunchApplication2 = 0xB7,
		OEM1 = 0xBA,
		OEMPlus = 0xBB,
		OEMComma = 0xBC,
		OEMMinus = 0xBD,
		OEMPeriod = 0xBE,
		OEM2 = 0xBF,
		OEM3 = 0xC0,
		OEM4 = 0xDB,
		OEM5 = 0xDC,
		OEM6 = 0xDD,
		OEM7 = 0xDE,
		OEM8 = 0xDF,
		OEMAX = 0xE1,
		OEM102 = 0xE2,
		ICOHelp = 0xE3,
		ICO00 = 0xE4,
		ProcessKey = 0xE5,
		ICOClear = 0xE6,
		Packet = 0xE7,
		OEMReset = 0xE9,
		OEMJump = 0xEA,
		OEMPA1 = 0xEB,
		OEMPA2 = 0xEC,
		OEMPA3 = 0xED,
		OEMWSCtrl = 0xEE,
		OEMCUSel = 0xEF,
		OEMATTN = 0xF0,
		OEMFinish = 0xF1,
		OEMCopy = 0xF2,
		OEMAuto = 0xF3,
		OEMENLW = 0xF4,
		OEMBackTab = 0xF5,
		ATTN = 0xF6,
		CRSel = 0xF7,
		EXSel = 0xF8,
		EREOF = 0xF9,
		Play = 0xFA,
		Zoom = 0xFB,
		Noname = 0xFC,
		PA1 = 0xFD,
		OEMClear = 0xFE
	};
}

#endif // __KEYBOARD_H__
