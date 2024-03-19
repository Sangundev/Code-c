#include<stdio.h>
struct nhapthongtinsinhvien
{
    char mssv[20];
	char tensv[20];
	int ngay,thang,nam;
	int tuoi;
	int gioitinh;
	char khoa[30];
	char truong[20];
    float diemtb;
};
typedef struct nhapthongtinsinhvien sv;
void nhapsv(sv &x)
{
	fflush(stdin);
	printf("nhap ten sinh vien : ");
	gets(x.tensv);
	printf("nhap ma so sinh vien : ");
	fflush(stdin);
	gets(x.mssv);
	
	do{
		printf("nhap gioi tinh x_nam,y_nu :");
		x.gioitinh=getche();
	}while(x.gioitinh!='x'&& x.gioitinh!='y');
	printf("nhap ngay: ");
	scanf("%d",&x.ngay);
	printf("nhap thang: ");
	scanf("%d",&x.thang);
	printf("nhap nam : ");
	scanf("%d",&x.nam );
	printf("nhap tuoi: ");
	scanf("%d",x.tuoi);
	printf("nhap khoa cua sinh vien : ");
	scanf("%s",&x.khoa);
	printf("nhap truong cua sinh vien theo hoc : ");
	scanf("%s",&x.truong);
    printf("nhap diem cua sinh vien : ");
    scanf("%f",diemtb&x.diemtb);
}
void xuatsv(sv x)
{
	printf("ten : %s",x.tensv);
	printf("ma so dinh vien : %s",x.mssv);
	if(x.gioitinh=='x') printf("gioi tinh : \nnam ");else printf("gioi tinh: nu");
	printf(" tuoi : %d",x.tuoi);
	printf("ngay thang nam sinh : %d/%d/%d ",x.ngay,x.thang,x.nam);
	printf("khoa : %s",x.khoa);
	printf("truong : %s",x.truong);
	printf("diem  trung binh : 0.2%f",x.diemtb);
}
int main()
{
	sv x;
	nhapsv(x);
	xuatsv(x);
	getch();
	return 0;
}
