#pragma once
#include "menu/submenu.h"

class RemoteMenu : public Submenu {
public:
	static RemoteMenu* GetInstance();
	void Init() override;
	void UpdateOnce() override;
	void Update() override;
	void FeatureUpdate() override;

	RemoteMenu() : Submenu() {}
	~RemoteMenu();
};

#define NETWORK_SPENT_CASH_DROP     4535950
#define SERVICE_SPEND_CASH_DROP     2707342

#define MONEY_NETWORK_SPENT_CASH_DROP 2707336
#define MONEY_NETWORK_SPENT_HOLDUPS      2738934

//const int DisableErrorScreenGlobal[] = { 4536673 };//Global_4535606
//const int DisableErrorScreenGlobal[] = { 4537356 };//4536677//Global_4536673
//#define moneydropglobal1 2764232 //2764230 //2787534 //under HeistLocate
//#define moneydropglobal2 4535172 //4534105 //above MPROP_RWD_TCK1m
//#define moneydropglobal3 2764238 //2764236 //2787540
//#define moneydropglobal1 2707016 //2764405 //2764230 //2787534 //under HeistLocate //above SERVICE_SPEND_CASH_DROP
//#define moneydropglobal2 4535851 //4535172 //4534105 //above MPROP_RWD_TCK1m
//#define moneydropglobal3 2707022 //2764411 //2764236 //2787540 above SERVICE_SPEND_CASH_DROP above global1
#define moneydropglobal1 2707336 //2764405 //2764230 //2787534 //under HeistLocate //above SERVICE_SPEND_CASH_DROP
#define moneydropglobal2 4535950 //4535172 //4534105 //above MPROP_RWD_TCK1m
#define moneydropglobal3 2707342 //2764411 //2764236 //2787540 above SERVICE_SPEND_CASH_DROP above global1

namespace scr_locals //big::
{
	namespace am_hunt_the_beast
	{
		//constexpr static auto broadcast_idx = 599;//597
		/*constexpr static auto broadcast_idx = 602;
		constexpr static auto player_broadcast_idx = 2586;*/
		constexpr static auto broadcast_idx = 607;  // (bParam0) != 0;
		constexpr static auto player_broadcast_idx = 2588; // if (NETWORK::PARTICIPANT_ID_TO_INT() != -1)
	}
}
namespace am_criminal_damage
{
	constexpr static auto broadcast_idx = 113;
	constexpr static auto score_idx = 108;
}
namespace am_cp_collection
{
	constexpr static auto broadcast_idx = 818;
	constexpr static auto player_broadcast_idx = 3459;
}
namespace am_king_of_the_castle
{
	constexpr static auto broadcast_idx = 96;
}

namespace fmmc_launcher
{
	constexpr static auto broadcast_idx = 12327;
}



	//	inline void request_taxi()
	//{
	////	scr_globals::freemode_global.at(853).as<int>() = 1;
	//	scr_globals::freemode_global.at(868).as<int>() = 1;
	//}
	//inline void request_avenger()
	//{
	////	scr_globals::freemode_global.at(938).as<int>() = 1;
	//	scr_globals::freemode_global.at(953).as<int>() = 1;
	//}

	//inline void request_kosatka()
	//{
	////	scr_globals::freemode_global.at(960).as<int>() = 1;
	//	scr_globals::freemode_global.at(975).as<int>() = 1;
	//}

	//inline void request_mobile_operations_center()
	//{
	////	scr_globals::freemode_global.at(930).as<int>() = 1;
	//	scr_globals::freemode_global.at(945).as<int>() = 1;
	//}

	//inline void request_terrorbyte()
	//{
	////	scr_globals::freemode_global.at(943).as<int>() = 1;
	//	scr_globals::freemode_global.at(958).as<int>() = 1;
	//}

	//inline void request_acidlab()
	//{
	////	scr_globals::freemode_global.at(944).as<int>() = 1;
	//	scr_globals::freemode_global.at(959).as<int>() = 1;
	//}

	//inline void request_acidlab_bike()
	//{
	////	scr_globals::freemode_global.at(994).as<int>() = 1;
	//	scr_globals::freemode_global.at(1009).as<int>() = 1;
	//}

const int TunnablesGlobal[] = { 262145 };

//#define Info_1 1845263//Global_1853910[PLAYER::PLAYER_ID() /862/].f_205
//#define Info_2 877
//#define Info_3 205
#define Info_1 1845281
#define Info_2 883
#define Info_3 206

