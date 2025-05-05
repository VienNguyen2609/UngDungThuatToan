#include<bits/stdc++.h>
using namespace std ; 

struct CauThu {
    string hoVaTen;
    int namSinh;
    double luongThang;
    int namBatDauThiDau;
};


vector<CauThu> khoiTaoDanhSach() {
    return {
        {"Nguyen Van A", 2000, 150000, 2020},
        {"Le Thi B", 1999, 160000, 2025},
        {"Tran Van C", 2001, 140000, 2024},
        {"Pham Thi D", 2003, 170000, 2021},
        {"Hoang Van E", 1998, 190000, 2023},
        {"Nguyen Thi F", 2002, 175000, 2025},
        {"Vo Van G", 2000, 180000, 2022}
    };
}

void hienThiTieuDe() {
    cout << "STT | Ho va ten       | Nam sinh | Luong (VND) | Nam bat dau\n";
    cout << "----+-----------------+----------+-------------+-------------\n";
}

void hienThiCauThu(const CauThu& ct, int stt) {
    cout << stt << "   | " << ct.hoVaTen
         << string(17 - ct.hoVaTen.length(), ' ')
         << "| " << ct.namSinh
         << "     | " << fixed << ct.luongThang
         << "     | " << ct.namBatDauThiDau << endl;
}

void hienThiDeQuy(const vector<CauThu>& ds, int i = 0) {
    if (i == ds.size()) return;
    hienThiCauThu(ds[i], i + 1);
    hienThiDeQuy(ds, i + 1);
}

int demChuaThiDau(const vector<CauThu>& ds, int left, int right, int namHienTai) {
    if (left > right) return 0;
    if (left == right) return ds[left].namBatDauThiDau > namHienTai ? 1 : 0;

    int mid = (left + right) / 2;
    int trai = demChuaThiDau(ds, left, mid, namHienTai);
    int phai = demChuaThiDau(ds, mid + 1, right, namHienTai);
    return trai + phai;
}


void xepCauThu(vector<CauThu>& ds, int i, vector<bool>& used, vector<CauThu>& viTri, int& dem) {
    int n = ds.size();
    if (i == n) {
        ++dem;
        cout << "Phuong an " << dem << ":\n";
        for (int j = 0; j < n; ++j) {
            cout << "  Vi tri " << j + 1 << ": " << viTri[j].hoVaTen << endl;
        }
        cout << "--------------------------\n";
        return;
    }

    for (int j = 0; j < n; ++j) {
        if (!used[j]) {
            used[j] = true;
            viTri[i] = ds[j];
            xepCauThu(ds, i + 1, used, viTri, dem);
            used[j] = false;
        }
    }
}

// -----------------------------
int main() {
    vector<CauThu> danhSach = khoiTaoDanhSach();
    int n = danhSach.size();
    int namHienTai = 2025;

    // A1 – In danh sách bằng đệ quy
    cout << "=== DANH SACH CAU THU ===\n";
    hienThiTieuDe();
    hienThiDeQuy(danhSach);

    // A2 – Đếm cầu thủ chưa thi đấu
    int soChuaThiDau = demChuaThiDau(danhSach, 0, n - 1, namHienTai);
    cout << "\nSo cau thu chua thi dau tinh den nam " << namHienTai << ": " << soChuaThiDau << endl;

    // A3 – In các cách xếp n cầu thủ vào n vị trí
    cout << "\n=== CAC PHUONG AN XEP CAU THU VAO VI TRI ===\n";
    vector<bool> used(n, false);
    vector<CauThu> viTri(n);
    int demPhuongAn = 0;
    xepCauThu(danhSach, 0, used, viTri, demPhuongAn);

    cout << "\nTong so phuong an: " << demPhuongAn << endl;
    return 0;
}
