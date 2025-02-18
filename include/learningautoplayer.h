#ifndef LEARNING_AUTO_PLAYER_H_DDFH92SDJFIUWEFH
#define LEARNING_AUTO_PLAYER_H_DDFH92SDJFIUWEFH
#include "iplayer.h"
#include "weightedautoplayer.h"
#include "roundinfo.h"

#include <string_view>
#include <vector>

using RoundData_t = std::vector<IndividualRoundInfo>;
class LearningAutoPlayer : IPlayer
{
	using opponentCount_t = int;
private:
	WeightedAutoPlayer m_weightedPlayer;
	RoundData_t m_roundData{};
	
	opponentCount_t m_opponentRockCount{0};
	opponentCount_t m_opponentPaperCount{0};
	opponentCount_t m_opponentScissorsCount{0};
	int m_roundCount{0};
	void updateMoveCounts(Move& move);
	void setWeights();
public:
	LearningAutoPlayer(const std::string_view name);
	virtual Move doTurn() override;
	virtual std::string_view getName() override;
	virtual int getScore() override;
	virtual void addScore(int scoreAddition) override;
	virtual void addOpponentRoundData(std::string_view name, Move move) override;
};
#endif
