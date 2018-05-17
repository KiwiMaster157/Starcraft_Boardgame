#include "Unit.h"
#include "../Gamestate.h"

namespace eng
{
	//Class Unit::Type

	Unit::Type::Type(Type::DefaultUnitList dul)
	{
		m_id = dul;
	}

	Unit::Type::Type(int value)
	{
		m_id = value;
	}

	int Unit::Type::value() const
	{
		return m_id;
	}

	//Class Unit

	//Private constructor
	Unit::Unit(int identity, Faction f, Place p, Type t)
		: OwnedObject(f), PlacedObject(p)
	{
		m_type = t;
		m_number = identity;
	}

	//Static member
	bool Unit::spawn(Faction f, Place p, Type t)
	{
		static int next_id(0);

		next_id++;

		return game().addUnit(Unit(next_id, f, p, t));
	}

	const Unit::Type& Unit::type() const
	{
		return m_type;
	}

	int Unit::identifier() const
	{
		return m_number;
	}

	bool Unit::move(Place p)
	{
		//Check if move is valid
		// i.e. within a planet || planets are adjacent && bridge is passable
		
		if (placeMove(p))
		{
			//Move unit between zones
		}

		return false;
	}

	bool Unit::kill()
	{
		//Remove ptr in gamestate, player, and zone
		return true;
	}

	//Non-member overloads

	bool operator==(Unit::Type lhs, Unit::Type rhs)
	{
		return lhs.value() == rhs.value();
	}

	bool operator!=(Unit::Type lhs, Unit::Type rhs)
	{
		return !(lhs == rhs);
	}
}//namespace eng