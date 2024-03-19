#include<stdio.h>
int sum(int n){
	 long S = 0;
  do
  {
    printf("\nnhap n > 0 :");
    scanf("%d", &n);
  if(n <= 0)
  {
    printf("\n thay chu n>0 khong vay, nhap lai dum cai : !");
  }
  }while(n <= 0);
  printf("tong cac uoc so tu 1 den %d la: ",n);
  for(int i = 1; i <= n; i++)
  {
    if(n % i == 0)
    {
      printf("%d + ", i);
      S = S + i;
    }
  }
  printf("\b\b= %d", S);
}
int main()
{
  int n; 
  sum(n);
  printf("\n-----------------------------------------\n");
}
