#pragma once
#pragma once
#include "GotoXY.h"

class Menu {
private:
	string* item; //Mảng lưu tên của các menu
	int _numberOfItem; //Số lượng menu
	//Quan ly danh muc
	string* item1;
	int _numberOfItem1;
	//Quan ly don hang
	string* item2;
	int _numberOfItem2;
	//Thong ke bao cao
	string* item3;
	int _numberOfItem3;
public:

	Menu();

	~Menu();

	void printMenu();

	void deleteMenu();

	int numberOfItem();

	string* getItem();

	// Quan ly danh muc
	void printMenuQLDM();
	void deleteMenuQLDM();
	void printMenuQLDMcon1();
	void deleteMenuQLDMcon1();
	void deleteMenuQLDMcon2();
	void printMenuQLDMcon2();


	int numberOfItem1();

	string* getItem1();

	//Quan ly don hang
	void printMenuQLDH();

	void deleteMenuQLDH();

	int numberOfItem2();

	string* getItem2();

	//Thong ke bao cao
	void printMenuTKBC();

	void deleteMenuTKBC();

	int numberOfItem3();

	string* getItem3();
};

