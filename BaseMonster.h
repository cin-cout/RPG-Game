#ifndef  BaseMonster_H
#define BaseMonster_H

#include<string>
using namespace std;

class BaseMonster {
public:
	BaseMonster(string, int, int, int, int, int, int);
	~BaseMonster();
	const string name;
	const int attack; 
	const int defense;  
	const int exp; 
	const int money; 
	const int max_hp; 
	const int max_mp; 

	void setHP(int);
	int getHP() const;

	void setMP(int);
	int getMP() const;

	static int getInstanceCount();

	virtual string serialize() = 0;

private:
	int hp;
	int mp;
	static int count;
};

#endif
