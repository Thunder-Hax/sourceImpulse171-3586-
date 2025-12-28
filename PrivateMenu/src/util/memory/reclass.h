#pragma once
#if _WIN32
#include <intrin.h>
#endif

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


#include <cstddef>
#include <cstdint>
#include <utility>
#include "util/types.h"

#include <cmath>
#pragma pack(push, 1)

#pragma warning(disable: 4242) // Désactiver l'avertissement C4242
// Code causant le warning C4242
//#pragma warning(default: 4242) // Rétablir l'avertissement par défaut

// Generated using ReClassEx

class CWorld;
class CPeda;
class CPedb;
class CPedhand;
class CVehicle;
class CVehiclea;
class CVehicleDeformation;
class CHandlingData;
class CPlayerInfo;
class CWeaponManager;
class CWeapon;
class CAmmoInfo;
class CVehicleDrawHandler;
class CVehicleDrawHandlera;
class CVehicleSteamRenderGFX;
class CVehicleStreamRender;
class CWeaponInfo;
class CReplayInterface;
class CCameraInterface;
class CVehicleInterface;
class CPedInterface;
class CPickupInterface;
class CObjectInterface;
class CPickupList;
class CVehList;
class CObjectList;
class CObjectHandle;
class CAimingInfo;
class CNetGamePlayer;
class CAIHandlingInfo;
class CSubHandlingData;
class CFlyingHandlingData;
class CBoatHandlingData;
class CBikeHandlingData;
class CModelInfo;
class CPedDrawHandler;
class CVehicleWeaponHandlingData;
class CNetEventInfo;
class CNetEventVTable;
class CMetric;
class CFragInst;
class CArcheTypeDamp;
class CFragType;
class CFragPhysicsLODGroup;
class CFragPhysicsLOD;
class CGroupNames;
class Groups;
class phBoundComposite;
class CEntitySkeleton;
class crSkeletonData;
class NativeMatrix;
class crSkeletonBoneDataArray;
class crSkeletonBoneData;
class CHostStruct;


#define DEFINE_RAGE_RTTI(className)    private:\
								virtual void* _0x00() = 0;\
								virtual void* _0x08() = 0;\
								virtual uint32_t _0x10() = 0;\
								virtual className* _0x18(void*) = 0;\
								virtual bool _0x20(void*) = 0;\
								virtual bool _0x28(void**) = 0;\
								virtual void destructor() = 0;\
								public:

#define PlayerId2 PLAYER::PlayerId()

namespace rage
{
#pragma warning(disable : 4324)

	using joaat_t = std::uint32_t;

	inline constexpr char joaat_to_lower(char c)
	{
		return (c >= 'A' && c <= 'Z') ? c + ('a' - 'A') : c;
	}

	template <std::size_t CharCount>
	struct constexpr_joaat
	{
		char data[CharCount];

		template <std::size_t... Indices>
		constexpr constexpr_joaat(const char* str, std::index_sequence<Indices...>) :
			data{ (str[Indices])... }
		{
		}

		constexpr joaat_t operator()()
		{
			joaat_t hash = 0;

			for (std::size_t i = 0; i < CharCount; ++i)
			{
				hash += joaat_to_lower(data[i]);
				hash += (hash << 10);
				hash ^= (hash >> 6);
			}

			hash += (hash << 3);
			hash ^= (hash >> 11);
			hash += (hash << 15);

			return hash;
		}
	};

	inline joaat_t joaat(std::string_view str)
	{
		joaat_t hash = 0;

		for (char c : str)
		{
			hash += joaat_to_lower(c);
			hash += (hash << 10);
			hash ^= (hash >> 6);
		}

		hash += (hash << 3);
		hash ^= (hash >> 11);
		hash += (hash << 15);

		return hash;
	}

	inline joaat_t joaat(const char* str)
	{
		joaat_t hash = 0;

		while (*str)
		{
			hash += joaat_to_lower(*(str++));
			hash += (hash << 10);
			hash ^= (hash >> 6);
		}

		hash += (hash << 3);
		hash ^= (hash >> 11);
		hash += (hash << 15);

		return hash;
	}

	/*class scrNativeRegistrationTable
	{
		scrNativeRegistration* m_entries[0xFF];
		std::uint32_t m_unk;
		bool m_initialized;
	};*/

}

#define RAGE_JOAAT_IMPL(str) (::rage::constexpr_joaat<sizeof(str) - 1>((str), std::make_index_sequence<sizeof(str) - 1>())())
#define RAGE_JOAAT(str) (std::integral_constant<rage::joaat_t, RAGE_JOAAT_IMPL(str)>::value) //CONSTEXPR_JOAAT

using joaat_t = std::uint32_t;

typedef unsigned __int64 QWORD;

class CDrawable {
public:
	char _0x0000[0x28];
	uint8_t m_type; //0x28
	char _0x0029[0x53];
	float m_width; //0x7C
	char _0x0080[0xC];
	float m_height; //0x86
	Vector3_t m_position; //0x90
	float m_anotherX;
	char _0x00A0[0x10];
	int m_lod;

	Vector3 GetPosition() {
		Vector3 pos;
		pos.x = m_position.x;
		pos.y = m_position.y;
		pos.z = m_position.z;

		return pos;
	}

	void SetPosition(Vector3 pos) {
		m_position.x = pos.x;
		m_position.y = pos.y;
		m_position.z = pos.z;
		m_anotherX = pos.x;
	}

	bool IsDrawable() {
		return m_type == 1;
	}

	bool IsScaleAccurate() {
		return m_width == m_height;
	}

	float GetEstimatedScale() {
		return m_width > m_height ? m_width : m_height;
	}

	Vector2 GetScale() {
		return Vector2(m_width, m_height);
	}

	void AddToScale(float scale) {
		// maintain aspect-ratio?
		m_width = m_width + scale;
		m_height = m_height + scale;
	}

	void SetScale(float scale) {
		// i think that the width and height of an entity is defaulted at 1
		m_width = scale;
		m_height = scale;
	}

	int GetLod() {
		return m_lod;
	}

	void SetLod(int lod) {
		m_lod = lod;
	}
};

class CPedhand {
public:
	char pad_0x00002[0x20]; //0x0000
	CModelInfo* ModelInfo2; //0x0020 
	char pad_0x00282[0x20]; //0x0028
	CPedDrawHandler* PedDrawHandler2; //0x0048 
	char pad_0x00502[0x10]; //0x0050
	Matrix TransformationMatrix2; //0x0060 
	char pad_0x00A02[0x1E0]; //0x00A0
	float Health2; //0x0280 
	char pad_0x02842[0x1C]; //0x0284
	float MaxHealth2; //0x02A0 
	char pad_0x02A42[0xA6C]; //0xA6C//0xA84 //0x02A4
	CVehiclea* m_playerVehicle2; //0x0D28 
	char pad_0x0D302[0x378]; //0x388//0x0D30
	CPlayerInfo* PlayerInfo2; //0x10B8 //0x10A8
	char pad_0x10C02[0x8]; //0x8 //0x10C0
	CWeaponManager* m_weaponManager2; //0x10C8 
	char pad_0x10D02[0x13C0]; //0x10D0
}; //Size=0x2490
class CPedb {
public:
	char pad_0x00001[0x20]; //0x0000
	CModelInfo* ModelInfo1; //0x0020 
	char pad_0x00281[0x20]; //0x0028
	CPedDrawHandler* PedDrawHandler1; //0x0048 
	char pad_0x00501[0x10]; //0x0050
	Matrix TransformationMatrix1; //0x0060 
	char pad_0x00A01[0x1E0]; //0x00A0
	float Health1; //0x0280 
	char pad_0x02841[0x1C]; //0x0284
	float MaxHealth1; //0x02A0 
	char pad_0x02A41[0xA84]; //0x02A4
	CVehiclea* m_playerVehicle1; //0x0D28 
	char pad_0x0D301[0x388]; //0x0D30
	CPlayerInfo* PlayerInfo1; //0x10B8 
	char pad_0x10C01[0x8]; //0x10C0
	CWeaponManager* m_weaponManager1; //0x10C8 
	char pad_0x10D01[0x13C0]; //0x10D0

}; //Size=0x2490

class CWorld {
public:
	char pad_0x0000[0x8]; //0x0000
	CPedb* LocalPed1; //0x0008 

}; //Size=0x0010

class CWorldd {
public:
	char pad_0x0000[0x8]; //0x0000
	CPedhand* LocalPed2; //0x0008 

}; //Size=0x0010

class CWorldManager {
public:
	char pad_0x0000[0xEA8];
	float WindSpeed;
};

struct CPedVTable {
	char pad_0x0[48];
	__int64(__fastcall *unk)(CPedb *);
};

namespace rage
{
	template<typename T>
	union vector2
	{
		T data[2];
		struct { T x, y; };

		vector2(T x, T y) :
			x(x),
			y(y)
		{
		}

		vector2() :
			x(),
			y()
		{
		}
	};

	template<typename T>
	union vector3
	{
		T data[3];
		struct { T x, y, z; };

		vector3(T x, T y, T z) :
			x(x),
			y(y),
			z(z)
		{
		}

		vector3() :
			x(),
			y(),
			z()
		{
		}
	};

	template<typename T>
	union vector4
	{
		T data[4];
		struct { T x, y, z, w; };

		vector4(T x, T y, T z, T w) :
			x(x),
			y(y),
			z(z),
			w(w)
		{
		}

		vector4() :
			x(),
			y(),
			z(),
			w()
		{
		}
	};

	template<typename T>
	union matrix34
	{
		T data[3][4];
		struct { struct { T x, y, z, w; } rows[3]; };
	};

	template<typename T>
	union matrix44
	{
		T data[4][4];
		struct { struct { T x, y, z, w; } rows[4]; };
	};

	typedef vector2<float> fvector2;
	typedef vector3<float> fvector3;
	typedef vector4<float> fvector4;
	typedef matrix34<float> fmatrix34;
	typedef matrix44<float> fmatrix44;
}


namespace rage
{
	// #pragma pack(push, 4)
	class fwDrawData
	{
	public:
		std::uint64_t qword0;
		std::uint64_t qword8;
		char gap10[8];
		std::uint32_t dword18;
		std::uint32_t dword1C;
		std::uint64_t qword20;
		std::uint32_t dword28;
	};
	//     static_assert(sizeof(fwDrawData) == 0x2C);
	// #pragma pack(pop)
}

namespace rage
{

	template <typename T>
	class fwRefAwareBaseImpl : public T
	{
	private:
		void* m_ref; // 0x08
	};

}
class datBase
{
public:
	virtual ~datBase() = default;
}; //Size: 0x0008
namespace rage
{

	class fwRefAwareBase : public fwRefAwareBaseImpl<datBase>
	{
	};
	//     static_assert(sizeof(fwRefAwareBase) == 0x10);

}


namespace rage
{

	class fwExtension
	{
	public:
		virtual ~fwExtension() = default;
		virtual void unk_0x08() = 0;
		virtual void unk_0x10() = 0;
		virtual uint32_t get_id() = 0;
	}; //Size: 0x0008
	//     static_assert(sizeof(fwExtension) == 0x8);

}
namespace rage
{

	class fwExtensionContainer
	{
	public:
		fwExtension* m_entry; //0x0000
		fwExtensionContainer* m_next; //0x0008
	}; //Size: 0x0010
	//     static_assert(sizeof(fwExtensionContainer) == 0x10);

}
namespace rage
{
	class fwExtensibleBase : public fwRefAwareBase
	{
	public:
		// virtual bool is_of_type(std::uint32_t hash) = 0;
		// virtual uint32_t const &get_type() = 0;

		fwExtensionContainer* m_extension_container; // 0x0010
		void* m_extensible_unk; // 0x0018
	}; //Size: 0x0020
	//     static_assert(sizeof(fwExtensibleBase) == 0x20);

}

namespace rage
{
	class phArchetype
	{
	public:
		char pad_0000[32]; //0x0000
		class phBound* m_bound; //0x0020
		char pad_0028[16]; //0x0028
	}; //Size: 0x0038
	//     static_assert(sizeof(phArchetype) == 0x38);

	class phArchetypePhys : public phArchetype
	{
	public:
		char pad_0038[28]; //0x0028
		float m_water_collision; //0x0054
		char pad_0058[40]; //0x0058
	}; //Size: 0x0080
	//     static_assert(sizeof(phArchetypePhys) == 0x80);

	class phArchetypeDamp : public phArchetypePhys
	{
	public:
		char pad_0080[96]; //0x0080
	}; //Size: 0x00E0
	//     static_assert(sizeof(phArchetypeDamp) == 0xE0);
}
class CNavigation
{
public:
	char pad_0000[16]; //0x0000
	class rage::phArchetypeDamp* m_damp; //0x0010
	char pad_0018[8]; //0x0018
	rage::fmatrix44 m_transformation_matrix;

	rage::fvector3* get_position()
	{
		return reinterpret_cast<rage::fvector3*>(&m_transformation_matrix.rows[3]);
	}

	void model_to_world(const rage::fvector3& model_coords, rage::fvector3& world_coords)
	{
		world_coords.x = model_coords.x * m_transformation_matrix.data[0][0] + model_coords.y * m_transformation_matrix.data[1][0] + model_coords.z * m_transformation_matrix.data[2][0] + m_transformation_matrix.data[3][0];
		world_coords.y = model_coords.x * m_transformation_matrix.data[0][1] + model_coords.y * m_transformation_matrix.data[1][1] + model_coords.z * m_transformation_matrix.data[2][1] + m_transformation_matrix.data[3][1];
		world_coords.z = model_coords.x * m_transformation_matrix.data[0][2] + model_coords.y * m_transformation_matrix.data[1][2] + model_coords.z * m_transformation_matrix.data[2][2] + m_transformation_matrix.data[3][2];
	}
}; //Size: 0x0060
namespace rage
{
	class fwDynamicEntityComponent;
	class crmtRequestPose;
	class crmtRequestIk;
	class crFrameFilter;
	class fwAudEntity;
	class CMoveObjectPooledObject;

	// #pragma pack(push, 1)
	class fwEntity : public fwExtensibleBase
	{
	public:
		DEFINE_RAGE_RTTI(rage::fwEntity);

		virtual void* _0x38(void*, void*) = 0;
		virtual void AddExtension(void* extension) = 0; // 0x40
		virtual void _0x48() = 0; // not implemented
		virtual void _0x50() = 0; // only implemented by CEntityBatch
		virtual void _0x58() = 0;
		virtual void SetModelInfo(std::uint16_t* model_index) = 0; // 0x60
		virtual void _0x68(int, fvector4*) = 0;
		virtual void* _0x70(int) = 0;
		virtual CNavigation* GetNavigation() = 0; // 0x78
		virtual CMoveObjectPooledObject* CreateMoveObject() = 0; // 0x80
		virtual std::uint32_t* GetType() = 0; // 0x88
		virtual void _0x90() = 0;
		virtual float _0x98() = 0;
		virtual bool TryRequestInverseKinematics(rage::crmtRequestPose* pose, rage::crmtRequestIk* ik) = 0; // 0xA0 implemented only by CPed
		virtual bool TryRequestFacialAnims(void*) = 0; // 0xA8 implemented only by CPed
		virtual void* _0xB0() = 0;
		virtual std::uint8_t _0xB8() = 0; // implemented only by CPed
		virtual rage::crFrameFilter* GetFrameFilter() = 0; // 0xC0
		virtual rage::fwAudEntity* GetEntityAudio() = 0; // 0xC8
		virtual void _0xD0() = 0;
		virtual void SetTransform(fmatrix44* matrix, bool update_pos) = 0; // 0xD8
		virtual void SetTransform2(fmatrix44* matrix, bool update_pos) = 0; // 0xE0
		virtual void SetPosition(fvector4* pos, bool update_pos) = 0; // 0xE8
		virtual void SetHeading(float heading, bool update_pos) = 0; // 0xF0
		virtual void SetEntityTypeFlags() = 0; // 0xF8
		virtual void _0x100() = 0; // not implemented
		virtual void UpdatePhysics(CNavigation* navigation) = 0; // 0x108
		virtual void UpdatePhysics2(CNavigation* navigation) = 0; // 0x110
		virtual void UpdatePosition() = 0; // 0x118

		enum class EntityFlags
		{
			IS_VISIBLE = (1 << 0)
		};

		class CBaseModelInfo* m_model_info; //0x0020
		uint8_t m_entity_type; //0x0028
		char gap29; //0x0029
		uint16_t gap2A; //0x002A
		uint32_t m_flags; //0x002D
		class CNavigation* m_navigation; //0x0030
		uint16_t gap38; //0x0038
		uint16_t gap3A; //0x003A
		uint32_t gap3C; //0x003C
		class rage::fwDynamicEntityComponent* m_dynamic_entity_component; //0x0040 (stores attachments and stuff)
		class rage::fwDrawData* m_draw_data; //0x0048
		class rage::fwDynamicEntityComponent* gap50; //0x0050
		uint64_t gap58; //0x0058
		fmatrix44 m_transformation_matrix; //0x0060
		rage::fwEntity* m_render_focus_entity; //0x00A0
		uint32_t m_render_focus_distance; //0x00A8
		uint32_t m_flags_2; //0x00AC
		uint32_t m_shadow_flags; //0x00B0
		char gapB4[4]; //0x00B4
		std::uint8_t byteB8; //0x00B8

		rage::fvector3* get_position()
		{
			return reinterpret_cast<rage::fvector3*>(&m_transformation_matrix.rows[3]);
		}

		void model_to_world(const fvector3& model_coords, fvector3& world_coords)
		{
			world_coords.x = model_coords.x * m_transformation_matrix.data[0][0] + model_coords.y * m_transformation_matrix.data[1][0] + model_coords.z * m_transformation_matrix.data[2][0] + m_transformation_matrix.data[3][0];
			world_coords.y = model_coords.x * m_transformation_matrix.data[0][1] + model_coords.y * m_transformation_matrix.data[1][1] + model_coords.z * m_transformation_matrix.data[2][1] + m_transformation_matrix.data[3][1];
			world_coords.z = model_coords.x * m_transformation_matrix.data[0][2] + model_coords.y * m_transformation_matrix.data[1][2] + model_coords.z * m_transformation_matrix.data[2][2] + m_transformation_matrix.data[3][2];
		}
	};
	//     static_assert(sizeof(fwEntity) == 0xB9);
	// #pragma pack(pop)
}

//class CEntityDrawHandler;
namespace rage
{
	class CEntityDrawHandler : public rage::fwDrawData
	{
	public:

	};
	//     static_assert(sizeof(CEntityDrawHandler) == 0x2C);
}

namespace rage
{
	class CEntity : public fwEntity
	{
	public:
		virtual void* _0x120() = 0; // implemented only by CPed
		virtual void UpdatePositionImpl() = 0; // 0x128
		virtual void _0x130() = 0;
		virtual void _0x138(void*) = 0;
		virtual void _0x140() = 0;
		virtual void _0x148(int) = 0;
		virtual bool _0x150() = 0;
		virtual CEntityDrawHandler* CreateDrawHandler() = 0; // 0x158
		virtual int GetTypeFlags() = 0; // 0x160
		virtual int GetTypeFlags2() = 0; // 0x168
		virtual bool _0x170() = 0; // implemented only by CPickup
		virtual bool _0x178() = 0;
		virtual void _0x180(bool) = 0;
		virtual bool _0x188() = 0;
		virtual bool _0x190() = 0;
		virtual void ClearDecals() = 0; // 0x198
		virtual void GetModelBounds(rage::fvector3* bounds) = 0; // 0x1A0
		virtual void GetModelBounds2(rage::fvector3* bounds) = 0; // 0x1A8
		virtual float GetBoundingBoxSize() = 0; // 0x1B0
		virtual float _0x1B8(void*) = 0;
		virtual float _0x1C0(void*) = 0;
		virtual rage::fvector3* _0x1C8() = 0;
		virtual rage::fvector3* GetCameraOffset() = 0; // 0x1D0
		virtual void GetCameraBasePosition(rage::fvector3* pos) = 0; // 0x1D8
		virtual bool _0x1E0() = 0;
		virtual bool Update() = 0; // 0x1E8 always returns true
		virtual bool _0x1F0() = 0;
		virtual void Warp(rage::fvector3* pos, float heading, bool) = 0; // 0x1F8


		uint8_t gapB9; //0x00B9
		char gapBA[6]; //0x00BA
		uint32_t m_flags_3; //0x00C0
		uint32_t m_flags_4; //0x00C4
		uint32_t dwordC8;
		uint32_t dwordCC;
	};
	//     static_assert(sizeof(CEntity) == 0xD0);
}



namespace rage
{
	class datBitBuffer;

	// #pragma pack(push, 8)
	class netSyncNodeBase
	{
	public:
		virtual ~netSyncNodeBase() = default;                                                                                                            // 0x00
		virtual bool IsDataNode() { return false; };                                                                                                     // 0x08
		virtual bool IsParentNode() { return false; };                                                                                                   // 0x10
		virtual void MoveCommonDataOpsVFT() {};                                                                                                          // 0x18
		virtual void ClearChildren() {};                                                                                                                 // 0x20
		virtual void _0x28(void*, void*, void*, int* out_count) {};                                                                                      // 0x28
		virtual bool Serialize(int flags, int flags2, void*, /*rage::*/datBitBuffer* buffer, int, void*, bool, int*, int* num_serialized) { return false; }  // 0x30
		virtual bool Deserialize(int flags, int flags2, /*rage::*/datBitBuffer* buffer, void*) { return false; }                                             // 0x38
		virtual int CalculateSize(int flags, int flags2, void*) { return 0; }                                                                            // 0x40
		virtual int CalculateSize2(int flags, int flags2, bool) { return 0; }                                                                            // 0x48

		netSyncNodeBase* m_next_sibling; //0x0008
		netSyncNodeBase* m_prev_sibling; //0x0010
		netSyncNodeBase* m_root; //0x0018
		netSyncNodeBase* m_parent; //0x0020

		uint32_t m_flags1; //0x0028
		uint32_t m_flags2; //0x002C
		uint32_t m_flags3; //0x0030

		uint32_t m_pad2; //0x0034

		netSyncNodeBase* m_first_child; //0x0038
	}; //Size: 0x0040
	// 	static_assert(sizeof(netSyncNodeBase) == 0x40);
	// #pragma pack(pop)
}
class netSyncTree
{
public:
	virtual ~netSyncTree() = default;

	char pad_0008[8]; //0x0008
	rage::netSyncNodeBase* m_next_sync_node; //0x0010
	rage::netSyncNodeBase* m_last_sync_node; //0x0018
	uint32_t m_child_node_count; //0x0020
	uint32_t m_unk_array_count; //0x0024
	char pad_0028[8]; //0x0028
	rage::netSyncNodeBase* m_child_nodes[42]; //0x0030
	uint32_t m_child_node_max_count; //0x0180
	rage::netSyncNodeBase* m_unk_array[32]; //0x0188
	uint32_t m_unk_array_max_count; //0x0288
	char pad_0290[560]; //0x0290
}; //Size: 0x0030


class CObject;
namespace rage
{
	class netObject
	{
	public:
		int16_t m_object_type; //0x0008
		int16_t m_object_id; //0x000A
		char pad_000C[52]; //0x000C
		int8_t m_bubble; //0x0040
		char pad_0041[8]; //0x0041
		int8_t m_owner_id; //0x0049
		int8_t m_wants_to_be_owner; //0x004A
		bool m_is_remote; //0x004B
		uint16_t m_flags_one; //0x004C
		uint16_t m_flags_two; //0x004E
		class CObject* m_game_object; //0x0050
		char pad_0058[48]; //0x0058
		uint32_t m_ownership_token; //0x0088
		//int16_t m_object_type; //0x0008
		//int16_t m_object_id; //0x000A
		//char pad_000C[61]; //0x000C
		//int8_t m_owner_id; //0x0049
		//int8_t m_control_id; //0x004A
		//int8_t m_next_owner_id; //0x004B
		//bool m_is_remote; //0x004C
		//bool m_wants_to_delete; //0x004D
		//char pad_004E[1]; //0x004E
		//bool m_should_not_be_delete; //0x004F

		DEFINE_RAGE_RTTI(rage::netObject)

		virtual void mov1() = 0;                                               // 0x38
		virtual void mov2() = 0;                                               // 0x40
		
		virtual void m_8() = 0;                                                // 0x48
		virtual class netSyncData* GetSyncData() = 0;                          // 0x50
		virtual void m_18() = 0;                                               // 0x58
		virtual void* m_20() = 0;                                              // 0x60
		virtual void m_28() = 0;                                               // 0x68
		virtual netSyncTree* GetSyncTree() = 0;                                // 0x70
		virtual void m_38() = 0;                                               // 0x78
		virtual void m_40() = 0;                                               // 0x80
		virtual void m_48() = 0;
		virtual void m_50() = 0;
		virtual void m_58() = 0;
		virtual void m_60() = 0;
		virtual void m_68() = 0;
		virtual void m_70() = 0;
		virtual void m_78() = 0;
		virtual CObject* GetGameObject() = 0;
		virtual void m_88() = 0;
		virtual void m_90() = 0;
		virtual void m_98() = 0;
		virtual int GetObjectFlags() = 0;
		virtual void m_A8() = 0;
		virtual void m_B0() = 0;
		virtual void m_B8() = 0;
		virtual void m_C0() = 0;
		virtual void m_C8() = 0;
		virtual int GetSyncFrequency() = 0;
		virtual void m_D8() = 0;
		virtual void m_E0() = 0;
		virtual void m_E8() = 0;
		virtual void m_F0() = 0;
		virtual void m_F8() = 0;
		virtual void Update() = 0;
		virtual bool m_108_1604() = 0; // added in 1604
		virtual void m_108() = 0;
		virtual void m_110() = 0;
		virtual void m_118() = 0;
		virtual void m_120() = 0;
		virtual void m_128() = 0;
		virtual void m_130() = 0;
		virtual void m_138() = 0;
		virtual void m_140() = 0;
		virtual void m_148() = 0;
		virtual void m_150() = 0;
		virtual bool m_158(void* player, int type, int* outReason) = 0;
		virtual void m_160() = 0;
		virtual bool m_168(int* outReason) = 0;
		virtual void m_170() = 0;
		virtual void m_178() = 0;
		virtual void m_180() = 0;
		virtual void m_188() = 0;
		virtual void m_190() = 0;
		virtual void m_198() = 0;
		virtual void m_1A0() = 0;
		virtual void m_1A8() = 0;
		virtual void m_1B0() = 0;
		virtual void m_1B8() = 0;
		virtual void m_1C0() = 0;
		virtual void m_1C8() = 0;
		virtual void m_1D0() = 0;
		virtual void m_1D8() = 0;
		virtual void m_1E0() = 0;
		virtual void m_1E8() = 0;
		virtual void m_1F0() = 0;
		virtual void m_1F8() = 0;
		virtual void m_200() = 0;
		virtual void m_208() = 0;
		virtual void m_210() = 0;
		virtual void m_218() = 0;
		virtual void m_220() = 0;
		virtual void m_228() = 0;
		virtual void m_230() = 0;
		virtual void m_238() = 0;
		virtual void m_240() = 0;
		virtual void m_248() = 0;
		virtual void m_250() = 0;
		virtual void m_258() = 0;
		virtual void m_260() = 0;
		virtual void m_268() = 0;
		virtual void m_270() = 0;
		virtual void m_278() = 0;
		virtual void m_280() = 0;
		virtual void m_288() = 0;
		virtual void m_290() = 0;
		virtual void m_298() = 0;
		virtual void m_2A0() = 0;
		virtual void m_2A8() = 0;
		virtual void m_2B0() = 0;
		virtual void m_2B8() = 0;
		virtual void m_2C0() = 0;
		virtual void m_2C8() = 0;
		virtual void m_2D0() = 0;
		virtual void m_2D8() = 0;
		virtual void m_2E0() = 0;
		virtual void m_2E8() = 0;
		virtual void m_2F0() = 0;
		virtual void m_2F8() = 0;
		virtual void m_300() = 0;
		virtual void m_308() = 0;
		virtual void m_310() = 0;
		virtual void m_318() = 0;
		virtual void m_320() = 0;
		virtual void UpdatePendingVisibilityChanges() = 0;
		//virtual void m_8() = 0;                                                // 0x48
		//virtual void m_10() = 0;                                               // 0x50
		//virtual void m_18() = 0;                                               // 0x58
		//virtual void* m_20() = 0;                                              // 0x60
		//virtual void m_28() = 0;                                               // 0x68
		//virtual netSyncTree* GetSyncTree() = 0;                                // 0x70
		//virtual void m_38() = 0;                                               // 0x78
		//virtual void m_40() = 0;                                               // 0x80
		//virtual void m_48() = 0;
		//virtual void m_50() = 0;
		//virtual void m_58() = 0;
		//virtual void m_60() = 0;
		//virtual void m_68() = 0;
		//virtual void m_70() = 0;
		//virtual void m_78() = 0;
		//virtual CObject* GetGameObject() = 0;
		//virtual void m_88() = 0;
		//virtual void m_90() = 0;
		//virtual void m_98() = 0;
		//virtual int GetObjectFlags() = 0;
		//virtual void m_A8() = 0;
		//virtual void m_B0() = 0;
		//virtual void m_B8() = 0;
		//virtual void m_C0() = 0;
		//virtual void m_C8() = 0;
		//virtual int GetSyncFrequency() = 0;
		//virtual void m_D8() = 0;
		//virtual void m_E0() = 0;
		//virtual void m_E8() = 0;
		//virtual void m_F0() = 0;
		//virtual void m_F8() = 0;
		//virtual void Update() = 0;
		//virtual bool m_108_1604() = 0; // added in 1604
		//virtual void m_108() = 0;
		//virtual void m_110() = 0;
		//virtual void m_118() = 0;
		//virtual void m_120() = 0;
		//virtual void m_128() = 0;
		//virtual void m_130() = 0;
		//virtual void m_138() = 0;
		//virtual void m_140() = 0;
		//virtual void m_148() = 0;
		//virtual void m_150() = 0;
		//virtual bool m_158(void* player, int type, int* outReason) = 0;
		//virtual void m_160() = 0;
		//virtual bool m_168(int* outReason) = 0;
		//virtual void m_170() = 0;
		//virtual void m_178() = 0;
		//virtual void m_180() = 0;
		//virtual void m_188() = 0;
		//virtual void m_190() = 0;
		//virtual void m_198() = 0;
		//virtual void m_1A0() = 0;
		//virtual void m_1A8() = 0;
		//virtual void m_1B0() = 0;
		//virtual void m_1B8() = 0;
		//virtual void m_1C0() = 0;
		//virtual void m_1C8() = 0;
		//virtual void m_1D0() = 0;
		//virtual void m_1D8() = 0;
		//virtual void m_1E0() = 0;
		//virtual void m_1E8() = 0;
		//virtual void m_1F0() = 0;
		//virtual void m_1F8() = 0;
		//virtual void m_200() = 0;
		//virtual void m_208() = 0;
		//virtual void m_210() = 0;
		//virtual void m_218() = 0;
		//virtual void m_220() = 0;
		//virtual void m_228() = 0;
		//virtual void m_230() = 0;
		//virtual void m_238() = 0;
		//virtual void m_240() = 0;
		//virtual void m_248() = 0;
		//virtual void m_250() = 0;
		//virtual void m_258() = 0;
		//virtual void m_260() = 0;
		//virtual void m_268() = 0;
		//virtual void m_270() = 0;
		//virtual void m_278() = 0;
		//virtual void m_280() = 0;
		//virtual void m_288() = 0;
		//virtual void m_290() = 0;
		//virtual void m_298() = 0;
		//virtual void m_2A0() = 0;
		//virtual void m_2A8() = 0;
		//virtual void m_2B0() = 0;
		//virtual void m_2B8() = 0;
		//virtual void m_2C0() = 0;
		//virtual void m_2C8() = 0;
		//virtual void m_2D0() = 0;
		//virtual void m_2D8() = 0;
		//virtual void m_2E0() = 0;
		//virtual void m_2E8() = 0;
		//virtual void m_2F0() = 0;
		//virtual void m_2F8() = 0;
		//virtual void m_300() = 0;
		//virtual void m_308() = 0;
		//virtual void m_310() = 0;
		//virtual void m_318() = 0;
		//virtual void m_320() = 0;
		//virtual void UpdatePendingVisibilityChanges() = 0;
	}; //Size: 0x0050
	//     static_assert(sizeof(netObject) == 0x50);
}

