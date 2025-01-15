#include "randomautoplayer.h"
#include "move.h"

#include "utility.h"

Move RandomAutoPlayer::getRandomMove()
{
	double rand {randomDouble()};
	Move move{MoveType::rock};

	if (0 <= rand < (1.0/3.0))
	{
		move = Move{MoveType::rock};
	}
	else if ((1.0/3.0) <= rand < (2.0/3.0))
	{
		move = Move{MoveType::paper};
	}
	else if ((2.0/3.0) <= rand <= 1.0)
	{
		move = Move{MoveType::scissors};
	}
	return move;
}

RandomAutoPlayer::RandomAutoPlayer(const std::string& name):
	m_name {name}
{
}

Move RandomAutoPlayer::doTurn()
{
	return getRandomMove();
}
std::string_view RandomAutoPlayer::getName() 
{
	return m_name;
}
int RandomAutoPlayer::getScore() 
{
	return m_points;
}

void RandomAutoPlayer::addScore(int scoreAddition) 
{
	m_points += scoreAddition;
}
void RandomAutoPlayer::addOpponentRoundData(std::string_view name, Move) 
{
}

