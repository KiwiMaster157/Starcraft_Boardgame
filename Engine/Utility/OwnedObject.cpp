#include "OwnedObject.h"
#include "../Gamestate.h"

namespace eng
{
	
	OwnedObject::OwnedObject(Faction f, bool locked)
	{
		m_faction = f;
		m_f_locked = locked;
	}

	const Faction& OwnedObject::faction() const
	{
		return m_faction;
	}

	Player& OwnedObject::player() const
	{
		return game().getPlayer(m_faction);
	}

	void OwnedObject::factionLock()
	{
		m_f_locked = true;
	}

	void OwnedObject::factionUnlock()
	{
		m_f_locked = false;
	}

	bool OwnedObject::isFactionLocked() const
	{
		return m_f_locked;
	}

	bool OwnedObject::factionExchange(Faction f)
	{
		if (!m_f_locked)
			m_faction = f;

		return !m_f_locked;
	}

}//namespace eng