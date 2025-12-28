#pragma once

class Global {
private:
	void* _handle;

public:
	Global(int index) : _handle(&Backend::GetGlobalPtr()[index >> 18 & 0x3F][index & 0x3FFFF]) {}
	Global(void* p) : _handle(p) {}
	Global(const Global& copy) : _handle(copy._handle) {}

	Global At(int index) const {
		return Global(reinterpret_cast<void**>(this->_handle) + (index));
	}

	Global At(int index, int size) const {
		return this->At(1 + (index * size));
	}

	template <typename T>
	T* Get() {
		return reinterpret_cast<T*>(this->_handle);
	}

	template <typename T>
	T& As() {
		return *this->Get<T>();
	}
};

typedef __int64(__cdecl* fpGetPlayerAddress)(Player);
typedef Entity(__cdecl* fpAddressToEntity)(__int64);
typedef char* (__cdecl* fpGetPlayerName)(Player player);

typedef Vehicle(__cdecl* fpCreateVehicle)(Hash model, Vector3* pos, float heading, BOOL networked, BOOL unk2);
typedef bool(__cdecl* fpTriggerScriptEvent)(int, void*, int, int, int);

//typedef Vehicle(__cdecl* fpworldscreen)(Vector3* pos, float x, float y);
//typedef BOOL ScreenWorld;
//typedef ScreenWorld(__cdecl* fpworldscreen)(Vector3 pos, float x, float y);

typedef unsigned long DWORD;
typedef DWORD H;
namespace HASH
{
	H GET_HASH_KEY(char* value);
	/*H GET_HASH_KEY(const std::wstring& value);
	H GET_HASH_KEY(const std::string& value);
	extern DWORD value3;
	H GETHASHKEYSTRING(std::string hexstring);
	extern std::string hex;
	H GETHASHKEYDWORD(DWORD value2);*/
}
typedef void(__cdecl* fpDrawRect)(float x, float y, float width, float height, int r, int g, int b, int a);
typedef BOOL(__cdecl* fpDrawNotification)(BOOL blink, BOOL showInBrief);
class CHooking
{
public:
	static fpDrawRect							draw_rect;
	static fpDrawNotification					draw_notification;
};

class Hooked
{
public:
	static fpTriggerScriptEvent	trigger_script_event;
	static fpCreateVehicle			create_vehicle;	
	static __int64** m_globalPtr2;
	static __int64** getGlobalPtr2();
	static __int64** m_globalPtr;
	static __int64** getGlobalPtr();
	static uint64_t m_worldPtr;
	static uint64_t getWorldPtr();

	static Ped get_player_ped(Player player);
	static fpGetPlayerAddress       GetPlayerAddress;
	static fpAddressToEntity		AddressToEntity;
	static fpGetPlayerName	        get_player_name;

	//static fpworldscreen	        world_screen;

	static bool Hooked::spectateplayer;
	static void Hooked::setinspectatormode(BOOL toggle, Ped playerPed);
};

class globalHandle
{
private:
	void* _handle;

public:
	globalHandle(int index)
		: _handle(&Hooked::getGlobalPtr2()[index >> 18 & 0x3F][index & 0x3FFFF])
	{ }

	globalHandle(void* p)
		: _handle(p)
	{ }

	globalHandle(const globalHandle& copy)
		: _handle(copy._handle)
	{ }

	globalHandle At(int index)
	{
		return globalHandle(reinterpret_cast<void**>(this->_handle) + (index));
	}

	globalHandle At(int index, int size)
	{
		// Position 0 = Array Size
		return this->At(1 + (index * size));
	}

	globalHandle Add(int offset)
	{
		return globalHandle(reinterpret_cast<void**>(this->_handle) + (offset));
	}


	template <typename T>
	T* Get()
	{
		return reinterpret_cast<T*>(this->_handle);
	}

	template <typename T>
	T& As()
	{
		return *this->Get<T>();
	}
};

class ScriptGlobal
{
public:
	constexpr explicit ScriptGlobal(std::size_t index) :
		m_Index(index)
	{}

	constexpr ScriptGlobal Add(std::size_t index)
	{
		return ScriptGlobal(m_Index + index);
	}

	constexpr ScriptGlobal Add(std::size_t index, std::size_t x)
	{
		return Add(1 + (index * x));
	}

	template <typename T>
	std::enable_if_t<std::is_pointer<T>::value, T> As() const
	{
		return reinterpret_cast<T>(IndexToPtr(m_Index));
	}

	template <typename T>
	std::enable_if_t<std::is_lvalue_reference<T>::value, T> As() const
	{
		return *reinterpret_cast<std::add_pointer_t<std::remove_reference_t<T>>>(IndexToPtr(m_Index));
	}

	template <typename T>
	std::enable_if_t<std::is_same<T, std::uintptr_t>::value, T> As() const
	{
		return reinterpret_cast<std::uintptr_t>(As<void*>());
	}
private:
	static void* IndexToPtr(std::size_t index)
	{
		/*g_GameVariables->m_GlobalBase = reinterpret_cast<std::uint64_t**>(hook_sender::baseGlobal);*/
		return (g_GameVariables->m_GlobalBase[index >> 0x12 & 0x3F]) + (index & 0x3FFFF);
		//return (GameFunctions::GlobalBase[index >> 0x12 & 0x3F]) + (index & 0x3FFFF);
	}

