#pragma once

#include "../Utility.h"

#include <map>

namespace eng
{

	//For Place here, the side value indicates which side of the planet it is located on.
	//0 = N, 1 = E, 2 = S, 3 = W
	class Navigation
	{
		Place m_first;
		Place m_second;

		bool m_zAxis;

		std::map<Faction, bool> m_transports;

	public:

		explicit Navigation();

		Navigation(const Place& first, const Place& second, bool zaxis = false);

		const Place& first() const;

		const Place& second() const;

		//false = first, true = second
		const Place& end(bool which) const;

		bool isZAxis() const;

		bool canCross(const Faction& player) const;

		bool addTransport(const Faction& player);

		bool killTransport(const Faction& player);

		bool moveEnd(const Place& initial, const Place& destination);
	};

	//Inline declaration
	struct navRoute
	{
		navRoute() : exists(false), connected(false) {}
		
		bool exists;
		bool connected;
		std::shared_ptr<Navigation> ptr;

		Navigation& operator*() const { return *ptr; }
		Navigation* operator->() const { return ptr.get(); }
	};

	//Checks the places of both ends and z-axis, but not the map
	bool operator==(const Navigation& lhs, const Navigation& rhs);
	bool operator!=(const Navigation& lhs, const Navigation& rhs);

}//namespace eng