#include<string>
#include"MagicPotion.h"
#include"NovicePlayer.h"

using namespace std;

MagicPotion::MagicPotion()
	:ConsumableItem('c', "MagicPotion", "�^�_�]�O30",
		"�]�O�F�ġA���ڦn���S�g�ƻ���x���ޯ�......�C"
		, 1, 5)
{}

void MagicPotion::use(NovicePlayer* n) {
	(*n).setMP((*n).getMP() + 30);
}