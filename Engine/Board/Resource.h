#pragma once

#include "../Utility.h"

namespace eng
{

	class Resource : public OwnedObject, public PlacedObject
	{
	public:

		enum ResourceType
		{
			None,
			Conquest,
			Mineral,
			Vespene,
			Gas = Vespene
		};

		enum class Depletion
		{
			None,    //Not depleted
			Partial, //Partially depleted
			Full     //Gone
		};

		Resource(ResourceType rType, int qty, const Place& p = Place::None);

		ResourceType type() const;
		int count() const;
		int usableCount() const;
		Depletion status() const;

		bool usable() const;//not fully depleted

		bool deplete();

		bool undeplete();

		bool exchange(const Faction& f = Faction::None);

	private:

		ResourceType m_type;
		int m_count;
		Depletion m_depl;

	};

	using resource = std::shared_ptr<Resource>;

}//namespace eng