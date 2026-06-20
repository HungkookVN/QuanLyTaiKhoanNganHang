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

KhachHang dsKH[1000005];
TaiKhoan dsTK[1000005];
GiaoDich dsGD[1000005];

int SLKH=0;
int SLTK=0;
int SLGD=0;

void DataTaiKhoan()
{
    ifstream inp("DataTaiKhoan.inp");
    int n=0;
    if(inp>>n)
    {
        inp.ignore();
        for(int i=0;i<n;i++)
        {
            KhachHang default_KH;
            TaiKhoan default_TK;

            getline(inp,dsKH[i].MaKH);
            getline(inp,dsKH[i].HoTen);
            getline(inp,dsKH[i].SDT);
            getline(inp,dsKH[i].SoCCCD);
            getline(inp,dsTK[i].MaKH);
            getline(inp,dsTK[i].SoTaiKhoan);
            getline(inp,dsTK[i].TenChuThe);
            getline(inp,dsTK[i].MaPin);
            inp>>dsTK[i].SoDu;
            inp.ignore();
        }

        SLTK=n;
        SLKH=n;
    }
    else
    {
        SLTK=0;
        SLKH=0;
    }

}

void SaveTaiKhoan()
{
    ofstream out("DataTaiKhoan.inp");
    int n=SLTK;out<<n<<"\n";
    for(int i=0;i<n;i++)
    {
        out <<dsKH[i].MaKH<<"\n"
            <<dsKH[i].HoTen<<"\n"
            <<dsKH[i].SDT<<"\n"
            <<dsKH[i].SoCCCD<<"\n"
            <<dsTK[i].MaKH<<"\n"
            <<dsTK[i].SoTaiKhoan<<"\n"
            <<dsTK[i].TenChuThe<<"\n"
            <<dsTK[i].MaPin<<"\n"
            <<dsTK[i].SoDu<<"\n";
    }
}

void DataGiaoDich()
{
    ifstream inp("DataGiaoDich.inp");
    int n=0;
    if(inp>>n)
    {
        inp.ignore();
        for(int i=0;i<n;i++)
        {
            getline(inp,dsGD[i].MaGiaoDich);
            getline(inp,dsGD[i].SoTaiKhoanGoc);
            getline(inp,dsGD[i].SoTaiKhoanDich);
            getline(inp,dsGD[i].LoaiGiaoDich);
            getline(inp,dsGD[i].ThoiGian);
            getline(inp,dsGD[i].NoiDung);
            inp>>dsGD[i].SoTien;
            inp.ignore();
        }

        SLGD=n;
    }
    else {SLGD=0;}

}

void SaveGiaoDich()
{
    ofstream out("DataGiaoDich.inp");
    int n=SLGD;out<<n<<"\n";
    for(int i=0;i<n;i++)
    {
        out <<dsGD[i].MaGiaoDich<<"\n"
            <<dsGD[i].SoTaiKhoanGoc<<"\n"
            <<dsGD[i].SoTaiKhoanDich<<"\n"
            <<dsGD[i].LoaiGiaoDich<<"\n"
            <<dsGD[i].ThoiGian<<"\n"
            <<dsGD[i].NoiDung<<"\n"
            <<dsGD[i].SoTien<<"\n";
    }
}

string LayThoiGianHienTai() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char buffer[25];
    sprintf(buffer, "%02d/%02d/%04d %02d:%02d:%02d",
            ltm->tm_mday, 1 + ltm->tm_mon, 1900 + ltm->tm_year,
            ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
    return string(buffer);
}

void TaoGhiNhanGiaoDich(string tkGoc, string tkDich, string loaiGD, long long soTien, string noiDung) {
    if (SLGD >= 1000005) {
        cout << "Canh bao: Bo nho lich su giao dich da day!\n";
        return;
    }

    GiaoDich gdMoi;
    gdMoi.MaGiaoDich = "GD" + to_string(SLGD + 1); // Tự động tạo mã GD001, GD002...
    gdMoi.SoTaiKhoanGoc = tkGoc;
    gdMoi.SoTaiKhoanDich = tkDich;
    gdMoi.LoaiGiaoDich = loaiGD;
    gdMoi.SoTien = soTien;
    gdMoi.ThoiGian = LayThoiGianHienTai();
    gdMoi.NoiDung = noiDung;

    dsGD[SLGD] = gdMoi;
    SLGD++;
}

