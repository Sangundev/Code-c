//cau 1
#include<stdio.h>
int main()
{
	int n ,i,s=0,t=0 ;
	printf("n=");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	if(n%i==0){
	printf("%d",i);
		s=s+1;
		t=t+i;
	}
	printf("\ntong cac uoc so %d laf %d",n,t);
	printf("\nso luong cac uoc so cua %d la %d ",n,s);
	return 0;	
}
//cau 4
#include "stdio.h"
#include "conio.h"
int main()
{
	int n ,i, s=0 ;
	printf("nhap n= ");
	scanf("%d",&n);
	for(i=1; i<=n; i++)
	if(i%3==0){
		printf("%d",i);
		s=s+i;
	}
	printf("tong so chia het cho 3= %d",s);
	return 0;
}
//cau 5
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n, i,Sum=0;
printf("Nhap n: ");
scanf("%d", &n);
for(i=1; i<=n; i++){

    Sum += 1/i;
}
printf("TONG = %f", Sum);
    return 0;
}
// cau 6
#include<stdio.h>
int main(){
 int i, n, fact = 1;

 printf("nhap so de tinh giai thua\n");

 scanf("%d", &n);

 for (i= 1; i<= n; i++)

   fact = fact * i;

 printf("giai thua cua %d = %d\n", n, fact);

 return 0;
}
//cau 7

#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
	int n ,i, s=0;
	printf("Nhap mot so nguyen duong \n");
	scanf("%d", &n);
	for (i=1; i<=n; i++) 
	if (n%i == 0)
	s=s+i;
	if (s==n)
		printf("%d la so hoan hao", n);
	else
		printf("%d khong la so hoan hao", n);
	return 0;
}
