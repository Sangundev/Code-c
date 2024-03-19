#include<stdio.h>
#include<conio.h>
void nhap(int a[][100], int d, int c)
{
	for(int i=0; i<d; i++)
		for(int j=0; j<c;j++)
		{
			printf("phan tu thu a[%d][%d]= ",i,j);
			scanf("%d",&a[i][j]);
		}
}
void xuat(int a[][100], int d, int c)
{
	for(int i=0; i<d; i++){
		for(int j=0; j<c;j++)
			printf("%d\t",a[i][j]);
			printf("\n\n");
		}
}
int demphantu(int a[][100], int d, int c)
{
	int dem=0;
		for(int i=0; i<d; i++){
		for(int j=0; j<c;j++)
			dem++;
		}return dem;
}
int tong(int a[][100], int d, int c)
{
	int s=0;
		for(int i=0; i<d; i++){
		for(int j=0; j<c;j++)
		s=s+a[i][j];
	}return s;
}
int max(int a[][100], int d, int c)
{
	int max1=a[0][0];
		for(int i=0; i<d; i++){
		for(int j=0; j<c;j++)
		if(max1<a[i][j])
		max1=a[i][j];
	}return max1;
}
int cheochinh(int a[][100], int d)
{
	int s=0;
	for(int i=0; i<d; i++){
			s=s+a[i][i];
	}return s;
}
int main()
{
	int a[100][100];
	int d=0,c=0;
	printf("nhap dong= ");     scanf("%d",&d);
	printf("nhap cot= ");     scanf("%d",&c);
	nhap(a,d,c);
	xuat(a,d,c);
	printf(" phan tu trong mang la %d ",demphantu(a,d,c));
	printf(" \ntong mang la %d",tong(a,d,c));
	printf("\n phan tu ln nhat %d",max(a,d,c));
	printf("\n tong cheo chinh %d",cheochinh(a,d));
	return 0;
}