#include "Navigation.h"

namespace eng
{
	//default: exists = false
	//explicit
	Navigation::Navigation()
	{
		m_zAxis = false;
		m_transports.clear();
	}

	Navigation::Navigation(const Place& first, const Place& second, bool zaxis)
	{
		m_first = first;
		m_second = second;
		m_zAxis = zaxis;

		m_transports.clear();
	}

	const Place& Navigation::first() const
	{
		return m_first;
	}

	const Place& Navigation::second() const
	{
		return m_second;
	}

	const Place& Navigation::end(bool which) const
	{
		return which ? m_second : m_first;
	}

	bool Navigation::isZAxis() const
	{
		return m_zAxis;
	}

	bool Navigation::canCross(const Faction& player) const
	{
		if (m_transports.find(player) != m_transports.end())
			return m_transports.at(player);

		return false;
	}

	bool Navigation::addTransport(const Faction& player)
	{
		if (m_transports.find(player) == m_transports.end())
		{
			m_transports.emplace(player, true);
			return true;
		}
		else if (!m_transports.at(player))
		{
			m_transports.at(player) = true;
			return true;
		}
		return false;
	}

	bool Navigation::killTransport(const Faction& player)
	{
		if (m_transports.find(player) == m_transports.end())
		{
			m_transports.emplace(player, false);
			return false;
		}
		else if (m_transports.at(player))
		{
			m_transports.at(player) = false;
			return true;
		}
		return false;
	}

	bool Navigation::moveEnd(const Place& initial, const Place& destination)
	{
		if (!isZAxis()) return false;

		if (m_first == initial)
		{
			m_first = destination;
			return true;
		}
		else if (m_second == initial)
		{
			m_second = destination;
			return true;
		}
		return false;
	}

	bool operator==(const Navigation& lhs, const Navigation& rhs)
	{
		return lhs.first() == rhs.first()
			&& lhs.second() == rhs.second()
			&& lhs.isZAxis() == rhs.isZAxis();
	}

	bool operator!=(const Navigation& lhs, const Navigation& rhs)
	{
		return !(lhs == rhs);
	}



}