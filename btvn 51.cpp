#include<stdio.h>
#include<conio.h>

struct sinhvienvietnam
{
	char tensv[30];
	int gioitinh;
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
		do{
		printf("nhap gioi tinh x_nam,y_nu :");
		x.gioitinh=getche();
	}while(x.gioitinh!='x'&& x.gioitinh!='y');
	printf("\nnhsp ma so sinh vien: ");
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
	if(x.gioitinh=='x') printf("gioi tinh : nam ");else printf("gioi tinh: nu");
	printf("\nmssv : %d\n",x.mssv);
	printf("\nnganh: %s\n",x.nganh);
	printf("ngay sinh :%d/%d/%d.\n ",x.ngay,x.thang,x.nam);
	printf("diem toan: %0.1f",x.diem);
}
void nhapds(sv a[],int n)
{
	for(int i=0; i<n;i++)
	{
		printf("\n nhap danh sach sinh vien thu %d: \n",i+1);
		nhapsv(a[i]);
	}
}
void xuatds(sv a[],int n)
{
	printf("\ndanh sach sinh vien-------------------------------\n ");
	for(int i=0;i<n;i++)
	xuatsv(a[i]);
}
int main()
{
	sv x;
	nhapsv(x);
	xuatsv(x);
	sv a[100],n;
	nhapds(a,n);
	xuatds(a,n);
	getch();
	return 0;
}