	std::uintptr_t m_Index;
};
enum eRemoteEvent/* : int32_t*/
{
	ceomoney30k = -337848027,
	putonbike = 879177392,
	marchandisespecial = -157970864,
	//first50k = 429482368, //697566862
	//second50k = -1178821498, //1046014587
	//helicospawn = 1131623211,
	//giverp = -2136917450,//SD_TIC_CMPLT func_20581 under
	first50k = -347033775, //697566862 //func SD_HT_CMPLT
	second50k = -1235428989, //1046014587 //reh_prop_reh_bag_para_01a
	helicospawn = -375628860, //am_island_backup_heli
	giverp = 1916113629, //func under SD_TIC_CMPLT
	/*freezespawn = -1796714618,*/
	freezespawn = -1253241415, //func under am_mp_smpl_interior_int
	/*tbsgive = -1872286655,
	yatchinv = 360735385,
	appinv = 36077543,*/
	/*StartScriptBegin = -95341040,
	StartScriptProceed = 1742713914,*/
	StartScriptBegin = -366707054,
	StartScriptProceed = 1757622014,
	milliondrop = -353514253,//1279059857
	//NetworkBail = 915462795, // NETWORK::NETWORK_BAIL(16, 0, 0); xref func
	//NetworkBail = 1017995959, // NETWORK::NETWORK_BAIL(16, 0, 0); xref func
	NetworkBail = -901348601, // NETWORK::NETWORK_BAIL(16, 0, 0); xref func
	CeoKick2 = 265836764,
	//MarkPlayerAsBeast = -2001677186, // GB_BOSSBST xref == PLAYER... global (sadly doesn't actually turn people into the beast)
	MarkPlayerAsBeast = 1649541577, // GB_BOSSBST xref == PLAYER... global (sadly doesn't actually turn people into the beast)
	//Spectate = -1903870031, // SPEC_TCK1
	eSpectate = 1840946429,  // SPEC_TCK1
	//KickFromInterior = 1454834612, //-1549662639, // ENTITY::SET_ENTITY_HEALTH(PLAYER::PLAYER_PED_ID(), PED::GET_PED_MAX_HEALTH(PLAYER::PLAYER_PED_ID()), false)
	/*KickFromInterior = 786522321,*/
	KickFromInterior = -1496371358,
	//InteriorControl = 1268038438, // eventData.f_3 != _INVALID_PLAYER_INDEX_0()
	//CEO_BAN = 316066012,//joaat("mpply_vipgameplaydisabledtimer")
	//CEO_KICK = -1831959078,//GBTER_BIG
	//NOTIFICATION = 548471420,
	//SEND_TO_MISSION_1 = -1578682814,//TICK_PH_INV
	//SEND_TO_MISSION_2 = 1858712297,//FMMC_PLYLOAD
	//TELEPORT_APARTMENT = -168599209, //Mission_Pass_Notify
	//PHONE_INVITE = -1891171016, //CELL_APTINVYACHT
	//TRANSACTION_ERROR = -492741651,//PIM_TIGC
	//ROTATE_CAM = 113023613,
	//PHONE_NOTIFICATION_1 = -382461133,//TICK_BC_ON
	//PHONE_NOTIFICATION_2 = -923087411, //TICK_BC_OFF
	//SPECTATE_MESSAGE = -2131157870, //SPEC_TCK1
	//CLEAR_WANTED = 2080651008, //PLYVEH_INS_DES v
	//BRIBE_AUTHORITY = -2095232746, //GB_BCUT_TICK0 v
	//OFF_RADAR = -162943635, //PLYVEH_INS_DES vl
	//TELEPORT_CAYO = -910497748, //CELL_HI_INV
	//VEHICLE_KICK = -852914485, //PIM_RFMOC /PIM_RFAVE/PIM_EMVTK
	//VehicleKick = -1603050746, // PIM_RFMOC
	//FAKE_MONEY = 548471420, //TICK_ATTVAN / R2P_ACCT / R2P_JOINT
	//FAKE_REMOVE = -1197151915, //TICK_TC_REMO
	//FAKE_BANKED = -1032040118, //TICK_TC_BANK
	//FAKE_STEAL = -28878294, //TICK_TC_STOL
	//BAIL_NETWORK = 1228916411,
	//SEND_TO_LOCATION = 1463943751,
	////fm_mission_controller and fm_mission_controller_2020 begin
	//TAKE_PASIFIC = -498982787,
	//TAKE_CASINO = -2119274437,
	TAKE_CAYO = 665841803, //-1264900797,//1073952270
	////end
	//KICK_1 = 608596116, //iVar0 = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), &uVar1);
	//KICK_2 = 1980827733, //(SCRIPT::_GET_NUMBER_OF_REFERENCES_OF_SCRIPT_WITH_NAME_HASH(joaat("am_mp_drone")) < 1) v2
	//KICK_3 = 1789363239, //if (Var0.f_3 != -1 && Var0.f_2 != func_
	//KICK_4 = 1279400152, // || Var0.f_1 == PLAYER::PLAYER_ID())
	//KICK_5 = 765043249, //(Var0.f_3, Var0.f_1, Var0.f_2, Var0.f_5);
	//KICK_6 = -1118275782,
	//KICK_7 = -1409079442,
	//KICK_8 = -1287840401,
	//KICK_9 = -1629692602,
	//KICK_10 = -1759853392,
	//KICK_11 = -2008929105,
	//KICK_12 = 547083265,
	//KICK_13 = -869583434,
	//KICK_14 = -959229116,
	//KICK_15 = 360408846,
	//KICK_16 = 1280542040,
	//KICK_17 = 1488038476,
	//KICK_18 = -539605978,
	//KICK_19 = 385584794,
	//KICK_20 = 601184540,
	//KICK_21 = -1858744609,
	//KICK_22 = -2056857136,
	//KICK_23 = 1789363239,
	//KICK_24 = -1544474774,
	//KICK_25 = 1810531023,
	//KICK_26 = -508465573,
	//KICK_27 = 1456052554,
	//KICK_28 = 1408207199,
	//KICK_29 = -1663428414,
	//KICK_30 = 1336398417,
	//KICK_31 = -442434037,
	//KICK_32 = -795380017,
	//KICK_33 = -709054397, //[iVar7] = Var0.f_2[iVar7];	
	//KICK_34 = 841020275,
	//KICK_35 = -398684455,
	//KICK_36 = -1247985006, //Var0.f_2.f_3[iVar40] = uParam0->f_3[iVar40];
	//KICK_37 = -468188833, //Var11.f_2 = Var1.f_2;
	//KICK_38 = -805921310, //Var0.f_3 = { *iParam2 };
	//KICK_39 = 2119903152, //Var0.f_2[iVar14] = (*iParam1)[iVar14];
	//KICK_40 = 1781594056,
	//KICK_41 = -66669983,
	//KICK_42 = -1501830047,
	//KICK_43 = -634789188, //(Var0.f_2, 212, "", func_
	//KICK_44 = 1983907072,
	//KICK_45 = 1268038438,
	//KICK_46 = 1648747828,
	//KICK_47 = -1733737974,
	//KICK_48 = 1434390292,
	//KICK_49 = 1789200508,
	//KICK_50 = 209861916,
	//KICK_51 = 813647057,
	//KICK_52 = 1992522613,
	//KICK_53 = 548471420,
	//KICK_54 = 495813132, //(Var0.f_2, Var0.f_5, Var0.f_6, Var0.f_1, 0, 0))
	//KICK_55 = -904555865, //if (NETWORK::NETWORK_HASH_FROM_PLAYER_HANDLE(PLAYER::PLAYER_ID()) == Var0.f_3[iVar10])
	//KICK_56 = 879177392, //if (NETWORK::NETWORK_HASH_FROM_PLAYER_HANDLE(PLAYER::PLAYER_ID()) == Var0.f_3[iVar37])
	//KICK_57 = 463008662, //(Var0.f_3)]), func_
	//KICK_58 = -1919386801,
	//KICK_59 = -442434037,
	//KICK_60 = 2065947370, //if (iVar1 > 0 && iVar1 <= 10)
	//KICK_61 = -1783216053,
	//Unknown1 = 1336398417, // (iVar4 - Var0.f_3);
	//Unknown2 = 80875492, // [Var0.f_2] = Var0.f_3;
	//Unknown3 = 1992522613,
	//Unknown4 = 1781594056, //if ((((((BitTest(uParam1->f_33, 1) && BitTest(uParam0->f_64, uParam1->f_34)) && !BitTest(uParam0->f_62, uParam1->f_34))
	//Unknown5 = -66669983, // ^ sama kyk atas 
	//Unknown6 = -1544474774,
	//SEC3 = -1539131577,
	//SEC6 = -2093023277,
	//SEC7 = 1192608757,
	//SEC8 = 1124104301,
	//SEC9 = 495813132,
	//SEC10 = 1810531023,
	//SEC11 = -508465573,
	//SEC12 = 1789363239,
	//SEC13 = -803535423,
	//Spaghettios = 1775863255,
	//SHKick = 1037001637,
	/*Bounty = 1459520933,*/
	Bounty = 1517551547, //above policeold2
	//Bounty = 1294995624, // (137, "FM_TXT_BNTY0", iVar1, PLAYER::GET_PLAYER_NAME(Var2.f_1), "", 5000, Var2.f_6);
	//CeoBan = 316066012, //1.61
	//CeoKick = -1831959078, //1.61
	//CeoMoney = 547083265, //1.61
	//ClearWantedLevel = 2080651008, //1.61
	//FakeDeposit = 548471420, //1.61
	//ForceMission = 1858712297, //1.61
	//ForceMission2 = -1578682814,
	//GtaBanner = -795380017, //1.61 //1572255940 1.60
	//PersonalVehicleDestroyed = -964882004, //1.61
	//RemoteOffradar = -162943635, //1.61
	//RotateCam = 113023613, //1.61
	//SendToCutscene = 392606458, //1.61
	//SendToIsland = -910497748, //1.61
	//SoundSpam = -1891171016, //1.61
	//Spectate = -2131157870, //1.61
	//SendToApartment = -168599209, //1.61
	//TransactionError = -492741651, //1.61
	//Crash = -904555865, //1.61
	//Crash2 = 879177392, //1.61
	//Crash3 = 1192608757, //1.61
	//Crash4 = 1124104301, //1.61
	//Kick1 = 1810531023, //1.61
	//Kick2 = -508465573, //1.61
	//NetworkBail = 915462795, //1.61
	//SendAndFreeze = -93722397, //1.61
	//Bribe = -2095232746, //1.61
	//Ghost = -162943635, //1.61
	//GiveCollectible = -1178972880, // DLC_SUM20_HIDDEN_COLLECTIBLES xref
	//SendToCayoPerico = -910497748, // CELL_HI_INV
	//SendToLocation = -93722397, // &Var222, 11);
	//TeleportToWarehouse = 434937615, // CAM::FORCE_CINEMATIC_RENDERING_THIS_UPDATE(true) xref counter
	//VehicleKick = -852914485, // PIM_RFMOC
	//Kick = 915462795,
	//ChangeMCRole = 656530441, // _PLAYSTATS_CHANGE_MC_ROLE
	//DisableRecording = 867047895, // GET_FINAL_RENDERED_CAM_COORD
	//MCTeleport = 879177392, // NETWORK::NETWORK_HASH_FROM_PLAYER_HANDLE(PLAYER::PLAYER_ID()) == (first one)
	//StartActivity = 243072129, // (Var0.f_2, -1); first match
	//MarkPlayerAsBeast = -490124271, // GB_BOSSBST xref == PLAYER... global (sadly doesn't actually turn people into the beast)
	//Crash5 = 1775863255,
	//TSECommand = 113023613, // CnCTG_IN_BF
	//TSECommandRotateCam = -1762807505, // != 29) && f
	//Notification0 = 548471420,
	//NotificationMoneyBanked = -1032040118, // TICK_TC_BANK
	//NotificationMoneyRemoved = -1197151915, // TICK_TC_REMO
	//NotificationMoneyStolen = -28878294 // TICK_TC_STOL
		//Main = 1853910,//1853131
		//Character = 1574918,//Global_1574918
	Character = 1574926,//Global_1574925//
	TransitionState = 1575011,//Global_1575008
	//TransitionState = 1574993,//Global_1574991
	//SHKick = 518811989,//1037001637

