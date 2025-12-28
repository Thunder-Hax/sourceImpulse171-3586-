#include "stdafx.h"
#include "reclass.h"

#include <deque>            // Conteneur de données double-ended queue (filaire)
#include <locale>           // Facilite la gestion des localisations, des jeux de caractères et des conversions de chaînes
#include <codecvt>          // Conversion entre les jeux de caractères Unicode et d'autres jeux de caractères
#include <variant>          // Alternative pour manipuler les types avec des valeurs de plusieurs types possibles
#include <optional>         // Type de conteneur pour représenter une valeur optionnelle
#include <any>              // Conteneur pour stocker n'importe quel type de données
#include <memory_resource>  // Ressources de mémoire personnalisées pour les allocations
#include <filesystem>       // Pour la manipulation de fichiers et de répertoires
#include <span>             // Conteneur non-propriétaire pour les tableaux C-style
#include <numeric>          // Opérations numériques sur les conteneurs
#include <compare>          // Opérateurs de comparaison <=> (spaceship)
#include <bit>              // Fonctions pour manipuler des bits individuels
#include <concepts>         // Conceptes de programmation générique
#include <execution>        // Exécution parallèle des algorithmes
#include <format>           // Mise en forme des chaînes de caractères
#include <source_location>  // Informations sur l'emplacement source dans le code
#include <stop_token>       // Token pour demander l'arrêt d'une opération asynchrone
#include <syncstream>       // Flux d'entrée/sortie synchronisé
#include <version>          // Macros de version C++ standard
#include <ranges>           // Opérations sur les plages de valeurs
#include <iostream>           // Pour les entrées/sorties standard
#include <fstream>            // Pour les opérations sur les fichiers
#include <vector>             // Pour utiliser des vecteurs
#include <string>             // Pour manipuler des chaînes de caractères
#include <cmath>              // Pour les fonctions mathématiques
#include <algorithm>          // Pour les algorithmes de la bibliothèque standard
#include <chrono>             // Pour la gestion du temps
#include <thread>             // Pour la gestion des threads
#include <regex>              // Pour les expressions régulières
#include <map>                // Pour les conteneurs de type map
#include <unordered_map>      // Pour les conteneurs de type unordered_map
#include <set>                // Pour les ensembles
#include <unordered_set>      // Pour les ensembles non triés
#include <queue>              // Pour les files
#include <stack>              // Pour les piles
#include <list>               // Pour les listes chaînées
#include <array>              // Pour les tableaux statiques
#include <tuple>              // Pour les tuples
#include <iomanip>            // Pour la mise en forme de sortie
#include <random>             // Pour la génération de nombres aléatoires
#include <functional>         // Pour les objets fonction
#include <memory>             // Pour la gestion de la mémoire
#include <atomic>             // Pour les opérations atomiques
#include <mutex>              // Pour les verrous mutex
#include <condition_variable> // Pour les variables de condition
#include <bitset>             // Pour les opérations sur les bits
#include <sstream>            // Pour les flux de chaînes de caractères
#include <stdexcept>          // Pour les exceptions standard
#include <limits>             // Pour les limites numériques
#include <cctype>             // Pour les fonctions de caractères
#include <ctime>              // Pour la gestion du temps en C
#include <cstdlib>            // Pour les fonctions de la bibliothèque standard C
#include <cstring>            // Pour les fonctions de manipulation de chaînes de caractères en C

// Exemples d'inclusions de bibliothèques tierces
//#include <SFML/Graphics.hpp>   // Pour la création d'applications graphiques avec SFML
//#include <opencv2/opencv.hpp>  // Pour le traitement d'images avec OpenCV
//#include <boost/algorithm/string.hpp>  // Pour les algorithmes de manipulation de chaînes avec Boost
//#include <json/json.h>         // Pour la manipulation de JSON avec JsonCpp
//#include <websocketpp/server.hpp>  // Pour la création de serveurs WebSocket avec WebSocket++ 
//#include <sqlite3.h>           // Pour les opérations sur les bases de données SQLite
//#include <asio.hpp>            // Pour la programmation réseau asynchrone avec Asio
//#include <libcurl/curl.h>      // Pour les opérations de transfert de données avec libcurl
#include <nlohmann/json.hpp>   // Pour la manipulation de JSON avec nlohmann/json
//#include <openssl/ssl.h>       // Pour les opérations de sécurité avec OpenSSL
//#include <glm/glm.hpp>         // Pour les calculs mathématiques avec GLM
#include <rapidjson/document.h>  // Pour la manipulation de JSON avec RapidJSON
//#include <zlib.h>              // Pour la compression/décompression de données avec zlib
//#include <libxml/parser.h>     // Pour le traitement de documents XML avec libxml2
//#include <libpng/png.h>        // Pour la manipulation d'images PNG avec libpng
//#include <gtest/gtest.h>       // Pour l'écriture de tests unitaires avec Google Test
//#include <yaml-cpp/yaml.h>     // Pour la manipulation de YAML avec YAML-cpp
//#include <flann/flann.hpp>     // Pour la recherche de voisins les plus proches avec FLANN
//#include <opencv2/highgui/highgui.hpp>  // Pour la création d'interfaces graphiques avec OpenCV
//#include <pcl/point_cloud.h>  // Pour la manipulation de nuages de points avec PCL
//#include <pcl/io/pcd_io.h>    // Pour la lecture/écriture de fichiers PCD avec PCL
//#include <pcl/visualization/cloud_viewer.h>  // Pour la visualisation de nuages de points avec PCL
//#include <Eigen/Core>         // Pour les calculs mathématiques avec Eigen
//#include <nana/gui.hpp>       // Pour la création d'interfaces graphiques avec Nana C++ GUI
//#include <curlpp/cURLpp.hpp>  // Pour les requêtes HTTP


namespace ReClass {
	CWorld* GetWorld() { return *(CWorld**)Backend::GetWorldPtr(); }
	CWorldd* GetWorldd() { return *(CWorldd**)Backend::GetWorldPtr(); }
	CNetworkPlayerManager* GetNetworkPlayerManager() { return *(CNetworkPlayerManager**)Backend::GetNetworkPlayerManagerPtr(); }
}


rage2::packet::packet() :
	m_buffer(m_data, 0x4000)
{
}
void rage2::packet::send(uint32_t msg_id)
{
	g_GameFunctions->m_queue_packet(GetNetwork()->m_game_session_ptr->m_net_connection_mgr, msg_id, m_data, (m_buffer.m_curBit + 7) >> 3, 1, nullptr);
}

void rage2::packet::send(int player, int connection_id)/*, bool is_peer*/
{
	auto mgr = GetNetwork()->m_game_session_ptr->m_net_connection_mgr;
	auto peer = g_GameFunctions->m_GetConnectionPeer(mgr, player);
	g_GameFunctions->m_send_packet(mgr, (netConnectionPeer*)peer, connection_id, m_data, (m_buffer.m_curBit + 7) >> 3, 0x1000000);
}




rage::snPlayer* m_function::GetSessionPlayer(int player)
{
	for (std::uint32_t i = 0; i < GetNetwork()->m_game_session_ptr->m_player_count; i++)
	{
		if (GetNetwork()->m_game_session_ptr->m_players[i]->m_player_data.m_host_token == g_GameVariables->m_GetNetPlayer(player)->get_net_data()->m_host_token)
		{
			return GetNetwork()->m_game_session_ptr->m_players[i];
		}

		if (GetNetwork()->m_game_session_ptr->m_local_player.m_player_data.m_host_token == g_GameVariables->m_GetNetPlayer(player)->get_net_data()->m_host_token)
			return &GetNetwork()->m_game_session_ptr->m_local_player;
	}

	return nullptr;
}

rage::snPeer* m_function::GetSessionPeer(int player)
{
	for (std::uint32_t i = 0; i < GetNetwork()->m_game_session_ptr->m_peer_count; i++)
	{
		if (GetNetwork()->m_game_session_ptr->m_peers[i]->m_peer_data.m_gamer_handle.m_rockstar_id == g_GameVariables->m_GetNetPlayer(player)->get_net_data()->m_gamer_handle.m_rockstar_id)
		{
			return GetNetwork()->m_game_session_ptr->m_peers[i];
		}
	}
	return nullptr;
}
inline CNetGamePlayer* GetNetPlayer(int player)
{
	return g_GameVariables->m_GetNetPlayer(player);
}


