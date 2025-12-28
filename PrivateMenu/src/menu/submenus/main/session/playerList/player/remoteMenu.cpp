#include "stdafx.h"
#include "remoteMenu.h"
#include "../playerMenu.h"
#include <thread>
#include <chrono>
#include <iostream>
#include <ratio>

#include <iostream>
#include <string>
#include <cstring>

#include <windows.h>
#include <cstdio>
#include <stdio.h>
#include <memory>
#include <array>

using namespace RemoteMenuVars;

int Time_Send_OTR;
int isme_R = 0;
void myid_R()
{
	for (int i = 0; i < 32; i++)
	{
		if (PLAYER::GetPlayerPedScriptIndex(i) == PLAYER::PlayerPedId()) {
			isme_R = i;
		}
	}
}

std::string vectorToString(const std::vector<std::string>& vec) {
	std::string result;
	for (const auto& str : vec) {
		result += str;
	}
	return result;
}

int SendToArcadePosition = 0;
std::array<int, 9> SendToArcadeEvent = { 20, 200, 203, 9, 218, 223, 219, 224, 225 };
std::vector<std::string> SendToArcadeString = { "Tutorial", "Golf", "Flightschool", "Darts", "Badlands", "SpaceMonkey", "wizard", "qub3d", "camhedz" };//, "Start Darts",  "Gunslinger", "Wizards Ruin"
std::uint64_t GetSpoofedSender()
{
	return (std::uint64_t)(0xFFFFFF00 | GetSelectedPlayer().m_id);
}

namespace RemoteMenuVars {
	Vars vars;

	ScrollStruct<int> invites[] = {
		TranslationString("Yacht", true), 1,
		TranslationString("Office", true), 2,
		TranslationString("Clubhouse", true), 3,
		TranslationString("Office garage", true), 6,
		TranslationString("Auto shop", true), 7,
		TranslationString("Apartment", true), 0
	};

	ScrollStruct<int> missions[] = {
		TranslationString("Weather Mission", true), 0,
		TranslationString("Exit Strat Mission", true), 2,
		TranslationString("Cover Blown Mission", true), 4,
		TranslationString("Mole Hunt Mission", true), 5,
		TranslationString("Data Breach Mission", true), 6,
		TranslationString("Work Dispute Mission", true), 7
	};

	ScrollStruct<int> msgs[] = {
		TranslationString("Armorerd truck", true), 1584445674, // 1.46 = -130461309
		TranslationString("Easy way out", true), -248473985, // 1.46 = 554851531
		TranslationString("Smuggler Plane", true), 867265021, // 1.46 = -53425260
		TranslationString("You have entered the .", true), -1105658240, // 1.46 = 1369534593
		TranslationString("You develiered a bag of cash", true), 1582222113, // 1.46 = -957727376
		TranslationString("Mugger $1", true), 771350006, // 1.46 = -210487359
		TranslationString("Added to your wanted level", true), -53170297, // 1.46 = 1723217930
		TranslationString("Off the radar", true), 1380034405, // 1.46 = -1476055326
		TranslationString("The king", true), 1219422932, // 1.46 = -89603292
		TranslationString("Revealed all players", true), 1532262544 // 1.46 = 650772739

	};

	ScrollStruct<int> moneyamount[] = {
		TranslationString("$1", true), 1,
		TranslationString("$10000", true), 10000,
		TranslationString("$1000000", true), 1000000,
		TranslationString("$100000000", true), 100000000,
		TranslationString("$999999999", true), 999999999,
		TranslationString("$2147483647", true), 2147483647,
		TranslationString("$1337", true), 1337,
		TranslationString("$69", true), 69
	};


	ScrollStruct<int> sendarcade[] = {
		TranslationString("tutorial", true), 20,
		TranslationString("golf", true), 193,
		TranslationString("Race And Chase", true), 210,
		TranslationString("Start Badlands Revenge II", true), 211,
		TranslationString("wizzard ruin", true), 212,
		TranslationString("Go Go Space Monkey", true), 216,
		TranslationString("qub3d", true), 217,
		TranslationString("camhedz", true), 218
	};


	ScrollStruct<int> moneymsgs[] = {
		TranslationString("Banked money", true), -1695772783, // 1.46 = -1550586884
		TranslationString("Stolen money", true), 1014468925, // 1.46 = -1432462772
		TranslationString("Removed money", true), 1207028646 // 1.46 = 2110027654
	};

	void NonHostKick(SPlayer& player) {
		NETWORK::NetworkSessionKickPlayer(player.m_id);
		Natives::ObfuscatedTriggerScriptEvent({ SCRIPTEVENTS::NONHOSTKICK1, player.m_id, 48 }, 3, player.m_id);
		Natives::ObfuscatedTriggerScriptEvent({ SCRIPTEVENTS::NONHOSTKICK2, player.m_id }, 2, player.m_id);
		Natives::ObfuscatedTriggerScriptEvent({ SCRIPTEVENTS::NONHOSTKICK3, player.m_id }, 2, player.m_id);
		Natives::ObfuscatedTriggerScriptEvent({ SCRIPTEVENTS::NONHOSTKICK4, player.m_id }, 2, player.m_id);
		Natives::ObfuscatedTriggerScriptEvent({ SCRIPTEVENTS::NONHOSTKICK5, player.m_id }, 2, player.m_id);
		Natives::ObfuscatedTriggerScriptEvent({ 1953937033, player.m_id, 0 }, 3, player.m_id);
		Natives::ObfuscatedTriggerScriptEvent({ 3353227751, player.m_id, 0 }, 3, player.m_id);
	}

	void KickToSingleplayer(SPlayer& player) {
		NETWORK::NetworkSessionKickPlayer(player.m_id);
		Natives::ObfuscatedTriggerScriptEvent({ SCRIPTEVENTS::KICKTOSP1, player.m_id, 1 }, 3, player.m_id);
		Natives::ObfuscatedTriggerScriptEvent({ SCRIPTEVENTS::KICKTOSP2, player.m_id }, 2, player.m_id);
		Natives::ObfuscatedTriggerScriptEvent({ SCRIPTEVENTS::KICKTOSP3, player.m_id, 0 }, 3, player.m_id);
		Natives::ObfuscatedTriggerScriptEvent({ SCRIPTEVENTS::NONHOSTKICK3, player.m_id, 0 }, 3, player.m_id);
		Natives::ObfuscatedTriggerScriptEvent({ SCRIPTEVENTS::NONHOSTKICK4, player.m_id, 0 }, 3, player.m_id);
		Natives::ObfuscatedTriggerScriptEvent({ SCRIPTEVENTS::NONHOSTKICK6, player.m_id, 0 }, 3, player.m_id);
		Natives::ObfuscatedTriggerScriptEvent({ 1953937033, player.m_id, 0 }, 3, player.m_id);
		Natives::ObfuscatedTriggerScriptEvent({ 2870072008, player.m_id, 0 }, 3, player.m_id);
	}

	void CEOKick(SPlayer& player) {
		Natives::TriggerScriptEvent({ SCRIPTEVENTS::CEOKICK, player.m_id, 1, 5 }, 4, player.m_id); // 585981075
	}

	void CEOBan(SPlayer& player) {
		Natives::TriggerScriptEvent({ SCRIPTEVENTS::CEOBAN, player.m_id, 2, 1 }, 4, player.m_id); // 1318668309
	}

	void InfiniteLoadingScreen(SPlayer& player) {
		Natives::TriggerScriptEvent({ SCRIPTEVENTS::ECLIPSETELEPORT, player.m_id, 0, 0 }, 4, player.m_id); // -328868154
	}

