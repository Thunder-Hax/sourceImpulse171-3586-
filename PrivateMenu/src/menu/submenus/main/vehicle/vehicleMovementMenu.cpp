#include "stdafx.h"
#include "vehicleMovementMenu.h"
#include "../vehicleMenu.h"
#include "src/menu/submenus/main/local/playerMovementMenu.h"
#include "src/menu/submenus/main/session/playerList/player/dropsMenu.h"

using namespace VehicleMovementMenuVars;

char* call1o;
char* call2o;
char* nameo;
//Ped PTLoopPed;
//Player selPlayer;
//char* call1s;
//char* call2s;
//char* names;
int Menu2::BoostBackKey = B_80;
bool Features::maxspeed = 0;
int Features::maxspeedint = 2000;
bool Features::boostboolb = false;
bool Features::screeneffect = true;
bool Features::ptfxeffect = true;
char* Features::nameEffect = "RaceTurbo";
int Features::BOOSTLEVEL2 = 2;
int Features::BOOSTLEVEL = 2;

void Features::PTFXCALL2car(char* call1, char* call2, char* name)
{
	call1o = call1;
	call2o = call2;
	nameo = name;
	STREAMING::RequestNamedPtfxAsset(call1);
	/*GRAPHICS::USE_PARTICLE_FX_ASSET(call2);*/
	/*GRAPHICS::_SET_PTFX_ASSET_NEXT_CALL(call2);*/
	GRAPHICS::_UseParticleFxAssetNextCall(call2);
	GRAPHICS::_StartParticleFxNonLoopedOnEntity2(name, PLAYER::PlayerPedId(), -2, -2, -0.5, 0, 0, 0.0, 1, false, false, false);
}
void Features::PTFXCALL2car1(char* call1, char* call2, char* name)
{
	call1o = call1;
	call2o = call2;
	nameo = name;
	STREAMING::RequestNamedPtfxAsset(call1);
	/*GRAPHICS::USE_PARTICLE_FX_ASSET(call2);*/
	/*GRAPHICS::_SET_PTFX_ASSET_NEXT_CALL(call2);*/
	GRAPHICS::_UseParticleFxAssetNextCall(call2);
	GRAPHICS::_StartParticleFxNonLoopedOnEntity2(name, PLAYER::PlayerPedId(), 2.5, -2, -0.5, 0, 0, 0.0, 1, false, false, false);
}
void Features::PTFXCALL2car2(char* call1, char* call2, char* name)
{
	call1o = call1;
	call2o = call2;
	nameo = name;
	STREAMING::RequestNamedPtfxAsset(call1);
	/*GRAPHICS::USE_PARTICLE_FX_ASSET(call2);*/
	/*GRAPHICS::_SET_PTFX_ASSET_NEXT_CALL(call2);*/
	GRAPHICS::_UseParticleFxAssetNextCall(call2);
	GRAPHICS::_StartParticleFxNonLoopedOnEntity2(name, PLAYER::PlayerPedId(), -2, 2, -0.5, 0.0, 0.0, 0.0, 1, false, false, false);
}
void Features::PTFXCALL2car3(char* call1, char* call2, char* name)
{
	call1o = call1;
	call2o = call2;
	nameo = name;
	STREAMING::RequestNamedPtfxAsset(call1);
	/*GRAPHICS::USE_PARTICLE_FX_ASSET(call2);*/
	/*GRAPHICS::_SET_PTFX_ASSET_NEXT_CALL(call2);*/
	GRAPHICS::_UseParticleFxAssetNextCall(call2);
	GRAPHICS::_StartParticleFxNonLoopedOnEntity2(name, PLAYER::PlayerPedId(), 2.5, 2, -0.5, 0.0, 0.0, 0.0, 1, false, false, false);
}

namespace VehicleMovementMenuVars {
	Vars vars;

	void BypassMaxSpeed() {
		GetEntityControl()->SimpleRequestControl(GetLocalPlayer().m_vehicle);
		ENTITY::SetEntityMaxSpeed(GetLocalPlayer().m_vehicle, 9999999);
	}

	void LimitMaxSpeed(bool toggle, float amount) {
		GetEntityControl()->SimpleRequestControl(GetLocalPlayer().m_vehicle);
		ENTITY::SetEntityMaxSpeed(GetLocalPlayer().m_vehicle, toggle ? amount / 3.6f : 500);
	}

	void FlyVehicle(float speed) {
		GetEntityControl()->SimpleRequestControl(GetLocalPlayer().m_vehicle);
		if (KeyDown(VK_NUMPAD9) || PAD::IsControlPressed(0, INPUT_FRONTEND_RT)) {
			float entitySpeed = ENTITY::GetEntitySpeed(GetLocalPlayer().m_vehicle);
			VEHICLE::SetVehicleForwardSpeed(GetLocalPlayer().m_vehicle, entitySpeed + ((speed * 50) / 100) < speed * 50 ? entitySpeed + ((speed * 50) / 100) : entitySpeed);
		}
		if (KeyDown(VK_NUMPAD7))ENTITY::SetEntityVelocity(GetLocalPlayer().m_vehicle, 0, 0, 50);
		if (KeyDown(VK_NUMPAD3) || PAD::IsControlPressed(0, INPUT_FRONTEND_LT))ENTITY::SetEntityVelocity(GetLocalPlayer().m_vehicle, 0, 0, 0);
	}

