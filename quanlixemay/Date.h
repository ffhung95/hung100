#pragma once
#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Date {
private:
	int ngay;
	int thang;
	int nam;
public:
	Date();
	Date(int day, int mon, int year);
	~Date();
	int getNgay();
	int getThang();
	int getNam();
	bool check(const int&, const int&, const int&);
	friend ostream& operator<<(ostream& out, const Date&);
	friend istream& operator>>(istream& in, Date&);
};


