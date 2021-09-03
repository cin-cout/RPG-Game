#include<string>
#include"AxeWeapon.h"
#include"WeaponItem.h"

using namespace std;

AxeWeapon::AxeWeapon()
	:WeaponItem('w', "強力斧頭", "攻擊力增加40.", 
		"削鐵如泥的無敵武器，雖然外型普普通通，就蘊含著神奇的力量，所謂可遇不可求！"
		, 5, 50, 40)
{}