namespace rage
{
	class CDynamicEntity : public rage::CEntity
	{
	public:
		class rage::netObject* m_net_object; //0x00D0
		char gapD8[16];
		uint64_t qwordE8;
	};
	//     static_assert(sizeof(CDynamicEntity) == 0xF0);
}

namespace rage
{
	// #pragma pack(push, 1)
	class CPhysical : public CDynamicEntity
	{
	public:
		char gapF0[144];
		uint64_t qword180;
		uint32_t m_damage_bits; //0x0188
		uint8_t m_hostility; //0x018C
		char gap18D[3];
		uint8_t byte190;
		char gap191[3];
		uint32_t dword194;
		char gap198[232];
		float m_health; //0x0280
		float m_maxhealth; //0x0284
		class CAttackers* m_attackers;
		char gap2B0[72];
		uint64_t qword2F8;
		uint64_t qword300;
		uint32_t dword308;
	};
	//     static_assert(sizeof(CPhysical) == 0x2EC);
	// #pragma pack(pop)
}

enum class ePedBoneType
{
	HEAD,
	L_FOOT,
	R_FOOT,
	L_ANKLE,
	R_ANKLE,
	L_HAND,
	R_HAND,
	NECK,
	ABDOMEN
};

class CPedBoneInfo
{
public:
	rage::fvector3 model_coords;
	char pad_000C[4];
};

extern void model_to_world(const rage::fvector3& model_coords, rage::fvector3& world_coords);

class CPeda : public rage::CPhysical
{
public:
	char gap2EC[20];
	rage::fvector3 m_velocity; //0x0300
	char pad_030C[260]; //0x030C
	class CPedBoneInfo m_bone_info[9]; //0x0410
	char pad_04A0[2160]; //0x04A0
	class CVehicle* m_vehicle; //0x0D10
	char pad_0D18[896]; //0x0D18
	uint32_t m_ped_type; //0x1098
	char pad_109C[4]; //0x109C
	class CPedIntelligence* m_ped_intelligence; //0x10A0
	class CPlayerInfo* m_player_info; //0x10A8
	class CPedInventory* m_inventory; //0x10B0
	class CPedWeaponManager* m_weapon_manager; //0x10B8
	char pad_10C0[892]; //0x10C0
	uint8_t m_seatbelt; //0x143C
	char pad_143D[13]; //0x143D
	uint8_t m_can_switch_weapon; //0x144A
	uint8_t m_ped_task_flag; //0x144B
	char pad_144C[4]; //0x144C
	uint8_t m_forced_aim; //0x1450 m_forced_aim ^= (m_forced_aim ^ -(char)toggle) & 0x20;
	char pad_1451[187]; //0x1451
	float m_armor; //0x150C
	float unk_health_threshold; //0x1510
	float m_fatigued_health_threshold; //0x1514
	float m_injured_health_threshold; //0x1518
	float m_dying_health_threshold; //0x151C
	float m_hurt_health_threshold; //0x1520
	char pad_1524[12]; //0x1524
	void* m_seat_info; //0x1530
	char pad_1538[220]; //0x1538
	uint16_t m_cash; //0x1614
	char pad_1616[846]; //0x1616
	uint8_t fired_sticky_bombs; //0x1964 reverse from 1.69 3258 function E8 ? ? ? ? 48 8B F8 EB ? 48 8B 47 add(1).rip(), function string: WM_MAX_STICKY
	uint8_t fired_unk_0; //0x1965
	uint8_t fired_flares; //0x1966
	uint8_t fired_unk_1; //0x1967
	//char gap2EC[20];
	//rage::fvector3 m_velocity; //0x0300
	//char pad_030C[260]; //0x030C
	//class CPedBoneInfo m_bone_info[9]; //0x0410
	//char pad_04A0[2160]; //0x04A0
	//class CVehicle* m_vehicle; //0x0D10
	//char pad_0D18[896]; //0x0D18
	//uint32_t m_ped_type; //0x1098
	//char pad_109C[4]; //0x109C
	//class CPedIntelligence* m_ped_intelligence; //0x10A0
	//class CPlayerInfo* m_player_info; //0x10A8
	//class CPedInventory* m_inventory; //0x10B0
	//class CPedWeaponManager* m_weapon_manager; //0x10B8
	//char pad_10C0[892]; //0x10C0
	//uint8_t m_seatbelt; //0x143C
	//char pad_143D[13]; //0x143D
	//uint8_t m_can_switch_weapon; //0x144A
	//uint8_t m_ped_task_flag; //0x144B
	//char pad_144C[4]; //0x144C
	//uint8_t m_forced_aim; //0x1450 m_forced_aim ^= (m_forced_aim ^ -(char)toggle) & 0x20;
	//char pad_1451[187]; //0x1451
	//float m_armor; //0x150C
	//float unk_health_threshold; //0x1510
	//float m_fatigued_health_threshold; //0x1514
	//float m_injured_health_threshold; //0x1518
	//float m_dying_health_threshold; //0x151C
	//float m_hurt_health_threshold; //0x1520
	//char pad_1524[240]; //0x1524
	//uint16_t m_cash; //0x1614
	//char pad_1616[842]; //0x1616
	//uint8_t fired_sticky_bombs; //0x1960 reverse from 1.66 2824 function E8 ? ? ? 48 8B F8 EB 5F add(1).rip(), function string: WM_MAX_STICKY
	//uint8_t fired_unk_0; //0x1961
	//uint8_t fired_flares; //0x1962
	//uint8_t fired_unk_1; //0x1963

	float get_speed() { return sqrt(m_velocity.x * m_velocity.x + m_velocity.y * m_velocity.y + m_velocity.z * m_velocity.z); }


	rage::fvector3 get_bone_coords(ePedBoneType type)
	{
		rage::fvector3 world_coords;
		model_to_world(m_bone_info[(uint32_t)type].model_coords, world_coords);
		return world_coords;
	}

	bool can_be_ragdolled() { return m_ped_type & 0x20; }

	uint32_t get_ped_type() { return m_ped_type << 11 >> 25; }

	bool has_seatbelt() { return m_seatbelt & 0x3; }

	void forced_aim(bool toggle) { m_forced_aim ^= (m_forced_aim ^ -(char)toggle) & 0x20; }
}; //Size: 0x1964

class CVehiclea {
public:
	char pad_0x0000[0x30]; //0x0000
	CFragInst* m_fragInst; //0x0030 
	char pad_0x0038[0x10]; //0x0038
	CVehicleDrawHandlera* m_vehicleDrawHandler; //0x0048 
	char pad_0x0050[0x230]; //0x0050
	float m_health; //0x0280 
	char pad_0x0284[0x1C]; //0x0284
	float m_maxHealth; //0x02A0 
	char pad_0x02A4[0x77]; //0x02A4
	unsigned char m_rocketState; //0x031B 
	char pad_0x031C[0x1]; //0x031C
	unsigned char m_rocketEnergy; //0x031D 
	char pad_0x031E[0x5FA]; //0x031E
	CHandlingData* m_handlingData; //0x0918 
	char pad_0x0920[0x48]; //0x0920
	CVehicle* m_vehicle; //0x0968 
	char pad_0x0970[0x8]; //0x0970
	CVehicleDeformation* m_vehicleDeformation; //0x0978 
	char pad_0x0980[0x101C]; //0x0980
	float m_visualSuspension; //0x199C 
	char pad_0x19A0[0x240]; //0x19A0

}; //Size=0x1BE0
class CVehicle : public rage::CPhysical
{
public:
	//char pad_02EC[12]; //0x02EC
	//bool m_boosting; //0x02F8
	//char pad_02F9[2]; //0x02F9
	//bool m_boost_allow_recharge; //0x02FB
	//char pad_02FC[4]; //0x02FC
	//float m_boost; //0x0300
	//float m_rocket_recharge_speed; //0x0304
	//char pad_0308[152]; //0x0308
	//float m_jump_boost_charge; //0x03A0
	//bool m_can_boost_jump; //0x03A4
	//char pad_03A5[123]; //0x03A5
	//class CVehicleDamage m_vehicle_damage; //0x0420
	//char pad_0838[72]; //0x0838
	//int16_t m_next_gear; //0x0880
	//int16_t m_current_gear; //0x0882
	//char pad_0884[2]; //0x0884
	//int8_t m_top_gear; //0x0886
	//char pad_0887[137]; //0x0887
	//float m_engine_health; //0x0910
	//char pad_0914[24]; //0x0914
	//float m_kers_boost_max; //0x092C
	//float m_kers_boost; //0x0930
	//char pad_0934[44]; //0x0934
	//class CHandlingData* m_handling_data; //0x0960
	//char pad_0968[2]; //0x0968
	//uint8_t m_drivable_bitset; //0x096A
	//uint8_t m_tyre_burst_bitset; //0x096B
	//uint8_t m_deform_god; //0x096C
	//char pad_096D[179]; //0x096D
	//float m_dirt_level; //0x0A20
	//char pad_0A24[202]; //0x0A24
	//bool m_is_targetable; //0x0AEE
	//char pad_0AEF[313]; //0x0AEF
	//uint32_t m_type; //0x0C28
	//char pad_0C2C[112]; //0x0C2C
	//float m_gravity; //0x0C9C
	//uint8_t m_max_passengers; //0x0CA0
	//char pad_0CA1[1]; //0x0CA1
	//uint8_t m_num_of_passengers; //0x0CA2
	//char pad_0CA3[5]; //0x0CA3
	//class CPed* m_driver; //0x0CA8
	//class CPed* m_passengers[15]; //0x0CB0
	//class CPed* m_last_driver; //0x0CB0
	//char pad_0D30[1696]; //0x0D30
	//uint32_t m_door_lock_status; //0x13D0
	//char pad_13D4[204]; //0x13D4
	char pad_02EC[0xC]; //0x02EC
	uint8_t m_boost_state; //0x02F8
	char pad_02F9[0x2]; //0x02F9
	uint8_t m_boost_allow_recharge; //0x02FB
	char pad_02FC[0x4]; //0x02FC
	float m_boost; //0x0300
	float m_rocket_recharge_speed; //0x304
	char pad_0308[0x98]; //0x88 //0x0308
	float m_jump_boost_charge; //0x0390
	char pad_0394[0x43C]; //0x0394
	rage::fvector3 m_velocity; //0x07D0
	char pad_07DC[0x44]; //0x07DC
	float m_body_health; //0x0820
	float m_petrol_tank_health; //0x0824
	char pad_0x828[0xC0]; //0x0828
	float m_engine_health; //0x08E8
	char pad_08EC[0x2C]; //0x08EC
	CHandlingData* m_handling_data; //0x0918
	char pad_0920[0x2]; //0x0920
	uint8_t m_is_drivable; //0x0922
	uint8_t m_tyres_can_burst; //0x0923
	uint8_t m_deform_god; //0x0924
	char pad_0925[0xB3]; //0x0925
	float m_dirt_level; //0x09D8
	char pad_09DC[0xC2]; //0x09DC
	uint8_t m_is_targetable; //0x0A9E
	char pad_0A9F[0x19D]; //0x0A9F
	float m_gravity; //0x0C3C - might be start of some sub-class
	uint8_t m_max_passengers; //0x0C40
	char pad_0C41; //0x0C41
	uint8_t m_num_of_passengers; //0x0C42
	char pad_0C43[5]; //0x0C43
	class CPed* m_driver; //0x0C48
	class CPed* m_passengers[15]; //0x0C50
	class CPed* m_last_driver; //0x0CC8
	char pad_0CD0[0x6A0]; //0x0CD0
	uint32_t m_door_lock_status; //0x1370
	char pad_1374[0xDC]; //0x1374

	float get_speed() { return sqrt(m_velocity.x * m_velocity.x + m_velocity.y * m_velocity.y + m_velocity.z * m_velocity.z); }
};
class CVehicleDrawHandlera {
public:
	char pad_0x0000[0x370]; //0x0000
	//CVehicleSteamRenderGFX* m_vehicleStreamRenderGfx; //0x0370 
	CVehicleStreamRender* m_vehicleStreamRender; //0x0370
	char pad_0x0378[0x8B0]; //0x0378

}; //Size=0x0C28

class CEntityDrawHandler : public rage::fwDrawData
{
public:

};
class CVehicleDrawHandler : public CEntityDrawHandler
{
public:
	uint64_t qword30;
	char gap38[848];
	uint8_t m_primary_color; //0x0388
	char gap389[3]; //0x0389
	uint8_t m_pearlescent; //0x038C
	char gap38D[3]; //0x038D
	uint8_t m_secondary_color; //0x0390
	char gap391[15]; //0x0391
	uint8_t m_neon_blue; //0x03A0
	uint8_t m_neon_green; //0x03A1
	uint8_t m_neon_red; //0x03A2
	char gap3A3[15]; //0x03A3
	uint8_t m_spoiler; //0x03B2
	uint8_t m_bumper_front; //0x03B3
	uint8_t m_bumper_rear; //0x03B4
	uint8_t m_sideskirts; //0x03B5
	uint8_t m_exhaust; //0x03B6
	uint8_t m_frame; //0x03B7
	uint8_t m_grille; //0x03B8
	uint8_t m_hood; //0x03B9
	uint8_t m_fenders; //0x03BA
	uint8_t m_bullbars; //0x03BB
	uint8_t m_roof; //0x03BC
	char gap3BD[3]; //0x03BD
	uint8_t m_ornaments; //0x03C0
	char gap3C1[1]; //0x03C1
	uint8_t m_dail_design; //0x03C2
	uint8_t m_sunstrips; //0x03C3
	uint8_t m_seats; //0x03C4
	uint8_t m_steering_wheel; //0x03C5
	uint8_t m_column_shifter_levers; //0x03C6
	char gap3C7[2]; //0x03C7
	uint8_t m_truck_beds; //0x03C9
	char gap3CA[4]; //0x03CA
	uint8_t m_roll_cages; //0x03CE
	uint8_t m_skid_plate; //0x03CF
	uint8_t m_secondary_light_surrounds; //0x03D0
	uint8_t m_hood_accessories; //0x03D1
	uint8_t m_doors; //0x03D2
	uint8_t m_snorkel; //0x03D3
	uint8_t m_livery; //0x03D4
	char gap3D5[1]; //0x03D5
	uint8_t m_engine; //0x03D6
	uint8_t m_brakes; //0x03D7
	uint8_t m_transmission; //0x03D8
	uint8_t m_horn; //0x03D9
	uint8_t m_suspension; //0x03DA
	uint8_t m_armor; //0x03DB
	char gap3DC[1]; //0x03DC
	uint8_t m_turbo; //0x03DD
	char gap3DE[3]; //0x03DE
	uint8_t m_xenon; //0x03E1
	uint8_t m_tire_design; //0x03E2
	char gap3E3[16]; //0x03E3
	uint8_t m_truck_bed; //0x03F3
	uint16_t m_modkit; //0x03F4
	uint8_t byte3F6;
	uint8_t byte3F7;
	uint8_t byte3F8;
	uint8_t m_wheel_color;
	uint8_t byte3FA;
	uint8_t byte3FB;
	char gap3FC[3];
	uint8_t m_window;
	char gap400[2];
	uint8_t m_neon_left;
	uint8_t m_neon_right;
	uint8_t m_neon_front;
	uint8_t m_neon_rear;
	char gap406[9];
	uint32_t dword410;
	uint32_t dword414;
};
class CVehicleSteamRenderGFX {
public:
	char pad_0x0000[0xB]; //0x0000
	unsigned char m_tireSize; //0x000B 
	char pad_0x000C[0x4]; //0x000C
	unsigned char m_customTires; //0x0010 
	char pad_0x0011[0xB8F]; //0x0011
	float m_tireWidth; //0x0BA0 
	char pad_0x0BA4[0x464]; //0x0BA4

}; //Size=0x1008

class CVehicleStreamRender {
public:
	char _0x0000[8];
	uint8_t UNK1;
	uint8_t UNK2;
	unsigned char TireSize; //0x000B 
	char pad_0x000C[0x4]; //0x000C
	unsigned char CustomTires; //0x0010 
	//char pad_0x0011[0xF]; //0x0011
	char pad_0x0011[0xB8F]; //0x0011
	float m_tireWidth; //0x0BA0 
	char pad_0x0BA4[0x464]; //0x0BA4

}; //Size=0x0020

class CWeaponInfo {
public:
	char pad_0x0000[0x8]; //0x0000

}; //Size=0x0008

class CVehicleDeformation {
public:
	char pad_0x0000[0x20]; //0x0000
	float Rot1; //0x0020 
	float Width; //0x0024 
	float SideTilt; //0x0028 
	char pad_0x002C[0x4]; //0x002C
	float Rot2; //0x0030 
	float Length; //0x0034 
	float FrontUp; //0x0038 
	char pad_0x003C[0x4]; //0x003C
	float Sideways; //0x0040 
	float Forward; //0x0044 
	float Height; //0x0048 
	char pad_0x004C[0x4]; //0x004C
	Vector3_t Position; //0x0050 

}; //Size=0x005C

//class CVehicle
//{
//public:
//	char pad_0x0000[0x30]; //0x0000
//	__int64* pCNavigation; //0x0030 
//	char pad_0x0038[0x10]; //0x0038
//	//CVehicleMods* pCVehicleMods; //0x0048 
//	char pad_0x0050[0x40]; //0x0050
//	Vector3 v3VisualPos; //0x0090 
//	char pad_0x009C[0x3C]; //0x009C
//	uint8_t btState; //0x00D8 
//	char pad_0x00D9[0xB0]; //0x00D9
//	uint8_t btGodMode; //0x0189 
//	char pad_0x018A[0xF6]; //0x018A
//	float fHealth; //0x0280 
//	char pad_0x0284[0x1C]; //0x0284
//	float fHealthMax; //0x02A0 
//	char pad_0x02A4[0x4]; //0x02A4
//	__int64* pCAttacker; //0x02A8 
//	char pad_0x02B0[0x6A]; //0x02B0
//	uint8_t btVolticRocketState; //0x031A 
//	char pad_0x031B[0x1]; //0x031B
//	float fVolticRocketEnergy; //0x031C 
//	char pad_0x0320[0x430]; //0x0320
//	Vector3 v3Velocity; //0x0750 
//	char pad_0x075C[0xF0]; //0x075C
//	float fHealth2; //0x084C 
//	char pad_0x0850[0x28]; //0x0850
//	char pad_0x0880[0x3]; //0x0880
//	uint8_t btBulletproofTires; //0x0883 
//	char pad_0x0884[0x4]; //0x0884
//	uint8_t btStolen; //0x0888 
//	char pad_0x0889[0x11]; //0x0889
//	uint8_t N00000954; //0x089A 
//	char pad_0x089B[0x41]; //0x089B
//	float N0000081E; //0x08DC 
//	char pad_0x08E0[0x58]; //0x08E0
//	float fDirtLevel; //0x0938			max = 15.f
//	char pad_0x093C[0xA8]; //0x093C
//	DWORD dwCarAlarmLength; //0x09E4 
//	char pad_0x09E8[0x148]; //0x09E8
//	uint8_t btOpenableDoors; //0x0B30 
//	char pad_0x0B31[0x4B]; //0x0B31
//	float fGravity; //0x0B7C
//	uint8_t btMaxPassengers; //0x0B80 
//	char pad_0x0B81[0x1]; //0x0B81
//	uint8_t btNumOfPassengers; //0x0B82 
//	char pad_0x0B83[0x3D]; //0x0B83
//}; //Size=0x0BC0


class CHandlingData {
public:
	char pad_0x0000[0x8]; //0x0000
	__int32 Hash; //0x0008 
	float fMass; //0x000C 
	char pad_0x0010[0x4]; //0x0010
	float fDownforceModifier; //0x0014 
	char pad_0x0018[0x8]; //0x0018
	Vector3_t vecCentreOfMassOffset; //0x0020 
	char pad_0x002C[0x4]; //0x002C
	Vector3_t vecInertiaMultiplier; //0x0030 
	char pad_0x003C[0x4]; //0x003C
	float fPercentSubmerged; //0x0040 
	char pad_0x0044[0x8]; //0x0044
	float fDriveBiasFront; //0x004C 
	unsigned char nInitialDriveGears; //0x0050 
	char pad_0x0051[0x3]; //0x0051
	float fDriveInertia; //0x0054 
	float fClutchChangeRateScaleUpShift; //0x0058 
	float fClutchChangeRateScaleDownShift; //0x005C 
	float fInitialDriveForce; //0x0060 
	char pad_0x0064[0x8]; //0x0064
	float fBrakeForce; //0x006C 
	char pad_0x0070[0x4]; //0x0070
	float fInitialDriveMaxFlatVel; //0x0074 
	char pad_0x0078[0x4]; //0x0078
	float fHandBrakeForce; //0x007C 
	float fSteeringLock; //0x0080 
	char pad_0x0084[0x4]; //0x0084
	float fTractionCurveMax; //0x0088 
	char pad_0x008C[0x14]; //0x008C
	float fTractionSpringDeltaMax; //0x00A0 
	char pad_0x00A4[0x4]; //0x00A4
	float fLowSpeedTractionLossMult; //0x00A8 
	float fCamberStiffnesss; //0x00AC 
	char pad_0x00B0[0x8]; //0x00B0
	float fTractionLossMult; //0x00B8 
	float fSuspensionForce; //0x00BC 
	float fSuspensionCompDamp; //0x00C0 
	float fSuspensionReboundDamp; //0x00C4 
	float fSuspensionUpperLimit; //0x00C8 
	float fSuspensionLowerLimit; //0x00CC 
	char pad_0x00D0[0xC]; //0x00D0
	float fAntiRollBarForce; //0x00DC 
	char pad_0x00E0[0x8]; //0x00E0
	float fRollCentreHeightFront; //0x00E8 
	float fRollCentreHeightRear; //0x00EC 
	float fCollisionDamageMult; //0x00F0 
	float fWeaponDamageMult; //0x00F4 
	float fDeformationDamageMult; //0x00F8 
	float fEngineDamageMult; //0x00FC 
	float fPetrolTankVolume; //0x0100 
	float fOilVolume; //0x0104 
	char pad_0x0108[0x4]; //0x0108
	Vector3_t fSeatOffset; //0x010C 
	__int32 nMonetaryValue; //0x0118 
	char pad_0x011C[0x30]; //0x011C
	unsigned char N00002337; //0x014C 
	unsigned char N0000239F; //0x014D 
	char pad_0x014E[0x2]; //0x014E
	CAIHandlingInfo* AIHandlingInfo; //0x0150 
	CSubHandlingData* SubHandlingData; //0x0158 

}; //Size=0x0160

//enum class eGameState : int32_t
//{
//    Invalid = -1,
//    Playing,
//    Died,
//    Arrested,
//    FailedMission,
//    LeftGame,
//    Respawn,
//    InMPCutscene
//};

class netConnectionPeer
{
public:
	uint32_t m_internal_ip; //0x0000
	uint16_t m_internal_port; //0x0004
	uint32_t m_external_ip; //0x0008
	uint16_t m_external_port; //0x000C
	uint64_t m_peer_id; //0x0010
	uint32_t unk_0018; //0x0018
	uint16_t unk_001C; //0x001C
	uint8_t m_platform; //0x001E
};

//namespace rage
//{

union netAddress {
	uint32_t m_packed; //0x0000
	struct {
		uint8_t m_field4; //0x0000
		uint8_t m_field3; //0x0001
		uint8_t m_field2; //0x0002
		uint8_t m_field1; //0x0003
	};
}; //Size: 0x0004
//static_assert(sizeof(netAddress) == 0x04);
// 

namespace rage
{
//#pragma pack(push,8)
	class rlGamerHandle
	{
	public:
		uint64_t m_rockstar_id; //0x0000
		uint8_t m_platform; //0x0008
		uint8_t unk_0009; //0x0009

		inline rlGamerHandle() = default;

		inline rlGamerHandle(uint64_t rockstar_id) :
			m_rockstar_id(rockstar_id),
			m_platform(3),
			unk_0009(0)
		{
		}
	}; //Size: 0x0010
	/*static_assert(sizeof(rlGamerHandle) == 0x10);
#pragma pack(pop)*/
}


	//#pragma pack(push,8)
namespace rage
{
	class netPeerAddress
	{
	public:
		netAddress m_internal_ip; //0x0000
		uint16_t m_internal_port; //0x0004
		netAddress m_external_ip; //0x0008
		uint16_t m_external_port; //0x000C
		uint64_t m_peer_id; //0x0010
		netAddress m_relay_address; //0x0018
		uint16_t m_relay_port; //0x001C
		uint8_t m_connection_type; //0x001E
	};
	class rlGamerInfoBase
	{
	public:
		//char pad_0000[0x8];              //0x0000
		//uint64_t m_peer_id;              //0x0008
		//rage::rlGamerHandle m_gamer_handle;    //0x0010
		//char m_aes_key[0x20];            //0x0020
		//char pad_0040[0x8];              //0x0040
		//netAddress m_unk_ip;             //0x0048
		//uint16_t m_unk_port;             //0x004C
		//netAddress m_relay_ip;           //0x0050
		//uint16_t m_relay_port;           //0x0054
		//char pad_0058[0x12];             //0x0056
		//char pad_0068[0x40];             //0x0068
		//netAddress m_external_ip;        //0x00A8
		//uint16_t m_external_port;        //0x00AC
		//netAddress m_internal_ip;        //0x00B0
		//uint16_t m_internal_port;        //0x00B4
		//char pad_00B6[0x2];              //0x00B6
		//uint32_t unk_00B8;               //0x00B8
		//char pad_00BC[0x4];              //0x00BC
		int m_security_enabled;          //0x0000
		uint64_t m_peer_id;              //0x0008
		rlGamerHandle m_gamer_handle;    //0x0010
		char m_aes_key[0x28];            //0x0020
		netPeerAddress m_relay_address;  //0x0048
		char m_relay_signature[0x40];    //0x0068
		netAddress m_external_ip;        //0x00A8
		uint16_t m_external_port;        //0x00AC
		netAddress m_internal_ip;        //0x00B0
		uint16_t m_internal_port;        //0x00B4
		uint32_t m_nat_type;             //0x00B8
		bool m_force_relays;             //0x00BC
	};
	/*static_assert(sizeof(rlGamerInfoBase) == 0xC0);
#pragma pack(pop)*/

}
//namespace rage
//{
//	//#pragma pack(push,8)
//	class rlGamerInfo : public rlGamerInfoBase
//	{
//	public:
//		uint64_t m_host_token;
//		uint64_t m_peer_id_2;
//		rlGamerHandle m_gamer_handle_2;
//		uint32_t m_ros_privilege;
//		char m_name[17];
//	}; //Size: 0x0098
//	/*static_assert(sizeof(rlGamerInfo) == 0xF8);
//#pragma pack(pop)*/
//}

namespace rage
{
//#pragma pack(push,8)
	class rlGamerInfo : public rlGamerInfoBase
	{
	public:
		uint64_t m_host_token;

		union
		{
			rlGamerHandle m_gamer_handle_2;
			uint32_t m_peer_id_2; // not found in all instances
		};

		uint32_t m_ros_privilege;
		char m_name[17];
	}; //Size: 0x0098
	/*static_assert(sizeof(rlGamerInfo) == 0xF0);
#pragma pack(pop)*/
}

//class CPlayerInfo
//{
//public:
//	char pad_0000[32]; //0x0000
//	class rage::rlGamerInfo m_net_player_data; //0x0020
//	char pad_00B8[184]; //0x00B8
//	float m_swim_speed; //0x0170
//	char pad_0174[20]; //0x0174
//	uint32_t m_water_proof; //0x0188
//	char pad_018C[76]; //0x018C
//	eGameState m_game_state; //0x01D8
//	char pad_01DC[12]; //0x01DC
//	class CPeda* m_ped; //0x01E8
//	char pad_01F0[40]; //0x01F0
//	uint32_t m_frame_flags; //0x0218
//	char pad_021C[52]; //0x021C
//	uint32_t m_player_controls; //0x0250
//	char pad_0254[1256]; //0x0254
//	float m_wanted_can_change; //0x073C
//	char pad_0740[144]; //0x0740
//	float m_wanted_level_difficulty; //0x07D0 min:-1 max:1
//	char pad_07D4[52]; //0x07D4
//	float m_wanted_level_multiplier; //0x0808 min:0 max:1
//	char pad_080C[100]; //0x080C
//	uint32_t m_npc_ignore; //0x0870
//	char pad_0874[12]; //0x0874
//	bool m_is_wanted; //0x0880
//	char pad_0881[7]; //0x0881
//	uint32_t m_wanted_level; //0x0888
//	uint32_t m_wanted_level_display; //0x088C
//	char pad_0890[1120]; //0x0890
//	float m_run_speed; //0x0CF0
//	float m_stamina; //0x0CF4
//	float m_stamina_regen; //0x0CF8
//	char pad_0CFC[16]; //0x0CFC
//	float m_weapon_damage_mult; //0x0D0C
//	float m_weapon_defence_mult; //0x0D10
//	char pad_0D14[4]; //0x0D14
//	float m_melee_weapon_damage_mult; //0x0D18
//	float m_melee_damage_mult; //0x0D1C
//	float m_melee_defence_mult; //0x0D20
//	char pad_0D24[8]; //0x0D24
//	float m_melee_weapon_defence_mult; //0x0D2C
//}; //Size: 0x0D30

