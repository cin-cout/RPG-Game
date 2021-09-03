#include<iostream>
#include<string>
#include<math.h>
#include"NovicePlayer.h"
#include"ConsumableItem.h"

using namespace std;

NovicePlayer::NovicePlayer(int l, string n) 
	:backpack_weight_limit(100), backpack_slot_limit(6)
{
	setLevel(l);
	setName(n);

	//¤£½T©w
	setHP(getMaxHP());
	setMP(getMaxMP());
	setExp(lastlvup_exp);
	setMoney(0);

	backpack_weight = 0;  

}

NovicePlayer::NovicePlayer(const NovicePlayer &n) 
	:backpack_weight_limit(100), backpack_slot_limit(6)
{

	setLevel(n.getLevel());
	setName(n.getName());
	setHP(n.getHP());
	setMP(n.getMP());
	setExp(n.getExp());
	setMoney(n.getMoney());
}

string NovicePlayer::getName() const{
	return name;
}

void NovicePlayer::setName(string n) {
	name = n;
}

int NovicePlayer::getHP() const {
	return hp;
}

void NovicePlayer::setHP(int h) {
	if (h <= 0) { hp = 0; }
	else if (h >= getMaxHP()) { hp = getMaxHP(); }
	else { hp = h; }
}

int NovicePlayer::getMP() const {
	return mp;
}

void NovicePlayer::setMP(int m) {
	if (m <= 0) { mp = 0; }
	else if (m > getMaxHP()) { mp = getMaxMP(); }
	else { mp = m; }
}

int NovicePlayer::getExp() const {
	return exp;
}

int NovicePlayer::getMoney() const {
	return money;
}

void NovicePlayer::setMoney(int m) {
	money = (0 <= m) ? m : 0;
}

void NovicePlayer::setExp(int e) {
	if (e <= lastlvup_exp) {
		exp = lastlvup_exp;
	}
	else { exp = e; }
}

int NovicePlayer::getLevel() const {
	return level;
}

void NovicePlayer::setLevel(int l) {
	level = (1 <= l) ? l : 1;
	attack = 20 + 5 * getLevel();
	defense = 20 + 5 * getLevel();
	max_hp = 100 + 10 * getLevel();
	max_mp = 40 + 5 * getLevel();
	lvup_exp = ceil(pow(10, log2(getLevel() + 1)));
	lastlvup_exp = ceil(pow(10, log2(getLevel())));
}

int NovicePlayer::getAttack() const {
	return attack;
}

int NovicePlayer::getDefense() const {
	return defense;
}

int NovicePlayer::getMaxHP() const {
	return max_hp;
}

int NovicePlayer::getMaxMP() const {
	return max_mp;
}

int NovicePlayer::getLvupExp() const {
	return lvup_exp;;
}

void NovicePlayer::specialSkill() {  }

string NovicePlayer::serialize() {
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

NovicePlayer* NovicePlayer::unserialize(string s) {
	
	static NovicePlayer n;
	for (int i = 0; i < 6; i++) {

		int a = s.find("$");
		string si = s.substr(0, a);
	
		switch (i)
		{
		case 0:
			n.setName(si);
			break;
		case 1:
			n.setLevel(stoi(si));
			break;
		case 2:
			n.setHP(stoi(si));
			break;
		case 3:
			n.setMP(stoi(si));
			break;
		case 4:
			n.setExp(stoi(si));
			break;
		case 5:
			n.setMoney(stoi(si));
			break;
		default:
			break;
		};
		s.erase(0, (si.length() + 1));
	}

	return &n;
}

WeaponItem *NovicePlayer::getweapon() const {
	return weapon;
}

ArmorItem *NovicePlayer::getarmor() const {
	return armor;
}

bool NovicePlayer::equipWeapon(WeaponItem* w) {
	if (w->level_required  >=  getLevel()) {
		weapon = w;
		return 1;
	}
	else { return 0; }
}

bool NovicePlayer::equipArmor(ArmorItem* a) {
	if (a->level_required >= getLevel()) {
		armor = a;
		return 1;
	}
	else { return 0; }
}

void NovicePlayer::useConsumable(ConsumableItem* c) {
	c->use(this);
}

bool NovicePlayer::putItem(Item* it) {
	for (int i = 0; i < backpack_slot_limit; i++) {
		
		if (backpack[i] == NULL) {
			if ((it->weight) <= (backpack_weight_limit - backpack_weight)) {
				backpack[i] = it;
				backpack_weight += it->weight;
				return 1;
			}
			else { return 0; }
		}

		else { return 0; }
	}
}

Item* NovicePlayer::takeItem(int n) {
	
	Item *i = NULL;

	if (backpack[n] != NULL) {
		i = backpack[n];
		backpack[n] = NULL;
		backpack_weight -= i->weight;
	}

	return i;
}