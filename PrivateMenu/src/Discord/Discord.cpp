#include "stdafx.h" 
#include "Discord.h" 

#include "discord_register.h"
#include "discord_rpc.h" 
#pragma comment(lib, "src/Discord/lib/discord-rpc.lib")

#include <windows.h>

#include <chrono>

Discord* g_Discord;

void DiscordApp::discordmain()
{
	g_Discord->initialize();
	g_Discord->UpdatePresence();
}

void Discord::initialize()
{

	DiscordEventHandlers Handler;
	memset(&Handler, 0, sizeof(Handler));
	Discord_Initialize("744435689562701915", &Handler, 1, NULL);
}

void Discord::UpdatePresence()
{
	DiscordRichPresence discordPresence;
	memset(&discordPresence, 0, sizeof(discordPresence));
	discordPresence.state = "https://Thunder-Menu.com";
	discordPresence.details = "Playing Thunder-Menu";
	discordPresence.startTimestamp = time(0); //initlialize time
	/*discordPresence.startTimestamp = 1507665886;*/
	/*discordPresence.endTimestamp = 1507665886;*/
	discordPresence.largeImageKey = "thunder_menu"; //large image file name no extension
	//discordPresence.largeImageText = "Numbani";
	discordPresence.largeImageText = "Thunder-Menu";
	/*discordPresence.smallImageKey = "thunder_menu";*/
	Discord_UpdatePresence(&discordPresence);
}


void DiscordApp::Shutdown()
{
	Discord_Shutdown(); //goodbye
}

//link-https://www.unknowncheats.me/forum/general-programming-and-reversing/361227-adding-discord-rich-presence-cheat.html
//link-https://github.com/Classic1338/DiscordRichPresence-
//link-https://github.com/Solybum/DiscordRPC
