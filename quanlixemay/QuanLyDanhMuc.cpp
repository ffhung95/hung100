#include"QuanLyDanhMuc.h"

vector<MotorbikeBrand> QuanLyDanhMuc::getBrand() {
	return _brands;
}

void QuanLyDanhMuc::themTenHangXe(MotorbikeBrand brand) {//thêm 1 hãng xe máy vào danh mục

	_brands.push_back(brand);
}

void QuanLyDanhMuc::SuaTenHangXe(string tenHangcu, string tenHangmoi) {
	//sửa tên 1 hãng xe máy, 
	//tên các xe may thuộc hãng cũ sẽ sang hãng xe mơi
	for (int i = 0; i < _brands.size(); i++) {
		if (_brands[i].getTenHang() == tenHangcu) {
			_brands[i].setTenHang(tenHangmoi);
			_brands[i].SuaTenHangCuaCacXeMay(tenHangmoi);
		}
	}
}

void QuanLyDanhMuc::XoaTenHangXe(string tenHang) {//xóa một hãng xe,
	//thì sẽ xóa tất cả các xe thuộc hãng đó
	for (int i = 0; i < _brands.size(); i++) {
		if (_brands[i].getTenHang() == tenHang) {
			_brands.erase(_brands.begin() + i);
		}
	}
}

bool QuanLyDanhMuc::isBrand(string tenHang) {
	for (int i = 0; i < _brands.size(); i++) {
		if (_brands[i].getTenHang() == tenHang) {
			return true;
		}
	}
	return false;
}

void QuanLyDanhMuc::DanhSachCacHangXe() {// xem danh sách các hãng xe.
	
	/*cout << "\nDanh sach cac hang xe hien co\n";
	cout << "STT" << "      Ten Hang\n";
	cout << " 1 " << "      yamaha\n";
	cout << " 2 " << "      honda\n";
	cout << " 3 " << "      suzuki\n";*/
	ofstream fileout;
	fileout.open("E:\\qlbanxe\\hang.txt");
	for (int i = 0; i < _brands.size(); i++) {
		
		fileout << " " << i + 1 << "       " << _brands[i].getTenHang() << endl;
	}
	cout << endl;
}

void QuanLyDanhMuc::XemCacSanPham(string tenhang) {  // xem tất cả sản phẩm ứng với một hãng
	for (int i = 0; i < _brands.size(); i++) {
		if (_brands[i].getTenHang() == tenhang) {
			_brands[i].DanhSachCacSanPham();
			break;
		}
	}
}

XeMay* QuanLyDanhMuc::TimKiemMotXeMay(string tenhang, string tenXe) {
	for (int i = 0; i < _brands.size(); i++) {
		if (_brands[i].getTenHang() == tenhang) {
			return _brands[i].timkiemxemay(tenXe);
		}
	}
	return NULL;
}

void QuanLyDanhMuc::themXeMay(XeMay* xemay) {// thêm thông tin một xe máy ứng với một hãng

	for (int i = 0; i < _brands.size(); i++) {
		if (_brands[i].getTenHang() == xemay->getTenHang()) {
			_brands[i].ThemMotXemay(xemay);
		}
	}
}



void QuanLyDanhMuc::xoaXeMay(string tenhang, string tenxe) {  // xóa thông tin một xe máy ứng với một hãng

	for (int i = 0; i < _brands.size(); i++) {
		if (_brands[i].getTenHang() == tenhang) {

			for (int j = 0; j < _brands[i].getMotorbikes().size(); j++) {
				_brands[i].XoaMotXeMay(tenxe);
			}
		}
	}
}

void QuanLyDanhMuc::SanPhamSapHet() {
	gotoxy(0, 12); cout << "STT  |  ";
	gotoxy(8, 12); cout << "Ten hang" << "   |   " << "Ten xe" << "   |   "
		<< "Loai xe" << "   |   " << "CC" << "   |   " << "Gia goc" << "   |   "
		<< "Gia ban" << "   |   " << "SL con lai" << "   |   " << "SL da ban";
	int stt = 1;
	for (int i = 0; i < _brands.size(); i++) {
		for (int j = 0; j < _brands[i].getMotorbikes().size(); j++) {
			if (_brands[i].getMotorbikes()[j]->getSL() < 10) {

				gotoxy(1, 12 + stt); cout << stt;
				gotoxy(5, 12 + stt); cout << "|";
				gotoxy(8, 12 + stt); cout << _brands[i].getMotorbikes()[j]->getTenHang();
				gotoxy(19, 12 + stt); cout << "|";
				gotoxy(23, 12 + stt); cout << _brands[i].getMotorbikes()[j]->getTenXe();
				gotoxy(32, 12 + stt); cout << "|";
				gotoxy(35, 12 + stt); cout << _brands[i].getMotorbikes()[j]->getLoaiXe();
				gotoxy(46, 12 + stt); cout << "|";
				gotoxy(50, 12 + stt); cout << _brands[i].getMotorbikes()[j]->getCC();
				gotoxy(55, 12 + stt); cout << "|";
				gotoxy(57, 12 + stt); cout << Tien(to_string(_brands[i].getMotorbikes()[j]->getGiaGoc()));
				gotoxy(69, 12 + stt); cout << "|";
				gotoxy(71, 12 + stt); cout << Tien(to_string(_brands[i].getMotorbikes()[j]->getGiaBan()));
				gotoxy(83, 12 + stt); cout << "|";
				gotoxy(90, 12 + stt); cout << _brands[i].getMotorbikes()[j]->getSL();
				gotoxy(100, 12 + stt); cout << "|";
				gotoxy(106, 12 + stt); cout << _brands[i].getMotorbikes()[j]->getSLBan();

				stt++;
			}
		}
	}
}

