#pragma once
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "GotoXY.h";
#include "Tokenizer.h"
using namespace std;


class XeMay {
private:
	string _tenHang;
	string _tenXe;
	string _loaixe;
	int _CC;
	int _giaGoc;
	int _giaBan;
	int _soluong;
	int _soluongBan;
public:
	XeMay();

	XeMay(string tenHang, string tenXe, string loaiXe, int CC, int giaGoc, int giaBan, int SL, int _soluongBan);

	~XeMay();

	//getter
	string getTenHang();

	string getTenXe();

	string getLoaiXe();

	int getCC();

	int getGiaGoc();

	int getGiaBan();

	int getSL();

	int getSLBan();

	//setter

	void setTenHang(string tenhang);

	void setTenXe(string tenxe);

	void setLoaiXe(string loaixe);

	void setCC(int CC);

	void setGiaGoc(int giagoc);

	void setGiaBan(int giaban);

	void setSL(int SL);

	void setSLBan(int SL);

	//

	void input();

	void  output();

	static XeMay* parse(string buffer);


};