	void Invite(SPlayer& player, int index) {
		Natives::TriggerScriptEvent({ SCRIPTEVENTS::INVITE, player.m_id, invites[index].m_result }, 3, player.m_id); // 729971264
	}


	void GOTR(SPlayer& player) {
		///*Time_Send_OTR = timeGetTime();
		//if ((timeGetTime() - Time_Send_OTR) > 5000)
		//{*/
		//DWORD ticks = GetTickCount64();
		//DWORD milliseconds = ticks % 1000;
		//ticks /= 1000;
		//DWORD seconds = ticks % 60;
		////ticks /= 60;
		////DWORD minutes = ticks % 60;
		////ticks /= 60;
		////DWORD hours = ticks; // may exceed 24 hours.
		//		/*int getTimer = TIME::GET_MILLISECONDS_PER_GAME_MINUTE();*/
		//int getTimer = seconds;
		//if (getTimer % 9 == 0)
		//{
		static int TIMER[32];
		Utils::DoTimedFunction(&TIMER[player.m_id], 300, [&] {
			//Natives::TriggerScriptEvent({ Freemode_Give_Off_The_Radar, GetSelectedPlayer().m_id, NETWORK::GetNetworkTime() + 0x3C, NETWORK::GetNetworkTime() + 0x3C, 1, 1, globalHandle(NeverWanted1).At(GetSelectedPlayer().m_id, NeverWanted2).At(NeverWanted3).As<int>() }, 7, GetSelectedPlayer().m_id);
			//Natives::TriggerScriptEvent({ Freemode_Give_Off_The_Radar, GetSelectedPlayer().m_id, NETWORK::GetNetworkTime() + 0x3C, NETWORK::GetNetworkTime() + 0x3C, 1, 1, globalHandle(NeverWantedGlobal[0]).At(GetSelectedPlayer().m_id, NeverWantedGlobal[1]).At(NeverWantedGlobal[2]).As<int>() }, 7, GetSelectedPlayer().m_id);
			Natives::TriggerScriptEvent({ Freemode_Give_Off_The_Radar, player.m_id, NETWORK::GetNetworkTime() + 0x3C, NETWORK::GetNetworkTime() + 0x3C, 1, 1, Global::Global(NeverWantedGlobal[0]).At(player.m_id, NeverWantedGlobal[1]).At(NeverWantedGlobal[2]).As<int>() }, 7, player.m_id);

			//Time_Send_OTR = GetTickCount64();
		//}
		});
	}
	int interval = 300;
	void JoinCeo(SPlayer& player)
	{
		//DWORD ticks = GetTickCount64();
		//DWORD milliseconds = ticks % 1000;
		//ticks /= 1000;
		//DWORD seconds = ticks % 60;
		////ticks /= 60;
		////DWORD minutes = ticks % 60;
		////ticks /= 60;
		////DWORD hours = ticks; // may exceed 24 hours.
		//		/*int getTimer = TIME::GET_MILLISECONDS_PER_GAME_MINUTE();*/
		//int getTimer = seconds;
		//if (getTimer % 9 == 0)
		//{
		static int TIMER;
		//Utils::DoTimedFunction(&TIMER[player.m_id], 300, [&] {
		Utils::DoTimedFunction(&TIMER, 9000, [&] {
			//auto ceoid = globalHandle(JoinCEOGlobal[0]).At(GetSelectedPlayer().m_id, JoinCEOGlobal[1]).At(JoinCEOGlobal[2]).As<int>();
			auto ceoid = globalHandle::globalHandle(JoinCEOGlobal[0]).At(GetSelectedPlayer().m_id, JoinCEOGlobal[1]).At(JoinCEOGlobal[2]).As<int>();
			if (ceoid != -1)
				/*globalHandle(JoinCEOGlobal[0]).At(PlayerId, JoinCEOGlobal[1]).At(JoinCEOGlobal[2]).As<int>() = ceoid;*/
				globalHandle::globalHandle(JoinCEOGlobal[0]).At(GetSelectedPlayer().m_id, JoinCEOGlobal[1]).At(JoinCEOGlobal[2]).As<int>() = ceoid;
			else
			{
			}
			});
		}

	void CeoMoneyvoid(SPlayer& player)
	{
		//DWORD ticks = GetTickCount64();
		//DWORD milliseconds = ticks % 1000;
		//ticks /= 1000;
		//DWORD seconds = ticks % 60;
		////ticks /= 60;
		////DWORD minutes = ticks % 60;
		////ticks /= 60;
		////DWORD hours = ticks; // may exceed 24 hours.
		//		/*int getTimer = TIME::GET_MILLISECONDS_PER_GAME_MINUTE();*/
		//int getTimer = seconds;
		//if (getTimer % 9 == 0)
		//{
		static int TIMER;
		Utils::DoTimedFunction(&TIMER, interval, [&] {
			//auto ceoid = globalHandle(JoinCEOGlobal[0]).At(GetSelectedPlayer().m_id, JoinCEOGlobal[1]).At(JoinCEOGlobal[2]).As<int>();
			//auto ceoid = Global(JoinCEOGlobal[0]).At(GetSelectedPlayer().m_id, JoinCEOGlobal[1]).At(JoinCEOGlobal[2]).As<int>();

			/*for (int i = 0; i < 32; i++)
			{*/
				unsigned int playerBit = (1 << GetSelectedPlayer().m_id);
				uint64_t args1[8] =
				{
					CEOMoneyGlobal[0], GetSelectedPlayer().m_id, 10000, CEOMoneyGlobal[1], 1, //PlayerID

					Global(NeverWantedGlobal[0]).At(1).At(GetSelectedPlayer().m_id * NeverWantedGlobal[1]).At(NeverWantedGlobal[2]).As<int>(),
					Global(BountyTransaction).At(9).As<int>(),
					Global(BountyTransaction).At(10).As<int>()
				};
				Hooked::trigger_script_event(1, args1, 8, 1 << GetSelectedPlayer().m_id, CEOMoneyGlobal[0]);
				//Natives::TriggerScriptEvent({ CEOMoneyGlobal[0], i, 30000, CEOMoneyGlobal[1], 1, Global::Global(NeverWantedGlobal[0]).At(1).At(i * NeverWantedGlobal[1]).At(NeverWantedGlobal[2]).As<int>(), Global::Global(BountyTransaction).At(9).As<int>(), Global::Global(BountyTransaction).At(10).As<int>() }, 8, player.m_id);

			//}

			});
	}

	/*}*/

	/*void SENDBOUNTY(SPlayer& player) {
		static int TIMER[32];
		Utils::DoTimedFunction(&TIMER[player.m_id], 300, [&] {
			Natives::TriggerScriptEvent({ BountyEvent, PLAYER::PlayerId(), reinterpret_cast<int>(&player), 1, 10000, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			Global(BountyTransaction).At(9).As<int>(),
			Global(BountyTransaction).At(10).As<int>() }, 7, player.m_id);
			});
	}*/

	//void m_features::CEOMoney2()
	//{
	//	DWORD ticks = GetTickCount64();
	//	DWORD milliseconds = ticks % 1000;
	//	ticks /= 1000;
	//	DWORD seconds = ticks % 60;
	//	//ticks /= 60;
	//	//DWORD minutes = ticks % 60;
	//	//ticks /= 60;
	//	//DWORD hours = ticks; // may exceed 24 hours.
	//			/*int getTimer = TIME::GET_MILLISECONDS_PER_GAME_MINUTE();*/
	//	int getTimer = seconds;
	//	if (getTimer % 10 == 0)
	//	{
	//		for (int i = 0; i < 32; i++)
	//		{
	//			unsigned int playerBit = (1 << i);
	//			uint64_t args1[8] =
	//			{
	//				75579707, i, 30000, 639967857, 1, //PlayerID
	//				globalHandle(NeverWanted1).At(1).At(i * NeverWanted2).At(NeverWanted3).As<int>(),
	//				globalHandle(BountyTransaction).At(9).As<int>(),
	//				globalHandle(BountyTransaction).At(10).As<int>()
	//			};
	//			Hooking::trigger_script_event(1, args1, 8, 1 << i);

