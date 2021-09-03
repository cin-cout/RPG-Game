#ifndef NovicePlayer_H
#define NovicePlayer_H

#include<iostream>
#include<string>
#include"Item.h"
#include"WeaponItem.h"
#include"ArmorItem.h"

class ConsumableItem;
using namespace std;

class NovicePlayer {
public:
	NovicePlayer(int = 1,string="anonymous");
	NovicePlayer(const NovicePlayer &);

	string getName() const;
	void setName(string);

	int getHP() const;
	void setHP(int);

	int getMP() const;
	void setMP(int);

	int getExp() const;
	void setExp(int);

	int getMoney() const;
	void setMoney(int);

	int getLevel() const;
	virtual void setLevel(int);

	int getAttack() const;
	int getDefense() const;
	int getMaxHP() const;
	int getMaxMP() const;
	int getLvupExp() const;

	virtual void specialSkill();

	virtual string serialize();
	static  NovicePlayer* unserialize(string);

	WeaponItem * getweapon() const;
	ArmorItem * getarmor() const;

	const int backpack_weight_limit;
	const int backpack_slot_limit;

	bool equipWeapon(WeaponItem*);
	bool equipArmor(ArmorItem*);
	void useConsumable(ConsumableItem*);

	bool putItem(Item*);
	Item* takeItem(int);

protected:

	int level;
	int attack;
	int defense;
	int max_hp;
	int max_mp;
	int lvup_exp;
	int lastlvup_exp;

private:
	string name;
	int hp;
	int mp;
	int exp;
	int money;

	Item* backpack[6] = {NULL};
	WeaponItem* weapon;
	ArmorItem* armor;
	int backpack_weight;

};

#endif // !NovicePlayer_H

