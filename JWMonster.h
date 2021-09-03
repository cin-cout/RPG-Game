#ifndef JWMonster_H
#define JWMonster_H

#include<string>
#include"BaseMonster.h"

using namespace std;

class JWMonster :public BaseMonster {
public:
	JWMonster();
	virtual string serialize();
	static JWMonster* unserialize(string);
};


#endif 
