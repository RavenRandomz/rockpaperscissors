#ifndef MOVE_H
#define MOVE_H

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


};
#endif
