#pragma once

#include "../Gamestate.h"
#include "Place.h"

namespace eng
{
	class Zone;
	class Planet;
	
	class PlacedObject
	{
		Place m_place;
		bool m_p_locked;

	public:

		PlacedObject(Place p = Place::None, bool locked = false);

		const Place& place() const;
		Zone& zone() const;
		Planet& planet() const;

		void placeLock();
		void placeUnlock();
		bool isPlaceLocked() const;

	protected:
		
		//Children should implement move() if applicable
		bool placeMove(Place p);
	};
}