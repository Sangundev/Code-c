#include<stdio.h>
#include<conio.h>
#include<math.h>
void nhapmang(int a[100][100],int &d, int &c)
{
	do{
	printf("nhap dong: ");
	scanf("%d",&d);
	if(d<0 || d>100)
	printf("nhap sai nhap lai ho tao cai ");
	}while(d<0 || d>100);
	do{
		printf("nhap cot: ");
		scanf("%d",&c);
		if(c<0 || c>100)
		printf("nhap sai roi tr oi tr ");
	}while(c<0 || c>100);
	for(int i=0;i<d;i++)
		for(int j=0;j<c;j++)
		{
		printf("a[%d][%d]= ",i,j);
		scanf("%d",&a[i][j]);
	}
}
void xuatmang(int a[100][100], int d ,int c)
{
	for(int i=0;i<d;i++){
		for(int j=0;j<c;j++)
	printf("%8d",a[i][j]);
	printf("\n\n");
}
}
int tong(int a[100][100],int d,int c)
{
	int s=0;
	for(int i=0;i<d;i++){
		for(int j=0;j<c;j++)
	s=s+a[i][j];
	}
	return s;
}
int tongdcc(int a[100][100],int d)
	{
		int t=0;
	for(int i=0;i<d;i++){
           t=t+a[i][i];
	}
	return t;
}
double tongdcp(int a[100][100], int n)
{
	double tong=0;
	for(int i=0;i<n;i++)
		{
		tong=tong+a[i][n-i-1];
}
return tong;
}
int main()
{
	int a[100][100];
	int d=0;
	int c=0;
	nhapmang(a,d,c);
	xuatmang(a,d,c);
	tong(a,d,c);
	printf("tong ma tran %d",tong(a,d,c));
	tongdcc(a,d);
	printf("\ntong duong cheo chih :%d",tongdcc(a,d));
	tongdcp(a,d);
	printf("\ntong duong cheo phu %8.2f",tongdcp(a,d));
	getch();
	return 0;
}