	void HornBoost(float speed) {
		/*if (PLAYER::IsPlayerPressingHorn(GetLocalPlayer().m_id)) {
			GetEntityControl()->SimpleRequestControl(GetLocalPlayer().m_vehicle);
			float entitySpeed = ENTITY::GetEntitySpeed(GetLocalPlayer().m_vehicle);
			AUDIO::SetVehicleBoostActive(GetLocalPlayer().m_vehicle, 1);
			VEHICLE::SetVehicleForwardSpeed(GetLocalPlayer().m_vehicle, entitySpeed + speed);
			AUDIO::SetVehicleBoostActive(GetLocalPlayer().m_vehicle, 0);
			GRAPHICS::_StartScreenEffect("RaceTurbo", 0, 0);
		}*/
		Features::playerid();

		Features::ptfxeffect = vars.ptfxboost;
		Features::screeneffect = vars.effectboost;
		Features::BOOSTLEVEL = vars.hornboostspeed;

		if (PLAYER::IsPlayerPressingHorn(Features::playerme))
		{
			Vehicle Veh = PED::GetVehiclePedIsIn(PLAYER::GetPlayerPedScriptIndex(Features::playerme), false);
			NETWORK::NetworkRequestControlOfEntity(Veh);
			if (NETWORK::NetworkHasControlOfEntity(Veh))
			{
				if (Features::screeneffect)
					/*GRAPHICS::ANIMPOSTFX_PLAY("RaceTurbo", 0, 0);*/
					GRAPHICS::_StartScreenEffect(Features::nameEffect, 0, 0);
				if (Features::ptfxeffect == true) {
					Features::PTFXCALL2car("scr_rcbarry1", "scr_rcbarry1", "scr_alien_teleport");
					Features::PTFXCALL2car1("scr_rcbarry1", "scr_rcbarry1", "scr_alien_teleport");
				}
				/*if (Features::ptfx2car01 == true) {
					Features::PTFXCALL2car("scr_rcbarry2", "scr_rcbarry2", "scr_clown_appears");
					Features::PTFXCALL2car1("scr_rcbarry2", "scr_rcbarry2", "scr_clown_appears");
				}
				if (Features::ptfx2car02 == true) {
					Features::PTFXCALL2car("scr_indep_fireworks", "scr_indep_fireworks", "scr_indep_firework_trailburst");
					Features::PTFXCALL2car1("scr_indep_fireworks", "scr_indep_fireworks", "scr_indep_firework_trailburst");
				}
				if (Features::ptfx2car03 == true) {
					Features::PTFXCALL2car("proj_xmas_firework", "proj_xmas_firework", "scr_firework_xmas_burst_rgw");
					Features::PTFXCALL2car1("proj_xmas_firework", "proj_xmas_firework", "scr_firework_xmas_burst_rgw");
				}
				if (Features::ptfx2car04 == true) {
					Features::PTFXCALL2car("proj_xmas_firework", "proj_xmas_firework", "scr_firework_xmas_spiral_burst_rgw");
					Features::PTFXCALL2car1("proj_xmas_firework", "proj_xmas_firework", "scr_firework_xmas_spiral_burst_rgw");
				}
				if (Features::ptfx2car05 == true) {
					Features::PTFXCALL2car("scr_ornate_heist", "scr_ornate_heist", "scr_heist_ornate_banknotes");
					Features::PTFXCALL2car1("scr_ornate_heist", "scr_ornate_heist", "scr_heist_ornate_banknotes");
				}
				if (Features::ptfx2car06 == true) {
					Features::PTFXCALL2car("scr_fbi4", "scr_fbi4", "scr_fbi4_trucks_crash");
					Features::PTFXCALL2car1("scr_fbi4", "scr_fbi4", "scr_fbi4_trucks_crash");
				}
				if (Features::ptfx2car07 == true) {
					Features::PTFXCALL2car("scr_rcbarry1", "scr_rcbarry1", "scr_alien_disintegrate");
					Features::PTFXCALL2car1("scr_rcbarry1", "scr_rcbarry1", "scr_alien_disintegrate");
				}
				if (Features::ptfx2car08 == true) {
					Features::PTFXCALL2car("scr_agencyheistb", "scr_agencyheistb", "scr_agency3b_elec_box");
					Features::PTFXCALL2car1("scr_agencyheistb", "scr_agencyheistb", "scr_agency3b_elec_box");
				}
				if (Features::ptfx2car09 == true) {
					Features::PTFXCALL2car("scr_fbi5a", "scr_fbi5a", "scr_fbi5_ped_water_splash");
					Features::PTFXCALL2car1("scr_fbi5a", "scr_fbi5a", "scr_fbi5_ped_water_splash");
				}
				if (Features::ptfx2car12 == true) {
					Features::PTFXCALL2car("scr_martin1", "scr_martin1", "scr_sol1_sniper_impact");
					Features::PTFXCALL2car1("scr_martin1", "scr_martin1", "scr_sol1_sniper_impact");
				}
				if (Features::ptfx2car13 == true) {
					Features::PTFXCALL2car("core_snow", "core_snow", "cs_mich1_spade_dirt_throw");
					Features::PTFXCALL2car1("core_snow", "core_snow", "cs_mich1_spade_dirt_throw");
				}
				if (Features::ptfx2car14 == true) {
					Features::PTFXCALL2car("scr_michael2", "scr_michael2", "scr_mich2_blood_stab");
					Features::PTFXCALL2car1("scr_michael2", "scr_michael2", "scr_mich2_blood_stab");
				}
				if (Features::ptfx2car15 == true) {
					Features::PTFXCALL2car("scr_michael2", "scr_michael2", "scr_abattoir_ped_sliced");
					Features::PTFXCALL2car1("scr_michael2", "scr_michael2", "scr_abattoir_ped_sliced");
				}
				if (Features::ptfx2car16 == true) {
					Features::PTFXCALL2car("scr_rcpaparazzo1", "scr_rcpaparazzo1", "scr_rcpap1_camera");
					Features::PTFXCALL2car1("scr_rcpaparazzo1", "scr_rcpaparazzo1", "scr_rcpap1_camera");
				}
				if (Features::ptfx2car17 == true) {
					Features::PTFXCALL2car("scr_familyscenem", "scr_familyscenem", "scr_meth_pipe_smoke");
					Features::PTFXCALL2car1("scr_familyscenem", "scr_familyscenem", "scr_meth_pipe_smoke");
				}
				if (Features::ptfx2car18 == true) {
					Features::PTFXCALL2car("scr_reburials", "scr_reburials", "scr_burial_dirt");
					Features::PTFXCALL2car1("scr_reburials", "scr_reburials", "scr_burial_dirt");
				}*/
				AUDIO::SetVehicleBoostActive(Veh, 1);
				if (Features::maxspeed)
					ENTITY::SetEntityMaxSpeed(Veh, Features::maxspeedint);
				float curSpeed = ENTITY::GetEntitySpeed(Veh);
				if (Features::screeneffect)
					GRAPHICS::_StopScreenEffect(Features::nameEffect);
				/*GRAPHICS::ANIMPOSTFX_STOP("RaceTurbo");*/

				VEHICLE::SetVehicleForwardSpeed(Veh, curSpeed + Features::BOOSTLEVEL);
				/*Hooking::SET_VEHICLE_FORWARD_SPEED(Veh, curSpeed + BOOSTLEVEL);*/
				{
					AUDIO::SetVehicleBoostActive(Veh, 0);
				}
			}
		}
		else
			if (GetAsyncKeyState(0x33) || PAD::IsControlPressed(2, Menu2::BoostBackKey)) {
				Vehicle Veh = PED::GetVehiclePedIsIn(PLAYER::GetPlayerPedScriptIndex(Features::playerme), false);
				NETWORK::NetworkRequestControlOfEntity(Veh);
				if (NETWORK::NetworkHasControlOfEntity(Veh))
				{
					if (Features::ptfxeffect == true) {
						Features::PTFXCALL2car2("scr_rcbarry1", "scr_rcbarry1", "scr_alien_teleport");
						Features::PTFXCALL2car3("scr_rcbarry1", "scr_rcbarry1", "scr_alien_teleport");
					}
					/*if (Features::ptfx2car01 == true) {
						Features::PTFXCALL2car2("scr_rcbarry2", "scr_rcbarry2", "scr_clown_appears");
						Features::PTFXCALL2car3("scr_rcbarry2", "scr_rcbarry2", "scr_clown_appears");
					}
					if (Features::ptfx2car02 == true) {
						Features::PTFXCALL2car2("scr_indep_fireworks", "scr_indep_fireworks", "scr_indep_firework_trailburst");
						Features::PTFXCALL2car3("scr_indep_fireworks", "scr_indep_fireworks", "scr_indep_firework_trailburst");
					}
					if (Features::ptfx2car03 == true) {
						Features::PTFXCALL2car2("proj_xmas_firework", "proj_xmas_firework", "scr_firework_xmas_burst_rgw");
						Features::PTFXCALL2car3("proj_xmas_firework", "proj_xmas_firework", "scr_firework_xmas_burst_rgw");
					}
					if (Features::ptfx2car04 == true) {
						Features::PTFXCALL2car2("proj_xmas_firework", "proj_xmas_firework", "scr_firework_xmas_spiral_burst_rgw");
						Features::PTFXCALL2car3("proj_xmas_firework", "proj_xmas_firework", "scr_firework_xmas_spiral_burst_rgw");
					}
					if (Features::ptfx2car05 == true) {
						Features::PTFXCALL2car2("scr_ornate_heist", "scr_ornate_heist", "scr_heist_ornate_banknotes");
						Features::PTFXCALL2car3("scr_ornate_heist", "scr_ornate_heist", "scr_heist_ornate_banknotes");
					}
					if (Features::ptfx2car06 == true) {
						Features::PTFXCALL2car2("scr_fbi4", "scr_fbi4", "scr_fbi4_trucks_crash");
						Features::PTFXCALL2car3("scr_fbi4", "scr_fbi4", "scr_fbi4_trucks_crash");
					}
					if (Features::ptfx2car07 == true) {
						Features::PTFXCALL2car2("scr_rcbarry1", "scr_rcbarry1", "scr_alien_disintegrate");
						Features::PTFXCALL2car3("scr_rcbarry1", "scr_rcbarry1", "scr_alien_disintegrate");
					}
					if (Features::ptfx2car08 == true) {
						Features::PTFXCALL2car2("scr_agencyheistb", "scr_agencyheistb", "scr_agency3b_elec_box");
						Features::PTFXCALL2car3("scr_agencyheistb", "scr_agencyheistb", "scr_agency3b_elec_box");
					}
					if (Features::ptfx2car09 == true) {
						Features::PTFXCALL2car2("scr_fbi5a", "scr_fbi5a", "scr_fbi5_ped_water_splash");
						Features::PTFXCALL2car3("scr_fbi5a", "scr_fbi5a", "scr_fbi5_ped_water_splash");
					}
					if (Features::ptfx2car12 == true) {
						Features::PTFXCALL2car2("scr_martin1", "scr_martin1", "scr_sol1_sniper_impact");
						Features::PTFXCALL2car3("scr_martin1", "scr_martin1", "scr_sol1_sniper_impact");
					}
					if (Features::ptfx2car13 == true) {
						Features::PTFXCALL2car2("core_snow", "core_snow", "cs_mich1_spade_dirt_throw");
						Features::PTFXCALL2car3("core_snow", "core_snow", "cs_mich1_spade_dirt_throw");
					}
					if (Features::ptfx2car14 == true) {
						Features::PTFXCALL2car2("scr_michael2", "scr_michael2", "scr_mich2_blood_stab");
						Features::PTFXCALL2car3("scr_michael2", "scr_michael2", "scr_mich2_blood_stab");
					}
					if (Features::ptfx2car15 == true) {
						Features::PTFXCALL2car2("scr_michael2", "scr_michael2", "scr_abattoir_ped_sliced");
						Features::PTFXCALL2car3("scr_michael2", "scr_michael2", "scr_abattoir_ped_sliced");
					}
					if (Features::ptfx2car16 == true) {
						Features::PTFXCALL2car2("scr_rcpaparazzo1", "scr_rcpaparazzo1", "scr_rcpap1_camera");
						Features::PTFXCALL2car3("scr_rcpaparazzo1", "scr_rcpaparazzo1", "scr_rcpap1_camera");
					}
					if (Features::ptfx2car17 == true) {
						Features::PTFXCALL2car2("scr_familyscenem", "scr_familyscenem", "scr_meth_pipe_smoke");
						Features::PTFXCALL2car3("scr_familyscenem", "scr_familyscenem", "scr_meth_pipe_smoke");
					}
					if (Features::ptfx2car18 == true) {
						Features::PTFXCALL2car2("scr_reburials", "scr_reburials", "scr_burial_dirt");
						Features::PTFXCALL2car3("scr_reburials", "scr_reburials", "scr_burial_dirt");
					}*/
					if (Features::screeneffect)
						/*GRAPHICS::ANIMPOSTFX_PLAY("RaceTurbo", 0, 0);*/
						GRAPHICS::_StartScreenEffect(Features::nameEffect, 0, 0);
					AUDIO::SetVehicleBoostActive(Veh, 1);
					float curSpeed = ENTITY::GetEntitySpeed(Veh);

					VEHICLE::SetVehicleForwardSpeed(Veh, (curSpeed * -1.0f) - Features::BOOSTLEVEL);
					/*Hooking::SET_VEHICLE_FORWARD_SPEED(Veh, (curSpeed * -1.0f) - BOOSTLEVEL);*/
					if (Features::screeneffect)
						/*GRAPHICS::ANIMPOSTFX_STOP("RaceTurbo");*/
						GRAPHICS::_StopScreenEffect(Features::nameEffect);
					{
						AUDIO::SetVehicleBoostActive(Veh, 0);
					}
				}
			}
	}