	////Kick1 = 1810531023,//2071375245
	////Kick2 = -398684455,//-1373106115
	////Kick3 = 2119903152,//1672674814
	////Kick4 = -508465573,//-1991423686
	////Kick5 = 1456052554,//523052032
	////Kick6 = -468188833,//-35026843
	////Kick7 = -805921310,//-320008018

	////Crash1 = -904555865,//526822748
	////Crash2 = 1192608757,//-637352381
	////Crash3 = 1124104301,//-51486976
	////Crash4 = 1775863255,//1348481963
	////InteriorState = -957260626,//2956049686
	////ScriptFreeze = -93722397,//1214823473
	////ScreenBanner = 1751618454,//-1435009097
	////Inssurance = -964882004,//-1838276770
	////VehicleKick = -852914485,//-714268990
	////SoundSpam = -1891171016,//1111927333
	////JoinedActivity = -1578682814,//-1908874529
	////ClearWantedLevel = 2080651008,//1449852136
	////OffTheRadar = -162943635,//-1973627888
	////NetworkKick = 915462795,//1674887089
	////Collectibles = 697566862,//-1178972880
	////MoneyEvent_1 = -1237225255,//-148426250 
	////MoneyEvent_2 = 549145155,//-1013989798 
	////RPEvent = 1046014587,//-1959124989
	////StartActivity = 243072129,//1368055548
	////SendToLocation = -93722397,//-93722397
	////BountyEvent = 1370461707,//1915499503
	////BountyTransaction = 1923597,//Global_1920255
	////SendToJob = 1858712297,//-283041276
	////SendToIsland = -910497748,//1361475530
	////SendToApartment = -168599209,//-1390976345
	////CEOBan = 316066012,//1240068495
	////CEOKick = -1831959078,//-1425016400
	////TransactionError = -492741651,//-768108950
	////SendToCutscene = 392606458,//2131601101
	////MCTeleport = 879177392,//-555356783
	////GtaBanner = -795380017,//145637109
	////Mugger = 532932991,//-1296682161
	////Checkpoint = 1757484042,//238216506 
	////ATMMoney = -1082301749,//-1173679408
	////MoneyDropped = 414496857,//954790247
	//InteriorControl = 1268038438,//111242367
	//InteriorControl = 1727896103,
	InteriorControl = -1638522928, // eventData.f_3 != _INVALID_PLAYER_INDEX_0()
	////DestroyVehicle = -513394492,//-2126830022
	////TSECommand = 113023613,//-1388926377
	////TSECommandRotateCam = -1762807505,//-1762807505 ??? pats_horse_right

	////Notification = 548471420,//-1529596656
	////NotificationMoneyBanked = -1032040118,//-849958015
	////NotificationMoneyRemoved = -1197151915,//-290070531
	////NotificationMoneyStolen = -28878294,//-1640162684

	////TeleportToWarehouse = 434937615//2130458390

	SHKick = -78445431,

	//Kick_1 = 1938530224,//1810531023 //oppressor2 7func above
	Kick_1 = -353458099,//1810531023 //bas de la page freemode recherche par en haut oppressor2 case of 7func above
	//Kick_2 = -1880259633,//-398684455 // Previous_Boss -1140090124
	Kick_2 = -1140090124,//-398684455 //bas de la page freemode recherche par en haut Previous_Boss case of 6func under
	//Kick_3 = -516949273,//2119903152 //oppressor2 case of 8func above 
	Kick_3 = -1713699293,//2119903152 //oppressor2 case of 8func above
	//Kick_4 = 1418092950,//-508465573 //oppressor2 case of 6func above
	Kick_4 = -1101672680,//-508465573 //oppressor2 case of 6func above 
	//Kick_5 = -1906333887,//1456052554 
	Kick_5 = -1544003568,//1456052554 //du bas du freemode 2 fois PLYVEH_INS_DES1 case of 4func above or 2time AM_MP_HANGAR du haut du freemode et func under 
	//Kick_6 = 1037271047,//-468188833 // du bas du freemode 2times AM_MP_SMPL_INTERIOR_EXT case of 19func above 
	Kick_6 = 1982477645,//-468188833 // du bas du freemode 2times AM_MP_SMPL_INTERIOR_EXT case of 19func above 
	//Kick_7 = -866893497,//-805921310 // du bas du freemode 2times AM_MP_SMPL_INTERIOR_EXT case 16func above 
	Kick_7 = 623462469,//-805921310 // du bas du freemode 2times AM_MP_SMPL_INTERIOR_EXT case 16func above 
	//Crash1 = -992162568,//-904555865
	//Crash2 = 39108873,//1192608757
	//Crash3 = -373650836,//1124104301
	//Crash4 = 1131623211,//1775863255 // du bas du freemode recherche par en haut FMCI_CHCKPNT_D case of 14func above

	Crash1 = -1604421397, // SET_NO_LOADING_SCREEN, xref it
	Crash2 = -375628860,
	Crash3 = 323285304,
	Crash4 = -375628860,//1775863255 // du bas du freemode recherche par en haut FMCI_CHCKPNT_D case of 14func above 

	ScriptFreeze2 = 1669592503,//330622597//-93722397 //FMCI_CHCKPNT_D 13 function above



	ScreenBanner = -767364034,//1751618454
	Inssurance = -642631978,//-964882004
	//VehicleKick = -1603050746,//-852914485
	VehicleKick = -503325966,  // PIM_RFMOC
	//SoundSpam = 36077543,//-1891171016
	eSoundSpam = 996099702,   // CELL_APTINVYACHT
	JoinedActivity = -647821994,//-1578682814
	//ClearWantedLevel = 1743540940,//2080651008
	ClearWantedLevel = -1704545346,
	//OffTheRadar = 1141648445,//-162943635
	Sudoyer = -305178342,//-162943635
	OffTheRadar = 57493695,    // NETWORK::GET_TIME_DIFFERENCE(NETWORK::GET_NETWORK_TIME(), Var0.f_2)
	NetworkKick = 1017995959,//915462795
	//Peyotl = 1839167950,//697566862
	MoneyEvent_1 = -1178821498,//-1237225255
	MoneyEvent_2 = 429482368,//549145155
	RPEvent = -2136917450,//1046014587
	//StartActivity = 1104117595,//243072129
	StartActivity = 1450115979, // (Var0.f_2, -1); first match
	//SendToLocation = 330622597,//-93722397
	SendToLocation = 1669592503,//-93722397 //case above FMCI_CHCKPNT_D
	//SendToLocation = 1669592503,  // &Var222, 11);
	//BountyEvent = 1459520933,//1370461707
	BountyEvent = 1517551547,//1370461707
	//BountyTransaction = 1923597,//1923597
	BountyTransaction = 1916617,//1916087 //1924276,//1923597	//SCRIPT_TASK_LEAVE_ANY_VEHICLE	
	//SendToJob = -2138393348,//1858712297 //func above FMMC_PLYLOAD
	SendToJob2 = 259469385,//1858712297 //func above FMMC_PLYLOAD
	//SendToIsland = 369672308,//-910497748 //HAND_SHAKE
	SendToIsland = 373376135,//-910497748 //HAND_SHAKE
	//SendToCayoPerico = 373376135,   // CELL_HI_INV
	//SendToApartment = -702866045,//-168599209
	SendToApartment = -1321657966,//-168599209 //under FM_DEL_UNS_4 //if (flag && flag2 && !flag3 && !flag4)
	//Teleport = -1321657966, // Mission_Pass_Notify
	//CEOBan = 1517094008,//316066012
	//CEOKick = 59823848,//-1831959078

	//CEOBan = 1517094008, // mpply_vipgameplaydisabledtimer
	//CEOKick = 1421455565,
	eCEOBan = 1531565154, // mpply_vipgameplaydisabledtimer
	eCEOKick = -11681548,

