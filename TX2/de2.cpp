/*
Cho danh sách d gồm n quyền giáo trình của n học phần khác nhau, thông tin về mỗi giáo trình gồm: tên giáo
trình (vi dụ: "Ngôn ngữ lập trình python", "Lập trình cơ sở dữ liệu", ... ), tên tác giả, giá bìa. Cải đặt chương
trình thực hiện.
Câu 1:
- Cải đặt thuật toán C theo chiến lược tham lam trả về các dữ liệu cần thiết để cho biết có thế mua được
nhiều nhất bao nhiêu giáo trình trong danh sách d mà số tiền không vượt quá một số tiền p cho trước, gồm
những giáo trình nào?
- Khởi tạo p, n (5 ≤n) và danh sách d (dữ liệu của danh sách d có tính thực tiễn). Sử dụng thuật toán C, với
những dữ liệu trả về từ C hãy hiển thị kết quả, với mỗi giáo trình cần hiển thị đầy đủ thông tin (nếu có).
Câu 2:

- Cải đặt một thuật toán B theo chiến lược quy hoạch động trả về các dữ liệu cần thiết để cho biết cần mua
những can rượu nào sao cho tổng giá trị có được là lớn nhất và tổng dung tích không vượt quả s.
- Khởi tạo s. Sử dụng thuật toán B, với các dữ liệu trả về từ B hãy hiển thị bảng phương án, số lượng can
rượu và thông tin đầy đủ về các can rượu cần mua.

- Cài đặt thuật toán Boyer Moore Horspool (BMH) trả về vị tri xuất hiện đầu tiên của xâu P trong xâu T.
- Sử dụng thuật toán BMH cho biết trong danh sách d có bao nhiêu giáo trình thuộc về các học phần dình
cho việc học “lập trình", hiển thị thông tin đầy đủ của những giảo trình đó (nu có).
*/



#include<bits/stdc++.h>

using namespace std ; 


struct GiaoTrinh{
	
	char tenGiaoTrinh[50];
	char tenTacGia[50];
	int giaBia ; 
	int dungTich ; 
	
};



void xuatTieuDe(){
	
	cout<<setw(10)<<"STT"<<
	setw(30)<<"Ten Giao Trinh"<<
	setw(20)<<"Ten Tac Gia"<<
	setw(20)<<"Gia Ban"<<
	setw(20)<<"Dung tich"<<endl ;
	
}


void xuatDanhSach(GiaoTrinh ds[], int n ){
	
	cout<<setw(70)<<"----Danh sach sau khi sap xep theo gia tang---"<<endl ;
	
	int soThuTu = 0 ; 
	xuatTieuDe();
	
	for(int i = 0 ; i < n ; i ++ ){
		cout<<setw(10)<<soThuTu<<setw(30)<<
		ds[i].tenGiaoTrinh <<setw(20)<<
		ds[i].tenTacGia <<setw(20)
		<< ds[i].giaBia <<setw(20)
		<< ds[i].dungTich<<endl; 
		soThuTu++; 
	}
	
	cout<<endl ; 
}




void sapXepTangDan(GiaoTrinh ds[] , int n ){
	
	for(int i = 0 ; i < n - 1 ; i ++ ){
		for(int j = n -1 ; j > i ; j -- ){
			if(ds[j].giaBia <ds[j - 1 ].giaBia ){
				swap(ds[j] ,ds[j - 1] );
			}
		}
	}
}


void thuatToanA(GiaoTrinh ds[] , int n , int p ,GiaoTrinh ketQua[] , int& soLuongChon ){
	
	sapXepTangDan(ds , n );
	
	float tongTien = 0 ; 
	 
	for(int i = 0 ; i < n ; i ++ ){
		if(tongTien + ds[i].giaBia <= p ){
			ketQua[soLuongChon++] = ds[i];
			tongTien += ds[i].giaBia ; 
		}
	}
	
	if(soLuongChon == 0 ){
		cout<<"+ khong the mua duoc bat ki giao trinh nao voi so tien: "<<p << " VND\n";
		return ;
	}
	
	cout<<"+ So tien hien co la: "<<p<<" VND\n"; 
	
	cout<<"+ Tong tien mua la: "<<tongTien<<" VND\n";
	
	cout<<"+ So tien con lai la: "<<p - tongTien << " VND\n"; 
	
	cout<<"+ So luong giao trinh co the mua la: "<<soLuongChon<<" giao trinh\n";
	
	cout<<setw(70)<<"----Danh sach giao trinh co the mua----\n";
	

	
}



