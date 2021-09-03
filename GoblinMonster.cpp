#include<iostream>
#include<string>
#include"BaseMonster.h"
#include"GoblinMonster.h"

using namespace std;

GoblinMonster::GoblinMonster() 
	:BaseMonster("Goblin",60,40,12,30,100,50)
{
	setHP(100);
	setMP(50);
}

string GoblinMonster::serialize() {
	string s;
	s += to_string(getHP());
	s += "$";
	s += to_string(getMP());
	return s;
}

GoblinMonster* GoblinMonster::unserialize(string s) {
	static GoblinMonster g;
	int a;
	int b;
	a = s.find("$");
	b = stoi(s.substr(0,a));
	g.setHP(b);
	b = stoi(s.substr(a+1));
	g.setMP(b);
	return &g;
}