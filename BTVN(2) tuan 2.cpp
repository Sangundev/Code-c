/// Nguyen Ngoc Sang
///201108714
///nguyenngocsang1682@gmail.

//// danh sach lien ket don 
#include<stdio.h>
#include<conio.h>
#include<string.h>
typedef struct CuonSach
{
	int masach;
	char tensach[40];
	float giasach;
}Sach;
typedef struct node
{ 
	Sach data; //// (data cung dc)
	node* pNext;	/// p=pointer
}Node;

typedef Node* NODEPTR;
void nhap1Sach(Sach &x)
{
    printf("nhap ma cuon sach: ");
    scanf("%d",&x.masach);
    printf("nhap ten cuon sach: ");
    fflush(stdin);  gets(x.tensach);
    printf("nhap gia cuon sach: ");
    scanf("%f",&x.giasach);
}
//==========================================
void xuat1Sach(Sach x )
{
	printf("\n | %8d | %-40s | %.2f |", x.masach, x.tensach, x.giasach);
}

void init(Node* &pHead)
{
	pHead = NULL;
}
////////////////========
void nhapsl(int &n)
{
	do{
		printf("\n\t nhap so luong so nguen <100 : ");
		scanf("%d",&n);
		if(n<1 )  printf("nhap lai :" );
	}while (n<1 );
}
///====================
Node* createNode(Sach x)
{

	Node* p = new Node;
	if( p!= NULL)
	{
		p->data = x,
		p->pNext = NULL;
	}
	return p;
}
//=================
void inserFirst(Node* &pHead,Sach x)
{
	Node* p = createNode(x);
	p->pNext = pHead;
	pHead = p;
}

//========================
void input(Node* &pHead)
{		
		int n; nhapsl(n);
		Sach x; 
		
		for(int i=0 ;i<n;i++)
		{
			printf(" nhap thong tin cuon sach thu %d: ",i+1);
			nhap1Sach(x);
			inserFirst(pHead, x);
		}
}

void output(Node* pHead)
{
	for(Node* i = pHead ; i!= NULL; i=i->pNext )
		xuat1Sach(i->data);
}
///////////////==============================================
Node* timtuyentinh(Node* pHead,int key)
{	Node* i= pHead ;
	while (i != NULL && key != i->data.masach )
	   i=i->pNext;
	   if(i!= NULL)  return i;
	   return NULL;
}
///////////////////////////=====================================
void swap(Sach &x, Sach &y)
{
	Sach tmp = x;
	x = y;
	y = tmp;
}
void sapxepgiam(Node* &pHead){
	for (Node* i = pHead; i->pNext !=NULL ; i=i->pNext)///i<n-1 = i->pNext !=NULL 
		for(Node*j = i->pNext ; j !=NULL ; j=j->pNext)
			if(i->data.masach < j->data.masach )
				swap(j->data,i->data);	
	}
	
///////////=====================================
void sapxepgiam_tt(Node* &pHead){
	for (Node* i = pHead; i->pNext !=NULL ; i=i->pNext){
		Node* vtmin = i;
		for(Node*j = i->pNext ; j !=NULL ; j=j->pNext)
			if(i->data.masach < j->data.masach )
					vtmin = j;
				swap(vtmin->data,i->data);	
			}
	}
/////////////////////////////=====================================

