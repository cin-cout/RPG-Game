#include<string>
#include"ArmorItem.h"

using namespace std;

ArmorItem::ArmorItem(char t, string n, string e, string d, int l, int w, int di)
	:Item(t, n, e, d, l, w), defense_increment(di)
{}