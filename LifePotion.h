#ifndef LifePotion_H
#define LifePotion_H

#include<string>
#include"NovicePlayer.h"
#include"ConsumableItem.h"

using namespace std;

class LifePotion : public ConsumableItem
{
public:
	LifePotion();
	virtual void use(NovicePlayer*);

};

#endif