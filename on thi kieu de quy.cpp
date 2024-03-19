#include<stdio.h>
#include<math.h>
void nhap(int a[], int n)
{
	if(n<=0)
		return ;
	nhap(a,n-1);
	printf("nhap phan tu thu a[%d]= ",n-1);
	scanf("%d",&a[n-1]);
}
void xuat(int a[], int n)
{
	if(n<=0)
	return ;
	xuat(a,n-1);
	printf("%4d",a[n-1]);
}
long tongmang(int a[], int n)
{
	if(n==0)
	return 0;
	tongmang(a,n-1);
	return tongmang(a,n-1)+a[n-1];
}
int ptcuoi(int a[], int n )
{
	if(n<=0) 
	return 1;
	ptcuoi(a,n-1);
	return a[n-1];
   return ptcuoi(a,n-1);
}

int main(){
	int a[100];
	int n;
	printf("nhap n= ");         scanf("%d",&n);
	nhap(a,n);
	xuat(a,n);
	printf("\ntong mang la : %ld ",tongmang(a,n));
	printf("\nphan tu vuoi trong mang la : %d ",ptcuoi(a,n));
}