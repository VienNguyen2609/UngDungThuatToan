#include<bits/stdc++.h>
using namespace std ;



/*
1 . Cho một danh sách d gồm n học sinh của một lớp học, thông tin về mỗi học sinh gồm họ và tên, điểm
tổng kết, xếp loại đạo đức, tiền được thưởng cuối năm học.
Viết một chương trình thực hiện (chương trình được viết bằng ngôn ngữ C/C++)
- Khai báo cấu trúc dữ liệu cho danh sách d. Khởi tạo n và khởi tạo danh sách d gồm n học sinh (dữ liệu
có tính thực tiễn, không nhập từ bàn phím, n ≥ 7).
- Cài đặt hàm biểu diễn thuật toán đệ quy A4 để tính và trả về tổng số tiền thưởng của tất cả học sinh
trong d. Ứng dụng A4.
- Cài đặt các hàm biểu diễn thuật toán chia để trị A5 để tính và trả về số học sinh trong d có điểm tổng
kết từ 7.0 trở lên và hàm biểu diễn thuật toán quay lui A6 cho biết có bao nhiêu phương án để lấy ra 6
học sinh từ danh sách d, hiển thị các phương án đó, thông tin mỗi học sinh hiển thị gồm họ tên, xếp loại
đạo đức. Ứng dụng A5 và A6.
không dùng vector để lưu danh sách bài trên.

2. Cho một danh sách d gồm n cầu thủ bóng đá của của một câu lạc bộ, thông tin về mỗi cầu thủ gồm họ
và tên cầu thủ, năm sinh, lương tháng, năm bắt đầu thi đấu chuyên nghiệp.
Viết một chương trình thực hiện (chương trình được viết bằng ngôn ngữ C/C++)
- Khai báo cấu trúc dữ liệu của danh sách d. Khởi tạo n và khởi tạo danh sách d gồm n cầu thủ (dữ liệu
khởi tạo có tính thực tiễn, không nhập từ bàn phím, n ≥ 7).
- Cài đặt hàm biểu điễn thuật toán đệ quy A1 hiển thị ra màn hình thông tin đầy đủ của tất cả các cầu thủ
trong d (danh sách theo mẫu có dòng tiêu đề, thông tin mỗi cầu thủ trên 1 tương ứng). Ứng dụng A1.
- Cài đặt các hàm biểu diễn thuật toán chia để trị A2 để đếm và trả về số lượng cầu thủ chưa thi đấu
chuyên nghiệp trong d và hàm biểu diễn thuật toán quay lui A3 để cho biết có tất cả bao nhiêu phươngg
án khác nhau để xếp n cầu thủ trong d tạo thành một đội bóng gồm n vị trí thi đấu được đánh số thứ tự
từ 1 đến n, hiển thị các phương án đó (mỗi phương án hiển thị họ và tên cầu thủ và vị trí thi đấu). Ứng
dụng A2 và A3.
không dùng vector để lưu danh sách.? */

int kichThuocDanhSach = 8 ;
const int MAX = 100 ; 


struct HocSinh {
	
  string hoVaTen ; 
  double diem;
  string loaiDaoDuc ; 
  double tienThuong; 
  	
};

    HocSinh danhSachHocSinh[MAX] = {
	     {"NguyenBaVien" , 9.5 , "Gioi", 10000}, 
         {"NguyenThiNu" , 5 , "Trung Binh", 500}, 
		 {"NguyenVanTung" , 8.5 , "Gioi", 9000}, 
		 {"BuiNgocTuan" , 4.5 , "Yeu", 0}, 
		 {"KieuMinhHieu" , 10 , "Xuat Sac", 15000}, 
		 {"TaVanTien" , 9 , "Gioi", 10000}, 
		 {"TranQuocTrung" , 3 , "Yeu", 0}, 
		 {"NguyenVanTuan" ,8 , "Gioi", 5000}		
	};

double tongTienThuong(HocSinh danhSachHocSinh[] , int kichThuocDanhSach , int chiSo){
	
	if( chiSo > kichThuocDanhSach ) {
		return 0 ;
	}
	
	else{
		return danhSachHocSinh[chiSo].tienThuong + tongTienThuong(danhSachHocSinh, kichThuocDanhSach ,chiSo + 1 ) ;
	}
}
 
 
 
int demSoHocSinhTren7(HocSinh danhSachHocSinh[]  ,  int trai , int phai ){
	
	if(trai > phai ){
		return 0 ; 
	}
	
	if(trai == phai ){
		
		if(danhSachHocSinh[trai].diem >= 7 ){
			return 1 ; 
		}
		else{
			return 0 ;
		}
	}
		int giua = (trai + phai ) / 2 ; 
		
		return demSoHocSinhTren7(danhSachHocSinh  , trai , giua ) + demSoHocSinhTren7(danhSachHocSinh  , giua +1  , phai ); 
		
}



void xuatTieuDe(){
	
	cout <<setw(10) <<"STT"<<setw(25) <<"HoVaTen"  << setw(15)<<  "Diem So" << setw(20) << "Dao Duc" << setw(22) 
	 << "Tien Thuong " <<endl ;	
}



