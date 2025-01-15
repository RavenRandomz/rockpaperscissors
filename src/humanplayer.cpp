#include "humanplayer.h"
#include "move.h"

#include <iostream>
#include <string>

std::string_view HumanPlayer::getName()
{
	return m_name;
}

HumanPlayer::HumanPlayer(const std::string &name):
	m_name{name}
{
}

HumanPlayer::HumanPlayer(HumanPlayer const &player):
	m_name(player.m_name)
{
}

void HumanPlayer::addOpponentRoundData(std::string_view name, Move)
{
}

int HumanPlayer::getScore()
{
	return m_score;
}

void HumanPlayer::addScore(int add)
{
	m_score += add;
}

Move HumanPlayer::doTurn()
{
	char input {};	
	std::cout << "Enter " << m_name << "\'s move(r,p,s): ";
	std::cin >> input;
	Move move{MoveType::rock};

	switch(input)
	{
		case('r'):
			move = Move{MoveType::rock};
			break;
		case('p'):
			move = Move{MoveType::paper};
			break;
		case('s'):
			move = Move{MoveType::scissors};
			break;
		default:
			throw("Fuck invalid input");
	}

	return move;
}

