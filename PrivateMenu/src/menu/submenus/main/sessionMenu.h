#pragma once
#include "menu/submenu.h"
#include "src/util/memory/reclass.h"

class SessionMenu : public Submenu {
public:
	static SessionMenu* GetInstance();
	void Init() override;
	void UpdateOnce() override;
	void Update() override;
	void FeatureUpdate() override;

	SessionMenu() : Submenu() {}
	~SessionMenu();
};

namespace SessionMenuVars
{

	struct Vars {
		int toJoin;
		bool showtalkingplayers = false;
		bool bypassevoblock;
		bool showmarkeronselectedbydefault;
		int markertypeselector;
		String message = "";
		bool showAsThunder;
		bool showAsThunderStaff;
		bool showAsThunderVIP;
		bool warncashcreation;
		bool warnonplayerjoin;
		bool showotr;
		bool showconnectandfree;
		int testing1;
		int testing2;
		int testing3;
		int testing4;
		bool showcoords;
		string DefaultSCName;
		String sessionhostdisplay = "";
	};
	extern Vars vars;
	inline void getThehost(int player) //
	{
		if (ForceHost(RAGE_JOAAT("freemode")))
		{
			if (auto freemode_thread = gta_util::find_script_thread(RAGE_JOAAT("freemode")); freemode_thread && freemode_thread->m_net_component)//
			{

				freemode_thread->m_net_component->block_host_migration(true);

				rage2::packet msg{};
				msg.write_message(eNetMessage::MsgScriptMigrateHost);
				freemode_thread->m_handler->get_id()->serialize(&msg.m_buffer);
				msg.write<int>(0, 16);
				msg.write<int>(0, 32);
				/*auto msg_id = player->get_net_game_player()->m_msg_id;*/
				auto msg_id = g_GameVariables->m_GetNetPlayer(player)->m_msg_id;
				msg.send(msg_id);


				freemode_thread->m_context.m_stack_size *= 2;

			}
		}
	}
}

