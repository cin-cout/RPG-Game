#ifndef OrcPlayer_H
#define OrcPlayer_H

#include"NovicePlayer.h"

class OrcPlayer:public NovicePlayer 
{
public:
	OrcPlayer(int = 1, string = "anonymous");
	OrcPlayer(const OrcPlayer &);

	virtual void setLevel(int);
	virtual void specialSkill();
	virtual string serialize();
	static  OrcPlayer* unserialize(string);
};

#endif
