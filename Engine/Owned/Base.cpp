#include "Base.h"

namespace eng
{
	Base::Base(const Faction& f, const Place& p)
		: OwnedObject(f, false), PlacedObject(p, true)
	{
		m_status = Status::Destroyed;
	}

	Base::Status Base::status() const
	{
		return m_status;
	}

	bool Base::exists() const
	{
		return m_status != Status::Destroyed;
	}

	bool Base::isFinished() const
	{
		return m_status == Status::Finished;
	}

	bool Base::destroy()
	{
		Status temp = m_status;
		factionExchange(Faction::None);
		m_status = Status::Destroyed;
		return m_status != Status::Destroyed;
	}

	bool Base::start(const Faction& f)
	{
		if (exists()) return false;
		factionExchange(f);
		m_status = Status::Incomplete;
		return true;
	}

	bool Base::finish()
	{
		if (m_status == Status::Incomplete)
		{
			m_status = Status::Finished;
			return true;
		}
		return false;
	}
}