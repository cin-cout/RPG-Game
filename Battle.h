#ifndef Battle_H
#define Battle_H
#include"NovicePlayer.h"
#include"GoblinMonster.h"
#include"JWMonster.h"
#include"KnightPlayer.h"
#include"MagicianPlayer.h"
#include"OrcPlayer.h"
#include"ZombieMonster.h"
#include"BaseMonster.h"

struct Charactor
{
	char type;
	bool alive;
	void *instance;
};

class Battle {
public:
	Battle(NovicePlayer**, BaseMonster**, int, int);
private:
	Charactor *ActionList;
};


#endif // !Battle_H

