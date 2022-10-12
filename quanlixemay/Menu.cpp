#include "Menu.h"
#include"GotoXY.h"



Menu::Menu() {
	item = new string[100];

	_numberOfItem = 4;

	item[0] = "QUAN LY DANH MUC";

	item[1] = "QUAN LY DON HANG";

	item[2] = "THONG KE BAO CAO";

	item[3] = "THOAT";

	item1 = new string[100];
	_numberOfItem1 = 13;

	item1[0] = "Quan ly Hang xe";

	item1[1] = "Xem danh sach cac hang xe";
	item1[2] = "Them Hang xe";
	item1[3] = "Xoa Hang xe";
	item1[4] = "Sua Hang xe";
	item1[5] = "Quay lai";

	item1[6] = "Quan ly Xe may";
	item1[7] = "Xem danh sach cac xe may theo hang";
	item1[8] = "Them xe may";
	item1[9] = "Xoa xe may";
	item1[10] = "Sua xe may";
	item1[11] = "Quay lai";

	item1[12] = "Quay lai";


	item2 = new string[100];
	_numberOfItem2 = 7;
	item2[0] = "Danh sach don hang";
	item2[1] = "Next";
	item2[2] = "Them";
	item2[3] = "Xem chi tiet don hang";
	item2[4] = "Cap nhat";
	item2[5] = "Xoa";
	item2[6] = "Quay lai";

	//Thong ke bao cao
	item3 = new string[100];
	_numberOfItem3 = 4;
	item3[0] = "Cac mat hang sap het";
	item3[1] = "Cac mat hang ban chay trong thang truoc";
	item3[2] = "Doanh thu, loi nhuan";
	item3[3] = "Quay lai";
}

Menu::~Menu() {}

void Menu::printMenu() {

	int i = 0;
	gotoxy(21, 3); cout << item[i++];
	gotoxy(42, 3); cout << item[i++];
	gotoxy(63, 3); cout << item[i++];
	gotoxy(84, 3); cout << item[i++];

}

void Menu::deleteMenu() {//Xóa menu khi kết thúc chương trình bằng cách viết đè kí tự trắng

	for (int i = 2; i < 4; i++) {
		for (int j = 0; j < 150; j++)
		{
			gotoxy(j, i);
			cout << " ";
		}
	}
}


int Menu::numberOfItem() {
	return _numberOfItem;
}

string* Menu::getItem() {
	return item;
}

void Menu::printMenuQLDM() {

	gotoxy(50, 5); cout << "QUAN LY DANH MUC";
	gotoxy(30, 7); cout << item1[0];
	gotoxy(55, 7); cout << item1[6];
	gotoxy(79, 7); cout << item1[12];
}
void Menu::printMenuQLDMcon1() {
	gotoxy(20, 9); cout << item1[1];
	gotoxy(50, 9); cout << item1[2];
	gotoxy(67, 9); cout << item1[3];
	gotoxy(83, 9); cout << item1[4];
	gotoxy(99, 9); cout << item1[5];
}
void Menu::deleteMenuQLDMcon1() {
	for (int i = 0; i < 150; i++) {
		gotoxy(i, 9); cout << " ";
	}
}
void Menu::printMenuQLDMcon2() {
	gotoxy(20, 9); cout << item1[7];
	gotoxy(59, 9); cout << item1[8];
	gotoxy(75, 9); cout << item1[9];
	gotoxy(90, 9); cout << item1[10];
	gotoxy(105, 9); cout << item1[11];
}
void Menu::deleteMenuQLDMcon2() {
	for (int i = 0; i < 150; i++) {
		gotoxy(i, 9); cout << " ";
	}
}
void Menu::deleteMenuQLDM() {


	for (int i = 0; i <= 150; i++) {
		for (int j = 3; j < 30; j++) {
			gotoxy(i, j);
			cout << " ";
		}
	}
}

int Menu::numberOfItem1() {
	return _numberOfItem1;
}

string* Menu::getItem1() {
	return item1;
}


//Quan ly don hang
void Menu::printMenuQLDH() {

	int i = 0;
	gotoxy(50, 3);
	cout << "QUAN LY DON HANG";

	gotoxy(15, 5);
	cout << item2[i++];
	gotoxy(38, 5);
	cout << item2[i++];
	gotoxy(47, 5);
	cout << item2[i++];
	gotoxy(56, 5);
	cout << item2[i++];
	gotoxy(82, 5);
	cout << item2[i++];
	gotoxy(95, 5);
	cout << item2[i++];
	gotoxy(103, 5);
	cout << item2[i++];


}

void Menu::deleteMenuQLDH() {

	for (int i = 50; i <= 100; i++) {
		gotoxy(i, 3);
		cout << " ";
	}
	for (int i = 0; i <= 130; i++) {
		gotoxy(i, 5);
		cout << " ";
	}
}

int Menu::numberOfItem2() {
	return _numberOfItem2;
}

string* Menu::getItem2() {
	return item2;
}
//Thong ke bao cao
void Menu::printMenuTKBC() {

	int i = 0;

	gotoxy(50, 3);
	cout << "THONG KE BAO CAO";
	gotoxy(5, 5);
	cout << item3[i++];
	gotoxy(30, 5);
	cout << item3[i++];
	gotoxy(74, 5);
	cout << item3[i++];
	gotoxy(99, 5);
	cout << item3[i++];
}

void Menu::deleteMenuTKBC() {

	for (int i = 50; i <= 100; i++) {
		gotoxy(i, 3);
		cout << " ";
	}
	for (int i = 0; i <= 130; i++) {
		gotoxy(i, 4);
		cout << " ";
	}
}

int Menu::numberOfItem3() {
	return _numberOfItem3;
}

string* Menu::getItem3() {
	return item3;
}