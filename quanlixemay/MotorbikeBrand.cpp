#include "MotorbikeBrand.h"

MotorbikeBrand::MotorbikeBrand() {};

MotorbikeBrand::MotorbikeBrand(string tenhang, vector<XeMay*> motorbikes) {
	_tenHang = tenhang;
	_motorbikes = motorbikes;
}


vector<XeMay*> MotorbikeBrand::getMotorbikes() {
	return _motorbikes;
}

void MotorbikeBrand::SanPhamSapHet() {


	int tam = 0;
	for (int i = 0; i < _motorbikes.size(); i++) {
		if (_motorbikes[i]->getSL() < 10) {

			gotoxy(1, 12 + tam); cout << tam + 1;
			gotoxy(5, 12 + tam); cout << "|";
			gotoxy(8, 12 + tam); cout << _motorbikes[i]->getTenHang();
			gotoxy(19, 12 + tam); cout << "|";
			gotoxy(23, 12 + tam); cout << _motorbikes[i]->getTenXe();
			gotoxy(32, 12 + tam); cout << "|";
			gotoxy(35, 12 + tam); cout << _motorbikes[i]->getLoaiXe();
			gotoxy(46, 12 + tam); cout << "|";
			gotoxy(50, 12 + tam); cout << _motorbikes[i]->getCC();
			gotoxy(55, 12 + tam); cout << "|";
			gotoxy(57, 12 + tam); cout << Tien(to_string(_motorbikes[i]->getGiaGoc()));
			gotoxy(69, 12 + tam); cout << "|";
			gotoxy(71, 12 + tam); cout << Tien(to_string(_motorbikes[i]->getGiaBan()));
			gotoxy(83, 12 + tam); cout << "|";
			gotoxy(90, 12 + tam); cout << _motorbikes[i]->getSL();
			gotoxy(100, 12 + tam); cout << "|";
			gotoxy(106, 12 + tam); cout << _motorbikes[i]->getSLBan();

			tam++;
		}
	}

}

void MotorbikeBrand::ThemMotXemay(XeMay* xemay) {
	_motorbikes.push_back(xemay);
}

void MotorbikeBrand::XoaMotXeMay(string tenXe) {

	for (int i = 0; i < _motorbikes.size(); i++) {
		if (_motorbikes[i]->getTenXe() == tenXe) {
			_motorbikes.erase(_motorbikes.begin() + i);
		}
	}

}

string MotorbikeBrand::getTenHang() {
	return _tenHang;
}
//void MotorbikeBrand::setTenHang(string getTenHang) {
//	ifstream fin;
//	fin.open("E:\\qlbanxe\\hang.txt");
//	fin >> getTenHang;
//}
XeMay* MotorbikeBrand::timkiemxemay(string tenxe) {
	for (int i = 0; i < _motorbikes.size(); i++) {
		if (_motorbikes[i]->getTenXe() == tenxe) {
			return _motorbikes[i];
		}
	}
	return NULL;
}

