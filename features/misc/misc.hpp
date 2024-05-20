#pragma once
#include "../../sdk/sdk.hpp"

namespace features::misc 
{
	struct hit_info_t 
	{
		std::string player_name;
		int damage;
		int health;
		std::string hitgroup;
	};

	inline hit_info_t hitinfo;

	void fix_mouse_delta(c_usercmd* cmd);

	void checkpoint_system();
	void viewfov();
	void viewmodel();
	void swayscale();
	void clantag_spammer();
	void force_crosshair();
	void recoil_crosshair();
	void sniper_crosshair();
	void spectators_list();
	void spread_circle();
	void big_scene_indicators();
	void preserve_killfeed();
	void hit_info(i_game_event* event);

	namespace hitmarker 
	{
		void draw();
		void event(i_game_event* event);
	}
}