class CPlayerInfo
{
public:
	//char pad_0000[32]; //0x0000
	//class rage::rlGamerInfo m_net_player_data; //0x0020
	//char pad_0110[184]; //0x0110
	//float m_swim_speed; //0x01C8
	//char pad_01CC[20]; //0x01CC
	//uint32_t m_water_proof; //0x01E0
	//char pad_01E4[76]; //0x01E4
	//GameState m_game_state; //0x0230
	//char pad_0234[12]; //0x0234
	//class CPeda* m_ped; //0x0240
	//char pad_0248[40]; //0x0248
	//uint32_t m_frame_flags; //0x0270
	//char pad_0274[52]; //0x0274
	//uint32_t m_player_controls; //0x02A8
	//char pad_02AC[1248]; //0x02AC
	//float m_wanted_can_change; //0x078C
	//char pad_0790[304]; //0x0790
	//uint32_t m_npc_ignore; //0x08C0
	//char pad_08C4[12]; //0x08C4
	//bool m_is_wanted; //0x08D0
	//char pad_08D1[7]; //0x08D1
	//uint32_t m_wanted_level; //0x08D8
	//uint32_t m_wanted_level_display; //0x08DC
	//char pad_08E0[1120]; //0x08E0
	//float m_run_speed; //0x0D40
	//float m_stamina; //0x0D44
	//float m_stamina_regen; //0x0D48
	//char pad_0D4C[16]; //0x0D4C
	//float m_weapon_damage_mult; //0x0D5C
	//float m_weapon_defence_mult; //0x0D60
	//char pad_0D64[4]; //0x0D64
	//float m_melee_weapon_damage_mult; //0x0D68
	//float m_melee_damage_mult; //0x0D6C
	//float m_melee_defence_mult; //0x0D70
	//char pad_0D74[8]; //0x0D74
	//float m_melee_weapon_defence_mult; //0x0D7C
	char pad_0000[32]; //0x0000
	class rage::rlGamerInfo m_net_player_data; //0x0020
	char pad_0110[184]; //0x0110
	float m_swim_speed; //0x01C8
	char pad_01CC[20]; //0x01CC
	uint32_t m_water_proof; //0x01E0
	char pad_01E4[76]; //0x01E4
	GameState m_game_state; //0x0230
	char pad_0234[12]; //0x0234
	class CPed* m_ped; //0x0240
	char pad_0248[40]; //0x0248
	uint32_t m_frame_flags; //0x0270
	char pad_0274[52]; //0x0274
	uint32_t m_player_controls; //0x02A8
	char pad_02AC[1264]; //0x02AC
	float m_wanted_can_change; //0x079C
	char pad_07A0[304]; //0x07A0
	uint32_t m_npc_ignore; //0x08D0
	char pad_08D4[12]; //0x08D4
	bool m_is_wanted; //0x08E0
	char pad_08E1[7]; //0x08E1
	uint32_t m_wanted_level; //0x08E8
	uint32_t m_wanted_level_display; //0x08EC
	char pad_08F0[1120]; //0x08F0
	float m_run_speed; //0x0D50
	float m_stamina; //0x0D54
	float m_stamina_regen; //0x0D58
	char pad_0D5C[16]; //0x0D5C
	float m_weapon_damage_mult; //0x0D6C
	float m_weapon_defence_mult; //0x0D70
	char pad_0D74[4]; //0x0D74
	float m_melee_weapon_damage_mult; //0x0D78
	float m_melee_damage_mult; //0x0D7C
	float m_melee_defence_mult; //0x0D80
	char pad_0D84[8]; //0x0D84
	float m_melee_weapon_defence_mult; //0x0D8C
}; //Size: 0x0D80

//class CPlayerInfo {
//public:
//	char pad_0x0000[0x34]; //0x0000
//	__int32 InternalIP; //0x0034 
//	__int16 InternalPort; //0x0038 
//	char pad_0x003A[0x2]; //0x003A
//	__int32 RelayIP; //0x003C 
//	__int16 RelayPort; //0x0040 
//	char pad_0x0042[0x2]; //0x0042
//	__int32 ExternalIP; //0x0044 
//	__int16 ExternalPort; //0x0048 
//	char pad_0x004A[0x1E]; //0x004A
//	__int64 RockstarID; //0x0068 
//	char pad_0x0070[0xC]; //0x0070
//	char Name[20]; //0x7C 
//	char pad_0x0090[0xB8]; //0x0090
//	float SwimSpeed; //0x0148 
//	float RunSpeed; //0x014C 
//	char pad_0x0150[0x51]; //0x0150
//	unsigned char IsRockstarDev; //0x01A1 
//	char pad_0x01A2[0x26]; //0x01A2
//	CPed* PlayerPed; //0x01C8 
//	char pad_0x01D0[0x28]; //0x01D0
//	__int32 FrameFlags; //0x01F8 
//	char pad_0x01FC[0x618]; //0x01FC
//	unsigned char WantedLevel1; //0x0814 
//	char pad_0x0815[0x3]; //0x0815
//	unsigned char WantedLevel2; //0x0818 
//	char pad_0x0819[0x46F]; //0x0819
//	float MeleeDamage; //0x0C88 
//	char pad_0x0C8C[0x2F0]; //0x0C8C
//
//}; //Size=0x0F7C

class CHostStruct {
public:
	char pad_0000[392]; //0x0000
	uint32_t SessionHost; //0x0188
}; //Size: 0x018C

class CWeaponManager {
public:
	char pad_0x0000[0x20]; //0x0000
	CWeapon* WeaponInfo; //0x0020 
	char pad_0x0028[0x178]; //0x0028
	Vector3_t LastAimedPosition; //0x01A0 
	char pad_0x01AC[0x4]; //0x01AC
	Vector3_t ImpactPosition; //0x01B0 
	char pad_0x01BC[0x2E4]; //0x01BC

}; //Size=0x04A0

class CWeapon {
public:
	char pad_0x0000[0x10]; //0x0000
	__int32 NameHash; //0x0010 
	__int32 ModelHash; //0x0014 
	char pad_0x0018[0x40]; //0x0018
	unsigned char WeaponWheelSlot; //0x0058 
	unsigned char N00002FF2; //0x0059 
	char pad_0x005A[0x6]; //0x005A
	CAmmoInfo* AmmoInfo; //0x0060 
	CAimingInfo* AimingInfo; //0x0068 
	unsigned char ClipSize; //0x0070 
	char pad_0x0071[0x3]; //0x0071
	float AccuracySpread; //0x0074 
	float AccurateModeAccuracyModifier; //0x0078 
	float RunAndGunAccuracyModifier; //0x007C 
	float RunAndGunAccuracyMinOverride; //0x0080 
	float RecoilAccuracyMax; //0x0084 
	float RecoilErrorTime; //0x0088 
	float RecoilRecoveryRate; //0x008C 
	float RecoilAccuracyToAllowHeadShotAI; //0x0090 
	float MinHeadShotDistanceAI; //0x0094 
	float MaxHeadShotDistanceAI; //0x0098 
	float HeadShotDamageModifierAI; //0x009C 
	float RecoilAccuracyToAllowHeadShotPlayer; //0x00A0 
	float MinHeadShotDistancePlayer; //0x00A4 
	float MaxHeadShotDistancePlayer; //0x00A8 
	float HeadShotDamageModifierPlayer; //0x00AC 
	float Damage; //0x00B0 
	float DamageTime; //0x00B4 
	float DamageTimeInVehicle; //0x00B8 
	float DamageTimeInVehicleHeadShot; //0x00BC 
	float HitLimbsDamageModifier; //0x00C0 
	float NetworkHitLimbsDamageModifier; //0x00C4 
	float LightlyArmouredDamageModifier; //0x00C8 
	float VehicleDamageModifier; //0x00CC 
	float Force; //0x00D0 
	float ForceHitPed; //0x00D4 
	float ForceHitVehicle; //0x00D8 
	float ForceHitFlyingHeli; //0x00DC 
	char pad_0x00E0[0x10]; //0x00E0
	float ForceMaxStrengthMult; //0x00F0 
	float ForceFalloffRangeStart; //0x00F4 
	float ForceFalloffRangeEnd; //0x00F8 
	float ForceFalloffMin; //0x00FC 
	float ProjectileForce; //0x0100 
	float FragImpulse; //0x0104 
	float Penetration; //0x0108 
	float VerticalLaunchAdjustment; //0x010C 
	float DropForwardVelocity; //0x0110 
	float Speed; //0x0114 
	unsigned char BulletsInBatch; //0x0118 
	char pad_0x0119[0x3]; //0x0119
	float BatchSpread; //0x011C 
	float ReloadTimeMP; //0x0120 
	float ReloadTimeSP; //0x0124 
	float VehicleReloadTime; //0x0128 
	float AnimReloadRate; //0x012C 
	unsigned char BulletsPerAnimLoop; //0x0130 
	char pad_0x0131[0x3]; //0x0131
	float TimeBetweenShots; //0x0134 
	float TimeLeftBetweenShotsWhereShouldFireIsCached; //0x0138 
	float SpinUpTime; //0x013C 
	float SpinTime; //0x0140 
	float SpinDownTime; //0x0144 
	float AlternateWaitTime; //0x0148 
	float BulletBendingNearRadius; //0x014C 
	float BulletBendingFarRadius; //0x0150 
	float BulletBendingZoomedRadius; //0x0154 
	float FirstPersonBulletBendingNearRadius; //0x0158 
	float FirstPersonBulletBendingFarRadius; //0x015C 
	float FirstPersonBulletBendingZoomedRadius; //0x0160 
	char pad_0x0164[0xDC]; //0x0164
	__int32 InitialRumbleDuration; //0x0240 
	float InitialRumbleIntensity; //0x0244 
	float InitialRumbleIntensityTrigger; //0x0248 
	__int32 RumbleDuration; //0x024C 
	float RumbleIntensity; //0x0250 
	float RumbleIntensityTrigger; //0x0254 
	float RumbleDamageIntensity; //0x0258 
	__int32 InitialRumbleDurationFps; //0x025C 
	float InitialRumbleIntensityFps; //0x0260 
	__int32 RumbleDurationFps; //0x0264 
	float RumbleIntensityFps; //0x0268 
	float NetworkPlayerDamageModifier; //0x026C 
	float NetworkPedDamageModifier; //0x0270 
	float NetworkHeadShotPlayerDamageModifier; //0x0274 
	float LockOnRange; //0x0278 
	float WeaponRange; //0x027C 
	char pad_0x0280[0x8]; //0x0280
	float DamageFallOffRangeMin; //0x0288 
	float DamageFallOffRangeMax; //0x028C 
	char pad_0x0290[0x4]; //0x0290
	float DamageFallOffModifier; //0x0294 
	char pad_0x0298[0x50]; //0x0298
	float FirstPersonFOV; //0x02E8 
	char pad_0x02EC[0x678]; //0x02EC

}; //Size=0x0964

class CAmmoInfo {
public:
	char pad_0x0000[0x20]; //0x0000
	unsigned char AmmoMax; //0x0020 
	char pad_0x0021[0x3]; //0x0021
	unsigned char AmmoMax50; //0x0024 
	char pad_0x0025[0x3]; //0x0025
	unsigned char AmmoMax100; //0x0028 
	char pad_0x0029[0x3]; //0x0029
	unsigned char AmmoMaxMP; //0x002C 
	char pad_0x002D[0x3]; //0x002D
	unsigned char AmmoMax50MP; //0x0030 
	char pad_0x0031[0x3]; //0x0031
	unsigned char AmmoMax100MP; //0x0034 
	char pad_0x0035[0xB]; //0x0035
	float Damage; //0x0040 
	float LifeTime; //0x0044 
	float FromVehicleLifeTime; //0x0048 
	float LifeTimeAfterImpact; //0x004C 
	float LifeTimeAfterExplosion; //0x0050 
	float ExplosionTime; //0x0054 
	float LaunchSpeed; //0x0058 
	float SeparationTime; //0x005C 
	float TimeToReachTarget; //0x0060 
	float Damping; //0x0064 
	float GravityFactor; //0x0068 
	float RicochetTolerance; //0x006C 
	float PedRicochetTolerance; //0x0070 
	float VehicleRicochetTolerance; //0x0074 
	float FrictionMultiplier; //0x0078 
	char pad_0x007C[0x64]; //0x007C
	Vector3_t LightColour; //0x00E0 
	char pad_0x00EC[0x4]; //0x00EC
	float LightIntensity; //0x00F0 
	float LightRange; //0x00F4 
	float LightFalloffExp; //0x00F8 
	float LightFrequency; //0x00FC 
	float LightPower; //0x0100 
	float CoronaSize; //0x0104 
	float CoronaIntensity; //0x0108 
	float CoronaZBias; //0x010C 
	char pad_0x0110[0x40]; //0x0110
	unsigned char AmmoMaxMPBonus; //0x0150 
	char pad_0x0151[0x7]; //0x0151

}; //Size=0x0158

class CReplayInterface {
public:
	char pad_0x0000[0x8]; //0x0000
	CCameraInterface* CameraInterface; //0x0008 
	CVehicleInterface* VehicleInterface; //0x0010 
	CPedInterface* PedInterface; //0x0018 
	CPickupInterface* PickupInterface; //0x0020 
	CObjectInterface* ObjectInterface; //0x0028 
	char pad_0x0030[0x10]; //0x0030

}; //Size=0x0040

class CCameraInterface {
public:
	char pad_0x0000[0x408]; //0x0000

}; //Size=0x0408

class CVehicleInterface {
public:
	char pad_0x0000[0x180]; //0x0000
	CVehList* VehList; //0x0180 
	__int32 MaxVehicles; //0x0188 
	char pad_0x018C[0x4]; //0x018C
	__int32 CurVehicles; //0x0190 
	char pad_0x0194[0x274]; //0x0194

}; //Size=0x0408

class CPedInterface {
public:
	char pad_0x0000[0x8]; //0x0000

}; //Size=0x0008

class CPickupInterface {
public:
	char pad_0x0000[0x100]; //0x0000
	CPickupList* PickupList; //0x0100 
	__int32 MaxPickups; //0x0108 
	char pad_0x010C[0x4]; //0x010C
	__int32 CurPickups; //0x0110 
	char pad_0x0114[0x2F4]; //0x0114

}; //Size=0x0408

class CObjectInterface {
public:
	char pad_0x0000[0x158]; //0x0000
	CObjectList* ObjectList; //0x0158 
	__int32 MaxObjects; //0x0160 
	char pad_0x0164[0x4]; //0x0164
	__int32 CurObjects; //0x0168 
	char pad_0x016C[0x2DC]; //0x016C

}; //Size=0x0448

class CPickupList {
public:
	char pad_0x0000[0x8]; //0x0000

}; //Size=0x0008

class CVehList {
public:
	char pad_0x0000[0x8]; //0x0000

}; //Size=0x0008

class CObjectList {
public:
	char pad_0x0000[0x48]; //0x0000

}; //Size=0x0048

class CObjectHandle {
public:
	char pad_0x0000[0x8]; //0x0000
	__int32 Handle; //0x0008 
	char pad_0x000C[0x3C]; //0x000C

}; //Size=0x0048

class CAimingInfo {
public:
	__int32 Hash; //0x0000 
	float HeadingLimit; //0x0004 
	float SweepPitchMin; //0x0008 
	float SweepPitchMax; //0x000C 

}; //Size=0x0010

//class CNetGamePlayer {
//public:
//	char pad_0x0000[0x2D]; //0x0000
//	uint8_t m_playerID; //0x002D 
//	char pad_0x002E[0x7A]; //0x002E
//	CPlayerInfo* PlayerInfo; //0x00A8 
//	char pad_0x00B0[0x20]; //0x00B0
//
//}; //Size=0x00D0



namespace rage
{
	class nonPhysicalPlayerDataBase
	{
	public:
		virtual ~nonPhysicalPlayerDataBase();
		virtual void read();
		virtual void write();
		virtual void calculate_size();
		virtual void log();
	}; //Size: 0x0008
	static_assert(sizeof(nonPhysicalPlayerDataBase) == 0x8);
}

//#pragma pack(push, 4)
class CNonPhysicalPlayerData : public rage::nonPhysicalPlayerDataBase
{
public:
	int32_t m_bubble_id; //0x0008
	int32_t m_player_id; //0x000C
	rage::fvector3 m_position; //0x0010
}; //Size: 0x001C
//static_assert(sizeof(CNonPhysicalPlayerData) == 0x1C);
//#pragma pack(pop)

namespace rage
{
//#pragma pack(push, 8)
	class netPlayer
	{
	public:
		virtual void* _0x00();
		virtual void* _0x08();
		virtual uint32_t _0x10();
		virtual netPlayer* _0x18(void*);
		virtual bool _0x20(void*);
		virtual bool _0x28(void**);
		virtual void destructor();
		virtual void reset();
		virtual bool is_valid();
		virtual const char* get_name();
		virtual std::uint64_t get_host_token();
		//virtual void _0x50();
		virtual void _0x58();
		virtual bool is_host();
		virtual rage::rlGamerInfo* get_net_data();
		/*virtual void _0x68();*/
		virtual void _0x70();

		char pad_0008[8]; //0x0008
		CNonPhysicalPlayerData* m_non_physical_player; //0x0010
		uint32_t m_msg_id; //0x0018
		char pad_001C[4]; //0x001C
		uint8_t m_active_id; //0x0020
		uint8_t m_player_id; //0x0021
		char pad_0022[3]; //0x0022
		uint16_t m_complaints; //0x0026
		char pad_0027[17]; //0x0028
		class CNetGamePlayer* m_unk_net_player_list[10]; //0x0040
		char pad_0090[4]; //0x0090
		uint64_t pad_0098; //0x0098
	}; //Size: 0x00A0 
	//class netPlayer
	//{
	//public:
	//	virtual void* _0x00();
	//	virtual void* _0x08();
	//	virtual uint32_t _0x10();
	//	virtual netPlayer* _0x18(void*);
	//	virtual bool _0x20(void*);
	//	virtual bool _0x28(void**);
	//	virtual void destructor();
	//	virtual void reset();
	//	virtual bool is_valid();
	//	virtual const char* get_name();
	//	virtual void _0x50();
	//	virtual bool is_host();
	//	virtual rage::rlGamerInfo* get_net_data();
	//	virtual void _0x68();

	//	char pad_0008[8]; //0x0008
	//	CNonPhysicalPlayerData* m_non_physical_player; //0x0010
	//	uint32_t m_msg_id; //0x0018
	//	char pad_001C[4]; //0x001C
	//	uint8_t m_active_id; //0x0020
	//	uint8_t m_player_id; //0x0021
	//	char pad_0022[3]; //0x0022
	//	uint16_t m_complaints; //0x0026
	//	char pad_0027[17]; //0x0028
	//	class CNetGamePlayer* m_unk_net_player_list[10]; //0x0040
	//	char pad_0090[4]; //0x0090
	//	uint64_t pad_0098; //0x0098
	//}; //Size: 0x00A0
	/*static_assert(sizeof(netPlayer) == 0xA0);
#pragma pack(pop)*/
}
#include <cstdint>

//#pragma pack(push, 1)
class ClanData
{
public:
	int64_t m_clan_member_id; //0x0000
	int64_t m_clan_id; //0x0008
	int32_t m_clan_color; //0x0010
	int32_t m_clan_member_count; //0x0014
	int32_t m_clan_created_time; //0x0018
	bool m_is_system_clan; //0x001C
	bool m_is_clan_open; //0x001D
	char m_clan_name[25]; //0x001E
	char m_clan_tag[5]; //0x0037
	char m_clan_motto[65]; //0x003C
	char pad_007D[3]; //0x007D
	int64_t m_clan_id_2; //0x0080
	char m_clan_rank_name[25]; //0x0088
	char pad_00A1[3]; //0x00A1
	int32_t m_clan_rank_order; //0x00A4
	int64_t m_clan_rank_flags; //0x00A8
	char unk_00B0[8]; //0x00B0
};
namespace rage
{
	class rlSessionInfo
	{
	public:
		uint64_t m_unk; //0x0000
		uint64_t m_session_token; //0x0008
		rlGamerInfoBase m_net_player_data; //0x0010
	};
	//static_assert(sizeof(rlSessionInfo) == 0xD0);
}
//#pragma pack(pop)
class CNetGamePlayer : public rage::netPlayer
{
public:
	void* m_unk;
	CPlayerInfo* m_player_info; //0x00A0
	uint32_t m_matchmaking_group; //0x0008
	bool m_is_spectating; //0x000C
	char pad_00AD[3]; //0x000AD
	uint64_t unk_00B0; //0x00B0
	char unk_00B8; //0x00B8
	char pad_00B9[3]; //0x00B9
	uint32_t unk_00BC; //0x00BC
	uint32_t unk_00C0; //0x00C0
	char pad_00C4[4]; //0x00C4
	ClanData m_clan_data; //0x00C8
	char m_crew_rank_title[25]; //0x0180
	bool m_is_rockstar_dev; //0x0199
	bool m_is_rockstar_qa; //0x019A
	bool m_is_cheater; //0x019B
	uint32_t unk_019C; //0x019C
	uint16_t unk_01A0; //0x01A0
	char unk_01A2; //0x01A2
	char pad_01A3; //0x01A3
	uint32_t m_phone_explosion_vehicle_net_id; //0x01A4
	uint16_t unk_01A8; //0x01A8
	bool m_has_started_transition; //0x01AA
	char pad_01AB[5]; //0x01AB
	rage::rlSessionInfo m_transition_session_info; //0x01A3
	char pad_022D[16]; //0x022D
	void* m_unk2;
	uint64_t unk_0230; //0x0230
	uint64_t unk_0238; //0x0238
	uint32_t m_mute_count; //0x0240
	uint32_t m_mute_talkers_count; //0x0244
	char pad_0248[5]; //0x0248
	bool m_have_communication_privileges; //0x024D
	uint16_t unk_024E; //0x024E
	uint16_t unk_0250; //0x0250
	char pad_0252[2]; //0x0252
	uint32_t m_cheat_report_ids[20]; //0x0254
	uint32_t m_num_cheat_reports; //0x02A4
	uint8_t unk_02A8; //0x02A8
	char pad_02A9[3]; //0x02A9
	uint32_t unk_02AC; //0x02AC
	char unk_02B0; //0x02B0
	char pad_02B1[3]; //0x02B1
	uint32_t unk_02B4; //0x02B4
	uint32_t m_account_id; //0x02B4
	uint32_t m_unk_02BC; //0x02BC
}; //Size: 0x02C0

class CAIHandlingInfo {
public:
	char pad_0x0000[0x48]; //0x0000

}; //Size=0x0048

class CFlyingHandlingData {
public:
	char pad_0x0000[0x8]; //0x0000
	float fThrust; //0x0008 
	float fThrustFallOff; //0x000C 
	float fThrustVectoring; //0x0010 
	char pad_0x0014[0x8]; //0x0014
	float fYawMult; //0x001C 
	float fYawStabilise; //0x0020 
	float fSideSlipMult; //0x0024 
	char pad_0x0028[0x4]; //0x0028
	float fRollMult; //0x002C 
	float fRollStabilise; //0x0030 
	float N000026D3; //0x0034 
	float fPitchMult; //0x0038 
	float fPitchStabilise; //0x003C 
	char pad_0x0040[0x4]; //0x0040
	float fFormLiftMult; //0x0044 
	float fAttackLiftMult; //0x0048 
	float fAttackDiveMult; //0x004C 
	float fGearDownDragV; //0x0050 
	float fGearDownLiftMult; //0x0054 
	float fWindMult; //0x0058 
	float fMoveRes; //0x005C 
	Vector3_t vecTurnRes; //0x0060 
	char pad_0x006C[0x4]; //0x006C
	Vector3_t vecSpeedRes; //0x0070 
	char pad_0x007C[0x4]; //0x007C
	float fGearDoorFrontOpen; //0x0080 
	float fGearDoorRearOpen; //0x0084 
	float fGearDoorRearOpen2; //0x0088 
	float fGearDoorRearMOpen; //0x008C 
	float fTurublenceMagnitudeMax; //0x0090 
	float fTurublenceForceMulti; //0x0094 
	float fTurublenceRollTorqueMulti; //0x0098 
	float fTurublencePitchTorqueMulti; //0x009C 
	float fBodyDamageControlEffectMult; //0x00A0 
	float fInputSensitivityForDifficulty; //0x00A4 
	float fOnGroundYawBoostSpeedPeak; //0x00A8 
	float fOnGroundYawBoostSpeedCap; //0x00AC 
	float fEngineOffGlideMulti; //0x00B0 

}; //Size=0x00B4

class CBoatHandlingData {
public:
	char pad_0x0000[0x8]; //0x0000
	float fBoxFrontMult; //0x0008 
	float fBoxRearMult; //0x000C 
	float fBoxSideMult; //0x0010 
	float fSampleTop; //0x0014 
	float fSampleBottom; //0x0018 
	float N000028C4; //0x001C 
	float fAquaplaneForce; //0x0020 
	float fAquaplanePushWaterMult; //0x0024 
	float fAquaplanePushWaterCap; //0x0028 
	float fAquaplanePushWaterApply; //0x002C 
	float fRudderForce; //0x0030 
	float fRudderOffsetSubmerge; //0x0034 
	float fRudderOffsetForce; //0x0038 
	float fRudderOffsetForceZMult; //0x003C 
	float fWaveAudioMult; //0x0040 
	float N000028CE; //0x0044 
	float N0000283E; //0x0048 
	float N000028D0; //0x004C 
	Vector3_t vecMoveResistance; //0x0050 
	float N000028D4; //0x005C 
	Vector3_t vecTurnResistance; //0x0060 
	float N000028D8; //0x006C 
	float fLook_L_R_CamHeight; //0x0070 
	float fDragCoefficient; //0x0074 
	float fKeelSphereSize; //0x0078 
	float fPropRadius; //0x007C 
	float fLowLodAngOffset; //0x0080 
	float fLowLodDraughtOffset; //0x0084 
	float fImpellerOffset; //0x0088 
	float fImpellerForceMult; //0x008C 
	float fDinghySphereBuoyConst; //0x0090 
	float fProwRaiseMult; //0x0094 

}; //Size=0x0098

class CBikeHandlingData {
public:
	char pad_0x0000[0x8]; //0x0000
	float fLeanFwdCOMMult; //0x0008 
	float fLeanFwdForceMult; //0x000C 
	float fLeanBakCOMMult; //0x0010 
	float fLeanBakForceMult; //0x0014 
	float fMaxBankAngle; //0x0018 
	char pad_0x001C[0x4]; //0x001C
	float fFullAnimAngle; //0x0020 
	float fDesLeanReturnFrac; //0x0024 
	float fStickLeanMult; //0x0028 
	float fBrakingStabilityMult; //0x002C 
	float fInAirSteerMult; //0x0030 
	float fWheelieBalancePoint; //0x0034 
	float fStoppieBalancePoint; //0x0038 
	float fWheelieSteerMult; //0x003C 
	float fRearBalanceMult; //0x0040 
	float fFrontBalanceMult; //0x0044 
	float fBikeGroundSideFrictionMult; //0x0048 
	float fBikeWheelGroundSideFrictionMult; //0x004C 
	float fBikeOnStandLeanAngle; //0x0050 c
	float fBikeOnStandSteerAngle; //0x0054 
	float fJumpForce; //0x0058 

}; //Size=0x005C

typedef union {
	CFlyingHandlingData FlyingHandlingData;
	CBikeHandlingData BikeHandlingData;
	CBoatHandlingData BoatHandlingData;
} CSubHandlingDataType;

class CSubHandlingData {
public:
	CSubHandlingDataType * SubHandlingData; //0x0000 
	CVehicleWeaponHandlingData* VehicleWeaponHandlingData; //0x0008 
	char pad_0x0010[0x8]; //0x0010

}; //Size=0x0018

class CModelInfo {
public:
	char pad_0x0000[0x808]; //0x0000

}; //Size=0x0808

class CPedDrawHandler {
public:
	char pad_0x0000[0x144]; //0x0000
	__int32 Face; //0x0144 
	__int32 FaceVariation; //0x0148 
	__int32 N00002CBF; //0x014C 
	char pad_0x0150[0x2B8]; //0x0150

}; //Size=0x0408

class CVehicleWeaponHandlingData {
public:
	char pad_0x0000[0x48]; //0x0000

}; //Size=0x0048


class CScriptedGameEvent {
public:
	char pad_0x0000[0x48]; //0x0000
	uint64_t EventID; //0x0048 
	char pad_0x0050[0x1AC]; //0x0050
	uint32_t ArgCount; //0x01FC 
	char pad_0x0200[0x24C]; //0x0200

	uint64_t* GetArgs() {
		return (uint64_t*)((uintptr_t)(this) + 0x224);
	}

}; //Size=0x044C

class CNetworkIncrementStatEvent {
public:
	char pad_0x0000[0x8]; //0x0000
	uint32_t Hash; //0x0008 
	int64_t Value; //0x000C 

}; //Size=0x0014

class CExplosionEvent {
public:
	char pad_0x0000[0x8]; //0x0000
	uint32_t ExplosionType; //0x0008 
	char pad_0x000C[0xC]; //0x000C
	Vector3 Position;
	char pad_0x0024[0x20]; //0x0024
	float DamageScale; //0x0044 
	char pad_0x0048[0xB8]; //0x0048
}; //Size=0x0100

class CRequestControlEvent {
public:
	char pad_0x0000[0x4]; //0x0000
	int32_t EntityID; //0x0008 

}; //Size=0x000C

typedef union {
	CScriptedGameEvent ScriptedGameEvent;
	CNetworkIncrementStatEvent NetworkIncrementStatEvent;
	CExplosionEvent ExplosionEvent;
	CRequestControlEvent RequestControlEvent;
} NetEventContext;

class CNetEventInfo {
public:
	CNetEventVTable * VTable; //0x0000 
	int16_t ID; //0x0008 
	char pad_0x000A[0xE]; //0x000A
	CNetGamePlayer* Receiver; //0x0018 
	char pad_0x0020[0x8]; //0x0020
	NetEventContext* m_context; //0x0028 

}; //Size=0x0278

class CNetEventVTable {
public:
	char pad_0x0000[0x8]; //0x0000
	char*(*GetName)(); //0x0008 
	char pad_0x0010[0x8]; //0x0010
	void(*m_0x18)(int64_t a1, int64_t a2); //0x0018 
	char pad_0x0020[0x10]; //0x0020
	void(*Setup)(CNetEventInfo* event_info, int64_t a2, CNetGamePlayer* sender, int64_t a4); //0x0030 
	uint8_t(*Execute)(CNetEventInfo* event_info, CNetGamePlayer* sender, int64_t a3); //0x0038 
	char pad_0x0040[0x18]; //0x0040
	void(*m_0x58)(CNetEventInfo* event_info, int64_t a2, int64_t a3, CNetGamePlayer* sender); //0x0058 
	char pad_0x0060[0x78]; //0x0060

}; //Size=0x00D8

   /*Model info*/
class fwArchetypeDef {
public:
	virtual ~fwArchetypeDef();

	virtual int64_t GetTypeIdentifier();

	float lodDist;
	uint32_t flags; // 0x10000 = alphaclip
	uint32_t specialAttribute; // lower 5 bits == 31 -> use alpha clip, get masked to 31 in InitializeFromArchetypeDef
	uint32_t pad;
	void* pad2;
	float bbMin[4];
	float bbMax[4];
	float bsCentre[4];
	float bsRadius;
	float hdTextureDist;
	uint32_t name;
	uint32_t textureDictionary;
	uint32_t clipDictionary;
	uint32_t drawableDictionary;
	uint32_t physicsDictionary;
	uint32_t assetType;
	uint32_t assetName;
	uint32_t pad5[7];

public:
	fwArchetypeDef() {
		flags = 0x10000; // was 0x2000
		lodDist = 299.0f;
		hdTextureDist = 375.0f;

		drawableDictionary = 0;
		assetType = 3;
		assetName = 0x12345678;

		specialAttribute = 31;

		pad = 0;
		pad2 = 0;
		clipDictionary = 0;
		physicsDictionary = 0;
		memset(pad5, 0, sizeof(physicsDictionary));
	}
};
class fwArchetype {
public:
	virtual ~fwArchetype() = default;

