#ifndef MagicPotion_H
#define MagicPotion_H

#include<string>
#include"NovicePlayer.h"
#include"ConsumableItem.h"

using namespace std;

class MagicPotion : public ConsumableItem
{
public:
	MagicPotion();
	virtual void use(NovicePlayer*);

};

#endif
