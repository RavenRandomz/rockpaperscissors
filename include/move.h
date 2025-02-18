#ifndef MOVE_H
#define MOVE_H
#include <iostream>
#include <string_view>

enum class MoveType
{
	rock,
	paper,
	scissors	
};

class Move
{
private:
	MoveType m_movetype;
public:
	Move(const MoveType& movetype);
	bool operator==(const Move& move);
	bool operator>(const Move& move);
	bool operator<(const Move& move);
	constexpr std::string_view getString()const;
	MoveType getMoveType() const;
};

std::ostream& operator<<(std::ostream& os, const Move& move);
#endif