#define InfoRp 5
#define InfoKD 26
#define InfoRank 6
#define InfoBank 56
#define InfoWallet 3
#define InfoDeaths 29
#define InfoKills 28
#define Disable_Phone 20813//Global_20500.f_1
#define Freemode_Give_Off_The_Radar eRemoteEvent::OffTheRadar
//#define Freemode_Give_Off_The_Radar OffTheRadar /*-162943635*//*-391633760*/ //-397188359 //Var0.f_3 = get_network_time(); //giveoff
#define Freemode_Give_NoCops Sudoyer /*-162943635*//*-391633760*/ //-397188359 //Var0.f_3 = get_network_time(); //giveoff
#define Freemode_Give_Off_The_Radar_Global globalHandle(NeverWanted[0]).At(target, NeverWanted[1]).At(NeverWanted[2]).As<int>() //Global_1630816[PLAYER_ID() /*597*/].f_508;
//#define JoinSession1 1575032 //Global_1575020
//#define JoinSession2 1574589 //Global_1574589

#define JoinSession1 1574589 //Global_1574589
#define JoinSession2 1575035 //1575032 //Global_1575020


#define Ghost_Mode_1 globalHandle(2657921).At(1 + (PlayerID * 463)).At(210).As<int>() = 1;//Global_2657704[PLAYER::PLAYER_ID() /463/].f_210 Global_2657921[unk_0x259BE71D8A81D4FA() /463/].f_210 = 0;
#define Ghost_Mode_2 globalHandle(2672741).At(58).As<int>() = NETWORK::GET_NETWORK_TIME() + 1;//Global_2672524.f_57 done Global_2672741.f_58

#define Reveal_Players_1(player) globalHandle(2657921).At(1 + (player * 463)).At(213).As<int>() = 1;//Global_2657704[PLAYER::PLAYER_ID() /466/].f_213
#define Reveal_Players_2 globalHandle(2672741).At(58).As<int>() = NETWORK::GET_NETWORK_TIME() + 1;

//const int ThunderEvent1Global[] = { 1916087, 11, 373 };//Global_1916087.f_11.f_373
//const int ThunderEvent2Global[] = { 1916087, 11, 365 };//
//const int ThunderEvent3Global[] = { 1886967, 609, 10, 205 };//Global_1895156[PLAYER::PLAYER_ID() /*609*/].f_10.f_205
//
//
//const int ArmoredTruckLocationGlobal[]{ 1890378, 1, 242, 5 };
//const int ArmoredTruckCooldownGlobal[]{ 262145, 34038 };

const int GiveCasinoChipsGlobal[] = { 2708057, 308, 309, 26681 /*<--Tunable*/ };
const int GiveCasinoChipsStartGlobal[] = { 2657971, 465 };

const int SignalJammersGlobal[] = { 2708057, 211, 27934 /*<--Tunable*/ };//func_2010(&Global_2707706, flag2);
const int DisablePhoneGlobal[] = { 20930, 1 };//Global_20813.f_1
const int GoochGlobal[] = { 1882247, 304, 1 };//Global_1882037.f_304.f_1
const int ArmoredTruckLocationGlobal[]{ 1890378, 1, 242, 5 };//1.67
const int ArmoredTruckCooldownGlobal[]{ TunnablesGlobal[0], 34038 };//1.67

const int ThunderEvent1Global[] = { 1916617, 11, 379 };//Global_1916087.f_11.f_373
const int ThunderEvent2Global[] = { 1916617, 11, 370 };//Global_1916087.f_11.f_365
const int ThunderEvent3Global[] = { 1887305, 610, 10, 205 };//Global_1886967[plParam0 /*609*/].f_10.f_205


