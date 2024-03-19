#include"stdio.h"
#include"conio.h"
typedef struct ngaythang
{
	int ngay;
	int thang;
	int nam; 
 };
typedef struct sinhvien
{
	char hoten[20];
	char MSSV[15];
	ngaythang    ngaysinh;
	char gioitinh[4];
	char lop[10];
	float diemtoan;
	float  diemly;
	float diemtin;
 } SV;
 void nhapngaythang(ngaythang &x)
 {
 	printf("nhap ngay");
 	scanf("%d",&x.ngay);
 		printf("nhap thang");
 	scanf("%d",&x.thang);
 		printf("nhap nam");
 	scanf("%d",&x.nam);
 }
 void nhap(SV *x)
 {
 	fflush(stdin);
 	printf("hoten : ");
 	gets(*x.hoten);
 	printf("ma so sinh  vien ");
 	gets(*x.MSSV);
 	printf(" ngay thang nam sinh ");
 	nhap ngaythang(x.ngaysinh);
 	printf("gioi tinh ");
 	gets(*x.gioitinh);
 	printf("lop");
 	gets(*x.lop);
 	printf("diem toan ");
 	scanf("%f",x.diemtoan);
 	printf("diem ly ");
 	scanf("%f",x.diemly);
 	printf("diem tin");
 	scanf("%f",x.diemtin);
 }
 void(SV x)
 {
 	printf("hoten");
 	puts(x.hoten);
 	printf("MSSV");
 	puts(x.MSSV);
 	printf("ngaysinh");
 	printf("%d%d%d\n.x.ngaysinh.ngay,x.ngaysinh.thang,x.ngaysinh.nam");
 	printf("gioitinh");
 	puts(x.gioitinh);
 	printf("lop");
 	puts(x.lop);
 	printf("diemtoan =0.2f\n diemly =0.2f\n diemtin =0.2f",x.diemtoan,x.diemly,x.diemtin);
 }
 int main()
 {
 	sinhvien x;
 	nhap(&x);
 	xuat(x);
 	getch();
 	return 0;
 }
