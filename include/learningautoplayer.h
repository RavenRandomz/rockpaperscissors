#ifndef LEARNING_AUTO_PLAYER_H_DDFH92SDJFIUWEFH
#define LEARNING_AUTO_PLAYER_H_DDFH92SDJFIUWEFH
#include "iplayer.h"
#include "weightedautoplayer.h"
#include <string_view>

class LearningAutoPlayer : IPlayer
{
private:
	WeightedAutoPlayer m_weightedPlayer;

public:
	LearningAutoPlayer(const std::string_view name);
	virtual Move doTurn() = 0;
	virtual std::string_view getName() = 0;
	virtual int getScore() = 0;
	virtual void addScore(int scoreAddition) = 0;
	virtual void addOpponentRoundData(std::string_view name, Move move) = 0;
};
#endif
