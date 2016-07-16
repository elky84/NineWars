#pragma once

#include "NWTypeDefinition.h"
#include <vector>

namespace NW
{

class Corps
{
public:
	typedef std::vector<WEAK_CARD> VECTOR_CARD;

public:
	Corps();
	~Corps();

	void AddCard(const WEAK_CARD& card);

	bool isExist(const WEAK_CARD& card);

	VECTOR_CARD& VectorCard()
	{
		return m_vector_Card;
	}

private:
	OWNING_SQUAD m_Squad;

	std::vector<WEAK_CARD> m_vector_Card;
};

} // namespace NW