#ifndef PLAYER_H
#define PLAYER_H

#include "move.h"
#include "iplayer.h"

#include <string>

class HumanPlayer: public IPlayer
{
private:
	int m_score{0};
	std::string m_name{};

public:
	
	void addOpponentRoundData(std::string_view name, Move) override;
	HumanPlayer(std::string const &playerName);
	HumanPlayer(HumanPlayer const &player);
	Move doTurn() override;

	void addScore(int scoreAddition) override;
	int getScore() override;
	std::string_view getName() override;
};

//limit your resistance to unlikely events
#endif
