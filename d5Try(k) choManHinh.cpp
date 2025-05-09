#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX = 100;

struct ManHinh {
    string tenHang;
    float kichThuoc;
    float giaBan;
};

int n = 7; // Giả sử có 4 màn hình, bạn có thể đổi lại ≥ 7
ManHinh danhSach[MAX] = {
    {"LG", 24.0, 3500000},
    {"Samsung", 27.0, 4200000},
    {"Asus", 15.6, 3000000},
    {"Acer", 15.6, 3000000},
    {"Lenovo", 15.6, 3000000},
    {"Dell", 15.6, 3000000},
    {"MSI", 17.0, 3200000}
};

int viTri[10];      // x[i] là chỉ số màn hình đặt lên bàn thứ i
bool dd[10];    // dd[i] = true nếu màn hình i đã được dùng
int dem = 0;
int gioiHan = 30; 

void show() {
	
	if(dem >= gioiHan ){
    	return ; 
	}
	
    cout << "Phuong an " << ++dem << ":\n";
    
    for (int i = 0; i < n; i++) {
        cout << "Ban " << i + 1 << " - " << danhSach[viTri[i]].tenHang << endl;
    }
    cout << "-------------------------\n";
}

void Try(int k) {

    for (int i = 0; i < n; i++) {
    	
        if (!dd[i]) {
            viTri[k] = i;
            dd[i] = true;
          
        if (k == n - 1 ) {
            show();
        }
		
		else {
            
            Try(k + 1);
        }
        dd[i] = false;
     }
    }
}


int main() {
    // Gọi thuật toán quay lui để tìm các hoán vị
    Try(0);
    cout << "Tong so phuong an: " << dem << endl;
    return 0;
}
