/* Cho một danh sach d chua dữ liệu về n man hình may tinh cua n nung bm
hình gồm tên hàng sản xuất, kích thước màn hình, giá bán.
Viết chương trình thực hiện (chương trình được viết bằng ngôn ngữ C/C++, lưu vào 1 file với tên:
HoVaTen_MSV.CPP).
Khai báo cấu trúc dữ liệu của danh sách d. Khởi tạo n và khởi tạo danh sách d gồm n màn hình (dữ liệu khởi
tạo có tính thực tiền, không nhập từ bàn phím, n≥ 7).
Thiết kế và cải đặt hàm biểu diễn thuật toán A1 để tính và trả về tổng giá bán của tất cả các màn hình trong d
bằng chiến lược đệ quy. Ứng dụng thuật toán A1 và biểu diễn kết quả của thuật toán.
Thiết kế các thuật toán A2 theo chiến lược chia để trị để tính và trả về số lượng màn hình trong d có kích
thước từ 15.6 inch trở lên và thuật toán A3 theo chiến lược quay lui để cho biết có tất cả bao nhiêu phương
án khác nhau để đặt n màn hình trong d lên n chiếc bàn được ghi số thứ tự từ 1 đến n, hiển thị các phương án
đó, mỗi phương án hiến thị số thứ tự được ghi trên bàn và tên nhà sản xuất (ví dụ: (1 - LG, 2 - HP, ... , n -
Samsung)). Cài đặt các hàm biểu diễn A2 và A3. Ứng dụng A2, A3 và biểu diễn kết quả của chúng. */

//#include<bits/stdc++.h>
//using namespace std ; 
//
//const int MAX =100 ; 
//
//struct ManHinh{
//	
//	string hangSanXuat; 
//	double kichThuoc ;
//	double giaBan; 
//
//};
//
//	int kichThuocDanhSach = 7;
//	
//	ManHinh danhSachManHinh[MAX]{
//	
//      {"Sam sung" , 15.6 , 1 } , 
//      {"LQ" , 15.6 , 2 } , 
//      {"HP" , 11 , 2 } , 
//      {"Acer" , 15.6 , 2 } , 
//      {"Asus" , 16 , 2 } , 
//      {"Dell" , 17 , 100000 } , 
//      {"Lenovo" , 18 , 100000 } 
//};
//
//double tongTien(ManHinh danhSachManHinh[], int kichThuocDanhSach , int chiSo){
//	
//	if(chiSo > kichThuocDanhSach  ){
//		return 0 ; 
//	}
//	
//	else{
//		return danhSachManHinh[chiSo].giaBan + tongTien(danhSachManHinh , kichThuocDanhSach , chiSo +1 ); 
//	}
//}
//
//int manHinh_15(ManHinh danhSachManHinh[], int trai , int phai){
//	
//	if(trai > phai ){
//		return 0 ;
//	}
//	
//	if(trai == phai ){
//		
//		if(danhSachManHinh[trai].kichThuoc >= 15.6){
//			return 1 ;
//		}
//		
//		else {
//			return 0 ;
//		}
//		
//	}
//	int giua = (trai + phai ) / 2 ; 
//	return manHinh_15(danhSachManHinh , trai , giua )  + manHinh_15(danhSachManHinh , giua +1  , phai ) ; 
//	
//}
//	
//	
////bool daXep[10] ; // Mảng đánh dấu: daXep[i] = true nếu màn hình i đã được xếp vào bàn nào đó
//// int viTri[10] ;    // Mảng lưu vị trí: viTri[k] = i nghĩa là tại bàn số k đang đặt màn hình i
////
////int soPhuongAn = 0 ; 
////int gioiHanPhuongAn = 10 ; 
////
////void inPhuongAn(){
////	
////	for(int i = 0 ; i < kichThuocDanhSach ; i++ ){
////		cout<<"(" << i +1 <<" - " << danhSachManHinh[viTri[i]].hangSanXuat << ")" << endl ; 
////	}
////	
////	cout<<endl ;
////}
////
////
////void datManHinh(int k ){
////	
////	if(soPhuongAn >=gioiHanPhuongAn ) {
////		return ; 
////	}
////	
////	if(k == kichThuocDanhSach ){
////		cout<<"Phuong an thu : "<< soPhuongAn + 1  << endl ;
////		inPhuongAn() ; 
////		soPhuongAn++ ; 
////	}
////	
////	else{
////		for(int i = 0 ; i < kichThuocDanhSach ; i ++ ){
////			if(!daXep[i]){ //neu ban thu i chua xep 
////				daXep[i] = true ;  // danh dau la da xet 
////				viTri[k] = i ;  // danh dau ban i dang o ban k 
////				datManHinh(k+1);  // tiep tuc goi de quy de xap cho man tiep tiep 
////				daXep[i] = false ;  // Hoàn tác đánh dấu daXep[i] để cho phép màn hình i có thể được xét lại trong phương án khác.
////			}
////		}
////	}
////}
//
//
//bool daXep[10] ; 
//int viTri[10] ; 
//int soPhuongAn = 0 ; 
//int gioiHanPhuongAn = 30 ; 
//
//void xuatPhuongAn(){
//	
//	for(int i = 0 ; i < kichThuocDanhSach ; i++ ){
//		cout<<"viTri" << i+ 1 << " -  "<< danhSachManHinh[viTri[i]].hangSanXuat << endl ;
//	}
//	cout<< endl ;
//}
//
//void xepViTri(int soBanHienBan){
//  
//  if(soPhuongAn  > gioiHanPhuongAn ){
//  	return ; 
//  }
//  
//  if(soBanHienBan == kichThuocDanhSach){
//  	xuatPhuongAn(); 
//  	soPhuongAn++; 
//  }
//  
//  else{
//  	for(int i = 0 ; i < kichThuocDanhSach ; i++ ){
//  		if(!daXep[i]){
//  			daXep[i] = true ;
//  			viTri[soBanHienBan] = i ; 
//  			xepViTri(soBanHienBan +1); 
//  			daXep[i] = false ;
//		  }
//	  }
//  }
//}
//	
 /* Gọi datManHinh(0):
  chọn i = 0 → đặt vào bàn 0
    gọi datManHinh(1):
      chọn i = 1 → đặt vào bàn 1
        gọi datManHinh(2):
          chọn i = 2 → đặt vào bàn 2
            gọi datManHinh(3): in phương án (0,1,2)
      quay lui, thử i = 2 → đặt vào bàn 1
        ...
*/
//void RunMain(){
//	
//
//	cout<<"Tong tien: " << tongTien(danhSachManHinh , kichThuocDanhSach , 0 )<<endl;
//	cout<<"so man hinh >= 15.6 : " << manHinh_15(danhSachManHinh , 0 , kichThuocDanhSach  )<<endl;
//       
//    xepViTri(0) ; 
// 
//}
//
//
//int main(){
//	
//	RunMain();
//	
//}