/////////////===================================================
void TimY(Node* &pHead ,Sach a[], char y[40])
{	
	int dem=0;
	for(Node* i = pHead ; i!= NULL; i=i->pNext )
	{
		if(strcmp(i->data.tensach,y)==0)
		{
			xuat1Sach(i->data);
			dem++;
		}
	}
	if(dem==0)
		printf("Khong tim thay cuon sach nay.");
}
///================================================
 int demslsach(Node* pHead)
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
////////////==========================================
void DeleteFirst(NODEPTR &pHead){
		NODEPTR p;
	if (pHead == NULL){
		printf(" k tim thay nut de xoa dau  ");
	}else {
		p = pHead;
		pHead = pHead->pNext;
		delete p;
}
}
//////	//======================================================
void Max(Node* &pHead,Sach a[])
{
		float max = a[0].giasach;
	for(Node* i = pHead ; i!= NULL; i=i->pNext )
		if(i->data.giasach > max)
			max = i->data.giasach;
	for(Node* i = pHead ; i!= NULL; i=i->pNext )
		if(i->data.giasach == max)
		xuat1Sach(i->data);
}
///===========================================
void Min(Node* &pHead,Sach a[])
{
		float min = a[0].giasach;
	for(Node* i = pHead ; i!= NULL; i=i->pNext )
		if(i->data.giasach < min)
		min = i->data.giasach;
	for(Node* i = pHead ; i!= NULL; i=i->pNext )
		if(i->data.giasach == min)
		xuat1Sach(i->data);
}
//===============================================================
void sapXepgiam_giasach(Node* pHead,Sach a[]) // InterChangeSort_Inc
{
	for( Node* i= pHead ; i->pNext != NULL; i=i->pNext)
		for( Node* j= i->pNext ; j != NULL; j=j->pNext)
			if(i->data.giasach < j->data.giasach)
				swap(j->data,i->data);
}
////////=========================================
//void deleteX(Node* pHead,Sach[])
//{
//	Node *p=pHead;
//	if(p==NULL || pHead->pNext == NULL){
//		printf(" \nkhong tim thay nut xoa\n ");
//	}else{
//		p = pHead->pNext;
//		pHead->pNext=p->pNext;
//		delete p;
//	}
//=====================================================
//void menu(int &chon)
//{
//	printf("\n\n=======MENU==============\n");
//	printf("1- Linear Search\n");
//	printf("2- Binary Search\n");
//	printf("\n0- Exit\n");
//	printf("=========================\n");
//	printf("Ban chon chuc nang: ");
//	scanf("%d", &chon);
//}
////=================================================
void Auto_input(NODEPTR &pHead, Sach a[], int n)
{
	
		Sach x; 
		for(int i=0 ;i<n;i++){
			inserFirst(pHead , a[i]);
		}
}
//=====================================================
int main()
{
	NODEPTR pHead ;
		Sach a[10] =
		{
		//int masach;	char tensach[40];	float giasach;
		{1004, "Lap trinh C", 		5.2},
		{1009, "Lap trinh Java", 	5.7},
		{1002, "Lap trinh Python", 	3.2},
		{1008, "Lap trinh Web", 	8.6},
		{1001, "Lap trinh Pascal", 	2.2},
		{1007, "Lap trinh C#", 		1.4},
		{1006, "Lap trinh mang", 	8.4},
		{1010, "Lap trinh AI", 		4.2},
		{1003, "Lap trinh Media", 	8.6},
		{1005, "Lap trinh Web", 	6.4}
	}; /// NODEPTR = node* pointet head
	int n = 10;
	
	init(pHead);
	
//	input(pHead);
	Auto_input(pHead, a, n);
	printf("\n noi dung moi nhap :\n");
	
	output(pHead);
	printf("\n----------load-------------\n");
	printf("\n o day co %d nhung loai sach dang ton tai  ", demslsach(pHead));
	printf("\n-----------------------\n");
	
	printf("\n giam dan theo masach ");
	sapxepgiam(pHead);
	output(pHead);
	
	
	printf("\n giam dan theo masach ");
	sapxepgiam_tt(pHead);
	output(pHead);
	
//	printf("\nnhap vi tri can xoa : ");
//	scanf("%d",&a);
//	deleteX(pHead,a);
//	printf("\n mang cua moi xoa \n ");	
//	output(pHead);
	
	DeleteFirst(pHead);
	printf("\n mang cua moi xoa dau  \n ");	
	output(pHead);
	
	printf(" \n sap xep giam theo gia sach ");
	sapXepgiam_giasach(	pHead,a);
	output(pHead);
	
	printf(" \ncuon sach co gia dat nhat : ");
	Max(pHead,a);
	
	printf(" \ncuon sach co gia ra nhat : ");
	Min(pHead,a);
	
	int x;
	printf("\nnhap ma cuon sach tim : ");
	scanf("%d",&x);
	Node* vt =timtuyentinh(pHead,x);
	if(vt == NULL )
	{
		printf(" phan tu (x=%d) khong co ton tai ");
	}
	else{
		printf("\n phan tu (x=%d) co to tai  ");
	}

	printf("\n--------TIM SACH TEN Y------- ");
	char y[40];
		printf("\nNhap ten sach can tim: ");
		fflush(stdin);								
		gets(y);
		TimY(pHead,a,y);
		
	
	return 0;
} 