#include<iostream>
#include<string>
#include"BaseMonster.h"
#include"ZombieMonster.h"

using namespace std;

ZombieMonster::ZombieMonster()
	:BaseMonster("Zombie", 50, 65, 17, 65, 150, 30)
{
	setHP(150);
	setMP(30);
}

string ZombieMonster::serialize() {
	string s;
	s += to_string(getHP());
	s += "$";
	s += to_string(getMP());
	return s;
}

ZombieMonster* ZombieMonster::unserialize(string s) {
	static ZombieMonster z;
	int a;
	int b;
	a = s.find("$");
	b = stoi(s.substr(0, a));
	z.setHP(b);
	b = stoi(s.substr(a + 1));
	z.setMP(b);
	return &z;
}