	char _0x0008[0x10]; // 0x0000
	Hash m_hash; // 0x0018
	char _0x001C[0x10]; // 0x001C
	float m_radius; // 0x002C
	float m_aabbMin[4]; // 0x0030
	float m_aabbMax[4]; // 0x0040
	uint32_t m_flags; // 0x0050
	char _0x0054[0x12]; // 0x0054
	uint16_t m_index; // 0x0066
};
class fwEntity {
public:
	virtual ~fwEntity() = 0;

	virtual bool IsOfType(uint32_t hash) = 0;
};


//class CBaseModelInfo : public fwArchetype {
//public:
//	virtual ~CBaseModelInfo() {}
//	virtual void Initialize() {}
//	virtual void InitializeFromArchetypeDef(uint32_t, fwArchetypeDef*, bool) {}
//	virtual fwEntity* CreateEntity() { return nullptr; }
//	// and lots of other functions...
//
//public:
//	uint8_t GetModelType() const {
//		return m_modelType & 0x1F;
//	}
//protected:
//	char _0x0068[0x35];	// 0x0068
//	uint8_t m_modelType;	// 0x009D (& 0x1F)
//	char _0x009E[0x2];	// 0x009E
//	uint32_t m_unkFlag;	// 0x00A0
//	char _0x00A4[0x4];	// 0x00A4
//	void* m_0x00A8;		// 0x00A8
//};

enum class eModelType : std::uint8_t
{
	Invalid,
	Object,
	MLO,
	Time,
	Weapon,
	Vehicle,
	Ped,
	Destructable,
	test,
	WorldObject = 33,
	Sprinkler = 35,
	Unk65 = 65,
	EmissiveLOD = 67,
	Plant = 129,
	LOD = 131,
	Unk132 = 132,
	Unk133 = 133,
	OnlineOnlyPed = 134,
	Building = 161,
	Unk193 = 193
};

class CBaseModelInfo : public fwArchetype
{
public:
	char pad_0070[8]; //0x0070
	uint64_t unk_0078; //0x0078
	uint64_t unk_0080; //0x0080
	char pad_0088[8]; //0x0088
	uint64_t unk_0090; //0x0090
	char pad_0098[5]; //0x0098
	eModelType m_model_type; //0x009D
	char pad_009E[6]; //0x009E
	uint64_t unk_00A8; //0x00A8
}; //Size: 0x00B0

class CVehicleModelInfo : public CBaseModelInfo {
public:
	virtual ~CVehicleModelInfo() {}
	virtual void Initialize() {}
	virtual void InitializeFromArchetypeDef(uint32_t, fwArchetypeDef*, bool) {}
	virtual fwEntity* CreateEntity() { return nullptr; }
	// and lots of other functions...

public:
	void* m_0x00B0; // 0x00B0
	char _0x00B8[0x40]; // 0x00B8
	uint8_t m_primaryColorCombinations[25]; // 0x00F8
	uint8_t m_secondaryColorCombinations[25]; // 0x0111
	uint8_t m_unkColor1Combinations[25]; // 0x012A
	uint8_t m_unkColor2Combinations[25]; // 0x0143
	uint8_t m_interiorColorCombinations[25]; // 0x015C
	uint8_t m_dashboardColorCombinations[25]; // 0x0175
	char _0x018E[0xE2]; // 0x018E
	char m_displayName[12]; // 0x0270 (aka gameName)
	char m_manufacturerName[12]; // 0x027C (aka makeName)
	uint8_t* m_modKits; // 0x0288
	uint16_t m_modKitsCount; // 0x0290
	char _0x0292[0x46]; // 0x0292
	void* m_driverInfo; // 0x02D8
	uint8_t m_numDrivers; // 0x02E0
	char _0x02E1[0x37]; // 0x02E1
	uint32_t m_vehicleType; // 0x0318
	uint32_t m_unkVehicleType; // 0x031C
	uint32_t m_diffuseTint; // 0x0320
	char _0x0324[0x90]; // 0x0324
	uint8_t m_unkModKitVal; // 0x03B4
	char _0x03B5[0xA7]; // 0x03B5
	float m_wheelScale; // 0x045C
	float m_wheelScaleRear; // 0x0460
	float m_defaultBodyHealth; // 0x0464
	char _0x0468[0x20]; // 0x0468
	uint32_t m_handlingIndex; // 0x0488
	uint32_t m_identicalModelSpawnDistance; // 0x048C
	char _0x0490[0x4]; // 0x0490
	uint32_t m_numColorCombinations; // 0x0494
	char _0x0498[0x30]; // 0x0498
	void* m_0x04C8; // 0x04C8 (wheel data? 0xAC -> burnout mult?)
	char _0x04D0[0x3B]; // 0x04D0
	uint8_t m_sirenInfoId; // 0x050B
	char _0x050C[0xC]; // 0x050C
	uint8_t m_vehicleClass; // 0x0518 (& 0x1F; (>> 5) & 3 -> plate type)
	char _0x0519[0x2F]; // 0x0519
	int m_seatCount; // 0x0548
	uint32_t m_flags1; // 0x054C
	uint32_t m_flags2; // 0x0550
	uint32_t m_flags3; // 0x0554
	uint32_t m_flags4; // 0x0558
	uint32_t m_flags5; // 0x055C
};
class CVehicleModelInfo1290 : public CBaseModelInfo {
public:
	virtual ~CVehicleModelInfo1290() {}
	virtual void Initialize() {}
	virtual void InitializeFromArchetypeDef(uint32_t, fwArchetypeDef*, bool) {}
	virtual fwEntity* CreateEntity() { return nullptr; }
	// and lots of other functions...

public:
	void* m_0x00B0; // 0x00B0
	char _0x00B8[0x40]; // 0x00B8
	uint8_t m_primaryColorCombinations[25]; // 0x00F8
	uint8_t m_secondaryColorCombinations[25]; // 0x0111
	uint8_t m_unkColor1Combinations[25]; // 0x012A
	uint8_t m_unkColor2Combinations[25]; // 0x0143
	uint8_t m_interiorColorCombinations[25]; // 0x015C
	uint8_t m_dashboardColorCombinations[25]; // 0x0175
	char _0x018E[0x10A]; // 0x018E
	char m_displayName[12]; // 0x0298 (aka gameName)
	char m_manufacturerName[12]; // 0x02A4 (aka makeName)
	uint16_t* m_modKits; // 0x02B0
	uint16_t m_modKitsCount; // 0x02B8
	char _0x02BA[0x46]; // 0x02BA
	void* m_driverInfo; // 0x0300
	uint8_t m_numDrivers; // 0x0308
	char _0x0309[0x37]; // 0x02E3
	uint32_t m_vehicleType; // 0x0340
	uint32_t m_unkVehicleType; // 0x0344
	uint32_t m_diffuseTint; // 0x0348
	char _0x034C[0x90]; // 0x034C
	uint8_t m_unkModKitVal; // 0x03DC (also uint16_t now?)
	char _0x03DD[0xA7]; // 0x03DD
	float m_wheelScale; // 0x0484
	float m_wheelScaleRear; // 0x0488
	float m_defaultBodyHealth; // 0x048C
	char _0x0490[0x20]; // 0x0490
	uint32_t m_handlingIndex; // 0x04B8
	uint32_t m_identicalModelSpawnDistance; // 0x04BC
	char _0x04C0[0x4]; // 0x04C0
	uint32_t m_numColorCombinations; // 0x04C4
	uint32_t m_fragmentIndex; // 0x04C8
	char _0x04CC[0x2C]; // 0x04CC
	void* m_0x04F8; // 0x04F8 (wheel data? 0xAC -> burnout mult?)
	char _0x0500[0x3B]; // 0x0500
	uint8_t m_sirenInfoId; // 0x053B
	char _0x053C[0x7]; // 0x053C
	uint8_t m_0x0543; // 0x0543
	char _0x0544_[0x4]; // 0x0544
	uint8_t m_vehicleClass; // 0x0548 (& 0x1F; (>> 5) & 3 -> plate type)
	char _0x0549[0x2F]; // 0x0549
	int m_seatCount; // 0x0578 (use only if unk_0x00B0->seatCount can't be used)
	uint32_t m_flags1; // 0x057C
	uint32_t m_flags2; // 0x0580
	uint32_t m_flags3; // 0x0584
	uint32_t m_flags4; // 0x0588
	uint32_t m_flags5; // 0x058C
	uint32_t m_flags6; // 0x0590
	char _0x0594[0xC]; // 0x0594
};

class CNetworkBandwithManager {
public:
	char m_pad_0x0000[0x8]; //0x0000

}; //Size=0x0008

class CNetworkPlayerManager {
public:
	char m_pad_0x0000[0x10]; //0x0000
	CNetworkBandwithManager* m_bandwidthManager; //0x0010 
	char m_pad_0x0018[0xD0]; //0x0018
	CNetGamePlayer* m_localPlayer; //0x00E8 
	char m_pad_0x00F0[0x88]; //0x00F0
	uint8_t m_playersOnline; //0x0178 
	char m_pad_0x0179[0x7]; //0x0179
	CNetGamePlayer* m_players[0x20]; //0x0180 

}; //Size=0x0280

struct WorldManager {
	char field_0[3752];
	float WindSpeed;
	char field_2[16];
	float Fog;
	float RoadSlipperiness;
};


class CFragInst {
public:
	char pad_0x0000[0x10]; //0x0000
	CArcheTypeDamp* ArcheTypeDamp; //0x0010 
	char pad_0x0018[0x60]; //0x0018
	CFragType* FragType; //0x0078 
	char pad_0x0080[0x388]; //0x0080

}; //Size=0x0408

class CArcheTypeDamp {
public:
	char pad_0x0000[0x20]; //0x0000
	phBoundComposite* Bounds; //0x0020 
	char pad_0x0028[0x130]; //0x0028
	CEntitySkeleton* EntitySkeleton; //0x0158 
	char pad_0x0160[0x2A8]; //0x0160

}; //Size=0x0408

class CFragType {
public:
	char pad_0x0000[0xF0]; //0x0000
	CFragPhysicsLODGroup* FragPhysicsLODGroup; //0x00F0 
	char pad_0x00F8[0x390]; //0x00F8

}; //Size=0x0488

class CFragPhysicsLODGroup {
public:
	char pad_0x0000[0x10]; //0x0000
	CFragPhysicsLOD* FragPhysicsLOD1; //0x0010 
	char pad_0x0018[0x3F0]; //0x0018

}; //Size=0x0408

class CFragPhysicsLOD {
public:
	char pad_0x0000[0xC0]; //0x0000
	CGroupNames* GroupNames; //0x00C0 
	Groups* Groups; //0x00C8 
	char pad_0x00D0[0x3F8]; //0x00D0

}; //Size=0x04C8

class CGroupNames {
public:
	char pad_0x0000[0x8]; //0x0000

}; //Size=0x0008

class Groups {
public:
	char pad_0x0000[0x48]; //0x0000

}; //Size=0x0048

enum BoundType : uint8_t {
	BTSphere = 0,
	BTCapsule = 1,
	BTBox = 3,
	BTGeometry = 4,
	BTBoundingVolumeHierarchy = 8,
	BTComposite = 10,
	BTDisc = 12,
	BTCylinder = 13,
};

class phBoundComposite {
public:
	char pad_0x0000[0x10]; //0x0000
	BoundType Type; //0x0010 
	char pad_0x0011[0x3]; //0x0011
	float BoundingSphereRadius; //0x0014 
	char pad_0x0018[0x8]; //0x0018
	Vector3_t BoundingBoxMax; //0x0020 
	char pad_0x002C[0x4]; //0x002C
	Vector3_t BoundingBoxMin; //0x0030 
	char pad_0x003C[0x4]; //0x003C
	Vector3_t BoundingBoxCenter; //0x0040 
	char pad_0x004C[0x4]; //0x004C
	Vector3_t Center; //0x0050 
	char pad_0x005C[0x3AC]; //0x005C

}; //Size=0x0408


class CEntitySkeleton {
public:
	crSkeletonData * SkeletonData; //0x0000 
	NativeMatrix* EntityMatrix; //0x0008 
	NativeMatrix* desiredBonesMatricesArray; //0x0010 
	NativeMatrix* currentBonesMatricesArray; //0x0018 
	__int32 BonesCount; //0x0020 
	char pad_0x0024[0x3E4]; //0x0024

}; //Size=0x0408

class N000014A7 {
public:
	char pad_0x0000[0x60]; //0x0000
	float N000014C0; //0x0060 
	char pad_0x0064[0x3E4]; //0x0064

}; //Size=0x0448

class crSkeletonData {
public:
	char pad_0x0000[0x20]; //0x0000
	crSkeletonBoneDataArray* Bones; //0x0020 
	NativeMatrix* array_BonesTransformationsInverted; //0x0028 
	NativeMatrix* array_BonesTransformations; //0x0030 
	char pad_0x0038[0x40C]; //0x0038

}; //Size=0x0444

class NativeMatrix {
public:
	Matrix Matrix; //0x0000 
}; //Size=0x0040

class crSkeletonBoneData {
public:
	Vector4 Rotation; //0x0000 
	Vector3_t Position; //0x0010 
	char pad_0x001C[0x16]; //0x001C
	__int16 ParentIndex; //0x0032 
	char pad_0x0034[0x4]; //0x0034
	char* N0000160F; //0x0038 
	char pad_0x0040[0x2]; //0x0040
	__int16 index; //0x0042 
	char pad_0x0044[0xC]; //0x0044

}; //Size=0x0050

class crSkeletonBoneDataArray {
public:
	crSkeletonBoneData * array_boneDatas; //0x0000 

}; //Size=0x0050

template <class T>
class RageNode {
public:
	char pad_0000[8];
	T *Data;
	class RageNode *Next;
	class RageNode *Last;
};

enum TransactionService {
	SERVICE_EARN_AMBIENT_JOB_BEAST = 0xCF63BF45,
	SERVICE_EARN_AMBIENT_JOB_BLAST = 0xC84D30CC,
	SERVICE_EARN_AMBIENT_JOB_CHALLENGES = 0xA87819A3,
	SERVICE_EARN_AMBIENT_JOB_CHECKPOINT_COLLECTION = 0xFC71898E,
	SERVICE_EARN_AMBIENT_JOB_DEAD_DROP = 0x5AEF7C87,
	SERVICE_EARN_AMBIENT_JOB_DESTROY_VEH = 0x8D682613,
	SERVICE_EARN_AMBIENT_JOB_DISTRACT_COPS = 0x862FB02E,
	SERVICE_EARN_AMBIENT_JOB_HELI_HOT_TARGET = 0x06A679FE,
	SERVICE_EARN_AMBIENT_JOB_HOT_PROPERTY = 0xB8D124BE,
	SERVICE_EARN_AMBIENT_JOB_HOT_TARGET_DELIVER = 0x60988977,
	SERVICE_EARN_AMBIENT_JOB_HOT_TARGET_KILL = 0x74EC47CE,
	SERVICE_EARN_AMBIENT_JOB_KING = 0xF353DF93,
	SERVICE_EARN_AMBIENT_JOB_PASS_PARCEL = 0x5E0B0A1C,
	SERVICE_EARN_AMBIENT_JOB_PENNED_IN = 0x39B3A1A7,
	SERVICE_EARN_AMBIENT_JOB_PLANE_TAKEDOWN = 0x6A22D039,
	SERVICE_EARN_AMBIENT_JOB_TIME_TRIAL = 0x67878154,
	SERVICE_EARN_AMBIENT_JOB_URBAN_WARFARE = 0x0C92ECEF,
	SERVICE_EARN_AMBIENT_MUGGING = 0xEC745CB2,
	SERVICE_EARN_AMBIENT_PICKUP = 0x20D60B56,
	SERVICE_EARN_ARMORED_TRUCKS = 0xB94DDB9B,
	SERVICE_EARN_BANK_INTEREST = 0xF97DB87A,
	SERVICE_EARN_BEND_JOB = 0x176D9D54,
	SERVICE_EARN_BETTING = 0xACA75AAE, //only 600,000 per second and a max of 1 billion before requires a short cooldown
	SERVICE_EARN_BONUS = 0x5C7EA5E8,
	SERVICE_EARN_BOSS = 0x3E7AA93E,
	SERVICE_EARN_BOSS_AGENCY = 0xCCFA5F2D,
	SERVICE_EARN_BOUNTY_COLLECTED = 0xC4F96E65,
	SERVICE_EARN_CASHING_OUT = 0x50503398,
	SERVICE_EARN_CHALLENGE_WIN = 0xFC8D0020,
	SERVICE_EARN_CNCB = 0x4D8C639E,
	SERVICE_EARN_CNCW = 0xD89979EE,
	SERVICE_EARN_CRATE_DROP = 0x2195C3D1,
	SERVICE_EARN_DAILY_OBJECTIVES = 0xBFCBE6B6,
	SERVICE_EARN_DEATHMATCH_BOUNTY = 0x31D3FC9B,
	SERVICE_EARN_DEBUG = 0x762D6BF6,
	SERVICE_EARN_DOOMSDAY_FINALE_BONUS = 0xBA16F44B,
	SERVICE_EARN_FROM_DESTROYING_CONTRABAND = 0x328CD5AA,
	SERVICE_EARN_FROM_VEHICLE_EXPORT = 0xEE884170,
	SERVICE_EARN_GANGATTACK_PICKUP = 0x506A6AF5,
	SERVICE_EARN_GANGOPS_AWARD_FIRST_TIME_XM_BASE = 0xC5ED889C,
	SERVICE_EARN_GANGOPS_AWARD_FIRST_TIME_XM_SILO = 0xB99C11F6,
	SERVICE_EARN_GANGOPS_AWARD_FIRST_TIME_XM_SUBMARINE = 0xFFC0D962,
	SERVICE_EARN_GANGOPS_AWARD_LOYALTY_AWARD_2 = 0xFF3F6FB2,
	SERVICE_EARN_GANGOPS_AWARD_LOYALTY_AWARD_3 = 0xED74CC1D,
	SERVICE_EARN_GANGOPS_AWARD_LOYALTY_AWARD_4 = 0x33E1D8F6,
	SERVICE_EARN_GANGOPS_AWARD_MASTERMIND_2 = 0x370A42A5,
	SERVICE_EARN_GANGOPS_AWARD_MASTERMIND_3 = 0xED97AFC1,
	SERVICE_EARN_GANGOPS_AWARD_MASTERMIND_4 = 0x23F59C7C,
	SERVICE_EARN_GANGOPS_AWARD_ORDER = 0x32537662,
	SERVICE_EARN_GANGOPS_AWARD_SUPPORTING = 0x8DACDD38,
	SERVICE_EARN_GANGOPS_ELITE_XM_BASE = 0x7353182D,
	SERVICE_EARN_GANGOPS_ELITE_XM_SILO = 0x7D1FD84C,
	SERVICE_EARN_GANGOPS_ELITE_XM_SUBMARINE = 0x6E63A5AC,
	SERVICE_EARN_GANGOPS_FINALE = 0x46521174,
	SERVICE_EARN_GANGOPS_PREP_PARTICIPATION = 0x53E15D9D,
	SERVICE_EARN_GANGOPS_RIVAL_DELIVERY = 0x7462F9E7,
	SERVICE_EARN_GANGOPS_SETUP = 0xA1DC5A42,
	SERVICE_EARN_GANGOPS_SETUP_FAIL = 0xFE5D3D39,
	SERVICE_EARN_GANGOPS_WAGES = 0xCBC91B24,
	SERVICE_EARN_GANGOPS_WAGES_BONUS = 0xD4E9820B,
	SERVICE_EARN_GOON = 0x21ECDA63,
	SERVICE_EARN_HOLDUPS = 0x676706D3,
	SERVICE_EARN_IMPORT_EXPORT = 0x381AE70B,
	SERVICE_EARN_INITIAL_CASH = 0x666D4B21,
	SERVICE_EARN_JBONUS = 0x631FCDF7,
	SERVICE_EARN_JOBS = 0xC2C5E339,
	SERVICE_EARN_JOBSHARE_CASH = 0x89AD02CE,
	SERVICE_EARN_JOB_BONUS = 0xA174F633,
	SERVICE_EARN_JOB_BONUS_CRIMINAL_MASTERMIND = 0x3EBB7442,
	SERVICE_EARN_JOB_BONUS_FIRST_TIME_BONUS = 0xB6D37A76,
	SERVICE_EARN_JOB_BONUS_HEIST_AWARD = 0x8107BB89,
	SERVICE_EARN_LESTER_TARGET_KILL = 0xEAFF75BD,
	SERVICE_EARN_LOTTERY = 0x628502B3,
	SERVICE_EARN_NOT_BADSPORT = 0xBCD304B8,
	SERVICE_EARN_PERSONAL_VEHICLE = 0x016B1CDE,
	SERVICE_EARN_PICKUP = 0xFE249573,
	SERVICE_EARN_PREMIUM_JOB = 0xFD2A7DE7,
	SERVICE_EARN_PROPERTY_SALES = 0xB77DD8B4, //only 600,000 per second and a max of 1 billion before requires a short cooldown
	SERVICE_EARN_RDR_BONUS_ALL_SLOTS = 0x82120337,
	SERVICE_EARN_REFUNDAMMODROP = 0xD8630BC3,
	SERVICE_EARN_REFUND_BACKUP_FAMILIES = 0x5841CC24,
	SERVICE_EARN_REFUND_BACKUP_LOST = 0x29358006,
	SERVICE_EARN_REFUND_BACKUP_VAGOS = 0x4CBAC3AA,
	SERVICE_EARN_REFUND_BOAT_PICKUP = 0x267CBC1B,
	SERVICE_EARN_REFUND_BUY_CARDROPOFF = 0xF6C6F8D3,
	SERVICE_EARN_REFUND_CHALLENGE = 0x2AD8ED30,
	SERVICE_EARN_REFUND_CLEAR_WANTED = 0x2DC5587F,
	SERVICE_EARN_REFUND_HEAD_2_HEAD = 0x8A91E076,
	SERVICE_EARN_REFUND_HELI_PICKUP = 0xAEC77375,
	SERVICE_EARN_REFUND_HIRE_MERCENARY = 0x2183C4D7,
	SERVICE_EARN_REFUND_HIRE_MUGGER = 0x5A26EAEF,
	SERVICE_EARN_REFUND_LOTTERY = 0x3530C574,
	SERVICE_EARN_REFUND_ORBITAL_AUTO = 0x0CD9EBA6, //only 500,000 per 2 seconds and a max of 5 per 2 minutes
	SERVICE_EARN_REFUND_ORBITAL_MANUAL = 0x6F225978,
	SERVICE_EARN_REFUND_SHARE_LAST_JOB = 0x8B70731D,
	SERVICE_EARN_ROCKSTAR = 0x129A5B6E,
	SERVICE_EARN_SALVAGE_CHECKPOINT_COLLECTION = 0x23C04B23,
	SERVICE_EARN_SMUGGLER_AGENCY = 0x1B9AFE05,
	SERVICE_EARN_VEHICLE_SALES = 0xFD389995,
	SERVICE_EARN_WAGE_PAYMENT = 0xF9F62A7C,
	SERVICE_EARN_WAGE_PAYMENT_BONUS = 0x5C66709A,
	SERVICE_SPEND_AIRSTRIKE = 0x5A58E3BD,
	SERVICE_SPEND_AMMO_DROP = 0x45F48C05,
	SERVICE_SPEND_ARREST_BAIL = 0x108CD6EE,
	SERVICE_SPEND_BACKUP_GANG = 0xCA5E1B40,
	SERVICE_SPEND_BACKUP_HELI = 0xD86D0371,
	SERVICE_SPEND_BANK_INTEREST = 0xB62639D4,
	SERVICE_SPEND_BA_ENFORCER_ARMOUR = 0x3A732240,
	SERVICE_SPEND_BA_SARGE_AMMO = 0xABCC04E3,
	SERVICE_SPEND_BA_SARGE_MOLOTOV = 0x24D87C9E,
	SERVICE_SPEND_BA_VP_BOUNTY = 0x6F6E2AEA,
	SERVICE_SPEND_BA_VP_BULLSHARK = 0xEBECC7F6,
	SERVICE_SPEND_BETTING = 0x6597C63C,
	SERVICE_SPEND_BOAT_PICKUP = 0x48090EBA,
	SERVICE_SPEND_BOSS_BUY_IN = 0xD8825569,
	SERVICE_SPEND_BOUNTY = 0xDB72FD6E,
	SERVICE_SPEND_BOUNTY_DM = 0xFA3E19A3,
	SERVICE_SPEND_BULL_SHARK = 0xD80064A4,
	SERVICE_SPEND_BUSINESS = 0x10077806,
	SERVICE_SPEND_CALL_PLAYER = 0x62A4B6CC,
	SERVICE_SPEND_CARWASH = 0x467E2916,
	SERVICE_SPEND_CAR_IMPOUND = 0x11611C06,
	SERVICE_SPEND_CAR_REPAIR = 0x8180486D,
	SERVICE_SPEND_CASH_DROP = 0x79D2BE32,
	SERVICE_SPEND_CASH_DROP_HOLDUP = 0x3CF098E4,
	SERVICE_SPEND_CASH_GIFT = 0xF2BEFF3E,
	SERVICE_SPEND_CASH_SHARED = 0xB3E76D2C,
	SERVICE_SPEND_CHALLENGE_WAGER = 0x2A6B291E,
	SERVICE_SPEND_CINEMA = 0xC571DB3D,
	SERVICE_SPEND_COPS_TURN_EYE = 0xE7BA9A2C,
	SERVICE_SPEND_EMPLOY_ASSASSINS = 0xC88FBB63,
	SERVICE_SPEND_EXEC_UTILITY_BILLS = 0x2D80114E,
	SERVICE_SPEND_FAIRGROUND = 0x61F840EB,
	SERVICE_SPEND_GANGOPS_CANNON = 0xAB4EA4F8,
	SERVICE_SPEND_GANGOPS_REPAIR_COST = 0x798D498F,
	SERVICE_SPEND_GANGOPS_SKIP_MISSION = 0x98AE71E5,
	SERVICE_SPEND_GANGOPS_START_STRAND = 0x8F2EC53A,
	SERVICE_SPEND_GANGOPS_TRIP_SKIP = 0xA3DDECA8,
	SERVICE_SPEND_HEALTHCARE = 0xE13B1F5A,
	SERVICE_SPEND_HELI_PICKUP = 0xD30E80F5,
	SERVICE_SPEND_HIRE_MERCENARY = 0x8F9E64E9,
	SERVICE_SPEND_HIRE_MUGGER = 0x7323DAB3,
	SERVICE_SPEND_IMPORT_EXPORT_REPAIR = 0xF7E7A848,
	SERVICE_SPEND_IMPROMPTU_RACE_FEE = 0x5D40F1F0,
	SERVICE_SPEND_JUKEBOX = 0x75CD3B70,
	SERVICE_SPEND_LOCATE_VEHICLE = 0x3F79E8B3,
	SERVICE_SPEND_LOSE_WANTED_LEVEL = 0xF54343EF,
	SERVICE_SPEND_LOTTERY = 0x847B5E8A,
	SERVICE_SPEND_MATCH_ENTRY_FEE = 0x73AF3590,
	SERVICE_SPEND_MECHANIC_WAGE = 0x9DEFCB5B,
	SERVICE_SPEND_MOVE_YACHT = 0x25A6481F,
	SERVICE_SPEND_OFF_THE_RADAR = 0x7F096F7D,
	SERVICE_SPEND_ORBITAL_AUTO = 0xBDE2A7A2,
	SERVICE_SPEND_ORBITAL_MANUAL = 0x3BE27CE6,
	SERVICE_SPEND_ORDER_BODYGUARD_VEHICLE = 0x27A4C3FB,
	SERVICE_SPEND_ORDER_WAREHOUSE_VEHICLE = 0xB0AE4A42,
	SERVICE_SPEND_OTHER_PLAYER_HEALTHCARE = 0x3DC70F44,
	SERVICE_SPEND_PASSIVE = 0x601646D2,
	SERVICE_SPEND_PAY_BOSS = 0x7A31F111,
	SERVICE_SPEND_PAY_GOON = 0x978B277B,
	SERVICE_SPEND_PA_SERVICE_DANCER = 0x810E1BBE,
	SERVICE_SPEND_PA_SERVICE_HELI = 0x3DB5C654,
	SERVICE_SPEND_PA_SERVICE_HELI_PICKUP = 0x73BA02A6,
	SERVICE_SPEND_PA_SERVICE_IMPOUND = 0x046F00FE,
	SERVICE_SPEND_PA_SERVICE_SNACK = 0xB3796027,
	SERVICE_SPEND_PA_SERVICE_VEHICLE = 0x30D378F8,
	SERVICE_SPEND_PEGASUS_DELIVERY = 0x10E398B4,
	SERVICE_SPEND_PERSONAL_ASSISTANT = 0x6E53C312,
	SERVICE_SPEND_PERSONAL_VEHICLE_DROPOFF = 0x15DAFB97,
	SERVICE_SPEND_PLAYER_APPEARANCE = 0x29EDC819,
	SERVICE_SPEND_PROSTITUTES = 0xAEF994E9,
	SERVICE_SPEND_RACE_VEHICLE_RENTAL = 0xAD32107E,
	SERVICE_SPEND_RENAME_ORGANIZATION = 0x25CFCEFF,
	SERVICE_SPEND_REQUEST_HEIST = 0xE1286116,
	SERVICE_SPEND_REQUEST_JOB = 0x741DADD0,
	SERVICE_SPEND_REVEAL_PLAYERS = 0x421452FF,
	SERVICE_SPEND_ROBBED_BY_MUGGER = 0x6DA50854,
	SERVICE_SPEND_STRIP_CLUB = 0x1B14F96B,
	SERVICE_SPEND_STYLIST_FEE = 0xAB5042C6,
	SERVICE_SPEND_TAXI = 0x92AEAB9C,
	SERVICE_SPEND_TELESCOPE = 0x26C85CA3,
	SERVICE_SPEND_UTILITY_BILLS = 0xDD16A585,
	SERVICE_SPEND_VEHICLE_EXPORT_MODS = 0x1A108B80,
	SERVICE_SPEND_VEHICLE_INSURANCE = 0xCBBC5D1E,
	SERVICE_SPEND_VEHICLE_INSURANCE_PREMIUM = 0x040E0F34,
	SERVICE_SPEND_WAGER = 0x2C41A631,
	TEST_1 = 0x408A6C26,
	TEST_2 = 0xD7858229
};

enum TransactionCategory {
	CATEGORY_SERVICE_WITH_THRESHOLD = 0x57DE404E,
	CATEGORY_SERVICE_UNLOCKED = 0x92257108,
	CATEGORY_SERVICE_WITH_LIMIT = 0xBC5B83BA,
	CATEGORY_SERVICE_ANTI_CHEAT = 0xAE04310C // sophisticated as fuck
};

enum TransactionActionType {
	ACTION_TYPE_SERVICE_SPEND = 0x2005D9A9,
	ACTION_TYPE_SERVICE_EARN = 0x562592BB,
};

enum TransactionTarget {
	TARGET_CASH = 1,
	TARGET_BANK = 2,
	TARGET_CASH_THEN_BANK = 8, // iirc
};

