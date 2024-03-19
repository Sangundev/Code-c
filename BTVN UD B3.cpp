/// Nguyen Ngoc Sang
///201108714
///nguyenngocsang1682@gmail.

//// danh sach lien ket don ,voi info =  int  
#include<stdio.h>
#include<conio.h>
typedef struct SinhVien
{
	int masv;
	char tensv[40];
	float diem;
}SV;
typedef struct node
{ 
	SV info; //// (data cung dc)
	node* pNext;	/// p=pointer
}Node;

typedef Node* NODEPTR;
void nhap1SV(SV &x)
{
    printf("nhap ma sinh vien: ");
    scanf("%d",&x.masv);
    printf("nhap ten Sinh vien: ");
    fflush(stdin);  gets(x.tensv);
    printf("nhap gia cuon sach: ");
    scanf("%f",&x.diem);
}
//==========================================
void xuat1SV(SV x )
{
	printf("\n | %8d | %-40s | %.2f |", x.masv, x.tensv, x.diem);
}


void init(Node* &pHead)
{
	pHead = NULL;
}
////////////////========
void nhapsl(int &n)
{
	do{
		printf("\n\t nhap so luong sinh vien <100 : ");
		scanf("%d",&n);
		if(n<1 )  printf("nhap lai :" );
	}while (n<1 );
}
///====================
Node* createNode(SV x)
{

	Node* p = new Node;
	if( p!= NULL)
	{
		p->info = x,
		p->pNext = NULL;
	}
	return p;
}
//=================
void inserFirst(Node* &pHead,SV X)
{
	Node* p = createNode(X);
	p->pNext = pHead;
	pHead = p;
}
//////===================================
void inserLast(Node* &pHead,SV X){
	
	Node*p = createNode(X);
	if(pHead ==NULL)
	pHead = p ;
	else
	{
		//lap i->9( trc null)
		Node* i = pHead;
		while( i->pNext != NULL )
		 i=i->pNext	;
			
		i->pNext= p;	//ket noi p saou i
	}
}
////////////////////////========================================
//========================
void output(Node* pHead)
{
	if(pHead == NULL )    printf("danh sach rong ");
	for(Node* i = pHead ; i!= NULL; i=i->pNext )
		xuat1SV(i->info);
}
///==============================================
Node* timtuyentinh(Node* pHead, int key)
{
	Node* i = pHead;
	while (i!= NULL && key != i->info.masv)
	   i=i->pNext;
	   if(i!= NULL)  return i;
	   return NULL;
}
//////==================================
//
void swap(SV &x, SV &y)
{
	SV tmp = x;
	x = y;
	y = tmp;
}
void sapxeptang(Node* &pHead){           ////////////////// InterChangeSort_Inc
	for (Node* i = pHead; i->pNext !=NULL ; i=i->pNext)///i<n-1 = i->pNext !=NULL 
		for(Node*j = i->pNext ; j != NULL ; j=j->pNext)
			if(i->info.masv > j->info.masv )
				swap(j->info,i->info);	
	}
////////====================================================
void sapxepgiam_diem(Node* &pHead)
{
	for (Node* i = pHead; i->pNext !=NULL ; i=i->pNext){
		Node* vtmin = i;
		for(Node*j = i->pNext ; j !=NULL ; j=j->pNext)
			if(vtmin->info.diem < j->info.diem )
					vtmin = j;
				swap(vtmin->info,i->info);	
			}
	}
//=========================================================
int countnode(Node* pHead )
{
   	int count = 0;
	   if(pHead != NULL)
	   {
	   	for(Node*i = pHead ; i != NULL ; i=i->pNext)
					count ++;
		   } else {	
					printf(" danh sach rong ");	
  }
  		return count;
}
//=====================================================
Node* Max(Node* &pHead)
{
		Node* max = pHead;
	for(Node* i = pHead ; i!= NULL; i=i->pNext )
	{
		
		if(i->info.diem > max->info.diem)
			max = i;
						}
						
		return max;
}