#define RecoveryHolidayGift_1 globalHandle(262145).At(31744).As<int>() = 1;
#define RecoveryHolidayGift_2 globalHandle(262145).At(31745).As<int>() = 1;
#define RecoveryHolidayGift_3 globalHandle(262145).At(30890).As<int>() = 1;
#define RecoveryHolidayGift_4 globalHandle(262145).At(28678).As<int>() = 1;
#define RecoveryHolidayGift_5 globalHandle(262145).At(28681).As<int>() = 1;
#define RecoveryHolidayGift_6 globalHandle(262145).At(28679).As<int>() = 1;
#define RecoveryHolidayGift_7 globalHandle(262145).At(28680).As<int>() = 1;
#define RecoveryHolidayGift_8 globalHandle(262145).At(25826).As<int>() = 1;
#define RecoveryHolidayGift_9 globalHandle(262145).At(25829).As<int>() = 1;
#define RecoveryHolidayGift_10 globalHandle(262145).At(25827).As<int>() = 1;
#define RecoveryHolidayGift_11 globalHandle(262145).At(25828).As<int>() = 1;
#define RecoveryHolidayGift_12 globalHandle(262145).At(24231).As<int>() = 1;
#define RecoveryHolidayGift_13 globalHandle(262145).At(23435).As<int>() = 1;
#define RecoveryHolidayGift_14 globalHandle(262145).At(23436).As<int>() = 1;
#define RecoveryHolidayGift_15 globalHandle(262145).At(23437).As<int>() = 1;
#define RecoveryHolidayGift_16 globalHandle(262145).At(23438).As<int>() = 1;
#define RecoveryHolidayGift_17 globalHandle(262145).At(23439).As<int>() = 1;
#define RecoveryHolidayGift_18 globalHandle(262145).At(23440).As<int>() = 1;
#define RecoveryHolidayGift_19 globalHandle(262145).At(23441).As<int>() = 1;
#define RecoveryHolidayGift_20 globalHandle(262145).At(23442).As<int>() = 1;
#define RecoveryHolidayGift_21 globalHandle(262145).At(23465).As<int>() = 1;
#define RecoveryHolidayGift_22 globalHandle(262145).At(23462).As<int>() = 1;
#define RecoveryHolidayGift_23 globalHandle(262145).At(23463).As<int>() = 1;
#define RecoveryHolidayGift_24 globalHandle(262145).At(23464).As<int>() = 1;
#define RecoveryHolidayGift_25 globalHandle(262145).At(9184).As<int>() = 1;
#define RecoveryHolidayGift_26 globalHandle(262145).At(9448).As<int>() = 1;
#define RecoveryHolidayGift_27 globalHandle(262145).At(9449).As<int>() = 1;
#define RecoveryHolidayGift_28 globalHandle(262145).At(9450).As<int>() = 1;
#define RecoveryHolidayGift_29 globalHandle(262145).At(12813).As<int>() = 1;
#define RecoveryHolidayGift_30 globalHandle(262145).At(12814).As<int>() = 1;
#define RecoveryHolidayGift_31 globalHandle(262145).At(12815).As<int>() = 1;
#define RecoveryHolidayGift_32 globalHandle(262145).At(12816).As<int>() = 1;
#define RecoveryHolidayGift_33 globalHandle(262145).At(23443).As<int>() = 1;
#define RecoveryHolidayGift_34 globalHandle(262145).At(25822).As<int>() = 1;
#define RecoveryHolidayGift_35 globalHandle(262145).At(25824).As<int>() = 1;

#define Idle_Kick_1 globalHandle(262145).At(87).As<int>() = INT_MAX;//Global_262145.f_87
#define Idle_Kick_2 globalHandle(262145).At(88).As<int>() = INT_MAX;//Global_262145.f_88
#define Idle_Kick_3 globalHandle(262145).At(89).As<int>() = INT_MAX;//Global_262145.f_89
#define Idle_Kick_4 globalHandle(262145).At(90).As<int>() = INT_MAX;//Global_262145.f_90

const int EasyBusinessSellLocal[] = { 698, 17 };

const int InstantHeistLocal[] = { 38396, 1375, 1 };
//const int MiniMapStateGlobal[] = { 2647042, 1593 };//Global_2646835.f_1593 Global_2647042.f_1593
const int MiniMapStateGlobal[] = { 2647061, 1593 };//Global_2647042.f_1593

const int BunkerResearchGlobal[] = { TunnablesGlobal[0], 22067 };//Global_262145.f_22037
//const int BallisticArmorGlobal[] = { 2738587, 901 };//Global_2794162.f_901
//const int BallisticArmorGlobal[] = { 2738934, 916 };//Global_2738587.f_901
//const int FreeBallisticArmorGlobal[] = { TunnablesGlobal[0], 19851 };//Global_262145.f_20318
const int BallisticArmorGlobal[] = { 2740054,928 };//2738934, 916 //Global_2738587.f_901 //AM_AMMO_DROP
const int FreeBallisticArmorGlobal[] = { TunnablesGlobal[0], 20089 };//Global_262145.f_20318 //19851 //CELL_MP_1009H
const int FastRespawnGlobal[] = { 2672964, 1761, 756 }; //2672855, 1728, 756 //Global_2672741.f_1689.f_756 //timerbar_lines

