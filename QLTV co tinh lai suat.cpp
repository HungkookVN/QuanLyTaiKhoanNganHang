#include <bits/stdc++.h>

using namespace std;

struct KhachHang {
    string MaKH;
    string HoTen;
    string SDT;
    string SoCCCD;
};

struct TaiKhoan {
    string SoTaiKhoan;
    string MaKH;
    string TenChuThe;
    string MaPin;
    long long SoDu;
};

struct GiaoDich {
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

int SLKH = 0;
int SLTK = 0;
int SLGD = 0;

// Đổi định dạng thành YYYY/MM/DD HH:MM:SS để chuẩn hóa việc so sánh chuỗi thời gian
string LayThoiGianHienTai() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char buffer[25];
    sprintf(buffer, "%04d/%02d/%02d %02d:%02d:%02d",
            1900 + ltm->tm_year, 1 + ltm->tm_mon, ltm->tm_mday,
            ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
    return string(buffer);
}

void TaoGhiNhanGiaoDich(string tkGoc, string tkDich, string loaiGD, long long soTien, string noiDung) {
    if (SLGD >= 1000005) {
        cout << "Canh bao: Bo nho lich su giao dich da day!\n";
        return;
    }

    GiaoDich gdMoi;
    gdMoi.MaGiaoDich = "GD" + to_string(SLGD + 1);
    gdMoi.SoTaiKhoanGoc = tkGoc;
    gdMoi.SoTaiKhoanDich = tkDich;
    gdMoi.LoaiGiaoDich = loaiGD;
    gdMoi.SoTien = soTien;
    gdMoi.ThoiGian = LayThoiGianHienTai();
    gdMoi.NoiDung = noiDung;

    dsGD[SLGD] = gdMoi;
    SLGD++;
}

int TimTaiKhoan(string soTK) {
    for (int i = 0; i < SLTK; i++) {
        if (dsTK[i].SoTaiKhoan == soTK) {
            return i;
        }
    }
    return -1;
}

void DangNhap() {
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
    } else {
        cout << "Loi: Ma PIN khong chinh xac!\n";
    }
}

void NapTien() {
    string soTK, maPin;
    cout << "--- NAP TIEN VAO TAI KHOAN ---\n";
    cout << "Nhap So tai khoan: ";
    cin >> soTK;

    int viTri = TimTaiKhoan(soTK);
    if (viTri == -1) {
        cout << "Loi: Tai khoan khong ton tai!\n";
        return;
    }

    cout << "Nhap Ma PIN: ";
    cin >> maPin;

    if (dsTK[viTri].MaPin != maPin) {
        cout << "Loi: Ma PIN khong chinh xac!\n";
        return;
    }

    long long tienNap;
    cout << "Nhap so tien muon nap (VND): ";
    cin >> tienNap;

    if (tienNap <= 0) {
        cout << "Loi: So tien nap phai lon hon 0!\n";
        return;
    }

    dsTK[viTri].SoDu += tienNap;
    TaoGhiNhanGiaoDich(soTK, "N/A", "NAP", tienNap, "Nap tien tai quay");
    cout << "=> Nap tien thanh cong! So du moi: " << dsTK[viTri].SoDu << " VND\n";
}

void RutTien() {
    string soTK, maPin;
    cout << "--- RUT TIEN MAT ---\n";
    cout << "Nhap So tai khoan: ";
    cin >> soTK;

    int viTri = TimTaiKhoan(soTK);
    if (viTri == -1) {
        cout << "Loi: Tai khoan khong ton tai!\n";
        return;
    }

    cout << "Nhap Ma PIN: ";
    cin >> maPin;

    if (dsTK[viTri].MaPin != maPin) {
        cout << "Loi: Ma PIN khong chinh xac!\n";
        return;
    }

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
    TaoGhiNhanGiaoDich(soTK, "N/A", "RUT", tienRut, "Rut tien mat");
    cout << "=> Rut tien thanh cong! So du moi: " << dsTK[viTri].SoDu << " VND\n";
}

void ChuyenKhoan() {
    string soTKGoc, soTKDich, maPin;
    cout << "--- CHUYEN KHOAN NGAN HANG ---\n";
    cout << "Nhap So tai khoan nguon: ";
    cin >> soTKGoc;
    int viTriGoc = TimTaiKhoan(soTKGoc);
    if (viTriGoc == -1) {
        cout << "Loi: Tai khoan nguon khong ton tai!\n";
        return;
    }

    cout << "Nhap Ma PIN: ";
    cin >> maPin;
    if (dsTK[viTriGoc].MaPin != maPin) {
        cout << "Loi: Ma PIN khong chinh xac!\n";
        return;
    }

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

    if (dsTK[viTriGoc].SoDu - tienChuyen < 50000) {
        cout << "Loi: So du khong du thuc hien! Phai duy tri toi thieu 50,000 VND.\n";
        return;
    }

    string noiDung;
    cout << "Nhap noi dung chuyen khoan (khong dau): ";
    cin.ignore();
    getline(cin, noiDung);

    dsTK[viTriGoc].SoDu -= tienChuyen;
    dsTK[viTriDich].SoDu += tienChuyen;

    TaoGhiNhanGiaoDich(soTKGoc, soTKDich, "CHUYEN", tienChuyen, noiDung);
    cout << "=> Chuyen khoan thanh cong!\n";
    cout << "So du moi cua ban: " << dsTK[viTriGoc].SoDu << " VND\n";
}

