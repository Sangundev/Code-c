#include <stdio.h>
#include <math.h>
void Nhap(int n)
{
	do{
    printf("Nhap vao so n: ");
    scanf("%d",&n);
 	if(n<0 || n>3000)
	printf(" nhap lai (0<n<3000)");     
}while(n<0 || n>3000);
}

int so_nt(int n)
    {
        if (n>1)
            {
                int i,j=1;
                for (i=2; i<= sqrt(n) ; i++ )
                        if (n%i==0) {
						j=0;
						break;
				}
                return j;
            }
        return 0;
    }
    
void Primes(int n)
{
    int i;
    for(i=2;i<=n;i++)
    {
        if(so_nt(i)) 
        printf(" %4d",i);
    }
}
void kt(int n,int x) {
int capso;
  int i;
  	for(capso = 1;capso<n;capso++){
   	 for(i=2;i<x;i++){
      	if(so_nt(i)&&so_nt(i+capso)&&so_nt(i+2*capso)&&(so_nt(i)+so_nt(i+2*capso)==2*so_nt(i+capso))) //vd 3,5,7 cap so la 2,thi (3)+(3+2*2)=2*(3+2)
     		printf("\n3 so : %d %d %d voi n : %d\n",i,i+capso,i+2*capso,capso);
     	}
     }
}
 int main(){
 	int n,x;
 	printf(" nhap n cap so : ");             scanf(" %d",&n);
 	printf(" nhap so : ");    scanf("%d",&x);
 	Primes(x);
 	 kt(n,x);
     return 0;
 }
