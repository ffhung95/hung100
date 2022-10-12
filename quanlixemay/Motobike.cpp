#include "Motobike.h"




XeMay::XeMay() {
	_tenHang = "";
	_tenXe = "";
	_loaixe = "";
	_CC = 0;
	_giaGoc = 0;
	_giaBan = 0;
	_soluong = 0;
}

XeMay::XeMay(string tenHang, string tenXe, string loaiXe, int CC, int giaGoc, int giaBan, int SL, int SLBan) {
	_tenHang = tenHang;
	_tenXe = tenXe;
	_loaixe = loaiXe;
	_CC = CC;
	_giaGoc = giaGoc;
	_giaBan = giaBan;
	_soluong = SL;
	_soluongBan = SLBan;
}

XeMay::~XeMay() {
	_tenHang = "";
	_tenXe = "";
	_loaixe = "";
	_CC = 0;
	_giaGoc = 0;
	_giaBan = 0;
	_soluong = 0;
}

string XeMay::getTenHang() {
	return _tenHang;
}

string XeMay::getTenXe() {
	return _tenXe;
}

string XeMay::getLoaiXe() {
	return _loaixe;
}

int XeMay::getCC() {
	return _CC;
}

int XeMay::getGiaGoc() {
	return _giaGoc;
}

int XeMay::getGiaBan()
{
	return _giaBan;
}

int XeMay::getSL() {
	return _soluong;
}

int XeMay::getSLBan() {
	return _soluongBan;
}

void XeMay::setTenHang(string tenhang) {
	_tenHang = tenhang;
}

void XeMay::setTenXe(string tenxe) {
	_tenXe = tenxe;
}

void XeMay::setLoaiXe(string loaixe) {
	_loaixe = loaixe;
}

void XeMay::setCC(int CC) {
	_CC = CC;
}

void XeMay::setGiaGoc(int giagoc) {
	_giaGoc = giagoc;
}

void XeMay::setGiaBan(int giaban) {
	_giaBan = giaban;
}

void XeMay::setSL(int SL) {
	_soluong = SL;
}

void XeMay::setSLBan(int SL) {
	_soluongBan = SL;
}

void XeMay::input() {
	int line = 9;
	gotoxy(30, line + 2);
	cout << "------------Nhap cac thong tin cua xe may------------";
	gotoxy(30, line + 3); cout << "Nhap ten hang xe: ";
	cin >> _tenHang;

	gotoxy(30, line + 4); cout << "Nhap ten xe may: ";
	cin >> _tenXe;

	gotoxy(30, line + 5); cout << "Nhap loai xe: ";
	cin.ignore();
	fflush(stdin);
	getline(cin, _loaixe);

	gotoxy(30, line + 6); cout << "Nhap phan phoi: ";
	cin >> _CC;

	gotoxy(30, line + 7); cout << "Nhap gia goc: ";
	cin >> _giaGoc;

	gotoxy(30, line + 8); cout << "Nhap gia ban: ";
	cin >> _giaBan;

	gotoxy(30, line + 9); cout << "Nhap so luong xe: ";
	cin >> _soluong;

	_soluongBan = 0;



}

void  XeMay::output() {

}

XeMay* XeMay::parse(string buffer) {
	vector<string> tokens = Tokenizer::split(buffer, ",");
	string tenhang = tokens[0];
	string tenxe = tokens[1];
	string loaixe = tokens[2];
	int CC = stoi(tokens[3]);
	int giagoc = stoi(tokens[4]);
	int giaban = stoi(tokens[5]);
	int sl = stoi(tokens[6]);
	int slban = stoi(tokens[7]);
	XeMay* result = new XeMay(tenhang, tenxe, loaixe, CC, giagoc, giaban, sl, slban);
	return result;
}