
/*
Cho danh sách d gồm n can rượu có dung tích và nhãn hiệu khác nhau, thông tin về mỗi can rượu gồm: nhăn
hiệu, dung tích (lít, số nguyên), giá trị (vnd), (Ví dụ: Vang Pháp, 2, 1200000). Cho một số s = 100. Cải đặt
chương trình thực hiện.
Câu 1:
- Cải đặt thuật toán A theo chiến lược tham lam trả về các dữ liệu cần thiết để cho biết rằng nếu sử dụng vừa
hết số tiền m có thể mua được nhiều nhất bao nhiêu can rượu trong danh sách d, gồm những can rượu nào
nào?
- Khởi tạo m, n (6 ≤ n) và danh sách d (dữ liệu của danh sách d có tính thực tiễn). Sử dụng thuật toán A,
thông qua các dữ liệu trả về từ A hãy hiển thị các kết quả, với mỗi can rượu hiển thị nhăn hiệu, giá bán.

Câu 2:
- Cải đặt một thuật toán B theo chiến lược quy hoạch động trả về các dữ liệu cần thiết để cho biết cần mua
những can rượu nào sao cho tổng giá trị có được là lớn nhất và tổng dung tích không vượt quả s.
- Khởi tạo s. Sử dụng thuật toán B, với các dữ liệu trả về từ B hãy hiển thị bảng phương án, số lượng can
rượu và thông tin đầy đủ về các can rượu cần mua.
viết bằng c++ , giải bài trên đơn giản nhất dùng mảng không dùng vector 
*/

#include<bits/stdc++.h>

using namespace std ; 

struct CanRuou{
	
	char nhanHieu[50] ; 
	int dungTich ; 
	int giaTri;

};

const int MAX =100 ; 


void xapXepTheoGiaTangDan(CanRuou ds[] , int n ){
	for(int i = 0 ; i < n ; i ++  ){
		for(int j = n -1 ; j > i ; j-- ){
			if(ds[j].giaTri < ds[i].giaTri){
				swap(ds[j] , ds[i] );
			}
		}
	}
}




void xuatTieuDe(){
	
	cout<<setw(10)<<"STT"<<
	setw(20)<<"Nhan Hieu"<<
	setw(20)<<"Dung tich"<<
	setw(20)<<"Gia Ban"<<endl ;
	
}



void A_MuaCanRuou(CanRuou ds[] , int n , int m ){
	
	xapXepTheoGiaTangDan(ds, n ); 
	
	int soLuongKQ = 0 ; 
	float tongTien = 0 ;
	CanRuou ketQua[n+1] ; 

	for(int i = 0 ; i < n ; i ++ ) { 
	    if(tongTien + ds[i].giaTri<= m){
	       ketQua[soLuongKQ++] = ds[i]; 
	       tongTien +=  ds[i].giaTri ; 	
		}
	} 
	
	if(soLuongKQ == 0 ){
		cout<<"+ Voi so tien "<<m << " khong the mua duoc can ruou nao trong danh sach\n"; 
		return ;
	}
	
    cout<<"+ So tien hien co: "<<m <<" VND\n";
	cout<<"+ Co the mua duoc toi da: "<< soLuongKQ <<" can ruou"<<endl;
	
	cout<<"+ So tien da dung: "<< tongTien <<" VND"<<endl; 
	
	cout<<"+ So tien con lai: "<< m - tongTien <<" VND"<<endl; 
	
	cout<<endl;
	cout<<"---------Danh sach ruou co the mua duoc la--------\n" ;  
	
	cout<<setw(10)<<"STT"<<
	setw(20)<<"Nhan Hieu"<<
	setw(20)<<"Gia Ban"<<endl;
	int soThuTu = 0 ;
	for(int i = 0 ; i < soLuongKQ; i ++){
		cout<<setw(10)<<soThuTu<<setw(20)<<
		ketQua[i].nhanHieu<<setw(20)<<
		ketQua[i].giaTri<<endl ;
		soThuTu++ ;
	}
	
}

int dp[MAX][MAX]; // dp[i][j]: max giá trị với j lít và i can đầu tiên

void thuatToanB(CanRuou d[], int n, int s) {
	
    // Khởi tạo DP
    for (int i = 0; i <= n; ++i){
        for (int j = 0; j <= s; ++j){
            dp[i][j] = 0;
        }
    }

    // Duyệt các can
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= s; ++j) {
            if (d[i-1].dungTich <= j) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - d[i-1].dungTich] + d[i-1].giaTri);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << "Tong gia tri lon nhat: " << dp[n][s] << " VND\n";

    // Truy vết
    int i = n, j = s;
    CanRuou ketQua[MAX];
    int soLuong = 0;

    while (i > 0 && j > 0) {
        if (dp[i][j] != dp[i-1][j]) {
            ketQua[soLuong++] = d[i-1];
            j -= d[i-1].dungTich;
        }
        i--;
    }

    cout << "So luong can ruou: " << soLuong << endl;
    cout << setw(50)<<"----------Danh sach----------\n";
    int soThuTu = 0 ;
    xuatTieuDe();
    for (int k = soLuong - 1; k >= 0; --k){
		cout<<setw(10)<<soThuTu<<setw(20)<<
		ketQua[k].nhanHieu<<setw(20)<<
		ketQua[k].dungTich<<setw(20)<<
		ketQua[k].giaTri<<endl ;
		soThuTu++ ;
	}
}


int main(){
	
    int n = 6 , m = 100000, s = 90 ; 
    CanRuou ds[n] ={
	{"Vang Phap", 20, 12000},
    {"Vang Y", 15, 9000},
    {"Vang Chile", 25, 13000},
    {"Vang My", 10, 50000},
    {"Vang Australia", 30, 16000},
    {"Vang Viet", 8, 5000}
	};
	
	xapXepTheoGiaTangDan(ds, n ); 
	
	xuatTieuDe();
	int soThuTu= 0 ;
	for(int i = 0 ; i < n ; i ++ ){
		cout <<setw(10)<<soThuTu<<setw(20)<<ds[i].nhanHieu <<setw(20)<<ds[i].giaTri<<setw(20)<<ds[i].dungTich<<endl ;
		soThuTu++;
	}
	
	A_MuaCanRuou(ds, n  , m );
	
	thuatToanB(ds , n ,s );
}



