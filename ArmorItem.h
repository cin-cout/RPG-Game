#ifndef ArmorItem_H
#define ArmorItem_H

#include<string>
#include"Item.h"

using namespace std;

class ArmorItem : public Item
{
public:
	ArmorItem(char, string, string, string, int, int, int);
	const int defense_increment;
};

#endif // !