#include<bits/stdc++.h>
using namespace std ; 

const int MAX = 100 ; 

struct ManHinh{
	
	string hangSanXuat; 
	double kichThuoc;
	double gia;
	
};

int kichThuocDanhSach = 7 ; 
ManHinh dSManHinh[MAX]{
	
  {"LG" , 15.6 , 10000}, 
  {"Sam sung" , 15 , 9000},
  {"Lenovo" , 16 , 15000},
  {"Asus" , 17 , 20000},
  {"Acer" , 15.6 , 10000},
  {"Nitro" , 16 , 15000},
  {"Dell" , 15 , 9000}
  
};


void xuatTieuDe(){ 

  cout<<setw(10)<<"STT" 
  <<setw(20)<<"HangSanXuat"
  <<setw(20)<<"KichThuoc"
  <<setw(20)<<"GiA"<< endl;
  
}




void xuatDs(ManHinh dSManHinh[] , int kichThuocDanhSach , int soThuTu ){
	
	if(  kichThuocDanhSach >= 7 ){
		return ; 
	}
	
	else{
		cout<<setw(10) << soThuTu <<  setw(20) <<dSManHinh[kichThuocDanhSach].hangSanXuat << 
		setw(20) <<dSManHinh[kichThuocDanhSach].kichThuoc << 
		setw(20) <<dSManHinh[kichThuocDanhSach].gia << endl;
		xuatDs(dSManHinh , kichThuocDanhSach + 1  ,soThuTu + 1  ); 
	}
}


double tongTienManHinh(ManHinh dSManHinh[] , int kichThuocDanhSach ){
	
	if(kichThuocDanhSach >=7 ){
		return 0 ; 
	}
	else{
		return dSManHinh[kichThuocDanhSach].gia + tongTienManHinh(dSManHinh , kichThuocDanhSach +1 ); 
	}
}


int demSoManHinh(ManHinh  dSManHinh[] , int trai , int phai ){
	
	if(trai > phai){
		return 0 ; 
	}
	
	if(trai == phai ){
		
		if(dSManHinh[trai].kichThuoc >= 15.6) {
			return 1 ; 
		}
		else{
			return 0 ;
		}
	}
	
	int giua = (trai + phai ) / 2 ; 
	return demSoManHinh(dSManHinh ,trai , giua  )+ demSoManHinh(dSManHinh , giua +1  , phai  );
}


