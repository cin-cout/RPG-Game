#ifndef KnightPlayer_H
#define KnightPlayer_H

#include"NovicePlayer.h"

class KnightPlayer : public NovicePlayer {
public:
	KnightPlayer(int = 1, string = "anonymous");
	KnightPlayer(const KnightPlayer &);
	
	virtual void setLevel(int);
	virtual void specialSkill();
	virtual string serialize();
	static  KnightPlayer* unserialize(string);
};

#endif
