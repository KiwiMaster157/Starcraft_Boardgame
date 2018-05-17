#include "Planet.h"

namespace eng
{
	Planet::Planet(const Place& p, const std::string& name, const sf::Vector2i& position)
		: PlacedObject(p)
	{
		m_locked = false;
		m_position = position;
		m_name = name;
		m_zoneCount = 0;
	}

	bool Planet::addZone(int cap, const Resource& r, char navAccess)
	{
		if (m_zoneCount >= 4 || !m_locked) return false;

		m_zones[m_zoneCount] = Zone(Place(place().planet(), m_zoneCount), cap, r, navAccess);
		
		m_zoneCount++;
		return true;
	}

	bool Planet::addNavigation(int direction)
	{
		if (!m_locked) return false;
		if (0 <= direction && direction < 4)
		{
			bool temp = m_navs[direction].exists;
			m_navs[direction].exists = true;
			return !temp;
		}
		return false;
	}

	void Planet::lock()
	{
		m_locked = true;
	}

	bool Planet::disconnectNavRoute(const navRoute& nav)
	{
		for (bool i = false; !i; i = true)
		{	
			navRoute& route = m_navs[nav->end(i).side()];
			if (*nav == *route)
			{
				route.connected = false;
				route.ptr.reset();
				return true;
			}
		}
		return false;
	}

	bool Planet::connectNavRoute(const navRoute& nav)
	{
		for (bool i = false; !i; i = true)
		{
			navRoute& route = m_navs[nav->end(i).side()];
			if (nav->end(i).planet() == place().planet()
				&& route.exists && !route.connected)
			{
				route.connected = true;
				route.ptr = nav.ptr;
				return true;
			}
		}
		return false;
	}

	Zone& Planet::getZone(const Place& p)
	{
		return m_zones[p.side()];
	}

	const Zone& Planet::getZone(const Place& p) const
	{
		return m_zones[p.side()];
	}

	navRoute& Planet::getNav(const Place& p)
	{
		return m_navs[p.side()];
	}

	const navRoute& Planet::getNav(const Place& p) const
	{
		return m_navs[p.side()];
	}

	int Planet::zoneCount() const
	{
		return m_zoneCount;
	}

	const std::string& Planet::name() const
	{
		return m_name;
	}

	const sf::Vector2i& Planet::position() const
	{
		return m_position;
	}

	int Planet::tokenCount() const
	{
		return m_tokens.size();
	}

	int Planet::tokenCount(const Faction& f) const
	{
		int counter = 0;
		for (auto i : m_tokens)
			counter += (i->faction() == f);
		return counter;
	}

	void Planet::tokenPush(const token& t)
	{
		m_tokens.emplace_back(t);
	}

	bool Planet::tokenPop()
	{
		if (m_tokens.empty()) return false;

		m_tokens.pop_back();
		return true;
	}

	const ActionToken& Planet::tokenTop() const
	{
		return *m_tokens.back();
	}

	bool Planet::hasBase(const Faction& f) const
	{
		for (int i = 0; i < m_zoneCount; i++)
			if (m_zones[i].getBase().faction() == f)
				return true;
		return false;
	}

}