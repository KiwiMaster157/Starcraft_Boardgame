#pragma once

#include "../Utility.h"
#include "../Owned.h"
#include "Resource.h"

#include <map>
#include <memory>

namespace eng
{

	/*
	Has navigation access to n if m_navAccess & (1 << n) == 1
	*/

	class Zone : public PlacedObject, public Iterated<int, unit>
	{
		int m_capacity;
		Base m_base;
		char m_navAccess;

		resource m_resource;

	public:

		Zone();

		Zone(const Place& p, int cap, const Resource& r, char navAccess = 0);

		Faction inControl() const;

		const Resource& resources() const;
		Resource& resources();

		bool exists() const;

		//Navigation Access
		bool grantAccess(int i);
		bool grantAccess(const Place& p);

		bool revokeAccess(int i);
		bool revokeAccess(const Place& p);

		char navAccess() const;
		bool navAccess(int i) const;
		bool navAccess(const Place& p) const;

		//Unit counts
		int count() const;
		bool isFull() const;
		bool isEmpty() const;

		//Bases
		bool destroyBase();
		bool buildBase();
		bool buildBase(const Faction& f);
		bool finishBase();

		const Base& getBase() const;

		//Unit movement
		bool remove(int identifier);
		bool remove(const unit& u);

		bool insert(const unit& u);

	};

	bool operator==(const Zone& lhs, const Zone& rhs);
	bool operator!=(const Zone& lhs, const Zone& rhs);

}//namespace eng