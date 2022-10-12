#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <sstream>
#include <conio.h>
#include <windows.h>
#include "Date.h"
#include "Motobike.h"
#include "MotorbikeBrand.h"
#include "QuanLyDanhMuc.h"
#include "Menu.h"
#include "GotoXY.h"
#include <ctime>
#include <fstream>
#include "Tokenizer.h"
#include <Windows.h>
using namespace std;

void printMenuQLDM();
void printMenu();
QuanLyDanhMuc inputDanhMuc() {
	QuanLyDanhMuc store;
	ifstream readerBrand("E:\\qlbanxe\\brands.txt");
	ifstream reader("E:\\qlbanxe\\xemay.txt");
	
	if (!readerBrand.is_open() || !reader.is_open()) {
		cout << "failed";
	}
	else {
		string buffer;
		getline(readerBrand, buffer);
		int count = stoi(buffer);
		for (int i = 0; i < count; i++) {
			
			getline(readerBrand, buffer);
			vector<XeMay*> tempMotorbike;
			string buffer1;
			getline(reader, buffer1);
			int n = stoi(buffer1);
			if (n == 0) {

			}
			else {
				for (int j = 0; j < n; j++) {
					
					getline(reader, buffer1);
					XeMay* xemay = NULL;
					xemay = XeMay::parse(buffer1);
					tempMotorbike.push_back(xemay);
				}
			}
			MotorbikeBrand temp(buffer, tempMotorbike);
			store.themTenHangXe(temp);
			
		}
		reader.close();
		readerBrand.close();
	}
	return store;
}

QuanLyDanhMuc store = inputDanhMuc();

class DonHang {
private:
	string _TenDonHang;
	string _tenKhachHang;
	string _sdt;
	Date _ngaymua;
	int _soluong;
	int _doanhthu;
	int _loinhuan;
	vector<XeMay*> _motorbikes;
	vector<int> _slxe;
public:
	DonHang() {}
	DonHang(string TenDonHang, string KH,string sdt, Date ngaymua, int SL, int doanhthu, int loinhuan, vector<XeMay*> motorbikes, vector<int> soluongxe) {
		_TenDonHang = TenDonHang;
		_tenKhachHang = KH;
		_sdt = sdt;
		_ngaymua = ngaymua;
		_soluong = SL;
		_doanhthu = doanhthu;
		_loinhuan = loinhuan;
		_motorbikes = motorbikes;
		_slxe = soluongxe;
	}
	string getTenDonHang() {
		return _TenDonHang;
	}
	string getTenKH() {
		return _tenKhachHang;
	}
	string getSDT() {
		return _sdt;
	}
	int getDoanhThu() {
		return _doanhthu;
	}
	int getLoiNhuan() {
		return _loinhuan;
	}
	void setMadonHang(string str) {
		_TenDonHang = str;
	}
	void setLoiNhuan(int loinhuan) {
		_loinhuan = loinhuan;
	}
	void setDoanhThu(int doanhthu) {
		_doanhthu = doanhthu;
	}
	void setMotorbike(vector<XeMay*> motobike) {
		_motorbikes = motobike;
	}
	void setSLtype(vector<int> soluong) {
		_slxe = soluong;
	}
	Date getNgayMua() {
		return _ngaymua;
	}
	int getSL() {
		return _soluong;
	}
	vector<XeMay*> getMotorbikes() {
		return _motorbikes;
	}
	vector<int> getsoluongmoiloai() {
		return _slxe;
	}
	void NhapDonHang() {
		
		cout << "\nNhap ho ten Khach hang: ";
		cin.ignore();
		fflush(stdin);
		getline(cin, _tenKhachHang);

		cout << "\nNhap so dien thoai: ";
		cin >> _sdt;

		cout << "\nNhap thoi gian mua hang: " << endl;
		cin >> _ngaymua;
		cout << "\nNhap so luong: ";
		cin >> _soluong;
		int tam = _soluong;
		do {
			cout << "\nNhap thong tin xe may: ";
			string tenHang;
			string tenXe;
			cout << "\nNhap ten Hang: ";
			cin >> tenHang;
			cout << "\nNhap ten Xe: ";
			cin >> tenXe;
			cout << "\nNhap so luong xe "<<tenXe <<" : ";
			int soluong;
			cin >> soluong;

			if (store.TimKiemMotXeMay(tenHang, tenXe) != NULL) {
				int tam1 = store.TimKiemMotXeMay(tenHang, tenXe)->getSL();
				_motorbikes.push_back(store.TimKiemMotXeMay(tenHang, tenXe));
				tam = tam - soluong;
				store.TimKiemMotXeMay(tenHang, tenXe)->setSL(tam1 - soluong);
				int tam2 = store.TimKiemMotXeMay(tenHang, tenXe)->getSLBan();
				store.TimKiemMotXeMay(tenHang, tenXe)->setSLBan(tam2 + soluong);
				_doanhthu = _doanhthu + store.TimKiemMotXeMay(tenHang, tenXe)->getGiaBan()*soluong;
				_loinhuan = _loinhuan + _doanhthu - store.TimKiemMotXeMay(tenHang, tenXe)->getGiaGoc()*soluong;
				_slxe.push_back(soluong);
			}
			else {
				cout << "\nKhong ton tai!" << endl;
				
			}
		} while (tam > 0);
	}
	void CapNhatDonHang() {
		
		gotoxy(40, 8); cout << "An phim 1 de sua Ma Don hang.";
		gotoxy(40, 9);  cout << "An phim 2 de sua Ten Khach hang.";
		gotoxy(40, 10); cout << "An phim 3 de sua So dien thoai.";
		gotoxy(40, 11); cout << "An phim 4 de sua Thoi Gian mua Xe." << endl<<endl;
		int luachon = 1;
		while (luachon != 0) {
			cout << "Nhap lua chon cua ban (An phim 0 de thoat): ";
			cin >> luachon;
			switch (luachon) {
			case 1: {
				cout << "Nhap lai Ma don hang: ";
				string tendonhang;
				cin >> tendonhang;
				_TenDonHang = tendonhang;
				break;
			}
			case 2: {
				cout << "\nNhap lai ten Khach hang: ";
				string tenKH;
				cin.ignore();
				fflush(stdin);
				getline(cin, tenKH);
				_tenKhachHang = tenKH;
				break;
			}
			case 3: {
				cout << "\nNhap lai So dien thoai: ";
				string sdt;
				cin >> sdt;
				_sdt = sdt;
				break;
			}
			case 4: {
				cout << "\nNhap lai Thoi Gian mua hang:" << endl;
				Date ngaymua;
				cin >> ngaymua;
				_ngaymua = ngaymua;
				break;
			}
			case 0:
				break;
			default:
				break;
			}

		}
	}
	void XuatDonHang() {
		gotoxy(30, 8);
		cout << "------------------Chi tiet don hang------------------";
		gotoxy(10, 9); cout << "Ma don hang: " << _TenDonHang;
		gotoxy(10, 10); cout << "Ho ten Khach hang: " << _tenKhachHang;
		gotoxy(10, 11); cout << "Thoi gian mua hang: " << _ngaymua;
		gotoxy(10, 12); cout << "So dien thoai lien he: " << _sdt;
		gotoxy(10, 13); cout << "So luong: " << _soluong;
		gotoxy(60, 9); cout << "Tong cong";
		gotoxy(60, 10); cout << Tien(to_string(_doanhthu)) << " vnd";
		
		gotoxy(30, 14);
		cout << "--------------Thong tin cac xe may da mua--------------";
		gotoxy(10, 17); cout << "STT  |  ";
		gotoxy(18, 17); cout << "Ten hang" << "   |   " << "Ten xe" << "   |   "
			<< "Loai xe" << "   |   " << "CC" << "   |   " << "Gia ban" << "   |   " << "So luong";

		for (int i = 0; i < _motorbikes.size(); i++) {
			gotoxy(11, 18 + i); cout << i + 1;
			gotoxy(15, 18 + i); cout << "|";
			gotoxy(18, 18 + i); cout << _motorbikes[i]->getTenHang();
			gotoxy(29, 18 + i); cout << "|";
			gotoxy(33, 18 + i); cout << _motorbikes[i]->getTenXe();
			gotoxy(42, 18 + i); cout << "|";
			gotoxy(45, 18 + i); cout << _motorbikes[i]->getLoaiXe();
			gotoxy(56, 18 + i); cout << "|";
			gotoxy(60, 18 + i); cout << _motorbikes[i]->getCC();
			gotoxy(65, 18 + i); cout << "|";
			gotoxy(67, 18 + i); cout << Tien(to_string(_motorbikes[i]->getGiaBan()));
			gotoxy(79, 18 + i); cout << "|";
			gotoxy(84, 18 + i); cout << _slxe[i];
		}
	}
	
