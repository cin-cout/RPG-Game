#ifndef GoblinMonster_H
#define GoblinMonster_H

#include<string>
#include"BaseMonster.h"

using namespace std;

class GoblinMonster :public BaseMonster{
public:
	GoblinMonster();
	virtual string serialize();
	static GoblinMonster* unserialize(string);
};


#endif // !GoblinMonster_H