///////======================================================
Node* Min(Node* pHead)
{		
	Node* min = pHead;
	for(Node* i = pHead->pNext; i!= NULL; i=i->pNext)
	{
		if(min->info.diem > i->info.diem)  
		{
			min = i;
		}
	}return min;
}
////////////////////////////===================
void inserAfterP(Node* &p,SV x)
{ 

  	if(p==NULL) return;

	Node* q = createNode(x);
	q->pNext = p->pNext ;
	p->pNext = q;
} 
void chensaumax(Node* &pHead)
{

	 SV x = {2011068812, "Nguyen Van B ", 		7.2} ;
	 Node* p = Max(pHead);
	 inserAfterP(p,x);
 }

/////////////===================================================
void deletefist( Node* &pHead){
	
	if(pHead == NULL)  return;
	
	Node* p = pHead;
	pHead = pHead->pNext; 
	delete (p);                   
}
//======================================================================
void deleteLast(Node* &pHead)
{
	if(pHead == NULL || pHead->pNext == NULL ) //// dslk co 1 node
	deletefist(pHead);
	else{
//		for(Node* i = pHead; i->pNext->pNext != NULL; i=i->pNext)
		Node* i = pHead;
		while(i->pNext->pNext != NULL)
		i=i->pNext;
		Node *p = i->pNext;
		i->pNext = NULL;
		delete(p);
	}
}
////============================================================
void deleteafterp(Node* &p)
{
	if(p == NULL || p->pNext == NULL)      return;    
	
	Node* q = p->pNext;
	p->pNext = q->pNext;
	delete(q);

}
//////////////////////=================================================
void deletep(Node* &pHead,Node* &p)
{
	if(p == NULL)      return;    
	if(p==pHead)  deletefist(pHead);
 	else{
 		swap(p->info,p->pNext->info);
 		deleteafterp(p);
	 }
}
//////////////////////====================================================
void xoatrung(Node* &pHead)
{
	for(Node* i = pHead; i->pNext !=NULL; i=i->pNext)
	{
		for(Node*j = i->pNext ; j !=NULL ; j=j->pNext)
		
		if(i->info.diem == j->info.diem){
		deletep(pHead,i);
		}
	}
}
/////////////////===============================================
void xoasn(Node* &pHead){
	
	Node *p= Min(pHead);
	deleteafterp(p);
}
////////////////////
void deleteall(Node* &pHead){
	
	while(pHead != NULL)
	deletefist(pHead);
}

