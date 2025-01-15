#ifndef IARENA_H
#define IARENA_H
class IArena
{
public:
	virtual void play() = 0;
	virtual void playTurns(int turns) = 0;
	virtual ~IArena() {};
};
#endif
