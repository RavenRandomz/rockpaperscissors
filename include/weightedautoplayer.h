#ifndef WEIGHT_RANDOM_AUTOPLAYER_H_9238USADFJ
#define WEIGHT_RANDOM_AUTOPLAYER_H_9238USADFJ
#include "iplayer.h"
#include "roundinfo.h"
#include <string>
#include <vector>

using RoundData_t = std::vector<IndividualRoundInfo>;

class WeightedAutoPlayer : public IPlayer
{
private:
	std::string m_name{};
	int m_score{};
	RoundData_t m_roundArchive{};
	double m_rockWeight{1};
	double m_paperWeight{0};
	double m_scissorWeight{0};

	double m_rockThreshold{1};
	double m_paperThreshold{1};
	double m_scissorThreshold{1};

public:
	WeightedAutoPlayer(std::string_view name);
	Move doTurn() override;
	std::string_view getName() override;
	int getScore() override;
	void addScore(int scoreAddition) override;
	void addOpponentRoundData(std::string_view name, Move move) override;
	/*
	 * Assume that the weights add up to 1. If they exceed one, they get
	 * truncated. If they are less than one the remaining probability is applied
	 * to scissorWeights
	 */
	void setWeight(double rockWeight, double paperWeight, double scissorWeight);
	
};

#endif
