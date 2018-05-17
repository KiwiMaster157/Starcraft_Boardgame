#include "Faction.h"

namespace eng
{
	Faction::Faction(Faction::DefaultFactionList dfl)
	{
		m_id = int(dfl);
	}

	Faction::Faction(int value)
	{
		m_id = value;
	}

	int Faction::value() const
	{
		return m_id;
	}

	bool operator==(Faction lhs, Faction rhs)
	{
		return lhs.value() == rhs.value();
	}

	bool operator!=(Faction lhs, Faction rhs)
	{
		return !(lhs == rhs);
	}

}//namespace eng