	void AutoDrive() {
		GetEntityControl()->SimpleRequestControl(GetLocalPlayer().m_vehicle);
		if (VEHICLE::IsVehicleOnAllWheels(GetLocalPlayer().m_vehicle)) {
			Utils::ApplyForceToEntity(GetLocalPlayer().m_vehicle, 0.5f, 0, 0);
			AUDIO::SetVehicleBoostActive(GetLocalPlayer().m_vehicle, 0);
			VEHICLE::SetVehicleForwardSpeed(GetLocalPlayer().m_vehicle, vars.autodrivespeed);
		}
	}

	void LowerRideHeight() {
		if (!GetLocalPlayer().m_isInVehicle)return;
		Utils::ApplyForceToEntity(GetLocalPlayer().m_vehicle, 0, 0, -0.4f);
	}
	void DriftVehicle(int amount) {
		static int TIMER, drifting = 0;
		if ((vars.driftkeyController && PAD::IsDisabledControlPressed(0, vars.driftkey)) || KeyDown(vars.driftkey)) {
			Utils::DoTimedFunction(&TIMER, 2, [amount] {
				if (drifting > 10 - amount)VEHICLE::SetVehicleReduceGrip(GetLocalPlayer().m_vehicle, true);
				else VEHICLE::SetVehicleReduceGrip(GetLocalPlayer().m_vehicle, false);
				drifting++;
				if (drifting > 10) drifting = 0;
			});
		} else {
			VEHICLE::SetVehicleReduceGrip(GetLocalPlayer().m_vehicle, false);
		}
	}