	//		}
	//	}
	//	if (globalHandle(DisableErrorScreenGlobal[0]).As<int>() != 0)
	//		globalHandle(DisableErrorScreenGlobal[0]).As<int>() = 0;
	//}
	//void SendToArcadeAll()
	//{
	//	SPlayer m_players[33];
	//	//myid_R();
	//	for (int i = 0; i <= 32; i++)
	//	{
	//		SPlayer& player = m_players[i];

	//	/*myid_R();
	//	for (int i = 0; i <= 32; i++)
	//	{*/
	//	//try {
	//		/*DWORD ticks = GetTickCount64();
	//		DWORD milliseconds = ticks % 1000;
	//		ticks /= 1000;
	//		DWORD seconds = ticks % 60;
	//		int getTimer = seconds;
	//		if (getTimer % 1 == 0)
	//		{*/
	//		/*int Handle = PLAYER::GetPlayerPedScriptIndex(player.m_id);

	//		*/
	//	//	if (i != isme_R)
	//	////if (GetLocalPlayer().m_id != player.m_id)
	//	//{
	//		int eventValue = SendToArcadeEvent[SendToArcadePosition];
	//		//unsigned int playerBit = (1 << i);
	//		const size_t arg_count = 26;
	//		/*const auto global = *ScriptGlobal(1894573 + 1 + i * 608 + 510).As<std::uint64_t*>();
	//		int64_t args1[25] = { -95341040, PLAYER::PLAYER_ID(), SendToArcadeEvent[SendToArcadePosition], 0, 0, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, global };
	//		int64_t args2[25] = { 1742713914, PLAYER::PLAYER_ID(), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };*/

	//		//const auto global = *ScriptGlobal::ScriptGlobal(NeverWantedGlobal[0] + 1 + player.m_id * NeverWantedGlobal[1] + NeverWantedGlobal[2]).As<std::uint64_t*>();//1895156
	//		/*int64_t args1[arg_count] = { eRemoteEvent::StartScriptBegin, PLAYER::PLAYER_ID(), playerBit, static_cast<int64_t>(eventValue), 0, 0, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, global };
	//		int64_t args2[arg_count] = { eRemoteEvent::StartScriptProceed, PLAYER::PLAYER_ID(), playerBit, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };*/
	//		//int64_t args1[arg_count] = { eRemoteEvent::StartScriptBegin, player.m_id, player.m_id, static_cast<int64_t>(eventValue), 0, 0, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, global };
	//		//int64_t args2[arg_count] = { eRemoteEvent::StartScriptProceed, player.m_id, player.m_id, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	//		const auto global = *ScriptGlobal(NeverWantedGlobal[0] + 1 + player.m_id * NeverWantedGlobal[1] + NeverWantedGlobal[2]).As<std::uint64_t*>();//1895156, 609, 511
	//		int64_t args1[arg_count] = {
	//			(int64_t)eRemoteEvent::StartScriptBegin,
	//			//(int)eRemoteEvent::StartScriptBegin,
	//			(int64_t)player.m_id,
	//			/*static_cast<int64_t>(Missile::GetSpoofedSender()),*/
	//			//static_cast<int64_t>(playerBit),
	//			(int64_t)player.m_id,
	//			(int64_t)SendToArcadeEvent[SendToArcadePosition],
	//			0, 0, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	//			//static_cast<int64_t>(-1),
	//			(int64_t)-1,
	//			0, 0, 0, 0, 0,
	//			/*static_cast<int64_t>(global)*/
	//				(int64_t)global
	//		};
	//		int64_t args2[arg_count] = {
	//			/*static_cast<int64_t>(eRemoteEvent::StartScriptProceed),
	//			static_cast<int64_t>(Missile::GetSpoofedSender()),*/
	//				(int64_t)eRemoteEvent::StartScriptProceed,
	//			(int64_t)player.m_id,
	//			//static_cast<int64_t>(playerBit),
	//			player.m_id,
	//			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	//		};
	//		g_GameFunctions->m_trigger_script_event(1, args1, arg_count, 1 << player.m_id, (int)eRemoteEvent::StartScriptBegin);
	//		g_GameFunctions->m_trigger_script_event(1, args2, arg_count, 1 << player.m_id, (int)eRemoteEvent::StartScriptProceed);
	//		//notifyMap("Send to Arcade");
	//	//}
	//	/*UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	//	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("~r~send to Arcade");
	//	UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_STRIPPER_CHEETAH", "CHAR_STRIPPER_CHEETAH", 1, 8, "~w~Thunder-Menu\n", "~w~Send to Arcade Player\r\n", 1, "~w~Thunder Menu\n ~w~Send to Arcade Player\r\n", 9, 1);
	//	UI::_DRAW_NOTIFICATION_3(FALSE, FALSE);*/
	//	/*}
	//	}*/
	//	/*catch (...) {
	//		return;
	//	}
	//	{
	//		if (i == 31)
	//		{
	//			break;
	//		}
	//	}*/
	//	}
	//}
	//void bountyAll()
	//{
	//	SPlayer m_players[33];
	//	//myid_R();
	//	for (int i = 0; i <= 32; i++)
	//	{
	//		SPlayer& player = m_players[i];
	//	//
	//	///*int Handle = PLAYER::GetPlayerPedScriptIndex(i);
	//	//if (Handle != isme2)*/
	//	//if (i != isme_R)
	//	//{
	//	//Player reyalP = PLAYER::GetPlayerPedScriptIndex(player.m_id);

	//		uint64_t pBTY[23] =
	//		{
	//			eRemoteEvent::BountyEvent, player.m_id, -1, player.m_id, 1, 10000, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	//			globalHandle(eRemoteEvent::BountyTransaction).Add(9).As<int>(),
	//			globalHandle(eRemoteEvent::BountyTransaction).Add(10).As<int>()
	//		};
	//		g_GameFunctions->m_trigger_script_event(1, (int64_t*)pBTY, 23, -1, (int)eRemoteEvent::BountyEvent);
	//	//}
	//	}
	//}

	/*std::uint64_t spoofsender::GetSpoofedSender()
	{
		return (std::uint64_t)(0xFFFFFF00 | GetSelectedPlayer().m_id);
	}*/
	//void PutOnBike()
	//{
	//	PLAYER::_ExpandWorldLimits(FLT_MAX, FLT_MAX, FLT_MAX);
	//	if (PED::IsPedInAnyVehicle(GetSelectedPlayer().m_id, false))
	//		BRAIN::ClearPedTasksImmediately(GetSelectedPlayer().m_id);
	//	long long signedValue = static_cast<long long>(spoofsender::GetSpoofedSender());
	//	Natives::TriggerScriptEvent({ MCTeleport, signedValue, 1, 32, NETWORK::NetworkHashFromPlayerHandle(GetSelectedPlayer().m_id), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 37, GetSelectedPlayer().m_id);
	//}

