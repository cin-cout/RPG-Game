#include<iostream>
#include<string>
#include"BaseMonster.h"
#include"JWMonster.h"

using namespace std;

JWMonster::JWMonster()
	:BaseMonster("JWMaster", 120, 100, 42, 175, 250, 100)
{
	setHP(250);
	setMP(100);
}

string JWMonster::serialize() {
	string s ;
	s += to_string(getHP());
	s += "$";
	s += to_string(getMP());
	return s;
}

JWMonster* JWMonster::unserialize(string s) {
	static JWMonster j;
	int a;
	int b;
	a = s.find("$");
	b = stoi(s.substr(0, a));
	j.setHP(b);
	b = stoi(s.substr(a + 1));
	j.setMP(b);
	return &j;
}