//
//netAddress m_function::GetIPAddress(int player)
//{
//	if ((player == /*PlayerId2*/PLAYER::PlayerId()) && (g_GameVariables->m_GetNetPlayer(/*PlayerId2*/PLAYER::PlayerId()) != nullptr))
//	{
//		return g_GameVariables->m_GetNetPlayer(/*PlayerId2*/PLAYER::PlayerId())->get_net_data()->m_external_ip;
//	}
//	if (auto session_player = get_session_player(player))
//	{
//		if (auto peer = g_GameFunctions->m_GetConnectionPeer(GetNetwork()->m_game_session_ptr->m_net_connection_mgr, (int)get_session_player(player)->m_player_data.m_peer_id_2))
//		{
//			return netAddress{ ((netConnectionPeer*)peer)->m_external_ip };
//		}
//	}
//	return { 0 };
//}
//netAddress m_function::GetIPAddress(int player)
//{
//	if ((player == PlayerId) && (GetNetPlayer(PlayerId) != nullptr))
//	{
//		return GetNetPlayer(PlayerId)->get_net_data()->m_external_ip;
//	}
//	if (auto session_player = GetSessionPlayer(player))
//	{
//		if (auto peer = g_GameFunctions->m_GetConnectionPeer(GetNetwork()->m_game_session_ptr->m_net_connection_mgr, (int)GetSessionPlayer(player)->m_player_data.m_peer_id_2))
//		{
//			return netAddress{ ((netConnectionPeer*)peer)->m_external_ip };
//		}
//	}
//	return { 0 };
//}

//std::string GetPlayerIP(int player)
//{
//	if (g_GameVariables->m_GetNetPlayer(player) != nullptr)
//	{
//		auto player_ip = GetIPAddress(player);
//		std::ostringstream ip; ip << static_cast<int>(player_ip.m_field1) << "." << static_cast<int>(player_ip.m_field2) << "." << static_cast<int>(player_ip.m_field3) << "." << static_cast<int>(player_ip.m_field4);
//		return ip.str();
//	}
//}
//std::string m_function::GetPlayerIP(int player)
//{
//	if (GetNetPlayer(player) != nullptr)
//	{
//		auto player_ip = GetIPAddress(player);
//		std::ostringstream ip; ip << static_cast<int>(player_ip.m_field1) << "." << static_cast<int>(player_ip.m_field2) << "." << static_cast<int>(player_ip.m_field3) << "." << static_cast<int>(player_ip.m_field4);
//		return ip.str();
//	}
//	return "127.0.0.1";
//}
//static rage::snPlayer* get_session_player(int player)
//{
//	for (std::uint32_t i = 0; i < GetNetwork()->m_game_session_ptr->m_player_count; i++)
//	{
//		if (GetNetwork()->m_game_session_ptr->m_players[i]->m_player_data.m_host_token == g_GameVariables->m_GetNetPlayer(player)->get_net_data()->m_host_token)
//		{
//			return GetNetwork()->m_game_session_ptr->m_players[i];
//		}
//
//		if (GetNetwork()->m_game_session_ptr->m_local_player.m_player_data.m_host_token == g_GameVariables->m_GetNetPlayer(player)->get_net_data()->m_host_token)
//			return &GetNetwork()->m_game_session_ptr->m_local_player;
//	}
//
//	return nullptr;
//}
static rage::snPlayer* get_session_player(int player)
{
	for (std::uint32_t i = 0; i < (std::uint32_t)GetNetwork()->m_game_session_ptr->m_player_count; i++)
	{
		if (GetNetwork()->m_game_session_ptr->m_players[i]->m_player_data.m_host_token == g_GameVariables->m_GetNetPlayer(player)->get_net_data()->m_host_token)
		{
			return GetNetwork()->m_game_session_ptr->m_players[i];
		}

		if (GetNetwork()->m_game_session_ptr->m_local_player.m_player_data.m_host_token == g_GameVariables->m_GetNetPlayer(player)->get_net_data()->m_host_token)
			return &GetNetwork()->m_game_session_ptr->m_local_player;
	}

	return nullptr;
}

static rage::snPeer* get_session_peer(int player)
{
	for (std::uint32_t i = 0; i < GetNetwork()->m_game_session_ptr->m_peer_count; i++)
	{
		if (GetNetwork()->m_game_session_ptr->m_peers[i]->m_peer_data.m_gamer_handle.m_rockstar_id == g_GameVariables->m_GetNetPlayer(player)->get_net_data()->m_gamer_handle.m_rockstar_id)
		{
			return GetNetwork()->m_game_session_ptr->m_peers[i];
		}
	}
	return nullptr;
}

static netAddress GetIPAddress(int player)
{
	if ((player == PlayerId2) && (g_GameVariables->m_GetNetPlayer(PlayerId2) != nullptr))
	{
		return g_GameVariables->m_GetNetPlayer(PlayerId2)->get_net_data()->m_external_ip;
	}
	if (auto session_player = get_session_player(player))
	{
		if (auto peer = g_GameFunctions->m_GetConnectionPeer(GetNetwork()->m_game_session_ptr->m_net_connection_mgr, (int)get_session_player(player)->m_player_data.m_peer_id_2))
		{
			return netAddress{ ((netConnectionPeer*)peer)->m_external_ip };
		}
	}
	return { 0 };
}

std::string m_function::GetPlayerIP(int player)
{
	if (g_GameVariables->m_GetNetPlayer(player) != nullptr)
	{
		auto player_ip = GetIPAddress(player);
		std::ostringstream ip; ip << static_cast<int>(player_ip.m_field1) << "." << static_cast<int>(player_ip.m_field2) << "." << static_cast<int>(player_ip.m_field3) << "." << static_cast<int>(player_ip.m_field4);
		return ip.str();
	}
	return "127.0.0.1";
}

//#define PlayerPedId PLAYER::PLAYER_PED_ID()

////const int PlayerInfoGlobal[] = { 1853910, 862, 205 };
//const int PlayerInfoGlobal[] = { 1853988, 867, 205 };
//const int PlayerPictureGlobal[] = { 1666485, 2 };//Global_1660783[iVar0 /*5*/].f_2
////const int PlayerPictureGlobal[] = { 1666668, 2 };//Global_1660783[iVar0 /*5*/].f_2
////const int InteriorStateGlobal[] = { 2657589, 1, 466, 245 };//Global_2689235[bVar0 /*453*/].f_243
//const char* m_function::PlayerPictureString(int a1)
//{
//	int index = PlayerPictureGlobal[0] + PlayerPictureGlobal[1];
//	for (int x = 0; x <= 150; x += 5)
//	{
//		int player_id = *ScriptGlobal(index).Add(x).As<int*>();
//		if (player_id == a1)
//		{
//			auto global_head = *ScriptGlobal(index).Add(x).Add(1).As<int*>();
//			if (PED::IsPedheadshotValid(global_head))
//				return PED::GetPedheadshotTxdString(global_head);
//		}
//	}
//	return "CHAR_MULTIPLAYER";
//}

std::uint64_t m_function::GetHostToken(int player)
{
	if (g_GameVariables->m_GetNetPlayer(player) != nullptr)
		return g_GameVariables->m_GetNetPlayer(player)->get_net_data()->m_host_token;
	return 18446744073709551614;
}

const char* m_function::GetPlayerName(int player)
{
	const char* socialclub = PLAYER::GetPlayerName(player);
	return socialclub;
}

std::uint64_t m_function::GetPlayerRID(int player)
{
	if (g_GameVariables->m_GetNetPlayer(player) != nullptr)
		return g_GameVariables->m_GetNetPlayer(player)->get_net_data()->m_gamer_handle.m_rockstar_id;
	return 0;
}

//std::string m_function::GetPlayerRID(int player)
//{
//	int networkhandle[13];
//	NETWORK::NETWORK_HANDLE_FROM_PLAYER(player, networkhandle, 13);
//	char* rockstar_id = NETWORK::NETWORK_MEMBER_ID_FROM_GAMER_HANDLE(&networkhandle[0]);
//	return rockstar_id;
//}


//bool m_function::IsPlayerGodMode(int player)
//{
//	bool invincible;
//	auto cutscene = NETWORK::IS_PLAYER_IN_CUTSCENE(player);
//	auto player_index = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player);
//	auto coords = ENTITY::GET_ENTITY_COORDS(player_index, 1);
//	auto interior = INTERIOR::IS_VALID_INTERIOR(INTERIOR::GET_INTERIOR_FROM_ENTITY(player_index));
//	auto interior_id = INTERIOR::GET_INTERIOR_AT_COORDS(coords.x, coords.y, coords.z);
//	auto visible_to_script = ENTITY::IS_ENTITY_VISIBLE_TO_SCRIPT(player_index);
//	auto interior_state = *ScriptGlobal(((InteriorStateGlobal[0] + InteriorStateGlobal[1]) + (player * InteriorStateGlobal[2])) + InteriorStateGlobal[3]).As<int*>();
//
//	auto playerhandle = g_GameFunctions->m_GetPlayerHandle(player_index);
//	if (playerhandle != 0)
//	{
//		if (!cutscene && !interior && !interior_id && !interior_state && visible_to_script)
//		{
//			return invincible = *reinterpret_cast<bool*>(playerhandle + 0x189);
//		}
//	}
//	return false;
//}



