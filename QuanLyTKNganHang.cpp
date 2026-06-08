#include <bits/stdc++.h>

using namespace std;

struct KhachHang{
    string MaKH;
    string HoTen;
    string SDT;
    string SoCCCD;
};

struct TaiKhoan{
    string SoTaiKhoan;
    string MaKH;
    string TenChuThe;
    string MaPin;
    long long SoDu;
};

struct GiaoDich{
    string MaGiaoDich;
    string SoTaiKhoanGoc;
    string SoTaiKhoanDich;
    string LoaiGiaoDich;
    string ThoiGian;
    string NoiDung;
    long long SoTien;
};
void DangNhap()
{

}
void NapTien()
{

}
void RutTien()
{

}
void ChuyenKhoan()
{

}
void SaoKe()
{

}
void TaoTK()
{

}
KhachHang dsKH[1000005];
TaiKhoan dsTK[1000005];
GiaoDich dsGD[1000005];
int SLKH=0;
int SLTK=0;
int SLGD=0;
int main()
{
    int LuaChon;
    bool HoatDong = true;
    while(HoatDong){
        cout << "\n=========================================";
        cout << "\n      HE THONG QUAN LY NGAN HANG         ";
        cout << "\n=========================================";
        cout << "\n1. Dang nhap tai khoan";
        cout << "\n2. Nap tien vao tai khoan";
        cout << "\n3. Rut tien";
        cout << "\n4. Chuyen khoan";
        cout << "\n5. Xem sao ke giao dich";
        cout << "\n6. Tao tai khoan";
        cout << "\n0. Luu du lieu va Thoat";
        cout << "\n=========================================";
        cout << "\nNhap lua chon cua ban: ";
        cin >> LuaChon;
        switch(LuaChon){
        case 1:
            DangNhap();
            break;
        case 2:
            NapTien();
            break;
        case 3:
            RutTien();
            break;
        case 4:
            ChuyenKhoan();
            break;
        case 5:
            SaoKe();
            break;
        case 6:
            TaoTK();
            break;
        case 0:
            //Ghi đè toàn bộ dữ liệu từ 3 danh sách xuống lại file txt
            cout << "Da luu du lieu. Hen gap lai!\n";
            HoatDong = false;
            break;
        default:
            cout << "Lua chon khong hop le. Vui long thu lai!\n";
        }
    }
    return 0;
}