	static DonHang* parse(string buffer)
	{
		vector<string> tokens = Tokenizer::split(buffer, ",");
		string  tenDH = tokens[0];
		string tenKH = tokens[1];
		string sdt = tokens[2];
		int ngay = stoi(tokens[3]);
		int thang = stoi(tokens[4]);
		int nam = stoi(tokens[5]);
		Date ngaymua = Date(ngay, thang, nam);
		int soluong = stoi(tokens[6]);
		vector<int> SLtype;
		vector<XeMay*> motorbike;
		DonHang *result =new DonHang(tenDH, tenKH,sdt, ngaymua, soluong,0,0, motorbike, SLtype);
		return result;
	}

};

class QuanLyDonHang {
private:
	vector <string> ordersName;
	vector<DonHang>  orders;
public:
	vector<DonHang> getOders() {
		return orders;
	}
	vector<string> getordersName() {
		return ordersName;
	}
	void themDonhang(string name, DonHang order) {
		ordersName.push_back(name);
		orders.push_back(order);
	}
	void XemDanhSachCacDonHang() {
		gotoxy(3, 9);
		cout << "----------Danh sach cac don hang hien co----------";
		
		if (orders.size() == 0) {
			gotoxy(35, 9);
			cout << "Khong ton tai don hang nao!";
		}
		else {
			gotoxy(20, 10);
			cout << "STT    Ma don hang";
			for (int i = 0; i < orders.size(); i++) {
				gotoxy(20, 11 + i);
				cout << " " << i + 1 << "      " << orders[i].getTenDonHang();
			}
			cout << endl;
		}
	}
	void ChitietDonHang(string tenDonHang) {
		int check = 0;
		for (int i = 0; i < orders.size(); i++) {
			if (orders[i].getTenDonHang() == tenDonHang) {
				check = 1;
				orders[i].XuatDonHang();
				cout << endl;
				break;
			}
		}
		if (check == 0) {
			cout << "Khong ton tai don hang nay!";
		}
	}
	void CapNhatDonHang(string tenDonHang) {
		int check = 0;
		for (int i = 0; i < orders.size(); i++) {
			if (orders[i].getTenDonHang() == tenDonHang) {
				orders[i].CapNhatDonHang();
				check = 1;
			}
		}
		for (int a = 6; a < 30; a++) {
			for (int b = 0; b < 150; b++) {
				gotoxy(b, a);
				cout << " ";
			}
		}
		if (check == 0) {
			gotoxy(50, 10);
			cout << "Khong tim thay don hang " << tenDonHang << " !";
		}
		else {
			gotoxy(50, 10);
			cout << "Cap nhat thanh cong !";
		}
	}
	void XoaDonHang(string tenDonHang) {
		int check = 0;
		vector<XeMay*> temp;
		vector<int> SLmoiloai;
		for (int i = 0; i < orders.size(); i++) {
			if (orders[i].getTenDonHang() == tenDonHang) {
				temp = orders[i].getMotorbikes();
				SLmoiloai = orders[i].getsoluongmoiloai();
				orders.erase(orders.begin() + i);
				check = 1;
			}
		}
		if (check == 1) {
			gotoxy(45, 10);
			cout << "Da xoa thanh cong don hang "<<tenDonHang<<"!";
			//cap nhat lai so luong cua moi xe
			for (int i = 0; i < temp.size(); i++) {
				for (int j = 0; j < store.getBrand().size(); j++) {
					for (int k = 0; k < store.getBrand()[j].getMotorbikes().size(); k++) {
						if (store.getBrand()[j].getMotorbikes()[k]->getTenHang() == temp[i]->getTenHang() &&
							store.getBrand()[j].getMotorbikes()[k]->getTenXe() == temp[i]->getTenXe()) {
							int tam1 = store.getBrand()[j].getMotorbikes()[k]->getSL();
							int tam2 = store.getBrand()[j].getMotorbikes()[k]->getSLBan();
							store.getBrand()[j].getMotorbikes()[k]->setSL(tam1 + SLmoiloai[i]);
							store.getBrand()[j].getMotorbikes()[k]->setSLBan(tam2 - SLmoiloai[i]);
						}
					}
				}
			}
		}
		else {
			gotoxy(45, 10);
			cout << "Khong ton tai don hang: "<<tenDonHang<<"!";
		}
	}
	void DoanhThu(int thang, int nam) {
		int doanhthu = 0;
		for (int i = 0; i < orders.size(); i++) {
			if (orders[i].getNgayMua().getThang() == thang && orders[i].getNgayMua().getNam() == nam) {
				doanhthu = orders[i].getDoanhThu() + doanhthu;
			}
		}
		cout << "Doanh thu thang " << thang << " nam " << nam << " la: " << Tien(to_string(doanhthu)) << " vnd" << endl;
	}
	void LoiNhuan(int thang, int nam) {
		int loinhuan=0;
		for (int i = 0; i < orders.size(); i++) {
			if (orders[i].getNgayMua().getThang() == thang && orders[i].getNgayMua().getNam() == nam) {
				loinhuan =loinhuan + orders[i].getLoiNhuan();
			}
		}
		cout << "Loi nhuan thang " << thang << " nam " << nam << " la: " <<Tien(to_string(loinhuan)) << " vnd" << endl;
	}
	//void SPbanchaytrongthangtruoc();
		
};

