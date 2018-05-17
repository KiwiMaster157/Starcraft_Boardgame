#pragma once

#include "../Utility.h"


namespace eng
{

	class Unit : public OwnedObject, public PlacedObject
	{
	public:
		class Type
		{
			int m_id;

		public:

			enum DefaultUnitList
			{
				All = -1,
				None = 0
			};

			Type(DefaultUnitList dul = DefaultUnitList::None);
			Type(int value);

			int value() const;
		};

		static bool spawn(
			Faction f = Faction::DefaultFactionList::None,
			Place p = Place::DefaultPlaceList::None,
			Type t = Type::DefaultUnitList::None);

		const Type& type() const;
		int identifier() const;

		bool move(Place p);
		bool kill();

	private:
		Type m_type;
		int m_number;

		//Private constructor
		Unit(int identity,
			Faction f = Faction::DefaultFactionList::None,
			Place p = Place::DefaultPlaceList::None,
			Type t = Type::DefaultUnitList::None);

	};

	bool operator==(Unit::Type lhs, Unit::Type rhs);
	bool operator!=(Unit::Type lhs, Unit::Type rhs);

	using unit = std::shared_ptr<Unit>;

}//namespace eng