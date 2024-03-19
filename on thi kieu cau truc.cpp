#include<stdio.h>
#include<conio.h>
typedef struct sinhvien
{
	char ma[11];
	char hoten[31];
	char ngay[3];
	char thang[3];
	char nam[7];
	int gt;
	char lop[10];
	float dtb;
}sv;
void nhap1sv(sv *x)
{
	printf(" nhap mssv  sinh vien: ");
	scanf("%s",(*x).ma);
	fflush(stdin);
	printf("\nnhap ten sinh vien : ");
	gets((*x).hoten);
	printf("\n nhap ngay sinh: ");
	scanf("%s",(*x).ngay);
	printf(" \nnhap thang sinh: ");
	scanf("%s",(*x).thang);
	printf("\n nhap nam sinh: ");
	scanf("%s",(*x).nam);
	printf(" \n lop : ");
	scanf("%s",(*x).lop);
	printf(" \nnhap ddiem trung binh : ");
	scanf("%f",(*x).dtb);
	do{
		printf("\n nhp gioi tinh x-nam, y-nu: ");
		(*x).gt=getch();
	}while((*x).gt!='x' && (*x).gt!='y');
}
void xuat1sv(sv x)
{
	printf("\nho va ten :%s\t ma so sinh vien :%s\t",x.hoten,x.ma);
	if(x.gt=='x')  printf("gioi tinh: nam\t");  else printf(" gioi tinh : nu\t");
	printf("\nngay thang nam sinh : %s/%s/%s",x.ngay,x.thang,x.nam);
	printf("\nlowp : %s",x.lop);
	printf("\ndiem tb : %0.1f",x.dtb);
}
void nhapsl(int &n)
{
	do{
		printf("nhap n= ");    scanf("%d",&n);
		if(n<0 || n>100)
		printf("nhap sai nhap lai 0<n<100");
	}while(n<0 || n>100);
}
void nhapds(sv a[], int n)
{
	printf("\n nhap danh sachs sinh vien --------------------------->\n");
	for(int i=0;i<n;i++)
	{
		printf("\n nhap sinh vien thu %d\n ",i+1);
		nhap1sv(&a[i]);
	}
}
void xuatds(sv a[], int n){
	printf("\n danh sach sinh vien ---------------------------------.\n");
	for(int i=0;i<n;i++)
		xuat1sv(a[i]);
}
int tk(sv a[], int n,int x)   //tim kiem tuyen tinh
{
 for(i=0;i<n;i++){
 	if(a[i].gia ==x )
 	return a[i];
 }
 sv temp;
 temp.gia=0;
 return temp;
}
int tknp(int tk(sv a[], int n,int x)  // tim kiem nhi phan 
{
	int left=0,right=n-1,mid;
	while(left<= right ){
	mib=(left+right)/2;
	if(a[mid].gia == x)
		return mib;
	if(a[mid].gia <x)
		return left=mib+1;
	if(a[mid].gia > x)
		return right=mid+1;
	}return -1;
}
long tongsv(sv a[], int n)
{
	int t=0;
	for(int i=0;i<n;i++)
	{
		t=t+a[i];
	}
}
void swap(int a, int b)
{
	int tam=a;
	a=b;
	tam=b;
}
void bubblesor(sv a[],int n)
{
	for(int i=0;i<n-1;i++)
		for(int j=n-1;j>i;j--)
			if(a[j-1]>a[j])
				sawp(a[j],a[j-1]);
}
void interchangesort(sv a[], int b)
{
   	for(int i=0;i<n-1;i++)
   		for(int j=i+1; j<n;j++)
   			if(a[i]>a[j])
   				sawp(a[j],a[j]);
}
void selectionsort(sv a[], int n)
{
   int 	vtmin=i;
   for(i=0; i<n-1;i++)
   	for(j=i+1;j<n;j++)
   	 if(a[j]<a[vtmin])
   	 vtmin=j;
   	 	swap(a[vtmin],a[i]);
}
void writefile(char *D:\\butbi.txt)
{
 FILE*f;
 int n,i;
 bb x;
 f=fopen(D:\\butbi.txt,"ab");
 printf("nhap so luong but bi ?");
 scanf("%d",&n);
 ffush(stdin);
 for(i=1;i,=n;i++){
 printf("cay but thu %i\n",i);
 printf("gia ban but bi ");
gets(x.gia);
fwrite(&x,sizeof(x),1,f);
fflush(stdin);
}
fclose(f);
getch();
}
void readfile(char * D:\\butbi.txt)
{
  file*f;
  bb x;
  f=fopen(D:\\butbi.txt,"rb");
  printf(" gia ban but \n");
  fread(&x,sizeof(x),1,f);
  while(!feof(f)){
  	printf(" %s",x.gia);
  	fread(&x,sizeof(x),1,f);
  }	
  fflush(stdin);
  getch();
}