void QuanLyDanhMuc::suamotXemay() {
	int line = 9;
	gotoxy(30, line + 2);
	cout << "----------Nhap thong tin xe may can chinh sua------------";
	string tenHang;
	gotoxy(20, line + 3); cout << "Nhap ten hang xe: ";
	cin >> tenHang;
	string tenXe;
	gotoxy(20, line + 4); cout << "Nhap ten xe may: ";
	cin >> tenXe;
	gotoxy(30, line + 5);  cout << "An phim 1 de sua ten Hang Xe may.";
	gotoxy(30, line + 6);  cout << "An phim 2 de sua ten Xe may.";
	gotoxy(30, line + 7);  cout << "An phim 3 de sua Loai xe.";
	gotoxy(30, line + 8);  cout << "An phim 3 de sua phan phoi Xe may.";
	gotoxy(30, line + 9);  cout << "An phim 4 de sua gia goc cua Xe may.";
	gotoxy(30, line + 10);  cout << "An phim 5 de sua gia ban cua Xe may.";
	gotoxy(30, line + 11);  cout << "An phim 6 de sua so luong Xe may." << endl;
	int luachon = 1;
	int check = 0;
	for (int i = 0; i < _brands.size(); i++) {
		for (int j = 0; j < _brands[i].getMotorbikes().size(); j++) {
			if (_brands[i].getMotorbikes()[j]->getTenHang() == tenHang && _brands[i].getMotorbikes()[j]->getTenXe() == tenXe) {
				check = 1;
				while (luachon != 0) {
					cout << "Nhap lua chon cua ban (An phim 0 de thoat): ";
					cin >> luachon;
					switch (luachon) {
					case 1: {
						string tenHang;
						cout << "Nhap ten Hang xe may: ";
						cin >> tenHang;
						_brands[i].getMotorbikes()[j]->setTenHang(tenHang);
						break;
					}
					case 2: {
						string tenxe;
						cout << "Nhap ten Xe may: ";
						cin >> tenxe;
						_brands[i].getMotorbikes()[j]->setTenXe(tenxe);
						break;
					}
					case 3: {
						cout << "Nhap loai xe may: ";
						string str;
						cin.ignore();
						fflush(stdin);
						getline(cin, str);
						_brands[i].getMotorbikes()[j]->setLoaiXe(str);
						break;
					}
					case 4: {
						int CC;
						cout << "Nhap phan phoi cua Xe may: ";
						cin >> CC;
						_brands[i].getMotorbikes()[j]->setCC(CC);
						break;
					}
					case 5: {
						int GiaGoc;
						cout << "Nhap gia goc cua Xe may: ";
						cin >> GiaGoc;
						_brands[i].getMotorbikes()[j]->setGiaGoc(GiaGoc);
						break;
					}
					case 6: {
						int GiaBan;
						cout << "Nhap gia cua Xe may: ";
						cin >> GiaBan;
						_brands[i].getMotorbikes()[j]->setGiaBan(GiaBan);
						break;
					}
					case 7: {
						int SL;
						cout << "Nhap so luong Xe may: ";
						cin >> SL;
						_brands[i].getMotorbikes()[j]->setSL(SL);
						break;
					}
					case 0:
						break;
					default:
						break;
					}
				}
			}
		}
	}
	for (int a = line + 1; a < 30; a++) {
		for (int b = 0; b < 150; b++) {
			gotoxy(b, a);
			cout << " ";
		}
	}
	if (check == 1) {
		gotoxy(45, line + 4); cout << "Da sua thanh cong!";
	}
	else {
		gotoxy(40, line + 4); cout << "Khong ton tai xe may " << tenXe << " hang " << tenHang;
	}
}