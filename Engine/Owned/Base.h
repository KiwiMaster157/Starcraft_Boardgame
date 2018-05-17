#pragma once

#include "../Utility.h"

namespace eng
{

	class Base : public OwnedObject, public PlacedObject
	{
	public:

		enum Status
		{
			Destroyed,
			Incomplete,
			Finished
		};

		Base(const Faction& f, const Place& p);

		Status status() const;

		bool exists() const;
		bool isFinished() const;

		bool destroy();
		bool start(const Faction& f);
		bool finish();

	private:

		Status m_status;

	};

}