QuanLyDonHang inputFileDonHang() {
	QuanLyDonHang result;
	ifstream reader("donhang.txt");

	if (!reader.is_open()) {
		cout << "failed";
	}
	else {
		string buffer;
		getline(reader, buffer);
		int count = stoi(buffer);
		for (int i = 0; i < count; i++) {
			getline(reader, buffer);
			DonHang* temp = NULL;
			temp = DonHang::parse(buffer);
			int line = temp->getSL();
			vector<int>SLtype;
			vector<XeMay*> motobikes;
			int doanhthu=0;
			int loinhuan=0;
			while (line != 0) {
				getline(reader, buffer);
				int soluong = stoi(buffer);
				getline(reader, buffer);
				XeMay* xemay = NULL;
				xemay = XeMay::parse(buffer);
				SLtype.push_back(soluong);
				motobikes.push_back(xemay);
				doanhthu = doanhthu + soluong * (xemay->getGiaBan());
				loinhuan = loinhuan +  soluong * (xemay->getGiaBan()- xemay->getGiaGoc());
				line = line - soluong;
			}
			temp->setMotorbike(motobikes);
			temp->setSLtype(SLtype);
			temp->setDoanhThu(doanhthu);
			temp->setLoiNhuan(loinhuan);

			result.themDonhang(temp->getTenDonHang(), *temp);
		}
	}
	return result;
}

QuanLyDonHang orderManagement = inputFileDonHang();

class ThongKeBaoCao {
public:
	void DSCacMatHangSapHet() {
		store.SanPhamSapHet();
	}
	void SPbanchaynhat() {
		// thời gian hiện tại tính theo hệ thống
		time_t t = time(0);   // get time now
		struct tm now;
		localtime_s(&now, &t);
		//tm* now = localtime(&t);
		int thang = now.tm_mon ;
		int nam = now.tm_year + 1900;
		
		vector<XeMay*> temp1;
		vector<DonHang> tam = orderManagement.getOders();
		vector <int>soluong;
		int check = 0;
		for (int i = 0; i < tam.size(); i++) {
			if (tam[i].getNgayMua().getThang() == thang && tam[i].getNgayMua().getNam() == nam) {
				check = 1;
				vector<XeMay*> tam1 = tam[i].getMotorbikes();
				vector<int> tam2 = tam[i].getsoluongmoiloai();
				for (int j = 0; j < tam1.size(); j++) {
					temp1.push_back(tam1[j]);
					soluong.push_back(tam2[j]);
					
				}
			}
		}

		if (check == 1) {
			
			gotoxy(40, 9); cout << "-----San pham ban chay nhat trong thang truoc-----";
			gotoxy(0, 11); cout << "STT  |  ";
			gotoxy(8, 11); cout << "Ten hang" << "   |   " << "Ten xe" << "   |   "
				<< "Loai xe" << "   |   " << "CC" << "   |   " << "Gia goc" << "   |   "
				<< "Gia ban" << "   |   " << "SL con lai" << "   | " << "SL ban trong thang";
			int stt = 0;
			for (int i = 0; i < temp1.size(); i++) {
				gotoxy(1, 12 + stt); cout << stt + 1;
				gotoxy(5, 12 + stt); cout << "|";
				gotoxy(8, 12 + stt); cout << temp1[i]->getTenHang();
				gotoxy(19, 12 + stt); cout << "|";
				gotoxy(23, 12 + stt); cout << temp1[i]->getTenXe();
				gotoxy(32, 12 + stt); cout << "|";
				gotoxy(35, 12 + stt); cout << temp1[i]->getLoaiXe();
				gotoxy(46, 12 + stt); cout << "|";
				gotoxy(50, 12 + stt); cout << temp1[i]->getCC();
				gotoxy(55, 12 + stt); cout << "|";
				gotoxy(57, 12 + stt); cout << Tien(to_string(temp1[i]->getGiaGoc()));
				gotoxy(69, 12 + stt); cout << "|";
				gotoxy(71, 12 + stt); cout << Tien(to_string(temp1[i]->getGiaBan())) ;
				gotoxy(83, 12 + stt); cout << "|";
				gotoxy(90, 12 + stt); cout << temp1[i]->getSL();
				gotoxy(100, 12 + stt); cout << "|";
				gotoxy(106, 12 + stt); cout << soluong[i]; //temp1[i]->getSLBan();
				stt++;
			}
		}
		

		else {
			gotoxy(10, 11);
			cout << "Thang truoc khong co don hang nao!";
		}
	}

