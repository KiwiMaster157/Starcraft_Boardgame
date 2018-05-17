#include "Zone.h"

namespace eng
{
	Zone::Zone()
		: m_base(Faction::None, Place::None)
	{
		m_resource = nullptr;
		m_navAccess = 0;
	}

	//default: navAccess = 0
	Zone::Zone(const Place& p, int cap, const Resource& r, char navAccess)
		: PlacedObject(p), m_base(Faction::None, p)
	{
		m_capacity = cap;
		m_resource = std::make_shared<Resource>(r);
		m_navAccess = navAccess;
	}

	Faction Zone::inControl() const
	{
		if (isEmpty())
			return Faction::None;
		return m_ittData.begin()->second->faction();
	}

	const Resource& Zone::resources() const
	{
		return *m_resource;
	}

	bool Zone::exists() const
	{
		return m_resource != nullptr;
	}

	Resource& Zone::resources()
	{
		return *m_resource;
	}

	bool Zone::grantAccess(int i)
	{
		if (i >= 0 && i < 4)
		{
			m_navAccess |= (1 << i);
			return true;
		}
		return false;
	}

	bool Zone::grantAccess(const Place& p)
	{
		if (p.planet() == place().planet())
			return grantAccess(p.side());
		return false;
	}

	bool Zone::revokeAccess(int i)
	{
		if (i >= 0 && i < 4)
		{
			m_navAccess &= ~(1 << i);
			return true;
		}
		return false;
	}

	bool Zone::revokeAccess(const Place& p)
	{
		if (p.planet() == place().planet())
			return revokeAccess(p.side());
		return false;
	}

	char Zone::navAccess() const
	{
		return m_navAccess;
	}

	bool Zone::navAccess(int i) const
	{
		if(i >= 0 && i < 4)
			return m_navAccess & (1 << i);
		return false;
	}

	bool Zone::navAccess(const Place& p) const
	{
		return navAccess(p.side()) && p.planet() == place().planet();
	}

	int Zone::count() const
	{
		return m_ittData.size();
	}

	bool Zone::isFull() const
	{
		return count() == m_capacity;
	}

	bool Zone::isEmpty() const
	{
		return m_ittData.empty();
	}

	bool Zone::destroyBase()
	{
		return m_base.destroy();
	}

	bool Zone::buildBase()
	{
		return buildBase(inControl());
	}

	bool Zone::buildBase(const Faction& f)
	{
		return m_base.start(f);
	}

	bool Zone::finishBase()
	{
		return m_base.finish();
	}

	const Base& Zone::getBase() const
	{
		return m_base;
	}

	bool Zone::remove(int identifier)
	{
		if (m_ittData.count(identifier)>0)
		{
			m_ittData.erase(identifier);
			return true;
		}
		return false;
	}

	bool Zone::remove(const unit& u)
	{
		return remove(u->identifier());
	}

	bool Zone::insert(const unit& u)
	{
		if (!m_ittData.count(u->identifier()))
		{
			m_ittData.emplace(u->identifier(), u);
			return true;
		}
		return false;
	}

	bool operator==(const Zone& lhs, const Zone& rhs)
	{
		return lhs.place() == rhs.place();
	}

	bool operator!=(const Zone& lhs, const Zone& rhs)
	{
		return !(lhs == rhs);
	}

}//namespace eng