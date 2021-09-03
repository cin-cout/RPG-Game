#include<iostream>
#include<string>
#include<fstream>
#include"windows.h"
#include"Field.h"

using namespace std;

Field::Field(const int m, int cx, int cy, int h, int w) {

	switch (m)
	{
	case 1:
		map_name = "maze4.txt";
		break;
	case 2:
		map_name = "maze3.txt";
		break;
	case 3:
		map_name = "maze1.txt";
		break;
	default:
		break;
	}

	ifstream inf(map_name, ios::in);

	int maze;
	char com;

	inf >> wid >> com >> hei;

	map_data = new int*[hei];
	for (int i = 0; i < hei; i++) {
		map_data[i] = new int[wid];
	}

	for (int i = 0; i < hei; i++) {
		for (int j = 0; j < wid; j++) {
			inf >> maze;
			if (j < (wid - 1)) { inf.seekg(1, ios::cur); }
			map_data[i][j] = maze;
		}
	}

	setPosition(cx, cy);
	setVisionSize(h, w);

}

Field::~Field() {
	for (int i = 0; i < hei; i++) {
		delete[] map_data[i];
	}
	delete[] map_data;
}

int Field::getCurrentPositionX() const {
	return current_position_x;
}

int Field::getCurrentPositionY() const {
	return current_position_y;
}

int Field::getVisionWidth() const {
	return vision_width;
}

int Field::getVisionHeight() const {
	return vision_height;
}

string Field::getMapName() const {
	return map_name;
}

int Field::getMapSymbol(int x, int y) {
	return map_data[x][y];
}

void Field::setPosition(int x, int y) {
	if (map_name == "maze1.txt" ) {
		if (x >11) { current_position_x = 11; }
		else if (x < 0) { current_position_x = 0; }
		else { current_position_x = x; }

		if (y > 11) { current_position_y = 11; }
		else if (y < 0) { current_position_y = 0; }
		else { current_position_y = y; }
	}

	else if (map_name == "maze3.txt") {
		if (x > 11) { current_position_x = 11; }
		else if (x < 0) { current_position_x = 0; }
		else { current_position_x = x; }

		if (y > 6) { current_position_y = 6; }
		else if (y < 0) { current_position_y = 0; }
		else { current_position_y = y; }
	}

	else if (map_name == "maze4.txt") {
		if (x > 11) { current_position_x = 11; }
		else if (x < 0) { current_position_x = 0; }
		else { current_position_x = x; }

		if (y > 4) { current_position_y = 4; }
		else if (y < 0) { current_position_y = 0; }
		else { current_position_y = y; }
	}

}

void Field::setMapSymbol(int x, int y, int s) {
	if (map_name == "maze1.txt") {
		if (0 < x && x < 12 && 0 < y && y < 12) {
			map_data[x][y] = s;
		}
	}
	else if (map_name == "maze3.txt") {
		if (0 < x && x < 12 && 0 < y && y < 7) {
			map_data[x][y] = s;
		}
	}
	else if (map_name == "maze4.txt") {
		if (0 < x && x < 12 && 0 < y && y < 5) {
			map_data[x][y] = s;
		}
	}
}

void Field::setVisionSize(int h, int w) {
	vision_width = w;
	vision_height = h;
}

void Field::display() const {

	int ph = ((getVisionHeight() - 1) / 2);
	int pw = ((getVisionWidth() - 1) / 2);

	int uh = getCurrentPositionY() + ph;
	int lh = getCurrentPositionY() - ph;
	int uw = getCurrentPositionX() + pw;
	int lw = getCurrentPositionX() - pw;

	if (map_name == "maze1.txt") {
		lh = (lh < 0) ? 0 : lh;
		uh = (uh > 11) ? 11 : uh;
		lw = (lw < 0) ? 0 : lw;
		uw = (uw > 11) ? 11 : uw;
	}

	if (map_name == "maze3.txt") {
		lh = (lh < 0) ? 0 : lh;
		uh = (uh > 6) ? 6 : uh;
		lw = (lw < 0) ? 0 : lw;
		uw = (uw > 11) ? 11 : uw;
	}

	if (map_name == "maze4.txt") {
		lh = (lh < 0) ? 0 : lh;
		uh = (uh > 4) ? 4 : uh;
		lw = (lw < 0) ? 0 : lw;
		uw = (uw > 11) ? 11 : uw;
	}

	cout << endl;
	for (int i = lh; i <= uh; i++) {
		for (int j = lw; j <= uw; j++) {
			if(i==getCurrentPositionY() && j==getCurrentPositionX()){ 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
					FOREGROUND_GREEN | FOREGROUND_BLUE);
				cout << "○"; 
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
					FOREGROUND_GREEN );
				switch (map_data[i][j])
				{
				case 0:
					cout << "  ";
					break;
				case 1:
					cout << "■";
					break;
				case 200:
					cout << "  ";
					break;
				case 201:
					cout << "★";
					break;
				default:
					cout << " ?";
					break;
				}
			}
		}
		cout << endl;

	}
}