// Chức năng mới 1: Tính lãi suất tiền gửi không kỳ hạn
void TinhLaiSuat() {
    string soTK, maPin;
    cout << "--- TINH LAI SUAT TIEN GUI KHONG KY HAN ---\n";
    cout << "Nhap So tai khoan: ";
    cin >> soTK;

    int viTri = TimTaiKhoan(soTK);
    if (viTri == -1) {
        cout << "Loi: Tai khoan khong ton tai!\n";
        return;
    }

    cout << "Nhap Ma PIN de xac thuc: ";
    cin >> maPin;
    if (dsTK[viTri].MaPin != maPin) {
        cout << "Loi: Ma PIN khong chinh xac!\n";
        return;
    }

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
    TaoGhiNhanGiaoDich(soTK, "N/A", "NHAN_LAI", tienLai, "Tra lai tien gui khong ky han " + to_string(soThang) + " thang");

    cout << "=> Da cong tien lai: " << tienLai << " VND vao tai khoan.\n";
    cout << "So du moi: " << dsTK[viTri].SoDu << " VND\n";
}

// Chức năng mới 2: Sao kê lọc theo thời gian
void SaoKe() {
    string soTK, maPin, ngayBatDau, ngayKetThuc;
    cout << "--- SAO KE GIAO DICH ---\n";
    cout << "Nhap So tai khoan: ";
    cin >> soTK;

    int viTri = TimTaiKhoan(soTK);
    if (viTri == -1) {
        cout << "Loi: Tai khoan khong ton tai!\n";
        return;
    }

    cout << "Nhap Ma PIN de xac thuc in sao ke: ";
    cin >> maPin;
    if (dsTK[viTri].MaPin != maPin) {
        cout << "Loi: Ma PIN khong chinh xac!\n";
        return;
    }

    cout << "Nhap ngay bat dau (YYYY/MM/DD) hoac nhap ALL de xem toan bo: ";
    cin >> ngayBatDau;

    if (ngayBatDau != "ALL") {
        cout << "Nhap ngay ket thuc (YYYY/MM/DD): ";
        cin >> ngayKetThuc;
    }

    cout << "\n================ LICH SU GIAO DICH ================\n";
    cout << "Tai khoan: " << dsTK[viTri].TenChuThe << " | So TK: " << soTK << "\n";
    cout << "---------------------------------------------------\n";

    bool coGiaoDich = false;

    for (int i = 0; i < SLGD; i++) {
        if (dsGD[i].SoTaiKhoanGoc == soTK || dsGD[i].SoTaiKhoanDich == soTK) {
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
                if (dsGD[i].SoTaiKhoanGoc == soTK) {
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
    if (SLTK >= 1000005) {
        cout << "He thong da dat gioi han bo nho!\n";
        return;
    }

    TaiKhoan tkMoi;
    cout << "--- TAO TAI KHOAN MOI ---\n";
    cout << "Nhap So tai khoan: ";
    cin >> tkMoi.SoTaiKhoan;

    if (TimTaiKhoan(tkMoi.SoTaiKhoan) != -1) {
        cout << "Loi: So tai khoan nay da ton tai!\n";
        return;
    }

    cout << "Nhap Ma Khach Hang: ";
    cin >> tkMoi.MaKH;

    cin.ignore();
    cout << "Nhap Ten Chu The: ";
    getline(cin, tkMoi.TenChuThe);

    cout << "Thiet lap Ma PIN: ";
    cin >> tkMoi.MaPin;

    tkMoi.SoDu = 50000;
    dsTK[SLTK] = tkMoi;
    SLTK++;

    cout << "=> Tao tai khoan thanh cong! So du ban dau la 50,000 VND.\n";
}

int main() {
    int LuaChon;
    bool HoatDong = true;
    while(HoatDong) {
        cout << "\n=========================================";
        cout << "\n      HE THONG QUAN LY NGAN HANG         ";
        cout << "\n=========================================";
        cout << "\n1. Dang nhap tai khoan";
        cout << "\n2. Nap tien vao tai khoan";
        cout << "\n3. Rut tien";
        cout << "\n4. Chuyen khoan";
        cout << "\n5. Xem sao ke giao dich";
        cout << "\n6. Tao tai khoan";
        cout << "\n7. Tinh lai suat theo thang";
        cout << "\n0. Luu du lieu va Thoat";
        cout << "\n=========================================";
        cout << "\nNhap lua chon cua ban: ";
        cin >> LuaChon;

        switch(LuaChon) {
        case 1: DangNhap(); break;
        case 2: NapTien(); break;
        case 3: RutTien(); break;
        case 4: ChuyenKhoan(); break;
        case 5: SaoKe(); break;
        case 6: TaoTK(); break;
        case 7: TinhLaiSuat(); break;
        case 0:
            cout << "Da luu du lieu. Hen gap lai!\n";
            HoatDong = false;
            break;
        default:
            cout << "Lua chon khong hop le. Vui long thu lai!\n";
        }
    }
    return 0;
}
