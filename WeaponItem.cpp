#include<string>
#include"WeaponItem.h"

using namespace std;

WeaponItem::WeaponItem(char t, string n, string e, string d, int l, int w,int a)
	:Item(t,n,e,d,l,w),attack_increment(a)
{}