#pragma once

#include "../Utility.h"

//UNFINISHED
//UNFINISHED
//UNFINISHED
//UNFINISHED
//UNFINISHED

namespace eng
{
	class ActionToken : public OwnedObject, public PlacedObject
	{
	public:

		enum ActionType
		{
			None,
			Build,
			Research,
			Move
		};

		ActionToken(const Faction& f, const Place& p = Place::None);

	private:

		ActionType m_type;
		bool m_golden;

	};

	using token = std::shared_ptr<ActionToken>;
}