#pragma once
#include "../../utils/padding.hpp"
#include "../../utils/vfunc.hpp"

class d_variant;
class recv_table;
class recv_prop;
class c_recv_proxy_data;

using recv_var_proxy_fn = void( * )( const c_recv_proxy_data* data, void* struct_ptr, void* out_ptr );
using array_length_recv_proxy_fn = void( * )( void* struct_ptr, int object_id, int current_array_length );
using data_table_recv_var_proxy_fn = void( * )( const recv_prop* prop, void** out_ptr, void* data_ptr, int object_id );

enum send_prop_type {
	_int = 0,
	_float,
	_vec,
	_vec_xy,
	_string,
	_array,
	_data_table,
	_int_64,
};

class d_variant {
public:
	union {
		float m_float;
		long m_int;
		char* m_string;
		void* m_data;
		float m_vector[ 3 ];
		__int64 m_int64;
	};
	send_prop_type type;
};

class c_recv_proxy_data {
public:
	const recv_prop* recv_prop;
	d_variant value;
	int element_index;
	int object_id;
};

class recv_prop {
public:
	char* prop_name;
	send_prop_type prop_type;
	int prop_flags;
	int buffer_size;
	int is_inside_of_array;
	const void* extra_data_ptr;
	recv_prop* array_prop;
	array_length_recv_proxy_fn array_length_proxy;
	recv_var_proxy_fn proxy_fn;
	data_table_recv_var_proxy_fn data_table_proxy_fn;
	recv_table* data_table;
	int offset;
	int element_stride;
	int elements_count;
	const char* parent_array_prop_name;
};

class recv_table {
public:
	recv_prop* props;
	int props_count;
	void* decoder_ptr;
	char* table_name;
	bool is_initialized;
	bool is_in_main_list;
};

class c_client_class;
class i_client_networkable;
class i_client_mode;

using m_create_client_class_fn = i_client_networkable * (__cdecl*)(int, int);
using m_create_event_fn = i_client_networkable * (__cdecl*)();

