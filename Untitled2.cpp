#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

struct HocSinh {
    string hoTen;
    float diemTongKet;
    string xepLoaiDaoDuc;
    int tienThuong;
};

// Khởi tạo danh sách học sinh (n >= 7)
int n = 8;
HocSinh d[MAX] = {
    {"Nguyen Van A", 8.5, "Tot", 500000},
    {"Tran Thi B", 6.8, "Kha", 300000},
    {"Le Van C", 7.2, "Tot", 400000},
    {"Pham Thi D", 9.0, "Tot", 600000},
    {"Hoang Van E", 5.5, "Trung binh", 0},
    {"Vo Thi F", 7.8, "Kha", 350000},
    {"Do Van G", 6.5, "Kha", 200000},
    {"Nguyen Thi H", 8.0, "Tot", 450000}
};

// ===================== A4: ĐỆ QUY TÍNH TỔNG TIỀN THƯỞNG =====================
int tongTienThuong(HocSinh d[], int n) {
    if (n == 0) return 0;
    return d[n - 1].tienThuong + tongTienThuong(d, n - 1);
}

// ===================== A5: CHIA ĐỂ TRỊ ĐẾM HỌC SINH ĐIỂM >= 7.0 =====================
int demHocSinhDiemCao(HocSinh d[], int left, int right) {
    if (left > right) return 0;
    if (left == right)
        return d[left].diemTongKet >= 7.0 ? 1 : 0;
    int mid = (left + right) / 2;
    return demHocSinhDiemCao(d, left, mid) + demHocSinhDiemCao(d, mid + 1, right);
}

// ===================== A6: QUAY LUI CHỌN 6 HỌC SINH =====================
void xuatToHop(HocSinh toHop[], int k) {
    for (int i = 0; i < k; i++) {
        cout << "- " << toHop[i].hoTen << " | Xếp loại: " << toHop[i].xepLoaiDaoDuc << endl;
    }
    cout << "---------------------" << endl;
}

int soPhuongAn = 0;

void chon6HocSinh(HocSinh d[], int n, int start, HocSinh toHop[], int k, int index) {
   
    if (index == k) {
        xuatToHop(toHop, k);
        soPhuongAn++;
        return;
    }
    for (int i = start; i <= n - (k - index); i++) { // i <= 8 - 6 + 0 
        toHop[index] = d[i];
        chon6HocSinh(d, n, i + 1, toHop, k, index + 1);
    }
}

// ===================== MAIN =====================
int main() {
    cout << "TONG TIEN THUONG (A4): " << tongTienThuong(d, n) << " VND\n\n";

    int soHocSinhDiemCao = demHocSinhDiemCao(d, 0, n - 1);
    cout << "SO HOC SINH CO DIEM >= 7.0 (A5): " << soHocSinhDiemCao << "\n\n";

    cout << "CAC PHUONG AN CHON 6 HOC SINH (A6):\n";
    HocSinh toHop[6];
    chon6HocSinh(d, n, 0, toHop, 6, 0);
    cout << "TONG SO PHUONG AN: " << soPhuongAn << endl;

    return 0;
}
