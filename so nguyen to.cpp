#include<stdio.h>
#include<conio.h>
#include<math.h>
int tong_so (int n,int i)
	{
		int tmp;
		tmp=0;
	for(i=0;i<=n;i++){
		if(n%i==0)
		printf("la so nguyen to");
	else
		printf("khong la so nguyen to");}
		return 0;
}
int main(){
		int i,n;
		printf("nhap n : ");
		scanf("%d",&n);
		tong_so(n,i);
		return 0;
}
