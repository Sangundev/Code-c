#include<stdio.h>
#include<conio.h>
#include <math.h>
#include<time.h>
#include<iostream>

void NhapMang(int a[], int n)
{
	for(int i=0; i<n; i++)
	{
		printf("Phan tu thu [%d] ",i);
		scanf("%d",&a[i]);
	}
}
//===============================
void XuatMang(int a[],int n)
{
	printf("\n Mang Vua Nhap\n ");
	for(int i=0; i<n; i++)
	{
		printf("%d\t",a[i]);
	}
}
void MangNgauNhien(int a[], int n)
{
	srand((unsigned)time(NULL));
	for(int i=0; i<n; i++)
		a[i]=rand()%100 - rand()%100;
}
//========================================
void GTle(int a[],int n)
{
	printf("\nPhan tu le cua mang: ");
    for (int i = 0; i < n; i++){
        if (a[i] % 2 != 0){
            printf("\nA[%d] = %d", i, a[i]);
        }
        }
}
//===================================================
int PTLONHONX (int a[],int n)
{
	int x = 13;
//	printf("nhap x :");     scanf("%d",&x);
	printf("\n phan tu lon hon %d la \n ",x);
	for(int i=0; i<n; i++)
	{
		if(a[i]>x){
			printf("%d\t",a[i]);
		}
	}
}
//======================================================
void DemPTBoix(int a[], int n)
{
	int m = 5;
//	printf("nhap m :");     scanf("%d",&m);
	
	printf("\nboi so cua %d gom\n ",m);
	for(int i=0; i<n; i++){
		if(a[i]%m && a[i]>0)
		printf("%d\t",a[i]);
	}
}
//=================================================
bool KTSNT(int x)
{
	int dem=0;
	for(int i=1; i<=x; i++)
		if (x % i == 0)
			dem++;
	if (dem==2)
		return true;
	return false;
}
void XuatPTSNT(int a[], int n)
{
	printf("\nSo nguyen to la:\n");
	for(int i=0; i<n; i++)
		if(KTSNT(a[i])==true)
			printf("%d\t",a[i]);
}
//=================================================
int VTGTle(int a[],int n)
{	int vitri;
	printf("\n PTGT LE : \n ");
	for(int i=0; i<n; i++)
	{
		if(a[i]%2 !=0 )
		{
			vitri=i;
			printf("\n vi tri %d\t",vitri);
		}
	}
}
//=====================================
int max(int a[],int n)
{
	int max=a[0];
		for(int i=0; i<n; i++)
		{
			if(max<a[i]){
				max=a[i];
			}
		}
	return max;
}
//========================================
int vitrimin(int a[], int n){
  int min = a[0];
  int vitri;
  for(int i = 0; i < n; i++){
    if(a[i] < min){
      min = a[i];
      vitri = i;
    }
  }
  return vitri;
}
//===================================================
int VTPTAmDTien(int a[], int n)
{
	{
		for (int i=0; i<n; i++)
		if (a[i]<0)
		return i; 
	} 
	return -1;
}
int VTPTAmLonNhat(int a[], int n)
{
	int i;
	int vitrimin=VTPTAmDTien(a,n);
	if(vitrimin!=-1)
	{
		for(i=vitrimin; i<n; i++)
			if(a[i]<0 && a[i]>a[vitrimin])
				vitrimin=i;
		return vitrimin;
	}
	return -1;
}
//===============================
int main()
{
//	int n,a[100];
	int a[]= {-12, 23, -14, 27, 15, -6, -16, 20, 22, 18};
	int n=10;
//	printf("nhap n :");      scanf("%d",&n);
//	NhapMang(a,n);
//	MangNgauNhien(a,n);
	XuatMang(a,n);
	GTle(a,n);
	PTLONHONX(a,n);
	DemPTBoix(a,n);
	XuatPTSNT(a,n);
	VTGTle(a,n);
	printf(" \nMAX %d",max(a,n));
	printf(" \nvi tri nhon nhat :%d",vitrimin(a,n));
	printf(" \nvi tri am lon nhat :%d",VTPTAmLonNhat(a,n));
	
return 0;
}