enum TransactionType {
	TYPE_DEFAULT = 0xBC537E0D // idk. that one is used for transactions from any script tho
};

class CNetShopTransaction {
public:
	char pad_0000[8]; //0x0000
	uint32_t TransactionId; //0x0008
	int32_t TypeHash; //0x000C
	char pad_0010[8]; //0x0010
	int32_t CategoryHash; //0x0018
	char pad_001C[8]; //0x001C
	int32_t ActionTypeHash; //0x0024
	uint32_t Target; //0x0028
	char pad_002C[180]; //0x002C
	int32_t ServiceHash; //0x00E0
	char pad_00E4[4]; //0x00E4
	uint64_t Amount; //0x00E8
	uint32_t Multiplier; //0x00F0
}; //Size: 0x0678

class NetshopQueue {
public:
	char pad_0000[32]; //0x0000
	class RageNode<CNetShopTransaction>* First; //0x0020
	class RageNode<CNetShopTransaction>* Last; //0x0028
	char pad_0030[9]; //0x0030
	bool IsBusy1; //0x0039
	char pad_003A[14]; //0x003A
	bool IsBusy2; //0x0048
	char pad_0049[7]; //0x0049
	bool IsBusy3; //0x0050
}; //Size: 0x0051

class NetCatalogBaseItem {
public:
	char pad_0000[8]; //0x0000
	uint32_t Hash; //0x0008
	uint32_t CategoryHash; //0x000C
	uint32_t Price; //0x0010
}; //Size: 0x0014

template<class T>
class HashList {

	char pad_0000[88]; //0x0000
	void* m_data; //0x0058
	uint16_t m_size; //0x0060

public:

	T *getEntry(const DWORD hash) {
		if (this->m_size) {
			const auto offset = hash % this->m_size * 8;

			for (auto i = *reinterpret_cast<unsigned __int64 *>(reinterpret_cast<unsigned __int64>(this->m_data) + offset); ; i = *reinterpret_cast<unsigned __int64 *>(i + 0x10)) {
				if (!i) {
					return nullptr;
				}

				if (*reinterpret_cast<DWORD *>(i) == hash) {
					return *reinterpret_cast<T **>(i + 8);
				}
			}
		}
	}
};

class NetCatalog {
public:
	char pad_0000[88]; //0x0000
	void* CatalogItems; //0x0058
	uint16_t CatalogSize; //0x0060
	char pad_0062[26]; //0x0062
	uint32_t CatalogVersion; //0x007C

	template<class T>
	T* getCatalogEntry(const DWORD hash) {
		if (this->CatalogSize) {
			const auto offset = hash % this->CatalogSize * 8;

			for (auto i = *reinterpret_cast<QWORD*>(reinterpret_cast<QWORD>(this->CatalogItems) + offset); ; i = *reinterpret_cast<QWORD*>(i + 0x10)) {
				if (!i) {
					return nullptr;
				}

				if (*reinterpret_cast<DWORD*>(i) == hash) {
					return *reinterpret_cast<T * *>(i + 8);
				}
			}
		}

		return nullptr;
	}

	int getServiceThreshold(const DWORD service) {
		const auto item = this->getCatalogEntry<NetCatalogBaseItem>(service);

		return item ? item->Price : -1;
	}
}; //Size: 0x0062

namespace ReClass {
	CWorld* GetWorld();
	CWorldd* GetWorldd();
	CNetworkPlayerManager* GetNetworkPlayerManager();
}

enum eExplosionHashes {
	EXP_TAG_GRENADE = 0x8A81EE87,
	EXP_TAG_GRENADELAUNCHER = 0x70768AE2,
	EXP_TAG_STICKYBOMB = 0x00776EE2,
	EXP_TAG_MOLOTOV = 0xF06FF2EA,
	EXP_TAG_ROCKET = 0x6E26E617,
	EXP_TAG_TANKSHELL = 0xF7F926C6,
	EXP_TAG_HI_OCTANE = 0x06A02001,
	EXP_TAG_CAR = 0x873EFA90,
	EXP_TAG_PLANE = 0x1EFAECAF,
	EXP_TAG_PETROL_PUMP = 0xF9C8CA18,
	EXP_TAG_BIKE = 0xB0982FC3,
	EXP_TAG_DIR_STEAM = 0xA1DCCBA6,
	EXP_TAG_DIR_FLAME = 0x68AB5E33,
	EXP_TAG_DIR_WATER_HYDRANT = 0x1FD48F6A,
	EXP_TAG_DIR_GAS_CANISTER = 0xD26A85F8,
	EXP_TAG_BOAT = 0x78C99422,
	EXP_TAG_SHIP_DESTROY = 0xA30CE475,
	EXP_TAG_TRUCK = 0x38C51930,
	EXP_TAG_BULLET = 0xC10B20E5,
	EXP_TAG_SMOKEGRENADELAUNCHER = 0x8E6F4BED,
	EXP_TAG_SMOKEGRENADE = 0xF910656E,
	EXP_TAG_BZGAS = 0x69BBC23A,
	EXP_TAG_FLARE = 0x5E2703F4,
	EXP_TAG_GAS_CANISTER = 0xC946D0BE,
	EXP_TAG_EXTINGUISHER = 0x9D23C3A1,
	EXP_TAG_PROGRAMMABLEAR = 0x407BB75E,
	EXP_TAG_TRAIN = 0x6DC5550C,
	EXP_TAG_BARREL = 0x41218EB0,
	EXP_TAG_PROPANE = 0x6DF18414,
	EXP_TAG_BLIMP = 0x9FE41D96,
	EXP_TAG_DIR_FLAME_EXPLODE = 0xFFE56FF4,
	EXP_TAG_TANKER = 0x2FA09A72,
	EXP_TAG_PLANE_ROCKET = 0x932F3E8F,
	EXP_TAG_VEHICLE_BULLET = 0x64DB13C9,
	EXP_TAG_GAS_TANK = 0xC717B00D,
	EXP_TAG_PROXMINE = 0x5AF62252,
	EXP_TAG_SNOWBALL = 0x4C4099F,
	EXP_TAG_AIR_DEFENCE = 0xD1653345,
	EXP_TAG_PIPEBOMB = 0x8123C100,
	EXP_TAG_VEHICLEMINE = 0x2E172C48,
	EXP_TAG_EXPLOSIVEAMMO = 0x958EE7C8,
	EXP_TAG_APCSHELL = 0x62412BA9,
	EXP_TAG_VALKYRIE_CANNON = 0xB780A2D9,
};

enum eExplosionFXHashes {
	EXP_VFXTAG_GRENADE = 0x8CBD7381,
	EXP_VFXTAG_STICKYBOMB = 0x6818372E,
	EXP_VFXTAG_MOLOTOV = 0x289C84AB,
	EXP_VFXTAG_ROCKET = 0xC18A7083,
	EXP_VFXTAG_PETROL_PUMP = 0x5C685140,
	EXP_VFXTAG_VEHICLE = 0x1FDD8CC7,
	EXP_VFXTAG_BIKE = 0x2E89B6C6,
	EXP_VFXTAG_DIR_STEAM = 0xB096860,
	EXP_VFXTAG_DIR_FLAME = 0x61BEF304,
	EXP_VFXTAG_DIR_WATER_HYDRANT = 0xC9E6266C,
	EXP_VFXTAG_DIR_GAS_CANISTER = 0xDCD1237B,
	EXP_VFXTAG_TRUCK = 0x272C2A1C,
	EXP_VFXTAG_BULLET = 0x4A602D1B,
	EXP_VFXTAG_SMOKE_GRENADE = 0x1B171B0A,
	EXP_VFXTAG_BZGAS = 0xC36F9FF4,
	EXP_VFXTAG_FBI4_TRUCK_DOORS = 0x68EC3F3E,
	EXP_VFXTAG_GAS_CANISTER = 0x531AE6D7,
	EXP_VFXTAG_EXTINGUISHER = 0x3C212E68,
	EXP_VFXTAG_TRAIN = 0x7DF5D791,
	EXP_VFXTAG_BARREL = 0x26A49BC,
	EXP_VFXTAG_PROPANE = 0x2A8D8114,
	EXP_VFXTAG_BLIMP = 0xBA683EF5,
	EXP_VFXTAG_FLARE = 0x4DFE55EF,
	EXP_VFXTAG_PLANE_ROCKET = 0x549AE743,
	EXP_VFXTAG_TANKER = 0x6136E279,
	EXP_VFXTAG_PLANE = 0x174DDF67,
	EXP_VFXTAG_BOAT = 0x9AE5CE85,
	EXP_VFXTAG_TANKSHELL = 0xC6109DA9,
	EXP_VFXTAG_TREV3_TRAILER = 0x567CAF1C,
	EXP_VFXTAG_BLIMP2 = 0x9077376B,
	EXP_VFXTAG_BIRDCRAP = 0x8B716982,
	EXP_VFXTAG_FIREWORK = 0x1499FEF9,
	EXP_VFXTAG_SNOWBALL = 0x4B0245BA,
	EXP_VFXTAG_AIR_DEFENCE = 0x3C84F30B,
	EXP_VFXTAG_PIPEBOMB = 0x2E3BC2D6,
	EXP_VFXTAG_BOMB_CLUSTER = 0x7007891E,
	EXP_VFXTAG_BOMB_GAS = 0xAD0A7E5D,
	EXP_VFXTAG_BOMB_INCENDIARY = 0x62F8744D,
	EXP_VFXTAG_BOMB_STANDARD = 0x30A5254A,
	EXP_VFXTAG_TORPEDO_UNDERWATER = 0x8D16EE2E,
	EXP_VFXTAG_MINE_UNDERWATER = 0x4F7CD2DC
};







class MemoryHandle
{
public:
	constexpr MemoryHandle(void* p = nullptr) :
		m_Ptr(p)
	{}
	/*constexpr explicit MemoryHandle(std::uintptr_t p) :*/
	explicit MemoryHandle(std::uintptr_t p) :
		m_Ptr(reinterpret_cast<void*>(p))
	{}

	template <typename T>
	constexpr std::enable_if_t<std::is_pointer_v<T>, T> As()
	{
		return static_cast<T>(m_Ptr);
	}

	template <typename T>
	constexpr std::enable_if_t<std::is_lvalue_reference_v<T>, T> As()
	{
		return *static_cast<std::add_pointer_t<std::remove_reference_t<T>>>(m_Ptr);
	}

	template <typename T>
	constexpr std::enable_if_t<std::is_same_v<T, std::uintptr_t>, T> As()
	{
		return reinterpret_cast<T>(m_Ptr);
	}

	template <typename T>
	constexpr MemoryHandle Add(T offset)
	{
		return MemoryHandle(As<std::uintptr_t>() + offset);
	}

	template <typename T>
	constexpr MemoryHandle Sub(T offset)
	{
		return MemoryHandle(As<std::uintptr_t>() - offset);
	}

	constexpr MemoryHandle Rip()
	{
		if (!m_Ptr)
			return nullptr;
		return Add(As<std::int32_t&>()).Add(4U);
	}

	constexpr explicit operator bool() noexcept
	{
		return m_Ptr;
	}
protected:
	void* m_Ptr;
};

class MemoryRegion
{
public:
	constexpr explicit MemoryRegion(MemoryHandle base, std::size_t size) :
		m_Base(base),
		m_Size(size)
	{}

	constexpr MemoryHandle Base()
	{
		return m_Base;
	}

	constexpr MemoryHandle End()
	{
		return m_Base.Add(m_Size);
	}

	constexpr std::size_t Size()
	{
		return m_Size;
	}

	constexpr bool Contains(MemoryHandle p)
	{
		if (p.As<std::uintptr_t>() < m_Base.As<std::uintptr_t>())
			return false;
		if (p.As<std::uintptr_t>() > m_Base.Add(m_Size).As<std::uintptr_t>())
			return false;

		return true;
	}
protected:
	MemoryHandle m_Base;
	std::size_t m_Size;
};

class Module : public MemoryRegion
{
public:
	explicit Module(std::nullptr_t) :
		Module(static_cast<char*>(nullptr))
	{}

	explicit Module(const char* name) :
		Module(GetModuleHandleA(name))
	{
	}

	Module(HMODULE hmod) :
		MemoryRegion(hmod, 0)
	{
		auto dosHeader = m_Base.As<IMAGE_DOS_HEADER*>();
		auto ntHeader = m_Base.Add(dosHeader->e_lfanew).As<IMAGE_NT_HEADERS64*>();
		m_Size = ntHeader->OptionalHeader.SizeOfImage;
	}

	template <typename TReturn, typename TOffset>
	TReturn GetRVA(TOffset rva)
	{
		return m_Base.Add(rva).As<TReturn>();
	}

	IMAGE_DOS_HEADER* GetDosHeaders()
	{
		return m_Base.As<IMAGE_DOS_HEADER*>();
	}

	IMAGE_NT_HEADERS64* GetNtHeaders()
	{
		return m_Base.Add(m_Base.As<IMAGE_DOS_HEADER*>()->e_lfanew).As<IMAGE_NT_HEADERS64*>();
	}
};

class Signature
{
public:
	struct Element
	{
		std::uint8_t m_Data{};
		bool m_Wildcard{};
	};

	/*explicit Signature(const char* pattern)
	{*/
	explicit Signature(const char* pattern, const char* namepattern)
	{
		std::cout << namepattern << std::endl;
		LOG_DEVDEBUG(namepattern);
		auto toUpper = [](char c) -> char
		{
			return c >= 'a' && c <= 'z' ? static_cast<char>(c + ('A' - 'a')) : static_cast<char>(c);
		};

		auto isHex = [&](char c) -> bool
		{
			switch (toUpper(c))
			{
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
				return true;
			default:
				return false;
			}
		};

		do
		{
			if (*pattern == ' ')
				continue;
			if (*pattern == '?')
			{
				m_Elements.push_back(Element{ {}, true });
				continue;
			}

			if (*(pattern + 1) && isHex(*pattern) && isHex(*(pattern + 1)))
			{
				char str[3] = { *pattern, *(pattern + 1), '\0' };
				auto data = std::strtol(str, nullptr, 16);

				m_Elements.push_back(Element{ static_cast<std::uint8_t>(data), false });
			}
		} while (*(pattern++));
	}

	MemoryHandle Scan(MemoryRegion region = Module(nullptr))
	{
		auto compareMemory = [](std::uint8_t* data, Element* elem, std::size_t num) -> bool
		{
			for (std::size_t i = 0; i < num; ++i)
			{
				if (!elem[i].m_Wildcard)
					if (data[i] != elem[i].m_Data)
						return false;
			}

			return true;
		};

		for (std::uintptr_t i = region.Base().As<std::uintptr_t>(), end = region.End().As<std::uintptr_t>(); i != end; ++i)
		{
			if (compareMemory(reinterpret_cast<std::uint8_t*>(i), m_Elements.data(), m_Elements.size()))
			{
				return MemoryHandle(i);
			}
		}

		return {};
	}
private:
	std::vector<Element> m_Elements;
};

namespace rage
{
	template <typename T>
	class ObfVar
	{
	private:
		T m_unk1;
		T m_unk2;
		T m_unk3;
		T m_unk4;

	public:
		T getData()
		{
			auto v105 = m_unk4;
			auto v28 = m_unk1 & v105;
			auto v94 = m_unk2 & ~v105;
			return v28 | v94;
		}

		operator T ()
		{
			return getData();
		}

#if _WIN32
		void setData(T val)
		{
			auto seed = time(nullptr);
			m_unk3 = seed;
			seed = time(nullptr);
			m_unk4 = seed;

			auto v48 = val & ~seed;
			m_unk1 = seed & val;
			m_unk2 = v48;
		}

		void operator =(T val)
		{
			setData(val);
		}
#endif
	};

	using Obf16 = ObfVar<unsigned short>;
	using Obf32 = ObfVar<unsigned int>;
}
class NetworkGameConfig
{
public:
	char pad_0000[48]; //0x0000
	uint32_t m_public_slots; //0x0030
	uint32_t m_private_slots; //0x0034
	char pad_0038[272]; //0x0038
}; //Size: 0x0148
namespace rage
{
	class rlMetric
	{
	public:
		virtual ~rlMetric() = default;

		virtual int _0x08() { return 0; }; // returns a constant integer

		virtual int _0x10() { return 0; }; // returns a constant integer

		virtual int _0x18() { return 0; };

		virtual const char* get_name() { return ""; };

		virtual bool serialize(void* serializer) { return false; };

		virtual int get_size() { return 0; };

		virtual joaat_t2 get_name_hash() { return 0; };
	};
};
class MetricSessionMigrated : public rage::rlMetric
{
public:
	char pad_0008[828]; //0x0008
	uint32_t m_num_players; //0x0344
}; //Size: 0x0348
class NetworkGameFilterMatchmakingComponent
{
public:
	// do not use for actual network filters, this will break things
	inline void SetParameter(const char* name, int index, int value)
	{
		std::strcpy(m_param_names[index], name);
		m_param_mappings[index] = index;
		m_param_values[index] = value;
		m_enabled_params_bitset |= (1 << index);

		if (m_num_parameters <= (uint32_t)index)
			m_num_parameters++;
	}

	uint32_t m_filter_type; //0x0000
	char m_filter_name[24]; //0x0004
	uint32_t m_num_parameters; //0x001C
	uint16_t m_game_mode; //0x0020
	uint16_t m_session_type; //0x0022
	uint32_t m_param_unk[8]; //0x0024
	char m_param_names[8][24]; //0x0044
	char pad_0104[4]; //0x0104
	uint32_t m_param_mappings[8]; //0x0108
	char pad_0128[352]; //0x0128
	uint32_t m_param_values[8]; //0x0288
	char pad_02A8[96]; //0x02A8
	uint32_t m_enabled_params_bitset; //0x0308
	char pad_030C[8]; //0x030C
}; //Size: 0x0314
class NetworkGameFilter
{
public:
	virtual ~NetworkGameFilter() = default;
	virtual void Reset() {};

	uint32_t m_build_type; //0x0008
	uint32_t m_discriminator; //0x000C
	uint32_t m_discriminator_mapping; //0x0010
	uint32_t m_region_mapping; //0x0014
	uint32_t m_language_mapping; //0x0018
	uint32_t m_mm_group_1_mapping; //0x001C
	uint32_t m_mm_group_2_mapping; //0x0020
	uint32_t m_activity_type_mapping; //0x0024
	uint32_t m_activity_id_mapping; //0x0028
	uint32_t m_activity_players_mapping; //0x002C
	class NetworkGameFilterMatchmakingComponent m_matchmaking_component; //0x0030
}; //Size: 0x0344
class SessionInfoBackup
{
public:
	class rage::rlSessionInfo m_session_info;
	uint32_t m_unk; //0x0070
	char pad_0074[4]; //0x0074
	uint32_t m_flags; //0x0078
}; //Size: 0x007C


namespace rage
{
	class netConnectionManager;
	class sysMemAllocator;

	class snPlayer
	{
	public:
		uint64_t m_msg_id; //0x0000
		class rage::rlGamerInfo m_player_data; //0x0008
		char pad_00F8[8]; //0x00F8
	}; //Size: 0x00A0
	//     static_assert(sizeof(rage::snPlayer) == 0x100);

	class snPeer
	{
	public:
		class rage::rlGamerInfo m_peer_data; //0x0000
		char pad_0098[40]; //0x0098
	}; //Size: 0x00C0
	//     static_assert(sizeof(rage::snPeer) == 0x120);

	class rlRemoteGamer
	{
	public:
		rage::rlGamerHandle m_handle;
		char pad_0010[4]; //0x0010
		uint32_t m_timeout_time; //0x0014
		uint32_t m_time_unk; //0x0018
		char pad_001C[4]; //0x001C
	}; //Size: 0x0020
	//     static_assert(sizeof(rage::rlRemoteGamer) == 0x20);


	//class rlSession
	//{
	//public:
	//	char pad_0008[264]; //0x0008
	//	class rage::rlSessionInfo m_session_info; //0x0110
	//	char pad_01E0[288]; //0x01E0
	//	uint64_t m_session_id; //0x0300
	//	char pad_0308[1136]; //0x0308

	//	virtual ~rlSession() = default;
	//}; //Size: 0x0778
	//     static_assert(sizeof(rage::rlSession) == 0x778);
	class rlSession
	{
	public:
		char pad_0008[248]; //0x0008
		class rage::rlSessionInfo m_session_info; //0x0100
		char pad_01D0[296]; //0x01D0
		uint64_t m_session_id; //0x02F8
		char pad_0300[1136]; //0x0300

		virtual ~rlSession() = default;
	}; //Size: 0x0770

	class rlSessionDetail
	{
	public:
		class rlGamerInfoBase m_base_gamer_info;
		char pad_0060[8]; //0x0060
		class rage::rlSessionInfo m_session_info; //0x0068
		char pad_00D8[14]; //0x00D8
		uint16_t m_session_type; //0x00E6
		char pad_00E8[324]; //0x00E8
		uint32_t m_player_count; //0x022C
		uint32_t m_unk_player_count; //0x0230
		char pad_0234[2]; //0x0234
		int16_t m_unk_pos_x; //0x0236
		int16_t m_unk_pos_y; //0x0238
		int16_t m_unk_pos_z; //0x023A
		uint8_t m_matchmaking_property_ids[32]; //0x023C
		char pad_025C[2]; //0x025C
		uint16_t m_rank; //0x025E
		char pad_0260[1]; //0x0260
		uint8_t m_mental_state; //0x0261
		char pad_0262[21]; //0x0262
		uint8_t m_population_density; //0x0277
		char pad_0278[320]; //0x0278
	}; //Size: 0x03CA
	//     static_assert(sizeof(rlSessionDetail) == 0x478);


	class rlMatchmakingFindResult
	{
	public:
		class rage::rlSessionDetail m_result_session_details[15]; //0x0000
		char pad_37C8[168]; //0x37C8
	}; //Size: 0x3870
	//     static_assert(sizeof(rage::rlMatchmakingFindResult) == 0x43B0);

	class netGamePlayerData
	{
	public:
		class rlGamerHandle m_handle;
		bool m_is_activity_spectator; //0x0010
		char pad_0011[7]; //0x0011
		uint64_t m_crew_id; //0x0018
		uint16_t m_rank; //0x0020
		uint16_t m_debug_unk; //0x0022
		char pad_0024[4]; //0x0024
		uint32_t m_nat_type; //0x0028
		bool m_is_rockstar_dev; //0x002C
		char pad_002D[3]; //0x002D
	}; //Size: 0x0030
	//     static_assert(sizeof(rage::netGamePlayerData) == 0x30);


	//class snSession
	//{
	//public:
	//	rage::sysMemAllocator* m_memory_allocator; //0x0000
	//	char pad_0008[64]; //0x0008
	//	rage::netConnectionManager* m_net_connection_mgr; //0x0048
	//	char pad_0050[48]; //0x0050
	//	class rage::rlSession m_rline_session; //0x0080
	//	class rage::snPlayer m_local_player; //0x0938
	//	uint64_t m_host_token; //0x09D8
	//	char pad_09E0[144]; //0x09E0
	//	class rage::snPeer m_peer_storage[32]; //0x0A70
	//	char pad_2270[24]; //0x2270
	//	class rage::snPeer* m_peers[32]; //0x2288
	//	uint32_t m_peer_count; //0x2388
	//	char pad_238C[4]; //0x238C
	//	class rage::snPlayer m_player_storage[32]; //0x2390
	//	char pad_3790[24]; //0x3790
	//	class rage::snPlayer* m_players[32]; //0x37A8
	//	uint32_t m_player_count; //0x38A8
	//	char pad_38AC[4]; //0x38AC
	//	class rage::rlRemoteGamer m_remote_gamers[32]; //0x38B0
	//	uint32_t m_num_remote_gamers; //0x3CB0
	//	bool m_player_joining; //0x3CB4
	//	char pad_3CB5[107]; //0x3CB5
	//	uint32_t m_connection_identifier; //0x3D20
	//	char pad_3D24[8]; //0x3D24
	//	char m_token_key[64]; //0x3D2C
	//	char m_id_key[64]; //0x3D6C
	//	char m_info_key[64]; //0x3DAC
	//	char m_host_key[64]; //0x3DEC
	//	char m_join_key[64]; //0x3E2C
	//	char pad_3E6C[4]; //0x3E6C

	//	inline bool is_host()
	//	{
	//		return m_local_player.m_player_data.m_host_token == m_host_token;
	//	}

	//	inline snPlayer* get_player_by_token(uint64_t token)
	//	{
	//		for (std::uint32_t i = 0; i < m_player_count; i++)
	//		{
	//			if (m_players[i]->m_player_data.m_host_token == token)
	//			{
	//				return m_players[i];
	//			}
	//		}

	//		return nullptr;
	//	}

	//	inline snPeer* get_peer_by_rockstar_id(uint64_t rid)
	//	{
	//		for (uint32_t i = 0; i < m_peer_count; i++)
	//		{
	//			if (m_peers[i]->m_peer_data.m_gamer_handle_2.m_rockstar_id == rid)
	//			{
	//				return m_peers[i];
	//			}
	//		}

	//		return nullptr;
	//	}

	//}; //Size: 0x3E70
	//     static_assert(sizeof(rage::snSession) == 0x5590);

	class snSession
	{
	public:
		uint64_t m_memory_allocator; //0x0000
		char pad_0008[64]; //0x0008
		rage::netConnectionManager* m_net_connection_mgr; //0x0048
		char pad_0050[48]; //0x0050
		class rage::rlSession m_rline_session; //0x0080
		class rage::snPlayer m_local_player; //0x07F0
		uint64_t m_host_token; //0x08F0
		char pad_08F8[144]; //0x08F8
		class rage::snPeer m_peer_storage[32]; //0x0988
		char pad_2C88[24]; //0x2C88
		class rage::snPeer* m_peers[32]; //0x2CA0
		uint32_t m_peer_count; //0x2DA0
		char pad_2DA4[4]; //0x2DA4
		class rage::snPlayer m_player_storage[32]; //0x2DA8
		char pad_4DA8[24]; //0x4DA8
		class rage::snPlayer* m_players[32]; //0x4DC0
		int32_t m_player_count; //0x4EC0
		char pad_4EC4[4]; //0x4EC4
		class rage::rlRemoteGamer m_remote_gamers[32]; //0x4EC8
		uint32_t m_num_remote_gamers; //0x52C8
		bool m_player_joining; //0x52CC
		char pad_52CD[107]; //0x52CD
		uint32_t m_connection_identifier; //0x5338
		char pad_533C[4]; //0x533C
		uint32_t m_profile_index; //0x5340
		char m_token_key[64]; //0x5344
		char m_id_key[64]; //0x5384
		char m_info_key[64]; //0x53C4
		char m_host_key[64]; //0x5404
		char m_join_key[64]; //0x5444
		char pad_5484[4]; //0x5484

		inline bool is_host()
		{
			return m_local_player.m_player_data.m_host_token == m_host_token;
		}

		inline snPlayer* get_player_by_token(uint64_t token)
		{
			for (std::uint32_t i = 0; i < m_player_count; i++)
			{
				if (m_players[i]->m_player_data.m_host_token == token)
				{
					return m_players[i];
				}
			}

			return nullptr;
		}

		inline snPeer* get_peer_by_rockstar_id(uint64_t rid)
		{
			for (uint32_t i = 0; i < m_peer_count; i++)
			{
				if (m_peers[i]->m_peer_data.m_gamer_handle_2.m_rockstar_id == rid)
				{
					return m_peers[i];
				}
			}

			return nullptr;
		}

	}; //Size: 0x3E70

	class snMsgRemoveGamersFromSessionCmd
	{
	public:
		uint64_t m_session_id; //0x0000
		uint64_t m_peer_ids[32]; //0x0008
		int32_t m_unk = -1; //0x0108
		uint32_t m_num_peers; //0x010C
	}; //Size: 0x0110
	//     static_assert(sizeof(rage::snMsgRemoveGamersFromSessionCmd) == 0x110);
}

class SessionSortEntry
{
public:
	class rage::rlSessionDetail* m_session_detail; //0x0000
	char pad_0008[4]; //0x0008
	float m_score; //0x000C
	char pad_0010[8]; //0x0010
}; //Size: 0x0018

class MatchmakingSessionResult
{
public:
	class rage::rlSessionDetail m_detail;
	char pad_03B8[24]; //0x03B8
}; //Size: 0x03D0
class CNetRemoteComplaint
{
public:
	uint64_t m_complainer_token; //0x0000
	uint64_t m_complainee_token; //0x0008
	uint32_t m_flags; //0x0010
	uint32_t m_time; //0x0014
}; //Size: 0x0018
//class CNetComplaintMgr
//{
//public:
//	uint64_t m_host_token; //0x0000
//	uint32_t m_host_peer_id; //0x0008
//	char pad_000C[4]; //0x000C
//	void* m_net_connection_mgr; //0x0010
//	char pad_0018[64]; //0x0018
//	uint64_t m_host_tokens_in_scope[64]; //0x0058
//	uint32_t m_num_tokens_in_scope; //0x0258
//	char pad_025C[4]; //0x025C
//	class CNetRemoteComplaint m_remote_complaints[64]; //0x0260
//	uint32_t m_num_remote_complaints; //0x0860
//	char pad_0864[4]; //0x0864
//	uint64_t m_host_tokens_complained[64]; //0x0868
//	uint32_t m_num_tokens_complained; //0x0A68
//	char pad_0A6C[520]; //0x0A6C
//	uint32_t m_connection_identifier; //0x0C74
//	uint32_t m_last_resend_time; //0x0C78
//	char pad_0C7C[4]; //0x0C7C
//	uint32_t m_time_to_resend; //0x0C80
//	uint32_t m_flags; //0x0C84
//	char pad_0C88[16]; //0x0C88
//
//	inline bool has_local_complaint(uint64_t host_token)
//	{
//		for (std::uint32_t i = 0; i < m_num_tokens_complained; i++)
//			if (m_host_tokens_complained[i] == host_token)
//				return true;
//
//		return false;
//	}
//
//	inline void raise_complaint(uint64_t host_token)
//	{
//		if (has_local_complaint(host_token))
//			return;
//
//		m_host_tokens_complained[m_num_tokens_complained++] = host_token;
//
//		// big::g_pointers->m_raise_network_complaint(this, host_token);
//	}
//
//	inline void remove_complaint(uint64_t host_token)
//	{
//		if (!has_local_complaint(host_token))
//			return;
//
//		for (std::uint32_t i = 0; i < m_num_tokens_complained; i++)
//			if (m_host_tokens_complained[i] == host_token)
//				m_host_tokens_complained[i] = m_host_tokens_complained[m_num_tokens_complained - 1];
//
//		m_num_tokens_complained--;
//	}
//
//}; //Size: 0x0C98

class CNetComplaintMgr
{
public:
	uint64_t m_host_token; //0x0000
	uint32_t m_host_peer_id; //0x0008
	char pad_000C[4]; //0x000C
	void* m_net_connection_mgr; //0x0010
	char pad_0018[64]; //0x0018
	class rage::rlGamerHandle m_handles_in_scope[64]; //0x0058
	uint32_t m_num_handles_in_scope; //0x0458
	char pad_045C[4]; //0x045C
	class CNetRemoteComplaint m_remote_complaints[64]; //0x0460
	uint32_t m_num_remote_complaints; //0x0A60
	char pad_0A64[4]; //0x0A64
	uint64_t m_host_tokens_complained[64]; //0x0A68
	uint32_t m_num_tokens_complained; //0x0C68
	char pad_0C6C[520]; //0x0C6C
	uint32_t m_connection_identifier; //0x0E74
	uint32_t m_last_resend_time; //0x0E78
	char pad_0E7C[4]; //0x0E7C
	uint32_t m_time_to_resend; //0x0E80
	uint32_t m_flags; //0x0E84
	char pad_0E88[16]; //0x0E88

