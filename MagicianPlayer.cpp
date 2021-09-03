#include<iostream>
#include<string>
#include<math.h>
#include"NovicePlayer.h"
#include"MagicianPlayer.h"

using namespace std;

MagicianPlayer::MagicianPlayer(int l, string n){
	setLevel(l);
	setName(n);

	//¤£½T©w
	setHP(getMaxHP());
	setMP(getMaxMP());
	setExp(lastlvup_exp);
	setMoney(0);
}

MagicianPlayer::MagicianPlayer(const  MagicianPlayer &m) {
	setLevel(m.getLevel());
	setName(m.getName());
	setHP(m.getHP());
	setMP(m.getMP());
	setExp(m.getExp());
	setMoney(m.getMoney());
}

void MagicianPlayer::setLevel(int l) {
	level = (1 <= l) ? l : 1;
	attack = 30 + 8 * getLevel();
	defense = 20 + 7 * getLevel();
	max_hp = 120 + 15 * getLevel();
	max_mp = 100 + 15 * getLevel();
	lvup_exp = ceil(pow(10, log2(getLevel() + 1)));
	lastlvup_exp = ceil(pow(10, log2(getLevel())));;
}

void MagicianPlayer::specialSkill() {
	//pray¤õ²y
	if (getMP() - 5 * getLevel() > 0) {
		setMP(getMP() - 5 * getLevel());
	}
	
}

string MagicianPlayer::serialize() {
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


MagicianPlayer* MagicianPlayer::unserialize(string s) {

	static MagicianPlayer m;
	for (int i = 0; i < 6; i++) {

		int a = s.find("$");
		string si = s.substr(0, a);

		switch (i)
		{
		case 0:
			m.setName(si);
			break;
		case 1:
			m.setLevel(stoi(si));
			break;
		case 2:
			m.setHP(stoi(si));
			break;
		case 3:
			m.setMP(stoi(si));
			break;
		case 4:
			m.setExp(stoi(si));
			break;
		case 5:
			m.setMoney(stoi(si));
			break;
		default:
			break;
		};
		s.erase(0, (si.length() + 1));
	}

	return &m;
}