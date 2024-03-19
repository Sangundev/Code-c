#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
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
	printf("\n");
}
}
int main()
{
	int a[100][100];
	int d=0;
	int c=0;
	nhapmang(a,d,c);
	xuatmang(a,d,c);
	getch();
	return 0;
}
