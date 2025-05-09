#include<bits/stdc++.h>
using namespace std ; 


struct HocSinh{
	
   string ten; 
   double diem; 
   int tienThuong; 
   	
};

const int MAX =100 ; 

int kichThuocDS = 6 ; 
HocSinh dSHocSinh[MAX]={
 {"NguyenBaVien" , 8.5 , 1000},
 {"NguyenVanTuan" , 8.5 , 20000},
 {"BuiThiHanh" , 8.5 , 1000},
 {"QuangThuan" , 8.5 , 1000},
 {"KieuMinhHieu" , 8 , 1000},
 {"TaVanTien" , 8.5 , 1000}
};


int tongTien(HocSinh dSHocSinh[] , int chiSo){
	
	if(chiSo >= kichThuocDS ){
		return 0 ;
	}
	
	else{
		return dSHocSinh[chiSo].tienThuong + tongTien(dSHocSinh , chiSo +1 ); 
	}
}


int demHS(HocSinh dSHocSinh[] , int trai , int phai ){
	if(trai >phai  ){
		return 0 ;
	}
	
	if(trai == phai ){
		if(dSHocSinh[trai].diem >= 8.5){
			return 1 ; 
		}
		else{
			return 0 ; 
		}
	}
	int giua = (trai + phai ) / 2 ; 
	return demHS(dSHocSinh , trai , giua ) + demHS(dSHocSinh , giua +1  , phai ) ; 
}



void xuatTieuDe(){
	cout<<setw(10)<<"STT"<<
	setw(20)<<"Ten"<<
	setw(20)<<"Diem"<<
	setw(20)<<"Tien thuong"<<endl ; 
}


void xuatDanhSach(HocSinh dSHocSinh[] , int chiSo, int soThuTu){
	
	if(chiSo >= kichThuocDS){
		return ; 
	}
	else{
		cout<<setw(10)<<soThuTu <<
		setw(20)<<dSHocSinh[chiSo].ten <<
		setw(20)<<dSHocSinh[chiSo].diem <<
		setw(20)<<dSHocSinh[chiSo].tienThuong <<endl;
		xuatDanhSach(dSHocSinh , chiSo +1 , soThuTu + 1 ); 
	}
}

int viTri[MAX]; 
bool danhDau[MAX]; 
int soPhuongAn = 0 ; 


void xuatPhuongAn(){
	
	for(int i = 0 ; i < kichThuocDS ; i ++ ){
		cout<<"Vi tri: "<< i + 1 << "-------"<< dSHocSinh[viTri[i]].ten<<endl ; 
	}
	cout<<endl ; 
}

void xepHocSinh(int soGhe){
	
	if(soGhe == kichThuocDS){
		cout<<"phuong an thu: "<<soPhuongAn + 1 << endl ; 
		xuatPhuongAn(); 
		soPhuongAn++; 
		return ;
	}
	
	else{
		for(int i = 0 ; i < kichThuocDS ; i ++ ){
			if(!danhDau[i]){
				danhDau[i] = true ; 
				viTri[soGhe] = i ; 
				xepHocSinh(soGhe + 1 ); 
				danhDau[i] = false ; 
			}
		}
	}
}


void Try(int soGhe){
	for(int i = 0 ; i < kichThuocDS ; i ++ ){
		
		if(!danhDau[i]){
			viTri[soGhe]= i ; 
			danhDau[i] = true ; 
		
		if(soGhe == 3  ){
			cout<<"phuong an thu: "<<soPhuongAn + 1 << endl ; 
		   	xuatPhuongAn(); 
		   	soPhuongAn ++ ; 
		}
		else {
			Try(soGhe + 1 ); 	
		}
		danhDau[i] = false ; 
    	}
	}
}

void xuatPhuongAn(HocSinh toHop[] , int chiSo ){
	
	for(int i = 0 ; i < chiSo ; i ++ ){
		cout<< toHop[i].ten<<endl ; 
	}
	cout<<endl ; 
}


void xep(HocSinh dSHocSinh[] , int kichThuocDS , int batDau ,HocSinh toHop[] , int soHocSinh , int chiSo ){
	
	if(chiSo == soHocSinh ){
		cout<<"phuong an thu: "<<soPhuongAn + 1 << endl ; 
		xuatPhuongAn(toHop , soHocSinh ); 
		soPhuongAn++; 
		return ; 
	}
	
	else{
		for(int i = batDau ; i <=  kichThuocDS - (soHocSinh -chiSo  ) ; i++ ){
			toHop[chiSo]=dSHocSinh[i];
			xep(dSHocSinh , kichThuocDS ,  i +1 ,toHop , soHocSinh ,chiSo +1   );
		}
	}
}

int soHocSinhChon = 4 ;
//void xuatPhuongAn(){
//	
//	for(int i =0 ; i <  soHocSinhChon ; i ++ ){
//		HocSinh hs = dSHocSinh[viTri[i]] ; 
//		 cout << setw(20) << hs.ten << setw(10) << hs.diem << setw(15) << hs.tienThuong<< "\n";
//	}
//	cout<<endl ; 
//	
//}


void Try(int viTriDangChon , int batDau){
	for(int i = batDau ; i < kichThuocDS ; i ++ ){
		if(!danhDau[i]){
			viTri[viTriDangChon] = i ; 
			danhDau[i] = true ;
			
			if(viTriDangChon ==soHocSinhChon    ){
				cout<<"phuong an thu: "<<soPhuongAn + 1 << endl ; 
				xuatPhuongAn();
				soPhuongAn++; 
			}
			else{
			    Try(viTriDangChon + 1 , i+1 );	
			}
			    danhDau[i] = false ;
		}
	}
}




int main(){

   cout<<"+ Tong tien tat ca hoc sinh la: " << tongTien(dSHocSinh , 0 )<<" VND"<<endl; 
   cout<<endl ; 
   cout<<"+ so hoc sinh  diem >=  8.5 la: " << demHS(dSHocSinh , 0  , kichThuocDS -1 )<<" Hoc sinh"<<endl; 
   cout<<endl ; 
   
   cout<<setw(60)<<"---------Danh Sach Hoc Sinh-------------"<<endl ;
   xuatTieuDe(); 
   xuatDanhSach(dSHocSinh ,  0,  0 );
 	
   cout<<"So phuong an chon ra 6 hoc sinh vao 6 ghe:"<<endl ;
//   HocSinh toHop[MAX] ; 
//   xep(dSHocSinh , kichThuocDS , 0 , toHop , 6 , 0); 
   Try(0 ); 
   cout <<"Tong so phuong an la: "<<soPhuongAn<<" Phuong An"<<endl; 
}