#include <stdio.h>
#include <conio.h>
#define MAX 100
int ucln(int,int);
int ucln(int a, int b)
{
int s;
if(a==b)
return a;
if(a%b==0 && a>b)
return b;
s=a%b;
a=s;
if(a>b)
return ucln(a,b);
else
ucln(b,a);
}
int main()
{

int tam,tam1,tam2=1,tam3,tamx;
int chuoiso[MAX];
int a,b,i,j,n;
printf("nhap a: ");
scanf("%d",&a);
printf("nhap b: ");
scanf("%d",&b);
printf("ucln cua a & b la: %d",ucln(a,b));
printf("\nnhap tu so a: ");
scanf("%d",&a);
printf("nhap mau so b: ");
scanf("%d",&b);
printf("a/b= %d/%d",(a/ucln(a,b)),(b/ucln(a,b)));
printf("\nban can nhap bao nhieu so? ");
printf("n = ");
scanf("%d",&n);

for(i=0;i<n;i++)
{
printf("nhap so thu %d: ",i+1);
scanf("%d",&chuoiso[i]);
}

for(i=1;i<n;i++)
if(chuoiso[0]>chuoiso[i])
{
tam = chuoiso[0];
chuoiso[0]=chuoiso[i];
chuoiso[i]=tam;
}

for(i=1;i<n;i++)
if(tam1 <ucln(chuoiso[0],chuoiso[i]))
tam1 =ucln(chuoiso[0],chuoiso[i]);

for(i=tam1;i>0;i--)
{

for(j=0;j<n;j++)
{
if(chuoiso[j]%i==0)
{
if(j==n-1)
{
printf("ucln cua chuoi n la: %d",i);
tamx=i;
goto end;
}
continue;
}
else
break;
}

}
end:


for(i=0;i<n-1;i++)
for(j=i+1;j<n;j++)
if(chuoiso[i]==chuoiso[j])
chuoiso[j]=tamx;
for(i=0;i<n;i++)
tam2*=(chuoiso[i]/tamx);

tam2*=tamx;
for(i=1;i<tamx;i++)
if(tam2%i==0&&tam2!=tamx)
{
tam2=tam2/i;
break;
}
printf("\nbcnn cua chuoi n la: %d", tam2);




getch();
return 0;
}