void MotorbikeBrand::SuaMotXeMay(XeMay* xemay) {

	gotoxy(30, 10);  cout << "An phim 1 de sua ten Hang Xe may.";
	gotoxy(30, 11);  cout << "An phim 2 de sua ten Xe may.";
	gotoxy(30, 12);  cout << "An phim 3 de sua phan phoi Xe may.";
	gotoxy(30, 13);  cout << "An phim 4 de sua gia goc cua Xe may.";
	gotoxy(30, 14);  cout << "An phim 5 de sua gia ban cua Xe may.";
	gotoxy(30, 15);  cout << "An phim 6 de sua so luong Xe may." << endl;
	int luachon = 1;

	for (int i = 0; i < _motorbikes.size(); i++) {
		if (_motorbikes[i]->getTenXe() == xemay->getTenXe()) {
			while (luachon != 0) {
				cout << "Nhap lua chon cua ban (An phim 0 de thoat): ";
				cin >> luachon;
				switch (luachon) {
				case 1: {
					string tenHang;
					cout << "Nhap ten Hang xe may: ";
					cin.ignore();
					fflush(stdin);
					getline(cin, tenHang);
					_motorbikes[i]->setTenHang(tenHang);
					break;
				}
				case 2: {
					string tenxe;
					cout << "Nhap ten Xe may: ";
					cin >> tenxe;
					_motorbikes[i]->setTenXe(tenxe);
					break;
				}
				case 3: {
					int CC;
					cout << "Nhap phan phoi cua Xe may: ";
					cin >> CC;
					_motorbikes[i]->setCC(CC);
					break;
				}
				case 4: {
					int GiaGoc;
					cout << "Nhap gia goc cua Xe may: ";
					cin >> GiaGoc;
					_motorbikes[i]->setGiaGoc(GiaGoc);
					break;
				}
				case 5: {
					int GiaBan;
					cout << "Nhap gia cua Xe may: ";
					cin >> GiaBan;
					_motorbikes[i]->setGiaBan(GiaBan);
					break;
				}
				case 6: {
					int SL;
					cout << "Nhap so luong Xe may: ";
					cin >> SL;
					_motorbikes[i]->setSL(SL);
					break;
				}
				case 0:
					break;
				default:
					break;
				}
			}
			break;
		}
	}
}

void MotorbikeBrand::setTenHang(string tenhang) {
	_tenHang = tenhang;
}

void MotorbikeBrand::SuaTenHangCuaCacXeMay(string tenhang) {
	for (int i = 0; i < _motorbikes.size(); i++) {
		_motorbikes[i]->setTenHang(tenhang);
	}
}

void MotorbikeBrand::DanhSachCacSanPham() {
	int line = 14;
	gotoxy(0, line); cout << "STT  |  ";
	gotoxy(8, line); cout << "Ten hang" << "   |   " << "Ten xe" << "   |   "
		<< "Loai xe" << "   |   " << "CC" << "   |   " << "Gia goc" << "   |   "
		<< "Gia ban" << "   |   " << "SL con lai" << "   |   " << "SL da ban";

	for (int i = 0; i < _motorbikes.size(); i++) {
		gotoxy(1, line + 1 + i); cout << i + 1;
		gotoxy(5, line + 1 + i); cout << "|";
		gotoxy(8, line + 1 + i); cout << _motorbikes[i]->getTenHang();
		gotoxy(19, line + 1 + i); cout << "|";
		gotoxy(23, line + 1 + i); cout << _motorbikes[i]->getTenXe();
		gotoxy(32, line + 1 + i); cout << "|";
		gotoxy(35, line + 1 + i); cout << _motorbikes[i]->getLoaiXe();
		gotoxy(46, line + 1 + i); cout << "|";
		gotoxy(50, line + 1 + i); cout << _motorbikes[i]->getCC();
		gotoxy(55, line + 1 + i); cout << "|";
		gotoxy(57, line + 1 + i); cout << Tien(to_string(_motorbikes[i]->getGiaGoc()));
		gotoxy(69, line + 1 + i); cout << "|";
		gotoxy(71, line + 1 + i); cout << Tien(to_string(_motorbikes[i]->getGiaBan()));
		gotoxy(83, line + 1 + i); cout << "|";
		gotoxy(91, line + 1 + i); cout << _motorbikes[i]->getSL();
		gotoxy(100, line + 1 + i); cout << "|";
		gotoxy(107, line + 1 + i); cout << _motorbikes[i]->getSLBan();
	}
}

XeMay* MotorbikeBrand::SanPhamBanChayNhatCuaMotHang() {
	int max = _motorbikes[0]->getSLBan();
	int vtMax = 0;
	for (int i = 0; i < _motorbikes.size(); i++) {
		if (_motorbikes[i]->getSLBan() > max) {
			max = _motorbikes[i]->getSLBan();
			vtMax = i;
		}
	}
	return _motorbikes[vtMax];
}