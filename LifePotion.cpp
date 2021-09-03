#include<string>
#include"LifePotion.h"
#include"NovicePlayer.h"

using namespace std;

LifePotion::LifePotion()
	:ConsumableItem('c', "LifePotion", "回復生命50",
		"用蛇血、龜甲和養樂多製作而成的藥劑，是一個中醫師偶然發現的。據說他那時不小心打翻了可樂......。"
		, 1, 5)
{}

void LifePotion::use(NovicePlayer* n) {
	(*n).setHP((*n).getHP() + 50);
}