#include "weightedautoplayer.h"
#include "iplayer.h"
#include "classicarena.h"
#include "learningautoplayer.h"
#include "randomautoplayer.h"
#include "move.h"

#include <iostream>

void testMove()
{
	Move paper{MoveType::paper};
	Move rock{MoveType::rock};
	Move scissors{MoveType::scissors};

	std::cout << "Equality Test pp: " << static_cast<int>(paper == paper) << '\n';
	std::cout << "Equality Test rr: " << static_cast<int>(rock == rock) << '\n';
	std::cout << "Equality Test ss: " << static_cast<int>(scissors == scissors) << '\n';

	std::cout << "Equality Test p > r: " << static_cast<int>(paper > rock) << '\n';
	std::cout << "Equality Test r > s: " << static_cast<int>(rock > scissors) << '\n';
	std::cout << "Equality Test s > p: " << static_cast<int>(scissors > paper) << '\n';

	std::cout << "Equality Test p < r: " << static_cast<int>(paper < rock) << '\n';
	std::cout << "Equality Test r < s: " << static_cast<int>(rock < scissors) << '\n';
	std::cout << "Equality Test s < p: " << static_cast<int>(scissors < paper) << '\n';
}

int main()
{
	WeightedAutoPlayer bill{"Bill"};
	LearningAutoPlayer steve{"Steve"};

	bill.setWeight(0.1, 0.2, 0.8);
	bill.setWeight(0.1, 0.2, 0.8);

	ClassicArena arena{&bill, &steve};
	arena.playTurns(1000);
	
	
	//initialize players
	//pass players to arena
	//begin arena
	return 0;
}