	//CeoMoney = 75579707, // func Goon_Paid_Large
	CeoMoney = -337848027, // func Goon_Paid_Large

	//TransactionError = 54323524,//-492741651 //func PIM_TIGC
	TransactionError = -830063381,//-492741651 //func PIM_TIGC
	//SendToCutscene = 2139870214,//392606458
	SendToCutscene = -1951335381, // (bVar3, bVar4, 125f, 1)
	//MCTeleport = 891653640,//879177392 //under RandomID 
	MCTeleport = 1103127469,//879177392 //RandomID 
	//MCTeleport = 1103127469, // NETWORK::NETWORK_HASH_FROM_PLAYER_HANDLE(PLAYER::PLAYER_ID()) == (first one)

	//GtaBanner = 2114252738,//-795380017
	GtaBanner = -330501227, // NETWORK::NETWORK_IS_SCRIPT_ACTIVE("BUSINESS_BATTLES", -1, true, 0) second one

	//TSECommand = -1428749433, //113023613
	//TSECommand = 113023613, // CnCTG_IN_BF
	//TSECommandRotateCam = -1762807505, //-1762807505

	TSECommand = 800157557, // CnCTG_IN_BF
	TSECommandRotateCam = 225624744, // != 29) && f

	DestroyPersonalVehicle = -2101545224, // CnC_PV_THEFT
	TriggerCEORaid = -1388385133,

	//Notification = 2041805809,//548471420
	//NotificationMoneyBanked = 276906331,//-1032040118
	//NotificationMoneyRemoved = 853249803,//-1197151915
	//NotificationMoneyStolen = 82080686,//-28878294
	Notification = -642704387,
	NotificationMoneyBanked = 94410750,   // TICK_TC_BANK
	NotificationMoneyRemoved = -242911964, // TICK_TC_REMO
	NotificationMoneyStolen = -295926414, // TICK_TC_STOL
	//GiveCollectible = 1839167950, // DLC_SUM20_HIDDEN_COLLECTIBLES xref
	GiveCollectible = 968269233, // DLC_SUM20_HIDDEN_COLLECTIBLES xref
	LesterAnim = -1951335381,
	TurbulencesAgent14 = 259469385,
	/*Coffres = 968269233,*/
//TeleportToWarehouse = -1796714618//434937615 //PYV_WarpFrom
TeleportToWarehouse = -1253241415//434937615 //PYV_WarpFrom
//TeleportToWarehouse = -1253241415, // .f_4 == 50

//////////
//PersonalVehicleDestroyed = 1655503526,  // PLYVEH_INS_DES1
//RemoteOffradar = 57493695,    // NETWORK::GET_TIME_DIFFERENCE(NETWORK::GET_NETWORK_TIME(), Var0.f_2)
//TransactionError = -830063381,  // NETWORK_RECEIVE_PLAYER_JOBSHARE_CASH

	//DestroyPersonalVehicle = 109434679, // CnC_PV_THEFT
	//TriggerCEORaid = -1906536929,

};

