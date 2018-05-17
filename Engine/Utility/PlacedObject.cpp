#include "PlacedObject.h"
#include "../Gamestate.h"

namespace eng
{
	PlacedObject::PlacedObject(Place p, bool locked)
	{
		m_place = p;
		m_p_locked = locked;
	}

	const Place& PlacedObject::place() const
	{
		return m_place;
	}

	Zone& PlacedObject::zone() const
	{
		return game().getZone(m_place);
	}

	Planet& PlacedObject::planet() const
	{
		return game().getPlanet(m_place);
	}

	bool PlacedObject::placeMove(Place p)
	{
		if (!m_p_locked)
			m_place = p;
		return !m_p_locked;
	}

	void PlacedObject::placeLock()
	{
		m_p_locked = true;
	}

	void PlacedObject::placeUnlock()
	{
		m_p_locked = false;
	}

	bool PlacedObject::isPlaceLocked() const
	{
		return m_p_locked;
	}

}//namespace eng