////////////===================================================
void Auto_input(NODEPTR &pHead, SV a[], int n)
{
	
		SV x; 
		for(int i=0 ;i<n;i++){
			inserFirst(pHead , a[i]);
		}
}
///////=====================================================
void menu(int &chon)
{
	printf("\n _______________________________________________\n");
	printf("|                      \MENU/                    |\n");
	printf("|1-sap xep tang theo mssv (InterChangeSort)      |\n");
	printf("|2-sap xep giam theo diem (SelectionSort)        |\n");
	printf("|3-dem so sinh vien                              |\n");
	printf("|4-sinh vien co diem cao nhat                    |\n");
	printf("|5-sinh vien co diem thap nhat                   |\n");
	printf("|6-chen chen them sv x sau sv co diem lon nhat   |\n");
	printf("|7-them sv x o dau ds                            |\n");
	printf("|8-them sv x o cuoi ds                           |\n");
	printf("|9-xoa sv co diem trung nhau                     |\n");
	printf("|10-xoa sv o dau ds                              |\n");
	printf("|11-xoa sv o cuoi ds                             |\n");
	printf("|12-xoa sv x ngay sau sv co diem be nhat         |\n");
	printf("|13-xoa tat ca  sv                               |\n");
	printf("|14 tim sinh vien co masv x va xoa               |\n");
	printf("|15-liet ke sinh vien co diem >5                 |\n");
	printf("|0-                       Exit                   |\n");
	printf("|________________________________________________|\n");
	printf("Ban chon chuc nang: ");
	scanf("%d", &chon);
}
//=======================================================
void LKnode_i(Node* pHead )
{
	int x = 5;
	   if(pHead != NULL )
	   {
	   	for(Node*i = pHead ; i != NULL ; i=i->pNext)
	   			if(i->info.diem >= x)
					xuat1SV(i->info);
		   } else {	
					printf(" danh sach rong ");	
				}
}
/////////////////////////////=============================================
void tinh(Node* pHead){
	int d=0;
	int n;
	printf("\n so sv da co diem ");
	scanf("%d",&n);
	for (Node* i = pHead; i->pNext !=NULL ; i=i->pNext){
					 if(i->info.diem < n)
					 	xuat1SV(i->info);
				}
}
//=====================================================
int main()
{
	NODEPTR pHead ;
		SV a[10] =
		{
		//int masach;	char tensach[40];	float giasach;
		{2011068714, "Nguyen Van A ", 		5.7},
		{2011068716, "Le Thi B", 	        5.7},
		{2011068715, "Do Hieu H", 	        3.2},
		{2011068711, "Pham Thi T", 	        8.6},
		{2011068719, "Nguyen Ngoc Z",     	2.4},
		{2011068712, "Nguyen Ngoc K", 	 	1.4},
		{2011068713, "Doan Xuan N",      	8.4},
		{2011068717, "Pham Hoai L", 		4.2},
		{2011068718, "Nguyen Tan Q", 	    9.6},
		{2011068811, "Do Thi WE", 	        6.4}
	}; /// NODEPTR = node* pointet head
	int n = 10;
	
	init(pHead);
	
//	input(pHead);
	Auto_input(pHead, a, n);
	printf("\n noi dung moi nhap :\n");
	
	output(pHead);
	
	int x = 2011068714;
//	printf("\nnhap ma sinh vien can tim : ");
//	scanf("%d",&x);

	SV X = {2011068813, "Nguyen Van c ", 		5.2} ;
	
	int chon;
	Node* vt = NULL;
	do {
		menu(chon);
		switch(chon)
		{
			case 1: 
					printf("\n tang dan ");
						sapxeptang(pHead);
							output(pHead);
				break;
			case 2:
					printf("\n giam dan ");
						sapxepgiam_diem(pHead);
							output(pHead);
				break;
			case 3:
					printf("\n so sv dang co la %d ",countnode(pHead));
				break;
			case 4:
					printf(" \nsv co diem lon nhat : %d\n",Max(pHead)->info);
				break;
			case 5:
					printf(" \nsv co diem nho nhat : %d\n",Min(pHead)->info);
				break;
			case 6:
					printf("\n vua them 1 sv sau sv co diem lon nhat ");
						chensaumax(pHead);
							output(pHead);
				break;
			case 7:
					printf("\n vua them 1 sv o dau danh sach  ");
						inserFirst(pHead,X);
							output(pHead);
				break;
			case 8:
					printf("\n vua them 1 sv o cuoi danh sach  ");
						inserLast(pHead,X);
							output(pHead);
				
				break;
			case 9:
						printf("\n xoa sv co diem trung nhau  ");
							xoatrung(pHead);
							output(pHead);
				break;
			case 10:
						printf("xoa sinh vien dau danh sach \n");
							deletefist(pHead);
									output(pHead);
				break;
			case 11:
						printf("xoa sinh vien cuoi danh sach \n");
							deleteLast(pHead);
								output(pHead);
				break;
			case 12:
						
						printf("xoa sinh sau sinh vien co diem be nhat \n");
							xoasn(pHead);
								output(pHead);
				break;
			case 13:
					printf("xoa tat ca sinh vien  \n");
							deleteall(pHead);
								output(pHead);
				break;
			case 14:
					 vt =timtuyentinh(pHead,x);
						if(vt == NULL )
					{
							printf(" Sinh Vien co ma(x=%d) khong co ton tai ",x);
						}else{
								deletep(pHead,vt);
								output(pHead);
												}
				break;
			case 15:
						printf("\n so sv cos diem tren 5 ");
						LKnode_i(pHead);
				break;
			case 16:
						printf("\n so sv cos diem tren 5 ");
						tinh(pHead);
				break;
		default:
			break;
		}
	}while(chon != 0);
	
	return 0;
} 