//static rage::snPlayer* get_session_player(int player)
//{
//	for (std::uint32_t i = 0; i < GetNetwork()->m_game_session_ptr->m_player_count; i++)
//	{
//		if (GetNetwork()->m_game_session_ptr->m_players[i]->m_player_data.m_host_token == g_GameVariables->m_GetNetPlayer(player)->get_net_data()->m_host_token)
//		{
//			return GetNetwork()->m_game_session_ptr->m_players[i];
//		}
//
//		if (GetNetwork()->m_game_session_ptr->m_local_player.m_player_data.m_host_token == g_GameVariables->m_GetNetPlayer(player)->get_net_data()->m_host_token)
//			return &GetNetwork()->m_game_session_ptr->m_local_player;
//	}
//
//	return nullptr;
//}
//
//static rage::snPeer* get_session_peer(int player)
//{
//	for (std::uint32_t i = 0; i < GetNetwork()->m_game_session_ptr->m_peer_count; i++)
//	{
//		if (GetNetwork()->m_game_session_ptr->m_peers[i]->m_peer_data.m_gamer_handle.m_rockstar_id == g_GameVariables->m_GetNetPlayer(player)->get_net_data()->m_gamer_handle.m_rockstar_id)
//		{
//			return GetNetwork()->m_game_session_ptr->m_peers[i];
//		}
//	}
//	return nullptr;
//}
//
//static netAddress GetIPAddress(int player)
//{
//	if ((player == PLAYER::PlayerId()) && (g_GameVariables->m_GetNetPlayer(PLAYER::PlayerId()) != nullptr))
//	{
//		return g_GameVariables->m_GetNetPlayer(PLAYER::PlayerId())->get_net_data()->m_external_ip;
//	}
//	if (auto session_player = get_session_player(player))
//	{
//		if (auto peer = g_GameFunctions->m_GetConnectionPeer(GetNetwork()->m_game_session_ptr->m_net_connection_mgr, (int)get_session_player(player)->m_player_data.m_peer_id_2))
//		{
//			return netAddress{ ((netConnectionPeer*)peer)->m_external_ip };
//		}
//	}
//	return { 0 };
//}
//typedef decltype(static_cast<const char*>(nullptr)) String2;







void BypassPatch::ModelSpawnBypass(bool toggle)
{
	if (g_GameVariables->m_ModelSpawnBypass == nullptr)
		return;
	*(unsigned short*)g_GameVariables->m_ModelSpawnBypass = toggle ? 0x9090 : 0x0574;
}






//GameFunctions1::GameFunctions1() :
//	m_WndProc(Signature("48 8B 0D ? ? ? ? 48 8D 55 EF FF 15").Scan().Sub(0x385).As<decltype(m_WndProc)>()),
//	//m_HandleRemoveGamerCmd(Signature("41 FF C6 FF C7").Scan().Sub(0x6E).As<decltype(m_HandleRemoveGamerCmd)>()),
//	m_HandleRemoveGamerCmd(Signature("48 85 D2 0F 84 0E 04").Scan().As<decltype(m_HandleRemoveGamerCmd)>()),
//	m_ReadBitbufDWORD(Signature("48 89 74 24 ? 57 48 83 EC 20 48 8B D9 33 C9 41 8B F0 8A").Scan().Sub(5).As<decltype(m_ReadBitbufDWORD)>()),
//	m_ReadBitbufArray(Signature("48 89 5C 24 ? 57 48 83 EC 30 41 8B F8 4C").Scan().As<decltype(m_ReadBitbufArray)>()),
//	//m_ReadBitbufString(Signature("E8 ? ? ? ? 48 8D 4F 3C").Scan().Add(1).Rip().As<decltype(m_ReadBitbufString)>()),
//	m_ReadBitbufString(Signature("48 89 5C 24 08 48 89 6C 24 18 56 57 41 56 48 83 EC 20 48 8B F2 45").Scan().As<decltype(m_ReadBitbufString)>()),
//	//m_ReadBitbufBool(Signature("E8 ? ? ? ? 84 C0 74 41 48 8D 56 2C").Scan().Add(1).Rip().As<decltype(m_ReadBitbufBool)>()),
//	m_ReadBitbufBool(Signature("E8 ? ? ? ? 84 C0 74 41 48 8D 56 34").Scan().Add(1).Rip().As<decltype(m_ReadBitbufBool)>()),
//	m_WriteBitbufDWORD(Signature("48 8B C4 48 89 58 08 48 89 68 10 48 89 70 18 48 89 78 20 41 56 48 83 EC 20 8B EA BF 01").Scan().As<decltype(m_WriteBitbufDWORD)>()),
//	m_WriteBitbufQWORD(Signature("48 89 5C 24 08 48 89 6C 24 10 48 89 74 24 18 57 48 83 EC 20 41 8B F0 48 8B EA 48 8B D9 41 83 F8 20").Scan().As<decltype(m_WriteBitbufQWORD)>()),
//	m_WriteBitbufInt64(Signature("E8 ? ? ? ? 8A 53 39 48 8B CF").Scan().Add(1).Rip().As<decltype(m_WriteBitbufInt64)>()),
//	m_WriteBitbufInt32(Signature("E8 ? ? ? ? 8A 53 74").Scan().Add(1).Rip().As<decltype(m_WriteBitbufInt32)>()),
//	m_WriteBitbufBool(Signature("E8 ? ? ? ? 8A 57 39").Scan().Add(1).Rip().As<decltype(m_WriteBitbufBool)>()),
//	m_WriteBitbufArray(Signature("E8 ? ? ? ? 01 7E 08").Scan().Add(1).Rip().As<decltype(m_WriteBitbufArray)>()),
//	m_SendChatPointer(Signature("83 7E 1C 01 48 8B 3D").Scan().Add(7).Rip().As<int64_t**>()),
//	m_SendChatMessage(Signature("48 83 EC 20 48 8B F1 48 8B CA 41 8A E9").Scan().Sub(21).As<decltype(m_SendChatMessage)>()),
//	m_queue_packet(Signature("E8 ? ? ? ? 84 C0 74 4D B3 01").Scan().Add(1).Rip().As<queue_packet*>()),
//	m_send_packet(Signature("48 8B C4 48 89 58 08 48 89 70 10 48 89 78 18 4C 89 48 20 55 41 54 41 55 41 56 41 57 48 8D A8 98").Scan().As<send_packet*>()),
//	model_info(Signature("0F B7 05 ? ? ? ? 45 33 C9 4C 8B DA 66 85 C0 0F 84 ? ? ? ? 44 0F B7 C0 33 D2 8B C1 41 F7 F0 48 8B 05 ? ? ? ? 4C 8B 14 D0 EB 09 41 3B 0A 74 54").Scan().As<fpModelInfo>()),
//	get_entity_from_script_gu_id(Signature("E8 ? ? ? ? 8D 53 01 33 DB").Scan().Add(1).Rip().As<fpGetEntityFromScriptGuId>()),
//	m_script_vm(Signature("E8 ? ? ? ? 48 85 FF 48 89 1D").Scan().Add(1).Rip().As<script_vm*>()),
//	//m_trigger_script_event(Signature("45 8B F0 41 8B F9 48 8B EA").Scan().Sub(0x1C).As<decltype(m_trigger_script_event)>())
//	m_trigger_script_event(Signature("48 8B C4 48 89 58 08 44 89 48 20 55 56 57 48 83 EC 30").Scan().As<decltype(m_trigger_script_event)>())
//{
//
//	auto sig2 = Signature("8D 42 FF 83 F8 FD 77 3D").Scan();
//	m_GetConnectionPeer = sig2.Add(23).Rip().As<decltype(m_GetConnectionPeer)>();
//	m_SendRemoveGamerCmd = sig2.Add(65).Rip().As<decltype(m_SendRemoveGamerCmd)>();
//}
GameFunctions1::GameFunctions1() :
	m_WndProc(Signature("48 8B 0D ? ? ? ? 48 8D 55 EF FF 15", "m_WndProc").Scan().Sub(0x385).As<decltype(m_WndProc)>()),
	//m_HandleRemoveGamerCmd(Signature("41 FF C6 FF C7").Scan().Sub(0x6E).As<decltype(m_HandleRemoveGamerCmd)>()),
	//m_HandleRemoveGamerCmd(Signature("48 85 D2 0F 84 0E 04", "m_HandleRemoveGamerCmd").Scan().As<decltype(m_HandleRemoveGamerCmd)>()),
	m_HandleRemoveGamerCmd(Signature("74 74 33 FF", "m_HandleRemoveGamerCmd").Scan().Sub(0x38).As<decltype(m_HandleRemoveGamerCmd)>()),
	m_ReadBitbufDWORD(Signature("48 89 74 24 ? 57 48 83 EC 20 48 8B D9 33 C9 41 8B F0 8A", "m_ReadBitbufDWORD").Scan().Sub(5).As<decltype(m_ReadBitbufDWORD)>()),
	m_ReadBitbufArray(Signature("48 89 5C 24 ? 57 48 83 EC 30 41 8B F8 4C", "m_ReadBitbufArray").Scan().As<decltype(m_ReadBitbufArray)>()),
	//m_ReadBitbufString(Signature("E8 ? ? ? ? 48 8D 4F 3C").Scan().Add(1).Rip().As<decltype(m_ReadBitbufString)>()),
	m_ReadBitbufString(Signature("48 89 5C 24 08 48 89 6C 24 18 56 57 41 56 48 83 EC 20 48 8B F2 45", "m_ReadBitbufString").Scan().As<decltype(m_ReadBitbufString)>()),
	//m_ReadBitbufBool(Signature("E8 ? ? ? ? 84 C0 74 41 48 8D 56 2C").Scan().Add(1).Rip().As<decltype(m_ReadBitbufBool)>()),
	//m_ReadBitbufBool(Signature("E8 ? ? ? ? 84 C0 74 41 48 8D 56 34", "m_ReadBitbufBool").Scan().Add(1).Rip().As<decltype(m_ReadBitbufBool)>()),
	m_ReadBitbufBool(Signature("48 8B C4 48 89 58 08 55 56 57 48 83 EC 20 48 83 60", "m_ReadBitbufBool").Scan().Add(1).Rip().As<decltype(m_ReadBitbufBool)>()),
	m_WriteBitbufDWORD(Signature("48 8B C4 48 89 58 08 48 89 68 10 48 89 70 18 48 89 78 20 41 56 48 83 EC 20 8B EA BF 01", "m_WriteBitbufDWORD").Scan().As<decltype(m_WriteBitbufDWORD)>()),
	m_WriteBitbufQWORD(Signature("48 89 5C 24 08 48 89 6C 24 10 48 89 74 24 18 57 48 83 EC 20 41 8B F0 48 8B EA 48 8B D9 41 83 F8 20", "m_WriteBitbufQWORD").Scan().As<decltype(m_WriteBitbufQWORD)>()),
	m_WriteBitbufInt64(Signature("E8 ? ? ? ? 8A 53 39 48 8B CF", "m_WriteBitbufInt64").Scan().Add(1).Rip().As<decltype(m_WriteBitbufInt64)>()),
	m_WriteBitbufInt32(Signature("E8 ? ? ? ? 8A 53 74", "m_WriteBitbufInt32").Scan().Add(1).Rip().As<decltype(m_WriteBitbufInt32)>()),
	m_WriteBitbufBool(Signature("E8 ? ? ? ? 8A 57 39", "m_WriteBitbufBool").Scan().Add(1).Rip().As<decltype(m_WriteBitbufBool)>()),
	m_WriteBitbufArray(Signature("E8 ? ? ? ? 01 7E 08", "m_WriteBitbufArray").Scan().Add(1).Rip().As<decltype(m_WriteBitbufArray)>()),
	m_SendChatPointer(Signature("83 7E 1C 01 48 8B 3D", "m_SendChatPointer").Scan().Add(7).Rip().As<int64_t**>()),
	//m_SendChatMessage(Signature("48 83 EC 20 48 8B F1 48 8B CA 41 8A E9", "m_SendChatMessage").Scan().Sub(21).As<decltype(m_SendChatMessage)>()),
	m_SendChatMessage(Signature("48 81 EC 80 00 00 00 48 8B E9 48 8B CA 41", "m_SendChatMessage").Scan().Sub(21).As<decltype(m_SendChatMessage)>()),
	m_queue_packet(Signature("E8 ? ? ? ? 84 C0 74 4D B3 01", "m_queue_packet").Scan().Add(1).Rip().As<queue_packet*>()),
	m_send_packet(Signature("48 8B C4 48 89 58 08 48 89 70 10 48 89 78 18 4C 89 48 20 55 41 54 41 55 41 56 41 57 48 8D A8 98", "m_send_packet").Scan().As<send_packet*>()),
	model_info(Signature("0F B7 05 ? ? ? ? 45 33 C9 4C 8B DA 66 85 C0 0F 84 ? ? ? ? 44 0F B7 C0 33 D2 8B C1 41 F7 F0 48 8B 05 ? ? ? ? 4C 8B 14 D0 EB 09 41 3B 0A 74 54", "model_info").Scan().As<fpModelInfo>()),
	get_entity_from_script_gu_id(Signature("E8 ? ? ? ? 8D 53 01 33 DB", "get_entity_from_script_gu_id").Scan().Add(1).Rip().As<fpGetEntityFromScriptGuId>()),
	m_script_vm(Signature("E8 ? ? ? ? 48 85 FF 48 89 1D", "m_script_vm").Scan().Add(1).Rip().As<script_vm*>()),
	//m_trigger_script_event(Signature("45 8B F0 41 8B F9 48 8B EA").Scan().Sub(0x1C).As<decltype(m_trigger_script_event)>())
	m_trigger_script_event(Signature("48 8B C4 48 89 58 08 44 89 48 20 55 56 57 48 83 EC 30", "m_trigger_script_event").Scan().As<decltype(m_trigger_script_event)>())
{

	auto sig2 = Signature("8D 42 FF 83 F8 FD 77 3D", "sig2").Scan();
	m_GetConnectionPeer = sig2.Add(23).Rip().As<decltype(m_GetConnectionPeer)>();
	m_SendRemoveGamerCmd = sig2.Add(65).Rip().As<decltype(m_SendRemoveGamerCmd)>();
}

