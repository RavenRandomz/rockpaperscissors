#include "weightedautoplayer.h"
#include "roundinfo.h"
#include "utility.h"

WeightedAutoPlayer::WeightedAutoPlayer(std::string_view name):
	m_name {name}
{
}

Move WeightedAutoPlayer::doTurn()
{
	double rand{randomDouble()};
	//The threshold is the maximum amount to trigger
	std::cout << rand << '\n';
	if ( (0 <= rand) && (rand <= m_rockThreshold))
	{
		return Move{MoveType::rock};
	}
	else if ((m_rockThreshold < rand) && (rand <= m_paperThreshold))
	{
		return Move{MoveType::paper};
	}
	else if ((m_paperThreshold < rand) && (rand <= m_scissorThreshold))
	{
		return Move{MoveType::scissors};
	}
	else //Ramen noodle stuff
	{
		return Move{MoveType::scissors};
	}
}

std::string_view WeightedAutoPlayer::getName()
{
	return m_name;
}
int WeightedAutoPlayer::getScore()
{
	return m_score;
}
void WeightedAutoPlayer::addScore(int scoreAddition)
{
	m_score += scoreAddition;
}

void WeightedAutoPlayer::addOpponentRoundData(std::string_view name, Move move)
{
	m_roundArchive.push_back(IndividualRoundInfo{name, move});
}

void WeightedAutoPlayer::setWeight(double rockWeight, double paperWeight, double scissorWeight)
{
	m_rockWeight = rockWeight;
	m_paperWeight = paperWeight;
	m_scissorWeight = scissorWeight;


	//The random number geneator will create a floating point number from 0 to
	//1. The thresholds create
	m_rockThreshold = m_rockWeight;
	m_paperThreshold = m_rockThreshold + m_paperWeight;
	m_scissorThreshold = m_paperWeight + m_scissorWeight;
}

	

