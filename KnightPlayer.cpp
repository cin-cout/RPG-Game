#include<iostream>
#include<string>
#include<math.h>
#include"NovicePlayer.h"
#include"KnightPlayer.h"

using namespace std;

KnightPlayer::KnightPlayer(int l, string n) 
{
	setLevel(l);
	setName(n);

	//¤£½T©w
	setHP(getMaxHP());
	setMP(getMaxMP());
	setExp(lastlvup_exp);
	setMoney(0);
}

KnightPlayer::KnightPlayer(const KnightPlayer &k) {
	setLevel(k.getLevel());
	setName(k.getName());
	setHP(k.getHP());
	setMP(k.getMP());
	setExp(k.getExp());
	setMoney(k.getMoney());
}

void KnightPlayer::setLevel(int l) {
	level = (1 <= l) ? l : 1;
	attack = 40 + 10 * getLevel();
	defense = 20 + 12 * getLevel();
	max_hp = 150 + 25 * getLevel();
	max_mp = 70 + 10 * getLevel();
	lvup_exp = ceil(pow(10, log2(getLevel() + 1)));
	lastlvup_exp = ceil(pow(10, log2(getLevel())));
}

void KnightPlayer::specialSkill() {
	
	if (getMP() - 5 * getLevel() > 0) {
		setMP(getMP() - 5 * getLevel());
	}

}

string KnightPlayer::serialize() {
	string s = getName();
	for (int i = 0; i < 5; i++) {
		s += "$";
		switch (i)
		{
		case 0:
			s += to_string(getLevel());
			break;
		case 1:
			s += to_string(getHP());
			break;
		case 2:
			s += to_string(getMP());
			break;
		case 3:
			s += to_string(getExp());
			break;
		case 4:
			s += to_string(getMoney());
			break;
		default:
			break;
		}
	}
	return s;
}


KnightPlayer* KnightPlayer::unserialize(string s) {

	static KnightPlayer k;
	for (int i = 0; i < 6; i++) {

		int a = s.find("$");
		string si = s.substr(0, a);

		switch (i)
		{
		case 0:
			k.setName(si);
			break;
		case 1:
			k.setLevel(stoi(si));
			break;
		case 2:
			k.setHP(stoi(si));
			break;
		case 3:
			k.setMP(stoi(si));
			break;
		case 4:
			k.setExp(stoi(si));
			break;
		case 5:
			k.setMoney(stoi(si));
			break;
		default:
			break;
		};
		s.erase(0, (si.length() + 1));
	}

	return &k;
}