	inline bool has_local_complaint(uint64_t host_token)
	{
		for (std::uint32_t i = 0; i < m_num_tokens_complained; i++)
			if (m_host_tokens_complained[i] == host_token)
				return true;

		return false;
	}

	inline void raise_complaint(uint64_t host_token)
	{
		if (has_local_complaint(host_token))
			return;

		m_host_tokens_complained[m_num_tokens_complained++] = host_token;

		// big::g_pointers->m_raise_network_complaint(this, host_token);
	}

	inline void remove_complaint(uint64_t host_token)
	{
		if (!has_local_complaint(host_token))
			return;

		for (std::uint32_t i = 0; i < m_num_tokens_complained; i++)
			if (m_host_tokens_complained[i] == host_token)
				m_host_tokens_complained[i] = m_host_tokens_complained[m_num_tokens_complained - 1];

		m_num_tokens_complained--;
	}

}; //Size: 0x0C98

//class PlayerNameMapNode
//{
//public:
//	char m_name[24]; //0x0000
//	class rage::rlGamerHandle m_handle; //0x0018
//	class PlayerNameMapNode* m_next; //0x0028
//	class PlayerNameMapNode* m_prev; //0x0030
//}; //Size: 0x0038

class PlayerNameMapNode
{
public:
	char m_name[16]; //0x0000
	class rage::rlGamerHandle m_handle; //0x0010
	class PlayerNameMapNode* m_next; //0x0020
	class PlayerNameMapNode* m_prev; //0x0028
}; //Size: 0x0030

//class JoiningPlayerNameMap
//{
//public:
//	class PlayerNameMapNode m_names[100]; //0x0000
//	char pad_15E0[40]; //0x15E0
//	uint32_t m_num_name_nodes; //0x1608
//	char pad_160C[796]; //0x160C
//}; //Size: 0x1928
class JoiningPlayerNameMap
{
public:
	class PlayerNameMapNode m_names[100]; //0x0000
	char pad_12C0[40]; //0x12C0
	uint32_t m_num_name_nodes; //0x12E8
	char pad_12EC[796]; //0x12EC
}; //Size: 0x1608

class CNetBlacklistNode
{
public:
	class rage::rlGamerHandle m_handle; //0x0000
	bool m_block_rejoin; //0x0010
	char pad_0011[3]; //0x0011
	uint32_t m_added_time; //0x0014
	class CNetBlacklistNode* m_next; //0x0018
	class CNetBlacklistNode* m_prev; //0x0020
}; //Size: 0x0028
// static_assert(sizeof(CNetBlacklistNode) == 0x28);

class CNetBlacklist
{
public:
	class CNetBlacklistNode m_nodes[16]; //0x0000
	class CNetBlacklistNode* m_head; //0x0280
	class CNetBlacklistNode* m_tail; //0x0288
	uint32_t m_free_nodes; //0x0290
	char pad_0294[4]; //0x0294
	class CNetBlacklistNode* m_start; //0x0298
	char pad_02A0[24]; //0x02A0
}; //Size: 0x02B8
class InvitedGamer
{
public:
	class rage::rlGamerHandle m_handle;
	char pad_0010[12]; //0x0010
	uint32_t m_flags; //0x001C
}; //Size: 0x0020
class InvitedGamers
{
public:
	class InvitedGamer m_invited_gamers[100]; //0x0000
	uint32_t m_num_invited_gamers; //0x0C80
	char pad_0C84[4]; //0x0C84
}; //Size: 0x0C88
class RemotePlayerData
{
public:
	class rage::netGamePlayerData m_data[32]; //0x0000
	uint32_t m_count; //0x0600
	char pad_0604[4]; //0x0604
}; //Size: 0x0608
//class Network
//{
//public:
//	rage::rlSessionInfo m_steam_unk_session; //0x0000
//	rage::Obf32 m_num_dinput8_instances; //0x0070
//	rage::Obf32 m_last_time_dinput8_checked; //0x0080
//	class rage::snSession* m_game_session_ptr; //0x0090
//	class rage::snSession* m_transition_session_ptr; //0x0098
//	char pad_00A0[24]; //0x00A0
//	class rage::snSession m_game_session; //0x00B8
//	class rage::snSession m_transition_session; //0x3F28
//	char pad_7D98[16]; //0x7D98
//	class NetworkGameConfig m_network_game_config; //0xAC48
//	class NetworkGameConfig m_network_transition_config; //0xAD90
//	bool m_session_attributes_dirty; //0xAED8
//	char pad_AED9[19]; //0xAED9
//	uint32_t m_session_visibility_flags; //0xAEEC
//	uint32_t m_transition_visibility_flags; //0xAEF0
//	char pad_AEF4[60]; //0xAEF4
//	class MetricSessionMigrated m_metric_session_migrated; //0xAF30
//	bool m_migrated_metric_enabled; //0xB278
//	char pad_B279[3]; //0xB279
//	uint32_t m_game_session_state; //0xB27C
//	class NetworkGameFilter m_network_game_filter; //0xB280
//	char pad_B5C4[33]; //0xB5C4
//	bool m_was_invited; //0xB5E5
//	char pad_B5E6[10]; //0xB5E6
//	class rage::rlSessionInfo m_unk_session_info; //0xB5F0
//	char pad_B6C0[635]; //0xB6C0
//	bool m_need_host_change; //0xB93B
//	char pad_B93C[2628]; //0xB93C
//	class rage::rlSessionDetail m_joining_session_detail; //0xC380
//	class SessionInfoBackup m_last_joined_session; //0xC7F8
//	char pad_C8D4[40]; //0xC8D4
//	uint32_t m_current_matchmaking_group; //0xC8FC
//	uint32_t m_matchmaking_group_max_players[5]; //0xC900
//	uint32_t m_num_active_matchmaking_groups; //0xC914
//	char pad_C918[8]; //0xC918
//	uint8_t m_matchmaking_property_id; //0xC920
//	uint8_t m_matchmaking_mental_state; //0xC921
//	char pad_C922[366]; //0xC922
//	class rage::rlMatchmakingFindResult m_game_session_matchmaking[3]; //0xCA90
//	char pad_195A0[40]; //0x195A0
//	class MatchmakingSessionResult m_game_matchmaking_session_results[10]; //0x195C8
//	char pad_1C368[308]; //0x1C368
//	uint32_t m_num_bosses; //0x1C49C
//	bool m_num_bosses_set; //0x1C4A0
//	char pad_1C4A1[7]; //0x1C4A1
//	class rage::rlGamerHandle m_transition_creator_handle; //0x1C4A8
//	char pad_1C4B8[12]; //0x1C4B8
//	bool m_is_waiting_async; //0x1C4C4
//	bool m_is_preferred_activity; //0x1C4C5
//	char pad_1C4C6[2]; //0x1C4C6
//	uint32_t m_in_progress_finish_time; //0x1C4C8
//	char pad_1C4CC[4]; //0x1C4CC
//	bool m_local_player_info_dirty; //0x1C4D0
//	char pad_1C4D1[495]; //0x1C4D1
//	class rage::rlGamerHandle m_inviter_handle; //0x1C6C0
//	class CNetComplaintMgr m_game_complaint_mgr; //0x1C6D0
//	class CNetComplaintMgr m_transition_complaint_mgr; //0x1D368
//	char pad_1E000[32]; //0x1E000
//	class JoiningPlayerNameMap m_unused_joining_player_name_map; //0x1E020
//	char pad_1F948[8]; //0x1F948
//	class CNetBlacklist m_blacklist; //0x1F950
//	char pad_1FC08[8]; //0x1FC08
//	class InvitedGamers m_game_invited_gamers; //0x1FC10
//	char pad_20898[4864]; //0x20898
//	class SessionInfoBackup m_last_joined_transition; //0x21B98
//	uint32_t m_activity_max_players; //0x21C74
//	uint32_t m_activity_max_spectators; //0x21C78
//	char pad_21C7C[48]; //0x21C7C
//	bool m_do_not_launch_from_join_as_migrated_host; //0x21CAC
//	char pad_21CAD[7]; //0x21CAD
//	bool m_is_activity_session; //0x21CB4
//	char pad_21CB5[35]; //0x21CB5
//	class RemotePlayerData m_remote_player_data; //0x21CD8
//	char pad_222E0[8]; //0x222E0
//	class rage::netGamePlayerData m_local_net_game_player_data; //0x222E8
//	char pad_22318[608]; //0x22318
//	class rage::rlMatchmakingFindResult m_transition_matchmaking[4]; //0x22578
//	class NetworkGameFilter m_transition_filters[4]; //0x33438
//	char pad_34148[20]; //0x34148
//	uint32_t m_transition_quickmatch_group_handle_count; //0x3415C
//	class rage::rlGamerHandle m_transition_quickmatch_group_handles[32]; //0x34160
//	bool m_retain_activity_group; //0x34360
//	char pad_34361[7]; //0x34361
//	class rage::rlSessionInfo m_transition_to_activity_session_info; //0x34368
//	char pad_34438[48]; //0x34438
//	class MatchmakingSessionResult m_transition_matchmaking_session_results[10]; //0x34468
//	char pad_37208[8]; //0x37208
//	class InvitedGamers m_transition_invited_gamers; //0x37210
//	char pad_37E98[16]; //0x37E98
//	class rage::rlGamerHandle m_transition_to_game_handle; //0x37EA8
//	class rage::rlSessionInfo m_transition_to_game_session_info; //0x37EB8
//	char pad_37F88[4]; //0x37F88
//	uint32_t m_transition_to_game_session_participant_count; //0x37F8C
//	class rage::rlGamerHandle m_transition_to_game_session_participants[32]; //0x37F90
//	char pad_38190[72]; //0x38190
//	class rage::rlGamerHandle m_follower_handles[32]; //0x381D8
//	uint32_t m_follower_count; //0x383D8
//	char pad_383DC[628]; //0x383DC
//}; //Size: 0x38650

class Network
{
public:
	bool m_unk;
	char pad_0001[0x7];
	rage::rlSessionInfo m_steam_unk_session; //0x0000
	rage::Obf32 m_num_dinput8_instances; //0x0070
	rage::Obf32 m_last_time_dinput8_checked; //0x0080
	class rage::snSession m_game_session; //0x00F0
	class rage::snSession m_transition_session; //0x5578
	char pad_AA00[16]; //0xAA00
	class rage::snSession* m_game_session_ptr_2; //0xAA10
	class rage::snSession* m_transition_session_ptr_2; //0xAA18
	char pad_AA20[16]; //0xAA20
	class rage::snSession* m_game_session_ptr; //0xAA30
	class rage::snSession* m_transition_session_ptr; //0xAA38
	char pad_AA40[24]; //0xAA40
	class NetworkGameConfig m_network_game_config; //0xAA58
	class NetworkGameConfig m_network_transition_config; //0xABA0
	bool m_session_attributes_dirty; //0xACE8
	char pad_ACE9[19]; //0xACE9
	uint32_t m_session_visibility_flags; //0xACFC
	uint32_t m_transition_visibility_flags; //0xAD00
	char pad_AD04[68]; //0xAD04
	class MetricSessionMigrated m_metric_session_migrated; //0xAD48
	bool m_migrated_metric_enabled; //0xB090
	char pad_B091[3]; //0xB091
	uint32_t m_game_session_state; //0xB094
	class NetworkGameFilter m_network_game_filter; //0xB098
	char pad_B3DC[33]; //0xB3DC
	bool m_was_invited; //0xB3FD
	char pad_B3FE[10]; //0xB3FE
	class rage::rlSessionInfo m_unk_session_info; //0xB408
	//char pad_B4D8[635]; //0xB4D8
	char pad_B4D8[643]; //0xB4D8
	bool m_need_host_change; //0xB753
	char pad_B754[74316]; //0xB754
	class rage::rlSessionDetail m_joining_session_detail; //0x1D9A0
	class SessionInfoBackup m_last_joined_session; //0x1DE18
	char pad_1DEF4[40]; //0x1DEF4
	uint32_t m_current_matchmaking_group; //0x1DF1C
	uint32_t m_matchmaking_group_max_players[5]; //0x1DF20
	uint32_t m_num_active_matchmaking_groups; //0x1DF34
	char pad_1DF38[8]; //0x1DF38
	uint8_t m_matchmaking_property_id; //0x1DF40
	uint8_t m_matchmaking_mental_state; //0x1DF41
	char pad_1DF42[366]; //0x1DF42
	class rage::rlMatchmakingFindResult m_game_session_matchmaking[3]; //0x1E0B0
	char pad_2ABC0[40]; //0x2ABC0
	class MatchmakingSessionResult m_game_matchmaking_session_results[10]; //0x2ABE8
	char pad_2D988[308]; //0x2D988
	uint32_t m_num_bosses; //0x2DABC
	bool m_num_bosses_set; //0x2DAC0
	char pad_2DAC1[7]; //0x2DAC1
	class rage::rlGamerHandle m_transition_creator_handle; //0x2DAC8
	char pad_2DAD8[12]; //0x2DAD8
	bool m_is_waiting_async; //0x2DAE4
	bool m_is_preferred_activity; //0x2DAE5
	char pad_2DAE6[2]; //0x2DAE6
	uint32_t m_in_progress_finish_time; //0x2DAE8
	char pad_2DAEC[4]; //0x2DAEC
	bool m_local_player_info_dirty; //0x2DAF0
	char pad_2DAF1[495]; //0x2DAF1
	class rage::rlGamerHandle m_inviter_handle; //0x2DCE0
	class CNetComplaintMgr m_game_complaint_mgr; //0x2DCF0
	class CNetComplaintMgr m_transition_complaint_mgr; //0x2EB88
	char pad_2FA20[32]; //0x2FA20
	class JoiningPlayerNameMap m_unused_joining_player_name_map; //0x2FA40
	char pad_31048[8]; //0x31048
	class CNetBlacklist m_blacklist; //0x31050
	char pad_31308[8]; //0x31308
	class InvitedGamers m_game_invited_gamers; //0x31310
	char pad_31F98[5888]; //0x31F98
	class SessionInfoBackup m_last_joined_transition; //0x33698
	uint32_t m_activity_max_players; //0x33774
	uint32_t m_activity_max_spectators; //0x33778
	char pad_3377C[48]; //0x3377C
	bool m_do_not_launch_from_join_as_migrated_host; //0x337AC
	char pad_337AD[7]; //0x337AD
	bool m_is_activity_session; //0x337B4
	char pad_337B5[35]; //0x337B5
	class RemotePlayerData m_remote_player_data; //0x337D8
	char pad_33DE0[8]; //0x33DE0
	class rage::netGamePlayerData m_local_net_game_player_data; //0x33DE8
	char pad_33E18[608]; //0x33E18
	class rage::rlMatchmakingFindResult m_transition_matchmaking[4]; //0x34078
	class NetworkGameFilter m_transition_filters[4]; //0x44F38
	char pad_45C48[20]; //0x45C48
	uint32_t m_transition_quickmatch_group_handle_count; //0x45C5C
	class rage::rlGamerHandle m_transition_quickmatch_group_handles[32]; //0x45C60
	bool m_retain_activity_group; //0x45E60
	char pad_45E61[7]; //0x45E61
	class rage::rlSessionInfo m_transition_to_activity_session_info; //0x45E68
	char pad_45F38[48]; //0x45F38
	class MatchmakingSessionResult m_transition_matchmaking_session_results[10]; //0x45F68
	char pad_48D08[8]; //0x48D08
	class InvitedGamers m_transition_invited_gamers; //0x48D10
	char pad_49998[16]; //0x49998
	class rage::rlGamerHandle m_transition_to_game_handle; //0x499A8
	class rage::rlSessionInfo m_transition_to_game_session_info; //0x499B8
	char pad_49A88[4]; //0x49A88
	uint32_t m_transition_to_game_session_participant_count; //0x49A8C
	class rage::rlGamerHandle m_transition_to_game_session_participants[32]; //0x49A90
	char pad_49C90[80]; //0x49C90
	class rage::rlGamerHandle m_follower_handles[32]; //0x49CE0
	uint32_t m_follower_count; //0x49EE0
	char pad_49EE4[628]; //0x49EE4
}; //Size: 0x38650
enum class ScriptType
{
	Game,
	D3D
};

enum class ScriptAction
{
	D3DResizeBuffersPre,
	D3DResizeBuffersPost,
	GetLabelText
};

class Scriptt
{
public:
	virtual ~Scriptt() noexcept = default;
	Scriptt(Scriptt const&) = delete;
	Scriptt(Scriptt&&) = delete;
	Scriptt& operator=(Scriptt const&) = delete;
	Scriptt& operator=(Scriptt&&) = delete;

	virtual bool IsInitialized() = 0;
	virtual ScriptType GetType() = 0;
	virtual void Initialize() = 0;
	virtual void Destroy() = 0;
	virtual void Tick() = 0;
protected:
	Scriptt() = default;
};

class AbstractCallback
{
public:
	virtual ~AbstractCallback() noexcept = default;
	AbstractCallback(AbstractCallback const&) = delete;
	AbstractCallback& operator=(AbstractCallback const&) = delete;
	AbstractCallback(AbstractCallback&&) = delete;
	AbstractCallback& operator=(AbstractCallback&&) = delete;

	/**
	 * \brief Is the callback completed?
	 * \return bool
	 */
	virtual bool IsDone() = 0;

	/**
	 * \brief Called when IsDone() returns true
	 */
	virtual void OnSuccess() = 0;

	/**
	 * \brief Called when IsDone() returns false
	 */
	virtual void OnFailure() = 0;
protected:
	AbstractCallback() = default;
};
class ModelCallback : public AbstractCallback
{
public:
	explicit ModelCallback(std::uint32_t model, std::function<void()> action) :
		m_Model(model),
		m_Action(std::move(action))
	{
	}

	bool IsDone() override
	{
		return STREAMING::HasModelLoaded(m_Model);
	}

	void OnSuccess() override
	{
		if (m_Action)
			std::invoke(m_Action);
	}

	void OnFailure() override
	{
		STREAMING::RequestModel(m_Model);
	}
private:
	std::uint32_t m_Model;
	std::function<void()> m_Action;
};

class CallbackScript : public Scriptt
{
public:
	explicit CallbackScript() = default;
	~CallbackScript() noexcept = default;

	bool IsInitialized() override;
	ScriptType GetType() override;
	void Initialize() override;
	void Destroy() override;
	void Tick() override;

	/**
	 * \brief Adds a callback to the list
	 * \param args... The arguments to be passed to CallbackType's constructor
	 */
	template <typename CallbackType, typename ...TArgs>
	void AddCallback(TArgs&&... args)
	{
		m_Callbacks.push_back(std::make_unique<CallbackType>(std::forward<TArgs>(args)...));
	}
private:
	bool m_Initialized{};
	std::vector<std::unique_ptr<AbstractCallback>> m_Callbacks;
};
inline std::shared_ptr<CallbackScript> g_CallbackScript;


enum class eThreadState : std::uint32_t
{
	running,
	idle,
	killed,
	paused
	//idle,
	//running,
	//killed,
	//unk_3,
	//unk_4,
};
class scrThreadContext
{
public:
	std::uint32_t m_thread_id;           // 0x00
	joaat_t2 m_script_hash;               // 0x04
	eThreadState m_state;                // 0x08
	std::uint32_t m_instruction_pointer; // 0x0C
	std::uint32_t m_frame_pointer;       // 0x10
	std::uint32_t m_stack_pointer;       // 0x14
	float m_timer_a;                     // 0x18
	float m_timer_b;                     // 0x1C
	float m_timer_c;                     // 0x20
	char m_padding1[0x2C];               // 0x24
	std::uint32_t m_stack_size;          // 0x50
	char m_padding2[0x54];               // 0x54
};
class datBitBuffer;


class CScriptParticipant
{
public:
	char pad_0000[16]; //0x0000
	class CNetGamePlayer* m_net_game_player; //0x0010
	char pad_0018[2]; //0x0018
	int16_t m_participant_index; //0x001A
	char pad_001C[12]; //0x001C
}; //Size: 0x0028



class netLoggingInterface;
class scrThread;

class scriptIdBase
{
public:
	virtual ~scriptIdBase() = default;                            // 0 (0x00)

	// Assumes the script thread's identity.
	virtual void assume_thread_identity(scrThread*) {};           // 1 (0x08)

	// Returns whether the hash of the script id is valid.
	virtual bool is_valid() { return false; };                                   // 2 (0x10)

	// Gets the hash of the script id.
	virtual joaat_t2* get_hash(joaat_t2* out) { return 0; };                   // 3 (0x18)

	// Gets an unknown value from the script id.
	virtual std::uint32_t* get_hash2(std::uint32_t* out) { return 0; };      // 4 (0x20)

	// Gets the name of the script id.
	virtual const char* get_name() { return nullptr; };                            // 5 (0x28)

	// Serializes the script id from the buffer.
	virtual void deserialize(datBitBuffer* buffer) {};            // 6 (0x30)

	// Serializes the script id to the buffer.
	virtual void serialize(datBitBuffer* buffer) {};              // 7 (0x38)

	// Calculates some information with the position hash & instance id.
	virtual std::uint32_t _0x40() { return 0; };                             // 8 (0x40)

	// Calls _0x40 and returns it's value added to another value.
	virtual std::uint32_t _0x48() { return 0; };                             // 9 (0x48)

	// Logs some information about the script id.
	virtual void log_information(netLoggingInterface* logger) {}; // 10 (0x50)

	// Copies the information of other to this object.
	virtual void copy_data(scriptIdBase* other) {}                // 11 (0x58)

	// Returns whether the other script id is equal.
	virtual bool operator==(scriptIdBase*) { return false; };                    // 12 (0x60)

	virtual bool _0x68(void*) { return false; };                                 // 13 (0x68)
};
class scriptId : public scriptIdBase
{
public:
	joaat_t2 m_hash;           // 0x08
	char m_name[0x20];        // 0x0C
};
//}

template <typename T, typename Base = datBase>
class atDNode : public Base
{
public:
	T m_data;
	void* m_unk;
	atDNode<T, Base>* m_next;
};

template <typename Node>
class atDList
{
public:
	Node* m_head;
	Node* m_tail;
};
class scriptResource
{
public:
	virtual ~scriptResource() = default;
};
class scriptHandlerObject;
class scrThread;
class scriptHandler;
class scriptHandlerNetComponent
{
public:
	virtual ~scriptHandlerNetComponent() = default;

	//public:
	scriptHandler* m_script_handler; // 0x08
};
class scriptHandler
{
public:
	class atDScriptObjectNode : public atDNode<scriptHandlerObject*>
	{
	};
public:
	virtual ~scriptHandler() = default;                                                                   //  0 (0x00)

	virtual bool _0x08() = 0;                                                                             //  1 (0x08)

	virtual void _0x10() = 0;                                                                             //  2 (0x10)

	virtual void cleanup_objects() = 0;                                                                   //  3 (0x18)

	virtual scriptId* _0x20() = 0;                                                                        //  4 (0x20)

	virtual scriptId* get_id() = 0;                                                                       //  5 (0x28)

	// Returns whether the script handler belongs to a networked script.
	virtual bool is_networked() = 0;                                                                      //  6 (0x30)

	// Initializes the network component for the script handler.
	virtual void init_net_component() = 0;                                                                //  7 (0x38)

	// Deletes the script handler's network component, if it exists.
	virtual void reset_net_component() = 0;                                                               //  8 (0x40)

	// Destroys the script handler.
	virtual bool destroy() = 0;                                                                           //  9 (0x48)

	// Adds the object to the script handler's list of objects.
	virtual void add_object(scriptHandlerObject*, bool is_network, bool is_network_and_scriptcheck) = 0; // 10 (0x50)

	// Something related to reservations.
	virtual void _0x58(void*) = 0;                                                                        // 11 (0x58)

	virtual void register_resource(scriptResource*, void*) = 0;                                           // 12 (0x60)

	virtual void _0x68() = 0;                                                                             // 13 (0x68)

	virtual void _0x70() = 0;                                                                             // 14 (0x70)

	virtual void _0x78() = 0;                                                                             // 15 (0x78)

	virtual void _0x80() = 0;                                                                             // 16 (0x80)

	virtual void _0x88() = 0;                                                                             // 17 (0x88)

	virtual void _0x90() = 0;                                                                             // 18 (0x90)

	virtual void _0x98() = 0;                                                                             // 19 (0x98)
public:
	void* m_0x08;                                // 0x08
	void* m_0x10;                                // 0x10
	scrThread* m_script_thread;                  // 0x18
	atDList<atDScriptObjectNode> m_objects;      // 0x20
	scriptResource* m_resource_list_head;        // 0x30
	scriptResource* m_resource_list_tail;        // 0x38
	void* m_0x40;                                // 0x40
	scriptHandlerNetComponent* m_net_component;  // 0x48
	std::uint32_t m_0x50;                        // 0x50
	std::uint32_t m_0x54;                        // 0x54
	std::uint32_t m_0x58;                        // 0x58
	std::uint32_t m_0x60;                        // 0x5C
};
class CGameScriptId : public scriptId
{
public:
	char m_padding[0x04];         // 0x2C
	std::int32_t m_timestamp;     // 0x30
	std::int32_t m_position_hash; // 0x34
	std::int32_t m_instance_id;   // 0x38
	std::int32_t m_unk;           // 0x3C
};
class CGameScriptHandler : public scriptHandler
{
public:
	CGameScriptId m_script_id; // 0x60
};

class CGameScriptHandlerNetComponent
{
public:
	virtual ~CGameScriptHandlerNetComponent() = default;

	virtual bool _0x08(void*) = 0;

	virtual void _0x10(CNetGamePlayer*) = 0; // creates a scriptId?

	virtual void* player_left(CNetGamePlayer* player) = 0;

	virtual void* send_host_migration_event(CNetGamePlayer* player) = 0;

	virtual void* player_joined(void**, void* msg_ctx) = 0;

	virtual void* player_joined_ack(void**, void* msg_ctx) = 0;

	virtual bool _0x38(void*, void*) = 0; // join_script?

	virtual void* _0x40(void*, void*) = 0;

	virtual void* _0x48(void*, void*, void*) = 0;

	virtual void* _0x50(void*, void*) = 0;

	virtual void* _0x58(void*, void*) = 0;

	virtual void* _0x60(void*, void*) = 0;

	virtual void* _0x68(void*, void*) = 0;

	virtual void _0x70(void*, void*) = 0;

	virtual void _0x78(void*, void*) = 0;

	virtual short _0x80(void*, void*) = 0;

	virtual void* _0x88(void*, void*) = 0;

	virtual void* _0x90(void*, void*) = 0; // HOST_MIGRATION_FAILED

	virtual bool _0x98(void*, void*) = 0;

	virtual void* _0xA0(void*, void*) = 0;

	virtual void* _0xA8(void*, void*) = 0;

	virtual short _0xB0(void*, void*) = 0;

	virtual bool register_host_broadcast_data(void* data, int size, char* a3) = 0;

	virtual bool register_player_broadcast_data(int a1, int size, bool a3) = 0;

	virtual bool _0xC8() = 0; // something to do to joining session

	virtual bool _0xD0() = 0;

	virtual bool add_player_to_script(CNetGamePlayer* player, short* outParticipantID, short* outSlot, int* outFailReason) = 0;

	virtual bool add_player_to_script_internal(CNetGamePlayer* player, short participantID, short slot) = 0; // player aka participant

	virtual bool remove_player_from_script(CNetGamePlayer* player) = 0;

	virtual void* player_left_impl(CNetGamePlayer*, bool) = 0;

	virtual bool do_host_migration(CNetGamePlayer* player, short host_token, bool unk) = 0; // aka _0xF8

	virtual void* leave_from_script() = 0; // calls above function with player = nullptr

	virtual bool _0x108() = 0;

	virtual void* _0x110() = 0;

	virtual bool _0x118() = 0; // related to above function

	//int m_state;
	//int m_join_msg_ack_pending_players;
	//CScriptParticipant* m_first_participant;
	//char gap20[16];
	//CScriptParticipant* m_host;
	//std::int16_t m_local_participant_index;
	//char pad_003A[6];
	//unsigned int m_participant_bitset;
	//uint16_t m_host_token;
	//CNetGamePlayer* m_last_host;
	//CNetGamePlayer* m_host_migration_target;
	//CNetGamePlayer* m_apparent_host_player;
	//char gap60[8];
	//char new_68[8]; // added b3407
	//CScriptParticipant* m_participants[32];
	//char pad_0168[8];
	//int m_next_host_verify_time;
	//char m_max_participants;
	//char pad_0175[23];
	//uint8_t m_num_participants;
	//uint8_t m_num_candidates;
	//uint8_t m_host_ack_error;
	//uint8_t m_host_array_count;
	//uint8_t m_player_array_count;
	//uint8_t m_host_migration_state;
	//std::uint8_t m_flags;
	//char pad_0193[13];
	//char m_script_status_queried;

	CGameScriptHandler* m_script_handler; //0x0008
	char pad_0010[32]; //0x0010
	class CScriptParticipant* m_host; //0x0030
	int16_t m_local_participant_index; //0x0038
	char pad_003A[6]; //0x003A
	uint32_t m_participant_bitset; //0x0040
	char pad_0044[36]; //0x0044
	class CScriptParticipant* m_participants[32]; //0x0068
	char pad_0168[12]; //0x0168
	int16_t m_num_participants; //0x0174
	char pad_0176[28]; //0x0176
	uint8_t m_host_migration_flags; //0x0192
	char pad_0193[29]; //0x0193

	int get_participant_index(CNetGamePlayer* player);
	bool is_player_a_participant(CNetGamePlayer* player);

	inline bool is_local_player_host()
	{
		if (!m_host)
			return true; // or return false?

		return m_host->m_participant_index == m_local_participant_index;
	}

	inline CNetGamePlayer* get_host()
	{
		if (!m_host)
			return nullptr;

		return m_host->m_net_game_player;
	}

	// not 100% foolproof
	inline void block_host_migration(bool toggle)
	{
		if (toggle)
			m_host_migration_flags |= (1 << 7);
		else
			m_host_migration_flags &= ~(1 << 7);
	}

}; //Size: 0x01B0

