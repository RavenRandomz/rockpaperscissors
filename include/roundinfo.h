#ifndef ROUND_INFO_H_1293847WE
#define ROUND_INFO_H_1293847WE
#include "move.h"

#include <string>
#include <string_view>

class IndividualRoundInfo
{
private:
	std::string m_playerName{};
	Move m_move;
public:
	IndividualRoundInfo(std::string_view name, Move move);
	std::string_view getPlayerName() const;
	Move getMove() const;
};

#endif
