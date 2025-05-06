#include<bits/stdc++.h>
using namespace std ; 

const int MAX = 100; 

struct CauThu {
	string ten ; 
	int namSinh; 
	double luongThang ; 
	int namBatDauThiDau; 
};


void xuatThongTinCauThu(CauThu danhSachCauThu[]  ,  int chiSo ,  int kichThuocCuaDanhSach){
	
	if( chiSo >= kichThuocCuaDanhSach ){
		return ; 
	}
	
	else{
		cout<<danhSachCauThu[chiSo].ten << endl; 
		xuatThongTinCauThu(danhSachCauThu ,chiSo + 1  ,  kichThuocCuaDanhSach  );
	}
	
}


int soCauThuChuaThiDau(CauThu danhSachCauThu[] ,  int chiSo, int kichThuocCuaDanhSach ){

	if( chiSo >= kichThuocCuaDanhSach ){
		return 0; 
	}
	
	else{	 
		return (danhSachCauThu[chiSo].namBatDauThiDau  ==0 ) + soCauThuChuaThiDau(danhSachCauThu, chiSo + 1 , kichThuocCuaDanhSach );
    } 
}


void hoanVi(CauThu danhSachCauThu[],  int kichThuocCuaDanhSach ,  int viTriHienTai) {
    
	if (viTriHienTai == kichThuocCuaDanhSach ) {
        for (int i = 0; i < kichThuocCuaDanhSach; i++) {
            cout << "Vi tri " << i + 1 << ": " << danhSachCauThu[i].ten << endl;
        }
        cout << "--------------------------\n";
        return;
    }
    
    for (int i = viTriHienTai; i < kichThuocCuaDanhSach; i++) {
        swap(danhSachCauThu[viTriHienTai], danhSachCauThu[i]);
        hoanVi(danhSachCauThu, kichThuocCuaDanhSach, viTriHienTai + 1);
        swap(danhSachCauThu[viTriHienTai], danhSachCauThu[i]); // backtrack
    }
}

int main(){
	
	CauThu danhSachCauThu[MAX] = {
		{"Messi" , 1990 , 2000000, 0	}, 
		{"Ronaldo" , 1990 , 30000, 0	},
		{"Neymar" , 1987 , 250000, 2004	},
		{"Vini" , 2002 , 10000000, 2006	},
		{"Kevin" , 1995 , 2000000, 2005	},
		{"Dembele" , 2000 , 2000000, 2010}		
	};

	
	xuatThongTinCauThu(danhSachCauThu , 0 , 7 ); 
	
	cout<<soCauThuChuaThiDau(danhSachCauThu, 0 , 7  )<<endl;
	
	hoanVi(danhSachCauThu , 3 , 0 ); 
}