auto socialclub_region = Module("socialclub.dll");
//GameVariables1::GameVariables1() :
//	m_GameState(Signature("83 3D ? ? ? ? ? 75 17 8B 43 20 25").Scan().Add(2).Rip().Add(1).As<decltype(m_GameState)>()),
//	//m_GameState(Signature("48 85 C9 74 4B 83 3D").Scan().Add(7).Rip().As<decltype(m_GameState)>()),
//	m_FrameCount(Signature("8B 15 ? ? ? ? 41 FF CF").Scan().Add(2).Rip().As<decltype(m_FrameCount)>()),
//	m_GameWindow(FindWindowA("grcWindow", "Grand Theft Auto V")),
//	m_GlobalBase(Signature("4C 8D 4D 08 48 8D 15 ? ? ? ? 4C 8B C0").Scan().Add(7).Rip().As<decltype(m_GlobalBase)>()),
//	m_IsSessionStarted(Signature("44 38 1D ? ? ? ? 0F 84 ? ? ? ? 48 8B 01 FF 90 ? ? ? ? 48 8B 85").Scan().Add(3).Rip().As<bool*>()),
//	m_ped_factory(Signature("48 8B 05 ? ? ? ? 48 8B 48 08 48 85 C9 74 52 8B 81").Scan().Add(3).Rip().As<CPedFactory**>()),// decltype(m_ped_factory)
//	m_GetNetPlayer(Signature("48 83 EC 28 33 C0 38 05 ? ? ? ? 74 0A").Scan().As<decltype(m_GetNetPlayer)>()),
//	m_NetworkPlayerMgr(Signature("48 8B 0D ? ? ? ? 8A D3 48 8B 01 FF 50 ? 4C 8B 07 48 8B CF").Scan().Add(3).Rip().As<decltype(m_NetworkPlayerMgr)>()),
//	m_get_screen_coords_for_world_coords(Signature("E8 ? ? ? ? 84 C0 74 19 F3 0F 10 44 24").Scan().Add(1).Rip().As<decltype(m_get_screen_coords_for_world_coords)>()), //new
//	//m_NetworkInfo(Signature("44 8B 6C 24 ? 45 8B C6 48 8D 4E 70 41 8B D5 45 2B C5 4C 8D 4C 24 ? 03 D5 44 2B C5 49 03 D4 E8 ? ? ? ? 84 C0 74 69").Scan().Sub(0x64).As<decltype(m_NetworkInfo)>()),
//	m_NetworkInfo(Signature("48 8B EC 48 83 EC 50 49 8B F9 45 8B F8 4C 8B E2").Scan().Sub(24).As<decltype(m_NetworkInfo)>()),
//	m_give_pickup_rewards(Signature("48 8B C8 33 C0 48 85 C9 74 0A 44 8B C3 8B D7 E8").Scan().Sub(0x28).As<decltype(m_give_pickup_rewards)>()),
//	//m_WaypointCoords(Signature("74 1F F3 0F 10 05 ? ? ? ? F3 0F 11 03").Scan().Add(6).Rip().As<decltype(m_WaypointCoords)>()),
//	//m_FogModification(Signature("? ? ? ? 6F 12 83 3A 0A D7 23 3C 35 FA 8E 3C 08 21 04 3D 89 88 08 3D").Scan().As<float*>()),
//	//m_RainRed(Signature("? ? ? ? ? ? ? ? ? ? ? ? CD CC 4C 3E CD CC 4C 3D CD CC 4C 3D CD CC CC 3D ? ? C8 42 ? ? ? ? ? ? A0 C0 ? ? 80 3F ? ? C8 42 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 80 3F ? ? 80 3F ? ? 80 3F F7 7F ? ? ? ? 20 41 ? ? 48 42 ? ? ? 3F F7 7F ? ? 66 66 66 3F ? ? ? ? ? ? ? ? CD CC CC 3D ? ? 80 3F ? ? 60 40 ? ? FA 43 02 ? ? ? ? ? 80 3F CD CC 4C 3F ? ? ? ? ? ? ? ? 19 81 69 F4 01 ? ? ? 9A 99 99 3E ? ? 40").Scan().As<float*>()),//? ? ? ? ? ? ? ? ? ? ? ? CD CC 4C 3E CD CC 4C 3D CD CC 4C 3D CD CC CC 3D
//	//m_RainGreen(Signature("? ? ? ? ? ? ? ? CD CC 4C 3E CD CC 4C 3D CD CC 4C 3D CD CC CC 3D ? ? C8 42 ? ? ? ? ? ? A0 C0 ? ? 80 3F ? ? C8 42 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 80 3F ? ? 80 3F ? ? 80 3F F7 7F ? ? ? ? 20 41 ? ? 48 42 ? ? ? 3F F7 7F ? ? 66 66 66 3F ? ? ? ? ? ? ? ? CD CC CC 3D ? ? 80 3F ? ? 60 40 ? ? FA 43 02 ? ? ? ? ? 80 3F CD CC 4C 3F ? ? ? ? ? ? ? ? 19 81 69 F4 01 ? ? ? 9A 99 99 3E ? ? 40").Scan().As<float*>()),//? ? ? ? ? ? ? ? CD CC 4C 3E CD CC 4C 3D CD CC 4C 3D CD CC CC 3D
//	//m_RainBlue(Signature("? ? ? ? CD CC 4C 3E CD CC 4C 3D CD CC 4C 3D CD CC CC 3D ? ? C8 42 ? ? ? ? ? ? A0 C0 ? ? 80 3F ? ? C8 42 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 80 3F ? ? 80 3F ? ? 80 3F F7 7F ? ? ? ? 20 41 ? ? 48 42 ? ? ? 3F F7 7F ? ? 66 66 66 3F ? ? ? ? ? ? ? ? CD CC CC 3D ? ? 80 3F ? ? 60 40 ? ? FA 43 02 ? ? ? ? ? 80 3F CD CC 4C 3F ? ? ? ? ? ? ? ? 19 81 69 F4 01 ? ? ? 9A 99 99 3E ? ? 40").Scan().As<float*>()),//? ? ? ? CD CC 4C 3E CD CC 4C 3D CD CC 4C 3D CD CC CC 3D ? ? C8 42
//	//ui_3d_draw_manager(Signature("4C 8B 15 ? ? ? ? F3 0F 11 45 ? F3 0F 10 05 ? ? ? ? BF ? ? ? ? BB ? ? ? ? 41 BE ? ? ? ? F3 0F 11").Scan().As<decltype(ui_3d_draw_manager)>()),
//	//push_scene_preset_manager(Signature("40 53 48 83 EC 20 8B 02 48 8D 54 24 38 48 8B D9 89 44 24 38 E8 ? ? ? ? 48 8B C8").Scan().As<decltype(push_scene_preset_manager)>()),
//	//add_element_to_scene(Signature("4C 8B DC 48 83 EC 58 8B").Scan().As<decltype(add_element_to_scene)>()),
//	//set_scene_element_lighting(Signature("48 8B C4 48 89 58 10 48 89 70 18 57 48 83 EC 30 48 83 B9").Scan().As<decltype(set_scene_element_lighting)>()),
//	//get_scene_preset(Signature("0F B7 81 10 08 00 00").Scan().As<decltype(get_scene_preset)>()),
//	//m_weather_data(Signature("40 53 48 83 EC 30 0F 29 74 24 ? 48 8B D9 E8 ? ? ? ? F3 0F 10 83 ? ? ? ? F3 0F 10 35").Scan().As<PVOID>()),
//	//rightstreet(Signature("? ? ? ? 01 01 01 01 01 01 01 01 42 60 E5 3B 8F C2 F5 3C 01 ? ? ? FF FF ? ? 02 ? ? ? ? ? ? ? 09 D7 23 3C CC CC 4C 3E").Scan().As<float*>()),//1E33240
//	//activatetraffic2(Signature("? ? ? ? 0A D7 23 3C CD CC CC 3D CD CC CC 3D ? ? ? ? 01 01 01 01 01 01 01 01 42 60 E5 3B 8F C2 F5 3C 01 ? ? ? FF").Scan().As<float*>()),//1E33230
//	//pedspeed(Signature("? ? ? ? ? ? ? ? CD CC 1C C1 ? ? ? ? 6F 12 83 3A 6F 12 83 3A 6F 12 83 3A ? ? ? ? CD CC CC 3D ? ? ? ?").Scan().As<float*>()),//1E33310		
//	//shitter_crash(Signature("48 89 5C 24 08 48 89 6C 24 10 48 89 74 24 18 57 41 56 41 57 48 83 EC 20 48 8D 81 D4 ? ? ?").Scan().As<PVOID>()),//15E5690
//	//m_zenith_patch(Signature("0F 29 A2 B0 00 00 00 8B 81 58 03 00 00").Scan().As<decltype(m_zenith_patch)>()),//GTA5.exe+E3FF77
//	//m_zenith_transition_patch(Signature("0F 29 A2 E0 00 00 00").Scan().As<decltype(m_zenith_transition_patch)>()),//GTA5.exe+E3FFB1
//	//m_east_azimuth_patch(Signature("0F 29 62 20").Scan().As<decltype(m_east_azimuth_patch)>()),//GTA5.exe+E3FEC9
//	//m_west_azimuth_patch(Signature("0F 29 62 50 8B 81 9C 03 00 00").Scan().As<decltype(m_west_azimuth_patch)>()),//GTA5.exe+E3FEFD
//	//m_azimuth_transition_patch(Signature("0F 29 A2 80 00 00 00").Scan().As<decltype(m_azimuth_transition_patch)>()),//GTA5.exe+E3FF31
//	//m_cloud_base_patch(Signature("0F 29 A2 80 03 00 00").Scan().As<decltype(m_cloud_base_patch)>()),//GTA5.exe+E402F1
//	//red_zenith(Signature("? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 27 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 26 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 44 ? ? 80 42 ? ? ? 43 ? ? ? ? 25").Scan().As<float*>()),//GTA5.exe+26BB960
//	//green_zenith(Signature("? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 27 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 26 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 44 ? ? 80 42 ? ? ? 43 ? ? ? ? 25").Scan().As<float*>()),//GTA5.exe+26BB964
//	//blue_zenith(Signature("? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 27 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 26 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 44 ? ? 80 42 ? ? ? 43 ? ? ? ? 25").Scan().As<float*>()),//GTA5.exe+26BB968
//	//red_transition(Signature("? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 27 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 26 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 44 ? ? 80 42 ? ? ? 43 ? ? ? ? 25").Scan().As<float*>()),//GTA5.exe+26BB990 //GTA5.exe+26CEB80 - 00 60 60              - add [rax+60],ah
//	//green_transition(Signature("? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 27 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 26 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 44 ? ? 80 42 ? ? ? 43 ? ? ? ? 25").Scan().As<float*>()),//GTA5.exe+26BB994
//	//blue_transition(Signature("? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 27 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 26 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 44 ? ? 80 42 ? ? ? 43 ? ? ? ? 25").Scan().As<float*>()),//GTA5.exe+26BB998
//	m_Network(Signature("48 8B 0D ? ? ? ? 48 8B D7 E8 ? ? ? ? 84 C0 75 17 48 8B 0D ? ? ? ? 48 8B D7").Scan().Add(3).Rip().As<Network**>()),
//	//m_friend_registry(Signature("3B 0D ? ? ? ? 73 17").Scan().Add(2).Rip().As<FriendRegistry*>()),
//	m_script_program_table(Signature("48 8B 1D ? ? ? ? 41 83 F8 FF").Scan().Add(3).Rip().As<decltype(m_script_program_table)>()),
//	//m_IsSessionStarted(Signature("40 38 35 ? ? ? ? 75 0E 4C 8B C3 49 8B D7 49 8B CE").Scan().Add(3).Rip().As<bool*>()),
//	m_StartGetPresenceAttributes(Signature("48 8B C4 48 89 58 08 48 89 68 10 48 89 70 18 48 89 78 20 41 54 41 56 41 57 48 83 EC 40 33 DB 41").Scan(socialclub_region).As<decltype(m_StartGetPresenceAttributes)>()), 
//	m_StartGetSessionByGamerHandle(Signature("E8 ? ? ? ? 84 C0 0F 84 ? ? ? ? 8B 05 ? ? ? ? 48 8D 4C 24").Scan().Add(1).Rip().As<decltype(m_StartGetSessionByGamerHandle)>()), 
//	m_DecodePeerInfo(Signature("48 89 5C 24 08 48 89 74 24 10 57 48 81 EC C0 00 00 00 48 8B F1 49").Scan().As<DecodePeerInfo*>()),
//	m_ConnectToPeer(Signature("48 89 5C 24 08 4C 89 4C 24 20 48 89 54 24 10 55 56 57 41 54 41 55 41 56 41 57 48 83 EC 60 4D").Scan().As<decltype(m_ConnectToPeer)>()),
//	m_sc_info(Signature("48 8B D3 48 8D 4C 24 ? 48 69 D2").Scan().Sub(4).As<decltype(m_sc_info)>()),
//	m_script_globals(Signature("48 8D 15 ? ? ? ? 4C 8B C0 E8 ? ? ? ? 48 85 FF 48 89 1D").Scan().Add(3).Rip().As<decltype(m_script_globals)>()),
//	//m_ReplayInterface(Signature("0F B7 44 24 ? 66 89 44 4E").Scan().Add(0x1F).Rip().As<rage::CReplayInterface**>()),
//	m_PtrToHandle(Signature("48 8B F9 48 83 C1 10 33 DB").Scan().Sub(0x15).As<decltype(m_PtrToHandle)>()),
//	m_HandleToPtr(Signature("83 F9 FF 74 31 4C 8B 0D").Scan().As<decltype(m_HandleToPtr)>()),
//	//m_RequestControl(Signature("E8 ? ? ? ? EB 3E 48 8B D3").Scan().Add(1).Rip().As<decltype(m_RequestControl)>()),
//	m_MigrateObject(Signature("48 89 5C 24 08 48 89 6C 24 10 48 89 74 24 18 57 41 54 41 55 41 56 41 57 48 83 EC 20 41 8B F8 48").Scan().As<decltype(m_MigrateObject)>()),//MigrateObject*
//	//m_WriteVehicleProximityMigrationDataNode(Signature("48 89 4C 24 08 55 53 56 57 41 54 41 55 41 56 41 57 48 8B EC 48 83 EC 68 4C 8B A9").Scan().As<PVOID>()),
//	//m_ClearPedTaskNetwork(Signature("E8 ? ? ? ? EB 28 48 8B 8F A0 10 00 00").Scan().Add(1).Rip().As<decltype(m_ClearPedTaskNetwork)>()),
//	m_ModelSpawnBypass(Signature("48 8B C8 FF 52 30 84 C0 74 05 48").Scan().Add(8).As<decltype(m_ModelSpawnBypass)>()),
//	m_ExplosionBypass(Signature("48 8B F1 74 56").Scan().Add(3).As<PVOID>())
//
//{
//
//	auto GameVersion = Signature("8B C3 33 D2 C6 44 24 20").Scan();
//	/*m_game_version = GameVersion.Add(0x24).Rip().As<const char*>();
//	m_online_version = GameVersion.Add(0x24).Rip().Add(0x20).As<const char*>();*/
//	auto signature4 = Signature("45 33 F6 8B E9 85 C9 B8").Scan();
//	m_scriptThreads = signature4.Sub(4).Rip().Sub(8).As<decltype(m_scriptThreads)>();
//	m_RunScriptThreads = signature4.Sub(0x1F).As<RunScriptThreads*>();
//
//
//	auto signature5 = Signature("48 8D 0D ? ? ? ? 48 8B 14 FA E8 ? ? ? ? 48 85 C0 75 0A").Scan();
//	m_native_registration_table = signature5.Add(3).Rip().As< rage::scrNativeRegistrationTable*>();
//	m_get_native_handler = signature5.Add(12).Rip().As<get_native_handler>();
//
//	/*auto signature_2 = Signature("48 8B 05 ? ? ? ? 8A D1").Scan().As<decltype(m_WorldBase)>();*/
//	auto signature_2 = Signature("48 8B 05 ? ? ? ? 45 ? ? ? ? 48 8B 48 08 48 85 C9 74 07").Scan().As<decltype(m_WorldBase)>();
//
//	m_WorldBase = GetAddressFromInstruction(signature_2);
//
//	auto resolution = Signature("66 0F 6E 0D ? ? ? ? 0F B7 3D").Scan();
//	m_resolution_x = resolution.Sub(4).Rip().As<int*>();
//	m_resolution_y = resolution.Add(4).Rip().As<int*>();
//
//	__int64 patternAdd = NULL;
//	auto p_viewport = Signature("48 8B 15 ? ? ? ? 48 8D 2D ? ? ? ? 48 8B CD").Scan().As<char*>();
//	//if (p_viewport != 0) {
//	//	patternAdd = reinterpret_cast<decltype(patternAdd)>(p_viewport);
//
//	//	// Calcul de l'adresse de m_viewPort à partir du pattern
//	//	uintptr_t m_viewPortAddress = *reinterpret_cast<uintptr_t*>(patternAdd + *reinterpret_cast<int*>(patternAdd));
//
//	//	// Utilisation de l'adresse m_viewPort pour accéder à l'objet CViewPort
//	//	// Assurez-vous que la structure CViewPort est correctement définie
//	//	/*CViewPort* m_viewPort = reinterpret_cast<CViewPort*>(m_viewPortAddress);*/
//	//	m_viewPort = reinterpret_cast<CViewPort*>(m_viewPortAddress);
//	//}
//	patternAdd = NULL;
//	patternAdd = reinterpret_cast<decltype(patternAdd)>(p_viewport);
//	//m_viewPort = *reinterpret_cast<CViewPort**>(patternAdd + *reinterpret_cast<int*>(patternAdd));
//	m_viewPort = *reinterpret_cast<CViewPort**>(patternAdd + *reinterpret_cast<int*>(patternAdd + 3) + 7);
//}
GameVariables1::GameVariables1() :
	//m_GameState(Signature("83 3D ? ? ? ? ? 75 17 8B 43 20 25", "m_GameState").Scan().Add(2).Rip().Add(1).As<decltype(m_GameState)>()),
	m_GameState(Signature("83 3D ? ? ? ? ? 75 17 8B 43 20 25", "m_GameState").Scan().Add(2).Rip().Add(1).As<GameState*>()),
	//m_GameState(Signature("83 3D ? ? ? ? ? 75 17 8B 43 20 25", "m_GameState").Scan().Add(7).Rip().As<decltype(m_GameState)>()),//48 85 C9 74 4B 83 3D
	m_FrameCount(Signature("8B 15 ? ? ? ? 41 FF CF", "m_FrameCount").Scan().Add(2).Rip().As<decltype(m_FrameCount)>()),
	m_GameWindow(FindWindowA("grcWindow", "Grand Theft Auto V")),
	m_GlobalBase(Signature("4C 8D 4D 08 48 8D 15 ? ? ? ? 4C 8B C0", "m_GlobalBase").Scan().Add(7).Rip().As<decltype(m_GlobalBase)>()),
	m_IsSessionStarted(Signature("44 38 1D ? ? ? ? 0F 84 ? ? ? ? 48 8B 01 FF 90 ? ? ? ? 48 8B 85", "m_IsSessionStarted").Scan().Add(3).Rip().As<bool*>()),
	m_ped_factory(Signature("48 8B 05 ? ? ? ? 48 8B 48 08 48 85 C9 74 52 8B 81", "m_ped_factory").Scan().Add(3).Rip().As<CPedFactory**>()),// decltype(m_ped_factory)
	m_GetNetPlayer(Signature("48 83 EC 28 33 C0 38 05 ? ? ? ? 74 0A", "m_GetNetPlayer").Scan().As<decltype(m_GetNetPlayer)>()),
	m_NetworkPlayerMgr(Signature("48 8B 0D ? ? ? ? 8A D3 48 8B 01 FF 50 ? 4C 8B 07 48 8B CF", "m_NetworkPlayerMgr").Scan().Add(3).Rip().As<decltype(m_NetworkPlayerMgr)>()),
	m_get_screen_coords_for_world_coords(Signature("E8 ? ? ? ? 84 C0 74 19 F3 0F 10 44 24", "m_get_screen_coords_for_world_coords").Scan().Add(1).Rip().As<decltype(m_get_screen_coords_for_world_coords)>()), //new
	//m_NetworkInfo(Signature("44 8B 6C 24 ? 45 8B C6 48 8D 4E 70 41 8B D5 45 2B C5 4C 8D 4C 24 ? 03 D5 44 2B C5 49 03 D4 E8 ? ? ? ? 84 C0 74 69", "m_NetworkInfo").Scan().Sub(0x64).As<decltype(m_NetworkInfo)>()),
	m_NetworkInfo(Signature("48 8B EC 48 83 EC 50 49 8B F9 45 8B F8 4C 8B E2", "m_NetworkInfo").Scan().Sub(24).As<decltype(m_NetworkInfo)>()),
	m_give_pickup_rewards(Signature("48 8B C8 33 C0 48 85 C9 74 0A 44 8B C3 8B D7 E8", "m_give_pickup_rewards").Scan().Sub(0x28).As<decltype(m_give_pickup_rewards)>()),
	//m_WaypointCoords(Signature("74 1F F3 0F 10 05 ? ? ? ? F3 0F 11 03").Scan().Add(6).Rip().As<decltype(m_WaypointCoords)>()),
	//m_FogModification(Signature("? ? ? ? 6F 12 83 3A 0A D7 23 3C 35 FA 8E 3C 08 21 04 3D 89 88 08 3D").Scan().As<float*>()),
	//m_RainRed(Signature("? ? ? ? ? ? ? ? ? ? ? ? CD CC 4C 3E CD CC 4C 3D CD CC 4C 3D CD CC CC 3D ? ? C8 42 ? ? ? ? ? ? A0 C0 ? ? 80 3F ? ? C8 42 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 80 3F ? ? 80 3F ? ? 80 3F F7 7F ? ? ? ? 20 41 ? ? 48 42 ? ? ? 3F F7 7F ? ? 66 66 66 3F ? ? ? ? ? ? ? ? CD CC CC 3D ? ? 80 3F ? ? 60 40 ? ? FA 43 02 ? ? ? ? ? 80 3F CD CC 4C 3F ? ? ? ? ? ? ? ? 19 81 69 F4 01 ? ? ? 9A 99 99 3E ? ? 40").Scan().As<float*>()),//? ? ? ? ? ? ? ? ? ? ? ? CD CC 4C 3E CD CC 4C 3D CD CC 4C 3D CD CC CC 3D
	//m_RainGreen(Signature("? ? ? ? ? ? ? ? CD CC 4C 3E CD CC 4C 3D CD CC 4C 3D CD CC CC 3D ? ? C8 42 ? ? ? ? ? ? A0 C0 ? ? 80 3F ? ? C8 42 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 80 3F ? ? 80 3F ? ? 80 3F F7 7F ? ? ? ? 20 41 ? ? 48 42 ? ? ? 3F F7 7F ? ? 66 66 66 3F ? ? ? ? ? ? ? ? CD CC CC 3D ? ? 80 3F ? ? 60 40 ? ? FA 43 02 ? ? ? ? ? 80 3F CD CC 4C 3F ? ? ? ? ? ? ? ? 19 81 69 F4 01 ? ? ? 9A 99 99 3E ? ? 40").Scan().As<float*>()),//? ? ? ? ? ? ? ? CD CC 4C 3E CD CC 4C 3D CD CC 4C 3D CD CC CC 3D
	//m_RainBlue(Signature("? ? ? ? CD CC 4C 3E CD CC 4C 3D CD CC 4C 3D CD CC CC 3D ? ? C8 42 ? ? ? ? ? ? A0 C0 ? ? 80 3F ? ? C8 42 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 80 3F ? ? 80 3F ? ? 80 3F F7 7F ? ? ? ? 20 41 ? ? 48 42 ? ? ? 3F F7 7F ? ? 66 66 66 3F ? ? ? ? ? ? ? ? CD CC CC 3D ? ? 80 3F ? ? 60 40 ? ? FA 43 02 ? ? ? ? ? 80 3F CD CC 4C 3F ? ? ? ? ? ? ? ? 19 81 69 F4 01 ? ? ? 9A 99 99 3E ? ? 40").Scan().As<float*>()),//? ? ? ? CD CC 4C 3E CD CC 4C 3D CD CC 4C 3D CD CC CC 3D ? ? C8 42
	//ui_3d_draw_manager(Signature("4C 8B 15 ? ? ? ? F3 0F 11 45 ? F3 0F 10 05 ? ? ? ? BF ? ? ? ? BB ? ? ? ? 41 BE ? ? ? ? F3 0F 11").Scan().As<decltype(ui_3d_draw_manager)>()),
	//push_scene_preset_manager(Signature("40 53 48 83 EC 20 8B 02 48 8D 54 24 38 48 8B D9 89 44 24 38 E8 ? ? ? ? 48 8B C8").Scan().As<decltype(push_scene_preset_manager)>()),
	//add_element_to_scene(Signature("4C 8B DC 48 83 EC 58 8B").Scan().As<decltype(add_element_to_scene)>()),
	//set_scene_element_lighting(Signature("48 8B C4 48 89 58 10 48 89 70 18 57 48 83 EC 30 48 83 B9").Scan().As<decltype(set_scene_element_lighting)>()),
	//get_scene_preset(Signature("0F B7 81 10 08 00 00").Scan().As<decltype(get_scene_preset)>()),
	//m_weather_data(Signature("40 53 48 83 EC 30 0F 29 74 24 ? 48 8B D9 E8 ? ? ? ? F3 0F 10 83 ? ? ? ? F3 0F 10 35").Scan().As<PVOID>()),
	//rightstreet(Signature("? ? ? ? 01 01 01 01 01 01 01 01 42 60 E5 3B 8F C2 F5 3C 01 ? ? ? FF FF ? ? 02 ? ? ? ? ? ? ? 09 D7 23 3C CC CC 4C 3E").Scan().As<float*>()),//1E33240
	//activatetraffic2(Signature("? ? ? ? 0A D7 23 3C CD CC CC 3D CD CC CC 3D ? ? ? ? 01 01 01 01 01 01 01 01 42 60 E5 3B 8F C2 F5 3C 01 ? ? ? FF").Scan().As<float*>()),//1E33230
	//pedspeed(Signature("? ? ? ? ? ? ? ? CD CC 1C C1 ? ? ? ? 6F 12 83 3A 6F 12 83 3A 6F 12 83 3A ? ? ? ? CD CC CC 3D ? ? ? ?").Scan().As<float*>()),//1E33310		
	//shitter_crash(Signature("48 89 5C 24 08 48 89 6C 24 10 48 89 74 24 18 57 41 56 41 57 48 83 EC 20 48 8D 81 D4 ? ? ?").Scan().As<PVOID>()),//15E5690
	//m_zenith_patch(Signature("0F 29 A2 B0 00 00 00 8B 81 58 03 00 00").Scan().As<decltype(m_zenith_patch)>()),//GTA5.exe+E3FF77
	//m_zenith_transition_patch(Signature("0F 29 A2 E0 00 00 00").Scan().As<decltype(m_zenith_transition_patch)>()),//GTA5.exe+E3FFB1
	//m_east_azimuth_patch(Signature("0F 29 62 20").Scan().As<decltype(m_east_azimuth_patch)>()),//GTA5.exe+E3FEC9
	//m_west_azimuth_patch(Signature("0F 29 62 50 8B 81 9C 03 00 00").Scan().As<decltype(m_west_azimuth_patch)>()),//GTA5.exe+E3FEFD
	//m_azimuth_transition_patch(Signature("0F 29 A2 80 00 00 00").Scan().As<decltype(m_azimuth_transition_patch)>()),//GTA5.exe+E3FF31
	//m_cloud_base_patch(Signature("0F 29 A2 80 03 00 00").Scan().As<decltype(m_cloud_base_patch)>()),//GTA5.exe+E402F1
	//red_zenith(Signature("? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 27 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 26 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 44 ? ? 80 42 ? ? ? 43 ? ? ? ? 25").Scan().As<float*>()),//GTA5.exe+26BB960
	//green_zenith(Signature("? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 27 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 26 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 44 ? ? 80 42 ? ? ? 43 ? ? ? ? 25").Scan().As<float*>()),//GTA5.exe+26BB964
	//blue_zenith(Signature("? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 27 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 26 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 44 ? ? 80 42 ? ? ? 43 ? ? ? ? 25").Scan().As<float*>()),//GTA5.exe+26BB968
	//red_transition(Signature("? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 27 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 26 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 44 ? ? 80 42 ? ? ? 43 ? ? ? ? 25").Scan().As<float*>()),//GTA5.exe+26BB990 //GTA5.exe+26CEB80 - 00 60 60              - add [rax+60],ah
	//green_transition(Signature("? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 27 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 26 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 44 ? ? 80 42 ? ? ? 43 ? ? ? ? 25").Scan().As<float*>()),//GTA5.exe+26BB994
	//blue_transition(Signature("? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 27 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 26 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 44 ? ? 80 42 ? ? ? 43 ? ? ? ? 25").Scan().As<float*>()),//GTA5.exe+26BB998
	m_Network(Signature("48 8B 0D ? ? ? ? 48 8B D7 E8 ? ? ? ? 84 C0 75 17 48 8B 0D ? ? ? ? 48 8B D7", "m_Network").Scan().Add(3).Rip().As<Network**>()),
	//m_friend_registry(Signature("3B 0D ? ? ? ? 73 17").Scan().Add(2).Rip().As<FriendRegistry*>()),
	m_script_program_table(Signature("48 8B 1D ? ? ? ? 41 83 F8 FF", "m_script_program_table").Scan().Add(3).Rip().As<decltype(m_script_program_table)>()),
	//m_IsSessionStarted(Signature("40 38 35 ? ? ? ? 75 0E 4C 8B C3 49 8B D7 49 8B CE").Scan().Add(3).Rip().As<bool*>()),
	m_StartGetPresenceAttributes(Signature("48 8B C4 48 89 58 08 48 89 68 10 48 89 70 18 48 89 78 20 41 54 41 56 41 57 48 83 EC 40 33 DB 41", "m_StartGetPresenceAttributes").Scan(socialclub_region).As<decltype(m_StartGetPresenceAttributes)>()),
	m_StartGetSessionByGamerHandle(Signature("E8 ? ? ? ? 84 C0 0F 84 ? ? ? ? 8B 05 ? ? ? ? 48 8D 4C 24", "m_StartGetSessionByGamerHandle").Scan().Add(1).Rip().As<decltype(m_StartGetSessionByGamerHandle)>()),
	m_DecodePeerInfo(Signature("48 89 5C 24 08 48 89 74 24 10 57 48 81 EC C0 00 00 00 48 8B F1 49", "m_DecodePeerInfo").Scan().As<DecodePeerInfo*>()),
	//m_DecodePeerInfo(Signature("48 89 5C 24 08 48 89 74 24 10 57 48 81 EC C0 00 00 00 48 8B F1 49", "m_DecodePeerInfo").Scan().As<DecodePeerInfo*>()),
	m_ConnectToPeer(Signature("48 89 5C 24 08 4C 89 4C 24 20 48 89 54 24 10 55 56 57 41 54 41 55 41 56 41 57 48 83 EC 60 4D", "m_ConnectToPeer").Scan().As<decltype(m_ConnectToPeer)>()),
	m_sc_info(Signature("48 8B D3 48 8D 4C 24 ? 48 69 D2", "m_sc_info").Scan().Sub(4).As<decltype(m_sc_info)>()),
	m_script_globals(Signature("48 8D 15 ? ? ? ? 4C 8B C0 E8 ? ? ? ? 48 85 FF 48 89 1D", "m_script_globals").Scan().Add(3).Rip().As<decltype(m_script_globals)>()),
	//m_ReplayInterface(Signature("0F B7 44 24 ? 66 89 44 4E").Scan().Add(0x1F).Rip().As<rage::CReplayInterface**>()),
	m_PtrToHandle(Signature("48 8B F9 48 83 C1 10 33 DB", "m_PtrToHandle").Scan().Sub(0x15).As<decltype(m_PtrToHandle)>()),
	m_HandleToPtr(Signature("83 F9 FF 74 31 4C 8B 0D", "m_HandleToPtr").Scan().As<decltype(m_HandleToPtr)>()),
	//m_RequestControl(Signature("E8 ? ? ? ? EB 3E 48 8B D3").Scan().Add(1).Rip().As<decltype(m_RequestControl)>()),
	m_MigrateObject(Signature("48 89 5C 24 08 48 89 6C 24 10 48 89 74 24 18 57 41 54 41 55 41 56 41 57 48 83 EC 20 41 8B F8 48", "m_MigrateObject").Scan().As<decltype(m_MigrateObject)>()),//MigrateObject*
	//m_WriteVehicleProximityMigrationDataNode(Signature("48 89 4C 24 08 55 53 56 57 41 54 41 55 41 56 41 57 48 8B EC 48 83 EC 68 4C 8B A9").Scan().As<PVOID>()),
	//m_ClearPedTaskNetwork(Signature("E8 ? ? ? ? EB 28 48 8B 8F A0 10 00 00").Scan().Add(1).Rip().As<decltype(m_ClearPedTaskNetwork)>()),
	m_ModelSpawnBypass(Signature("48 8B C8 FF 52 30 84 C0 74 05 48", "m_ModelSpawnBypass").Scan().Add(8).As<decltype(m_ModelSpawnBypass)>()),
	m_TimecycleOverride(Signature("48 83 EC 18 48 8B 0D", "m_TimecycleOverride").Scan().As<PVOID>()),
	m_ExplosionBypass(Signature("48 8B F1 74 56", "m_ExplosionBypass").Scan().Add(3).As<PVOID>())
{

	auto GameVersion = Signature("8B C3 33 D2 C6 44 24 20", "GameVersion").Scan();
	/*m_game_version = GameVersion.Add(0x24).Rip().As<const char*>();
	m_online_version = GameVersion.Add(0x24).Rip().Add(0x20).As<const char*>();*/
	auto signature4 = Signature("45 33 F6 8B E9 85 C9 B8", "signature4").Scan();
	m_scriptThreads = signature4.Sub(4).Rip().Sub(8).As<decltype(m_scriptThreads)>();
	m_RunScriptThreads = signature4.Sub(0x1F).As<RunScriptThreads*>();


	auto signature5 = Signature("48 8D 0D ? ? ? ? 48 8B 14 FA E8 ? ? ? ? 48 85 C0 75 0A", "signature5").Scan();
	m_native_registration_table = signature5.Add(3).Rip().As< rage::scrNativeRegistrationTable*>();
	m_get_native_handler = signature5.Add(12).Rip().As<get_native_handler>();

	auto signature_2 = Signature("48 8B 05 ? ? ? ? 8A D1", "signature_2").Scan().As<decltype(m_WorldBase)>();
	m_WorldBase = GetAddressFromInstruction(signature_2);

	auto resolution = Signature("66 0F 6E 0D ? ? ? ? 0F B7 3D", "resolution").Scan();
	m_resolution_x = resolution.Sub(4).Rip().As<int*>();
	m_resolution_y = resolution.Add(4).Rip().As<int*>();

	__int64 patternAdd = NULL;
	auto p_viewport = Signature("48 8B 15 ? ? ? ? 48 8D 2D ? ? ? ? 48 8B CD", "p_viewport").Scan().As<char*>();
	patternAdd = NULL;
	patternAdd = reinterpret_cast<decltype(patternAdd)>(p_viewport);
	m_viewPort = *reinterpret_cast<CViewPort**>(patternAdd + *reinterpret_cast<int*>(patternAdd + 3) + 7);

}
bool CallbackScript::IsInitialized()
{
	return m_Initialized;
}