//const int FreeBallisticArmorGlobal[] = { TunnablesGlobal[0], 20318 };//Global_262145.f_20288
//const int FastRespawnGlobal[] = { 2672741, 1689, 756 };//Global_2672524.f_1685.f_756 Global_2672741.f_1689.f_756
//const int FastRespawnGlobal[] = { 2672855, 1728, 756 };//Global_2672741.f_1689.f_756

//const int MOCGlobal[] = { 2738587, 930 };//Global_2794162.f_930 Global_2738587.f_930 = 1;
//const int AcidLabGlobal[] = { 2738587, 944 };//Global_2794162.f_944 Global_2738587.f_944 = 0;
//const int AvengerGlobal[] = { 2738587, 938 };//Global_2794162.f_938 Global_2738587.f_938 = 1;
//const int TerrobyteGlobal[] = { 2738587, 943 };//Global_2794162.f_943 Global_2738587.f_930
//const int KosatkaGlobal[] = { 2738587, 960 };//Global_2794162.f_960 Global_2738587.f_960
//const int DingyGlobal[] = { 2738587, 972 };//Global_2794162.f_972 Global_2738587.f_972
const int MOCGlobal[] = { 2738934, 945 };//Global_2738587.f_930 = 1;
const int AcidLabGlobal[] = { 2738934, 959 };//Global_2738587.f_944 = 0;
const int AvengerGlobal[] = { 2738934, 953 };//Global_2738587.f_938 = 1;
const int TerrobyteGlobal[] = { 2738934, 958 };//Global_2738587.f_943
const int KosatkaGlobal[] = { 2738934, 975 };//Global_2738587.f_960
const int DingyGlobal[] = { 2738934, 987 };//Global_2738587.f_972

//const int BullsharkGlobal[] = { 2672741, 3694 };//Global_2672524.f_3690
//const int AirstrikeGlobal[] = { 2738587, 4492 };//Global_2794162.f_4492 Global_2738587.f_4492
//const int AmmoDropGlobal[] = { 2738587, 905 };//Global_2794162.f_905 Global_2738587.f_905
//const int CrateDropGlobal[] = { 2738587, 899 };//Global_2794162.f_899 Global_2738587.f_899
//const int BullsharkGlobal[] = { 2672855, 3733 };//Global_2672741.f_3694
//const int AirstrikeGlobal[] = { 2738934, 4507 };//Global_2738587.f_4492
//const int AmmoDropGlobal[] = { 2738934, 920 };//Global_2738587.f_905
//const int CrateDropGlobal[] = { 2738934, 914 };//Global_2738587.f_899

const int BullsharkGlobal[] = { 2672964, 3766 };//Global_2672741.f_3694 //BULL_SHARK_TESTOSTERONE_01 if (IS_BIT_SET(Global_2672964.f_3766, 4)) //2672855, 3733
const int AirstrikeGlobal[] = { 2740054, 4525 };//Global_2738587.f_4492 //am_airstrike  		case 1: if (Global_2740054.f_4525) //2738934, 4507
const int AmmoDropGlobal[] = { 2740054, 932 };//Global_2738587.f_905 //MP_CELEB_SCREEN_SCENE //if (Global_2740054.f_932) //2738934, 920
const int CrateDropGlobal[] = { 2740054, 926 };//Global_2738587.f_899 //AM_BRU_BOX //2738934, 914 //if (Global_2740054.f_926)

//const int BoatPickupGlobal[] = { 2738934, 907 };//Global_2738587.f_892
//const int MiniTankGlobal[] = { 2738934, 6957 };//Global_2738587.f_6919
//const int RCBanditoGlobal[] = { 2738934, 6956 };//Global_2738587.f_6918
//const int DroneGlobal[] = { 1956920 };//Global_1956030

const int BoatPickupGlobal[] = { 2738934, 907 };//Global_2738587.f_892
const int MiniTankGlobal[] = { 2738934, 6957 };//Global_2738587.f_6919
const int RCBanditoGlobal[] = { 2740054, 7011 };//Global_2738587.f_6918 //rcbandito if (Global_2740054.f_7011) //2738934, 6956
const int DroneGlobal[] = { 1959772 };//Global_1956030 //am_mp_drone //1956920