enum class eNetMessage : uint32_t
{
	MsgInvalid = 0xFFFFF,
	MsgSessionAcceptChat = 0x62,
	MsgStartMatchCmd = 0x2D,
	MsgSetInvitableCmd = 0x1F,
	MsgSessionMemberIds = 0x23,
	MsgRequestGamerInfo = 0x54,
	MsgRemoveGamersFromSessionCmd = 0x53,
	MsgNotMigrating = 0x35,
	MsgMigrateHostResponse = 0x12,
	MsgMigrateHostRequest = 0x66,
	MsgJoinResponse = 0x2A,
	MsgJoinRequest = 0x41,
	MsgHostLeftWhilstJoiningCmd = 0x58,
	MsgConfigResponse = 0x5F,
	MsgConfigRequest = 0x48,
	MsgChangeSessionAttributesCmd = 0x5A,
	MsgAddGamerToSessionCmd = 0x64, // this is where send net info to lobby is called, among other things
	MsgReassignResponse = 0x10,
	MsgReassignNegotiate = 0x01,
	MsgReassignConfirm = 0x26,
	MsgPlayerData = 0x18,
	MsgPackedReliables = 0x30,
	MsgPackedCloneSyncACKs = 0x3B,
	MsgNonPhysicalData = 0x16,
	MsgNetArrayMgrUpdateAck = 0x5D,
	MsgNetArrayMgrUpdate = 0x60,
	MsgNetArrayMgrSplitUpdateAck = 0x25,
	MsgScriptVerifyHostAck = 0x0B,
	MsgScriptVerifyHost = 0x3E,
	MsgScriptNewHost = 0x0E,
	MsgScriptMigrateHostFailAck = 0x1A,
	MsgScriptMigrateHost = 0x33,
	MsgScriptLeaveAck = 0x40,
	MsgScriptLeave = 0x17,
	MsgScriptJoinHostAck = 0x4D,
	MsgScriptJoinAck = 0x43,
	MsgScriptJoin = 0x5C,
	MsgScriptHostRequest = 0x67,
	MsgScriptHandshakeAck = 0x5B,
	MsgScriptHandshake = 0x57,
	MsgScriptBotLeave = 0x2B, // unused?
	MsgScriptBotJoinAck = 0x63, // unused?
	MsgScriptBotJoin = 0x1C, // unused?
	MsgScriptBotHandshakeAck = 0x31, // unused?
	MsgScriptBotHandshake = 0x4B, // unused?
	MsgPartyLeaveGame = 0x3D,
	MsgPartyEnterGame = 0x1E,
	MsgCloneSync = 0x4E, // aka clone_create, clone_sync etc.
	MsgActivateNetworkBot = 0x65, // unused?
	MsgRequestObjectIds = 0x29,
	MsgInformObjectIds = 0x09,
	MsgTextMessage = 0x24, // this one is for chat
	MsgPlayerIsTyping = 0x61,
	MsgPackedEvents = 0x4F, // aka received_event
	MsgPackedEventReliablesMsgs = 0x20,
	MsgRequestKickFromHost = 0x0D,
	MsgTransitionToGameStart = 0x50,
	MsgTransitionToGameNotify = 0x02,
	MsgTransitionToActivityStart = 0x06,
	MsgTransitionToActivityFinish = 0x36,
	MsgTransitionParameters = 0x3C,
	MsgTransitionParameterString = 0x37,
	MsgTransitionLaunchNotify = 0x1B,
	MsgTransitionLaunch = 0x19,
	MsgTransitionGamerInstruction = 0x14,
	MsgTextMessage2 = 0x0A, // this one is for phone message
	MsgSessionEstablishedRequest = 0x52,
	MsgSessionEstablished = 0x07,
	MsgRequestTransitionParameters = 0x42,
	MsgRadioStationSyncRequest = 0x47,
	MsgRadioStationSync = 0x46,
	MsgPlayerCardSync = 0x3A,
	MsgPlayerCardRequest = 0x6A,
	MsgLostConnectionToHost = 0x81,
	MsgKickPlayer = 0x34, // host kick
	MsgDebugStall = 0x7E, // unused?
	MsgCheckQueuedJoinRequestReply = 0x59,
	MsgCheckQueuedJoinRequest = 0x51,
	MsgBlacklist = 0x0C,
	MsgRoamingRequestBubbleRequiredResponse = 0x83,
	MsgRoamingRequestBubbleRequiredCheck = 0x82,
	MsgRoamingRequestBubble = 0x2E,
	MsgRoamingJoinBubble = 0x4C,
	MsgRoamingJoinBubbleAck = 0x3F,
	MsgRoamingInitialBubble = 0x32,
	MsgVoiceStatus = 0x03,
	MsgTextChatStatus = 0x00,
	MsgJoinResponse2 = 0x08,
	MsgJoinRequest2 = 0x68,
	MsgNetTimeSync = 0x38, // ctor 40 53 48 83 EC 20 BA ? ? ? ? 4C 8D 0D ? ? ? ? 48 8B D9 44 8D 42 37
	MsgNetComplaint = 0x55, // ctor 40 53 48 83 EC 20 BA ? ? ? ? 4C 8D 0D ? ? ? ? 48 8B D9 44 8D 42 54
	MsgNetLagPing = 0x27, // unused? ctor 40 53 48 83 EC 20 BA ? ? ? ? 4C 8D 0D ? ? ? ? 48 8B D9 44 8D 42 26
	MsgSearchResponse = 0x6B, // unused? ctor 40 53 48 83 EC 20 BA ? ? ? ? 4C 8D 0D ? ? ? ? 48 8B D9 44 8D 42 6A
	MsgSearchRequest = 0x05, // unused?
	MsgQosProbeResponse = 0x2C, // ctor 40 53 48 83 EC 20 BA ? ? ? ? 4C 8D 0D ? ? ? ? 48 8B D9 44 8D 42 2B
	MsgQosProbeRequest = 0x1D, // ctor 40 53 48 83 EC 20 BA ? ? ? ? 4C 8D 0D ? ? ? ? 48 8B D9 44 8D 42 1C
	MsgCxnRelayAddressChanged = 0x49, // ctor 40 53 48 83 EC 20 BA ? ? ? ? 4C 8D 0D ? ? ? ? 48 8B D9 44 8D 42 48
	MsgCxnRequestRemoteTimeout = 0x2F, // ctor 40 53 48 83 EC 20 BA ? ? ? ? 4C 8D 0D ? ? ? ? 48 8B D9 44 8D 42 2E
	MsgSessionDetailRequest = 0x22, // ctor 40 53 48 83 EC 20 BA ? ? ? ? 4C 8D 0D ? ? ? ? 48 8B D9 44 8D 42 21
	MsgSessionDetailResponse = 0x13, // ctor 40 53 48 83 EC 20 BA ? ? ? ? 4C 8D 0D ? ? ? ? 48 8B D9 44 8D 42 12
	MsgKeyExchangeOffer = 0x0F, // ctor 40 53 48 83 EC 20 BA ? ? ? ? 4C 8D 0D ? ? ? ? 48 8B D9 44 8D 42 0E (last result)
	MsgKeyExchangeAnswer = 0x44, // ctor 40 53 48 83 EC 20 BA ? ? ? ? 4C 8D 0D ? ? ? ? 48 8B D9 44 8D 42 43
	Msg_0x87 = 0x87,
	Msg_0x88 = 0x88,
	Msg_0x80 = 0x80,
	Msg_0x28 = 0x28,
	Msg_0x11 = 0x11,
	Msg_0x45 = 0x45,
	Msg_0x89 = 0x89,
	Msg_0x86 = 0x86,
	MsgBattlEyeCmd = 0x8F,
};

namespace rage2
{
	class pgBase
	{
	public:
		virtual ~pgBase() = default;
		virtual int return_zero() = 0;
		virtual void error() = 0;

		void* unk_0000; // 0x0000
	}; //Size: 0x0008
	//static_assert(sizeof(pgBase) == 0x10);
}

namespace rage2
{
	class scrProgram : public rage2::pgBase
	{
	public:
		std::uint8_t** m_code_blocks;  // 0x10
		std::uint32_t m_hash;          // 0x18
		std::uint32_t m_code_size;     // 0x1C
		std::uint32_t m_arg_count;     // 0x20
		std::uint32_t m_local_count;   // 0x24
		std::uint32_t m_global_count;  // 0x28
		std::uint32_t m_native_count;  // 0x2C
		void* m_local_data;            // 0x30
		std::int64_t** m_global_data;  // 0x38
		void** m_native_entrypoints;   // 0x40
		char m_padding6[0x10];         // 0x48
		std::uint32_t m_name_hash;     // 0x58
		char m_padding7[0x04];         // 0x5C
		const char* m_name;            // 0x60
		const char** m_strings_data;   // 0x68
		std::uint32_t m_strings_count; // 0x70
		char m_padding8[0x0C];         // 0x74

		bool is_valid() const
		{
			return m_code_size != 0;
		}

		std::uint32_t get_num_code_pages() const
		{
			return (m_code_size + 0x3FFF) >> 14;
		}

		std::uint32_t get_code_page_size(std::uint32_t page) const
		{
			auto num = get_num_code_pages();
			if (page < num)
			{
				if (page == num - 1)
					return m_code_size & 0x3FFF;
				return 0x4000;
			}

			return 0;
		}

		std::uint32_t get_full_code_size() const
		{
			auto numPages = get_num_code_pages();
			if (!numPages)
				return 0;
			if (numPages == 1)
				--numPages;

			return (numPages * 0x4000) + (m_code_size & 0x3FFF);
		}

		std::uint8_t* get_code_page(std::uint32_t page) const
		{
			return m_code_blocks[page];
		}

		std::uint8_t* get_code_address(std::uint32_t index) const
		{
			if (index < m_code_size)
				return &m_code_blocks[index >> 14][index & 0x3FFF];

			return nullptr;
		}

		const char* get_string(std::uint32_t index) const
		{
			if (index < m_strings_count)
				return &m_strings_data[index >> 14][index & 0x3FFF];

			return nullptr;
		}

		void** get_address_of_native_entrypoint(void* entrypoint)
		{
			for (std::uint32_t i = 0; i < m_native_count; ++i)
			{
				if (m_native_entrypoints[i] == entrypoint)
				{
					return m_native_entrypoints + i;
				}
			}

			return nullptr;
		}
	};

	class scrProgramTableEntry
	{
	public:
		scrProgram* m_program;     // 0x00
		char m_Pad1[0x04];         // 0x08
		joaat_t m_hash;            // 0x0C
	};

	class scrProgramTable
	{
	public:
		scrProgramTableEntry* m_data;    // 0x00
		char m_padding[0x10];            // 0x08
		std::uint32_t m_size;            // 0x18

		std::list<joaat_t> all_script_hashes()
		{
			std::list<rage::joaat_t> hash;

			for (uint32_t i = 0; i < m_size; ++i)
			{
				if (m_data[i].m_program != nullptr && m_data[i].m_program->m_name != nullptr)
				{
					hash.push_back(m_data[i].m_hash);
				}
			}
			return hash;
		}

		std::list<std::string> all_script_names()
		{
			std::list<std::string> hash;

			for (uint32_t i = 0; i < m_size; ++i)
			{
				if (m_data[i].m_program != nullptr && m_data[i].m_program->m_name != nullptr)
				{
					hash.push_back(m_data[i].m_program->m_name);
				}
			}
			return hash;
		}

		scrProgram* find_script(joaat_t hash)
		{
			for (std::uint32_t i = 0; i < m_size; ++i)
			{
				if (m_data[i].m_hash == hash)
				{
					return m_data[i].m_program;
				}
			}

			return nullptr;
		}

		scrProgramTableEntry* begin()
		{
			return m_data;
		}

		scrProgramTableEntry* end()
		{
			return m_data + m_size;
		}
	};

	/*static_assert(sizeof(scrProgram) == 0x80);
	static_assert(sizeof(scrProgramTableEntry) == 0x10);
	static_assert(sizeof(scrProgramTable) == 0x1C);*/
}

class GameFunctions1
{
public:
	explicit GameFunctions1();
	~GameFunctions1() noexcept = default;
	GameFunctions1(GameFunctions1 const&) = delete;
	GameFunctions1(GameFunctions1&&) = delete;
	GameFunctions1& operator=(GameFunctions1 const&) = delete;
	GameFunctions1& operator=(GameFunctions1&&) = delete;

	using WndProc = LRESULT(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	WndProc* m_WndProc;

	using GetEventData = bool(std::int32_t eventGroup, std::int32_t eventIndex, std::int64_t* args, std::uint32_t argCount);
	GetEventData* m_GetEventData;

	using GetLabelText = const char* (void* unk, const char* label);
	GetLabelText* m_GetLabelText;

	using DisableErrorScreen = void(char* entryHeader, char* entryLine1, int instructionalKey, char* entryLine2, BOOL p4, Any p5, Any* p6, Any* p7, BOOL background);
	DisableErrorScreen* m_DisableErrorScreen;

	/*using RIDJoinHandle = std::int64_t* (int32_t friendIndex);
	RIDJoinHandle* m_RIDJoinHandle;

	using RIDJoinFriends = bool(int64_t* a1, int* hash);
	RIDJoinFriends* m_RIDJoinFriends;*/

	using ScriptVM = int(void* stack, signed __int64** globals, void* program, scrThreadContext* threadContext);
	ScriptVM* m_ScriptVM;
	using GetConnectionPeer = netConnectionPeer*(rage::netConnectionManager* manager, int peer_id);
	GetConnectionPeer* m_GetConnectionPeer;
	using SendRemoveGamerCmd = void(rage::netConnectionManager* net_connection_mgr, netConnectionPeer* player, int connection_id, rage::snMsgRemoveGamersFromSessionCmd* cmd, int flags);
	SendRemoveGamerCmd* m_SendRemoveGamerCmd;

	using HandleRemoveGamerCmd = void* (rage::snSession* session, rage::snPlayer* origin, rage::snMsgRemoveGamersFromSessionCmd* cmd);
	HandleRemoveGamerCmd* m_HandleRemoveGamerCmd;

	using ReadBitbufDWORD = bool(datBitBuffer* buffer, PVOID read, int bits);
	ReadBitbufDWORD* m_ReadBitbufDWORD;
	using ReadBitbufString = bool(datBitBuffer* buffer, char* read, int bits);
	ReadBitbufString* m_ReadBitbufString;
	using ReadBitbufBool = bool(datBitBuffer* buffer, bool* read, int bits);
	ReadBitbufBool* m_ReadBitbufBool;
	using ReadBitbufArray = bool(datBitBuffer* buffer, PVOID read, int bits, int unk);
	ReadBitbufArray* m_ReadBitbufArray;

	using WriteBitbufQWORD = bool(datBitBuffer* buffer, uint64_t val, int bits);
	WriteBitbufQWORD* m_WriteBitbufQWORD;
	using WriteBitbufDWORD = bool(datBitBuffer* buffer, uint32_t val, int bits);
	WriteBitbufDWORD* m_WriteBitbufDWORD;
	using WriteBitbufInt64 = bool(datBitBuffer* buffer, int64_t val, int bits);
	WriteBitbufInt64* m_WriteBitbufInt64;
	using WriteBitbufInt32 = bool(datBitBuffer* buffer, int32_t val, int bits);
	WriteBitbufInt32* m_WriteBitbufInt32;
	using WriteBitbufBool = bool(datBitBuffer* buffer, bool val, int bits);
	WriteBitbufBool* m_WriteBitbufBool;
	using WriteBitbufArray = bool(datBitBuffer* buffer, void* val, int bits, int unk);
	WriteBitbufArray* m_WriteBitbufArray;

	/*using ReadBitbufDWORD = bool(__thiscall*)(datBitBuffer* buffer, PVOID read, int bits);
	ReadBitbufDWORD m_ReadBitbufDWORD;
	using ReadBitbufString = bool(__thiscall*)(datBitBuffer* buffer, char* read, int bits);
	ReadBitbufString m_ReadBitbufString;
	using ReadBitbufBool = bool(__thiscall*)(datBitBuffer* buffer, bool* read, int bits);
	ReadBitbufBool m_ReadBitbufBool;
	using ReadBitbufArray = bool(__thiscall*)(datBitBuffer* buffer, PVOID read, int bits, int unk);
	ReadBitbufArray m_ReadBitbufArray;

	using WriteBitbufQWORD = bool(__thiscall*)(datBitBuffer* buffer, uint64_t val, int bits);
	WriteBitbufQWORD m_WriteBitbufQWORD;
	using WriteBitbufDWORD = bool(__thiscall*)(datBitBuffer* buffer, uint32_t val, int bits);
	WriteBitbufDWORD m_WriteBitbufDWORD;
	using WriteBitbufInt64 = bool(__thiscall*)(datBitBuffer* buffer, int64_t val, int bits);
	WriteBitbufInt64 m_WriteBitbufInt64;
	using WriteBitbufInt32 = bool(__thiscall*)(datBitBuffer* buffer, int32_t val, int bits);
	WriteBitbufInt32 m_WriteBitbufInt32;
	using WriteBitbufBool = bool(__thiscall*)(datBitBuffer* buffer, bool val, int bits);
	WriteBitbufBool m_WriteBitbufBool;
	using WriteBitbufArray = bool(__thiscall*)(datBitBuffer* buffer, void* val, int bits, int unk);
	WriteBitbufArray m_WriteBitbufArray;*/

	int64_t** m_SendChatPointer{};
	using SendChatMessage = bool(int64_t* send_chat_ptr, rage::rlGamerInfo* gamer_info, char* message, bool is_team);
	SendChatMessage* m_SendChatMessage;

	using send_packet = bool(rage::netConnectionManager* mgr, netConnectionPeer* peer, int connection_id, void* data, int size, int flags);
	using queue_packet = bool(rage::netConnectionManager* mgr, int msg_id, void* data, int size, int flags, void* unk);
	send_packet* m_send_packet;
	queue_packet* m_queue_packet;

	typedef __int64(__cdecl* fpModelInfo)(unsigned int model, DWORD* out);
	fpModelInfo model_info;
	typedef uint64_t(__cdecl* fpGetEntityFromScriptGuId)(int ped);
	fpGetEntityFromScriptGuId			    get_entity_from_script_gu_id;

	using script_vm = int(uint64_t* stack, int64_t** scr_globals, rage2::scrProgram* program, scrThreadContext* ctx);
	script_vm* m_script_vm;
	using trigger_script_event = void(int event_group, int64_t* args, int arg_count, int player_bits, int event_id);
	trigger_script_event* m_trigger_script_event;

};
inline std::unique_ptr<GameFunctions1> g_GameFunctions;

using give_pickup_rewards = void(*)(int players, uint32_t hash);

namespace rage
{
	class snConnectToPeerTaskData
	{
	public:
		int m_unk;
		int m_reason;
		uint64_t m_session_token;
	};

	class snConnectToPeerTaskResult
	{
	public:
		char pad[0x10]{};
		int m_peer_id;
		char pad2[0x400]{};
	};
}
namespace rage
{
	struct rlTaskStatus
	{
		int status = 0;
		int unk = 0;
	};
}
class ScInfo
{
public:
	char m_ticket[208]; //0x0000
	char pad_00D0[304]; //0x00D0
	char m_session_ticket[88]; //0x0200 - rlSessionInfo base64 serialized?
	char pad_0258[40]; //0x0258
	uint32_t m_nonce; //0x0280
	char pad_0284[4]; //0x0284
	uint32_t m_account_id; //0x0288
	char pad_028C[16]; //0x028C
	char m_profile_pic[128]; //0x029C
	char pad_031C[32]; //0x031C
	char m_country_code[4]; //0x033C
	char pad_0340[31]; //0x0340
	char m_email_address[96]; //0x035F
	char pad_03BF[6]; //0x03BF
	char m_language_subtag[8]; //0x03C5
	char pad_03CD[2]; //0x03CD
	char m_sc_name[20]; //0x03CF
	char pad_03E3[533]; //0x03E3
	char m_session_key[16]; //0x05F8
	char pad_0608[2296]; //0x0608
}; //Size: 0x0F00




namespace rage
{
	// #pragma pack(push,8)
	class rlScHandle
	{
	public:
		uint64_t m_rockstar_id; //0x0000
		char m_pad[2];
		uint8_t m_platform; //0x000A
		uint8_t unk_0009; //0x000B

		inline rlScHandle() = default;

		inline rlScHandle(uint64_t rockstar_id) :
			m_rockstar_id(rockstar_id),
			m_platform(3),
			unk_0009(0)
		{
		}
	}; //Size: 0x0010
	// 	static_assert(sizeof(rlScHandle) == 0x10);
	// #pragma pack(pop)
}
namespace rage
{
	class rlQueryPresenceAttributesContext
	{
	public:
		char m_presence_attribute_key[64]; //0x0000
		char m_presence_attribute_value[256]; //0x0040
		uint32_t m_presence_attibute_type; //0x0140
		char pad_0144[4]; //0x0144
	}; //Size: 0x0148
	// 	static_assert(sizeof(rage::rlQueryPresenceAttributesContext) == 0x148);
}

namespace rage
{
	class rlSessionByGamerTaskResult
	{
	public:
		rlGamerHandle m_gamer_handle{ 0 };
		rlSessionInfo m_session_info;
	};
}


class scrThread
{
public:
	virtual ~scrThread() = default;                                                                 // 0 (0x00)
	virtual void reset(std::uint32_t script_hash, void* args, std::uint32_t arg_count) = 0;         // 1 (0x08)
	virtual eThreadState run() = 0;                                                                 // 2 (0x10)
	virtual eThreadState tick(std::uint32_t ops_to_execute) = 0;                                    // 3 (0x18)
	virtual void kill() = 0;                                                                        // 4 (0x20)

	/*inline static scrThread* get()
	{
		return rage::tlsContext::get()->m_script_thread;
	}*/
public:
	scrThreadContext m_context;                      // 0x08
	void* m_stack;                                   // 0xB0
	char m_padding[0x4];                             // 0xB8
	uint32_t m_arg_size;                             // 0xBC
	uint32_t m_arg_loc;                              // 0xC0
	char m_padding2[0x4];                            // 0xC4
	const char* m_exit_message;                      // 0xC8
	std::uint32_t m_name_hash;                       // 0xCC
	char m_name[0x40];                               // 0xD4
	scriptHandler* m_handler;                        // 0x114
	CGameScriptHandlerNetComponent* m_net_component; // 0x11C
	//rage::joaat_t m_script_hash;                // 0x128
};

class scriptHandlerMgr
{
public:
	virtual ~scriptHandlerMgr() = default;

	// Initializes some scripting-related pools.
	virtual bool initialize() = 0;                                                          // 1 (0x08)

	// Called every tick.
	virtual void _0x10() = 0;                                                               // 2 (0x10)

	// Frees some scripting-related pools.
	virtual void shutdown() = 0;                                                            // 3 (0x18)

	virtual void _0x20() = 0;                                                               // 4 (0x20)
	virtual void _0x28() = 0;                                                               // 5 (0x28)
	virtual void _0x30() = 0;                                                               // 6 (0x30)

	// Generates a rage::scriptId from the thread and copies it over to a global structure.
	virtual void _0x38(scrThread*) = 0;                                                     // 7 (0x38)

	// Allocates and constructs a script handler.
	virtual scriptHandler* create_script_handler() = 0;                                     // 8 (0x40)

	// Finds the script handler for a given script id.
	virtual scriptHandler* get_script_handler(scriptId*) = 0;                               // 9 (0x48)

	// Attaches a script thread.
	virtual void attach_thread(scrThread*) = 0;                                             // 10 (0x50)

	// Detaches a script thread.
	virtual void detach_thread(scrThread*) = 0;                                             // 11 (0x58)

	// Called when a player joins.
	virtual void on_player_join(rage::netPlayer*) = 0;                                            // 12 (0x60)

	// Called when a player leaves.
	virtual void on_player_left(rage::netPlayer*) = 0;                                            // 13 (0x68)

	virtual std::int32_t _0x70() = 0;                                                       // 14 (0x70)
	virtual void* _0x78() = 0;                                                              // 15 (0x78)
public:
	char m_padding1[0x28];                         // 0x08
	bool m_initialized;                            // 0x30
	bool m_initialized2;                           // 0x31
	char m_padding2[0x0E];                         // 0x32
	netLoggingInterface* m_logger;           // 0x40
};

class GtaThread : public scrThread
{
public:
	rage::joaat_t m_script_hash;                // 0x128
	int m_force_cleanup_ip;                     // 0x12C
	int m_force_cleanup_fp;                     // 0x130
	int m_force_cleanup_sp;                     // 0x134
	int m_force_cleanup_filter;                 // 0x138
	int m_force_cleanup_cause;                  // 0x13C
	std::int32_t m_instance_id;                 // 0x140
	char m_padding4[0x04];                      // 0x144
	std::uint8_t m_flag1;                       // 0x148
	bool m_safe_for_network_game;               // 0x149
	char m_padding5[0x02];                      // 0x14A
	bool m_is_minigame_script;                  // 0x14C
	char m_padding6[0x02];                      // 0x14D
	bool m_can_be_paused;                       // 0x14F
	bool m_can_remove_blips_from_other_scripts; // 0x150
	char m_padding7[0x2];                       // 0x151
	std::uint8_t m_force_cleanup_state;         // 0x153
	char m_padding8[0xC];                       // 0x154
	//rage::joaat_t m_script_hash;                // 0x128
	//char m_padding3[0x14];                      // 0x12C
	//std::int32_t m_instance_id;                 // 0x140
	//char m_padding4[0x04];                      // 0x144
	//std::uint8_t m_flag1;                       // 0x148
	//bool m_safe_for_network_game;               // 0x149
	//char m_padding5[0x02];                      // 0x14A
	//bool m_is_minigame_script;                  // 0x14C
	//char m_padding6[0x02];                      // 0x14D
	//bool m_can_be_paused;                       // 0x14F
	//bool m_can_remove_blips_from_other_scripts; // 0x150
	//char m_padding7[0x0F];                      // 0x151
};
template<typename T> class pgCollection
{
private:
	T* m_pData;
	UINT16		m_pCount;
	UINT16		m_pSize;

public:
	T* begin()
	{
		return m_pData;
	}

	T* end()
	{
		return (m_pData + m_pCount);
	}

	T* at(UINT16 index)
	{
		return &m_pData[index];
	}
};

template<typename T> class pgPtrCollection
{
private:
	T** m_pData;
	UINT16		m_pCount;
	UINT16		m_pSize;

public:
	T** begin()
	{
		return m_pData;
	}

	T** end()
	{
		return (m_pData + m_pCount);
	}

	T* at(UINT16 index)
	{
		return m_pData[index];
	}

	UINT16 count()
	{
		return m_pCount;
	}

	void set(UINT16 index, T* ptr)
	{
		m_pData[index] = ptr;
	}
};

namespace rage
{
	class scrNativeRegistration
	{
	public:
		uint64_t m_next_registration1;
		uint64_t m_next_registration2;
		void* m_handlers[7];
		uint32_t m_num_entries1;
		uint32_t m_num_entries2;
		uint64_t m_hashes;
		scrNativeRegistration* get_next_registration() {
			std::uintptr_t result;
			auto nextReg = uintptr_t(&m_next_registration1);
			auto newReg = nextReg ^ m_next_registration2;
			auto charTableOfRegs = (char*)&result - nextReg;
			for (auto i = 0; i < 3; i++) {
				*(std::uint32_t*)&charTableOfRegs[nextReg] = static_cast<std::uint32_t>(newReg) ^ *(std::uint32_t*)nextReg;
				nextReg += 4;
			}
			return reinterpret_cast<scrNativeRegistration*>(result);
		}

		std::uint32_t get_num_entries() {
			return static_cast<std::uint32_t>(((std::uintptr_t)&m_num_entries1) ^ m_num_entries1 ^ m_num_entries2);
		}

		std::uint64_t get_hash(std::uint32_t index) {
			auto nativeAddress = 16 * index + std::uintptr_t(&m_next_registration1) + 0x54;
			std::uint64_t result;
			auto charTableOfRegs = (char*)&result - nativeAddress;
			auto addressIndex = nativeAddress ^ *(std::uint32_t*)(nativeAddress + 8);
			for (auto i = 0; i < 3; i++) {
				*(std::uint32_t*)&charTableOfRegs[nativeAddress] = static_cast<std::uint32_t>(addressIndex ^ *(std::uint32_t*)(nativeAddress));
				nativeAddress += 4;
			}
			return result;
		}
	};
}

namespace rage
{
	class scrNativeRegistrationTable
	{
		scrNativeRegistration* m_entries[0xFF];
		std::uint32_t m_unk;
		bool m_initialized;
	};
}
namespace rage
{
	class scrNativeCallContext
	{
	public:
		void reset()
		{
			m_arg_count = 0;
			m_data_count = 0;
		}

		template <typename T>
		void push_arg(T&& value)
		{
			//             static_assert(sizeof(T) <= sizeof(std::uint64_t));
			*reinterpret_cast<std::remove_cv_t<std::remove_reference_t<T>>*>(reinterpret_cast<std::uint64_t*>(m_args) + (m_arg_count++)) = std::forward<T>(value);
		}

		template <typename T>
		T& get_arg(std::size_t index)
		{
			//             static_assert(sizeof(T) <= sizeof(std::uint64_t));
			return *reinterpret_cast<T*>(reinterpret_cast<std::uint64_t*>(m_args) + index);
		}

		template <typename T>
		void set_arg(std::size_t index, T&& value)
		{
			//             static_assert(sizeof(T) <= sizeof(std::uint64_t));
			*reinterpret_cast<std::remove_cv_t<std::remove_reference_t<T>>*>(reinterpret_cast<std::uint64_t*>(m_args) + index) = std::forward<T>(value);
		}

		template <typename T>
		T* get_return_value()
		{
			return reinterpret_cast<T*>(m_return_value);
		}

		template <typename T>
		void set_return_value(T&& value)
		{
			*reinterpret_cast<std::remove_cv_t<std::remove_reference_t<T>>*>(m_return_value) = std::forward<T>(value);
		}
		static void(*SetVectorResults)(scrNativeCallContext*);
	protected:
		void* m_return_value;
		std::uint32_t m_arg_count;
		void* m_args;
		std::int32_t m_data_count;
		std::uint32_t m_data[48];
	};
	//     static_assert(sizeof(scrNativeCallContext) == 0xE0);

	using scrNativeHash = std::int64_t;
	using scrNativePair = std::pair<scrNativeHash, scrNativeHash>;
	using scrNativeHandler = void(*)(scrNativeCallContext*);
}
class CPedFactory
{
public:
	enum class PedCreateFlags
	{
		IS_NETWORKED = (1 << 0),
		IS_PLAYER = (1 << 1)
	};

	virtual ~CPedFactory() = default;
	virtual CPeda* CreatePed(std::uint8_t* flags, std::uint16_t* model_index, rage::fmatrix44* matrix, bool default_component_variation, bool register_network_object, bool give_default_loadout, bool, bool) = 0; // 0x08
	virtual CPeda* CreateClone(std::uint8_t* flags, std::uint16_t* model_index, rage::fmatrix44* matrix, bool default_component_variation, bool, bool register_network_object, bool) = 0;                          // 0x10
	virtual CPeda* ClonePed(CPeda* ped, bool register_network_object, bool link_blends, bool clone_compressed_damage) = 0;                                                                                          // 0x18
	virtual CPeda* ClonePedToTarget(CPeda* source, CPeda* target, bool clone_compressed_damage) = 0;                                                                                                                 // 0x20
	virtual CPeda* CreatePlayer(std::uint8_t* flags, std::uint16_t model_index, rage::fmatrix44* matrix, CPlayerInfo* player_info) = 0;                                                                            // 0x28
	virtual void DestroyPed(CPeda* ped) = 0;                                                                                                                                                                       // 0x30

	class CPeda* m_local_ped; //0x0008
}; //Size: 0x0010

class datBitBuffer;

// #pragma pack(push,8)
namespace rage {
	class playerDataMsg
	{
	public:
		virtual ~playerDataMsg() = 0;
		virtual int GetBufferSize() = 0;
		virtual void Log() = 0;
		virtual bool Serialize(datBitBuffer* buffer) = 0;
		virtual bool Deserialize(datBitBuffer* buffer) = 0;

