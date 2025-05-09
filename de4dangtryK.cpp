#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX = 100;

struct HocSinh {
    string hoTen;
    double diem;
    string loaiDaoDuc;
    double tienThuong;
};

int n = 8; // Số học sinh
int k = 6; // Số học sinh cần chọn
HocSinh d[MAX] = {
    {"VienA", 9, "Gioi", 5000},
    {"VienB", 8, "Gioi", 4000},
    {"VienC", 10, "Xuat Sac", 7000},
    {"VienD", 6, "TB", 2000},
    {"VienE", 9, "Gioi", 5000},
    {"VienF", 7.5, "Kha", 3000},
    {"VienG", 5, "Yeu", 0},
    {"VienH", 8.5, "Gioi", 4500}
};

int x[10];     // Lưu chỉ số học sinh được chọn
bool dd[MAX];  // Đánh dấu đã chọn hay chưa
int soPhuongAn = 0;

// In ra tổ hợp học sinh
void show() {
    cout << "Phuong an " << ++soPhuongAn << ":\n";
    cout << setw(20) << "Ho va ten" << setw(10) << "Diem" << setw(15) << "Dao Duc" << setw(15) << "Thuong\n";
    for (int i = 1; i <= k; i++) {
        HocSinh hs = d[x[i]];
        cout << setw(20) << hs.hoTen << setw(10) << hs.diem << setw(15) << hs.loaiDaoDuc << setw(15) << hs.tienThuong << "\n";
    }
    cout << endl;
}

// Hàm quay lui dạng Try(k)
void Try(int step, int start) {
    for (int i = start; i < n; i++) {
        if (!dd[i]) {
            x[step] = i;
        }
            dd[i] = true;

            if (step == k){
                show();
            }
            else{
                Try(step + 1, i + 1); // Chỉ xét tiếp từ i+1 để tránh trùng
            }
            dd[i] = false; // Hủy đánh dấu
        }
    }

int main() {
    Try(1, 0);
    cout << "Tong so phuong an: " << soPhuongAn << endl;
    return 0;
}
