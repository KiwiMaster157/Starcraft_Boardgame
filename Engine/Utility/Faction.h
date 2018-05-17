#pragma once

namespace eng
{
	class Faction
	{
		int m_id;

	public:

		enum DefaultFactionList
		{
			All = -1,
			None = 0
		};

		Faction(DefaultFactionList dfl = DefaultFactionList::None);
		Faction(int value);

		int value() const;
	};

	bool operator==(Faction lhs, Faction rhs);
	bool operator!=(Faction lhs, Faction rhs);
}