	void SendToArcadePlayer()
	{
		//unsigned int playerBit = (1 << Features::Online::selectedPlayer);
				/*const size_t arg_count = 25;
				const auto global = *ScriptGlobal(1894573 + 1 + Features::Online::selectedPlayer * 608 + 510).As<std::uint64_t*>();
				int64_t args1[25] = { -95341040, PLAYER::PLAYER_ID(), SendToArcadeEvent[SendToArcadePosition], 0, 0, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, global};
				int64_t args2[25] = { 1742713914, PLAYER::PLAYER_ID(), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

				g_GameFunctions->m_trigger_script_event(1, args1, arg_count, 1 << Features::Online::selectedPlayer);
				g_GameFunctions->m_trigger_script_event(1, args2, arg_count, 1 << Features::Online::selectedPlayer);*/
				/*const size_t arg_count = 25;*/
		const size_t arg_count = 26;
		//const auto global = *ScriptGlobal(NeverWantedGlobal[0] + 1 + Features::Online::selectedPlayer * NeverWantedGlobal[1] + NeverWantedGlobal[2]).As<std::uint64_t*>();//1895156, 609, 511
		//int64_t args1[25] = { -366707054, PLAYER::PLAYER_ID(), SendToArcadeEvent[SendToArcadePosition], 0, 0, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, global };
		//int64_t args2[25] = { 1757622014, PLAYER::PLAYER_ID(), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
		const auto global = *ScriptGlobal(NeverWantedGlobal[0] + 1 + GetSelectedPlayer().m_id * NeverWantedGlobal[1] + NeverWantedGlobal[2]).As<std::uint64_t*>();//1895156, 609, 511
		//int64_t args1[arg_count] = { (int64_t)eRemoteEvent::StartScriptBegin, Missile::GetSpoofedSender(), playerBit, static_cast<int64_t>(SendToArcadeEvent[SendToArcadePosition]), 0, 0, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, (int64_t)(int)-1, 0, 0, 0, 0, 0, static_cast<int64_t>(global)};
		int64_t args1[arg_count] = {
			(int64_t)eRemoteEvent::StartScriptBegin,
			//(int)eRemoteEvent::StartScriptBegin,
			(int64_t)GetSelectedPlayer().m_id,
			/*static_cast<int64_t>(Missile::GetSpoofedSender()),*/
			//static_cast<int64_t>(playerBit),
			(int64_t)GetSelectedPlayer().m_id,
			(int64_t)SendToArcadeEvent[SendToArcadePosition],
			0, 0, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			//static_cast<int64_t>(-1),
			(int64_t)-1,
			0, 0, 0, 0, 0,
			/*static_cast<int64_t>(global)*/
				(int64_t)global
		};
		//RtlSecureZeroMemory(args1, sizeof(args1));
		//args1[0] = (int)eRemoteEvent::StartScriptBegin;
		//args1[1] = static_cast<int64_t>(Missile::GetSpoofedSender());
		////args1[2] = static_cast<int64_t>(playerBit);
		//args1[2] = Features::Online::selectedPlayer;
		//args1[3] = SendToArcadeEvent[SendToArcadePosition];
		//args1[4] = 0;
		//args1[5] = 0;
		//args1[6] = 48;
		//args1[7] = 0;
		//args1[8] = 0;
		//args1[9] = 0;
		//args1[10] = 0;
		//args1[11] = 0;
		//args1[12] = 0;
		//args1[13] = 0;
		//args1[14] = 0;
		//args1[15] = 0;
		//args1[16] = 0;
		//args1[17] = 0;
		//args1[18] = 0;
		//args1[19] = -1;
		//args1[20] = 0;
		//args1[21] = 0;
		//args1[22] = 0;
		//args1[23] = 0;
		//args1[24] = 0;
		//args1[25] = static_cast<int64_t>(global);

		int64_t args2[arg_count] = {
			/*static_cast<int64_t>(eRemoteEvent::StartScriptProceed),
			static_cast<int64_t>(Missile::GetSpoofedSender()),*/
				(int64_t)eRemoteEvent::StartScriptProceed,
			(int64_t)GetSelectedPlayer().m_id,
			//static_cast<int64_t>(playerBit),
			GetSelectedPlayer().m_id,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		};


		//RtlSecureZeroMemory(args2, sizeof(args2));
		//args2[0] = (int)eRemoteEvent::StartScriptBegin;
		//args2[1] = static_cast<int64_t>(Missile::GetSpoofedSender());
		////args2[2] = static_cast<int64_t>(playerBit);
		//args2[2] = Features::Online::selectedPlayer;
		//args2[3] = 0;
		//args2[4] = 0;
		//args2[5] = 0;
		//args2[6] = 0;
		//args2[7] = 0;
		//args2[8] = 0;
		//args2[9] = 0;
		//args2[10] = 0;
		//args2[11] = 0;
		//args2[12] = 0;
		//args2[13] = 0;
		//args2[14] = 0;
		//args2[15] = 0;
		//args2[16] = 0;
		//args2[17] = 0;
		//args2[18] = 0;
		//args2[19] = 0;
		//args2[20] = 0;
		//args2[21] = 0;
		//args2[22] = 0;
		//args2[23] = 0;
		//args2[24] = 0;
		//args2[25] = 0;

		//g_GameFunctions->m_trigger_script_event(1, args1, arg_count, 1 << GetSelectedPlayer().m_id, (int)eRemoteEvent::StartScriptBegin);
		//g_GameFunctions->m_trigger_script_event(1, args2, arg_count, 1 << GetSelectedPlayer().m_id, (int)eRemoteEvent::StartScriptProceed);
		/*memset(args1, 0, sizeof(args1));
		memset(args2, 0, sizeof(args2));*/
		//trigger_script_event
		g_GameFunctions->m_trigger_script_event(1, args1, arg_count, 1 << GetSelectedPlayer().m_id, (int)eRemoteEvent::StartScriptBegin);
		g_GameFunctions->m_trigger_script_event(1, args2, arg_count, 1 << GetSelectedPlayer().m_id, (int)eRemoteEvent::StartScriptProceed);

		//Natives::TriggerScriptEvent({ eRemoteEvent::StartScriptBegin, GetSelectedPlayer().m_id, GetSelectedPlayer().m_id, SendToArcadeEvent[vars.m_sendtoarcade], 0, 0, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0 }, 26, GetSelectedPlayer().m_id);
		//Natives::TriggerScriptEvent({ eRemoteEvent::StartScriptProceed, GetSelectedPlayer().m_id, GetSelectedPlayer().m_id, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 26, GetSelectedPlayer().m_id);

	}


