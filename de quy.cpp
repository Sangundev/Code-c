#include <stdio.h>
#include <conio.h>
#include<math.h>
void nhapMang(int a[], int n)
{
    if(n== 0) return ;
        nhapMang(a, n-1);
        printf("Nhap vao phan tu thu %d : ", n-1);
        scanf("%d", &a[n-1]);
    }
void xuatMang(int a[], int n)
{
    if(n==0) return ;
        xuatMang(a, n-1);
        printf("%4d ",a[n-1]);
}
long tong(int a[],int n)
{
	if(n==0)  return 0; 
	return a[n-1]+tong(a,n-1); 
} 
long tongchan(int a[] , int n)
{
	if(n==0)  return 0; 
	if(a[n-1]%2==0)
	return  tongchan(a,n-1)+ a[n-1];
	else return tongchan(a,n-1);
}
long tongle(int a[] , int n)
{
	if(n==0)  return 0; 
	if(a[n-1]%2!=0)
	return  tongle(a,n-1)+ a[n-1];
	else return tongle(a,n-1);
}
int kiemtra( int n)
{
	int tam=sqrt(n);
	for(int i=2; i<=tam ; i++)
   {
   	if (n%i==0)
   	return 0;
   }
	return 1;
}
int nguyentodau(int a[], int n)
{
	
	if(n==0)
	return 0 ;
	if(kiemtra(nguyentodau(a,n-1)==1)) return nguyentodau(a,n-1); 
	if(kiemtra(a[n-1]))
	return a[n-1];	
}
int tongsnt(int a[],int n)
{
		if(n==0)
	return 0 ;
	if(kiemtra(tongsnt(a,n-1)==1)) return tongsnt(a,n-1)+a[n-1]; 
	if(kiemtra(a[n-1]))
	return a[n-1];	
} 
int chandau( int a[], int n)
{
	if(n<=0) 
	return 1;
	chandau(a,n-1);
	if(chandau(a,n-1)%2==0)
	return chandau(a,n-1);
	if(a[n-1]%2==0)
	return a[n-1];
	else return 1;
} 
int ledau( int a[], int n)
{
	if(n<=0) 
	return 1;
	chandau(a,n-1);
	if(chandau(a,n-1)%2==1)
	return chandau(a,n-1);
	if(a[n-1]%2==1)
	return a[n-1];
	else return 1;
} 
int chancuoi(int a[], int n )
{
	if(n<=0) 
	return 1;
	if(a[n-1]%2==0)
	return a[n-1];
   else return chancuoi(a,n-1);
}
int timmax(int a[], int n)
{
if(n==0)
return a[0];
if(timmax(a,n-1)>a[n-1])
return timmax(a,n-1);
else return a[n-1];
}
int demchan(int a[],int n)
{
	
	if(n==0)
	return 0;
	int d=demchan(a,n-1);
	if(a[n-1]%2==0)
	return d+1;
	else return d;
}
int demmax(int a[], int n,int max)
{
	
	if(n<=0)
	return 0;
	if(a[n-1]==max)
	return demmax(a,n-1,max)+1;
	return demmax(a,n-1,max);	
}
int main()
{
    int a[100], n;
        printf("\nNhap vao so phan tu mang: ");
        scanf("%d", &n);
    nhapMang(a, n);
    xuatMang(a, n);
    printf( "\ntong cac phan tu : %ld ",tong(a,n));
    printf( "\ntong cac phan tu chan : %ld ",tongchan(a,n));
    printf( "\ntong cac phan tu le : %d ",tongle(a,n));
    printf("\n so nguyen to dau : %d ", nguyentodau(a,n));
     printf("\n tong so  nguyen to: %d ", tongsnt(a,n));
    printf(" \n phan tu chan dau : %d", chandau(a,n));
    printf("\n phan tu le dau la : %d ", ledau(a,n)); 
    printf("\n chan cuoi la : %d",chancuoi(a,n));
    printf(" \n phan tu lon nhat trong mang la : %d", timmax(a,n));
    printf("\n cac phan tu chan trong mang la : %d ",demchan(a,n));
    int max=timmax(a,n);
    printf("\n so phan tu max : %d",demmax(a,n,max));
	getch();
    return 0;
}