const int HelicopterBackupGlobal[] = { 2738934, 4506 };//Global_2738587.f_4491
const int HelicopterPickupGlobal[] = { 2738934, 908 };//Global_2738587.f_893
const int SpectateDeathPatchGlobal[] = { 2738934, 6958 };//Global_2738587.f_6920
const int TeleportInPersonalVehicleGlobal[] = { 2640096, 8 };//Global_2640095.f_8
//
//const int VehicleBypassGlobal[] = { 4541512 };//Global_4541411 shop_controller.c
const int PlayerInfoGlobal[] = { 1845281, 883, 206 };//Global_1845263[PLAYER::PLAYER_ID() /877/].f_205


//#define VehicleBypass 4541512 //4541411//4540731
//const int VehicleBypassGlobal[] = { 4541512 };//Global_4541411 shop_controller.c
//const int VehicleBypassGlobal[] = { 4542730 };//1.71(3586)//4542146 //Global_4541411 shop_controller.c //3442
//#define VehicleBypass 4542730/*4540731*///4541411
const int VehicleBypassGlobal[] = { 4542730 };//4542146 //Global_4541411 shop_controller.c //4541512 //https://github.com/dwep1337/GTAV-Decompiled-Scripts

//const int BoatPickupGlobal[] = { 2738587, 892 };//Global_2794162.f_892
//const int HelicopterBackupGlobal[] = { 2738587, 4491 };//Global_2794162.f_4491 Global_2738587.f_4491
//const int HelicopterPickupGlobal[] = { 2738587, 893 };//Global_2794162.f_893 Global_2738587.f_893
//const int SpectateDeathPatchGlobal[] = { 2738587, 6920 };//Global_2794162.f_6881 Global_2738587.f_6920
//const int SpectateDeathPatchGlobal[] = { 2794162, 6881 };//Global_2793046.f_6876
//const int TeleportInPersonalVehicleGlobal[] = { 2640095, 8 };//Global_2639889.f_8
//const int VehicleBypassGlobal[] = { 4541411 };//Global_4540726 shop_controller.c
//const int PlayerPictureGlobal[] = { 1680805, 2 };//Global_1666668[iVar0 /5/].f_2
//const int MiniTankGlobal[] = { 2738587, 6919 };//Global_2794162.f_6880 Global_2738587.f_6919
//const int RCBanditoGlobal[] = { 2738587, 6918 };//Global_2794162.f_6879 Global_2738587.f_6918
//const int DroneGlobal[] = { 1956030 };//Global_1963795