	//spoofsender::GetSpoofedSender()
	//void SendToArcadePlayer()
	//{
	//	//const size_t arg_count = 25;
	//	const size_t arg_count = 26;
	//	/*const auto global = *ScriptGlobal(1894573 + 1 + GetSelectedPlayer().m_id * 608 + 510).As<std::uint64_t*>();
	//	long long signedValue = static_cast<long long>(global);
	//	Natives::TriggerScriptEvent({ -95341040, PlayerId, SendToArcadeEvent[vars.m_sendtoarcade], 0, 0, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, signedValue }, 25, GetSelectedPlayer().m_id);
	//	Natives::TriggerScriptEvent({ 1742713914, PlayerId, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 25, GetSelectedPlayer().m_id);*/
	//	//const auto global = *ScriptGlobal(1895156 + 1 + GetSelectedPlayer().m_id * 609 + 511).As<std::uint64_t*>();
	//	//long long signedValue = static_cast<long long>(global);
	//	//Natives::TriggerScriptEvent({ -366707054, PlayerId, SendToArcadeEvent[vars.m_sendtoarcade], 0, 0, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, signedValue }, 25, GetSelectedPlayer().m_id);
	//	//Natives::TriggerScriptEvent({ 1757622014, PlayerId, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 25, GetSelectedPlayer().m_id);
	//	const auto global = *ScriptGlobal(NeverWantedGlobal[0] + 1 + GetSelectedPlayer().m_id * NeverWantedGlobal[1] + NeverWantedGlobal[2]).As<std::uint64_t*>();
	//	long long signedValue = static_cast<long long>(global);
	//	Natives::TriggerScriptEvent({ eRemoteEvent::StartScriptBegin, GetSelectedPlayer().m_id, GetSelectedPlayer().m_id, SendToArcadeEvent[vars.m_sendtoarcade], 0, 0, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, signedValue }, 26, GetSelectedPlayer().m_id);
	//	Natives::TriggerScriptEvent({ eRemoteEvent::StartScriptProceed, GetSelectedPlayer().m_id, GetSelectedPlayer().m_id, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 26, GetSelectedPlayer().m_id);
	//
	//}

#define Freemode_Give_NoCops Sudoyer
	void GNeverWanted(SPlayer& player) {
		///*static int TIMER[32];
		//Utils::DoTimedFunction(&TIMER[player.m_id], 300, [&] { */
		//DWORD ticks = GetTickCount64();
		//DWORD milliseconds = ticks % 1000;
		//ticks /= 1000;
		//DWORD seconds = ticks % 60;
		////ticks /= 60;
		////DWORD minutes = ticks % 60;
		////ticks /= 60;
		////DWORD hours = ticks; // may exceed 24 hours.
		//		/*int getTimer = TIME::GET_MILLISECONDS_PER_GAME_MINUTE();*/
		//int getTimer = seconds;
		//if (getTimer % 9 == 0)
		//{
		static int TIMER005[32];
		Utils::DoTimedFunction(&TIMER005[player.m_id], interval, [&] {
			Natives::TriggerScriptEvent({ Freemode_Give_NoCops, player.m_id, NETWORK::GetNetworkTime() + 0x3C, NETWORK::GetNetworkTime() + 0x3C, 1, 1, Global(NeverWantedGlobal[0]).At(player.m_id, NeverWantedGlobal[1]).At(NeverWantedGlobal[2]).As<int>() }, 7, player.m_id);
			//Natives::TriggerScriptEvent({ Freemode_Give_NoCops, GetSelectedPlayer().m_id, NETWORK::GetNetworkTime() + 0x3C, NETWORK::GetNetworkTime() + 0x3C, 1, 1, globalHandle(NeverWantedGlobal[0]).At(GetSelectedPlayer().m_id, NeverWantedGlobal[1]).At(NeverWantedGlobal[2]).As<int>() }, 7, GetSelectedPlayer().m_id);
			//Natives::TriggerScriptEvent({ SCRIPTEVENTS::GNEVERWANTED, GetSelectedPlayer().m_id, *ScriptGlobal::ScriptGlobal(Globals::REMOTE_BASE).Add(GetSelectedPlayer().m_id, Globals::REMOTE_SIZE).Add(Globals::REMOTE_OFFSET).As<int*>() }, 3, GetSelectedPlayer().m_id);
			});
		//}
	}

	void GCopsTurnBlindEye(SPlayer& player) {
		static int TIMER[32];
		Utils::DoTimedFunction(&TIMER[player.m_id], interval, [&] {
			Natives::TriggerScriptEvent({ SCRIPTEVENTS::GCOPSTURNBLINDEYE, player.m_id, NETWORK::GetNetworkTime(), NETWORK::GetNetworkTime(), 1, 1, Global(Globals::REMOTE_BASE).At(player.m_id, Globals::REMOTE_SIZE).At(Globals::REMOTE_OFFSET).As<int>() }, 7, player.m_id);
			//int handle = globalHandle(1625435).At(target, 560).At(491).As<int>();
			//int handle1 = globalHandle(2524719).At(4545).As<int>();
		});
	}

	void Friendly(SPlayer& player) {
		Backend::IncrementPlayerStat(player.m_id, Utils::GetHashKey("MPPLY_FRIENDLY"), 9999);
	}

	void Helpful(SPlayer& player) {
		Backend::IncrementPlayerStat(player.m_id, Utils::GetHashKey("MPPLY_HELPFUL"), 9999);
	}

	void RBadSport(SPlayer& player) {
		static int TIMER[32];
		Utils::DoTimedFunction(&TIMER[player.m_id], 200, [&] {
			Backend::IncrementPlayerStat(player.m_id, Utils::GetHashKey("MPPLY_HELPFUL"), 99999);
			Backend::IncrementPlayerStat(player.m_id, Utils::GetHashKey("MPPLY_FRIENDLY"), 99999);
		});
	}

	void BadRep(SPlayer& player) {
		Backend::IncrementPlayerStat(player.m_id, Utils::GetHashKey("MPPLY_BECAME_CHEATER_NUM"), 10);
		Backend::IncrementPlayerStat(player.m_id, Utils::GetHashKey("MPPLY_GRIEFING"), 10);
		Backend::IncrementPlayerStat(player.m_id, Utils::GetHashKey("MPPLY_OFFENSIVE_LANGUAGE"), 10);
		Backend::IncrementPlayerStat(player.m_id, Utils::GetHashKey("MPPLY_OFFENSIVE_UGC"), 10);
	}