	void DoanhThu(int thang, int nam) {
		
		orderManagement.DoanhThu(thang, nam);
	}
	void LoiNhuan(int thang, int nam) {
		
		orderManagement.LoiNhuan(thang, nam);
	}
};

ThongKeBaoCao TKBC;
void printMenuQLDMcon1() {
	Menu menu;
	int x;
	int line = 9;// vị trí dòng của menu
	int col = 18; //vi tri cot cua menu
	bool thoat = false;
	menu.printMenuQLDMcon1();
	int i = 1;

	gotoxy(col, line);
	cout << (char)62; //Vẽ con trỏ trỏ tới menu

	while (!thoat) {

		if (_kbhit()) {

			x = move();

			gotoxy(col, line);
			cout << " "; //Xóa con trỏ ở vị trí cũ

			switch (x) {

			case 1: {}

			case 3: {
				if (i == 1) {
					col = col + 30;
				}
				if (i == 2) {
					col = col + 17;
				}
				if (i == 3) {
					col = col+16;
				}
				if (i == 4) {
					col = col + 16;
				}
				if (i == 5) {
					i = 0;
					col = 18;
				}
				i++;
				break;
			}

			case 2: {}

			case 4: {
				if (i == 5) {
					col = col - 16;
				}
				if (i == 4) {
					col = col - 16;
				}
				if (i == 3) {
					col = col-17;
				}
				if (i == 2) {
					col = col - 30;
				}
				if (i == 1) {
					col = 97;
					i = 6;
				}
				i--;
				break;
			}

			case 5:
			{
				if (menu.getItem1()[i] == "Them Hang xe") {
					for (int a = line+1; a < 30; a++) {
						for (int b = 0; b < 150; b++) {
							gotoxy(b, a);
							cout << " ";
						}
					}
					gotoxy(col, line + 4);
					store.DanhSachCacHangXe();
					string tenHang;
					gotoxy(col, line + 2);
					cout << "\nNhap ten hang muon them: ";
					cin >> tenHang;
					vector<XeMay*> xemay;
					MotorbikeBrand temp(tenHang, xemay);
					int check = 0;
					for (int i = 0; i < store.getBrand().size(); i++) {
						if (store.getBrand()[i].getTenHang() == tenHang) {
							check = 1;
							break;
						}
					}
					if (check == 1) {
						gotoxy(45, line + 3); cout << "Hang xe " << tenHang << " da ton tai!";
					}
					else {
						store.themTenHangXe(temp);

						for (int a = line + 1; a < 30; a++) {
							for (int b = 0; b < 150; b++) {
								gotoxy(b, a);
								cout << " ";
							}
						}
						gotoxy(col, line + 4);
						store.DanhSachCacHangXe();
					}
					break;
				}
				if (menu.getItem1()[i] == "Xoa Hang xe") {
					for (int a = line+1; a < 30; a++) {
						for (int b = 0; b < 150; b++) {
							gotoxy(b, a);
							cout << " ";
						}
					}
					gotoxy(col, line + 4);
					store.DanhSachCacHangXe();
					string tenHang;
					gotoxy(col, line + 2);
					cout << "\nNhap ten hang muon xoa: ";
					cin >> tenHang;
					store.XoaTenHangXe(tenHang);
					for (int a = line+1; a < 30; a++) {
						for (int b = 0; b < 150; b++) {
							gotoxy(b, a);
							cout << " ";
						}
					}
					gotoxy(col, line + 4);
					store.DanhSachCacHangXe();
					break;
				}
				if (menu.getItem1()[i] == "Sua Hang xe") {
					for (int a = line+1; a < 30; a++) {
						for (int b = 0; b < 150; b++) {
							gotoxy(b, a);
							cout << " ";
						}
					}
					gotoxy(col, line + 4);
					store.DanhSachCacHangXe();
					string Hangcu;
					gotoxy(col, line + 2);
					cout << "\nNhap ten hang xe cu: ";
					cin >> Hangcu;
					gotoxy(col, line + 3);
					cout << "\nNhap ten hang xe moi: ";
					string Hangmoi;
					cin >> Hangmoi;
					store.SuaTenHangXe(Hangcu, Hangmoi);
					for (int a = line+1; a < 30; a++) {
						for (int b = 0; b < 150; b++) {
							gotoxy(b, a);
							cout << " ";
						}
					}
					gotoxy(col, line + 4);
					store.DanhSachCacHangXe();
					break;
				}
				if (menu.getItem1()[i] == "Xem danh sach cac hang xe") {
					for (int a = line+1; a < 30; a++) {
						for (int b = 0; b < 150; b++) {
							gotoxy(b, a);
							cout << " ";
						}
					}
					gotoxy(col, line + 4);
					store.DanhSachCacHangXe();
					break;
				}
				if (menu.getItem1()[i] == "Quay lai") {
					for (int a = line + 1; a < 30; a++) {
						for (int b = 0; b < 150; b++) {
							gotoxy(b, a);
							cout << " ";
						}
					}
					menu.deleteMenuQLDMcon1();
					printMenuQLDM();
					exit(0);
				}
				break;
			}

			case 8: {
				thoat = true;
			}
			}
			gotoxy(col, line);
			cout << (char)62;
		}

	}

	menu.deleteMenuQLDMcon1();
}
void printMenuQLDMcon2() {
	Menu menu;
	int x;
	int line = 9;// vị trí dòng của menu
	int col = 18; //vi tri cot cua menu
	bool thoat = false;
	menu.printMenuQLDMcon2();
	int i = 7;

	gotoxy(col, line);
	cout << (char)62; //Vẽ con trỏ trỏ tới menu

	while (!thoat) {

		if (_kbhit()) {

			x = move();

			gotoxy(col, line);
			cout << " "; //Xóa con trỏ ở vị trí cũ

			switch (x) {

			case 1: {}

			case 3: {
				if (i == 7) {
					col = col + 39;
				}
				if (i == 8) {
					col = col + 16;
				}
				if (i == 9) {
					col = col + 15;
				}
				if (i == 10) {
					col = col + 15;
				}
				if (i == 11) {
					i = 6;
					col = 18;
				}
				i++;
				break;
			}

			case 2: {}

			case 4: {
				if (i == 11) {
					col = col - 15;
				}
				if (i == 10) {
					col = col - 15;
				}
				if (i == 9) {
					col = col - 16;
				}
				if (i == 8) {
					col = col - 39;
				}
				if (i == 7) {
					col = 103;
					i = 12;
				}
				i--;
				break;
			}

			case 5:
			{
				
				if (menu.getItem1()[i] == "Xem danh sach cac xe may theo hang") {
					for (int a = line+1; a < 30; a++) {
						for (int b = 0; b < 150; b++) {
							gotoxy(b, a);
							cout << " ";
						}
					}

					string tenHang;
					gotoxy(col, line + 1);
					cout << "\nNhap ten hang xe: ";
					cin >> tenHang;
					gotoxy(45, line + 3);
					cout << "-----Cac san pham cua hang xe " << tenHang << "-----";
					store.XemCacSanPham(tenHang);
					break;
				}
				if (menu.getItem1()[i] == "Them xe may") {
					for (int a = line+1; a < 30; a++) {
						for (int b = 0; b < 150; b++) {
							gotoxy(b, a);
							cout << " ";
						}
					}
					XeMay* xemay = new XeMay();
					xemay->input();
					int check = 0;
					for (int i = 0; i < store.getBrand().size(); i++) {
						if (store.getBrand()[i].getTenHang() == xemay->getTenHang()) {
							check = 1;
							break;
						}
					}
					if (check == 0) {

						vector <XeMay*> tempXeMay;
						tempXeMay.push_back(xemay);
						MotorbikeBrand temp(xemay->getTenHang(), tempXeMay);
						store.themTenHangXe(temp);
					}
					else {
						store.themXeMay(xemay);
					}
					for (int a = line+1; a < 30; a++) {
						for (int b = 0; b < 150; b++) {
							gotoxy(b, a);
							cout << " ";
						}
					}
					gotoxy(45, line+2); cout << "Da them thanh cong!";
					break;
				}
				if (menu.getItem1()[i] == "Sua xe may") {
					for (int a = line+1; a < 30; a++) {
						for (int b = 0; b < 150; b++) {
							gotoxy(b, a);
							cout << " ";
						}
					}
					store.suamotXemay();
					break;
				}
				if (menu.getItem1()[i] == "Xoa xe may") {
					for (int a = line+1; a < 30; a++) {
						for (int b = 0; b < 150; b++) {
							gotoxy(b, a);
							cout << " ";
						}
					}
					gotoxy(30, line + 2);
					cout << "----------Nhap thong tin xe may muon xoa------------";
					string tenHang;
					gotoxy(30, line + 3); cout << "Nhap ten hang xe: ";
					cin >> tenHang;
					//
					string tenXe;
					gotoxy(30, line + 4); cout << "Nhap ten xe may: ";
					cin >> tenXe;
					for (int a = line + 1; a < 30; a++) {
						for (int b = 0; b < 150; b++) {
							gotoxy(b, a);
							cout << " ";
						}
					}
					if (store.TimKiemMotXeMay(tenHang, tenXe) != NULL) {
						store.xoaXeMay(tenHang, tenXe);
						gotoxy(45, line + 4); cout << "Da xoa thanh cong xe may " << tenXe << " cua hang " << tenHang;
					}
					else {
						gotoxy(45, line + 4); cout << "Khong ton tai xe may " << tenXe << " cua hang " << tenHang;
					}
					break;
				}
				if (menu.getItem1()[i] == "Quay lai") {
					for (int i = line + 1; i < 30; i++) {
						for (int j = 0; j < 150; j++) {
							gotoxy(j, i); cout << " ";
						}
					}
					menu.deleteMenuQLDMcon2();
					printMenuQLDM();
					exit(0);
				}
				break;
			}

			case 8: {
				thoat = true;
			}
			}
			gotoxy(col, line);
			cout << (char)62;
		}

	}
	menu.deleteMenuQLDMcon2();
}
void printMenuQLDM() {
	Menu menu;
	int x;
	int line = 7;// vị trí dòng của menu
	int col = 28; //vi tri cot cua menu
	bool thoat = false;
	menu.printMenuQLDM();
	int i = 0;

	gotoxy(col, line);
	cout << (char)62; //Vẽ con trỏ trỏ tới menu

	while (!thoat) {

		if (_kbhit()) {

			x = move();

			gotoxy(col, line);
			cout << " "; //Xóa con trỏ ở vị trí cũ

			switch (x) {

			case 1: {}

			case 3:{
				if (i == 0) {
					col = col + 25;
				}
				if (i == 6) {
					col = col + 24;
				}
				if (i == 12) {
					col = 28;
					i = -6;
				}
				i = i + 6;
				break;
			}

			case 2: {}

			case 4:{
				if (i == 12) {
					col = col - 24;
				}
				if (i == 6) {
					col = col - 25;
				}
				if (i == 0) {
					col = 77;
					i = 18;
				}
				i = i - 6;
				break;
			}

			case 5:
			{
				if (menu.getItem1()[i] == "Quan ly Hang xe") {
					printMenuQLDMcon1();
					break;
				}
				if (menu.getItem1()[i] == "Quan ly Xe may") {
					printMenuQLDMcon2();
					break;
				}
				if (menu.getItem1()[i] == "Quay lai") {
					menu.deleteMenuQLDM();
					printMenu();
					exit(0);
				}
				break;
			}

			case 8: {
				thoat = true;
			}
			}

			gotoxy(col, line);
			cout << (char)62;

		}

	}

	menu.deleteMenuQLDM();
}

