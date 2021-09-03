#include"Item.h"
#include<string>

Item::Item(char t,string n,string e,string d,int l,int w) 
	:type(t),name(n), effects(e), description(d), level_required(l), weight(w)
{}