//enum eRemoteEvent/* : int32_t*/
//{
//	ceomoney30k = -337848027,
//	putonbike = 879177392,
//	marchandisespecial = -157970864,
//	//first50k = 429482368, //697566862
//	//second50k = -1178821498, //1046014587
//	//helicospawn = 1131623211,
//	//giverp = -2136917450,//SD_TIC_CMPLT func_20581 under
//	first50k = -347033775, //697566862 //func SD_HT_CMPLT
//	second50k = -1235428989, //1046014587 //reh_prop_reh_bag_para_01a
//	helicospawn = -375628860, //am_island_backup_heli
//	giverp = 1916113629, //func under SD_TIC_CMPLT
//	/*freezespawn = -1796714618,*/
//	freezespawn = -1253241415, //func under am_mp_smpl_interior_int
//	/*tbsgive = -1872286655,
//	yatchinv = 360735385,
//	appinv = 36077543,*/
//	/*StartScriptBegin = -95341040,
//	StartScriptProceed = 1742713914,*/
//	StartScriptBegin = -366707054,
//	StartScriptProceed = 1757622014,
//	milliondrop = -353514253,//1279059857
//	//NetworkBail = 915462795, // NETWORK::NETWORK_BAIL(16, 0, 0); xref func
//	//NetworkBail = 1017995959, // NETWORK::NETWORK_BAIL(16, 0, 0); xref func
//	NetworkBail = -901348601, // NETWORK::NETWORK_BAIL(16, 0, 0); xref func
//	CeoKick2 = 265836764,
//	//MarkPlayerAsBeast = -2001677186, // GB_BOSSBST xref == PLAYER... global (sadly doesn't actually turn people into the beast)
//	MarkPlayerAsBeast = 1649541577, // GB_BOSSBST xref == PLAYER... global (sadly doesn't actually turn people into the beast)
//	//Spectate = -1903870031, // SPEC_TCK1
//	eSpectate = 1840946429,  // SPEC_TCK1
//	//KickFromInterior = 1454834612, //-1549662639, // ENTITY::SET_ENTITY_HEALTH(PLAYER::PLAYER_PED_ID(), PED::GET_PED_MAX_HEALTH(PLAYER::PLAYER_PED_ID()), false)
//	/*KickFromInterior = 786522321,*/
//	KickFromInterior = -1496371358,
//	//InteriorControl = 1268038438, // eventData.f_3 != _INVALID_PLAYER_INDEX_0()
//	//CEO_BAN = 316066012,//joaat("mpply_vipgameplaydisabledtimer")
//	//CEO_KICK = -1831959078,//GBTER_BIG
//	//NOTIFICATION = 548471420,
//	//SEND_TO_MISSION_1 = -1578682814,//TICK_PH_INV
//	//SEND_TO_MISSION_2 = 1858712297,//FMMC_PLYLOAD
//	//TELEPORT_APARTMENT = -168599209, //Mission_Pass_Notify
//	//PHONE_INVITE = -1891171016, //CELL_APTINVYACHT
//	//TRANSACTION_ERROR = -492741651,//PIM_TIGC
//	//ROTATE_CAM = 113023613,
//	//PHONE_NOTIFICATION_1 = -382461133,//TICK_BC_ON
//	//PHONE_NOTIFICATION_2 = -923087411, //TICK_BC_OFF
//	//SPECTATE_MESSAGE = -2131157870, //SPEC_TCK1
//	//CLEAR_WANTED = 2080651008, //PLYVEH_INS_DES v
//	//BRIBE_AUTHORITY = -2095232746, //GB_BCUT_TICK0 v
//	//OFF_RADAR = -162943635, //PLYVEH_INS_DES vl
//	//TELEPORT_CAYO = -910497748, //CELL_HI_INV
//	//VEHICLE_KICK = -852914485, //PIM_RFMOC /PIM_RFAVE/PIM_EMVTK
//	//VehicleKick = -1603050746, // PIM_RFMOC
//	//FAKE_MONEY = 548471420, //TICK_ATTVAN / R2P_ACCT / R2P_JOINT
//	//FAKE_REMOVE = -1197151915, //TICK_TC_REMO
//	//FAKE_BANKED = -1032040118, //TICK_TC_BANK
//	//FAKE_STEAL = -28878294, //TICK_TC_STOL
//	//BAIL_NETWORK = 1228916411,
//	//SEND_TO_LOCATION = 1463943751,
//	////fm_mission_controller and fm_mission_controller_2020 begin
//	//TAKE_PASIFIC = -498982787,
//	//TAKE_CASINO = -2119274437,
//	TAKE_CAYO = 665841803, //-1264900797,//1073952270
//	////end
//	//KICK_1 = 608596116, //iVar0 = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), &uVar1);
//	//KICK_2 = 1980827733, //(SCRIPT::_GET_NUMBER_OF_REFERENCES_OF_SCRIPT_WITH_NAME_HASH(joaat("am_mp_drone")) < 1) v2
//	//KICK_3 = 1789363239, //if (Var0.f_3 != -1 && Var0.f_2 != func_
//	//KICK_4 = 1279400152, // || Var0.f_1 == PLAYER::PLAYER_ID())
//	//KICK_5 = 765043249, //(Var0.f_3, Var0.f_1, Var0.f_2, Var0.f_5);
//	//KICK_6 = -1118275782,
//	//KICK_7 = -1409079442,
//	//KICK_8 = -1287840401,
//	//KICK_9 = -1629692602,
//	//KICK_10 = -1759853392,
//	//KICK_11 = -2008929105,
//	//KICK_12 = 547083265,
//	//KICK_13 = -869583434,
//	//KICK_14 = -959229116,
//	//KICK_15 = 360408846,
//	//KICK_16 = 1280542040,
//	//KICK_17 = 1488038476,
//	//KICK_18 = -539605978,
//	//KICK_19 = 385584794,
//	//KICK_20 = 601184540,
//	//KICK_21 = -1858744609,
//	//KICK_22 = -2056857136,
//	//KICK_23 = 1789363239,
//	//KICK_24 = -1544474774,
//	//KICK_25 = 1810531023,
//	//KICK_26 = -508465573,
//	//KICK_27 = 1456052554,
//	//KICK_28 = 1408207199,
//	//KICK_29 = -1663428414,
//	//KICK_30 = 1336398417,
//	//KICK_31 = -442434037,
//	//KICK_32 = -795380017,
//	//KICK_33 = -709054397, //[iVar7] = Var0.f_2[iVar7];	
//	//KICK_34 = 841020275,
//	//KICK_35 = -398684455,
//	//KICK_36 = -1247985006, //Var0.f_2.f_3[iVar40] = uParam0->f_3[iVar40];
//	//KICK_37 = -468188833, //Var11.f_2 = Var1.f_2;
//	//KICK_38 = -805921310, //Var0.f_3 = { *iParam2 };
//	//KICK_39 = 2119903152, //Var0.f_2[iVar14] = (*iParam1)[iVar14];
//	//KICK_40 = 1781594056,
//	//KICK_41 = -66669983,
//	//KICK_42 = -1501830047,
//	//KICK_43 = -634789188, //(Var0.f_2, 212, "", func_
//	//KICK_44 = 1983907072,
//	//KICK_45 = 1268038438,
//	//KICK_46 = 1648747828,
//	//KICK_47 = -1733737974,
//	//KICK_48 = 1434390292,
//	//KICK_49 = 1789200508,
//	//KICK_50 = 209861916,
//	//KICK_51 = 813647057,
//	//KICK_52 = 1992522613,
//	//KICK_53 = 548471420,
//	//KICK_54 = 495813132, //(Var0.f_2, Var0.f_5, Var0.f_6, Var0.f_1, 0, 0))
//	//KICK_55 = -904555865, //if (NETWORK::NETWORK_HASH_FROM_PLAYER_HANDLE(PLAYER::PLAYER_ID()) == Var0.f_3[iVar10])
//	//KICK_56 = 879177392, //if (NETWORK::NETWORK_HASH_FROM_PLAYER_HANDLE(PLAYER::PLAYER_ID()) == Var0.f_3[iVar37])
//	//KICK_57 = 463008662, //(Var0.f_3)]), func_
//	//KICK_58 = -1919386801,
//	//KICK_59 = -442434037,
//	//KICK_60 = 2065947370, //if (iVar1 > 0 && iVar1 <= 10)
//	//KICK_61 = -1783216053,
//	//Unknown1 = 1336398417, // (iVar4 - Var0.f_3);
//	//Unknown2 = 80875492, // [Var0.f_2] = Var0.f_3;
//	//Unknown3 = 1992522613,
//	//Unknown4 = 1781594056, //if ((((((BitTest(uParam1->f_33, 1) && BitTest(uParam0->f_64, uParam1->f_34)) && !BitTest(uParam0->f_62, uParam1->f_34))
//	//Unknown5 = -66669983, // ^ sama kyk atas 
//	//Unknown6 = -1544474774,
//	//SEC3 = -1539131577,
//	//SEC6 = -2093023277,
//	//SEC7 = 1192608757,
//	//SEC8 = 1124104301,
//	//SEC9 = 495813132,
//	//SEC10 = 1810531023,
//	//SEC11 = -508465573,
//	//SEC12 = 1789363239,
//	//SEC13 = -803535423,
//	//Spaghettios = 1775863255,
//	//SHKick = 1037001637,
//	/*Bounty = 1459520933,*/
//	Bounty = 1517551547, //above policeold2
//	//Bounty = 1294995624, // (137, "FM_TXT_BNTY0", iVar1, PLAYER::GET_PLAYER_NAME(Var2.f_1), "", 5000, Var2.f_6);
//	//CeoBan = 316066012, //1.61
//	//CeoKick = -1831959078, //1.61
//	//CeoMoney = 547083265, //1.61
//	//ClearWantedLevel = 2080651008, //1.61
//	//FakeDeposit = 548471420, //1.61
//	//ForceMission = 1858712297, //1.61
//	//ForceMission2 = -1578682814,
//	//GtaBanner = -795380017, //1.61 //1572255940 1.60
//	//PersonalVehicleDestroyed = -964882004, //1.61
//	//RemoteOffradar = -162943635, //1.61
//	//RotateCam = 113023613, //1.61
//	//SendToCutscene = 392606458, //1.61
//	//SendToIsland = -910497748, //1.61
//	//SoundSpam = -1891171016, //1.61
//	//Spectate = -2131157870, //1.61
//	//SendToApartment = -168599209, //1.61
//	//TransactionError = -492741651, //1.61
//	//Crash = -904555865, //1.61
//	//Crash2 = 879177392, //1.61
//	//Crash3 = 1192608757, //1.61
//	//Crash4 = 1124104301, //1.61
//	//Kick1 = 1810531023, //1.61
//	//Kick2 = -508465573, //1.61
//	//NetworkBail = 915462795, //1.61
//	//SendAndFreeze = -93722397, //1.61
//	//Bribe = -2095232746, //1.61
//	//Ghost = -162943635, //1.61
//	//GiveCollectible = -1178972880, // DLC_SUM20_HIDDEN_COLLECTIBLES xref
//	//SendToCayoPerico = -910497748, // CELL_HI_INV
//	//SendToLocation = -93722397, // &Var222, 11);
//	//TeleportToWarehouse = 434937615, // CAM::FORCE_CINEMATIC_RENDERING_THIS_UPDATE(true) xref counter
//	//VehicleKick = -852914485, // PIM_RFMOC
//	//Kick = 915462795,
//	//ChangeMCRole = 656530441, // _PLAYSTATS_CHANGE_MC_ROLE
//	//DisableRecording = 867047895, // GET_FINAL_RENDERED_CAM_COORD
//	//MCTeleport = 879177392, // NETWORK::NETWORK_HASH_FROM_PLAYER_HANDLE(PLAYER::PLAYER_ID()) == (first one)
//	//StartActivity = 243072129, // (Var0.f_2, -1); first match
//	//MarkPlayerAsBeast = -490124271, // GB_BOSSBST xref == PLAYER... global (sadly doesn't actually turn people into the beast)
//	//Crash5 = 1775863255,
//	//TSECommand = 113023613, // CnCTG_IN_BF
//	//TSECommandRotateCam = -1762807505, // != 29) && f
//	//Notification0 = 548471420,
//	//NotificationMoneyBanked = -1032040118, // TICK_TC_BANK
//	//NotificationMoneyRemoved = -1197151915, // TICK_TC_REMO
//	//NotificationMoneyStolen = -28878294 // TICK_TC_STOL
//		//Main = 1853910,//1853131
//	Character = 1574918,//Global_1574918
//	//TransitionState = 1574993,//Global_1574991
//	//SHKick = 518811989,//1037001637
//
//	////Kick1 = 1810531023,//2071375245
//	////Kick2 = -398684455,//-1373106115
//	////Kick3 = 2119903152,//1672674814
//	////Kick4 = -508465573,//-1991423686
//	////Kick5 = 1456052554,//523052032
//	////Kick6 = -468188833,//-35026843
//	////Kick7 = -805921310,//-320008018
//
//	////Crash1 = -904555865,//526822748
//	////Crash2 = 1192608757,//-637352381
//	////Crash3 = 1124104301,//-51486976
//	////Crash4 = 1775863255,//1348481963
//	////InteriorState = -957260626,//2956049686
//	////ScriptFreeze = -93722397,//1214823473
//	////ScreenBanner = 1751618454,//-1435009097
//	////Inssurance = -964882004,//-1838276770
//	////VehicleKick = -852914485,//-714268990
//	////SoundSpam = -1891171016,//1111927333
//	////JoinedActivity = -1578682814,//-1908874529
//	////ClearWantedLevel = 2080651008,//1449852136
//	////OffTheRadar = -162943635,//-1973627888
//	////NetworkKick = 915462795,//1674887089
//	////Collectibles = 697566862,//-1178972880
//	////MoneyEvent_1 = -1237225255,//-148426250 
//	////MoneyEvent_2 = 549145155,//-1013989798 
//	////RPEvent = 1046014587,//-1959124989
//	////StartActivity = 243072129,//1368055548
//	////SendToLocation = -93722397,//-93722397
//	////BountyEvent = 1370461707,//1915499503
//	////BountyTransaction = 1923597,//Global_1920255
//	////SendToJob = 1858712297,//-283041276
//	////SendToIsland = -910497748,//1361475530
//	////SendToApartment = -168599209,//-1390976345
//	////CEOBan = 316066012,//1240068495
//	////CEOKick = -1831959078,//-1425016400
//	////TransactionError = -492741651,//-768108950
//	////SendToCutscene = 392606458,//2131601101
//	////MCTeleport = 879177392,//-555356783
//	////GtaBanner = -795380017,//145637109
//	////Mugger = 532932991,//-1296682161
//	////Checkpoint = 1757484042,//238216506 
//	////ATMMoney = -1082301749,//-1173679408
//	////MoneyDropped = 414496857,//954790247
//	//InteriorControl = 1268038438,//111242367
//	//InteriorControl = 1727896103,
//	InteriorControl = -1638522928, // eventData.f_3 != _INVALID_PLAYER_INDEX_0()
//	////DestroyVehicle = -513394492,//-2126830022
//	////TSECommand = 113023613,//-1388926377
//	////TSECommandRotateCam = -1762807505,//-1762807505 ??? pats_horse_right
//
//	////Notification = 548471420,//-1529596656
//	////NotificationMoneyBanked = -1032040118,//-849958015
//	////NotificationMoneyRemoved = -1197151915,//-290070531
//	////NotificationMoneyStolen = -28878294,//-1640162684
//
//	////TeleportToWarehouse = 434937615//2130458390
//
//	SHKick = -78445431,
//
//	//Kick_1 = 1938530224,//1810531023 //oppressor2 7func above
//	Kick_1 = -353458099,//1810531023 //bas de la page freemode recherche par en haut oppressor2 case of 7func above
//	//Kick_2 = -1880259633,//-398684455 // Previous_Boss -1140090124
//	Kick_2 = -1140090124,//-398684455 //bas de la page freemode recherche par en haut Previous_Boss case of 6func under
//	//Kick_3 = -516949273,//2119903152 //oppressor2 case of 8func above 
//	Kick_3 = -1713699293,//2119903152 //oppressor2 case of 8func above
//	//Kick_4 = 1418092950,//-508465573 //oppressor2 case of 6func above
//	Kick_4 = -1101672680,//-508465573 //oppressor2 case of 6func above 
//	//Kick_5 = -1906333887,//1456052554 
//	Kick_5 = -1544003568,//1456052554 //du bas du freemode 2 fois PLYVEH_INS_DES1 case of 4func above or 2time AM_MP_HANGAR du haut du freemode et func under 
//	//Kick_6 = 1037271047,//-468188833 // du bas du freemode 2times AM_MP_SMPL_INTERIOR_EXT case of 19func above 
//	Kick_6 = 1982477645,//-468188833 // du bas du freemode 2times AM_MP_SMPL_INTERIOR_EXT case of 19func above 
//	//Kick_7 = -866893497,//-805921310 // du bas du freemode 2times AM_MP_SMPL_INTERIOR_EXT case 16func above 
//	Kick_7 = 623462469,//-805921310 // du bas du freemode 2times AM_MP_SMPL_INTERIOR_EXT case 16func above 
//	//Crash1 = -992162568,//-904555865
//	//Crash2 = 39108873,//1192608757
//	//Crash3 = -373650836,//1124104301
//	//Crash4 = 1131623211,//1775863255 // du bas du freemode recherche par en haut FMCI_CHCKPNT_D case of 14func above
//
//	Crash1 = -1604421397, // SET_NO_LOADING_SCREEN, xref it
//	Crash2 = -375628860,
//	Crash3 = 323285304,
//	Crash4 = -375628860,//1775863255 // du bas du freemode recherche par en haut FMCI_CHCKPNT_D case of 14func above 
//
//	ScriptFreeze2 = 1669592503,//330622597//-93722397 //FMCI_CHCKPNT_D 13 function above
//
//
//
//	ScreenBanner = -767364034,//1751618454
//	Inssurance = -642631978,//-964882004
//	//VehicleKick = -1603050746,//-852914485
//	VehicleKick = -503325966,  // PIM_RFMOC
//	//SoundSpam = 36077543,//-1891171016
//	eSoundSpam = 996099702,   // CELL_APTINVYACHT
//	JoinedActivity = -647821994,//-1578682814
//	//ClearWantedLevel = 1743540940,//2080651008
//	ClearWantedLevel = -1704545346,
//	//OffTheRadar = 1141648445,//-162943635
//	Sudoyer = -305178342,//-162943635
//	OffTheRadar = 57493695,    // NETWORK::GET_TIME_DIFFERENCE(NETWORK::GET_NETWORK_TIME(), Var0.f_2)
//	NetworkKick = 1017995959,//915462795
//	//Peyotl = 1839167950,//697566862
//	MoneyEvent_1 = -1178821498,//-1237225255
//	MoneyEvent_2 = 429482368,//549145155
//	RPEvent = -2136917450,//1046014587
//	//StartActivity = 1104117595,//243072129
//	StartActivity = 1450115979, // (Var0.f_2, -1); first match
//	//SendToLocation = 330622597,//-93722397
//	SendToLocation = 1669592503,//-93722397 //case above FMCI_CHCKPNT_D
//	//SendToLocation = 1669592503,  // &Var222, 11);
//	//BountyEvent = 1459520933,//1370461707
//	BountyEvent = 1517551547,//1370461707
//	//BountyTransaction = 1923597,//1923597
//	BountyTransaction = 1916087, //1924276,//1923597		
//	//SendToJob = -2138393348,//1858712297 //func above FMMC_PLYLOAD
//	SendToJob2 = 259469385,//1858712297 //func above FMMC_PLYLOAD
//	//SendToIsland = 369672308,//-910497748 //HAND_SHAKE
//	SendToIsland = 373376135,//-910497748 //HAND_SHAKE
//	//SendToCayoPerico = 373376135,   // CELL_HI_INV
//	//SendToApartment = -702866045,//-168599209
//	SendToApartment = -1321657966,//-168599209 //under FM_DEL_UNS_4 //if (flag && flag2 && !flag3 && !flag4)
//	//Teleport = -1321657966, // Mission_Pass_Notify
//	//CEOBan = 1517094008,//316066012
//	//CEOKick = 59823848,//-1831959078
//
//	//CEOBan = 1517094008, // mpply_vipgameplaydisabledtimer
//	//CEOKick = 1421455565,
//	eCEOBan = 1531565154, // mpply_vipgameplaydisabledtimer
//	eCEOKick = -11681548,
//
//	//CeoMoney = 75579707, // func Goon_Paid_Large
//	CeoMoney = -337848027, // func Goon_Paid_Large
//
//	//TransactionError = 54323524,//-492741651 //func PIM_TIGC
//	TransactionError = -830063381,//-492741651 //func PIM_TIGC
//	//SendToCutscene = 2139870214,//392606458
//	SendToCutscene = -1951335381, // (bVar3, bVar4, 125f, 1)
//	//MCTeleport = 891653640,//879177392 //under RandomID 
//	MCTeleport = 1103127469,//879177392 //RandomID 
//	//MCTeleport = 1103127469, // NETWORK::NETWORK_HASH_FROM_PLAYER_HANDLE(PLAYER::PLAYER_ID()) == (first one)
//
//	//GtaBanner = 2114252738,//-795380017
//	GtaBanner = -330501227, // NETWORK::NETWORK_IS_SCRIPT_ACTIVE("BUSINESS_BATTLES", -1, true, 0) second one
//
//	//TSECommand = -1428749433, //113023613
//	//TSECommand = 113023613, // CnCTG_IN_BF
//	//TSECommandRotateCam = -1762807505, //-1762807505
//
//	TSECommand = 800157557, // CnCTG_IN_BF
//	TSECommandRotateCam = 225624744, // != 29) && f
//
//	DestroyPersonalVehicle = -2101545224, // CnC_PV_THEFT
//	TriggerCEORaid = -1388385133,
//
//	//Notification = 2041805809,//548471420
//	//NotificationMoneyBanked = 276906331,//-1032040118
//	//NotificationMoneyRemoved = 853249803,//-1197151915
//	//NotificationMoneyStolen = 82080686,//-28878294
//	Notification = -642704387,
//	NotificationMoneyBanked = 94410750,   // TICK_TC_BANK
//	NotificationMoneyRemoved = -242911964, // TICK_TC_REMO
//	NotificationMoneyStolen = -295926414, // TICK_TC_STOL
//	//GiveCollectible = 1839167950, // DLC_SUM20_HIDDEN_COLLECTIBLES xref
//	GiveCollectible = 968269233, // DLC_SUM20_HIDDEN_COLLECTIBLES xref
//
//	//TeleportToWarehouse = -1796714618//434937615 //PYV_WarpFrom
//	TeleportToWarehouse = -1253241415//434937615 //PYV_WarpFrom
//	//TeleportToWarehouse = -1253241415, // .f_4 == 50
//
//	//////////
//	//PersonalVehicleDestroyed = 1655503526,  // PLYVEH_INS_DES1
//	//RemoteOffradar = 57493695,    // NETWORK::GET_TIME_DIFFERENCE(NETWORK::GET_NETWORK_TIME(), Var0.f_2)
//	//TransactionError = -830063381,  // NETWORK_RECEIVE_PLAYER_JOBSHARE_CASH
//
//		//DestroyPersonalVehicle = 109434679, // CnC_PV_THEFT
//		//TriggerCEORaid = -1906536929,
//
//};
//enum eRemoteEvent/* : int32_t*/
//{
//	//BountyEvent = 1459520933,//1370461707
//	//BountyTransaction = 1923597,//1923597
//	BountyEvent = 1517551547,//1370461707
//	BountyTransaction = 1924276,//1923597	
//	//first50k = 429482368, //697566862
//	//second50k = -1178821498, //1046014587
//	//helicospawn = 1131623211,
//	//giverp = -2136917450,//SD_TIC_CMPLT func_20581 under
//	first50k = -347033775, //697566862 //func SD_HT_CMPLT
//	second50k = -1235428989, //1046014587 //reh_prop_reh_bag_para_01a
//	helicospawn = -375628860, //am_island_backup_heli
//	giverp = 1916113629, //func under SD_TIC_CMPLT
//
//	//freezespawn = -1796714618,
//	freezespawn = -1253241415, //func under am_mp_smpl_interior_int
//	tbsgive = -1872286655,
//	yatchinv = 360735385,
//	appinv = 36077543,
//	//StartScriptBegin = -95341040,
//	//StartScriptProceed = 1742713914,
//	//milliondrop = -353514253,//1279059857
//	StartScriptBegin = -366707054,
//	StartScriptProceed = 1757622014,
//	milliondrop = -353514253,//1279059857
//	//NetworkBail = 1017995959, // NETWORK::NETWORK_BAIL(16, 0, 0); xref func
//	//CeoKick2 = 265836764,
//	NetworkBail = -901348601, // NETWORK::NETWORK_BAIL(16, 0, 0); xref func
//	CeoKick2 = 265836764,
//	//MarkPlayerAsBeast = -2001677186, // GB_BOSSBST xref == PLAYER... global (sadly doesn't actually turn people into the beast)
//	MarkPlayerAsBeast = 1649541577, // GB_BOSSBST xref == PLAYER... global (sadly doesn't actually turn people into the beast)
//
//	//eSpectate = -1903870031, // SPEC_TCK1
//	eSpectate = 1840946429,  // SPEC_TCK1
//	//KickFromInterior = 786522321,
//	KickFromInterior = -1496371358,
//	//TAKE_CAYO = 665841803, //-1264900797,//1073952270
//
//	//Bounty = 1459520933,
//	Bounty = 1517551547, //above policeold2
//	Character = 1574918,//Global_1574918
//	//InteriorControl = 1727896103,
//	InteriorControl = -1638522928, // eventData.f_3 != _INVALID_PLAYER_INDEX_0()
//	SHKick = -78445431,
//	//Kick_1 = 1938530224,//1810531023
//	//Kick_2 = -1880259633,//-398684455
//	//Kick_3 = -516949273,//2119903152
//	//Kick_4 = 1418092950,//-508465573
//	//Kick_5 = -1906333887,//1456052554
//	//Kick_6 = 1037271047,//-468188833
//	//Kick_7 = -866893497,//-805921310
//	//Crash1 = -992162568,//-904555865
//	//Crash2 = 39108873,//1192608757
//	//Crash3 = -373650836,//1124104301
//	//Crash4 = 1131623211,//1775863255
//	Kick_1 = -353458099,//1810531023 //bas de la page freemode recherche par en haut oppressor2 case of 7func above
//	Kick_2 = -1140090124,//-398684455 //bas de la page freemode recherche par en haut Previous_Boss case of 6func under
//	Kick_3 = -1713699293,//2119903152 //oppressor2 case of 8func above
//	Kick_4 = -1101672680,//-508465573 //oppressor2 case of 6func above 
//	Kick_5 = -1544003568,//1456052554 //du bas du freemode 2 fois PLYVEH_INS_DES1 case of 4func above or 2time AM_MP_HANGAR du haut du freemode et func under 
//	Kick_6 = 1982477645,//-468188833 // du bas du freemode 2times AM_MP_SMPL_INTERIOR_EXT case of 19func above 
//	Kick_7 = 623462469,//-805921310 // du bas du freemode 2times AM_MP_SMPL_INTERIOR_EXT case 16func above 
//	Crash1 = -1604421397, // SET_NO_LOADING_SCREEN, xref it
//	Crash2 = -375628860,
//	Crash3 = 323285304,
//	Crash4 = -375628860,//1775863255 // du bas du freemode recherche par en haut FMCI_CHCKPNT_D case of 14func above 
//
//	//ScriptFreeze = 330622597,//-93722397
//	ScriptFreeze = 1669592503,//330622597//-93722397 //FMCI_CHCKPNT_D 13 function above
//
//	ScreenBanner = -767364034,//1751618454
//	Inssurance = -642631978,//-964882004
//	//VehicleKick = -1603050746,//-852914485
//	VehicleKick = -503325966,  // PIM_RFMOC
//	//eSoundSpam = 36077543,//-1891171016
//	eSoundSpam = 996099702,   // CELL_APTINVYACHT
//
//	JoinedActivity = -647821994,//-1578682814
//	//ClearWantedLevel = 1743540940,//2080651008
//	ClearWantedLevel = -1704545346,
//	//OffTheRadar = 1141648445,//-162943635
//	Sudoyer = -305178342,//-162943635
//	OffTheRadar = 57493695,    // NETWORK::GET_TIME_DIFFERENCE(NETWORK::GET_NETWORK_TIME(), Var0.f_2)
//
//	NetworkKick = 1017995959,//915462795
//	MoneyEvent_1 = -1178821498,//-1237225255
//	MoneyEvent_2 = 429482368,//549145155
//	RPEvent = -2136917450,//1046014587
//	//StartActivity = 1104117595,//243072129
//	StartActivity = 1450115979, // (Var0.f_2, -1); first match
//	//SendToLocation = 330622597,//-93722397
//	SendToLocation = 1669592503,//-93722397 //case above FMCI_CHCKPNT_D
//	//SendToJob = -2138393348,//1858712297
//	SendToJob = 259469385,//1858712297 //func above FMMC_PLYLOAD
//	//SendToIsland = 369672308,//-910497748
//	SendToIsland = 373376135,//-910497748 //HAND_SHAKE
//	//SendToApartment = -702866045,//-168599209
//	SendToApartment = -1321657966,//-168599209 //under FM_DEL_UNS_4
//	//eCEOBan = 1517094008, // mpply_vipgameplaydisabledtimer
//	//eCEOKick = 1421455565,
//	eCEOBan = 1531565154, // mpply_vipgameplaydisabledtimer
//	eCEOKick = -11681548,
//	//CeoMoney = 75579707, // Goon_Paid_Large
//	CeoMoney = -337848027, // func Goon_Paid_Large
//	//TransactionError = 54323524,//-492741651
//	TransactionError = -830063381,//-492741651 //func PIM_TIGC
//	//SendToCutscene = 2139870214,//392606458
//	SendToCutscene = -1951335381, // (bVar3, bVar4, 125f, 1)
//	//MCTeleport = 891653640,//879177392
//	MCTeleport = 1103127469,//879177392 //RandomID 
//	//GtaBanner = 2114252738,//-795380017
//	GtaBanner = -330501227, // NETWORK::NETWORK_IS_SCRIPT_ACTIVE("BUSINESS_BATTLES", -1, true, 0) second one
//
//	//TSECommand = 113023613, // CnCTG_IN_BF
//	//TSECommandRotateCam = -1762807505, //-1762807505
//	//DestroyPersonalVehicle = -2101545224, // CnC_PV_THEFT
//	//TriggerCEORaid = -1388385133,
//
//	TSECommand = 800157557, // CnCTG_IN_BF
//	TSECommandRotateCam = 225624744, // != 29) && f
//
//	DestroyPersonalVehicle = -2101545224, // CnC_PV_THEFT
//	TriggerCEORaid = -1388385133,
//
//	//Notification = 2041805809,//548471420
//	//NotificationMoneyBanked = 276906331,//-1032040118
//	//NotificationMoneyRemoved = 853249803,//-1197151915
//	//NotificationMoneyStolen = 82080686,//-28878294
//	Notification = -642704387,
//	NotificationMoneyBanked = 94410750,   // TICK_TC_BANK
//	NotificationMoneyRemoved = -242911964, // TICK_TC_REMO
//	NotificationMoneyStolen = -295926414, // TICK_TC_STOL
//	//GiveCollectible = 1839167950, // DLC_SUM20_HIDDEN_COLLECTIBLES xref
//	GiveCollectible = 968269233, // DLC_SUM20_HIDDEN_COLLECTIBLES xref
//	//TeleportToWarehouse = -1796714618//434937615
//	TeleportToWarehouse = -1253241415//434937615 //PYV_WarpFrom
//};