void printMenuQLDH() {
	Menu menu;
	int x;
	int line = 5;// vị trí dòng của menu
	int col = 13; //vi tri cot cua menu
	bool thoat = false;
	menu.printMenuQLDH();
	int i = 0;

	gotoxy(col, line);
	cout << (char)62; //Vẽ con trỏ trỏ tới menu
	int page = 1;
	int nguyen = orderManagement.getOders().size() / 10;
	while (!thoat) {

		if (_kbhit()) {

			x = move();

			gotoxy(col, line);
			cout << " "; //Xóa con trỏ ở vị trí cũ

			switch (x) {

			case 1: {

			}

			case 3:{

				if (i == 0) {
					col = col + 23;
				}
				if (i == 1) {
					col = col + 9;
				}
				if (i == 2) {
					col = col + 9;
				}
				if (i == 3) {
					col = col + 26;
				}
				if (i == 4) {
					col = col+13;
				}
				if (i == 5) {
					col = col+8;
				}
				if (i == 6) {
					col = 13;
					i = -1;
				}
				i++;
				break;

			}

			case 2: {

			}

			case 4:{
				if (i == 6) {
					col = col - 8;
				}
				if (i == 5) {
					col = col - 13;
				}
				if (i == 4) {
					col = col - 26;
				}
				if (i == 3) {
					col = col - 9;
				}
				if (i == 2) {
					col = col - 9;
				}
				if (i == 1) {
					col = col - 23;
				}
				if (i == 0) {
					i = 7;
					col = 101;
				}
				i--;
				break;
			}

			case 5:
			{
				if (menu.getItem2()[i] == "Danh sach don hang") {
					for (int a = line+1; a < 30; a++) {
						for (int b = 0; b < 150; b++) {
							gotoxy(b, a);
							cout << " ";
						}
					}
					gotoxy(3, 8);
					cout << "----------Danh sach cac don hang hien co----------";

					if (orderManagement.getOders().size() == 0) {
						gotoxy(35, 9);
						cout << "Khong ton tai don hang nao!";
					}
					else {
						
						int du = orderManagement.getOders().size() % 10;
						gotoxy(80, 10); cout << "Trang " << page << "/" << nguyen+1;
						gotoxy(20, 10);
						cout << "STT    Ma don hang";
						if (page <= nguyen) {
							for (int i = (page-1)*10; i < page*10; i++) {
								gotoxy(20, 11 + i -(page-1)*10);
								if (i + 1 < 10) {
									cout << " " << i + 1 << "      " << orderManagement.getOders()[i].getTenDonHang();
								}
								else {
									cout << i + 1 << "      " << orderManagement.getOders()[i].getTenDonHang();
								}
							}
						}
						else {
							for (int i = (page-1)*10; i < orderManagement.getOders().size(); i++) {
								gotoxy(20, 11 + i-(page-1)*10);
								if (i + 1 < 10) {
									cout << " " << i + 1  << "      " << orderManagement.getOders()[i].getTenDonHang();
								}
								else {
									cout << i + 1 << "      " << orderManagement.getOders()[i].getTenDonHang();
								}
							}
						}
						cout << endl;
					}
				}
				if (menu.getItem2()[i] == "Next") {
					for (int a = line+1; a < 30; a++) {
						for (int b = 0; b < 150; b++) {
							gotoxy(b, a);
							cout << " ";
						}
					}
					gotoxy(3, 8);
					cout << "----------Danh sach cac don hang hien co----------";
					if (page <= nguyen) {
						page++;
					}
					else {
						page = 1;
					}
					int du = orderManagement.getOders().size() % 10;
					gotoxy(80, 10); cout << "Trang " << page << "/" << nguyen + 1;
					gotoxy(20, 10);
					cout << "STT    Ma don hang";
					if (page <= nguyen) {
						for (int i = (page - 1) * 10; i < page * 10; i++) {
							gotoxy(20, 11 + i-(page-1)*10);
							if (i + 1 < 10) {
								cout <<" "<< i + 1<< "      " << orderManagement.getOders()[i].getTenDonHang();
							}
							else {
								cout <<i + 1  << "      " << orderManagement.getOders()[i].getTenDonHang();
							}
							
						}
					}
					else {
						for (int i = (page - 1) * 10; i < orderManagement.getOders().size(); i++) {
							gotoxy(20, 11 + i-(page-1)*10);
							if (i + 1 < 10) {
								cout <<" "<< i + 1 << "      " << orderManagement.getOders()[i].getTenDonHang();
							}
							else {
								cout << i + 1 << "      " << orderManagement.getOders()[i].getTenDonHang();
							}
							
						}
					}
					cout << endl;
				}
				if (menu.getItem2()[i] == "Them") {
					for (int a = line+1; a < 30; a++) {
						for (int b = 0; b < 150; b++) {
							gotoxy(b, a);
							cout << " ";
						}
					}
					DonHang temp;
					gotoxy(10, 5);
					string madonhang;
					int check;
					cout << "\nNhap Ma Don hang: ";
					cin >> madonhang;
					do {
						check = 0;
						for (int i = 0; i < orderManagement.getOders().size(); i++) {
							if (madonhang == orderManagement.getOders()[i].getTenDonHang()) {
								cout << "Ma don hang da ton tai!" << endl;
								cout << "Nhap lai Ma don hang: ";
								cin >> madonhang;
								check = 1;
							}
						}
						
					} while (check == 1);
					
					temp.setMadonHang(madonhang);
					temp.NhapDonHang();
					orderManagement.themDonhang(temp.getTenDonHang(),temp);
					for (int a = line+1; a < 40; a++) {
						for (int b = 0; b < 150; b++) {
							gotoxy(b, a);
							cout << " ";
						}
					}
					gotoxy(45, 10); cout << "Da them thanh cong don hang " << temp.getTenDonHang();
				}
				if (menu.getItem2()[i] == "Xem chi tiet don hang") {
					for (int a = line+1; a < 30; a++) {
						for (int b = 0; b < 150; b++) {
							gotoxy(b, a);
							cout << " ";
						}
					}
					gotoxy(10, line+1);
					cout << "Nhap ma don hang: ";
					string tendonhang;
					cin >> tendonhang;
					gotoxy(10, line+3);
					orderManagement.ChitietDonHang(tendonhang);
				}
				if (menu.getItem2()[i] == "Cap nhat") {
					for (int a = line+1; a < 30; a++) {
						for (int b = 0; b < 150; b++) {
							gotoxy(b, a);
							cout << " ";
						}
					}
					gotoxy(10, line+1);
					cout << "Nhap ma don hang muon cap nhat: ";
					string tendonhang;
					cin >> tendonhang;
					orderManagement.CapNhatDonHang(tendonhang);
	
				}
				if (menu.getItem2()[i] == "Xoa") {
					for (int a = line+1; a < 30; a++) {
						for (int b = 0; b < 150; b++) {
							gotoxy(b, a);
							cout << " ";
						}
					}
					string tenDH;
					gotoxy(10, line+1);
					cout << "Nhap ma don hang muon xoa:  ";
					cin >> tenDH;
					orderManagement.XoaDonHang(tenDH);
					
				}
				if (menu.getItem2()[i] == "Quay lai") {
					for (int a = line+1; a < 30; a++) {
						for (int b = 0; b < 150; b++) {
							gotoxy(b, a);
							cout << " ";
						}
					}
					menu.deleteMenuQLDH();
					printMenu();
					exit(0);
				}

				break;
			}

			case 8:

				thoat = true;

			}

			gotoxy(col, line);
			cout << (char)62;

		}

	}

	menu.deleteMenuQLDM();
}