int TimTaiKhoan(string soTK)
{
    for (int i = 0; i < SLTK; i++) {
        if (dsTK[i].SoTaiKhoan == soTK) {
            return i;
        }
    }
    return -1;
}

void DangNhap(bool &TrangThaiDangNhap, int &TKDangHoatDong) {
    string soTK, maPin;
    cout << "--- DANG NHAP HE THONG ---\n";
    cout << "Nhap So tai khoan: ";
    cin >> soTK;

    int viTri = TimTaiKhoan(soTK);

    if (viTri == -1) {
        cout << "Loi: Tai khoan khong ton tai!\n";
        return;
    }

    cout << "Nhap Ma PIN: ";
    cin >> maPin;

    if (dsTK[viTri].MaPin == maPin) {
        cout << "=> Dang nhap thanh cong! Xin chao " << dsTK[viTri].TenChuThe << "\n";
        cout << "So du hien tai: " << dsTK[viTri].SoDu << " VND\n";
        TrangThaiDangNhap=true;
        TKDangHoatDong=viTri;

        // Ghi chú: Tại đây có thể thiết lập một biến toàn cục như `TaiKhoanDangDangNhap`
        // để lưu vết phục vụ cho các hàm Nạp/Rút/Chuyển phía sau.
    } else {
        cout << "Loi: Ma PIN khong chinh xac!\n";
    }
}

void NapTien(int viTri)
{
    cout << "--- NAP TIEN VAO TAI KHOAN ---\n";

    long long tienNap;
    cout << "Nhap so tien muon nap (VND): ";
    cin >> tienNap;

    if (tienNap <= 0) {
        cout << "Loi: So tien nap phai lon hon 0!\n";
        return;
    }

    dsTK[viTri].SoDu += tienNap;

    // Ghi nhận giao dịch
    TaoGhiNhanGiaoDich(dsTK[viTri].SoTaiKhoan, "N/A", "NAP", tienNap, "Nap tien tai quay");

    cout << "=> Nap tien thanh cong! So du moi: " << dsTK[viTri].SoDu << " VND\n";
}

void RutTien(int viTri)
{
    cout << "--- RUT TIEN MAT ---\n";

    long long tienRut;
    cout << "Nhap so tien muon rut (VND): ";
    cin >> tienRut;

    if (tienRut <= 0) {
        cout << "Loi: So tien rut phai lon hon 0!\n";
        return;
    }

    if (dsTK[viTri].SoDu - tienRut < 50000) {
        cout << "Loi: So du khong du! Phai duy tri toi thieu 50,000 VND trong tai khoan.\n";
        return;
    }

    dsTK[viTri].SoDu -= tienRut;
    TaoGhiNhanGiaoDich(dsTK[viTri].SoTaiKhoan, "N/A", "RUT", tienRut, "Rut tien mat");

    cout << "=> Rut tien thanh cong! So du moi: " << dsTK[viTri].SoDu << " VND\n";
}

void ChuyenKhoan(int viTri)
{
    string soTKGoc, soTKDich;
    soTKGoc=dsTK[viTri].SoTaiKhoan;
    cout << "--- CHUYEN KHOAN NGAN HANG ---\n";

    cout << "Nhap So tai khoan dich: ";
    cin >> soTKDich;
    int viTriDich = TimTaiKhoan(soTKDich);

    if (viTriDich == -1) {
        cout << "Loi: Tai khoan dich khong ton tai tren he thong!\n";
        return;
    }

    if (soTKGoc == soTKDich) {
        cout << "Loi: Khong the chuyen khoan cho chinh minh!\n";
        return;
    }

    cout << "=> Tai khoan dich: " << dsTK[viTriDich].TenChuThe << "\n";

    long long tienChuyen;
    cout << "Nhap so tien muon chuyen (VND): ";
    cin >> tienChuyen;

    if (tienChuyen <= 0) {
        cout << "Loi: So tien chuyen phai lon hon 0!\n";
        return;
    }

    if (dsTK[viTri].SoDu - tienChuyen < 50000) {
        cout << "Loi: So du khong du thuc hien! Phai duy tri toi thieu 50,000 VND.\n";
        return;
    }

    string noiDung;
    cout << "Nhap noi dung chuyen khoan (khong dau): ";
    cin.ignore();
    getline(cin, noiDung);

    dsTK[viTri].SoDu -= tienChuyen;
    dsTK[viTriDich].SoDu += tienChuyen;

    // Ghi nhận giao dịch chuyển khoản
    TaoGhiNhanGiaoDich(soTKGoc, soTKDich, "CHUYEN", tienChuyen, noiDung);

    cout << "=> Chuyen khoan thanh cong!\n";
    cout << "So du moi cua ban: " << dsTK[viTri].SoDu << " VND\n";
}

