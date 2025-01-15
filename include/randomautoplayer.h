#ifndef RANDOM_AUTO_PLAYER_924VJOWEFJSDLFJ
#define RANDOM_AUTO_PLAYER_924VJOWEFJSDLFJ
#include "iplayer.h"
#include "move.h"

#include <string>
class RandomAutoPlayer : public IPlayer
{
private:
	std::string m_name;
	int m_points{0};

	Move getRandomMove();

public:
	RandomAutoPlayer(const std::string& name);
	Move doTurn() override;
	std::string_view getName() override;
	int getScore() override;
	void addScore(int scoreAddition) override;
	void addOpponentRoundData(std::string_view name, Move) override;
};

#endif