	void BadSport(SPlayer& player) {
		static int TIMER[32];
		Utils::DoTimedFunction(&TIMER[player.m_id], 300, [&] {
			Backend::IncrementPlayerStat(player.m_id, Utils::GetHashKey("MPPLY_BECAME_CHEATER_NUM"), 99999);
			Backend::IncrementPlayerStat(player.m_id, Utils::GetHashKey("MPPLY_GRIEFING"), 99999);
			Backend::IncrementPlayerStat(player.m_id, Utils::GetHashKey("MPPLY_OFFENSIVE_LANGUAGE"), 99999);
			Backend::IncrementPlayerStat(player.m_id, Utils::GetHashKey("MPPLY_OFFENSIVE_UGC"), 99999);
		});
	}
	void moneytoAll25k()
	{

		for (int i = 0; i <= 32; i++)
		{

			if (ENTITY::DoesEntityExist(Hooked::get_player_ped(i)))//player.m_ped
			{
				/*Vector3 coords = ENTITY::GetEntityCoords(Hooked::get_player_ped(i), false);
				*ScriptGlobal::ScriptGlobal(moneydropglobal1 + 3).As<float*>() = coords.x;
				*ScriptGlobal::ScriptGlobal(moneydropglobal1 + 4).As<float*>() = coords.y;
				*ScriptGlobal::ScriptGlobal(moneydropglobal1 + 5).As<float*>() = coords.z;
				*ScriptGlobal::ScriptGlobal(moneydropglobal1 + 1).As<int*>() = 2000;
				*ScriptGlobal::ScriptGlobal(moneydropglobal2 + (1 + *ScriptGlobal::ScriptGlobal(moneydropglobal1).As<int*>() * 85) + 66 + 2).As<int*>() = 2;
				*ScriptGlobal::ScriptGlobal(moneydropglobal3).As<int*>() = 1 << 0;*/
				Vector3 coords = ENTITY::GetEntityCoords(Hooked::get_player_ped(i), false);
				/**ScriptGlobal::ScriptGlobal(moneydropglobal1 + 3).As<float*>() = coords.x;
				*ScriptGlobal::ScriptGlobal(moneydropglobal1 + 4).As<float*>() = coords.y;
				*ScriptGlobal::ScriptGlobal(moneydropglobal1 + 5).As<float*>() = coords.z;
				*ScriptGlobal::ScriptGlobal(moneydropglobal1 + 1).As<int*>() = 2000;
				*ScriptGlobal::ScriptGlobal(moneydropglobal2 + (1 + *ScriptGlobal::ScriptGlobal(moneydropglobal1).As<int*>() * 85) + 66 + 2).As<int*>() = 2;
				*ScriptGlobal::ScriptGlobal(moneydropglobal3).As<int*>() = 1 << 0;*/
				/*script_global global = script_global(MONEY_NETWORK_SPENT_HOLDUPS);
				int index = global.at(5055).as<int>();
				global.at(5056).as<int>() = value;
				global.at(5058).as<float>() = coords.x;
				global.at(5059).as<float>() = coords.y;
				global.at(5060).as<float>() = coords.z;

				script_global(NETWORK_SPENT_CASH_DROP).at(index, 85).at(66).at(2).as<int>() = 2;
				global.at(7).as<int>() = 1 << 1;*/
				Hash poly_bag = HASH::GET_HASH_KEY("p_poly_bag_01_s");
				if (!STREAMING::HasModelLoaded(poly_bag))
					STREAMING::RequestModel(poly_bag);
				ScriptGlobal global = ScriptGlobal(MONEY_NETWORK_SPENT_HOLDUPS);
				/**global.Add(5058).As<float*>() = coords.x;*/
				*global.Add(5073).As<float*>() = coords.x;
				*global.Add(5074).As<float*>() = coords.y;
				*global.Add(5075).As<float*>() = coords.z + 1.f;
				/**global.Add(5059).As<float*>() = coords.y;
				*global.Add(5060).As<float*>() = coords.z + 1.f;*/
				/**global.Add(5056).As<int*>() = 2500;*/
				*global.Add(5071).As<int*>() = 2500;
				*ScriptGlobal(NETWORK_SPENT_CASH_DROP).Add(*global.Add(5070).As<int*>(), 85).Add(66).Add(2).As<int*>() = 2;
				/**ScriptGlobal(NETWORK_SPENT_CASH_DROP).Add(*global.Add(5055).As<int*>(), 85).Add(66).Add(2).As<int*>() = 2;*/
				*global.Add(7).As<int*>() = 1 << 1;
			}
		}
	}
	void moneytoAll()
	{
		//static int TIMER;

		//GetEntityControl()->SimpleRequestModel(-1666779307);
		//int playerId = static_cast<int>(player.m_id);
		/*Utils::DoTimedFunction(&TIMER, vars.standarddropdelay, [&] {*/
			/*if (Global(DisableErrorScreenGlobal[0]).As<int>() != 0)
				Global(DisableErrorScreenGlobal[0]).As<int>() = 0;*/

				//if (ENTITY::DoesEntityExist(PLAYER::GetPlayerPedScriptIndex(playerId)))
				//	/*if (ENTITY::DoesEntityExist(Hooked::get_player_ped(player.m_id)))*/
				//{
				//	Vector3 coords = ENTITY::GetEntityCoords(PLAYER::GetPlayerPedScriptIndex(playerId), false);
				//	/*Vector3 coords = ENTITY::GetEntityCoords(Hooked::get_player_ped(player.m_id), false);*/
				//	*ScriptGlobal::ScriptGlobal(moneydropglobal1 + 3).As<float*>() = coords.x;
				//	*ScriptGlobal::ScriptGlobal(moneydropglobal1 + 4).As<float*>() = coords.y;
				//	*ScriptGlobal::ScriptGlobal(moneydropglobal1 + 5).As<float*>() = coords.z;
				//	*ScriptGlobal::ScriptGlobal(moneydropglobal1 + 1).As<int*>() = 2000;
				//	*ScriptGlobal::ScriptGlobal(moneydropglobal2 + (1 + *ScriptGlobal::ScriptGlobal(moneydropglobal1).As<int*>() * 85) + 66 + 2).As<int*>() = 2;
				//	*ScriptGlobal::ScriptGlobal(moneydropglobal3).As<int*>() = 1 << 0;
				//}
		/*DWORD ticks = GetTickCount64();
		DWORD milliseconds = ticks % 1000;
		ticks /= 1000;
		DWORD seconds = ticks % 60;
		int getTimer = seconds;
		if (getTimer % 1 == 0)
		{*/
		//SPlayer m_players[33];
		//myid_R();
		for (int i = 0; i <= 32; i++)
		{
			//SPlayer& player = m_players[i];
			//	/*if (moneybool1[i])
			//	{*/
			//	Player reyalP = PLAYER::GetPlayerPed(i);
				if (ENTITY::DoesEntityExist(Hooked::get_player_ped(i)))//player.m_ped
				{
					Vector3 coords = ENTITY::GetEntityCoords(Hooked::get_player_ped(i), false);
					*ScriptGlobal::ScriptGlobal(moneydropglobal1 + 3).As<float*>() = coords.x;
					*ScriptGlobal::ScriptGlobal(moneydropglobal1 + 4).As<float*>() = coords.y;
					*ScriptGlobal::ScriptGlobal(moneydropglobal1 + 5).As<float*>() = coords.z;
					*ScriptGlobal::ScriptGlobal(moneydropglobal1 + 1).As<int*>() = 2000;
					*ScriptGlobal::ScriptGlobal(moneydropglobal2 + (1 + *ScriptGlobal::ScriptGlobal(moneydropglobal1).As<int*>() * 85) + 66 + 2).As<int*>() = 2;
					*ScriptGlobal::ScriptGlobal(moneydropglobal3).As<int*>() = 1 << 0;
				}
			}
			/*else
				moneybool1[i] = 0;
		}*/
		//}
		//});
	}
	void SoundSpam(SPlayer& player) {
		Natives::TriggerScriptEvent({ SCRIPTEVENTS::INVITE, player.m_id, 0 }, 3, player.m_id);
	}

	void DisplaySpectatingMessage(SPlayer& player) {
		Natives::TriggerScriptEvent({ SCRIPTEVENTS::SPECTATINGMESSAGE, player.m_id }, 2, player.m_id);
	}

	void FaceCameraForward(SPlayer& player) {
		static int TIMER2[32];
		Utils::DoTimedFunction(&TIMER2[player.m_id], 200, [&] {
			Natives::TriggerScriptEvent({ SCRIPTEVENTS::FACECAMERAFORWARD, player.m_id, SCRIPTEVENTS::FACECAMERAFORWARD2 }, 3, player.m_id);
		});
	}

	void test(SPlayer& player) {
		Natives::TriggerScriptEvent({ 2023259876 }, 1, player.m_id);
		Natives::TriggerScriptEvent({ -2100194653 }, 1, player.m_id);
	}

	void WantedLevelRP(SPlayer& player) {
		PLAYER::ReportCrime(player.m_id, 8, PLAYER::GetWantedLevelThreshold(5));

		static int TIMER2[32];
		Utils::DoTimedFunction(&TIMER2[player.m_id], 2000, [&] {
			Natives::TriggerScriptEvent({ SCRIPTEVENTS::GNEVERWANTED, player.m_id, Global(Globals::REMOTE_BASE).At(player.m_id, Globals::REMOTE_SIZE).At(Globals::REMOTE_OFFSET).As<int>() }, 3, player.m_id);
		});
	}
}

