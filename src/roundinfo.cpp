#include "roundinfo.h"


IndividualRoundInfo::IndividualRoundInfo(std::string_view name, Move move):
	m_playerName{name}, m_move {move}
{
}

Move IndividualRoundInfo::getMove() const 
{
	return m_move;

}

std::string_view IndividualRoundInfo::getPlayerName() const
{
	return m_playerName;
}
