#include<bits/stdc++.h>
using namespace std ; 

struct CauThu{
	
   string hoVaTen; 
   int namSinh ; 
   double luongThang; 
   int namBatDauThiDau ; 
   
};


vector<CauThu> KhoiTaoDanhSach(){
	vector<CauThu> danhSachCauThu = {
	{"Vien1" , 2005 , 150000 , 0} , 
	{"Vien2" , 2005 , 150000 , 0} , 
	{"Vien3" , 2005 , 150000 , 2020} , 
	{"Vien4" , 2005 , 150000 , 2020} , 
	{"Vien5" , 2005 , 150000 , 2020} , 
	{"Vien6" , 2005 , 150000 , 2020} , 
	{"Vien7" , 2005 , 150000 , 2020} 		
 };
 return danhSachCauThu ; 
}


void xuatTieuDe(){
	cout<<"STT"<<setw(20)<< "HoVaTen" << setw(20)<<"NamSinh" << setw(20)<<"LuongThang" << setw(23)
	   <<"NamBatDauThiDau" <<endl;
}


void xuatDanhSachCauThu(const vector<CauThu>& danhSachCauThu , int kichThuoc , int soThuTu = 0 ){
	
	if(kichThuoc > danhSachCauThu.size()  -1  ){
		return ;
	}
	
	else{
     	cout<<soThuTu<<setw(20)<<danhSachCauThu[kichThuoc].hoVaTen <<setw(20) <<danhSachCauThu[kichThuoc].namSinh <<setw(20) <<
	    danhSachCauThu[kichThuoc].luongThang <<setw(20)<<danhSachCauThu[kichThuoc].namBatDauThiDau <<   endl;
	   	xuatDanhSachCauThu(danhSachCauThu ,kichThuoc+1 , soThuTu + 1  ) ;
	}
}



int demCauThuChuaThiDau(const vector<CauThu>& danhSachCauThu , int kichThuoc) {
	
	if(kichThuoc >= danhSachCauThu.size() ){
		return 0 ; 
	}
	
	return (danhSachCauThu[kichThuoc].namBatDauThiDau == 0 ) + demCauThuChuaThiDau(danhSachCauThu ,kichThuoc + 1  );
}


void Run(){
	
	 vector<CauThu> danhSachCauThu = KhoiTaoDanhSach() ; 
	 
     xuatTieuDe();
     
     xuatDanhSachCauThu(danhSachCauThu , 0 , 0  ); 
     
     cout<< endl ;
     
     cout<<"So cau thu chua thi dau chuyen nghiep: "<< demCauThuChuaThiDau(danhSachCauThu , 0);
    
}



int main (){
    
    Run(); 
    
}