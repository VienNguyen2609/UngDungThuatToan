#include<bits/stdc++.h>
using namespace std ;
 
struct HocSinh{
	string hoTen ;
	double diemTK; 
	string loaiDaoDuc;
	double tienThuong; 
};

vector<HocSinh> KhoiTaoDanhSach(){
	
	vector<HocSinh> danhSach = {
	    {"vienQ", 10 , "Gioi",700} ,
	    {"vienA", 6 , "Gioi",100} ,
	    {"vienB", 7 , "Gioi",200} ,
	    {"vienC", 10 , "Gioi",300} ,
	    {"vienD", 7 , "Gioi",400},
	    {"vienE", 8 , "Gioi",500},
	    {"vienF", 9 , "Gioi",600},
	    {"vienG", 9 , "Gioi",600}
	};
	return danhSach;
}


double TinhTongTienThuong( const vector<HocSinh>& danhSach , int i ){
	
	if(i < 0 ){
		return 0 ; 
	}
	return danhSach[i].tienThuong + TinhTongTienThuong(danhSach , i - 1 ) ; 
}


int demHocSinhDiem7 (const vector<HocSinh>& danhSach , int left , int right ){
	
	if(left > right ) return 0 ; 
	
	if(left == right ){
		if(danhSach[left].diemTK >= 7 ){
			return 1 ; 
		}
		else{
			return 0 ;
		}
	}
	
	int mid=(left + right) / 2 ; 
	return demHocSinhDiem7(danhSach ,left ,mid ) + demHocSinhDiem7(danhSach ,mid +1  ,right );
		
}


void lietKePhuongAn(const vector<HocSinh>& danhSach  , vector<int>& phuongAn ,int batDau , int soHocSinh , int &dem  ){
	
	if(phuongAn.size() == soHocSinh ){
		 dem++;
		int n = 0 ; 
		cout<<"Phuong an: "<< dem <<endl ;
		cout<<"STT" <<setw(20)  <<"HoVaTen"<<setw(20) << "DiemSo" <<setw(20)  << "LoaiDaoDuc" <<setw(20) << "TienThuong" <<endl;
		for(int xds : phuongAn ){
			cout<<n <<setw(20)<< danhSach[xds].hoTen <<setw(20)<< danhSach[xds].diemTK<<setw(20)
			<<danhSach[xds].loaiDaoDuc<<setw(20)<<danhSach[xds].tienThuong << endl;
			n++; 
		}
		cout << endl ; 
		return; 
	}
	
    for(int i = batDau; i < danhSach.size(); ++i) {
        phuongAn.push_back(i);
        lietKePhuongAn(danhSach, phuongAn, i + 1, soHocSinh , dem);
        phuongAn.pop_back();
    }
    
}
 
int main(){
	
  vector<HocSinh> danhSach = KhoiTaoDanhSach() ; 
  
  cout << "Tong tien thuong hoc sinh: "<<TinhTongTienThuong(danhSach , danhSach.size() -1 ) << endl; 
  
  cout << "So hoc sinh diem tu 7 tro len : " <<demHocSinhDiem7(danhSach , 0 ,danhSach.size() -1 )<< endl; 
  
  vector<int> phuongAn;
  cout << "Cac phuong an lay 6 hoc sinh:" << endl;
  cout<<endl; 
  
  int dem = 0 ; 
  lietKePhuongAn(danhSach, phuongAn, 0,6, dem  );
  
  cout<<"tong co: "<<dem << " phuong an chon 6 hoc sinh "<< endl ;
  
}

