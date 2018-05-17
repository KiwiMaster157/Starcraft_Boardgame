#include "Resource.h"
#include "../Gamestate.h"

namespace eng
{
	Resource::Resource(Resource::ResourceType rType, int qty, const Place& p)
		: OwnedObject(Faction::None, false), PlacedObject(p, true)
	{
		m_type = rType;
		m_count = qty;
		m_depl = Depletion::None;
	}

	Resource::ResourceType Resource::type() const
	{
		return m_type;
	}

	int Resource::count() const
	{
		return m_count;
	}

	int Resource::usableCount() const
	{
		return usable() ? m_count : 0;
	}

	Resource::Depletion Resource::status() const
	{
		return m_depl;
	}

	bool Resource::usable() const
	{
		return m_depl != Depletion::Full;
	}

	bool Resource::deplete()
	{
		if (m_type == ResourceType::Conquest || m_type == ResourceType::None)
			return false;
		if (m_depl == Depletion::Full)
			return false;
		else if (m_depl == Depletion::Partial)
			m_depl = Depletion::Full;
		else //== None
			m_depl = Depletion::Partial;
		return true;
	}

	bool Resource::undeplete()
	{
		if (m_type == ResourceType::Conquest || m_type == ResourceType::None)
			return false;
		if (m_depl == Depletion::None)
			return false;
		else if (m_depl == Depletion::Partial)
			m_depl = Depletion::None;
		else //== Full
			m_depl = Depletion::Partial;
		return true;
	}

	bool Resource::exchange(const Faction& f)
	{
		//if(f exists)
		//Take from current player
		//Give to player f via gamestate
		
		factionExchange(f);
		return true;
		//else

		return false;
	}

}//namespace eng