//#define Freemode_Send_to_Island SendToIsland
void RemoteMenu::Init() {
	setParentSubmenu<PlayerMenu>();
	setName("Remote", true, false);

	/*addOption(ButtonOption("Non host kick")
		.addFunction([] { test(GetSelectedPlayer()); })
		.addTooltip("Non host kick").addTranslation());*/

	addOption(ButtonOption("Non host kick")
		.addFunction([] { NonHostKick(GetSelectedPlayer()); })
		.addTooltip("Non host kick").addTranslation());

	addOption(ButtonOption("Kick to single player")
		.addFunction([] {KickToSingleplayer(GetSelectedPlayer()); })
		.addTooltip("Kick to single player").addTranslation());

	addOption(ButtonOption("CEO kick")
		.addFunction([] {CEOKick(GetSelectedPlayer()); })
		.addTooltip("CEO kick").addTranslation());

	addOption(ButtonOption("CEO ban")
		.addFunction([] {CEOBan(GetSelectedPlayer()); })
		.addTooltip("CEO ban").addTranslation());

	addOption(BreakOption("Troll").addTranslation());

	/*addOption(ButtonOption("Infinite loading screen")
		.addFunction([] {InfiniteLoadingScreen(GetSelectedPlayer()); })
		.addTooltip("Infinite loading screen").addTranslation());

	addOption(ToggleOption("Sound spam")
		.addToggle(GetSelectedPlayer().m_soundSpam)
		.addOnUpdate([](ToggleOption* option) {option->addToggle(GetSelectedPlayer().m_soundSpam); })
		.addTranslation()
		.addTooltip("Sound spam"));

#ifdef HARD_DEV

#endif*/

	addOption(ButtonOption("Transaction error")
		.addFunction([] { 
			auto var0 = Global(1895156 + 1 + GetSelectedPlayer().m_id * 609 + 511).As<int>();
			auto var1 = Global(BountyTransaction + 9).As<int>();
			auto var2 = Global(BountyTransaction + 10).As<int>();
		/*auto var0 = Global(1894573 + 1 + GetSelectedPlayer().m_id * 608 + 510).As<int>();
		auto var1 = Global(1923597 + 9).As<int>();*/
		Natives::TriggerScriptEvent({ SCRIPTEVENTS::TRANSACTIONERRORSPAM, GetSelectedPlayer().m_id, 10000, 0, 0, var0, var1, var2 }, 8, GetSelectedPlayer().m_id);
	})
		.addTooltip("This will give the player a transaction error black screen").addTranslation());

	/*addOption(ButtonOption("Face players camera forward")
		.addFunction([] { Natives::TriggerScriptEvent({ SCRIPTEVENTS::FACECAMERAFORWARD, GetSelectedPlayer().m_id, SCRIPTEVENTS::FACECAMERAFORWARD2 }, 3, GetSelectedPlayer().m_id); })
		.addTooltip("Face the players camera forward").addTranslation());

	addOption(ToggleOption("Force players camera forward")
		.addToggle(GetSelectedPlayer().m_facecamera)
		.addOnUpdate([](ToggleOption* option) {option->addToggle(GetSelectedPlayer().m_facecamera); })
		.addTooltip("Force the players camera forward on loop").addTranslation());*/

	addOption(ButtonOption("Gentle kick from vehicle")
		.addFunction([] { Natives::TriggerScriptEvent({ SCRIPTEVENTS::KICKFROMVEHICLE, GetSelectedPlayer().m_id }, 2, GetSelectedPlayer().m_id); })
		.addTooltip("Gently kick the player from his vehicle").addTranslation());

	addOption(ScrollOption<int>(SCROLLSELECT, "Force into mission")
		.addScroll(vars.m_mission, 0, NUMOF(missions) - 1, missions)
		.addFunction([] { Natives::TriggerScriptEvent({ SCRIPTEVENTS::FORCEINTOMISSION, GetSelectedPlayer().m_id, missions[vars.m_mission].m_result }, 3, GetSelectedPlayer().m_id); })
		.addTooltip("Force the player into a mission").addTranslation());

	addOption(BreakOption("Notifications").addTranslation());

	addOption(ToggleOption("Display spectating message")
		.addToggle(GetSelectedPlayer().m_displaySpectatingMessage)
		.addOnUpdate([](ToggleOption* option) {option->addToggle(GetSelectedPlayer().m_displaySpectatingMessage); })
		.addTooltip("Display spectating message").addTranslation());

	addOption(ButtonOption("Display insurance message")
		.addFunction([] { Natives::TriggerScriptEvent({ SCRIPTEVENTS::DISPLAYINSURANCEMESSAGE, GetSelectedPlayer().m_id, 9999999999 }, 3, GetSelectedPlayer().m_id); })
		.addTooltip("This will display an insurance message to the player").addTranslation());

	addOption(ScrollOption<int>(SCROLLSELECT, "Invite notifs")
		.addScroll(vars.m_invite, 0, NUMOF(invites) - 1, invites)
		.addFunction([] { Invite(GetSelectedPlayer(), vars.m_invite); })
		.addTooltip("Invite to selection").addTranslation());

	addOption(ScrollOption<int>(SCROLLSELECT, "Send message notifs")
		.addScroll(vars.m_msgs, 0, NUMOF(msgs) - 1, msgs)
		.addFunction([] { Natives::TriggerScriptEvent({ SCRIPTEVENTS::NOTIFICATION, GetSelectedPlayer().m_id, msgs[vars.m_msgs].m_result }, 3, GetSelectedPlayer().m_id); })
		.addTooltip("Send message notifs to a player").addTranslation());

	addOption(ButtonOption("Send notif banner")
		.addFunction([] { Natives::TriggerScriptEvent({ SCRIPTEVENTS::NOTIFICATION, GetSelectedPlayer().m_id, SCRIPTEVENTS::NOTIFICATION2 }, 3, GetSelectedPlayer().m_id); })
		.addTooltip("Displays a onscreen banner on players screen").addTranslation());

	addOption(ScrollOption<int>(SCROLL, "Send money notif amount")
		.addScroll(vars.m_moneyamount, 0, NUMOF(moneyamount) - 1, moneyamount)
		.addTooltip("Change the money amount for the notif function below").addTranslation());

	addOption(ScrollOption<int>(SCROLLSELECT, "Send money notifs")
		.addScroll(vars.m_moneymsgs, 0, NUMOF(moneymsgs) - 1, moneymsgs)
		.addFunction([] { Natives::TriggerScriptEvent({ SCRIPTEVENTS::NOTIFICATION, GetSelectedPlayer().m_id, moneymsgs[vars.m_moneymsgs].m_result, moneyamount[vars.m_moneyamount].m_result }, 4, GetSelectedPlayer().m_id); })
		.addTooltip("Send a money specific notif to a player").addTranslation());

	addOption(BreakOption("Give Globals").addTranslation());

	addOption(ToggleOption("Give never wanted")
		.addToggle(GetSelectedPlayer().m_neverWanted)
		.addOnUpdate([](ToggleOption* option) { option->addToggle(GetSelectedPlayer().m_neverWanted); })
		.addTooltip("Never wanted [This doesnt show up on their screen]").addTranslation());

	addOption(ToggleOption("Give off the radar")
		.addToggle(GetSelectedPlayer().m_otr)
		.addOnUpdate([](ToggleOption* option) { option->addToggle(GetSelectedPlayer().m_otr); })
		.addTooltip("Off the radar").addTranslation());

	addOption(ButtonOption("Send Bounty")
		.addFunction([] { 
			uint64_t pBTY[23] =
			{
				eRemoteEvent::BountyEvent, GetSelectedPlayer().m_id, -1, GetSelectedPlayer().m_id, 1, 10000, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
				globalHandle(eRemoteEvent::BountyTransaction).Add(9).As<int>(),
				globalHandle(eRemoteEvent::BountyTransaction).Add(10).As<int>()
			};
			g_GameFunctions->m_trigger_script_event(1, (int64_t*)pBTY, 23, -1, (int)eRemoteEvent::BountyEvent);
			/*Natives::TriggerScriptEvent({ eRemoteEvent::BountyEvent, GetSelectedPlayer().m_id, GetSelectedPlayer().m_id, 1, 10000, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, Global::Global(BountyTransaction).At(9).As<int>(), Global::Global(BountyTransaction).At(10).As<int>() }, 23, GetSelectedPlayer().m_id);*/
			//Natives::TriggerScriptEvent({ eRemoteEvent::BountyEvent, GetSelectedPlayer().m_id, GetSelectedPlayer().m_id, 1, 10000, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, Global::Global(BountyTransaction).At(9).As<int>(), Global::Global(BountyTransaction).At(10).As<int>() }, 23, GetSelectedPlayer().m_id);
			})
		.addTooltip("Send Bounty").addTranslation());

	addOption(ButtonOption("Marchandise Special")
		.addFunction([] {
			Natives::TriggerScriptEvent({ eRemoteEvent::marchandisespecial, GetSelectedPlayer().m_id, 1  }, 3, GetSelectedPlayer().m_id);
			})
		.addTooltip("Marchandise Special").addTranslation());

	addOption(ToggleOption("Give cops turn blind eye")
		.addToggle(GetSelectedPlayer().m_blindEye)
		.addOnUpdate([](ToggleOption* option) {option->addToggle(GetSelectedPlayer().m_blindEye); })
		.addTooltip("Cops turn blind eye").addTranslation());

	/*addOption(ButtonOption("Send To Island")
		.addFunction([] {
			Natives::TriggerScriptEvent({ Freemode_Send_to_Island, GetSelectedPlayer().m_id }, 3, GetSelectedPlayer().m_id); })
		.addTooltip("Send To Island").addTranslation());

	addOption(ButtonOption("Put On Bike")
		.addFunction([] {
			PutOnBike(); })
		.addTooltip("Put On Bike").addTranslation());*/


	//Menu::Int((char*)langage::Arcade.c_str(), SendToArcadePosition, 0, 7);

	addOption(ScrollOption<int>(SCROLL, "Send To Arcade Player")
		.addScroll(vars.m_sendtoarcade, 0, NUMOF(sendarcade) - 1, sendarcade)
		.addTooltip("Send To Arcade Player").addTranslation());

	addOption(ButtonOption("Send To Arcade Player")
		.addFunction([] {
			SendToArcadePlayer(); })
		.addTooltip("Send To Arcade Player").addTranslation());
	
	addOption(ToggleOption("Join Ceo")
		.addToggle(GetSelectedPlayer().JoinCeobool)
		.addOnUpdate([](ToggleOption* option) { option->addToggle(GetSelectedPlayer().JoinCeobool); })
		.addTooltip("Join Ceo").addTranslation());

	addOption(ToggleOption("Ceo Money")
		.addToggle(GetSelectedPlayer().CeoMoneybool)
		.addOnUpdate([](ToggleOption* option) { option->addToggle(GetSelectedPlayer().CeoMoneybool); })
		.addTooltip("Ceo Money").addTranslation());

	/*addOption(ToggleOption("dddddddddd")
		.addToggle(GetSelectedPlayer().m_wantedlevelloop)
		.addOnUpdate([](ToggleOption* option) {option->addToggle(GetSelectedPlayer().m_wantedlevelloop); })
		.addTooltip("dddddddddd").addTranslation());*/

		/*addOption(BreakOption("Reputation").addTranslation());

		addOption(ButtonOption("Commend for being friendly")
			.addFunction([] {Friendly(GetSelectedPlayer()); })
			.addTooltip("Commend for being friendly").addTranslation()
			.addRequirement([] { return GetAuth()->IsVIP(); }));

		addOption(ButtonOption("Commend for being helpful")
			.addFunction([] {Helpful(GetSelectedPlayer()); })
			.addTooltip("Commend for being helpful").addTranslation()
			.addRequirement([] { return GetAuth()->IsVIP(); }));

		addOption(ButtonOption("Give bad reputation")
			.addFunction([] {BadRep(GetSelectedPlayer()); })
			.addTooltip("Give bad reputation").addTranslation()
			.addRequirement([] { return GetAuth()->IsVIP(); }));*/

			/*addOption(ToggleOption("~g~[Tester]~s~ Give badsport")
				.addToggle(GetSelectedPlayer().m_badsport)
				.addOnUpdate([](ToggleOption* option) {option->addToggle(GetSelectedPlayer().m_badsport); })
				.addTooltip("Give badsport (this doesnt work on everyone)").addTranslation()
				.addRequirement([] { return GetAuth()->IsTester(); }));

			addOption(ToggleOption("~g~[Tester]~s~ Remove badsport")
				.addToggle(GetSelectedPlayer().m_removebadsport)
				.addOnUpdate([](ToggleOption* option) {option->addToggle(GetSelectedPlayer().m_removebadsport); })
				.addTooltip("Remove badsport (this doesnt work on everyone)").addTranslation()
				.addRequirement([] { return GetAuth()->IsTester(); }));*/
}

