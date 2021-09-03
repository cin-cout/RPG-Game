#include<iostream>
#include<string>
#include<math.h>
#include"BaseMonster.h"

using namespace std;

int BaseMonster::count = 0;

int BaseMonster::getInstanceCount() {
	return count;
}

BaseMonster::BaseMonster(string n, int a, int d, int e, int m, int mh, int mm) 
	:name(n),attack(a),defense(d),exp(e),money(m),max_hp(mh),max_mp(mm)
{
	count++;
}

BaseMonster::~BaseMonster() {
	count--;
}

void BaseMonster::setHP(int h) {
	if (h <= 0) { hp = 0; }
	else if (h >= max_hp) { hp = max_hp; }
	else { hp = h; }
}

int BaseMonster::getHP() const {
	return hp;
}

void BaseMonster::setMP(int m) {
	if (m <= 0) { mp = 0; }
	else if (m >= max_mp) { mp = max_mp; }
	else { mp = m; }
}

int BaseMonster::getMP() const {
	return mp;
}