		uint32_t m_game_version; //0x0008
		uint32_t m_nat_type; //0x000C
	}; //Size: 0x0010
	//     static_assert(sizeof(playerDataMsg) == 0x10);
}

class CNetGamePlayerDataMsg : public rage::playerDataMsg
{
public:
	uint32_t m_player_type; //0x0010
	uint32_t m_matchmaking_group; //0x0014
	uint32_t m_flags; //0x0018
	uint32_t m_team; //0x001C
	uint64_t m_crew_id; //0x0020
	uint32_t m_aim_preference; //0x0028
	uint16_t m_rank; //0x002C
	uint16_t unk_002E; //0x002E
	uint16_t unk_0030; //0x0030
}; //Size: 0x0038

class netPlayerMgrBase
{
public:
	virtual ~netPlayerMgrBase() = default;
	virtual void Initialize() = 0;
	virtual void Shutdown() = 0;
	virtual void unk_0x18() = 0;
	virtual CNetGamePlayer* AddPlayer_raw(rage::rlGamerInfo* gamer_info, uint32_t a2, CNetGamePlayerDataMsg* player_data, CNonPhysicalPlayerData* non_physical_player_data) = 0;
	virtual void RemovePlayer(CNetGamePlayer* net_game_player) = 0;
	virtual void UpdatePlayerListsForPlayer(CNetGamePlayer* net_game_player) = 0;
	virtual CNetGamePlayer* AddPlayer(rage::rlGamerInfo* gamer_info, uint32_t a3, CNetGamePlayerDataMsg* player_data, CNonPhysicalPlayerData* non_physical_player_data) = 0;

	char pad_0008[8]; //0x0008
	uint64_t* m_network_bandwidth_manager; //0x0010
	//char pad_0018[208]; //0x0018
	char pad_0018[216]; //0x0018
	CNetGamePlayer* m_local_net_player; //0x00E8
	char pad_00F0[144]; //0x00F0
	CNetGamePlayer* m_player_list[32]; //0x0180
	uint16_t m_player_limit; //0x0280
	char pad_0282[10]; //0x0282
	uint16_t m_player_count; //0x028C
	char pad_0290[1618]; //0x0290
}; //Size: 0x08E0

class CNetworkPlayerMgr : public netPlayerMgrBase
{
public:
	CNetGamePlayer m_net_players[32]; //0x08E0
	uint64_t unk_60E0; //0x60E0
	uint64_t unk_60E8; //0x60E8
	uint64_t unk_60F0; //0x60F0
	uint64_t unk_60F8; //0x60F8
	CNetGamePlayer m_net_players_2[32]; //0x6100
	uint64_t unk_B900; //0xB900
	uint64_t unk_B908; //0xB908
	uint64_t unk_B910; //0xB910
	uint64_t unk_B918; //0xB918
	uint64_t unk_B920; //0xB920
	uint64_t unk_B928; //0xB928
	uint64_t unk_B930; //0xB930
	uint32_t unk_B938; //0xB938
	char pad_B93C[3]; //0xB93C
	bool unk_B93F; //0xB93F
	uint32_t unk_B940; //0xB940
	uint32_t unk_B944; //0xB944
	uint16_t unk_B948; //0xB948
}; //Size: 0xB94A

class CViewPort
{
public:
	char _0x0000[0x24C];
	float fViewMatrix[0x10];
};

namespace BypassPatch
{
	extern void ModelSpawnBypass(bool toggle);
}

//enum class eGameState : int32_t
//{
//	Invalid = -1,
//	Playing,
//	Died,
//	Arrested,
//	FailedMission,
//	LeftGame,
//	Respawn,
//	InMPCutscene
//};

class GameVariables1
{
public:
	explicit GameVariables1();
	~GameVariables1() noexcept = default;
	GameVariables1(GameVariables1 const&) = delete;
	GameVariables1(GameVariables1&&) = delete;
	GameVariables1& operator=(GameVariables1 const&) = delete;
	GameVariables1& operator=(GameVariables1&&) = delete;

	//using get_screen_coords_for_world_coords = bool/*(*)*/(float world_coords, float* out_x, float* out_y);
	using get_screen_coords_for_world_coords = bool/*(*)*/(Vector3 world_coords, float* out_x, float* out_y);
	get_screen_coords_for_world_coords* m_get_screen_coords_for_world_coords/*{}*/;


	CViewPort* m_viewPort;


	int* m_resolution_x;
	int* m_resolution_y;

	using GetNetPlayer = CNetGamePlayer*(std::int8_t PlayerIndex);
	GetNetPlayer* m_GetNetPlayer;

	Network** m_Network;
	using SendNetworkInfo = bool(*)(rage::rlGamerInfo* player, int64_t a2, int64_t a3, DWORD* a4);//rage::netPlayerData
	SendNetworkInfo* m_NetworkInfo;

	give_pickup_rewards m_give_pickup_rewards/* = nullptr*/;
	PVOID m_ExplosionBypass;

	using StartGetPresenceAttributes = bool(int profile_index, rage::rlScHandle* handle, rage::rlQueryPresenceAttributesContext* contexts, int count, rage::rlTaskStatus* state);
	StartGetPresenceAttributes* m_StartGetPresenceAttributes;
	using StartGetSessionByGamerHandle = bool(int profile_index, rage::rlGamerHandle* handles, int count, rage::rlSessionByGamerTaskResult* result, int unk, bool* success, rage::rlTaskStatus* state);
	StartGetSessionByGamerHandle* m_StartGetSessionByGamerHandle;

	using DecodePeerInfo = bool(rage::rlGamerInfoBase* info, char* buffer, int* bytes_read);
	DecodePeerInfo* m_DecodePeerInfo;
	using ConnectToPeer = bool(rage::netConnectionManager* mgr, rage::rlGamerInfoBase* gamer_info, rage::snConnectToPeerTaskData* data, rage::snConnectToPeerTaskResult* result, rage::rlTaskStatus* status);
	ConnectToPeer* m_ConnectToPeer;
	ScInfo* m_sc_info;    // Social Club Info

	std::int64_t** m_script_globals/*{}*/;

	using PtrToHandle = Entity(void*);
	PtrToHandle* m_PtrToHandle{};

	using HandleToPtr = rage::CDynamicEntity* (Entity);
	HandleToPtr* m_HandleToPtr{};

	rage2::scrProgramTable* m_script_program_table{};

	pgCollection<GtaThread*>* m_scriptThreads;

	using RunScriptThreads = bool(std::uint32_t ops_to_execute);
	RunScriptThreads* m_RunScriptThreads{};

	rage::scrNativeRegistrationTable* m_native_registration_table{};

	using get_native_handler = rage::scrNativeHandler(*)(rage::scrNativeRegistrationTable* registration_table, rage::scrNativeHash hash);
	get_native_handler m_get_native_handler{};

	CPedFactory** m_ped_factory/*{}*/;

	HWND m_GameWindow;

	CNetworkPlayerMgr** m_NetworkPlayerMgr/*{}*/;

	using MigrateObject = void(CNetGamePlayer* player, rage::netObject* object, int type);
	MigrateObject* m_MigrateObject/*{}*/;

	std::uint64_t** m_GlobalBase;

	std::uint64_t m_WorldBase;
	//std::uint32_t* m_GameState;
	//eGameState* m_GameState;
	GameState* m_GameState;

	std::uint32_t* m_FrameCount;
	bool* m_IsSessionStarted;
	PVOID m_ModelSpawnBypass;
	PVOID m_TimecycleOverride;//m_timecycle_keyframe_override
};
inline std::unique_ptr<GameVariables1> g_GameVariables;


class datBitBuffer
{
public:
	datBitBuffer(void* data, uint32_t size) {
		m_data = data;
		m_bitOffset = 0;
		m_maxBit = size * 8;
		m_bitsRead = 0;
		m_curBit = 0;
		m_highestBitsRead = 0;
		m_flagBits = 0;
	}
	uint32_t GetPosition() {
		return m_bitsRead;
	}
	bool Seek(uint32_t bits) {
		if (bits >= 0) {
			uint32_t length = (m_flagBits & 1) ? m_maxBit : m_curBit;
			if (bits <= length)
				m_bitsRead = bits;
		}
		return false;
	}
	bool WriteBool(bool integer) {
		return g_GameFunctions->m_WriteBitbufBool(this, integer, 1);
	}
	bool ReadBool(bool* integer) {
		return g_GameFunctions->m_ReadBitbufBool(this, integer, 1);
	}
	bool ReadPeerId(uint64_t* integer) {
		return this->ReadQWord(integer, 0x40);
	}
	uint64_t ReadBits(size_t numBits) {
		auto const totalBits = (m_flagBits & 1) ? m_maxBit : m_curBit;
		if ((m_flagBits & 2) || m_bitsRead + numBits > totalBits)
			return 0;
		auto const bufPos = m_bitsRead + m_bitOffset;
		auto const initialBitOffset = bufPos & 0b111;
		auto const start = &((uint8_t*)m_data)[bufPos / 8];
		auto const next = &start[1];
		auto result = (start[0] << initialBitOffset) & 0xff;
		for (auto i = 0; i < ((numBits - 1) / 8); i++) {
			result <<= 8;
			result |= next[i] << initialBitOffset;
		}
		if (initialBitOffset)
			result |= next[0] >> (8 - initialBitOffset);
		m_bitsRead += static_cast<uint32_t>(numBits);
		if (m_bitsRead > m_highestBitsRead)
			m_highestBitsRead = m_bitsRead;
		return result >> ((8 - numBits) % 8);
	}
	int GetDataLength() {
		int leftoverBit = (m_curBit % 8) ? 1 : 0;
		return (m_curBit / 8) + leftoverBit;
	}
	bool ReadString(char* string, int bits) {
		return g_GameFunctions->m_ReadBitbufString(this, string, bits);
	}
	bool WriteByte(uint8_t integer, int bits) {
		return g_GameFunctions->m_WriteBitbufDWORD(this, integer, bits);
	}
	bool ReadByte(uint8_t* integer, int bits) {
		uint32_t read;
		if (g_GameFunctions->m_ReadBitbufDWORD(this, &read, bits)) {
			*integer = read;
			return true;
		}
		return false;
	}
	bool WriteWord(uint16_t integer, int bits) {
		return g_GameFunctions->m_WriteBitbufDWORD(this, integer, bits);
	}
	bool ReadWord(uint16_t* integer, int bits) {
		uint32_t read;
		if (g_GameFunctions->m_ReadBitbufDWORD(this, &read, bits)) {
			*integer = read;
			return true;
		}
		return false;
	}
	bool WriteDword(uint32_t integer, int bits) {
		return g_GameFunctions->m_WriteBitbufDWORD(this, integer, bits);
	}
	bool ReadDword(uint32_t* integer, int bits) {
		return g_GameFunctions->m_ReadBitbufDWORD(this, integer, bits);
	}
	bool WriteInt32(int32_t integer, int bits) {
		return g_GameFunctions->m_WriteBitbufDWORD(this, integer, bits);
	}
	bool ReadInt32(int32_t* integer, int bits) {
		int32_t v8;
		int32_t v9;
		if (ReadDword((uint32_t*)&v8, 1u) && ReadDword((uint32_t*)&v9, bits - 1)) {
			*integer = v8 + (v9 ^ -v8);
			return true;
		}
		return false;
	}
	bool WriteQWord(uint64_t integer, int bits) {
		return g_GameFunctions->m_WriteBitbufQWORD(this, integer, bits);
	}
	bool ReadQWord(uint64_t* integer, int bits) {
		if (bits <= 32) {
			uint32_t v10;
			if (ReadDword(&v10, bits)) {
				*integer = v10;
				return true;
			}
		}
		else {
			uint32_t v10, v11;
			if (ReadDword(&v11, 32u) && ReadDword(&v10, bits - 32u)) {
				*integer = v11 | ((uint64_t)v10 << 32);
				return true;
			}
		}
		return false;
	}
	bool WriteInt64(int64_t integer, int bits) {
		return g_GameFunctions->m_WriteBitbufInt64(this, integer, bits);
	}
	bool ReadInt64(int64_t* integer, int bits) {
		uint32_t v8;
		uint64_t v9;
		if (ReadDword(&v8, 1u) && ReadQWord(&v9, bits - 1)) {
			*integer = v8 + (v9 ^ -(int64_t)v8);
			return true;
		}
		return false;
	}

	bool WriteArray(void* array, int size) {
		return g_GameFunctions->m_WriteBitbufArray(this, array, size, 0);
	}
	bool ReadArray(PVOID array, int size) {
		return g_GameFunctions->m_ReadBitbufArray(this, array, size, 0);
	}

	template<typename T>
	inline T Read(int length)
	{
		static_assert(sizeof(T) <= 4, "maximum of 32 bit read");

		uint32_t val = 0;
		ReadDword(&val, length);

		return T(val);
	}

	template<typename T>
	inline T ReadSigned(int length)
	{
		static_assert(sizeof(T) <= 4, "maximum of 32 bit read");

		int val = 0;
		ReadInt32(&val, length);

		return T(val);
	}

	template<typename T>
	inline void Write(T data, int length)
	{
		static_assert(sizeof(T) <= 8, "maximum of 64 bit write");

		WriteQWord((uint64_t)data, length);
	}

	template<typename T>
	inline void WriteSigned(int length, T data)
	{
		int sign = data < 0;
		int signEx = (data < 0) ? 0xFFFFFFFF : 0;
		int d = (data ^ signEx);

		Write<int>(1, sign);
		Write<int>(length - 1, d);
	}

	inline float ReadFloat(int length, float divisor)
	{
		auto integer = Read<int>(length);

		float max = (1 << length) - 1;
		return ((float)integer / max) * divisor;
	}

	inline void WriteFloat(int length, float divisor, float value)
	{
		float max = (1 << length) - 1;
		int integer = (int)((value / divisor) * max);

		Write<int>(length, integer);
	}

	inline float ReadSignedFloat(int length, float divisor)
	{
		auto integer = ReadSigned<int>(length);

		float max = (1 << (length - 1)) - 1;
		return ((float)integer / max) * divisor;
	}

	inline void WriteSignedFloat(int length, float divisor, float value)
	{
		float max = (1 << (length - 1)) - 1;
		int integer = (int)((value / divisor) * max);

		WriteSigned<int>(length, integer);
	}
public:
	void* m_data; //0x0000
	uint32_t m_bitOffset; //0x0008
	uint32_t m_maxBit; //0x000C
	uint32_t m_bitsRead; //0x0010
	uint32_t m_curBit; //0x0014
	uint32_t m_highestBitsRead; //0x0018
	uint8_t m_flagBits; //0x001C
};

namespace rage2
{

	class packet
	{
	public:
		char m_data[0x4000]{};
		datBitBuffer m_buffer;

		packet();
		void send(uint32_t msg_id);
		void send(int player, int connection_id);

		inline operator datBitBuffer& ()
		{
			return m_buffer;
		}

		template <typename T>
		inline void write(T data, int length)
		{
			m_buffer.Write<T>(data, length);
		}

		inline void write_message(eNetMessage message)
		{
			write<int>(0x3246, 14);
			if ((int)message > 0xFF)
			{
				write<bool>(true, 1);
				write<eNetMessage>(message, 16);
			}
			else
			{
				write<bool>(false, 1);
				write<eNetMessage>(message, 8);
			}
		}

		inline void write_peer_id(std::uint64_t peer_id)
		{
			char b[8];
			datBitBuffer buf(b, 8);
			buf.WriteQWord(peer_id, 64);
			m_buffer.WriteArray(b, 8 * buf.GetDataLength());
		}
	};
}
inline Network* GetNetwork()
{
	return *g_GameVariables->m_Network;
}

namespace gta_util
{
	inline CPeda* get_local_ped()
	{
		if (auto ped_factory = *g_GameVariables->m_ped_factory)
		{
			return ped_factory->m_local_ped;
		}

		return nullptr;
	}

	inline CVehicle* get_local_vehicle()
	{
		if (const auto ped = get_local_ped(); ped)
		{
			if (const auto veh = ped->m_vehicle; veh)
			{
				return veh;
			}
		}
		return nullptr;
	}

	inline CPlayerInfo* get_local_playerinfo()
	{
		if (auto ped_factory = *g_GameVariables->m_ped_factory)
		{
			if (auto ped = ped_factory->m_local_ped)
			{
				return ped->m_player_info;
			}
		}

		return nullptr;
	}

	inline CNetworkPlayerMgr* get_network_player_mgr()
	{
		//return *g_GameVariables->m_network_player_mgr;
		return *g_GameVariables->m_NetworkPlayerMgr;
	}

	inline Network* get_network()
	{
		return *g_GameVariables->m_Network;
	}

	template <typename F, typename ...Args>
	void execute_as_script(rage::joaat_t script_hash, F&& callback, Args &&...args)
	{
		auto tls_ctx = tlsContextz::get();
		/*	for (auto thread : *g_GameVariables->script_threads)*/
		for (auto thread : *g_GameVariables->m_scriptThreads)//m_script_threads
		{
			if (!thread || !thread->m_context.m_thread_id || thread->m_context.m_script_hash != script_hash)
				continue;

			auto og_thread = tls_ctx->m_script_thread;

			tls_ctx->m_script_thread = thread;
			tls_ctx->m_is_script_thread_active = true;

			std::invoke(std::forward<F>(callback), std::forward<Args>(args)...);

			tls_ctx->m_script_thread = og_thread;
			tls_ctx->m_is_script_thread_active = og_thread != nullptr;

			return;
		}
	}



	inline GtaThread* find_script_thread(joaat_t hash)
	{
		for (auto thread : *g_GameVariables->m_scriptThreads)
		{
			if (thread
				&& thread->m_context.m_thread_id
				&& thread->m_handler
				&& thread->m_script_hash == hash)
			{
				return thread;
			}
		}

		return nullptr;
	}

	static rage2::scrProgram* find_script_program(rage::joaat_t hash)
	{
		for (auto& script : *g_GameVariables->m_script_program_table)
		{
			if (script.m_program && script.m_program->m_name_hash == hash)
				return script.m_program;
		}

		return nullptr;
	}
}

class HashNode
{
public:
	int32_t m_hash; //0x0000
	uint16_t m_idx; //0x0004
	char pad_0006[2]; //0x0006
	HashNode* m_next; //0x0008
}; //Size: 0x0010
//static_assert(sizeof(HashNode) == 0x10);

template<typename T>
class HashTable
{
public:
	T* m_data; //0x0000
	uint16_t m_size; //0x0008
	char pad_000A[14]; //0x000A
	uint64_t m_item_size; //0x0018
	char pad_0020[64]; //0x0020
	HashNode** m_lookup_table; //0x0060
	uint16_t m_lookup_key; //0x0068
}; //Size: 0x006A
class CVoiceConnection
{
public:
	class rage::rlGamerInfo m_gamer_info; //0x0000
	char pad_0098[40]; //0x00F8
}; //Size: 0x00C0
//static_assert(sizeof(CVoiceConnection) == 0x118);

class CVoice
{
public:
	class CVoiceConnection m_connection_storage[32]; //0x0000
	char pad_2300[8]; //0x2300
	class CVoiceConnection* m_connections[32]; //0x2308
	uint32_t m_connection_count; //0x2408
	char pad_240C[3508]; //0x240C
}; //Size: 0x31C0
//static_assert(sizeof(CVoice) == 0x31C0);

class CCommunications
{
public:
	char pad_0000[48]; //0x0000
	class CVoice m_voice; //0x0030
	char pad_31F0[280300]; //0x31F0
}; //Size: 0x478DC

class MatchmakingAttributes
{
public:
	uint32_t m_game_mode; //0x0000
	uint32_t m_num_params; //0x0004
	uint32_t m_param_unk[8]; //0x0008
	char m_param_names[8][24]; //0x0028
	uint32_t m_param_values[8]; //0x00E8
	uint32_t m_params_bitset; //0x0108
}; //Size: 0x010C
class RemoteGamerInfoMsg
{
public:
	uint64_t m_session_id; //0x0000
	class rage::rlGamerInfo m_gamer_info; //0x0008
	class netConnectionPeer m_gamer_peer_data; //0x00A0
	uint32_t unk_0xC0; //0x00C0
	uint32_t m_unk_struct_size; //0x00C4 
	char m_unk_struct[512]; //0x00C8 Might be bitbuffer data
	uint32_t m_num_handles; //0x02C8
	class rage::rlGamerHandle m_handles[32]; //0x02D0
}; //Size: 0x04D0
int CGameScriptHandlerNetComponent::get_participant_index(CNetGamePlayer* player)
{
	if (player == (*g_GameVariables->m_NetworkPlayerMgr)->m_local_net_player)
		return m_local_participant_index;

	if (m_num_participants <= 1)
		return -1;

	for (int i = 0; i < m_num_participants - 1; i++)
	{
		if (m_participants[i] && m_participants[i]->m_net_game_player == player)
			return m_participants[i]->m_participant_index;
	}

	return -1;
}
inline bool ForceHost(joaat_t hash)
{

	/*if (auto launcher = findscriptthread::findscriptthread2(hash); launcher && launcher->m_net_component)*/
	if (auto launcher = gta_util::find_script_thread(hash); launcher && launcher->m_net_component)
	{
		for (int i = 0; !launcher->m_net_component->is_local_player_host(); i++)
		{
			if (i > 200)
				return false;

			((CGameScriptHandlerNetComponent*)launcher->m_net_component)->send_host_migration_event(g_GameVariables->m_GetNetPlayer(/*PlayerId2*/PLAYER::PlayerId()));
			/*g_FiberScript->addTask([] { g_FiberScript->Wait(10); });*/
			WAIT(100);
			if (!launcher->m_stack || !launcher->m_net_component)
				return false;
		}
	}

	return true;
}
//Vector3 WorldToScreenAddress;
//
//ImVec2 WorldToScreen(Vector3 pos)
//{
//	//auto& io = ImGui::GetIO();
//	ImVec2 tempVec2;
//	reinterpret_cast<bool(__fastcall*)(Vector3*, float*, float*)>(WorldToScreenAddress)(&pos, &tempVec2.x, &tempVec2.y);
//	tempVec2.x *= io.DisplaySize.x;
//	tempVec2.y *= io.DisplaySize.y;
//	return tempVec2;
//}

//Vector2 WorldToScreen(Vector3 pos)
//{
//	auto& io = ImGui::GetIO();
//
//	Vector3 v3;
//	float* viewMatrix = g_GameVariables->m_viewPort->fViewMatrix;
//	v3.x = (viewMatrix[1] * pos.x) + (viewMatrix[5] * pos.y) + (viewMatrix[9] * pos.z) + viewMatrix[13];
//	v3.y = (viewMatrix[2] * pos.x) + (viewMatrix[6] * pos.y) + (viewMatrix[10] * pos.z) + viewMatrix[14];
//	v3.z = (viewMatrix[3] * pos.x) + (viewMatrix[7] * pos.y) + (viewMatrix[11] * pos.z) + viewMatrix[15];
//	v3.z = 1.0f / v3.z;
//	v3.x *= v3.z;
//	v3.y *= v3.z;
//	float xTmp = io.DisplaySize.x * 0.5f;
//	float yTmp = io.DisplaySize.y * 0.5f;
//
//	float* p1;
//	float* p2;
//
//	v3.x += xTmp + (int)(0.5f * v3.x * io.DisplaySize.x + 0.5f);
//	v3.y = yTmp - (int)(0.5f * v3.y * io.DisplaySize.y + 0.5f);
//	Vector2 Coords = { v3.x, v3.y };
//	return Coords;
//}

//#include <Windows.h>
//#include <vector>
//Vector2 WorldToScreen(Vector3 pos)
//{
//	Vector3 v3;
//	float* viewMatrix = g_GameVariables->m_viewPort->fViewMatrix;
//	v3.x = (viewMatrix[1] * pos.x) + (viewMatrix[5] * pos.y) + (viewMatrix[9] * pos.z) + viewMatrix[13];
//	v3.y = (viewMatrix[2] * pos.x) + (viewMatrix[6] * pos.y) + (viewMatrix[10] * pos.z) + viewMatrix[14];
//	v3.z = (viewMatrix[3] * pos.x) + (viewMatrix[7] * pos.y) + (viewMatrix[11] * pos.z) + viewMatrix[15];
//	v3.z = 1.0f / v3.z;
//	v3.x *= v3.z;
//	v3.y *= v3.z;
//
//	HWND hwnd = GetDesktopWindow();
//	RECT desktop;
//	GetWindowRect(hwnd, &desktop);
//	float xTmp = desktop.right * 0.5f;
//	float yTmp = desktop.bottom * 0.5f;
//
//	v3.x += xTmp + (int)(0.5f * v3.x * desktop.right + 0.5f);
//	v3.y = yTmp - (int)(0.5f * v3.y * desktop.bottom + 0.5f);
//	Vector2 Coords = { v3.x, v3.y };
//	return Coords;
//}

//HWND GetDesktopWindowWithRetry() {
//	HWND hwnd = nullptr;
//	hwnd = FindWindow(L"grcWindow", nullptr);
//	return hwnd;
//}


class m_function
{
public:
	//static bool IsPlayerGodMode(int player);
	static std::string GetPlayerIP(int player);
	static rage::snPlayer* GetSessionPlayer(int player);
	static rage::snPeer* GetSessionPeer(int player);
	//static netAddress GetIPAddress(int player);
	//static const char* PlayerPictureString(int a1);
	static std::uint64_t GetHostToken(int player);
	static const char* GetPlayerName(int player);
	static std::uint64_t GetPlayerRID(int player);
	/*static void DownloadSignature();
	static PStruct* GetSignature(string name);*/
};


namespace wtos
{
	extern Vector2 WorldToScreen(Vector3 pos);
}
namespace rage
{
	class netSyncData;
	class netObject;
}
namespace rage
{
	// #pragma pack(push, 8)
	class netSyncDataNode : public netSyncNodeBase
	{
	public:
		uint32_t flags; //0x40
		uint32_t pad3; //0x44
		uint64_t pad4; //0x48

		netSyncDataNode* parentData; //0x50
		uint32_t childCount; //0x58
		netSyncDataNode* children[8]; //0x5C
		uint8_t syncFrequencies[8]; //0x9C
		void* commonDataOpsVFT; //0xA8 wtf
	};
	//     static_assert(sizeof(netSyncDataNode) == 0xB0);
	// #pragma pack(pop)
}
namespace rage
{
	class datBitBuffer;
	class netSyncDataNode;
}

class NodeCommonDataOperations
{
public:
	virtual ~NodeCommonDataOperations() = default;
	virtual void ReadFromBuffer(rage::netSyncDataNode* node) {};            // 0x08
	virtual void WriteToBuffer(rage::netSyncDataNode* node) {};             // 0x10
	virtual void Unk() {};                                                  // 0x18
	virtual int CalculateSize(rage::netSyncDataNode* node) { return 0; };   // 0x20
	virtual int CalculateSize2(rage::netSyncDataNode* node) { return 0; };  // 0x28
	virtual void LogSyncData(rage::netSyncDataNode* node) {};               // 0x30
	virtual void LogSyncData2(rage::netSyncDataNode* node) {};              // 0x38

	rage::datBitBuffer* m_buffer; // 0x8
};
class CProjectBaseSyncDataNode : public rage::netSyncDataNode
{
public:
	virtual bool IsSyncNode() { return false; }                                 // 0x50
	virtual bool _0x58() { return false; }                                      // 0x58
	virtual bool IsGlobalFlags() { return false; }                              // 0x60
	virtual void DoPreCache(rage::netSyncData* data) {}                         // 0x68
	virtual std::uint8_t GetSyncFrequency(int index) { return 0; }              // 0x70
	virtual int GetSyncInterval(int index) { return 0; }                        // 0x78
	virtual int GetBandwidthForPlayer(int player) { return 200; }               // 0x80 (should always return 200)
	virtual void _0x88(void*) {}                                                // 0x88
	virtual bool _0x90(void*, void*, int, int, int) { return false; }           // 0x90
	virtual int CalculateSize() { return 0; }                                   // 0x98 need to verify later
	virtual bool IsPreCacheDisabled() { return false; }                         // 0xA0
	virtual bool CanApply(rage::netObject* object) { return false; }            // 0xA8
	virtual int GetPlayersInScope() { return -1; }                              // 0xB0
	virtual void DeserializeImpl() {}                                           // 0xB8 need to verify later
	virtual void SerializeImpl() {}                                             // 0xC0 need to verify later
	virtual int CalculateSize2() { return 0; }                                  // 0xC8
	virtual int _0xD0() { return 0; }                                           // 0xD0 calls NodeCommonDataOperations::Unk()
	virtual void Log() {}                                                       // 0xD8
	virtual bool CanPreCache(int) { return false; }                             // 0xE0 arg is always zero afaik
	virtual bool CanBeEmpty() { return false; }                                 // 0xE8
	virtual bool IsEmpty() { return false; }                                    // 0xF0 returns true if all data is default
	virtual void SetEmpty() {}                                                  // 0xF8 sets all data to their default values
	virtual void Log2() {}                                                      // 0x100
	virtual void ResetScriptData() {}                                           // 0x108
	virtual bool _0x110() { return false; }                                     // 0x110

private:
	NodeCommonDataOperations m_common_data_operations; // 0xB0 this is generally invalidated by MoveCommonDataOpsVFT()
};
// static_assert(sizeof(CProjectBaseSyncDataNode) == 0xC0);

class CSyncDataNodeFrequent : public CProjectBaseSyncDataNode {};
class CSyncDataNodeInfrequent : public CProjectBaseSyncDataNode {};
class CVehicleProximityMigrationDataNode : CProjectBaseSyncDataNode
{
public:
	uint32_t m_max_occupants;
	bool m_has_occupants[16];
	int16_t m_occupants[16];
	char pad[16];
	bool m_override_position;
	char pad2[8];
	rage::fvector3 m_position;
	rage::vector3<int32_t> m_velocity;
	char pad3[352];
}; //Size: 0x0180
namespace rage
{
	// #pragma pack(push, 1)
	class tlsContext
	{
	public:
		//char gap0[180];
		char gap0[8884];
		std::uint8_t m_unk_byte; // 0xB4
		char gapB5[3];
		sysMemAllocator* m_allocator; // 0xB8
		sysMemAllocator* m_allocator2; // 0xC0 - Same as 0xB8
		sysMemAllocator* m_allocator3; // 0xC8 - Same as 0xB8
		uint32_t m_console_smth; // 0xD0
		char gapD4[188];
		uint64_t m_unk; // 0x190
		/*char gap198[1712];*/
		//char gap198[1728];
		char gap198[1720];
		/*scrThread *m_script_thread;*/ // 0x848
		scrThread* m_script_thread;
		bool m_is_script_thread_active; // 0x850

#if _WIN32
		static tlsContext* get()
		{
			constexpr std::uint32_t TlsIndex = 0x0;
			return *reinterpret_cast<tlsContext**>(__readgsqword(0x58) + TlsIndex);
		}
#endif
	};
	//     static_assert(sizeof(tlsContext) == 0x851);
	//     static_assert(sizeof(tlsContext) == 0x861);

	// #pragma pack(pop)
}