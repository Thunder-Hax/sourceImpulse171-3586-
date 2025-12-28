#include "stdafx.h"
#include "sessionRemote.h"
#include "../allPlayersMenu.h"
#include "../playerList/player/remoteMenu.h"

using namespace SessionRemoteMenuVars;

namespace SessionRemoteMenuVars {
	Vars vars;
}


//void mytimer()
//{
//	DWORD ticks = GetTickCount64();
//DWORD milliseconds = ticks % 1000;
//ticks /= 1000;
//DWORD seconds = ticks % 60;
//int getTimer = seconds;
//if (getTimer % 1 == 0)
//{
//}
//}

void SessionRemoteMenu::Init() {
	setParentSubmenu<AllPlayersMenu>();
	setName("Remote", true, true);


	addOption(ButtonOption("Send Bounty All").addTranslation().addHotkey()
		.addFunction([] { //{ OnlinePlayerCallback(false, [](SPlayer player) 
			//SPlayer m_players[33];
			//myid_R();
			for (int i = 0; i <= 32; i++)
			{
				//SPlayer player2 = m_players[i];
				//
				///*int Handle = PLAYER::GetPlayerPedScriptIndex(i);
				//if (Handle != isme2)*/
				//if (i != isme_R)
				//{
				//Player reyalP = PLAYER::GetPlayerPedScriptIndex(player.m_id);

				uint64_t pBTY[23] =
				{
					eRemoteEvent::BountyEvent, PLAYER::PlayerId(), -1, i, 1, 10000, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
					globalHandle(eRemoteEvent::BountyTransaction).Add(9).As<int>(),
					globalHandle(eRemoteEvent::BountyTransaction).Add(10).As<int>()
				};
				g_GameFunctions->m_trigger_script_event(1, (int64_t*)pBTY, 23, -1, (int)eRemoteEvent::BountyEvent);
				//}
			}
			/*RemoteMenuVars::bountyAll();*/ 
			//});
			})
		.addTooltip("Send Bounty All"));
			/*Natives::TriggerScriptEvent({ eRemoteEvent::BountyEvent, GetSelectedPlayer().m_id, GetSelectedPlayer().m_id, 1, 10000, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, Global::Global(BountyTransaction).At(9).As<int>(), Global::Global(BountyTransaction).At(10).As<int>() }, 23, GetSelectedPlayer().m_id);*/
			//Natives::TriggerScriptEvent({ eRemoteEvent::BountyEvent, GetSelectedPlayer().m_id, GetSelectedPlayer().m_id, 1, 10000, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, Global::Global(BountyTransaction).At(9).As<int>(), Global::Global(BountyTransaction).At(10).As<int>() }, 23, GetSelectedPlayer().m_id);

	addOption(ButtonOption("Send To Arcade All Player").addTranslation().addHotkey()
		.addFunction([] { //OnlinePlayerCallback(false, [](SPlayer player) {
			myid_R();
			for (int i = 0; i <= 32; i++)
			{

				try {
					DWORD ticks = GetTickCount64();
					DWORD milliseconds = ticks % 1000;
					ticks /= 1000;
					DWORD seconds = ticks % 60;
					int getTimer = seconds;
					if (getTimer % 1 == 0)
					{
						/*int Handle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
						if (Handle == Features::playerme)
						{
						}*/
						if (i != isme_R)
						{
							int eventValue = SendToArcadeEvent[SendToArcadePosition];
							//unsigned int playerBit = (1 << i);
							const size_t arg_count = 26;
							/*const auto global = *ScriptGlobal(1894573 + 1 + i * 608 + 510).As<std::uint64_t*>();
							int64_t args1[25] = { -95341040, PLAYER::PLAYER_ID(), SendToArcadeEvent[SendToArcadePosition], 0, 0, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, global };
							int64_t args2[25] = { 1742713914, PLAYER::PLAYER_ID(), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };*/

							const auto global = *ScriptGlobal(NeverWantedGlobal[0] + 1 + i * NeverWantedGlobal[1] + NeverWantedGlobal[2]).As<std::uint64_t*>();//1895156
							/*int64_t args1[arg_count] = { eRemoteEvent::StartScriptBegin, PLAYER::PLAYER_ID(), playerBit, static_cast<int64_t>(eventValue), 0, 0, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, global };
							int64_t args2[arg_count] = { eRemoteEvent::StartScriptProceed, PLAYER::PLAYER_ID(), playerBit, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };*/
							int64_t args1[arg_count] = { eRemoteEvent::StartScriptBegin, PLAYER::PlayerId(), i, static_cast<int64_t>(eventValue), 0, 0, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, global };
							int64_t args2[arg_count] = { eRemoteEvent::StartScriptProceed, PLAYER::PlayerId(), i, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
							g_GameFunctions->m_trigger_script_event(1, args1, arg_count, 1 << i, (int)eRemoteEvent::StartScriptBegin);
							g_GameFunctions->m_trigger_script_event(1, args2, arg_count, 1 << i, (int)eRemoteEvent::StartScriptProceed);
							//notifyMap("Send to Arcade");
						}
						/*UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
						UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("~r~send to Arcade");
						UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_STRIPPER_CHEETAH", "CHAR_STRIPPER_CHEETAH", 1, 8, "~w~Thunder-Menu\n", "~w~Send to Arcade Player\r\n", 1, "~w~Thunder Menu\n ~w~Send to Arcade Player\r\n", 9, 1);
						UI::_DRAW_NOTIFICATION_3(FALSE, FALSE);*/
					}
				}
				catch (...) {
					return;
				}
				{
					if (i == 31)
					{
						break;
					}
				}
			}

			})
		.addTooltip("Send To Arcade All Player"));

	addOption(ToggleOption("2.5k")
		.addToggle(vars.m_MoneyDropai25)
		.addOnUpdate([](ToggleOption* option) {option->addToggle(vars.m_MoneyDropai25); })
		.addTranslation().addTooltip("2.5k"));

	addOption(ToggleOption("2K AI money drop All")
		.addToggle(vars.m_MoneyDropai)
		.addOnUpdate([](ToggleOption* option) {option->addToggle(vars.m_MoneyDropai); })
		.addTranslation().addTooltip("Standard money drop"));

	addOption(ButtonOption("Non host kick")
		.addFunction([] { OnlinePlayerCallback(false, [](SPlayer player) { RemoteMenuVars::NonHostKick(player); }); })
		.addTooltip("Non host kick").addTranslation().addHotkey());

	addOption(ButtonOption("Kick to single player")
		.addFunction([] { OnlinePlayerCallback(false, [](SPlayer player) { RemoteMenuVars::KickToSingleplayer(player); }); })
		.addTooltip("Kick to single player").addTranslation().addHotkey());

	addOption(ButtonOption("CEO kick")
		.addFunction([] { OnlinePlayerCallback(false, [](SPlayer player) { RemoteMenuVars::CEOKick(player); }); })
		.addTooltip("CEO kick").addTranslation().addHotkey());

	addOption(ButtonOption("CEO ban")
		.addFunction([] { OnlinePlayerCallback(false, [](SPlayer player) { RemoteMenuVars::CEOBan(player); }); })
		.addTooltip("CEO ban").addTranslation().addHotkey());

	addOption(BreakOption("Troll").addTranslation());

	addOption(ButtonOption("Infinite loading screen")
		.addFunction([] { OnlinePlayerCallback(false, [](SPlayer player) { RemoteMenuVars::InfiniteLoadingScreen(player); }); })
		.addTooltip("Infinite loading screen").addTranslation().addHotkey());

	addOption(ToggleOption("Sound spam")
		.addTranslation().addHotkey()
		.addToggle(vars.soundSpam)
		.addTooltip("Sound spam"));

	addOption(ToggleOption("Lock lobbies view to face forward")
		.addTranslation().addHotkey()
		.addToggle(vars.lockview)
		.addTooltip("Lock lobbies view to face forward"));

	addOption(ButtonOption("Gentle kick from vehicle").addTranslation().addHotkey()
		.addFunction([] { OnlinePlayerCallback(false, [](SPlayer player) {  Natives::TriggerScriptEvent({ SCRIPTEVENTS::KICKFROMVEHICLE, player.m_id }, 2, player.m_id); }); })
		.addTooltip("Gently kick the player from his vehicle"));

	addOption(ScrollOption<int>(SCROLLSELECT, "Force into mission").addTranslation()
		.addScroll(vars.m_mission, 0, NUMOF(RemoteMenuVars::missions) - 1, RemoteMenuVars::missions)
		.addFunction([] { OnlinePlayerCallback(false, [](SPlayer player) { Natives::TriggerScriptEvent({ SCRIPTEVENTS::FORCEINTOMISSION, player.m_id, RemoteMenuVars::missions[vars.m_mission].m_result }, 3, player.m_id); }); })
		.addTooltip("Force the player into a mission"));

	addOption(BreakOption("Notifications").addTranslation());

	addOption(ToggleOption("Display spectating message")
		.addTranslation().addHotkey()
		.addToggle(vars.spectating)
		.addTooltip("Display spectating message"));

	addOption(ButtonOption("Display insurance message")
		.addFunction([] { OnlinePlayerCallback(false, [](SPlayer player) { Natives::TriggerScriptEvent({ 380155193, player.m_id, 9999999999 }, 3, player.m_id); }); })
		.addTooltip("This will display an insurance message to the player").addTranslation());

	addOption(ScrollOption<int>(SCROLLSELECT, "Invite notif")
		.addScroll(vars.m_invite, 0, NUMOF(RemoteMenuVars::invites) - 1, RemoteMenuVars::invites)
		.addFunction([] { OnlinePlayerCallback(false, [](SPlayer player) { RemoteMenuVars::Invite(player, vars.m_invite); }); })
		.addTooltip("Invite to selection").addTranslation().addHotkey());

	addOption(ScrollOption<int>(SCROLLSELECT, "Send message notifs")
		.addScroll(vars.m_sendmsg, 0, NUMOF(RemoteMenuVars::msgs) - 1, RemoteMenuVars::msgs)
		.addFunction([] { OnlinePlayerCallback(false, [](SPlayer player) { Natives::TriggerScriptEvent({ SCRIPTEVENTS::NOTIFICATION, player.m_id, RemoteMenuVars::msgs[vars.m_sendmsg].m_result }, 3, player.m_id); }); })
		.addTooltip("Send messages that are notifications").addTranslation().addHotkey());

	addOption(ButtonOption("Send notif banner").addTranslation().addHotkey()
		.addFunction([] { OnlinePlayerCallback(false, [](SPlayer player) {  Natives::TriggerScriptEvent({ SCRIPTEVENTS::NOTIFICATION, player.m_id, SCRIPTEVENTS::NOTIFICATION2 }, 3, player.m_id); }); })
		.addTooltip("Displays a onscreen banner on players screen"));

	addOption(ScrollOption<int>(SCROLLSELECT, "Send money notif amount")
		.addScroll(vars.m_moneyamount, 0, NUMOF(RemoteMenuVars::moneyamount) - 1, RemoteMenuVars::moneyamount)
		.addTooltip("Change the money amount for the notif function below").addTranslation().addHotkey());

	addOption(ScrollOption<int>(SCROLLSELECT, "Send money notifs")
		.addScroll(vars.m_sendmmsg, 0, NUMOF(RemoteMenuVars::moneymsgs) - 1, RemoteMenuVars::moneymsgs)
		.addFunction([] { OnlinePlayerCallback(false, [](SPlayer player) { Natives::TriggerScriptEvent({ SCRIPTEVENTS::NOTIFICATION, player.m_id, RemoteMenuVars::moneymsgs[vars.m_sendmmsg].m_result, RemoteMenuVars::moneyamount[vars.m_moneyamount].m_result }, 4, player.m_id); }); })
		.addTooltip("Send a money specific notif to a player").addTranslation().addHotkey());

	addOption(BreakOption("Give Globals").addTranslation());

	addOption(ToggleOption("Give never wanted")
		.addToggle(vars.gneverWanted)
		.addTranslation().addHotkey()
		.addTooltip("Give Never wanted"));

	addOption(ToggleOption("Give cops turn blind eye")
		.addToggle(vars.gblindEye)
		.addTranslation().addHotkey()
		.addTooltip("Give Cops turn blind eye"));

	addOption(ToggleOption("Give off the radar")
		.addToggle(vars.gotr)
		.addTooltip("Give Off the radar").addTranslation().addHotkey());

	/*addOption(ButtonOption("Send Bounty").addTranslation().addHotkey()
		.addFunction([] { OnlinePlayerCallback(false, [](SPlayer player) {  
			RemoteMenuVars::SENDBOUNTY(player);
			}); })
		.addTooltip("Send Bounty"));*/

	/*addOption(BreakOption("Reputation").addTranslation());

	addOption(ButtonOption("Commend for being friendly")
		.addFunction([] { OnlinePlayerCallback(false, [](SPlayer player) { RemoteMenuVars::Friendly(player); }); })
		.addTooltip("Commend for being friendly").addTranslation().addHotkey()
		.addRequirement([] { return GetAuth()->IsVIP(); }));

	addOption(ButtonOption("Commend for being helpful")
		.addFunction([] { OnlinePlayerCallback(false, [](SPlayer player) { RemoteMenuVars::Helpful(player); }); })
		.addTooltip("Commend for being helpful").addTranslation().addHotkey()
		.addRequirement([] { return GetAuth()->IsVIP(); }));

	addOption(ButtonOption("Give bad reputation")
		.addFunction([] { OnlinePlayerCallback(false, [](SPlayer player) { RemoteMenuVars::BadRep(player); }); })
		.addTooltip("Give bad reputation").addTranslation().addHotkey()
		.addRequirement([] { return GetAuth()->IsVIP(); }));

	addOption(ToggleOption("~g~[Tester]~s~ Give badsport to lobby")
		.addRequirement([] { return GetAuth()->IsTester(); })
		.addTranslation().addHotkey()
		.addToggle(vars.badsportlobby)
		.addTooltip("Give badsport (this doesnt work on everyone)"));

	addOption(ToggleOption("~g~[Tester]~s~ Remove badsport from lobby")
		.addRequirement([] { return GetAuth()->IsTester(); })
		.addTranslation().addHotkey()
		.addToggle(vars.rbadsportlobby)
		.addTooltip("Remove badsport (this doesnt work on everyone)"));*/
}

/*Update once when submenu is opened*/
void SessionRemoteMenu::UpdateOnce() {}

/*Update while submenu is active*/
void SessionRemoteMenu::Update() {}

/*Background update*/
void SessionRemoteMenu::FeatureUpdate() {
	if (vars.soundSpam) {
		OnlinePlayerCallback(false, [](SPlayer player) { RemoteMenuVars::SoundSpam(player); });
	}
	if (vars.m_MoneyDropai) {
		/*OnlinePlayerCallback(false, [](SPlayer player) { */RemoteMenuVars::moneytoAll();/* });*/
	}
	if (vars.m_MoneyDropai25) {
		/*OnlinePlayerCallback(false, [](SPlayer player) { */RemoteMenuVars::moneytoAll25k();/* });*/
	}
	//if (vars.transactionSpam) {
	//	OnlinePlayerCallback(false, [](SPlayer player) { RemoteMenuVars::TransactionSpam(player); });
	//}

	if (vars.spectating) {
		OnlinePlayerCallback(false, [](SPlayer player) { RemoteMenuVars::DisplaySpectatingMessage(player); });
	}

	if (vars.gotr) {
		OnlinePlayerCallback(false, [](SPlayer player) { RemoteMenuVars::GOTR(player); });
	}

	/*if (vars.JoinCeobool) {
		OnlinePlayerCallback(false, [](SPlayer player) { RemoteMenuVars::JoinCeo(player); });
	}*/

	/*if (vars.sendbounties) {
		OnlinePlayerCallback(false, [](SPlayer player) { RemoteMenuVars::SENDBOUNTY(player); });
	}*/
	if (vars.gneverWanted) {
		OnlinePlayerCallback(false, [](SPlayer player) { RemoteMenuVars::GNeverWanted(player); });
	}

	if (vars.gblindEye) {
		OnlinePlayerCallback(false, [](SPlayer player) { RemoteMenuVars::GCopsTurnBlindEye(player); });
	}

	if (vars.lockview) {
		OnlinePlayerCallback(false, [](SPlayer player) { RemoteMenuVars::FaceCameraForward(player); });
	}

	if (vars.badsportlobby) {
		OnlinePlayerCallback(false, [](SPlayer player) { RemoteMenuVars::BadSport(player); });
	}

	if (vars.rbadsportlobby) {
		OnlinePlayerCallback(false, [](SPlayer player) { RemoteMenuVars::RBadSport(player); });
	}
}

/*Singleton*/
SessionRemoteMenu* _instance;
SessionRemoteMenu* SessionRemoteMenu::GetInstance() {
	if (_instance == nullptr) {
		_instance = new SessionRemoteMenu();
		_instance->Init();
		GetSubmenuHandler()->addSubmenu(_instance);
	}
	return _instance;
}
SessionRemoteMenu::~SessionRemoteMenu() { delete _instance; }