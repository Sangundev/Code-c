/// Nguyen Ngoc Sang
///201108714
///nguyenngocsang1682@gmail.

//// danh sach lien ket don ,voi info =  int  
#include<stdio.h>
#include<conio.h>
#include<math.h>

typedef struct node
{ 
	int data; //// (data cung dc)
	node* pNext;	/// p=pointer
}Node;

typedef Node* NODEPTR;


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
Node* createNode(int x)
{

	Node* p = new Node;
	if(p!= NULL)
	{
		p->data = x,
		p->pNext = NULL;
	}
	return p;
}
//=================
void inserFirst(Node* &pHead,int x)
{
	Node* p = createNode(x);
	p->pNext = pHead;
	pHead = p;
}

//========================
void input(Node* &pHead)
{		
		int n; nhapsl(n);
		int x; 
		
		for(int i=0 ;i<n;i++)
		{
			printf(" nhap so nguyen thu %d: ",i+1);
			scanf("%d", &x );
			inserFirst(pHead, x);
		}
}

void output(Node* pHead)
{
	for(Node* i = pHead ; i!= NULL; i=i->pNext )
			printf("%4d",i->data);
}

///=//================================================
void insertfist(Node* pHead, int x)
{
	Node* p= createNode(x);
	if(pHead==NULL)
	{
		pHead=p;
	}
	else{
		p->pNext=pHead;
		pHead=p;
	}
}
//////==============================================
Node* timtuyentinh(Node* pHead,int key)
{	Node* i= pHead ;
	while (i != NULL && key != i->data )
	   i=i->pNext;
	   if(i!= NULL)  return i;
	   return NULL;
}

////==========================================
 int demsl(Node* pHead)
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
///////////////////////////////=============
int  demle(Node* pHead)
{
	int dem=0;
		for(Node* i = pHead ; i!= NULL; i=i->pNext )
				if(i->data %2!=0)
				dem++;
			return dem;	
}
//////////======================================
int  demchan(Node* pHead)
{
	int dem=0;
		for(Node* i = pHead ; i!= NULL; i=i->pNext )
				if(i->data %2 ==0)
				dem++;
			return dem;	
}
/////========================================
int Max(Node* pHead)
{
	Node *p=pHead;
	int max ;
	max=pHead->data;
	while(p!=NULL){
		if(max<p->data){
			max=p->data;
		}
		p=p->pNext;
	}return max;
}

//////======================================
int Min(Node* pHead)
{
	Node *p=pHead;
	int min ;
	min=pHead->data;
	while(p!=NULL){
		if(min>p->data){
			min=p->data;
		}
		p=p->pNext;
	}return min;
}	
/////=======================================
void swap(int &x, int &y)
{
	int tmp = x;
	x = y;
	y = tmp;
}
void sapxepgiam(Node* &pHead){
	for (Node* i = pHead; i->pNext !=NULL; i=i->pNext)///i<n-1 = i->pNext !=NULL 
		for(Node*j = i->pNext ; j != NULL ; j=j->pNext)
			if(i->data < j->data)
				swap(j->data,i->data);	
}
////=========================================
void deleteX(Node* pHead)
{
	Node *p=pHead;
	if(p==NULL || pHead->pNext == NULL){
		printf(" \nkhong tim thay nut xoa\n ");
	}else{
		p = pHead->pNext;
		pHead->pNext=p->pNext;
		delete p;
	}
}
//=====================================================

////================================================
long tongchan(Node* pHead)
{
	int s=0;
		for(Node* i = pHead ; i!= NULL; i=i->pNext )
				if(i->data %2==0)
				s=s+i->data;
			return s;	
}
//////===============================================
long tongle(Node* pHead)
{
	int s=0;
		for(Node* i = pHead ; i!= NULL; i=i->pNext )
				if(i->data %2!=0)
				s=s+i->data;
			return s;	
}
////====================================================
long tong(Node* pHead)
{
	int s=0;
		for(Node* i = pHead ; i!= NULL; i=i->pNext )
				s=s+i->data;
			return s;	
}
//=====================================================
	