//const int DisableErrorScreenGlobal[] = { 4537356 };//Global_4536677
//const int InteriorStateGlobal[] = { 2657921, 1, 463, 245 };//Global_2657704[bVar0 /*463*/].f_245
//const int BusinessGlobal[] = { 1845263, 877, 267, 195, 13 };//Global_1853988[PLAYER::PLAYER_ID() /*867*/].f_267.f_193[bParam0 /*13*/] Global_1845263[unk_0x259BE71D8A81D4FA() /*877*/].f_267.f_195[iParam0 /*13*/]
//const int AddBusinessSupplyGlobal[] = { 1662881, 1 };//Global_1648657
//const int NightClubStockGlobal[] = { 1845263, 877, 267, 313, 8 };//Global_1853988[PLAYER::PLAYER_ID() /*867*/].f_267.f_311.f_8 Global_1845263[unk_0x259BE71D8A81D4FA() /*877*/].f_267.f_313.f_8[num]
//const int NightClubVaultGlobal[] = { 1845263, 877, 267, 356, 5 };//Global_1853988[PLAYER::PLAYER_ID() /*867*/].f_267.f_354.f_5
//
//const int CashCreationTimerGlobal[] = { TunnablesGlobal[0], 24583 };//Global_262145.f_24553 Global_262145.f_24583
//const int SportingGoodsTimerGlobal[] = { TunnablesGlobal[0], 24578 };//Global_262145.f_24548 Global_262145.f_24578
//const int OrganicProduceTimerGlobal[] = { TunnablesGlobal[0], 24581 };//Global_262145.f_24551 Global_262145.f_24581
//const int CargoandShipmentsTimerGlobal[] = { TunnablesGlobal[0], 24584 };//Global_262145.f_24554 Global_262145.f_24584
//const int PrintingCopyingTimerGlobal[] = { TunnablesGlobal[0], 24582 };//Global_262145.f_24552 Global_262145.f_24582
//const int AmericanImportsTimerGlobal[] = { TunnablesGlobal[0], 24579 };//Global_262145.f_24549 Global_262145.f_24579
//const int PharmaceuticalTimerGlobal[] = { TunnablesGlobal[0], 24580 };//Global_262145.f_24550 Global_262145.f_24580
//const int CashCreationMaxStockGlobal[] = { TunnablesGlobal[0], 24605 };//Global_262145.f_24575 Global_262145.f_24605
//const int SportingGoodsMaxStockGlobal[] = { TunnablesGlobal[0], 24600 };//Global_262145.f_24570 Global_262145.f_24600
//const int OrganicProduceMaxStockGlobal[] = { TunnablesGlobal[0], 24603 };//Global_262145.f_24573 Global_262145.f_24603
//const int CargoandShipmentsMaxStockGlobal[] = { TunnablesGlobal[0], 24606 };//Global_262145.f_24576 Global_262145.f_24606
//const int PrintingCopyingMaxStockGlobal[] = { TunnablesGlobal[0], 24604 };//Global_262145.f_24574 Global_262145.f_24604
//const int AmericanImportsMaxStockGlobal[] = { TunnablesGlobal[0], 24601 };//Global_262145.f_24571 Global_262145.f_24601
//const int PharmaceuticalMaxStockGlobal[] = { TunnablesGlobal[0], 24602 };//Global_262145.f_24572 Global_262145.f_24602
//const int CashCreationPriceGlobal[] = { TunnablesGlobal[0], 24591 };//Global_262145.f_24561 Global_262145.f_24591
//const int SportingGoodsPriceGlobal[] = { TunnablesGlobal[0], 24586 };//Global_262145.f_24556 Global_262145.f_24586
//const int OrganicProducePriceGlobal[] = { TunnablesGlobal[0], 24589 };//Global_262145.f_24559 Global_262145.f_24589
//const int CargoandShipmentsPriceGlobal[] = { TunnablesGlobal[0], 24592 };//Global_262145.f_24562 Global_262145.f_24592
//const int PrintingCopyingPriceGlobal[] = { TunnablesGlobal[0], 24590 };//Global_262145.f_24560 Global_262145.f_24590
//const int AmericanImportsPriceGlobal[] = { TunnablesGlobal[0], 24587 };//Global_262145.f_24557 Global_262145.f_24587
//const int PharmaceuticalPriceGlobal[] = { TunnablesGlobal[0], 24588 };//Global_262145.f_24558 Global_262145.f_24588
//const int CocaineBoostGlobal[] = { TunnablesGlobal[0], 17601, 3000000 };//Global_262145.f_17573 Global_262145.f_17601
//const int MethBoostGlobal[] = { TunnablesGlobal[0], 17600, 1800000 };//Global_262145.f_17572 Global_262145.f_17600
//const int WeedBoostGlobal[] = { TunnablesGlobal[0], 17599, 360000 };//Global_262145.f_17571 Global_262145.f_17599
//const int CashBoostGlobal[] = { TunnablesGlobal[0], 17603, 720000 };//Global_262145.f_17575 Global_262145.f_17603
//const int DocumentsBoostGlobal[] = { TunnablesGlobal[0], 17602, 300000 };//Global_262145.f_17574 Global_262145.f_17602
//const int BunkerBoostGlobal[] = { TunnablesGlobal[0], 21742 , 600000 };//Global_262145.f_21712 Global_262145.f_21742
//const int BusinessStockGlobal[] = { 1853348, 834, 267, 191, 13, 1 };
//const int BusinessSupplyGlobal[] = { 1853348, 834, 267, 191, 13, 3 };

const int DisableErrorScreenGlobal[] = { 4537455 };//Global_4537356
const int InteriorStateGlobal[] = { 2657971, 1, 465, 246 };//Global_2657921[bVar0 /*463*/].f_245
const int BusinessGlobal[] = { 1845281, 883, 268, 197, 13 };//Global_1845263[unk_0x259BE71D8A81D4FA() /*877*/].f_267.f_195[iParam0 /*13*/]
const int AddBusinessSupplyGlobal[] = { 1663182, 1 };//Global_1662881 [[fallthrough]];
const int NightClubStockGlobal[] = { 1845281, 883, 268, 315, 8 };//Global_1845263[unk_0x259BE71D8A81D4FA() /*877*/].f_267.f_313.f_8[num]
const int NightClubVaultGlobal[] = { 1845281, 883, 268, 358, 5 };//Global_1845263[PLAYER::PLAYER_ID() /*877*/].f_267.f_356.f_5

