#include<stdio.h>
#include<conio.h>
void nhapmang( int *a, int m, int n)
{
	for(int i=0; i<m;i++)
		for(int j=0; j<n; j++)
		{
		printf("nhap a[%d][%d]=	",i,j);
		scanf("%d",(a+i*n+j));
	}
}
void xuatmang( int *a, int m, int n)
{
    for(int i=0; i<m;i++){
		for(int j=0; j<n; j++)
	printf("%4d",*(a+i*n+j));
	printf("\n");
}
}
int solon( int *a, int m, int n)
{
	int max==a[0][0];
	for(int i=0; i<m;i++){
		for(int j=0; j<n; j++)
		if(max<*(a+i*n+j))
		max=*(a+i*n+j);
	}return max;
}
int main(){
	int m=0;
	int n=0;
	int *a; 
	printf("nhap dong=");         scanf("%d",&m);
	printf("nhap cot=");            scanf("%d",&n);
	nhapmang(a,m,n);
	xuatmang(a,m,n);
	printf("phan tu lon nhat trong mang la %d",solon(a,m,n))
	getch();
	return 0;
}