ScriptType CallbackScript::GetType()
{
	return ScriptType::Game;
}

void CallbackScript::Initialize()
{
	m_Initialized = true;
}

void CallbackScript::Destroy()
{
}

void CallbackScript::Tick()
{
	for (auto it = m_Callbacks.begin(); it != m_Callbacks.end();)
	{
		auto&& cb = *it;
		if (cb->IsDone())
		{
			cb->OnSuccess();
			it = m_Callbacks.erase(it);
		}
		else
		{
			cb->OnFailure();
			++it;
		}
	}
}

Vector2 wtos::WorldToScreen(Vector3 pos)
{
	Vector3 v3;
	float* viewMatrix = g_GameVariables->m_viewPort->fViewMatrix;
	v3.x = (viewMatrix[1] * pos.x) + (viewMatrix[5] * pos.y) + (viewMatrix[9] * pos.z) + viewMatrix[13];
	v3.y = (viewMatrix[2] * pos.x) + (viewMatrix[6] * pos.y) + (viewMatrix[10] * pos.z) + viewMatrix[14];
	v3.z = (viewMatrix[3] * pos.x) + (viewMatrix[7] * pos.y) + (viewMatrix[11] * pos.z) + viewMatrix[15];
	v3.z = 1.0f / v3.z;
	v3.x *= v3.z;
	v3.y *= v3.z;

	/*HWND hwnd = GetDesktopWindow();
	RECT desktop;
	GetWindowRect(hwnd, &desktop);
	float xTmp = desktop.right * 0.5f;
	float yTmp = desktop.bottom * 0.5f;*/

	/*HWND hwnd = GetDesktopWindowWithRetry();
	RECT desktop;
	GetWindowRect(hwnd, &desktop);*/
	/*m_resolution_x = desktop.right;
	m_resolution_y = desktop.bottom;*/

	//HWND hwnd = GetForegroundWindow();

	//// Obtenez les dimensions de la fenêtre active
	//RECT windowRect;
	//GetWindowRect(hwnd, &windowRect);
	//int windowWidth = windowRect.right - windowRect.left;
	//int windowHeight = windowRect.bottom - windowRect.top;

	/*float xTmp = static_cast<float>(desktop.right) * 0.5f;
	float yTmp = static_cast<float>(desktop.bottom) * 0.5f;*/

	HWND hwnd = FindWindow(nullptr, L"Grand Theft Auto V");
	//HWND hwnd = GetForegroundWindow();

	// Obtenez les dimensions de la fenêtre active
	RECT windowRect;
	GetWindowRect(hwnd, &windowRect);

	float windowWidth = static_cast<float>(windowRect.right - windowRect.left);
	float windowHeight = static_cast<float>(windowRect.bottom - windowRect.top);

	v3.x = (v3.x * windowWidth) + (windowWidth / 2.0f);
	v3.y = windowHeight - ((v3.y * windowHeight) + (windowHeight / 2.0f));

	// Convertir les dimensions en float
	/*float windowWidth = static_cast<float>(windowRect.right - windowRect.left);
	float windowHeight = static_cast<float>(windowRect.bottom - windowRect.top);

	v3.x += windowWidth + (int)(0.5f * v3.x * windowWidth + 0.5f);
	v3.y = windowHeight - (int)(0.5f * v3.y * windowHeight + 0.5f);*/
	/*float xTmp = static_cast<float>(*g_GameVariables->m_resolution_x) * 0.5f;
	float yTmp = static_cast<float>(*g_GameVariables->m_resolution_y) * 0.5f;

	//v3.x += xTmp + (int)(0.5f * v3.x * *g_GameVariables->m_resolution_x + 0.5f);
	//v3.y = yTmp - (int)(0.5f * v3.y * *g_GameVariables->m_resolution_y + 0.5f);

	v3.x += xTmp + (int)(0.5f * v3.x * *g_GameVariables->m_resolution_x + 0.5f);
	v3.y = yTmp - (int)(0.5f * v3.y * *g_GameVariables->m_resolution_y + 0.5f);*/
	Vector2 Coords = { v3.x, v3.y };
	return Coords;
}