enum class_ids {
	C_AI_BASE_NPC,
	C_WEAPON_AK47,
	C_BASE_ANIMATING,
	C_BASE_ANIMATING_OVERLAY,
	C_BASE_ATTRIBUTABLE_ITEM,
	C_BASE_BUTTON,
	C_BASE_COMBAT_CHARACTER,
	C_BASE_COMBAT_WEAPON,
	C_BASE_CS_GRENADE,
	C_BASE_CS_GRENADE_PROJECTILE,
	C_BASE_DOOR,
	C_BASE_ENTITY,
	C_BASE_FLEX,
	C_BASE_GRENADE,
	C_BASE_PARTICLE_ENTITY,
	C_BASE_PLAYER,
	C_BASE_PROP_DOOR,
	C_BASE_TEAM_OBJECTIVE_RESOURCE,
	C_BASE_TEMP_ENTITY,
	C_BASE_TOGGLE,
	C_BASE_TRIGGER,
	C_BASE_VIEWMODEL,
	C_BASE_VPHYSICS_TRIGGER,
	C_BASE_WEAPON_WORLD_MODEL,
	C_BEAM,
	C_BEAM_SPOTLIGHT,
	C_BONE_FOLLOWER,
	C_BR_C4_TARGET,
	C_BREACH_CHARGE,
	C_BREACH_CHARGE_PROJECTILE,
	C_BREAKABLE_PROP,
	C_BREAKABLE_SURFACE,
	C_BUMP_MINE,
	C_BUMP_MINE_PROJECTILE,
	C_C4,
	C_CASCADE_LIGHT,
	C_CHICKEN,
	C_COLOR_CORRECTION,
	C_COLOR_CORRECTION_VOLUME,
	C_CS_GAMERULES_PROXY,
	C_CS_PLAYER,
	C_CS_PLAYER_RESOURCE,
	C_CS_RAGDOLL,
	C_CS_TEAM,
	C_DANGERZONE,
	C_DANGERZONE_CONTROLLER,
	C_DEAGLE,
	C_DECOY_GRENADE,
	C_DECOY_PROJECTILE,
	C_DRONE,
	C_DRONE_GUN,
	C_DYNAMIC_LIGHT,
	C_DYNAMIC_PROP,
	C_ECON_ENTITY,
	C_ECON_WEARABLE,
	C_EMBERS,
	C_ENTITY_DISSOLVE,
	C_ENTITY_FLAME,
	C_ENTITY_FREEZING,
	C_ENTITY_PARTICLE_TRAIL,
	C_ENV_AMBIENT_LIGHT,
	C_ENV_DETAIL_CONTROLLER,
	C_ENV_DOF_CONTROLLER,
	C_ENV_GAS_CANISTER,
	C_ENV_PARTICLE_SCRIPT,
	C_ENV_PROJECTED_TEXTURE,
	C_ENV_QUADRATIC_BEAM,
	C_ENV_SCREEN_EFFECT,
	C_ENV_SCREEN_OVERLAY,
	C_ENV_TONEMAP_CONTROLLER,
	C_ENV_WIND,
	C_FE_PLAYER_DECAL,
	C_FIRECRACKER_BLAST,
	C_FIRE_SMOKE,
	C_FIRE_TRAIL,
	C_FISH,
	C_FISTS,
	C_FLASHBANG,
	C_FOG_CONTROLLER,
	C_FOOTSTEP_CONTROL,
	C_FUNC_DUST,
	C_FUNC_LOD,
	C_FUNC_AREA_PORTAL_WINDOW,
	C_FUNC_BRUSH,
	C_FUNC_CONVEYOR,
	C_FUNC_LADDER,
	C_FUNC_MONITOR,
	C_FUNC_MOVE_LINEAR,
	C_FUNC_OCCLUDER,
	C_FUNC_REFLECTIVE_GLASS,
	C_FUNC_ROTATING,
	C_FUNC_SMOKE_VOLUME,
	C_FUNC_TRACK_TRAIN,
	C_GAMERULES_PROXY,
	C_GRASS_BURN,
	C_HANDLE_TEST,
	C_HE_GRENADE,
	C_HOSTAGE,
	C_HOSTAGE_CARRIABLE_PROP,
	C_INCENDIARY_GRENADE,
	C_INFERNO,
	C_INFO_LADDER_DISMOUNT,
	C_INFO_MAP_REGION,
	C_INFO_OVERLAY_ACCESSOR,
	C_ITEM_HEALTHSHOT,
	C_ITEM_CASH,
	C_ITEM_DOGTAGS,
	C_KNIFE,
	C_KNIFE_GG,
	C_LIGHT_GLOW,
	C_MAP_VETO_PICK_CONTROLLER,
	C_MATERIAL_MODIFY_CONTROL,
	C_MELEE,
	C_MOLOTOV_GRENADE,
	C_MOLOTOV_PROJECTILE,
	C_MOVIE_DISPLAY,
	C_PARADROP_CHOPPER,
	C_PARTICLE_FIRE,
	C_PARTICLE_PERFORMANCE_MONITOR,
	C_PARTICLE_SYSTEM,
	C_PHYS_BOX,
	C_PHYS_BOX_MULTIPLAYER,
	C_PHYSICS_PROP,
	C_PHYSICS_PROP_MULTIPLAYER,
	C_PHYS_MAGNET,
	C_PHYS_PROP_AMMO_BOX,
	C_PHYS_PROP_LOOT_CRATE,
	C_PHYS_PROP_RADAR_JAMMER,
	C_PHYS_PROP_WEAPON_UPGRADE,
	C_PLANTED_C4,
	C_PLASMA,
	C_PLAYER_PING,
	C_PLAYER_RESOURCE,
	C_POINT_CAMERA,
	C_POINT_COMMENT_ARYNODE,
	C_POINT_WORLD_TEXT,
	C_POSE_CONTROLLER,
	C_POST_PROCESS_CONTROLLER,
	C_PRECIPITATION,
	C_PRECIPITATION_BLOCKER,
	C_PREDICTED_VIEW_MODEL,
	C_PROP_HALLUCINATION,
	C_PROP_COUNTER,
	C_PROP_DOOR_ROTATING,
	C_PROP_JEEP,
	C_PROP_VEHICLE_DRIVEABLE,
	C_RAGDOLL_MANAGER,
	C_RAGDOLL_PROP,
	C_RAGDOLL_PROP_ATTACHED,
	C_ROPE_KEYFRAME,
	C_WEAPON_SCAR17,
	C_SCENE_ENTITY,
	C_SENSOR_GRENADE,
	C_SENSOR_GRENADE_PROJECTILE,
	C_SHADOW_CONTROL,
	C_SLIDE_SHOW_DISPLAY,
	C_SMOKE_GRENADE,
	C_SMOKE_GRENADE_PROJECTILE,
	C_SMOKE_STACK,
	C_SNOWBALL,
	C_SNOWBALL_PILE,
	C_SNOWBALL_PROJECTILE,
	C_SPATIAL_ENTITY,
	C_SPOTLIGHT_END,
	C_SPRITE,
	C_SPRITE_ORIENTED,
	C_SPRITE_TRAIL,
	C_STATUE_PROP,
	C_STEAMJET,
	C_SUN,
	C_SUNLIGHT_SHADOW_CONTROL,
	C_SURVIVAL_SPAWN_CHOPPER,
	C_TABLET,
	C_TEAM,
	C_TEAM_PLAYROUND_BASED_RULES_PROXY,
	C_TEAR_MORRICOCHET,
	C_TE_BASE_BEAM,
	C_TE_BEAM_ENT_POINT,
	C_TE_BEAM_ENTS,
	C_TE_BEAM_FOLLOW,
	C_TE_BEAM_LASER,
	C_TE_BEAM_POINTS,
	C_TE_BEAM_RING,
	C_TE_BEAM_RING_POINT,
	C_TE_BEAM_SPLINE,
	C_TE_BLOOD_SPRITE,
	C_TE_BLOOD_STREAM,
	C_TE_BREAK_MODEL,
	C_TE_BSP_DECAL,
	C_TE_BUBBLES,
	C_TE_BUBBLE_TRAIL,
	C_TE_CLIENT_PROJECTILE,
	C_TE_DECAL,
	C_TE_DUST,
	C_TE_DYNAMIC_LIGHT,
	C_TE_EFFECT_DISPATCH,
	C_TE_ENERGY_SPLASH,
	C_TE_EXPLOSION,
	C_TE_FIRE_BULLETS,
	C_TE_FIZZ,
	C_TE_FOOTPRINT_DECAL,
	C_TE_FOUNDRY_HELPERS,
	C_TE_GAUSS_EXPLOSION,
	C_TE_GLOW_SPRITE,
	C_TE_IMPACT,
	C_TE_KILL_PLAYER_ATTACHMENTS,
	C_TE_LARGE_FUNNEL,
	C_TE_METAL_SPARKS,
	C_TE_MUZZLE_FLASH,
	C_TE_PARTICLE_SYSTEM,
	C_TE_PHYSICS_PROP,
	C_TE_PLANT_BOMB,
	C_TE_PLAYER_ANIM_EVENT,
	C_TE_PLAYER_DECAL,
	C_TE_PROJECTED_DECAL,
	C_TE_RADIOICON,
	C_TE_SHATTER_SURFACE,
	C_TE_SHOW_LINE,
	C_TE_SLA,
	C_TE_SMOKE,
	C_TE_SPARKS,
	C_TE_SPRITE,
	C_TE_SPRITE_SPRAY,
	C_TEST_PROXY_TOGGLE_NETWORKABLE,
	C_TEST_TRACE_LINE,
	C_TE_WORLD_DECAL,
	C_TRIGGER_PLAYER_MOVEMENT,
	C_TRIGGER_SOUND_OPERATOR,
	C_VGUI_SCREEN,
	C_VOTE_CONTROLLER,
	C_WATER_BULLET,
	C_WATER_LOD_CONTROL,
	C_WEAPON_AUG,
	C_WEAPON_AWP,
	C_WEAPON_BASE_ITEM,
	C_WEAPON_PPBIZON,
	C_WEAPON_CS_BASE,
	C_WEAPON_CS_BASE_GUN,
	C_WEAPON_CYCLER,
	C_WEAPON_DUAL_BERETTAS,
	C_WEAPON_FAMAS,
	C_WEAPON_FIVESEVEN,
	C_WEAPON_G3SG1,
	C_WEAPON_GALIL,
	C_WEAPON_GALIL_AR,
	C_WEAPON_GLOCK18,
	C_WEAPON_P2000,
	C_WEAPON_M249,
	C_WEAPON_M3,
	C_WEAPON_M4A4,
	C_WEAPON_MAC10,
	C_WEAPON_MAG7,
	C_WEAPON_MP5SD,
	C_WEAPON_MP7,
	C_WEAPON_MP9,
	C_WEAPON_NEGEV,
	C_WEAPON_NOVA,
	C_WEAPON_P228,
	C_WEAPON_P250,
	C_WEAPON_P90,
	C_WEAPON_SAWEDOFF,
	C_WEAPON_SCAR20,
	C_WEAPON_SCOUT,
	C_WEAPON_SG550,
	C_WEAPON_SG552,
	C_WEAPON_SG553,
	C_WEAPON_BALLISTIC_SHIELD,
	C_WEAPON_SSG08,
	C_WEAPON_ZEUSX27,
	C_WEAPON_TEC9,
	C_WEAPON_TMP,
	C_WEAPON_UMP45,
	C_WEAPON_USP,
	C_WEAPON_XM1014,
	C_WORLD,
	C_WORLD_VGUI_TEXT,
	DUST_TRAIL,
	MOVIE_EXPLOSION,
	PARTICLE_SMOKE_GRENADE,
	ROCKET_TRAIL,
	SMOKE_TRAIL,
	SPORE_EXPLOSION,
	SPORE_TRAIL
};

class c_client_class {
public:
	m_create_client_class_fn create_fn;
	m_create_event_fn create_event_fn;
	char* network_name;
	recv_table* recvtable_ptr;
	c_client_class* next_ptr;
	class_ids class_id;
};

class i_base_client_dll {
public:

	c_client_class* get_all_classes() {
		using original_fn = c_client_class * (__thiscall*)(i_base_client_dll*);
		return (*(original_fn**)this)[8](this);
	}

	bool dispatch_user_message(int msg_type, unsigned int arg1, unsigned int length, const void* data = nullptr) {
		using original_fn = bool(__thiscall*)(void*, int, unsigned int, unsigned int, const void*);
		return (*(original_fn**)this)[38](this, msg_type, arg1, length, data);
	}
};