namespace SCRIPTEVENTS {
	static const int64_t START_TYPING = 3033046699;
	static const int64_t STOP_TYPING = 2994416968;
	static const int64_t PAUSE_ENTER = 2329576889; // 1.46 = 1613784162
	static const int64_t PAUSE_LEAVE = 457878498;

	static const int64_t JOINED_PLAYER = 1829532170; // 1.46 = 256098994

	static const int64_t ECLIPSETELEPORT = -1321657966;//-702866045 //1365267338 // 1.46 = 1000837481
	static const int64_t INCREASERP = 1916113629;//-2136917450 // -181444979 // NOT USED
	static const int64_t KICKFROMVEHICLE = -503325966;//-1603050746 //1796063150 // 1.46 = 325218053
	static const int64_t FORCEINTOMISSION = 259469385;//-2138393348 // -2145536660// 1.46 = -15432926
	static const int64_t NOTIFICATION = -642704387;//2041805809 //111286607// 1.46 = 713068249
	static const int64_t NOTIFICATION2 = 94410750;//276906331 // -270262485// 1.46 = 1009196241

	static const int64_t NONHOSTKICK1 = -353458099;//1938530224 //423635655 // 1.46 = -120668417
	static const int64_t NONHOSTKICK2 = -1140090124;//-1880259633 //400031869 // 1.46 = 1222825035
	static const int64_t NONHOSTKICK3 = -1713699293;//-516949273 // -510378036 // 1.46 = 769347061
	static const int64_t NONHOSTKICK4 = -1101672680;//1418092950 // -815817885 // 1.46 = 999090520
	static const int64_t NONHOSTKICK5 = -1544003568;//-1906333887 // -1264063129 // 1.46 = 1642479322
	static const int64_t NONHOSTKICK6 = 1982477645;//1037271047 //-941739545 // 1.46 = 2055958901


