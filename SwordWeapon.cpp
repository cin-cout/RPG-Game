#include<string>
#include"SwordWeapon.h"
#include"WeaponItem.h"

using namespace std;

SwordWeapon::SwordWeapon()
	:WeaponItem('w', "破舊長劍", "攻擊力增加10",
		"其實就只是工匠不小心把菜刀做的太長了......。"
		,1, 30,10)
{}