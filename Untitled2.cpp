#include<bits/stdc++.h>
using namespace std ; 

const int MAX = 100; 

struct HS {
	string hoTen ;
	double diemTK; 
	string loaiDaoDuc;
	double tienThuong; 
};


double tongTienThuong(HS danhSachCauThu[] , int chiSo ,int kichThuocDanhSach){

	if(chiSo > kichThuocDanhSach){
		return 0 ; 
	}
	else{
		return danhSachCauThu[chiSo].tienThuong + tongTienThuong(danhSachCauThu , chiSo + 1 ,kichThuocDanhSach );
	}
}

int soHocSinhTrenTu7Diem(HS danhSachCauThu[] , int benTrai ,int benPhai){
  
   if(benTrai > benPhai ){
  	return 0 ;
   }
   
   if(benTrai ==benPhai  ){
   	
   	  if(danhSachCauThu[benTrai].diemTK >= 7  ){
   	  	return 1 ;
	   }
	  else{
		return 0 ;
		 }
   } 
   int giua= (benTrai + benPhai) / 2 ; 
   return soHocSinhTrenTu7Diem(danhSachCauThu ,benTrai , giua ) +soHocSinhTrenTu7Diem(danhSachCauThu ,giua +1  , benPhai );  
}

void toHop6HocSinh(HS d[], int n, int k, int start, int index, HS toHop[], int &dem) {
    if (index == k) {
        dem++;
        cout << "Phuong an " << dem << ":\n";
        for (int i = 0; i < k; i++) {
            cout << "- " << toHop[i].hoTen << " | Dao duc: " << toHop[i].loaiDaoDuc << endl;
        }
        cout << "--------------------------\n";
        return;
    }

    for (int i = start; i <= n - (k - index); i++) {
        toHop[index] = d[i];
        toHop6HocSinh(d, n, k, i + 1, index + 1, toHop, dem);
    }
}

int main(){
	
		HS danhSachCauThu[MAX] = {
		{"Messi" , 6 , "Gioi", 1	}, 
		{"Ronaldo" , 1990 , "Gioi", 1	},
		{"Neymar" , 1987 , "Gioi", 2004	},
		{"Vini" , 2002 , "Gioi", 2006.232	},
		{"Kevin" , 1995 , "Gioi", 2005	},
		{"Dembele" , 2000 , "Gioi", 2010}		
	};
	
    HS toHop[6];
    int dem = 0;
    
    cout<<"tong tien: "<< tongTienThuong(danhSachCauThu , 0 , 6 )<<endl;
    
    toHop6HocSinh(danhSachCauThu, 6, 6, 0, 0, toHop, dem);
    
    cout<<" diem 7 > : "<< soHocSinhTrenTu7Diem(danhSachCauThu , 0 , 6 )<<endl;
}