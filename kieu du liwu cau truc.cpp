#include<stdio.h>
#include<conio.h>
#include<algorithm> //std::__gcd(a,b)
struct phansotumau
{
	int ts;
	int ms;
};
typedef struct phansotumau phanso;
void nhapps( phanso &ps )
{
	printf("nhap tu so :");                 scanf("%d",&ps.ts);
	do{
		printf("nhap mau so :");                scanf("%d",&ps.ms);
		if(ps.ms==0)
         printf("nhap sai rooi ba oi , nhap lai ho t cai\n");
	}while(ps.ms==0);
 } 
 void xuatps( phanso ps)
 {
 	printf("%d/%d",ps.ts,ps.ms);
 }
 int UCLN(int a , int b)
 {
 	if(b==0)  return a;
 	return UCLN(b,a%b);
 }
 void rutgon(phanso &ps)
 {
 	int c=UCLN(ps.ts,ps.ms);
 	ps.ts=ps.ts/c;
 	ps.ms=ps.ms/c;
 }
 	phanso tongps(phanso a ,phanso b)
 	{
 		phanso tong;
 		tong.ts=a.ts*b.ms+a.ms*b.ts;
 		tong.ms=a.ms+b.ms;
 		rutgon(tong);
 		return tong;
	 }
phanso hieups(phanso a ,phanso b)
 	{
 		phanso h;
 		h.ts=a.ts*b.ms-a.ms*b.ts;
 		h.ms=a.ms+b.ms;
 		rutgon(h);
 		return h;
	 }
phanso tichps(phanso a, phanso b)
{
	phanso t;
	t.ts=a.ts*b.ts;
	t.ms=b.ms*b.ms;
	rutgon(t);
	return t;
	 }	
phanso thuongps(phanso a, phanso b)
{
	phanso thuong;
	thuong.ts=a.ts*b.ms;
	thuong.ms=b.ts*a.ms;
	rutgon(thuong);
	return thuong;
 } 
int main()
{
	phanso x,y;
	printf("nhap phan so thu nhat\n ");
	nhapps(x);
	xuatps(x);
	printf("\nnhap phan so thu 2\n");
	nhapps(y);
	xuatps(y);
	phanso tong=tongps(x,y);
	printf("\ntong: ");
	xuatps(tong);
	phanso hieu=hieups(x,y);
	printf("\nhieu: ");
	xuatps(hieu);
	phanso tich=tichps(x,y);
	printf("\ntich: ");
	xuatps(tich);
	phanso thuong=thuongps(x,y);
	printf("\nthuong: ");
	xuatps(thuong);
	getch();
	return 0;
}
