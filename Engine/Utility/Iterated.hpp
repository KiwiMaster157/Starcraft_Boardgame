#pragma once

#include <map>
#include <memory>

namespace eng
{

	template<typename K, typename V>
	class Iterated
	{
	protected:
		std::map< K, V > m_ittData;

	public:

		std::map<K, V>::iterator begin() const
		{
			return m_ittData.begin();
		}

		std::map<K, V>::iterator end() const
		{
			return m_ittData.end();
		}

	};

}