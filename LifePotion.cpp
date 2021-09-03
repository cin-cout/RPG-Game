#include<string>
#include"LifePotion.h"
#include"NovicePlayer.h"

using namespace std;

LifePotion::LifePotion()
	:ConsumableItem('c', "LifePotion", "�^�_�ͩR50",
		"�γD��B�t�ҩM�i�֦h�s�@�Ӧ����ľ��A�O�@�Ӥ���v���M�o�{���C�ڻ��L���ɤ��p�ߥ�½�F�i��......�C"
		, 1, 5)
{}

void LifePotion::use(NovicePlayer* n) {
	(*n).setHP((*n).getHP() + 50);
}