#ifndef ConsumableItem_H
#define ConsumableItem_H

#include<iostream>
#include<string>
#include"Item.h"

class NovicePlayer;
using namespace std;

class ConsumableItem : public Item
{
public:
	ConsumableItem(char, string, string, string, int, int);
	virtual void use(NovicePlayer*);

};

#endif // !#pragma once
