#include "Place.h"
#include <stdexcept>
#include <string>

namespace eng
{
	Place::Place(Place::DefaultPlaceList dpl)
	{
		m_data = int(dpl);
	}

	Place::Place(int planet, int side)
	{
		if (side > 3 || side < 0)
			throw std::range_error("Place side must be in [0, 3].");
		
		m_data = (planet << 2) | side;
	}

	Place::Place(int value)
	{
		m_data = value;
	}

	int Place::side() const
	{
		return m_data & 0x03;
	}

	int Place::planet() const
	{
		return m_data >> 2;
	}

	void Place::setSide(int value)
	{
		if (value > 3 || value < 0)
			throw std::range_error("Place side must be in [0, 3].");
		
		m_data &= ~0x03;
		m_data |= value;
	}

	void Place::setPlanet(int value)
	{
		m_data &= 0x03;
		m_data |= (value << 2);
	}

	bool operator==(Place lhs, Place rhs)
	{
		return lhs.m_data == rhs.m_data;
	}

	bool operator!=(Place lhs, Place rhs)
	{
		return !(lhs == rhs);
	}

}//namespace eng