	static const int64_t KICKTOSP1 = 623462469;//-866893497 // -1424895288 // 1.46 = 994306218

	static const int64_t KICKTOSP2 = 1314698923; // 1.46 = -928998106
	static const int64_t KICKTOSP3 = -158670784; // 1.46 = 1153942884

	static const int64_t CEOKICK = -11681548;// 1421455565 // -606032195// 1.46 = -1190833098
	static const int64_t CEOBAN = 1531565154;//1517094008 // -326132866// 1.46 = 360381720

	static const int64_t INVITE = 996099702;//36077543 //715645088// 1.46 = -175474624
	static const int64_t GOTR_Event = 57493695;//1141648445 //1141648445//1848739240 // 1.46 = 1344161996
	static const int64_t GNEVERWANTED = 1895156;//1894573 //1743540940//685727305// 1.46 = 1475266103
	static const int64_t GCOPSTURNBLINDEYE = -305178342;//-1635856102 // 1.46 = 1555129594

	static const int64_t SPECTATINGMESSAGE = 1840946429;//-1903870031 //446273009// 1.46 = 436170208
	static const int64_t FACECAMERAFORWARD = 225624744;//-1762807505 // -42615386// 1.46 = 566035618
	static const int64_t FACECAMERAFORWARD2 = 745899999; // 1.46 = -1432407380

