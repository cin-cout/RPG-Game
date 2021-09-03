#ifndef  Field_H
#define  Field_H
#include<string>

using namespace std;

class Field {
public:
	Field(const int, int, int, int, int);
	~Field();

	int getCurrentPositionX() const;
	int getCurrentPositionY() const;
	int getVisionWidth() const;
	int getVisionHeight() const;
	string getMapName() const;
	int getMapSymbol(int, int);

	void setPosition(int, int);
	void setMapSymbol(int, int, int);
	void setVisionSize(int, int);

	void display() const;


private:
	int** map_data;
	int current_position_x;
	int current_position_y;
	string map_name;
	int vision_width;
	int vision_height;
	int wid;
	int hei;


};

#endif 

  