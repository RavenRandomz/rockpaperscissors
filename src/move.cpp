#include "move.h"

Move::Move(const MoveType& movetype):
	m_movetype{movetype}
{
}

bool Move::operator==(const Move& move)
{
	return m_movetype == move.m_movetype;
}

bool Move::operator>(const Move& move)
{
	bool verdict {};
	if(m_movetype == MoveType::rock)
	{
		switch(move.m_movetype)
		{
			case (MoveType::scissors):
				verdict = true;
				break;
			default:
				verdict = false;
		}
	}
	else if (m_movetype == MoveType::paper)
	{
		switch(move.m_movetype)
		{
			case (MoveType::rock):
				verdict = true;
				break;
			default:
				verdict = false;
		}
	}
	else if (m_movetype == MoveType::scissors)
	{
		switch(move.m_movetype)
		{
			case (MoveType::paper):
				verdict = true;
				break;
			default:
				verdict = false;
		}
	}
	return verdict;
}

bool Move::operator<(const Move& move)
{
	return !(*this > move);
}
