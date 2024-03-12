/// Nguyen Ngoc Sang
///201108714
///nguyenngocsang1682@gmail.com
//// danh sach lien ket don vơi stack ,voi info =  int  
#include<stdio.h>
#include<conio.h>

typedef struct node
{ 
	int info; //// (data cung dc)
	node* pNext;	/// p=pointer
}Node;
typedef Node* NODEPTR;

struct stack 
{
	Node* pTop;
};
typedef stack STACK;

void init(STACK &s)
{
	s.pTop = NULL;
}
////////////////========

bool IsEmpty(STACK s)
 {
	 if(s.pTop == NULL ){
	 	return true;
	 } return false;
}

///====================
Node* createNode(int x)
{

	Node* p = new Node;
	if(p!= NULL)
	{
		p->info = x,
		p->pNext = NULL;
	}
	return p;
}
//=================them phan tu vao dau stack ===============]
bool  push(STACK &s , int x)
{
	Node* p = createNode(x);
	if(IsEmpty(s) == true){
		s.pTop = p;
	}
	else
	{
		p->pNext = s.pTop;
		s.pTop=  p;
	}
}
/////////===================================
Node* pop(STACK &s , int &x){
	if(IsEmpty(s)== true) {
		return NULL;
	}
	else
	{
		Node *p = s.pTop;
		x = p->info;
		s.pTop=s.pTop->pNext;
		delete p;
	return p;
}
}
/////////////===================================
bool top (STACK &s , int x)
{
	if(IsEmpty(s)== true){
		return false;
	}
	x=s.pTop->info;
	return true;
}
/////////=====================================
void inputstack(STACK &s)////////////////////napj vao toiws 0 laf duwngf
{
		int x, stt=1;
		do
		{
			printf(" nhap so nguyen thu %d: ",stt++);
			scanf("%d", &x );
			if(x!=0){
				push(s,x);
			}
		}while(x!=0);
}
//////////////=================
void outputStack(STACK s) {
	while (IsEmpty(s) == false) {
		int x;
		pop(s, x);
		printf("%d ", x);
	}
}
////////////=============================================
void menu(int &chon ){
	printf("\n\n=======MENU==============\n");
	printf("1- nhap bang stack\n");
	printf("2- xuat \n");
	printf("\n0- Exit\n");
	printf("=========================\n");
	printf("Ban chon chuc nang: ");
	scanf("%d", &chon);
}
int main()
{
	STACK s;  /// NODEPTR = node* pointet head
	init(s);
	int chon;
do{
		menu(chon);
		STACK s; 
		init(s);
		switch(chon)
		{
			case 1:
			 	printf("\n nhap phan tu (0 dung)\n"); 
				inputstack(s);
				break;
			case 2: 
				printf("\n noi dung moi nhap :\n");
				outputStack(s);	
				break;
			default: chon = 0;
		} 
}while(chon != 0);
	return 0;
} 