void printMenuTKBC() {
	Menu menu;
	int x;
	int line = 5;// vị trí dòng của menu
	int col = 3; //vi tri cot cua menu
	bool thoat = false;
	menu.printMenuTKBC();
	int i = 0;

	gotoxy(col, line);
	cout << (char)62; //Vẽ con trỏ trỏ tới menu

	while (!thoat) {
		
		if (_kbhit()) {

			x = move();

			gotoxy(col, line);
			cout << " "; //Xóa con trỏ ở vị trí cũ

			switch (x) {

			case 1: {

			}

			case 3:{

				if (i == 0) {
					col = col + 25;
				}
				if (i == 1) {
					col = col + 44;
				}
				if (i == 2) {
					col = col + 25;
				}
				if (i == 3) {
					col = 3;
					i = -1;
				}
				i++;
				break;

			}

			case 2: {

			}

			case 4:{
				
				if (i == 3) {
					col = col - 25;
				}
				if (i == 2) {
					col = col - 44;
				}
				if (i == 1) {
					col = col - 25;
				}
				if (i == 0) {
					i = 4;
					col = 97;
				}
				i--;
				break;
			}

			case 5:
			{
				if (menu.getItem3()[i] == "Cac mat hang sap het") {
					for (int a = line+1; a < 30; a++) {
						for (int b = 0; b < 150; b++) {
							gotoxy(b, a);
							cout << " ";
						}
					}
					gotoxy(40, line + 2); cout << "-----Cac san pham sap het (soluong < 10 )-----";
					TKBC.DSCacMatHangSapHet();
				}
				if (menu.getItem3()[i] == "Cac mat hang ban chay trong thang truoc") {
					for (int a = line+1; a < 30; a++) {
						for (int b = 0; b < 150; b++) {
							gotoxy(b, a);
							cout << " ";
						}
					}
					
					TKBC.SPbanchaynhat();
				}
				if (menu.getItem3()[i] == "Doanh thu, loi nhuan") {
					for (int a = line+1; a < 30; a++) {
						for (int b = 0; b < 150; b++) {
							gotoxy(b, a);
							cout << " ";
						}
					}
					gotoxy(10, line+2);
					cout << "\nXin nhap thang, nam cu the:    ";
					int thang, nam;
					cout << "\nthang = ";
					cin >> thang;
					cout << "nam = ";
					cin >> nam;
					TKBC.DoanhThu(thang,nam);
					TKBC.LoiNhuan(thang,nam);
				}
				
				if (menu.getItem3()[i] == "Quay lai") {
					for (int a = line; a < 30; a++) {
						for (int b = 0; b < 150; b++) {
							gotoxy(b, a);
							cout << " ";
						}
					}
					menu.deleteMenuTKBC();
					printMenu();
					exit(0);
				}
				
				break;
			}

			case 8:

				thoat = true;

			}

			gotoxy(col, line);
			cout << (char)62;

		}

	}

	menu.deleteMenuTKBC();
}