bool daXep[10]; 
int viTri[10] ; 
int soPhuongAn = 0 ; 
int gioiHanPhuongAn = 30 ;


void xuatPhuongAn(){
	
	int soThuTu = 0 ; 
	for(int i = 0 ; i < kichThuocDanhSach ; i++ ){
	   cout<<"ViTri: "<< i +1 <<  "--- "<< dSManHinh[viTri[i]].hangSanXuat << endl ;
	}
}


void xepManHinhVaoBan(int soBanHienTai){
	
	if(soBanHienTai == kichThuocDanhSach ){
	
		cout<<"Phuong an thu: "<<soPhuongAn+1 << endl; 
		xuatPhuongAn(); 
 		soPhuongAn++; 
		cout<<endl; 
		return;
		
	}
	
	if(soPhuongAn >= gioiHanPhuongAn ){
		return ;
	}
	
	else { 
	    
	    for(int i = 0 ; i < kichThuocDanhSach ; i++ ){
	    	if(!daXep[i]){
	    		daXep[i] = true; 
	    		viTri[soBanHienTai] = i ; 
	    		xepManHinhVaoBan(soBanHienTai+1); 
	    		daXep[i] = false; 
			}
		}
	}
}
// chon 6 man hinh trong 7 man hinh 

void xuatManHinhChon(ManHinh toHop[] , int kichThuoc1){
	
	xuatTieuDe();
	int soThuTu = 0 ; 
	for(int i = 0 ; i < kichThuoc1 ; i++ ){
		cout<<setw(10) << soThuTu <<  setw(20) <<toHop[i].hangSanXuat << 
		setw(20) <<toHop[i].kichThuoc << 
		setw(20) <<toHop[i].gia << endl;
		soThuTu++ ; 
	}
	
}

int phuongAn = 0 ; 

void chon6ManHinh(ManHinh  dSManHinh[] , int kichThuocDanhSach , int batDau , ManHinh toHop[] , int soManHinh , int chiSo){
	
	if(chiSo == soManHinh ){
		cout<<"Phuong an thu: "<<phuongAn+ 1 << endl ; 
		xuatManHinhChon(toHop , soManHinh ) ; 
		phuongAn++; 
		return ;
	}
	
	else{
		for (int i = batDau ; i <= kichThuocDanhSach -  (soManHinh - chiSo )  ; i++ ){
			toHop[chiSo]  = dSManHinh[i];
			chon6ManHinh(dSManHinh , kichThuocDanhSach , i +1 ,toHop , soManHinh , chiSo +1  ); 
		}
	}
	
}

int inDex[MAX];     
bool dd[MAX];   
int dem = 0;
int gioiHan = 30;

void show() {
	
	if(dem >= gioiHan ){
    	return ; 
	}
	
    cout << "Phuong an " << ++dem << ":\n";
    
    for (int i = 0; i < kichThuocDanhSach; i++) {
        cout << "Ban " << i + 1 << " - " << dSManHinh[inDex[i]].hangSanXuat << endl;
    }
    cout << "-------------------------\n";
}


void Try(int k) {
    for (int i = 0; i < kichThuocDanhSach; i++) {
        if (!dd[i]) {
            inDex[k] = i;
        }
        dd[i] = true;
            
        if (k == kichThuocDanhSach - 1) {
            show();
        } else {
            Try(k + 1);
        }

        dd[i] = false;
    }
}


void RunMain(){
	
	cout<<setw(60)<<"--------Danh sach sinh vien----------" << endl; 
	xuatTieuDe();
	xuatDs(dSManHinh ,0 , 0  ); 
	cout<<endl;
	
	cout<<"+ Tong tien cua cac man hinh la: " << tongTienManHinh (dSManHinh , 0 )<< " VND" << endl; 
	
	cout<<endl;
	
	cout<<"+ so man hinh co kich thuoc >= 15.6in la: " << demSoManHinh (dSManHinh , 0 , kichThuocDanhSach -1  )<< " ManHinh" << endl; 
	
	Try(0); 
    
//	ManHinh toHop[6]; 
//	cout<<"+ cac phuong an chon 6 man hinh trong 7 man hinh la: "<< endl;
//	chon6ManHinh(dSManHinh , kichThuocDanhSach , 0 ,toHop , 6 , 0  ); 
//	cout<<"tong so cach chon man hinh la: "<<phuongAn<<" cach chon"<<endl ;
//	
}


int main(){
	
	RunMain(); 
	
}