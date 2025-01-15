#ifndef WEIGHT_RANDOM_AUTOPLAYER_H_9238USADFJ
#define WEIGHT_RANDOM_AUTOPLAYER_H_9238USADFJ
#include "iplayer.h"

class WeightedAutoPlayer : public IPlayer
{
private:

public:
	Move doTurn() override;
	std::string_view getName() override;
	int getScore() override;
	void addScore(int scoreAddition) override;
	void addOpponentRoundData(std::string_view name, Move) override;
};

#endif
