#include "GotoXY.h"

void gotoxy(int column, int line)

{

	COORD coord;

	coord.X = column;

	coord.Y = line;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

int move() {

	char c = _getch();

	if ((int)c == -32) c = _getch();

	switch ((int)c) {

	case 80:
		return 1; //cout << "Xuong";

	case 72:
		return 2; //cout << "Len";

	case 77:
		return 3; //cout << "Phai";       

	case 75:
		return 4; //cout << "Trai";

	case 27:
		return 8; //Nut ESC thoat

	case 13:
		return 5; //Nut Enter

	default:
		return 0; //cout << "Sai";

	}

}

string Tien(string str) {
	int len = str.length();
	int tam = 0;
	for (int i = len; i >= 0; i--) {

		if (tam == 3 && i != 0) {
			str.insert(i, ".");
			tam = 0;
		}
		tam++;
	}
	return str;
}