void printMenu() {
	Menu menu;
	int x;
	int line = 3;// vị trí dòng của menu
	int col = 19; //vi tri cot cua menu
	bool thoat = false;
	menu.printMenu();
	int i = 0;
	gotoxy(40, 1);
	cout << "HE THONG QUAN LY CHO CUA HANG BAN XE MAY";
	gotoxy(col, line);
	cout << (char)62; //Vẽ con trỏ trỏ tới menu

	while (!thoat) {

		if (_kbhit()) {

			x = move();

			gotoxy(col, line);
			cout << " "; //Xóa con trỏ ở vị trí cũ

			switch (x) {

			case 1: {
		
			}

			case 3:{
				
				if (i == 0) {
					col = col + 21;
				}
				if (i == 1) {
					col = col + 21;
				}
				if (i == 2) {
					col = col + 21;
				}
				if (i == 3) {
					i = -1;
					col = 19;
				}
				i++;
				break;

			}

			case 2: {

			}

			case 4:{
				if (i == 3) {
					col = col - 21;
				}
				if (i == 2) {
					col = col - 21;
				}
				if (i == 1) {
					col = col - 21;
				}
				if (i == 0) {
					i = 4;
					col = 82;
				}
				i--;
				break;
			}

			case 5:{
				if (menu.getItem()[i] == "QUAN LY DANH MUC") {
					menu.deleteMenu();
					printMenuQLDM();
				}
				if (menu.getItem()[i] == "QUAN LY DON HANG") {
					menu.deleteMenu();
					printMenuQLDH();
				}
				if (menu.getItem()[i] == "THONG KE BAO CAO") {
					menu.deleteMenu();
					printMenuTKBC();
				}
				if (menu.getItem()[i] == "THOAT") {
					thoat = true;
					for (int i = 20; i < 100; i++) {
						gotoxy(i, 0);
						cout << " ";
					}
					break;
				}
				break;
			}
			case 8:

				thoat = true;
				for (int i = 20; i < 100; i++) {
					gotoxy(i, 0);
					cout << " ";
				}

			}

			gotoxy(col, line);
			cout << (char)62;

		}

	}

	menu.deleteMenu();
}


