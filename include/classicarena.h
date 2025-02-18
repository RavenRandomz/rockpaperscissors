#ifndef CLASSIC_ARENA_H
#define CLASSIC_ARENA_H
#include "iarena.h"
#include "iplayer.h"
#include <string_view>

class ClassicArena:public IArena
{
private:
	IPlayer* m_player1;
	IPlayer* m_player2;
	int m_scoreIncrement{1};

	void announceTie();
	void announceVictory (std::string_view victor);
	void announceScore();
	void announceMoves(const Move& player1Move, const Move& player2Move) const;
	void turn();
public:
	ClassicArena(IPlayer* player1, IPlayer* player2);
	~ClassicArena();
	void play() override;
	void playTurns(int turns) override;
};

#endif
