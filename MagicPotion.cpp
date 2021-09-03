#include<string>
#include"MagicPotion.h"
#include"NovicePlayer.h"

using namespace std;

MagicPotion::MagicPotion()
	:ConsumableItem('c', "MagicPotion", "回復魔力30",
		"魔力靈藥，但我好像沒寫甚麼很屌的技能......。"
		, 1, 5)
{}

void MagicPotion::use(NovicePlayer* n) {
	(*n).setMP((*n).getMP() + 30);
}