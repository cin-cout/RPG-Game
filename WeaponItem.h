#ifndef WeaponItem_H
#define WeaponItem_H

#include<string>
#include"Item.h"

using namespace std;

class WeaponItem : public Item 
{
public:
	WeaponItem(char, string, string, string, int, int,int);
	const int attack_increment;
};

#endif // !