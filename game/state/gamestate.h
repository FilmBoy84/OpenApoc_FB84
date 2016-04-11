#pragma once
#include "library/sp.h"

#include "game/state/agent.h"
#include "game/state/base/base.h"
#include "game/state/city/city.h"
#include "game/state/organisation.h"
#include "game/state/research.h"
#include "game/state/rules/doodad_type.h"
#include "game/state/rules/facility_type.h"
#include "game/state/rules/vehicle_type.h"
#include "game/state/rules/vequipment.h"
#include "game/state/stateobject.h"
#include "game/state/ufopaedia.h"
#include "library/strings.h"
#include <random>

namespace OpenApoc
{

class City;
class Base;

static const unsigned TICKS_PER_SECOND = 60;

class GameState
{
  public:
	std::map<UString, sp<VehicleType>> vehicle_types;
	std::map<UString, sp<Organisation>> organisations;
	std::map<UString, sp<FacilityType>> facility_types;
	std::map<UString, sp<DoodadType>> doodad_types;
	std::map<UString, sp<VEquipmentType>> vehicle_equipment;
	std::map<UString, sp<BaseLayout>> base_layouts;
	std::map<UString, sp<Base>> player_bases;
	std::map<UString, sp<City>> cities;
	std::map<UString, sp<Vehicle>> vehicles;
	std::map<UString, sp<UfopaediaCategory>> ufopaedia;
	std::map<UString, sp<ResearchTopic>> research;

	std::map<UString, sp<Agent>> agents;
	AgentGenerator agent_generator;

	std::map<Agent::Type, unsigned> initial_agents;
	std::map<UString, unsigned> initial_facilities;

	StateRef<Organisation> player;

	GameState();
	~GameState();

	bool showTileOrigin;
	bool showVehiclePath;
	bool showSelectableBounds;

	std::default_random_engine rng;

	UString getPlayerBalance() const;
	StateRef<Organisation> getOrganisation(const UString &orgID);
	StateRef<Organisation> getPlayer() const;

	// The time from game start in ticks
	// FIXME: Is a 32bit val enough?
	// That should be 60ticks/sec 60secs/min 60mins/hour 24hours/day 7days/week = 118 weeks?
	unsigned int time;

	bool loadGame(const UString &path);
	bool saveGame(const UString &path, bool pack = true);

	// Called on a newly started Game to setup initial state that isn't serialized in (random
	// vehicle positions etc.) - it is not called
	void startGame();
	// Called after serializing in to hook up 'secondary' data (stuff that is derived from stuff
	// that is serialized but not serialized itself). This should also be called on starting a new
	// game after startGame()
	void initState();
};

}; // namespace OpenApoc