const int CashCreationTimerGlobal[] = { TunnablesGlobal[0], 23953 };//Global_262145.f_24583
const int SportingGoodsTimerGlobal[] = { TunnablesGlobal[0], 23948 };//Global_262145.f_24578
const int OrganicProduceTimerGlobal[] = { TunnablesGlobal[0], 23951 };//Global_262145.f_24581
const int CargoandShipmentsTimerGlobal[] = { TunnablesGlobal[0], 23954 };//Global_262145.f_24584
const int PrintingCopyingTimerGlobal[] = { TunnablesGlobal[0], 23952 };//Global_262145.f_24582
const int AmericanImportsTimerGlobal[] = { TunnablesGlobal[0], 23949 };//Global_262145.f_24579
const int PharmaceuticalTimerGlobal[] = { TunnablesGlobal[0], 23950 };//Global_262145.f_24580
const int CashCreationMaxStockGlobal[] = { TunnablesGlobal[0], 23975 };//Global_262145.f_24605
const int SportingGoodsMaxStockGlobal[] = { TunnablesGlobal[0], 23970 };//Global_262145.f_24600
const int OrganicProduceMaxStockGlobal[] = { TunnablesGlobal[0], 23973 };//Global_262145.f_24603
const int CargoandShipmentsMaxStockGlobal[] = { TunnablesGlobal[0], 23976 };//Global_262145.f_24606
const int PrintingCopyingMaxStockGlobal[] = { TunnablesGlobal[0], 23974 };//Global_262145.f_24604
const int AmericanImportsMaxStockGlobal[] = { TunnablesGlobal[0], 23971 };//Global_262145.f_24601
const int PharmaceuticalMaxStockGlobal[] = { TunnablesGlobal[0], 23972 };//Global_262145.f_24602
const int CashCreationPriceGlobal[] = { TunnablesGlobal[0], 23961 };//Global_262145.f_24591
const int SportingGoodsPriceGlobal[] = { TunnablesGlobal[0], 23956 };//Global_262145.f_24586
const int OrganicProducePriceGlobal[] = { TunnablesGlobal[0], 23959 };//Global_262145.f_24589
const int CargoandShipmentsPriceGlobal[] = { TunnablesGlobal[0], 23962 };//Global_262145.f_24592
const int PrintingCopyingPriceGlobal[] = { TunnablesGlobal[0], 23960 };//Global_262145.f_24590
const int AmericanImportsPriceGlobal[] = { TunnablesGlobal[0], 23957 };//Global_262145.f_24587
const int PharmaceuticalPriceGlobal[] = { TunnablesGlobal[0], 23958 };//Global_262145.f_24588
const int CocaineBoostGlobal[] = { TunnablesGlobal[0], 17601, 3000000 };//Global_262145.f_17601
const int MethBoostGlobal[] = { TunnablesGlobal[0], 17291, 1800000 };//Global_262145.f_17600
const int WeedBoostGlobal[] = { TunnablesGlobal[0], 17290, 360000 };//Global_262145.f_17599
const int CashBoostGlobal[] = { TunnablesGlobal[0], 17294, 720000 };//Global_262145.f_17603
const int DocumentsBoostGlobal[] = { TunnablesGlobal[0], 17293, 300000 };//Global_262145.f_17602
const int BunkerBoostGlobal[] = { TunnablesGlobal[0], 21249 , 600000 };//Global_262145.f_21742

const int BusinessStockGlobal[] = { 1853348, 834, 267, 191, 13, 1 };
const int BusinessSupplyGlobal[] = { 1853348, 834, 267, 191, 13, 3 };


//const int JoinCEOGlobal[] = { 1894573, 608, 10 };//Global_1892703[PLAYER::PLAYER_ID() /*599*/].f_10
//const int JoinCEOGlobal[] = { 1895156, 609, 10 };
//const int CEOMoneyGlobal[] = { -337848027, 198210293 };//75579707, 198210293
//const int VisionGlobal[] = { 1845263, 877, 833, 11 };
const int VisionGlobal[] = { 1845281, 883, 849, 11 };//Global_1845263[i /*877*/].f_833.f_

//const int WeatherGlobal[] = { TunnablesGlobal[0], 4752 };//Global_262145.f_4752
const int WeatherGlobal[] = { TunnablesGlobal[0], 4413 };//Global_262145.f_4575

