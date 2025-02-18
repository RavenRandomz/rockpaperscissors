#include "learningautoplayer.h"

LearningAutoPlayer::LearningAutoPlayer(const std::string_view name):
	m_weightedPlayer{name}
{
}
Move LearningAutoPlayer::doTurn()
{
}

std::string_view LearningAutoPlayer::getName()
{
}

int LearningAutoPlayer::getScore()
{
}
void LearningAutoPlayer::addScore(int scoreAddition)
{
}

void LearningAutoPlayer::addOpponentRoundData(std::string_view name, Move move)
{
}


