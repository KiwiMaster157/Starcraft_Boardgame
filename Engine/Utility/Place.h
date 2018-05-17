#pragma once


namespace eng
{
	/*
	Place holds the address of a zone or object.
	The last 2 bits of m_data are the side, the rest of the bits are the planet.
	Use Gamestate::zone() or Gamestate::planet() to access referenced location.
	
	Planet = 0 -> None
	Planet < 0 -> Any

	Side numbers start at North + epsilon.
	*/

	class Place
	{
		int m_data;

	public:

		enum DefaultPlaceList
		{
			None = 0
		};

		Place(DefaultPlaceList dpl = DefaultPlaceList::None);
		
		//Use Place(#, 0) to specify just a planet.
		Place(int planet, int side);
		explicit Place(int value);

		int side() const;
		int planet() const;

		void setSide(int value);
		void setPlanet(int value);

		friend bool operator==(Place lhs, Place rhs);
		friend bool operator!=(Place lhs, Place rhs);


	};

}