	void UnlimitedVehicleBoost() {
		VEHICLE::_SetVehicleRocketBoostRefillTime(GetLocalPlayer().m_vehicle, 0.0f);
		if (VEHICLE::_IsVehicleRocketBoostActive(GetLocalPlayer().m_vehicle)) {
			VEHICLE::_SetVehicleRocketBoostPercentage(GetLocalPlayer().m_vehicle, 100);
		}
	}

	bool IsVehicleGoingForward(Vehicle vehicle) {
		Vector3 velocity = ENTITY::GetEntityVelocity(vehicle);
		Vector3 forwardVec = ENTITY::GetEntityForwardVector(vehicle);
		if ((forwardVec.y * velocity.y) + (forwardVec.x * velocity.x) > 0.2) return true;
		return false;
	}

	void SetVehicleBrakeForce(float brakePower) {
		if (KeyDown('S') || KeyDown(VK_SPACE) || PAD::IsControlPressed(0, INPUT_VEH_BRAKE)) {
			if (IsVehicleGoingForward(GetLocalPlayer().m_vehicle)) {
				GetEntityControl()->SimpleRequestControl(GetLocalPlayer().m_vehicle);
				Utils::ApplyForceToEntity(GetLocalPlayer().m_vehicle, 0, ((brakePower / 10) * -1), 0);
			}
		}
	}