int main() {

	SetConsoleTitle(L"He thong cua hang ban xe may");
	printMenu();
	ofstream writerBrand("brands.txt");
	writerBrand << store.getBrand().size() << endl;
	for (int i = 0; i < store.getBrand().size(); i++) {
		writerBrand << store.getBrand()[i].getTenHang() << endl;
	}
	ofstream writer("xemay.txt");
	
	for (int i = 0; i < store.getBrand().size(); i++) {
		writer << store.getBrand()[i].getMotorbikes().size() << endl;
		for (int j = 0; j < store.getBrand()[i].getMotorbikes().size(); j++) {
			writer << store.getBrand()[i].getMotorbikes()[j]->getTenHang() << ",";
			writer << store.getBrand()[i].getMotorbikes()[j]->getTenXe() << ",";
			writer << store.getBrand()[i].getMotorbikes()[j]->getLoaiXe() << ",";
			writer << store.getBrand()[i].getMotorbikes()[j]->getCC() << ",";
			writer << store.getBrand()[i].getMotorbikes()[j]->getGiaGoc() << ",";
			writer << store.getBrand()[i].getMotorbikes()[j]->getGiaBan() << ",";
			writer << store.getBrand()[i].getMotorbikes()[j]->getSL() << ",";
			writer << store.getBrand()[i].getMotorbikes()[j]->getSLBan() << "\n";
		}
	}

	ofstream writerDonHang("donhang.txt");
	writerDonHang << orderManagement.getOders().size() << endl;
	for (int i = 0; i < orderManagement.getOders().size(); i++) {
		writerDonHang << orderManagement.getOders()[i].getTenDonHang() << ",";
		writerDonHang << orderManagement.getOders()[i].getTenKH() << ",";
		writerDonHang << orderManagement.getOders()[i].getSDT() << ",";
		writerDonHang << orderManagement.getOders()[i].getNgayMua().getNgay() << ",";
		writerDonHang << orderManagement.getOders()[i].getNgayMua().getThang() << ",";
		writerDonHang << orderManagement.getOders()[i].getNgayMua().getNam() << ",";
		writerDonHang << orderManagement.getOders()[i].getSL() <<endl;
		for (int j = 0; j < orderManagement.getOders()[i].getMotorbikes().size(); j++) {
			writerDonHang << orderManagement.getOders()[i].getsoluongmoiloai()[j] <<endl;
			writerDonHang << orderManagement.getOders()[i].getMotorbikes()[j]->getTenHang() << ",";
			writerDonHang << orderManagement.getOders()[i].getMotorbikes()[j]->getTenXe() << ",";
			writerDonHang << orderManagement.getOders()[i].getMotorbikes()[j]->getLoaiXe() << ",";
			writerDonHang << orderManagement.getOders()[i].getMotorbikes()[j]->getCC() << ",";
			writerDonHang << orderManagement.getOders()[i].getMotorbikes()[j]->getGiaGoc() << ",";
			writerDonHang << orderManagement.getOders()[i].getMotorbikes()[j]->getGiaBan() << ",";
			writerDonHang << orderManagement.getOders()[i].getMotorbikes()[j]->getSL() << ",";
			writerDonHang << orderManagement.getOders()[i].getMotorbikes()[j]->getSLBan() <<endl;
		}
	}

}