void TinhLaiSuat(int viTri) {
    cout << "--- TINH LAI SUAT TIEN GUI KHONG KY HAN ---\n";

    int soThang;
    cout << "Nhap so thang da gui (de mo phong chot lai): ";
    cin >> soThang;

    if (soThang <= 0) {
        cout << "Loi: So thang phai lon hon 0!\n";
        return;
    }

    // Giả sử lãi suất không kỳ hạn là 0.2% / tháng (tương đương 2.4% / năm)
    double laiSuatThang = 0.002;
    long long tienLai = dsTK[viTri].SoDu * laiSuatThang * soThang;

    dsTK[viTri].SoDu += tienLai;

    // Ghi nhận giao dịch nhận lãi
    TaoGhiNhanGiaoDich(dsTK[viTri].SoTaiKhoan, "N/A", "NHAN_LAI", tienLai, "Tra lai tien gui khong ky han " + to_string(soThang) + " thang");

    cout << "=> Da cong tien lai: " << tienLai << " VND vao tai khoan.\n";
    cout << "So du moi: " << dsTK[viTri].SoDu << " VND\n";
}

void SaoKe(int viTri) {
    string ngayBatDau, ngayKetThuc;
    cout << "--- SAO KE GIAO DICH ---\n";

    cout << "Nhap ngay bat dau (YYYY/MM/DD) hoac nhap ALL de xem toan bo: ";
    cin >> ngayBatDau;

    if (ngayBatDau != "ALL") {
        cout << "Nhap ngay ket thuc (YYYY/MM/DD): ";
        cin >> ngayKetThuc;
    }

    cout << "\n================ LICH SU GIAO DICH ================\n";
    cout << "Tai khoan: " << dsTK[viTri].TenChuThe << " | So TK: " << dsTK[viTri].SoTaiKhoan << "\n";
    cout << "---------------------------------------------------\n";

    bool coGiaoDich = false;

    for (int i = 0; i < SLGD; i++) {
        if (dsGD[i].SoTaiKhoanGoc == dsTK[viTri].SoTaiKhoan || dsGD[i].SoTaiKhoanDich == dsTK[viTri].SoTaiKhoan) {
            // Cắt 10 ký tự đầu của chuỗi thời gian (YYYY/MM/DD) để so sánh
            string ngayGiaoDich = dsGD[i].ThoiGian.substr(0, 10);

            // Lọc theo khoảng thời gian nếu người dùng không chọn ALL
            if (ngayBatDau != "ALL") {
                if (ngayGiaoDich < ngayBatDau || ngayGiaoDich > ngayKetThuc) {
                    continue; // Bỏ qua giao dịch nằm ngoài khoảng
                }
            }

            coGiaoDich = true;
            cout << "[" << dsGD[i].ThoiGian << "] - Ma GD: " << dsGD[i].MaGiaoDich << "\n";

            if (dsGD[i].LoaiGiaoDich == "NAP" || dsGD[i].LoaiGiaoDich == "NHAN_LAI") {
                cout << "  + " << dsGD[i].SoTien << " VND (" << dsGD[i].NoiDung << ")\n";
            }
            else if (dsGD[i].LoaiGiaoDich == "RUT") {
                cout << "  - " << dsGD[i].SoTien << " VND (Rut tien)\n";
            }
            else if (dsGD[i].LoaiGiaoDich == "CHUYEN") {
                if (dsGD[i].SoTaiKhoanGoc == dsTK[viTri].SoTaiKhoan) {
                    cout << "  - " << dsGD[i].SoTien << " VND (Chuyen den: " << dsGD[i].SoTaiKhoanDich << ")\n";
                    cout << "  Noi dung: " << dsGD[i].NoiDung << "\n";
                } else {
                    cout << "  + " << dsGD[i].SoTien << " VND (Nhan tu: " << dsGD[i].SoTaiKhoanGoc << ")\n";
                    cout << "  Noi dung: " << dsGD[i].NoiDung << "\n";
                }
            }
            cout << "---------------------------------------------------\n";
        }
    }

    if (!coGiaoDich) {
        cout << "Khong co giao dich nao trong khoang thoi gian nay.\n";
    }
    cout << "===================================================\n";
}

