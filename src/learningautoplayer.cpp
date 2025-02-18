#include "learningautoplayer.h"
#include "move.h"

LearningAutoPlayer::LearningAutoPlayer(const std::string_view name):
	m_weightedPlayer{name}
{
}
Move LearningAutoPlayer::doTurn()
{
	return m_weightedPlayer.doTurn();
}

void LearningAutoPlayer::updateMoveCounts(Move& move)
{
	switch (move.getMoveType())
	{
	case(MoveType::rock):
		++m_opponentRockCount;
		break;
	case(MoveType::paper):
		++m_opponentPaperCount;
		break;
	case(MoveType::scissors):
		++m_opponentScissorsCount;
		break;
	}
}

void LearningAutoPlayer::setWeights()
{
	double rockRatio{(double) m_opponentRockCount/ (double) m_roundCount};
	double paperRatio{(double) m_opponentPaperCount/ (double) m_roundCount};
	double scissorsRatio{(double) m_opponentScissorsCount/ (double) m_roundCount};

	//Set the weight to equal that which this player will beat i.e. if the
	//oponent has a history of playing rock, this player will shift its weight
	//towards paper. THINK: If the opponent has a high ratio of a certain move
	//type, what would I like for the learned auto player to play in order to
	//win?
	
	m_weightedPlayer.setWeight(scissorsRatio, rockRatio, paperRatio);
}

std::string_view LearningAutoPlayer::getName()
{
	return m_weightedPlayer.getName();
}

int LearningAutoPlayer::getScore()
{
	return m_weightedPlayer.getScore();
}
void LearningAutoPlayer::addScore(int scoreAddition)
{
	m_weightedPlayer.addScore(scoreAddition);
}

void LearningAutoPlayer::addOpponentRoundData(std::string_view name, Move move)
{
	updateMoveCounts(move);
	++m_roundCount;
	m_roundData.push_back(IndividualRoundInfo{name, move});

}


