#include "classicarena.h"
#include "iplayer.h"
#include "move.h"

#include <iostream>
#include <string_view>

ClassicArena::ClassicArena(IPlayer* player1, IPlayer* player2):
	m_player1{player1}, m_player2{player2}
{
}

ClassicArena::~ClassicArena()
{
	delete m_player1;
	m_player1 = nullptr;
	delete m_player2;
	m_player2 = nullptr;
}

void ClassicArena::announceTie()
{
	std::cout << "Tie!\n";
}

void ClassicArena::announceVictory (std::string_view victor)
{
	std::cout << victor << " wins the game!\n";
}

void ClassicArena::announceScore()
{
	std::cout << m_player1->getName() << ": " << m_player1->getScore() << '\n';
	std::cout << m_player2->getName() << ": " << m_player2->getScore() << '\n';
}

void ClassicArena::turn()
{
	std::cout << m_player1->getName() << " vs. " << m_player2->getName() << '\n';
	Move move1 = {m_player1->doTurn()};
	Move move2 = {m_player2->doTurn()};

	if (move1 == move2)
	{
		announceTie();
	}
	else if (move1 > move2)
	{
		announceVictory(m_player1->getName());
		m_player1->addScore(m_scoreIncrement);
	}
	else if (move2 > move1)
	{
		announceVictory(m_player2->getName());
		m_player2->addScore(m_scoreIncrement);
	}
 	announceScore();
}

void ClassicArena::play() 
{
	std::cout << "Game began\n";	
	turn();
}

void ClassicArena::playTurns(int turns)
{
	for(int i{0}; i <= turns; ++i)
	{
		turn();
	}
}