	void SetDownforce(float downforce) {
		if (!ENTITY::IsEntityInAir(GetLocalPlayer().m_vehicle))Utils::ApplyForceToEntity(GetLocalPlayer().m_vehicle, 0, 0, -downforce);
	}

	void VehicleJump() {
		if (!GetLocalPlayer().m_isInVehicle)return;
		static int TIMER;
		Utils::DoTimedFunction(&TIMER, 50, [] {
			if (PAD::IsDisabledControlPressed(2, 203)) {
				ENTITY::ApplyForceToEntity(GetLocalPlayer().m_vehicle, 1, 0 + ENTITY::GetEntityForwardX(GetLocalPlayer().m_vehicle), 0 + ENTITY::GetEntityForwardY(GetLocalPlayer().m_vehicle), 7, 0, 0, 0, 1, 0, 1, 1, 1, 1);
			}
		});
	}

	//void HornBoost() {
	//	if (!GetLocalPlayer().m_isInVehicle)return;
	//	if (PLAYER::IsPlayerPressingHorn(GetLocalPlayer().m_id)) {
	//		AUDIO::SetVehicleBoostActive(GetLocalPlayer().m_vehicle, 1);
	//		VEHICLE::SetVehicleForwardSpeed(GetLocalPlayer().m_vehicle, ENTITY::GetEntitySpeed(GetLocalPlayer().m_vehicle) + 3);
	//		GRAPHICS::_StartScreenEffect("RaceTurbo", 0, 0);
	//	} else AUDIO::SetVehicleBoostActive(GetLocalPlayer().m_vehicle, 0);
	//}

	void FlyVehicle() {
		static bool check = false;
		if (!GetLocalPlayer().m_isInVehicle)return;
			Vector3 Rot = ENTITY::GetEntityRotation(GetLocalPlayer().m_vehicle, 2);
			float currentSpeed = ENTITY::GetEntitySpeed(GetLocalPlayer().m_vehicle);
			currentSpeed = currentSpeed * 4.2;
			int currentSpeedInt = (int)currentSpeed;
			if (check) {
				if (currentSpeedInt < 28 && PAD::IsControlPressed(0, INPUT_FRONTEND_RT))
					VEHICLE::SetVehicleGravity(GetLocalPlayer().m_vehicle, true);
				if (currentSpeedInt > 28 || !VEHICLE::IsVehicleOnAllWheels(GetLocalPlayer().m_vehicle)) {
					if (KeyDown(0x57)) {
						VEHICLE::SetVehicleGravity(GetLocalPlayer().m_vehicle, false);
						VEHICLE::SetVehicleForwardSpeed(GetLocalPlayer().m_vehicle, 80);
						ENTITY::FreezeEntityPosition(GetLocalPlayer().m_vehicle, false);
					}
					else {
						if (currentSpeedInt < 15 || KeyDown(VK_SPACE))
							ENTITY::FreezeEntityPosition(GetLocalPlayer().m_vehicle, true);
					}
					if (KeyDown(0x44)) {
						ENTITY::SetEntityRotation(GetLocalPlayer().m_vehicle, Rot.x, 0, Rot.z - 28 + 27.5, 1, 0);
					}
					else if (KeyDown(0x41)) {
						ENTITY::SetEntityRotation(GetLocalPlayer().m_vehicle, Rot.x, 0, Rot.z + 28 - 27.5, 1, 0);
					}
				}
				if (VEHICLE::IsVehicleOnAllWheels(GetLocalPlayer().m_vehicle))
					VEHICLE::SetVehicleGravity(GetLocalPlayer().m_vehicle, true), check = false;
			}
			if (KeyDown(VK_SHIFT) && VEHICLE::IsVehicleOnAllWheels(GetLocalPlayer().m_vehicle)) {
				ENTITY::SetEntityRotation(GetLocalPlayer().m_vehicle, Rot.x + 10, Rot.y, Rot.z, 1, 1);
				VEHICLE::SetVehicleForwardSpeed(GetLocalPlayer().m_vehicle, currentSpeedInt + 10);
				check = true;
			}
	}

