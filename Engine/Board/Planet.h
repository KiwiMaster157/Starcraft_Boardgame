#pragma once

#include <SFML/System.hpp>

#include "../Utility.h"
#include "../Owned.h"
#include "../Gamestate.h"

#include "Navigation.h"
#include "Zone.h"

#include <deque>
#include <string>

namespace eng
{

	constexpr int PLANET_MAX_SIDE = 4;
	
	class Planet : public PlacedObject
	{
		sf::Vector2i m_position;
		std::string m_name;

		int m_zoneCount;
		bool m_locked;

		Zone m_zones[PLANET_MAX_SIDE];
		navRoute m_navs[PLANET_MAX_SIDE];

		std::deque<token> m_tokens;

	public:

		//Construction
		Planet(const Place& p, const std::string& name, const sf::Vector2i& position);

		bool addZone(int cap, const Resource& r, char navAccess);
		bool addNavigation(int direction);

		//lock() will prevent addZone() and addNavigation() from doing anything
		void lock();

		bool disconnectNavRoute(const navRoute& nav);
		bool connectNavRoute(const navRoute& nav);

		//Will not check for correct planet
		Zone& getZone(const Place& p);
		const Zone& getZone(const Place& p) const;

		navRoute& getNav(const Place& p);
		const navRoute& getNav(const Place& p) const;

		int zoneCount() const;
		const std::string& name() const;
		const sf::Vector2i& position() const;

		//Counts total tokens on planet
		int tokenCount() const;

		//Counts tokens on planet owned by a given player
		int tokenCount(const Faction& f) const;

		void tokenPush(const token& t);
		bool tokenPop();
		const ActionToken& tokenTop() const;

		bool hasBase(const Faction& f) const;

	};

}