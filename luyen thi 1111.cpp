#include<stdio.h>
void nhap(int a[], int n)
{
	for(int i=0; i<n; i++)
	printf("a[%d]= " , i);
	scanf("%d",&a[i]);
}
void xuat(int a[], int n)
{
	for(int i=0 ; i<n; i++)
	{
    	printf("%4d",a[i]);
	}
}
int main()
{
	int n, a[100];
	printf("nhap n= ");       scanf("%d",&n);
	nhap(a,n);
	xuat(a,n);
	return 0;
} 