	void CrateRide() {
		if (PED::IsPedOnAnyBike(GetLocalPlayer().m_ped)) {
			Vector3 Rotation = ENTITY::GetEntityRotation(GetLocalPlayer().m_vehicle, 1);
			Vector3 CurrentVehicleCoords = ENTITY::GetEntityCoords(GetLocalPlayer().m_vehicle, true);
			if (!ENTITY::DoesEntityExist(vars.crateriderent)) {
				vars.crateriderent = OBJECT::CreateObject(MISC::GetHashKey("prop_container_old1"), CurrentVehicleCoords.x, CurrentVehicleCoords.y, CurrentVehicleCoords.z - 1.910, true, false, false);
			}
			else {
				GetEntityControl()->SimpleRequestControl(vars.crateriderent);
				if (!VEHICLE::IsVehicleOnAllWheels(GetLocalPlayer().m_vehicle)) {
					ENTITY::SetEntityCoords(vars.crateriderent, CurrentVehicleCoords.x, CurrentVehicleCoords.y, CurrentVehicleCoords.z - 1.910, true, true, true, true);
					ENTITY::SetEntityRotation(vars.crateriderent, Rotation.x, Rotation.y, Rotation.z, 1, true);
				}
			}
		}
	}

	void Wheelie() {
		if (!GetLocalPlayer().m_isInVehicle)return;
		if (PAD::IsDisabledControlPressed(0, INPUT_FRONTEND_X)) {
			Vector3 Rotation = ENTITY::GetEntityRotation(GetLocalPlayer().m_vehicle, false);
			ENTITY::SetEntityRotation(GetLocalPlayer().m_vehicle, Rotation.x + 0.5f, Rotation.y, Rotation.z, 2, 1);
		}
	}

	void DriveOnWalls() {
		if (GetLocalPlayer().m_isInVehicle) ENTITY::ApplyForceToEntity(GetLocalPlayer().m_vehicle, 1, 0, 0, -0.4f, 0, 0, 0, false, true, true, true, false, true);
	}

#define IsKeyPressed(key) GetAsyncKeyState(key) & 0x8000

	bool FlyModeControlsPressed() {
		if (IsKeyPressed(VK_KEY_W) || PAD::IsDisabledControlJustPressed(2, 269) || PAD::IsControlPressed(0, INPUT_FRONTEND_RT)) {
			return true;
		}
		if (IsKeyPressed(VK_KEY_S) || PAD::IsDisabledControlJustPressed(2, 268) || PAD::IsControlPressed(0, INPUT_FRONTEND_LT)) {
			return true;
		}
		if (IsKeyPressed(VK_SHIFT) || PAD::IsDisabledControlJustPressed(2, 206)) {
			return true;
		}
		if (IsKeyPressed(VK_SPACE) || PAD::IsDisabledControlJustPressed(2, 205)) {
			return true;
		}
		return false;
	}

	void BasicFlyMode() {
		if (GetLocalPlayer().m_isInVehicle) {
			Vector3 PlayerPos = GetLocalPlayer().m_coordinates;
			Vector3 Rotation = CAM::GetGameplayCamRot(0);
			ENTITY::SetEntityRotation(GetLocalPlayer().m_vehicle, Rotation.x, Rotation.y, Rotation.z, 0, true);
			if (!FlyModeControlsPressed()) {
				VEHICLE::SetVehicleForwardSpeed(GetLocalPlayer().m_vehicle, 0);
				VEHICLE::SetVehicleFixed(GetLocalPlayer().m_vehicle);
				VEHICLE::SetVehicleForwardSpeed(GetLocalPlayer().m_vehicle, 0);
			}
			if (IsKeyPressed(VK_KEY_W) || PAD::IsDisabledControlJustPressed(2, 269) || PAD::IsControlPressed(0, INPUT_FRONTEND_RT)) {
				VEHICLE::SetVehicleForwardSpeed(GetLocalPlayer().m_vehicle, vars.basicflyspeed);
			}
			if (IsKeyPressed(VK_KEY_S) || PAD::IsDisabledControlJustPressed(2, 268) || PAD::IsControlPressed(0, INPUT_FRONTEND_LT)) {
				VEHICLE::SetVehicleForwardSpeed(GetLocalPlayer().m_vehicle, (-vars.basicflyspeed));
			}
		}
	}

