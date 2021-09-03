#ifndef Item_H
#define Item_H

#include<string>

using namespace std;

class Item {
public:
	Item(char, string, string, string, int, int);

	const char type;
	const string name;
	const string effects;
	const string description;
	const int level_required;
	const int weight;
};

#endif // !Item_H