///===================================================
int main()
{
	NODEPTR pHead ; /// NODEPTR = node* pointet head
	
	init(pHead);
	input(pHead);
	printf("\n mang vua moi nhap la :\n ");
	output(pHead);
	int chon ,tieptuc;
	int a;
	int x;
	printf("\n------cac chuc nang--------\n");
	printf("1-xoa so bat ki\n ");
	printf("2-sap xep giam dan\n ");
	printf("3-so luon phan tu trong mang\n ");
	printf("4-so luong phan tu le\n ");
	printf("5-so luong phan tu chan\n");
	printf("6-min \n");
	printf("7-max\n ");
	printf("8-tong chan\n");
	printf("9-tong le \n");
	printf("10-tong mang\n ");
	printf("11-kiem tra tuyen tinh\n ");
	printf("moi chon\n");
do{
	printf("\n chon chu nang : ");       scanf("%d",&chon);

		switch (chon)
		{
//				case 0 :
//					input(pHead);
//					break;
//				case 1 :
//					printf("\n mang vua moi nhap la :\n ");
//					output(pHead);
//			 	break;			
				case 1 :
					printf("\nnhap so can xoa : ");
					scanf("%d",&a);
					deleteX(pHead);
					printf("\n mang cua moi xoa \n ");	
					output(pHead);
			 	break;
				case 2 :
					printf("\n giam dan \n ");
					sapxepgiam(pHead);
					output(pHead);
			 	break;
			   case 3:
			   		printf("\n so luong phan tu trong mang la:%d",demsl(pHead));
			   	break;
			   	case 4:
			   		printf("\n so luong phan tu le trong mang la:%d",demle(pHead));	
			   	break;
			   	case 5:
			   		printf("\n so luong phan tu chan trong mang la:%d",demchan(pHead));
			   	break;
			   	case 6:
			   		printf("\n phan tu lon nhat trong mang la:%d",Min(pHead));
			   		break;
				case 7: 
					printf("\n phan tu lon nhat trong mang la:%d",Max(pHead));
				break;
				case 8:
					printf("\n tong phan tu chan trong mang la:%d",tongchan(pHead));
				break;
				case 9:
					printf("\n tong phan tu le trong mang la:%d",tongle(pHead));
				break;
				case 10:
					printf("\n tong phan tu  trong mang la:%d",tong(pHead));
				break;
				case 11:
						printf("\nnhap phan tu can tim : ");
						scanf("%d",&x);
						Node* vt =timtuyentinh(pHead,x);
						if(vt == NULL )
						{
							printf(" phan tu (x=%d) khong co ton tai ");
						}
						else{
							printf("\n phan tu (x=%d) co ton tai  ");
						}
							break;
			 	printf(" ----------------ket thuc -------------");
		}
		 printf(" \nban co muon chay tiep tuc khong :(1=co ,2 = khong ) : ");
		 scanf("%d",&tieptuc);
	}while(tieptuc==1);
	return 0;         
	//	printf("\nnhap so can xoa : ");
//	scanf("%d",&a);
//	deleteX(pHead);
//	printf("\n mang cua moi xoa \n ");	
//	output(pHead);
//	
//	printf("\n giam dan \n ");
//	sapxepgiam(pHead);
//	output(pHead);
	
//	printf("\n so luong phan tu trong mang la:%d",demsl(pHead));
//	
//	printf("\n so luong phan tu le trong mang la:%d",demle(pHead));
//	
//	printf("\n so luong phan tu le trong mang la:%d",demchan(pHead));
//	
//	printf("\n phan tu lon nhat trong mang la:%d",Max(pHead));
//	
//	printf("\n tong phan tu chan trong mang la:%d",tongchan(pHead));
//	
//	printf("\n tong phan tu le trong mang la:%d",tongle(pHead));
//	
//	printf("\n tong phan tu  trong mang la:%d",tong(pHead));
//
//	printf("\nnhap phan tu can tim : ");
//	scanf("%d",&x);
//	Node* vt =timtuyentinh(pHead,x);
//	if(vt == NULL )
//	{
//		printf(" phan tu (x=%d) khong co ton tai ");
//	}
//	else{
//		printf("\n phan tu (x=%d) co ton tai  ");
//	}
} 