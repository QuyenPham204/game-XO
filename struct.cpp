/*
Câu 2: Vi?t chuong trình th?c hi?n nh?ng yêu c?u sau:
a) (3 di?m)
Ð?nh nghia ki?u c?u trúc MAYTINH d? qu?n lý máy tính, bao g?m nh?ng thông tin sau:
Mã máy tính, Tình tr?ng máy tính, H? và tên nhân viên ph? trách máy, S? di?n tho?i nhân
viên ph? trách máy.
Ð?c d? li?u t? bàn phím vào m?ng c?u trúc (n máy tính)
MAYTINH A[MAX]; // #define MAX 100
Yêu c?u: Khi nh?p d? li?u Tình tr?ng máy tính ch? ch?p nh?n các ký hi?u T, H, M, P
v?i ý nghia nhu sau:
T: Máy tính ho?t d?ng t?t
H: Máy tính h?ng ph?n c?ng
M: Máy tính l?i k?t n?i m?ng
P: Máy tính l?i ph?n m?m
b) (2 di?m)
Xóa thông tin các máy tính b? h?ng ph?n c?ng (Tình tr?ng H) ra kh?i danh sách máy tính.
c) (2 di?m)
Hi?n th? lên màn hình danh sách máy tính theo khuôn d?ng sau:
STT Mã máy tính Ghi chú Tên nhân viên S? di?n tho?i
Trong dó, m?c Ghi chú c?n ghi chi ti?t tình tr?ng máy tính
(Ghi chú: May tinh hoat dong tot, May tinh loi ket noi mang, May tinh loi phan mem)
------------------------------- H?t ------------------------------
Luu ý: Sinh viên không du?c s? d?ng tài li?u. Cán b? coi thi không gi?i thích
*/
#include<bits/stdc++.h>
#define MAX 100
using namespace std;
typedef struct Maytinh {
	int ma;
	char tt;
	string ten;
	string sdt;
} MT;
int n;     // bien toan cuc
MT A[MAX];
void nhap1(MT &a) {
	cout<<"Ma may tinh : ";
	cin>>a.ma;
	cout<<"Tinh trang may tinh : ";
	cin>>a.tt;
	cout<<"Ho va ten :";
	fflush(stdin);
	getline(cin,a.ten);
	cout<<"So dien thoai : ";
	fflush(stdin);
	getline(cin,a.sdt);
}
void nhap() {
	for(int i=0; i<n; ++i) {
		nhap1(A[i]);
	}
	cout<<"Da nhap xong !";
}
string kiemtra(char a) {
	string x="";
	if(a=='T') x="May hoat dong tot";
	else if(a=='H') x="May hong phan cung ";
	else if(a=='M') x="May tinh loi ket noi mang";
	else if(a=='P') x="May tinh loi phan mem";
	return x;
}
void hien1(MT a) {
	cout<<"Ma may tinh : "<<a.ma<<endl;
	cout<<"Tinh trang cua may tinh : "<<kiemtra(a.tt)<<endl;
	cout<<"Ho va ten : "<<a.ten<<endl;
	cout<<"So dien thoai : "<<a.sdt<<endl;
}
void hien() {
	cout<<"Danh sach may tinh la : "<<endl;
	for(int i=0; i<n; ++i) {
		hien1(A[i]);
	}
}
// ham xoa
void xoa(int b) {
	for(int i=b; i<n; ++i) {
		A[i]=A[i+1];
	}
	--n;
}
//Xóa thông tin các máy tính b? h?ng ph?n c?ng (Tình tr?ng H) ra kh?i danh sách máy tính.
void xoaMay() {
	printf("Thuc hien xoa may :\n");
	for(int i=0; i<n; ++i) {
		if(A[i].tt=='H') xoa(i);
	}
	printf("Da xoa thanh cong!");
}
// ham xep xep
// sap xep theo ma giam dan , neu 2 may co cung ma thi sap xep tinh trang tang dan
bool cmp(MT a,MT b) { // dieu kien sap xep
	if(a.ma==b.ma) return a.tt<b.tt;
	return a.ma>b.ma;
}
void sx() {
	sort(A,A+n,cmp);
	printf("Sap xep thanh cong !");
}
// ham tim kiem theo tinh trang
void timKiem() {
	char x;
	printf("Nhap tinh trang may muon tim : ");
	fflush(stdin);
	scanf("%c",&x);
	for(int i=0; i<n; ++i) {
		if(A[i].tt==x) {
			printf("Thong tin may can tim :\n");
			hien1(A[i]);
			break;
		}
	}
	printf("Tim kiem thanh cong!");
}
// ham them
void themMay(){
	nhap1(A[n]);
	++n;
	printf("Them thanh cong !");
}
void hienmaylonnhat() {
	cout<<"Danh sach may tinh la : "<<endl;
	
		hien1(A[1]);
	
}
int main() {
	int option;
	system("color E");
	do {
		printf("1) Nhap danh sach may tinh     :\n");
		printf("2) Xuat danh sach may tinh     :\n");
		printf("3) Xoa may tinh hong phan cung :\n");
		printf("4) Sap xep may tinh            :\n");
		printf("5) Tim kiem may tinh           :\n");
		printf("6) Them may tinh               :\n");
		printf("7) Ma may lon nhat             :\n");
		printf("Moi bn cho lenh : ");
		scanf("%d",&option);
		system("cls");
		switch(option) {
			case 1:
				printf("Nhap so luong may tinh : ");
				scanf("%d",&n);
				nhap();
				break;
			case 2:
				hien();
				break;
			case 3:
				xoaMay();
				hien();
				break;
			case 4:
				sx();
				hien();
				break;
			case 5:
				timKiem();
				break;
			case 6:
				themMay();
				break;
				case 7: 
				hienmaylonnhat();
				break;
				
				
		}
		system("pause");
	} while(option<=7);
}
