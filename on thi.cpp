#include<conio.h>
#include<stdio.h>
#define MAX 100
void nhapsl(int &n)
{
	do{
		printf("n= ");
		scanf("%d",&n);
		if(n<0 || n>100 )
		printf(" nhap sai moi nahp lai n>0>100");
	}while(n<0 || n>100);
}

void nhapmang(int a[],int n)
{
	for( int i=0 ; i<n ; i++){
		printf(" a[%d]= ",i);
		scanf("%d",&a[i]);
		}
		}
void xuatmang(int a[] , int n ){
	printf(" \n mag gom cac phan tu\n ");
 for ( int i=0; i<n ;i++)
       printf("%5d",a[i]);
 }
 void chiahet3(int a[] , int n ){
 	printf("\n cac phan tu chia het cho 3 \n ");
 	for(int i=0; i<n;i++){
 	if(a[i]%3==0)
 	printf("%d",a[i]);
    }
}
int main()
{
	int a[100],n;
	nhapsl(n);
	nhapmang(a,n);
	xuatmang(a,n);
	chiahet3(a,n);
	return 0;
}
