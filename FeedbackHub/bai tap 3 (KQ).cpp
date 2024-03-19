/// Nguyen Ngoc Sang
///201108714
///nguyenngocsang1682@gmail.

//// danh sach lien ket don 
#include<stdio.h>
#include<conio.h>
#include<string.h>
typedef struct SinhVien
{
	char masv[10];
	char hoten[40];
	float dtb;
}SV;
typedef struct node
{ 
	SV data; //// (data cung dc)
	node* pNext;	/// p=pointer
}Node;

typedef Node* NODEPTR;
void nhap1SV(SV &x)
{
    printf("nhap ma sinh vien : ");
    scanf("%s",&x.masv);
    printf("nhap ten sinh vien  ");
    fflush(stdin);  gets(x.hoten);
    printf("nhap diem tb : ");
    scanf("%f",&x.dtb);
}
////==========================================
void xuatSV(SV x )
{
	printf("\n | %8s | %-40s | %.2f |", x.masv, x.hoten, x.dtb);
}

void init(Node* &pHead)
{
	pHead = NULL;
}
//////////////////========
void nhapsl(int &n)
{
	do{
		printf("\n\t nhap so luong so hoc vien <100 : ");
		scanf("%d",&n);
		if(n<1 )  printf("nhap lai :" );
	}while (n<1 );
}
/////====================
Node* createNode(SV x)
{

	Node* p = new Node;
	if( p!= NULL)
	{
		p->data = x,
		p->pNext = NULL;
	}
	return p;
}
////=================
void inserFirst(Node* &pHead,SV x)
{
	Node* p = createNode(x);
	p->pNext = pHead;
	pHead = p;
}

////========================
void input(Node* &pHead)
{		
		int n; nhapsl(n);
		SV x; 
		
		for(int i=0 ;i<n;i++)
		{
			printf(" nhap thong tin sinh vien thu %d:\n ",i+1);
			nhap1SV(x);
			inserFirst(pHead, x);
		}
}

void output(Node* pHead)
{
	for(Node* i = pHead ; i!= NULL; i=i->pNext )
		xuatSV(i->data);
}
/////////////////==============================================
Node* timtuyentinh(Node* pHead)
{	
	Node* i= pHead ;
	while (i != NULL && stricmp(key , i->data.masv) != 0 )
	   i=i->pNext;
	   if(i!= NULL)  return i;
	   return NULL;
}
/////////////////////////////=====================================
void swap(SV &x, SV &y)
{
	SV tmp = x;
	x = y;
	y = tmp;
}
void sapxepgiam(Node* &pHead){
	for (Node* i = pHead; i->pNext !=NULL ; i=i->pNext)///i<n-1 = i->pNext !=NULL 
		for(Node*j = i->pNext ; j !=NULL ; j=j->pNext)
			if(i->data.masv < j->data.masv)
				swap(j->data,i->data);	
	}
//	
///////////////===================================================
//void TimY(Node* &pHead ,Sach a[], char y[40])
//{	
//	int dem=0;
//	for(Node* i = pHead ; i!= NULL; i=i->pNext )
//	{
//		if(strcmp(i->data.tensach,y)==0)
//		{
//			xuat1Sach(i->data);
//			dem++;
//		}
//	}
//	if(dem==0)
//		printf("Khong tim thay cuon sach nay.");
//}
/////================================================
 int demslSV(Node* pHead)
{
    Node *p=pHead;
    int dem=0;
    while(p!=NULL)
    {
        p=p->pNext;
        dem++;
    }
    return dem;
}
//////////////==========================================
//void DeleteFirst(NODEPTR &pHead){
//		NODEPTR p;
//	if (pHead == NULL){
//		printf(" k tim thay nut de xoa dau  ");
//	}else {
//		p = pHead;
//		pHead = pHead->pNext;
//		delete p;
//}
//}
////////	//======================================================
void Max(Node* &pHead, SV a[])
{
		float max = a[0].dtb;
	for(Node* i = pHead ; i!= NULL; i=i->pNext )
		if(i->data.dtb > max)
			max = i->data.dtb;
	for(Node* i = pHead ; i!= NULL; i=i->pNext )
		if(i->data.dtb == max)
		xuatSV(i->data);
}
/////===========================================
//void Min(Node* &pHead,Sach a[])
//{
//		float min = a[0].giasach;
//	for(Node* i = pHead ; i!= NULL; i=i->pNext )
//		if(i->data.giasach < min)
//		min = i->data.giasach;
//	for(Node* i = pHead ; i!= NULL; i=i->pNext )
//		if(i->data.giasach == min)
//		xuat1Sach(i->data);
//}
////===============================================================
//void sapXepgiam_giasach(Node* pHead,Sach a[]) // InterChangeSort_Inc
//{
//	for( Node* i= pHead ; i->pNext != NULL; i=i->pNext)
//		for( Node* j= i->pNext ; j != NULL; j=j->pNext)
//			if(i->data.giasach < j->data.giasach)
//				swap(j->data,i->data);
//}
//////////=========================================
////void deleteX(Node* pHead,Sach[])
////{
////	Node *p=pHead;
////	if(p==NULL || pHead->pNext == NULL){
////		printf(" \nkhong tim thay nut xoa\n ");
////	}else{
////		p = pHead->pNext;
////		pHead->pNext=p->pNext;
////		delete p;
////	}
////=====================================================
//=====================================================
int main()
{
	NODEPTR pHead ;
	
	SV a[100];
	init(pHead);
	
	input(pHead);
	printf("\n noi dung moi nhap :\n");
	output(pHead);
	
//	printf("\n----------load-------------\n");
//	printf("\n o day co %d nhung loai sach dang ton tai  ", demslsach(pHead));
//	printf("\n-----------------------\n");
//	
	printf("\n giam dan theo masach ");
	sapxepgiam(pHead);
	output(pHead);
//	
//	
////	printf("\nnhap vi tri can xoa : ");
////	scanf("%d",&a);
////	deleteX(pHead,a);
////	printf("\n mang cua moi xoa \n ");	
////	output(pHead);
//	
//	DeleteFirst(pHead);
//	printf("\n mang cua moi xoa dau  \n ");	
//	output(pHead);
//	
//	printf(" \n sap xep giam theo gia sach ");
//	sapXepgiam_giasach(	pHead,a);
//	output(pHead);
//	
	printf(" \nsinh vien  co diem cao dat nhat : ");
	Max(pHead, a);
//	
//	printf(" \ncuon sach co gia ra nhat : ");
//	Min(pHead,a);
//	
	int x;
	printf("\nnhap ma sinh vien tim : ");
	scanf("%d",&x);
	Node* vt =timtuyentinh(pHead,x);
	if(vt == NULL )
	{
		printf(" sv (x=%d) khong co ton tai  ");
	}
	else{
		printf("\n sv (x=%d) co to tai  ");
	}
//
//	printf("\n--------TIM SACH TEN Y------- ");
//	char y[40];
//		printf("\nNhap ten sach can tim: ");
//		fflush(stdin);								
//		gets(y);
//		TimY(pHead,a,y);
		
	
	return 0;
} 