	void DriveOnWater() {
		float waterHeight = 0;
		Vector3 coords = GetLocalPlayer().m_coordinates;
		WATER::GetWaterHeight(coords.x, coords.y, coords.z, &waterHeight);

		Vector3 adjustedCoords = { coords.x, coords.y, waterHeight - 2 };

		if (coords.z - waterHeight <= 3) {
			if (!ENTITY::DoesEntityExist(vars.driveonwaterobject)) {
				if (!STREAMING::HasModelLoaded(-1003748966)) {
					GetEntityControl()->SimpleRequestModel(-1003748966);
				} else {
					vars.driveonwaterobject = OBJECT::CreateObject(-1003748966, coords.x, coords.y, coords.z, true, false, false);
					STREAMING::SetModelAsNoLongerNeeded(-1003748966);
				}
			}
			ENTITY::FreezeEntityPosition(vars.driveonwaterobject, true);
			Vector3 ROT = { 180, 90, 180 };
			ENTITY::SetEntityRotation(vars.driveonwaterobject, ROT.x, ROT.y, ROT.z, 2, 1);
			ENTITY::SetEntityCoords(vars.driveonwaterobject, adjustedCoords.x, adjustedCoords.y, adjustedCoords.z, false, false, false, false);
			ENTITY::SetEntityVisible(vars.driveonwaterobject, false, 1);
		}
	}

}

void VehicleMovementMenu::Init() {
	setParentSubmenu<VehicleMenu>();
	setName("Vehicle movement", true, true);

	addOption(ToggleOption("Vehicle jump")
		.addToggle(vars.jump)
		.addHotkey().canBeSaved().addTranslation()
		.addTooltip("Vehicle jump"));

	addOption(ToggleOption("Basic fly vehicle")
		.addToggle(vars.basicflyingvehicle)
		.addHotkey().canBeSaved().addTranslation()
		.addTooltip("W to go forward / S to go backward / Mouse to control direction"));

	addOption(NumberOption<float>(SCROLL, "Basic fly speed")
		.addNumber(vars.basicflyspeed, "%.2f", 5.0f).addMin(10.0f).addMax(100.0f)
		.addHotkey().canBeSaved().addTranslation()
		.addTooltip("Set the basic fly speed"));

	addOption(ToggleOption("Precise fly vehicle")
		.addToggle(vars.flyingvehicle)
		.addHotkey().canBeSaved().addTranslation()
		.addTooltip("Shift start - W forward - A/D to rotate - CTRL/SHIFT to tilt - Space to freeze"));

	addOption(BreakOption("Vehicle speed").addTranslation());

	addOption(ToggleOption("Speed vehicle")
		.addToggle(vars.fly)
		.addHotkey().canBeSaved().addTranslation()
		.addTooltip("Speed your vehicle using numpad 9 and number 3 || RT and LT"));

	addOption(NumberOption<int>(SCROLL, "Speed")
		.addNumber(vars.flyspeed, "%d", 1).addMin(1).addMax(50)
		.addHotkey().canBeSaved().addTranslation()
		.addTooltip("Set the speed"));

	addOption(BreakOption("Boosting").addTranslation());

	addOption(ToggleOption("Horn boost")
		.addToggle(vars.hornboost)
		.addHotkey().canBeSaved().addTranslation()
		.addTooltip("Boost on horning"));

	addOption(NumberOption<int>(SCROLL, "Horn boost speed")
		.addNumber(vars.hornboostspeed, "%d", 1).addMin(1).addMax(1000)
		.addHotkey().canBeSaved().addTranslation()
		.addTooltip("Set the speed of the horn boost"));

	addOption(ToggleOption("Effect Boost")
		.addToggle(vars.effectboost)
		.addHotkey().canBeSaved().addTranslation()
		/*.addTooltip("")*/);

	addOption(ToggleOption("Ptfx Boost")
		.addToggle(vars.ptfxboost)
		.addHotkey().canBeSaved().addTranslation()
		/*.addTooltip("")*/);

	addOption(ToggleOption("Infinite Boost")
		.addToggle(vars.unlimitedboost)
		.addHotkey().canBeSaved().addTranslation()
		.addTooltip("Unlimited boost ~c~(R. voltic, Opressor)"));

	addOption(BreakOption("Force").addTranslation());

	addOption(NumberOption<int>(SCROLL, "Brake force")
		.addNumber(vars.brakeforce, "%d", 1).addMin(0).addMax(10)
		.addHotkey().canBeSaved().addTranslation()
		.addTooltip("Set the vehicles brake force"));

	addOption(NumberOption<float>(SCROLL, "Downforce")
		.addNumber(vars.downforce, "%.2f", 0.05f).addMin(-2).addMax(2)
		.addHotkey().canBeSaved().addTranslation()
		.addTooltip("Set the vehicles downforce"));

	addOption(ToggleOption("Lower ride height")
		.addToggle(vars.lowerrideheight)
		.addHotkey().canBeSaved().addTranslation()
		.addTooltip("Lower ride height"));

	addOption(BreakOption("Autodrive").addTranslation());

	addOption(ToggleOption("Auto drive")
		.addToggle(vars.autodrive)
		.addHotkey().canBeSaved().addTranslation()
		.addTooltip("Auto drive"));

	addOption(NumberOption<int>(SCROLL, "Autodrive speed")
		.addNumber(vars.autodrivespeed, "%d", 1).addMin(5).addMax(1000)
		.addTooltip("Autodrive").addTranslation());

	addOption(BreakOption("Drifting").addTranslation());

	addOption(ToggleOption("Drift")
		.addToggle(vars.drift)
		.addHotkey().canBeSaved().addTranslation()
		.addTooltip("Vehicle drifting"));

	addOption(NumberOption<int>(SCROLL, "Drift amount")
		.addNumber(vars.driftamount, "%d", 1).addMin(1).addMax(10)
		.addHotkey().canBeSaved().addTranslation()
		.addTooltip("Set the drift amount"));

	addOption(KeyOption("Drift key")
		.addKeyWithControllerSupport(vars.driftkey, vars.driftkeyController)
		.canBeSaved().addHotkey().addTranslation()
		.addTooltip("Set the drift key"));

	addOption(BreakOption("Limits").addTranslation());

	addOption(ToggleOption("Bypass max speed")
		.addToggle(vars.bypassmaxspeed)
		.addHotkey().canBeSaved().addTranslation()
		.addTooltip("Bypass max speed"));

	addOption(NumberOption<float>(TOGGLE, "Limit vehicle speed")
		.addToggle(vars.speedlimit)
		.addNumber(vars.speedlimitamount, "%.1f", 0.5f).addMin(1).addMax(300)
		.addFunction([] {LimitMaxSpeed(vars.speedlimit, 0); })
		.addHotkey().canBeSaved().addTranslation()
		.addTooltip("Limit the maximum vehicle speed"));

	addOption(BreakOption("Misc").addTranslation());

	addOption(ToggleOption("Bike crate rider")
		.addToggle(vars.craterider)
		.addHotkey().canBeSaved().addTranslation()
		.addTooltip("Make sure to be on a bike, then angle it to ride"));

	addOption(ToggleOption("Wheelie")
		.addToggle(vars.wheelie)
		.addHotkey().canBeSaved().addTranslation()
		.addTooltip("Wheelie"));

	addOption(ToggleOption("Drive on walls")
		.addToggle(vars.driveonwalls)
		.addHotkey().canBeSaved().addTranslation()
		.addTooltip("Drive on walls"));

	addOption(ToggleOption("Drive on water")
		.addToggle(vars.driveonwater)
		.addHotkey().canBeSaved().addTranslation()
		.addTooltip("Drive on water"));
}

