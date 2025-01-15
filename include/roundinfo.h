#ifndef ROUND_INFO_H_1293847WE
#define ROUND_INFO_H_1293847WE
#include "move.h"

#include <string_view>

class individualRoundInfo
{
private:
	std::string_view m_playerName{};
	Move m_move;
public:
	std::string_view getPlayerName();
	Move getMove();
};

#endif