int BMH( char T[],  char P[]) {
	
    int n = strlen(T);
    int m = strlen(P);
    
    if (m > n){
	  return -1;
    }

    int skip[256];
    
    for (int i = 0; i < 256; i++) {
	     skip[i] = m;
    }
    
    for (int i = 0; i < m - 1; i++){
        skip[(unsigned char)P[i]] = m - i - 1;
    }
    
    int i = 0;
    while (i <= n - m) {
    	
        int j = m - 1;
        while (j >= 0 && P[j] == T[i + j]){
		    j--;
	    }
	    
        if (j < 0) {
		  return i;
	    }
	    
        i += skip[(unsigned char)T[i + m - 1]];
    }
    return -1;
}



void timGiaoTrinhLapTrinh(GiaoTrinh ds[], int n, GiaoTrinh ketQua[], int& soLuong) {
     char keyword[] = "Ngon ngu";
    soLuong = 0;
    for (int i = 0; i < n; i++) {
        if (BMH(ds[i].tenGiaoTrinh, keyword) != -1){
            ketQua[soLuong++] = ds[i];
        }
    }
}


int dp[100][100]; // dp[i][j]: max giá trị với j lít và i can đầu tiên

void thuatToanB(GiaoTrinh d[], int n, int s) {
	
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
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - d[i-1].dungTich] +  d[i-1].giaBia);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
     
    cout<<endl ;
    cout<<"+ Voi dung tich la: "<<s << endl ; 
    cout << "+ Tong gia tri lon nhat co the mua la: " << dp[n][s] << " VND\n";

    // Truy vết
    int i = n, j = s;
    GiaoTrinh ketQua[100];
    int soLuong = 0;

    while (i > 0 && j > 0) {
        if (dp[i][j] != dp[i-1][j]) {
            ketQua[soLuong++] = d[i-1];
            j -= d[i-1].dungTich;
        }
        i--;
    }

    cout << "+ So luong can ruou: " << soLuong << endl;
    cout << setw(70)<<"----------Danh sach mua duoc la----------\n";
    int soThuTu = 0 ;
    xuatTieuDe();
    for (int k =0 ; k < soLuong ; k ++ ){
		cout<<setw(10)<<soThuTu<<setw(30)<<
		ketQua[k].tenGiaoTrinh<<setw(20)<<
		ketQua[k].tenTacGia<<setw(20)<<
		ketQua[k].giaBia<<setw(20)<<
		ketQua[k].dungTich<<endl ;
		soThuTu++ ;
	}
}




int main(){
	
	int n = 5  , p = 20000 , s = 100 ; 
	
	GiaoTrinh ds[n]= {
		
	{"Ngon ngu lap trinh python" , "Bill Gate" , 5000 , 10 },
	{"Ngon ngu lap trinh c++" , "Antony" , 3000  , 30},
	{"lich su dang Viet Nam" , "Giang Vien Haui" , 35000 , 24 },
	{"lap trinh co so du lieu" , "Jane Travis" , 10000 , 30 },
	{"Ung dung thuat toan" , "GV An Van Minh" , 7000  , 45}	
	
	};
	
	
	sapXepTangDan(ds , n );
	
	xuatDanhSach(ds, n );
	
	GiaoTrinh ketQua[100]; 
	int soLuongChon;
	
	thuatToanA(ds, n , p, ketQua , soLuongChon);
     
    int soThuTu= 0 ;
	for(int i = 0 ; i < soLuongChon ; i ++ ){
		cout<<setw(10)<<soThuTu<<setw(30)<<
		ketQua[i].tenGiaoTrinh <<setw(20)<<
		ketQua[i].tenTacGia <<setw(20)
		<< ketQua[i].giaBia<<endl;
		soThuTu++; 
	}
	
	cout<<endl ; 
	
    char T[] = "Ngon ngu lap trinh C++";
    char P[] = "lap trinh";

    int pos = BMH(T, P);
    
    if (pos != -1){
        cout << "+ Tim thay tai vi tri: " << pos << endl;
    }
    
    else{
        cout << "+ Khong tim thay xau." << endl;
    }


    GiaoTrinh ketQuaTim[100];
    int soLuongTim;
    timGiaoTrinhLapTrinh(ds, n, ketQuaTim, soLuongTim);

    cout << "+ So giao trinh chua 'lap trinh': " << soLuongTim << "\n";
    for (int i = 0; i < soLuongTim; i++){
    	cout<<ketQuaTim[i].tenTacGia <<setw(30)<<ketQuaTim[i].tenGiaoTrinh<<endl;
	}
        
        
    thuatToanB(ds, n , s);    
	
}