void TaoTK() {
    if (SLTK >= 1000005 || SLKH >= 1000005) {
        cout << "He thong da dat gioi han bo nho!\n";
        return;
    }

    TaiKhoan tkMoi;
    KhachHang khMoi;

    cout << "--- TAO TAI KHOAN MOI ---\n";

    cin.ignore(10000, '\n');

    cout << "Nhap Ho ten chu the: ";
    getline(cin, khMoi.HoTen);

    // Đồng nhất biến Họ Tên của Khách Hàng với Tên Chủ Thẻ của Tài Khoản
    tkMoi.TenChuThe = khMoi.HoTen;

    cout << "Nhap So dien thoai: ";
    getline(cin, khMoi.SDT);

    cout << "Nhap So CCCD: ";
    getline(cin, khMoi.SoCCCD);

    // Sinh Mã Khách Hàng liên kết 2 bảng
    string maKHMoi = "KH" + to_string(SLKH + 1);
    khMoi.MaKH = maKHMoi;
    tkMoi.MaKH = maKHMoi;

    cout << "Nhap So tai khoan: ";
    cin >> tkMoi.SoTaiKhoan;

    // Kiểm tra số tài khoản đã tồn tại chưa
    if (TimTaiKhoan(tkMoi.SoTaiKhoan) != -1) {
        cout << "Loi: So tai khoan nay da ton tai!\n";
        return;
    }

    cout << "Thiet lap Ma PIN: ";
    cin >> tkMoi.MaPin;

    // Quy định số dư tối thiểu ban đầu
    tkMoi.SoDu = 50000;

    dsKH[SLKH] = khMoi;
    SLKH++;

    dsTK[SLTK] = tkMoi;
    SLTK++;

    cout << "=> Tao tai khoan thanh cong! So du ban dau la 50,000 VND.\n";
}

int main()
{
    DataTaiKhoan();
    DataGiaoDich();
    string LuaChon;
    bool TrangThaiDangNhap = false;
    int TkDangHoatDong=-1;
    while(true){
        cout << "=========================================";
        cout << "\n      HE THONG QUAN LY NGAN HANG         ";
        cout << "\n=========================================";
        cout << "\n1. Dang nhap tai khoan";
        cout << "\n2. Nap tien vao tai khoan";
        cout << "\n3. Rut tien";
        cout << "\n4. Chuyen khoan";
        cout << "\n5. Xem sao ke giao dich";
        cout << "\n6. Tinh lai suat theo thang";
        cout << "\n7. Tao tai khoan";
        cout << "\n0. Luu du lieu va Thoat";
        cout << "\n=========================================";
        cout << "\nNhap lua chon cua ban: ";

        cin >> LuaChon;
        if(LuaChon.length()!=1)
        {
            cout << "Lua chon khong hop le. Vui long thu lai!\n";
            continue;
        }
        char LuaChonHopLe=LuaChon[0];

    switch(LuaChonHopLe){
        case '1':
            DangNhap(TrangThaiDangNhap,TkDangHoatDong);
            break;
        case '2':
            if(TrangThaiDangNhap==false)
            {
                cout<<"Ban chua dang nhap!";
                break;
            }
            NapTien(TkDangHoatDong);
            break;
        case '3':
            if(TrangThaiDangNhap==false)
            {
                cout<<"Ban chua dang nhap!";
                break;
            }
            RutTien(TkDangHoatDong);
            break;
        case '4':
            if(TrangThaiDangNhap==false)
            {
                cout<<"Ban chua dang nhap!";
                break;
            }
            ChuyenKhoan(TkDangHoatDong);
            break;
        case '5':
            if(TrangThaiDangNhap==false)
            {
                cout<<"Ban chua dang nhap!";
                break;
            }
            SaoKe(TkDangHoatDong);
            //nhap(TkDangHoatDong);
            break;
        case '6':
            if(TrangThaiDangNhap==false)
            {
                cout<<"Ban chua dang nhap!";
                break;
            }
            TinhLaiSuat(TkDangHoatDong);
            break;
        case '7':
            TaoTK();
            break;
        case '0':
            //Ghi đè toàn bộ dữ liệu từ 3 danh sách xuống lại file txt
            cout << "Da luu du lieu. Hen gap lai!\n";
            SaveTaiKhoan();
            SaveGiaoDich();
            return 0;
        default:
            cout << "Lua chon khong hop le. Vui long thu lai!\n";
        }
    }

}
