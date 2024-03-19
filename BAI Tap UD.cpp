/// Nguyen Ngoc Sang
///201108714
///nguyenngocsang1682@gmail.com
#include<stdio.h>
#include<conio.h>
#define MAX 100
#include<math.h>
///nhap xuat bang de quy 
void nhapmang(int a[], int n)
{
    if(n== 0) return ;
        nhapmang(a, n-1);
        printf("Nhap vao phan tu thu %d : ", n-1);
        scanf("%d", &a[n-1]);
    }
void xuatmang(int a[], int n)
{
    if(n==0) return ;
        xuatmang(a, n-1);
        printf("%4d ",a[n-1]);
}
//// tong cac phan tu bang de quy 
long tongDQ(int a[], int n)
{
	if ( n== 0)
		return 0;
	return a[n-1] + tongDQ(a,n-1) ;
}
//tong chan de quy 
long tongchanDQ(int a[], int n)
{
	if ( n== 0)
		return 0;
	if( a[n-1] % 2 == 0 )
	return a[n-1] + tongchanDQ(a,n-1) ;
	return tongchanDQ(a,n-1);
}
/// tong le de quy
long tongleDQ(int a[], int n)
{
	if ( n== 0)
		return 0;
	if( a[n-1] % 2 != 0 )
	return a[n-1] + tongleDQ(a,n-1) ;
	return tongleDQ(a,n-1);
}
// so lon nhat trong mang 
int timmax(int a[], int n)
{
	if (n == 0)
		return a[0];
	if (timmax(a, n - 1) > a[n - 1])
		return timmax(a, n - 1);
	else
		return a[n - 1];
}
/////tim so no nhat trong mang 
int timmin(int a[], int n)
{
	if (n == 0)
		return a[0];
	if (timmin(a, n - 1) < a[n - 1])
		return timmin(a, n - 1);
	else		
		return a[n - 1];
}
/// dem cac phan tu chan
int demchan(int a[], int n)
{

	if (n == 0)
		return 0;
	int d = demchan(a, n - 1);
	if (a[n - 1] % 2 == 0)
		return d + 1;
	else
		return d;
}
void lietkechan(int a[],int n){
 for(int i=0; i<n;i++){
 	if(a[i] % 2 == 0 ){
 	printf("%4d ",a[i]);
}
}
}
//// tim kiem tuyen tinh giam dan
int timtuyentinh(int a[], int n, int key)
{
	int i=0;
	while (i<n && key != a[i])
	   i++;
	   if(i<n)  return i;
	   return -1;
}
////tim kiem nhi phan giam dan 
void swap(int &x, int &y)
{
	int tmp = x;
	x = y;
	y = tmp;
}
void sapxepgiam(int a[], int n){
	for (int i = 0; i<n-1;i++)
		for(int j=i+1 ; j<n ; j++)
			if(a[i] < a[j])
		swap(a[i],a[j]);	
	}
int timNhiPhan_giam(int a[], int n, int key)
{
	int left = 0, right = n-1, mid;
	while(left <= right)
	{
		mid = (left+right)/2;
		if(a[mid] == key)
			return mid;
		if(a[mid] > key)
			left = mid+1;
		else 
			right = mid-1;
	}
	return -1;
}

//ham menu
void menu(int &chon)
{
	printf("\n\n=======MENU==============\n");
	printf("1- Linear Search\n");
	printf("2- Binary Search\n");
	printf("\n0- Exit\n");
	printf("=========================\n");
	printf("Ban chon chuc nang: ");
	scanf("%d", &chon);
}

int main()
{
	int a[MAX] = {6,5,8,-7,1,0,-9,4};
	int n = 8;
	int x = -7, vt ,chon;
	printf("cac phan tu cua mang \n ");
	xuatmang(a,n);
	printf("\ntong cac phan tu cua mang la : %ld",tongDQ(a,n));
	printf("\n tong cac phan tu chan trong mang : %ld",tongchanDQ(a,n));
	printf("\n tong cac phan tu le trong mang : %ld",tongleDQ(a,n));
	printf("\n phan tu lon nhat trong mang : %ld",timmax(a,n));
	printf("\n phan tu nho nhat trong mang : %ld",timmin(a,n));
	printf("\n co %d chan trong mang: ",demchan(a,n));
	
	lietkechan(a,n);
//	int a[MAX];
//	int n;
//		printf("nhap vao so luong phan tu mang : ");
//		scanf("%d",&n);
//	nhapmang(a,n);
//		printf(" phan tu mang vua moi nhap :\n");
//	xuatmang(a,n);
	printf("\n----------tim kiem tuyen tinh --------------\n");
	sapxepgiam(a,n);
	xuatmang(a,n);
	 vt = timtuyentinh(a,n,x);
	if(vt == -1 ) printf("\n (x=%d) khong ton tai ", x);
	else printf("\n (x=%d) tai vi tri [%d]",x,vt);
	
	printf("\n-------------tim kiem nhi phan ----------------\n");
	sapxepgiam(a,n);
	printf("\n noi dung mang khi giam la : \n ");
	xuatmang(a,n);
	vt = timNhiPhan_giam(a,n,x);
	if(vt == -1 ) printf("\n (x=%d) khong ton tai ", x);
	else printf("\n (x=%d) tai vi tri [%d]",x,vt );
	
	do
	{
		menu(chon);
		switch(chon)
		{
			case 1: //Linear Search / timTuyenTinh 
					printf("\n phan tu vua moi nhap la \n");
					xuatmang(a,n);
					 vt = timtuyentinh(a,n,x);
					if(vt == -1 ) printf("\n (x=%d) khong ton tai ", x);
							
				break;
				
			case 2: // timNhiPhan_giam
					sapxepgiam(a,n);
					printf("\n noi dung mang khi tang la : \n ");
					xuatmang(a,n);
					vt = timNhiPhan_giam(a,n,x);
					if(vt == -1 ) printf("\n (x=%d) khong ton tai ", x);
					else printf("\n (x=%d) tai vi tri [%d]",x,vt );		
				break;
			default: chon =0;
		}
		
	}while(chon != 0);
	return 0;
} 