void xuatToHopChon6HocSinh( HocSinh toHopKetQua[] , int kichThuocToHop){
	 
	 xuatTieuDe(); 
     for(int i = 0 ; i <kichThuocToHop ; i++  ){
     	cout<<setw(10) <<i<<  setw(25)<< toHopKetQua[i].hoVaTen<<setw(15)<<toHopKetQua[i].diem<<setw(20)<<
     	toHopKetQua[i].loaiDaoDuc<<setw(20)<<toHopKetQua[i].tienThuong<<endl;
	 }
	 cout<< endl; 
}


int phuongAnChon6HocSinh = 0 ; 
void chonToHop6HocSinh(HocSinh danhSachHocSinh[] , int kichThuocDanhSach , int batDau , HocSinh toHopKetQua[] , int soHocSinh, int chiSo){
	
	if(chiSo == soHocSinh){	
	    cout<<"Phuong an thu:" << phuongAnChon6HocSinh + 1 << endl ; 
		xuatToHopChon6HocSinh(toHopKetQua , soHocSinh) ; 
		phuongAnChon6HocSinh++ ;
		return ; 		
	}
	
	for(int i = batDau ; i <= kichThuocDanhSach -(soHocSinh - chiSo ) ; i++ ){
		toHopKetQua[chiSo] = danhSachHocSinh[i]; 
	chonToHop6HocSinh(danhSachHocSinh ,kichThuocDanhSach , i+1 ,  toHopKetQua ,soHocSinh , chiSo + 1  ) ; 
	}
	
}


void xuatDanhSachHocSinhTheoDeQuy(HocSinh danhSachHocSinh[] , int kichThuocDanhSach  ,int batDau , int soThuTu ){
	
	if( batDau > kichThuocDanhSach -1 ) {
		return ;
	}
	
	else{
		cout<<setw(10)<<soThuTu << setw(20)<<danhSachHocSinh[batDau].hoVaTen
		<< setw(20)<<danhSachHocSinh[batDau].diem
		<< setw(20)<<danhSachHocSinh[batDau].loaiDaoDuc
		<< setw(20)<<danhSachHocSinh[batDau].tienThuong<<endl ; 
	
   		return xuatDanhSachHocSinhTheoDeQuy(danhSachHocSinh ,kichThuocDanhSach , batDau+1 , soThuTu+1  );
   	}
}


int demHocSinhCoTienHon10000(HocSinh danhSachHocSinh[]  ,  int trai , int phai ){
	
	if(trai > phai ){
		return 0 ; 
	}
	
	if(trai == phai ){
		
		if(danhSachHocSinh[trai].tienThuong >= 10000 ){
			return 1 ; 
		}
		else{
			return 0 ;
		}
	}
		int giua = (trai + phai ) / 2 ; 
		
		return demHocSinhCoTienHon10000(danhSachHocSinh  , trai , giua ) + demHocSinhCoTienHon10000(danhSachHocSinh  , giua +1  , phai ); 	
}

bool daXep[10];  // đánh dấu đã xếp
int viTri[10];   // vị trí của từng cầu thủ

void inPhuongAn( HocSinh danhSachHocSinh[] , int kichThuocDanhSach) {
	
    for (int i = 0; i < kichThuocDanhSach; i++) {
        cout << "Vi tri " << i + 1 << ": " << danhSachHocSinh[viTri[i]].hoVaTen << endl;
    }
    cout << "------------------------\n";
    
}
 // k là chỉ số bàn hiện tại đang cần đặt màn hình
void xepViTri(int k) {
    if (k == kichThuocDanhSach) {
        inPhuongAn(danhSachHocSinh , kichThuocDanhSach);
        return;
    }
    for (int i = 0; i < kichThuocDanhSach; i++) {
        if (!daXep[i]) {
            daXep[i] = true;
            viTri[k] = i;
            xepViTri(k + 1);
            daXep[i] = false;  // quay lui
        }
    }
}







void RunMain(){
	

	

    
    cout<<setw(70)<< "---------Danh sach hoc sinh---------"<<endl ;
    xuatTieuDe(); 
    xuatDanhSachHocSinhTheoDeQuy(danhSachHocSinh ,kichThuocDanhSach , 0 , 0  ); 
    cout<<endl ;
    
    cout<<"Tong Tien Thuong Cua Tat Ca Hoc Sinh la: "<< tongTienThuong(danhSachHocSinh , kichThuocDanhSach , 0 )<< " VND\n"; 
    
    cout<<"So hoc sinh diem tu 7 la: "<< demSoHocSinhTren7(danhSachHocSinh  , 0 ,  kichThuocDanhSach   )<<" Hoc Sinh"<<endl; 
    
    cout<<"So hoc sinh co tien thuong tu 10000: "<<demHocSinhCoTienHon10000(danhSachHocSinh  , 0 ,  kichThuocDanhSach) <<endl ;
    
    HocSinh toHopKetQua[6] ; 
  
    cout<<"So phuong an chon ra 6 hoc sinh la: "<<endl;
    chonToHop6HocSinh(danhSachHocSinh ,kichThuocDanhSach , 0 ,toHopKetQua , 6 , 0   ); 
    cout<<" Tong phuong an chon ra 6 hoc sinh la : "<< phuongAnChon6HocSinh << endl;
    
   // xepViTri(0);
}



int main(){
	
	RunMain();
	
}