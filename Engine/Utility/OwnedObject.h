#pragma once

#include "Faction.h"

namespace eng
{
	class Player;
	
	class OwnedObject
	{
		Faction m_faction;
		bool m_f_locked;

	public:

		explicit OwnedObject(Faction f = Faction::None, bool locked = true);

		const Faction& faction() const;
		Player& player() const;

		void factionLock();
		void factionUnlock();
		bool isFactionLocked() const;

	protected:

		//Children should implement exchange() if applicable
		bool factionExchange(Faction f);

	};

}//namespace eng