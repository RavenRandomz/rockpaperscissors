#include "learningautoplayer.h"
#include "move.h"

LearningAutoPlayer::LearningAutoPlayer(const std::string_view name):
	m_weightedPlayer{name}
{
}
Move LearningAutoPlayer::doTurn()
{
}

void LearningAutoPlayer::updateMoveCounts(Move& move)
{
	switch (move.getMoveType())
	{
	case(MoveType::rock):
		++m_oponentRockCount;
		break;
	case(MoveType::paper):
		++m_oponentPaperCount;
		break;
	case(MoveType::scissors):
		++m_oponentScissorsCount;
		break;
	}
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
	m_roundData.push_back(IndividualRoundInfo{name, move});
}


