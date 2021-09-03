#ifndef ZombieMonster_H
#define ZombieMonster_H

#include<string>
#include"BaseMonster.h"

using namespace std;

class ZombieMonster :public BaseMonster {
public:
	ZombieMonster();
	virtual string serialize();
	static ZombieMonster* unserialize(string);
};


#endif 