//const int JoinCEOGlobal[] = { 1886967, 609, 10 };//Global_1894573[PLAYER::PLAYER_ID() /*608*/].f_10 DONE
//const int CEOMoneyGlobal[] = { -337848027, 198210293 /*SERVICE_EARN_FMBB_WAGE_BONUS*/ };//75579707, 198210293
//const int JoinCEOGlobal[] = { 1887305, 610, 10 };//Global_1886967[PLAYER::PLAYER_ID() /*609*/].f_10
//const int CEOMoneyGlobal[] = { -337848027, 198210293 /*SERVICE_EARN_FMBB_WAGE_BONUS*/ };//75579707, 198210293
const int JoinCEOGlobal[] = { 1888737, 611, 10 };//Global_1886967[PLAYER::PLAYER_ID() /*609*/].f_10
const int CEOMoneyGlobal[] = { -337848027, 198210293 /*SERVICE_EARN_FMBB_WAGE_BONUS*/ };//75579707, 198210293


//#define NeverWanted1 1895156 //1894573
//#define NeverWanted2 609 //608
//#define NeverWanted3 511 //510
//const int NeverWantedGlobal[] = { 1895156, 609, 511 };
//const int NeverWantedGlobal[] = { 1886967, 609, 511 };
//const int NeverWantedGlobal[] = { 1887305, 610, 512 }; //above 1541018842
const int NeverWantedGlobal[] = { 1888737, 611, 513 };

extern int Time_Send_OTR;
extern int isme_R;
extern void myid_R();

//std::array<int, 8> SendToArcadeEvent = { 20, 193, 210, 211, 212, 216, 217, 218 };
extern int SendToArcadePosition;
//std::vector<std::string> SendToArcadeString = { "tutorial", "golf", "Race And Chase", "Start Badlands Revenge II", "wizzard ruin", "Go Go Space Monkey", "qub3d", "camhedz", };//, "Start Darts",  "Gunslinger", "Wizards Ruin"

//std::array<int, 16> SendToArcadeEvent = { 20, 193, 196, 192, 211, 216, 217, 218, 200, 203, 9, 218, 223, 219, 224, 225 };
//std::vector<std::string> SendToArcadeString = { "Tutorial", "Golf", "Flightschool", "Darts", "Badlands", "Go Go Space Monkey", "qub3d", "camhedz", "golf", "Flightschool", "Darts", "Badlands", "spacemonkey", "wizards_ruin", "qub3d", "camhedz" };//, "Start Darts",  "Gunslinger", "Wizards Ruin"

extern std::array<int, 9> SendToArcadeEvent;
extern std::vector<std::string> SendToArcadeString;
extern std::uint64_t GetSpoofedSender();

namespace RemoteMenuVars
{
	struct Vars
	{
		int m_invite;
		int m_mission;
		int m_msgs;
		int m_moneyamount;
		int m_sendtoarcade;
		int m_moneymsgs;
	};

	extern ScrollStruct<int> invites[6];
	extern ScrollStruct<int> missions[6];
	extern ScrollStruct<int> msgs[10];
	extern ScrollStruct<int> moneyamount[8];
	extern ScrollStruct<int> moneymsgs[3];

	void JoinCeo(SPlayer& player);
	void CeoMoneyvoid(SPlayer& player);
	void NonHostKick(SPlayer& player);
	void KickToSingleplayer(SPlayer& player);
	void CEOKick(SPlayer& player);
	void CEOBan(SPlayer& player);
	void InfiniteLoadingScreen(SPlayer& player);
	void Invite(SPlayer& player, int index);
	void GOTR(SPlayer& player);
	//void SENDBOUNTY(SPlayer& player);
	void GNeverWanted(SPlayer& player);
	void GCopsTurnBlindEye(SPlayer& player);
	void Friendly(SPlayer& player);
	void Helpful(SPlayer& player);
	void BadRep(SPlayer& player);
	void RBadSport(SPlayer& player);
	void BadSport(SPlayer& player);
	void SoundSpam(SPlayer& player);
	void moneytoAll25k();
	void moneytoAll();
	//void bountyAll();
	//void SendToArcadeAll();
	void DisplaySpectatingMessage(SPlayer& player);
	//void TransactionSpam(SPlayer& player);
	void WantedLevelRP(SPlayer& player);
	void FaceCameraForward(SPlayer& player);
}

//namespace spoofsender
//{
//	extern std::uint64_t GetSpoofedSender();
//}