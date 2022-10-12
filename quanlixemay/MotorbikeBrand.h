#pragma once
#pragma once
#include"Motobike.h"
#include"GotoXY.h"
#include "Tokenizer.h"
#include<fstream>
class MotorbikeBrand {
private:
	string _tenHang;
	vector<XeMay*> _motorbikes;
public:
	MotorbikeBrand();
	MotorbikeBrand(string tenhang, vector<XeMay*> motorbikes);
	vector<XeMay*> getMotorbikes();
	string getTenHang();
	void setTenHang(string getTenHang);
	void SanPhamSapHet(); // số lượng < 10
	void ThemMotXemay(XeMay* xemay);
	void XoaMotXeMay(string tenXe);
	XeMay* timkiemxemay(string tenxe);
	void SuaMotXeMay(XeMay* xemay);
	void setTenHang(string tenhang);
	void SuaTenHangCuaCacXeMay(string tenhang);
	void DanhSachCacSanPham();
	XeMay* SanPhamBanChayNhatCuaMotHang();
};