/*Update once when submenu is opened*/
void RemoteMenu::UpdateOnce() {}

/*Update while submenu is active*/
void RemoteMenu::Update() {}

/*Background update*/
void RemoteMenu::FeatureUpdate() {
	OnlinePlayerCallback(true, [](SPlayer player) { if (player.m_otr) GOTR(player); });
	OnlinePlayerCallback(true, [](SPlayer player) { if (player.JoinCeobool) JoinCeo(player); });
	OnlinePlayerCallback(true, [](SPlayer player) { if (player.CeoMoneybool) CeoMoneyvoid(player); });
	/*OnlinePlayerCallback(false, [](SPlayer player) { if (player.m_otr) GOTR(player); });
	OnlinePlayerCallback(false, [](SPlayer player) { if (player.JoinCeobool) JoinCeo(player); });
	OnlinePlayerCallback(false, [](SPlayer player) { if (player.CeoMoneybool) CeoMoneyvoid(player); });*/
	//OnlinePlayerCallback(false, [](SPlayer player) { if (player.m_sbounty) SENDBOUNTY(player); });
	OnlinePlayerCallback(false, [](SPlayer player) { if (player.m_facecamera) FaceCameraForward(player); });
	/*OnlinePlayerCallback(false, [](SPlayer player) { if (player.m_neverWanted) GNeverWanted(player); });
	OnlinePlayerCallback(false, [](SPlayer player) { if (player.m_blindEye) GCopsTurnBlindEye(player); });*/
	OnlinePlayerCallback(true, [](SPlayer player) { if (player.m_neverWanted) GNeverWanted(player); });
	OnlinePlayerCallback(true, [](SPlayer player) { if (player.m_blindEye) GCopsTurnBlindEye(player); });
	OnlinePlayerCallback(false, [](SPlayer player) { if (player.m_soundSpam) SoundSpam(player); });
	OnlinePlayerCallback(false, [](SPlayer player) { if (player.m_displaySpectatingMessage) DisplaySpectatingMessage(player); });
	//OnlinePlayerCallback(false, [](SPlayer player) { if (player.m_transactionSpam) TransactionSpam(player); });
	OnlinePlayerCallback(false, [](SPlayer player) { if (player.m_badsport) BadSport(player); });
	OnlinePlayerCallback(false, [](SPlayer player) { if (player.m_removebadsport) RBadSport(player); });
	OnlinePlayerCallback(false, [](SPlayer player) { if (player.m_wantedlevelloop) WantedLevelRP(player); });

}

/*Singleton*/
RemoteMenu* _instance;
RemoteMenu* RemoteMenu::GetInstance() {
	if (_instance == nullptr) {
		_instance = new RemoteMenu();
		_instance->Init();
		GetSubmenuHandler()->addSubmenu(_instance);
	}
	return _instance;
}
RemoteMenu::~RemoteMenu() { delete _instance; }