/*Update once when submenu is opened*/
void VehicleMovementMenu::UpdateOnce() {}

/*Update while submenu is active*/
void VehicleMovementMenu::Update() {}

/*Background update*/
void VehicleMovementMenu::FeatureUpdate() {
	if (GetLocalPlayer().m_isInVehicle && VEHICLE::GetPedInVehicleSeat(GetLocalPlayer().m_vehicle, -1, 1) == GetLocalPlayer().m_ped) {
		if (vars.bypassmaxspeed)BypassMaxSpeed();
		if (vars.speedlimit)LimitMaxSpeed(vars.speedlimit, vars.speedlimitamount);
		if (vars.fly) FlyVehicle(vars.flyspeed);
		if (vars.hornboost)HornBoost(vars.hornboostspeed);
		if (vars.drift)DriftVehicle(static_cast<int>(vars.driftamount));
		if (vars.unlimitedboost)UnlimitedVehicleBoost();
		if (vars.brakeforce != 0)SetVehicleBrakeForce(vars.brakeforce);
		if (vars.downforce != 0)SetDownforce(vars.downforce);
		if (vars.jump) VehicleJump();
		if (vars.wheelie) Wheelie();
		if (vars.autodrive) AutoDrive();
		if (vars.driveonwalls) DriveOnWalls();
		if (vars.driveonwater) DriveOnWater();
		if (vars.craterider) CrateRide();
		if (vars.lowerrideheight) LowerRideHeight();
		if (vars.flyingvehicle) FlyVehicle();
		if (vars.basicflyingvehicle) BasicFlyMode();
	}
}

/*Singleton*/
VehicleMovementMenu* _instance;
VehicleMovementMenu* VehicleMovementMenu::GetInstance() {
	if (_instance == nullptr) {
		_instance = new VehicleMovementMenu();
		_instance->Init();
		GetSubmenuHandler()->addSubmenu(_instance);
	}
	return _instance;
}
VehicleMovementMenu::~VehicleMovementMenu() { delete _instance; }