	static const int64_t DISPLAYINSURANCEMESSAGE = -642631978; //252265430// 1.46 = 380155193
	static const int64_t TRANSACTIONERRORSPAM = -830063381;//54323524// -1049031463
};


namespace Globals {
	static const int LEVEL = 289559; // 1.46 = 287850
	static const int MPINSP = 4540731; //4540726//4267883// UPDATED
	//static const int PLAYER_BASE = 1853910; //1589819 // 1.46 = 1589747
	static const int PLAYER_BASE = 1853988; //1589819 // 1.46 = 1589747
	//static const int PLAYER_PADDING = 862; //818 // 1.46 = 790
	 static const int PLAYER_PADDING = 867; //818 // 1.46 = 790
	//static const int PLAYER_EXTRA = 237; // 1.46 = 237
	//static const int PLAYER_OFFSET = 205; //211 // SAME
	 static const int PLAYER_OFFSET = 205; //211 // SAME
	static const int PLAYER_OFFSET_WALLET = 3; // SAME
	static const int PLAYER_OFFSET_TOTAL = 56; // SAME
	static const int PLAYER_OFFSET_XP = 5; // SAME
	static const int PLAYER_OFFSET_LEVEL = 6; // SAME
	static const int PLAYER_OFFSET_KD = 26; // SAME
	static const int PLAYER_OFFSET_KILLS = 28; // SAME
	static const int PLAYER_OFFSET_DEATHS = 29; // SAME
	static const int OTR_BASE = 2657704; //2424047// 1.46 = 2423801
	static const int OTR_PADDING = 463; //416// 1.46 = 413
	static const int OTR_OFFSET = 210;//200 // SAME
	static const int OTR_PLAYERS_OFFSET = 222; // SAME
	static const int EFFECT_TIME_BASE = 2672524; //2672505//2437364// 1.46 = 2437022
	static const int TIME_BASE = 2528542; // 1.46 = 2524719
	static const int TIME_OFFSET = 57;//70 // SAME
	static const int NOIDLEKICK = 1654054;//1653913 //1371947// 1.46 = 1368245
	static const int TESTOSTERONE_OFFSET = 3690; //3880// 1.46 = 3876
	static const int BLINDEYEOFFSET1 = 4546; // 1.46 = 4542
	static const int BLINDEYEOFFSET2 = 4549; // 1.46 = 4545
	static const int SNOW_BASE = 262145; // SAME
	static const int SNOW_OFFSET = 4752; //4721// SAME

	/*Interaction menu instructional queue*/
	static const int IMIQUEUE_BASE = 17411; // 1.46 = 17367
	static const int IMIQUEUE_OFFSET = 4769; // 1.46 = 4767
	static const int IMIQUEUE_OFFSET2 = 4770; // 1.46 = 4768
	static const int PHONE_BASE = 14553; // UPDATED
	static const int PHONE_BOOL1 = 14725; // 1.46 = 14681
	static const int PHONE_POSSET = 14481; // 1.46 = 14441
	static const int PHONE_POSGET = 14498; // 1.46 = 14458
	static const int PHONE_BITSET1 = 2424; // 1.46 = 2384
	static const int PHONE_BITSET2 = 2423; // 1.46 = 2383

	static const int REMOTE_BASE = 1895156;//1894573 //1626536// 1.46 = 1625435
	static const int REMOTE_SIZE = 609;//608 //603// 1.46 = 560
	static const int REMOTE_OFFSET = 511;//510 //529// 1.46 = 491

	/* Added before casino dlc */
	//static const int NOIDLEKICK2 = 1172; //1165// 1.46 = 1165
	//static const int NOIDLEKICK3 = 1156; //1149// 1.46 = 1149
	static const int NOIDLEKICK2 = 1171; //1165// 1.46 = 1165
	static const int NOIDLEKICK3 = 1155; //1149// 1.46 = 1149
};




