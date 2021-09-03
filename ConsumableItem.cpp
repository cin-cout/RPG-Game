#include<string>
#include"ConsumableItem.h"
#include"NovicePlayer.h"

using namespace std;

ConsumableItem::ConsumableItem(char t, string n, string e, string d, int l, int w)
	:Item(t, n, e, d, l, w)
{}

void ConsumableItem::use(NovicePlayer*) {}