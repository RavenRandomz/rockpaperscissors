#ifndef I_PLAYER_H_193487239047
#define I_PLAYER_H_193487239047
#include "move.h"
#include <string_view>
class IPlayer
{
public:

	virtual Move doTurn() = 0;
	virtual std::string_view getName() = 0;
	virtual int getScore() = 0;
	virtual void addScore(int scoreAddition) = 0;
	virtual void addOpponentRoundData(std::string_view name, Move move) = 0;
	virtual ~IPlayer() {};
};
#endif



