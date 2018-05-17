#pragma once

#include "Utility.h"

#include <stdexcept>
#include <memory>
#include <vector>
#include <set>


namespace eng
{

	class Gamestate : public Iterated<int, unit>
	{
		
		static std::unique_ptr<Gamestate> s_instance;
		
		//std::vector< Planet > m_planets;
		//std::vector< Player > m_players;

		Gamestate();// throws if a Gamestate already exists

	public:

		static Gamestate& instance()
		{
			if (!s_instance)
				s_instance = std::make_unique<Gamestate>();
			return *s_instance;
		}
	
		Gamestate(const Gamestate&) = delete;
		Gamestate& operator=(const Gamestate&) = delete;

		//Lookups
		Player& getPlayer(const Faction& value);
		Zone& getZone(const Place& address);
		Planet& getPlanet(const Place& address);
		Planet& getPlanet(int planetNumber);
		Unit& getUnit(int identifier);

		//Insertion
		bool addUnit(const Unit& addition);
		bool addPlanet(const Planet& addition);


	};

	Gamestate& game() {return Gamestate::instance();}

	std::unique_ptr<Gamestate> Gamestate::s_instance = nullptr;

}