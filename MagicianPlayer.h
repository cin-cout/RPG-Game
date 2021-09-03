#ifndef MagicianPlayer_H
#define MagicianPlayer_H

#include"NovicePlayer.h"

class MagicianPlayer : public NovicePlayer {
public:
	MagicianPlayer(int = 1, string = "anonymous");
	MagicianPlayer(const  MagicianPlayer &);

	virtual void setLevel(int);
	virtual void specialSkill();
	virtual string serialize();
	static  MagicianPlayer* unserialize(string);
};

#endif
