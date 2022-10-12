#include "Date.h"
Date::Date() {};
Date::Date(int day, int mon, int year) {
    ngay = day;
    thang = mon;
    nam = year;
};
Date::~Date() {};
int Date::getNgay() {
    return ngay;
}
int Date::getThang() {
    return thang;
}
int Date::getNam() {
    return nam;
}
bool Date::check(const int& a, const int& b, const int& c)
{
    switch (b)
    {
    case 1:case 3:case 5: case 7: case 8: case 10: case 12:
        if (a <= 0 || a > 31) return false;
        break;
    case 4: case 6: case 9: case 11:
        if (a <= 0 || a > 30) return false;
        break;
    case 2:
        if (c % 400 == 0 || (c % 4 == 0 && c % 100 != 0))
        {
            if (a <= 0 || a > 29) return false;
        }
        else if (a <= 0 || a > 28) return false;
        break;
    default: return false;
    }
    return true;
}
istream& operator>>(istream& in, Date& d)
{
    bool k;
    do {
        k = false;
        cout << "ngay =  "; in >> d.ngay;
        cout << "thang =  "; in >> d.thang;
        cout << "nam =  "; in >> d.nam;
        k = d.check(d.ngay, d.thang, d.nam);
        if (k == false) cout << "khong hop le!\n";
    } while (!k);
    return in;
}
ostream& operator<<(ostream& out, const Date& d)
{
    out << d.ngay << "/" << d.thang << "/" << d.nam;
    return out;
}
