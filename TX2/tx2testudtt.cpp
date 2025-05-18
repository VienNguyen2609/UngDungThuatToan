#include<bits/stdc++.h>

using namespace std; 


struct GiaoTrinh{
	
	char tenGiaoTrinh[50] ; 
	int gia ; 
	int dungTich ; 
	
};



void xuatTieuDe(){
	
	cout<<setw(10)<<"STT"<<setw(30)<<"Ten giao trinh"
	<<setw(30)<<"Gia ban"
    <<setw(30)<<"Dung tich"<<endl;
	
}


void sapXep(GiaoTrinh ds[] , int n ){
	
	for(int i = 0 ; i < n -1 ; i ++ ){ 
	    for(int j = n -1 ; j > i ; j -- ){
	    	if(ds[j].gia < ds[j-1].gia){
	    		swap(ds[j], ds[j-1]);
			}
		}
	}
	
}



void muaTheoP(GiaoTrinh ds[] , int n , int p , int& tongTien , GiaoTrinh ketQua[] , int& soLuong){
	
	sapXep(ds, n); 
	
	for(int i = 0 ; i < n ; i ++ ){
		if(tongTien + ds[i].gia <= p ){
			ketQua[soLuong++] = ds[i] ; 
			tongTien += ds[i].gia; 
		}
	}
	
	if(soLuong == 0 ){
		cout<<"khong the mua\n"; 
		return ;
	}
	
}


//void muaTheoDungTich(GiaoTrinh ds[] , int n  , int s , int& tongDungTich , int dp[100][100] , GiaoTrinh ketQua[] , int& soLuong){
//	
//	for(int i = 0; i <= n ; i ++ ){
//		for(int j = 0 ; j <=s ; j ++ ){
//			dp[i][j] = 0 ;
//		}
//	}
//	
//	for(int i = 1; i <= n ; i ++ ){
//		for(int j = 0 ; j <=s ; j ++ ){
//			
//			if(ds[i-1].dungTich <= j ){
//				dp[i][j] = max(dp[i-1][j] , dp[i-1][j-ds[i-1].dungTich] + ds[i-1].gia);
//			}
//			else{
//				dp[i][j] = dp[i-1][j];
//			}
//		}
//	}
//	
//	int i = n , j = s ; 
//	while(i > 0 && j > 0 ){
//		if(dp[i][j] != dp[i-1][j]){
//			ketQua[soLuong++]= ds[i-1]; 
//			tongDungTich += ds[i-1].dungTich ; 
//			j -= ds[i-1].dungTich;
//		}
//		i-- ; 
//	}
//}
//
//
//int viTriKyTuTrongXau(char p , char t[]){
//	
//	int len = strlen(t);
//	for(int i = len -2 ; i>= 0 ; i--){
//		if(t[i] == p){
//			return i ;
//		}
//	}
//	return -1 ;
//}
//
//
//int timViTriXuatHienBMH(char p[] , char t[]){
//	
//	int v = strlen(p) ; 
//	int i = v -1 ; 
//	while( i < strlen(t)){
//		
//		int k = v -1 ; 
//		
//		while( k > -1 && t[i] == p[k]){
//			i--;
//			k--;
//		}
//		
//		if(k < 0 ){
//			return i +1 ;
//		}
//		
//		int x = viTriKyTuTrongXau(t[i] , p);
//		
//		if(x< 0 ){
//			i += v ; 
//		}
//		else{
//			i += v- x - 1 ;
//		}
//	}
//	return -1;
//}


void muaTheoDungTich(GiaoTrinh ds[], int n , int s ,int& tongDungTich , int dp[100][100] , GiaoTrinh ketQua[] , int& soLuongKetQua){
	
	for(int i = 0; i <=n ; i++){
		for(int j = 0 ; j<=s ; j ++ ){
			dp[i][j] = 0 ;
		}
	}
	
	for(int i = 1; i <=n ; i++){
		for(int j = 0 ; j<=s ; j ++ ){
			
			if(ds[i-1].dungTich <= j ){
				dp[i][j] = max(dp[i-1][j] , dp[i-1][j - ds[i-1].dungTich] + ds[i-1].gia);
			}
			
			else {
				dp[i][j] = dp[i-1][j];	
			}
		}
	}
	
	int i = n , j =s ; 
	while(i > 0 && j > 0 ){
		if(dp[i][j] != dp[i-1][j]){
			ketQua[soLuongKetQua++] = ds[i-1];
			tongDungTich += ds[i-1].dungTich;
			j -= ds[i-1].dungTich;
    	}
    	i--;
    }
}


