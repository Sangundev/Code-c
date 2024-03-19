#include<stdio.h>
#include<conio.h>

struct sinhvienvietnam
{
	char tensv[30];
	int mssv;
	char nganh[40];
	int ngay,thang,nam;
	float diem;
};
typedef struct sinhvienvietnam sv;
void nhapsv(sv &x)
{
	fflush(stdin);
	printf("nhap ten sinh vien : ");
	gets(x.tensv);
	printf("nhsp ma so sinh vien: ");
	scanf("%d",&x.mssv);
	printf("nganh : ");
	fflush(stdin);
    gets(x.nganh);
	printf("nhap ngay:");
	scanf("%d",&x.ngay);
	printf("nhap thang:");
	scanf("%d",&x.thang);
	printf("nhap nam:");
	scanf("%d",&x.nam);
	printf("\nnhap diem toan : ");
	scanf("%f",&x.diem);
}
void xuatsv(sv x)
{ 
     printf("_____________________________________________________________________________");
     printf("\n\n");
	printf(" ten : %s\n",x.tensv);
	printf("\nmssv : %d\n",x.mssv);
	printf("\nnganh: %s\n",x.nganh);
	printf("ngay sinh :%d/%d/%d.\n ",x.ngay,x.thang,x.nam);
	printf("diem toan: %0.1f",x.diem);
	
}
int main()
{
	sv x;
	nhapsv(x);
	xuatsv(x);
	getch();
	return 0;
}

