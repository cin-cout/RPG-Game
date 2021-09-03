#include<iostream>
#include<string>
#include<math.h>
#include"NovicePlayer.h"
#include"OrcPlayer.h"

using namespace std;

OrcPlayer::OrcPlayer(int l,string n){
	setLevel(l);
	setName(n);

	//¤£½T©w
	setHP(getMaxHP());
	setMP(getMaxMP());
	setExp(lastlvup_exp);
	setMoney(0);
}

OrcPlayer::OrcPlayer(const OrcPlayer &o){
	setLevel(o.getLevel());
	setName(o.getName());
	setHP(o.getHP());
	setMP(o.getMP());
	setExp(o.getExp());
	setMoney(o.getMoney());
}

void OrcPlayer::setLevel(int l) {
	level = (1 <= l) ? l : 1;
	attack = 50 + 12 * getLevel();
	defense = 30 + 10 * getLevel();
	max_hp = 200 + 20 * getLevel();
	max_mp = 50 + 5 * getLevel();
	lvup_exp = ceil(pow(10, log2(getLevel() + 1)));
	lastlvup_exp = ceil(pow(10, log2(getLevel())));
}

void OrcPlayer::specialSkill() {
	
	if (getMP() - 5 * getLevel() > 0) {
		setHP(getHP() + 10 * getLevel());
		setMP(getMP() - 5 * getLevel());
	}

}

string OrcPlayer::serialize() {
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


OrcPlayer* OrcPlayer::unserialize(string s) {

	static OrcPlayer o;
	for (int i = 0; i < 6; i++) {

		int a = s.find("$");
		string si = s.substr(0, a);

		switch (i)
		{
		case 0:
			o.setName(si);
			break;
		case 1:
			o.setLevel(stoi(si));
			break;
		case 2:
			o.setHP(stoi(si));
			break;
		case 3:
			o.setMP(stoi(si));
			break;
		case 4:
			o.setExp(stoi(si));
			break;
		case 5:
			o.setMoney(stoi(si));
			break;
		default:
			break;
		};
		s.erase(0, (si.length() + 1));
	}

	return &o;
}