int viTriKyTuTrongXau(char p , char t[]){
	
	int n = strlen(t);
	for(int i = n -2 ; i >= 0 ; i --  ){
		if(t[i] == p){
			return i;
		}
	}
	return -1 ;
}


int timViTriXuatHien_BMH(char p[] , char t[]){
	
	int v =strlen(p);
	int i = v -1 ; 
	while(i < strlen(t)){
		int k = v -1 ; 
		while( k > -1 && t[i] == p[k] ){
			i-- ; 
			k--;
		}
		if(k < 0 ){
			return i + 1 ;
		}
		int x = viTriKyTuTrongXau(t[i] , p);
		if(x < 0  ){
			i += v; 
		}
		else{
			i += v- x - 1 ;
		}
	}
	return -1;
}



int main(){
	
	int n = 5 , p = 100000 , s = 100 ; 
	
	GiaoTrinh ds[n]={
	
	{"lap trinh c++" , 10000 , 25 },
	{"lap trinh Java" , 14000 , 12 },
	{"lap trinh python" , 7000 , 2 },
	{"Ung dung thuat toan" , 50000 , 60 },
	{"Ngon ngu lap trinh co ban" , 33000 , 20 }
	
	};
	
	GiaoTrinh ketQua[100]; 
	int soLuong = 0 , tongTien = 0  ; 
	
	muaTheoP(ds, n , p , tongTien , ketQua , soLuong); 
	
	cout<<"+ Voi so tien "<<p<<" VND\n"; 
	cout<<"+ Co the mua duoc "<<soLuong <<" giao trinh\n"; 
	cout<<"+ Tong tien mua la: "<<tongTien<< " VND\n";
	cout<<"+ So tien con lai la: "<<p - tongTien << "VND\n"; 
	
	cout<<setw(80)<<"-----------------Danh Sach mua duoc---------------\n ";
	xuatTieuDe();
	for(int i = 0 ;i < soLuong ; i ++ ){
		cout<<setw(10)<<i 
		<<setw(30)<<ketQua[i].tenGiaoTrinh
		<<setw(30)<<ketQua[i].gia
		<<setw(30)<<ketQua[i].dungTich<<endl ;
	}
	
	GiaoTrinh ketQuaMua[100] ; 
	int soLuongMua = 0 ,tongDungTich = 0 ; 
	int dp[100][100]; 
	
	muaTheoDungTich(ds, n , s , tongDungTich,  dp, ketQuaMua , soLuongMua); 
	
	cout<<"+ Voi dung tich "<<s<<" co the mua duoc tong so tien la: "<<dp[n][s]<<endl ; 
	cout<<"+ Tong dung tich mua la: "<<tongDungTich<<endl ; 
	cout<<"+So Giao trinh co the mua la: "<<soLuongMua<<" Giao trinh\n";
	
	cout<<setw(80)<<"-----------------Danh Sach mua duoc-----------------\n ";
    xuatTieuDe();
	for(int i = 0 ;i < soLuongMua ; i ++ ){
		cout<<setw(10)<<i 
		<<setw(30)<<ketQuaMua[i].tenGiaoTrinh
		<<setw(30)<<ketQuaMua[i].gia
		<<setw(30)<<ketQuaMua[i].dungTich<<endl ;
	}
	
	
	char P[] = "lap trinh" ; 
	char T[] = "Ngon ngu lap trinh C++";
	
	int index =  timViTriXuatHien_BMH(P , T);
	cout<<"vi tri dau tien xuat hien cuoi p("<<P<< ") trong xau t("<<T<<") la: "<<index <<endl ; 
	
	cout<<setw(90)<<"-----------------Danh Sach cho hoc lap trinh------------------\n ";
	xuatTieuDe();
	for(int i = 0 ; i < n ; i ++ ){
		if(timViTriXuatHien_BMH(P, ds[i].tenGiaoTrinh )  != -1 ){
		   cout<<setw(10)<<i 
		   <<setw(30)<<ds[i].tenGiaoTrinh
	       <<setw(30)<<ds[i].gia
		   <<setw(30)<<ds[i].dungTich<<endl ;
		}
	}

}