#include "../hooks.hpp"
#include "../../features/misc/misc.hpp"
#include "../../menu/config/config.hpp"
#include "../../features/skins/skins.hpp"
#include "../../features/visuals/visuals.hpp"
#include "../../features/misc/misc.hpp"
#include "../../features/movement/movement.hpp"
#include "../../features/movement/prediction/prediction.hpp"

void __stdcall sdk::hooks::frame_stage_notify::frame_stage_notify( int stage ) {

	if (stage == frame_render_start) {
		features::misc::force_crosshair();
		features::misc::recoil_crosshair();
		features::visuals::flashalpha();
		features::visuals::skybox_changer(frame_render_start);
		features::visuals::nosmoke();
		backtrack.setup_records();
	}
	else if (stage == frame_render_end) {
		features::visuals::particles();
	}
	else if (stage == frame_net_update_postdataupdate_start) {
		features::skins::agent_changer( );
		features::skins::knife_changer( );
		features::skins::gloves_changer();
		features::skins::full_update();
	}
	else if (stage == frame_net_update_end) {

	}
	else if (stage == frame_start)
	{
	
	}

	if (!interfaces::engine->is_in_game()) {
		fakeping.clear_sequence();
		return ofunc(interfaces::client, stage);
	}

	ofunc( interfaces::client, stage );
}