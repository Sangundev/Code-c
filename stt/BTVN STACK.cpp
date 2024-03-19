#include<stdio.h>
#include<conio.h>

typedef struct Node {
	int info;
	struct Node *pNext;
} Node;

typedef struct Stack {
	Node *pTop;
} Stack;
typedef Stack STACK;

void Init(STACK &s) {
	s.pTop = NULL;
}

bool IsEmpty(STACK s) {
	if (s.pTop == NULL) {
		return true;
	}
	return false;
}

Node* createNode(int x) {
	Node* p = new Node;
	if (p == NULL)
		return NULL;

	p->info = x;
	p->pNext = NULL;

	return p;
}

void Push(STACK &s, int info) {
	Node *p = createNode(info);
	if (IsEmpty(s) == true) {
		s.pTop = p;
	} else {
		p->pNext = s.pTop;
		s.pTop = p;
	}
}

Node* Pop(STACK &s) {
	if (IsEmpty(s) == true) {
		return NULL;
	}
	Node *p = s.pTop;
	s.pTop = s.pTop->pNext;
	return p;
}

void outputStack(STACK s) {
	if(!IsEmpty(s)) {
		for(Node *i = s.pTop; i != NULL; i=i->pNext) {
			printf("%d ", i->info);
		}
	} else {
		printf(" ko ton tai phan tu !");
	}
}
void inputStack(STACK &s)
{
		int x, stt=1;
			printf("\n Stop(_0_) \n");
		do
		{
			printf(" nhap so nguyen thu %d: ",stt++);
			scanf("%d", &x );
			if(x!=0){
				Push(s,x);
			}
		}while(x!=0);
}
void addStack(STACK &s) {
	int x;
	printf("\n nhap phan tu can them : ");
	scanf("%d", &x);
	Push(s,x);
}
void deleteHead(STACK &s) {
	Pop(s);
	outputStack(s);
}
int countStack(STACK s) {
	int dem = 0;
	if(!IsEmpty(s)) {
		for(Node *i = s.pTop; i != NULL; i=i->pNext) {
			dem++;
		}
	} else {
		printf("- khoong ton tai phan tu nay !");
	}
	return dem;
}
void chuyenCoSo(int x) {
	
	Stack s;
	Init(s);
	printf("- Nhap So Thap Phan: ");
	scanf("%d", &x);
	while(x != 0) {
		int du = x % 2;
		Push(s, du); 
		x = x / 2;
	}
	printf("- GT Nhi Phan:  ", x);
	outputStack(s);
}
void menu(int &chon) 
{
		printf("\n __________________________________\n");
		printf("|              \ MENU /               |\n");
		printf("|1. Nhap bang Stack                  |\n");
		printf("|2. Xuat bang Stack                  |\n");
		printf("|3. Them mot phan tu dau Stack       |\n");
		printf("|4. Xoa Stack Dau Trong Danh Sach    |\n");
		printf("|5. Dem So Luong Phan Tu Trong Stack |\n");
		printf("|6.chuyen doi co so sang he nhi phan |\n");
		printf("|0. -----------ket thuc--------------|\n");
		printf("|____________________________________|\n");
		printf("Chon chuc nang : ");
		scanf("%d", &chon);
}

int main() 
{
	
	STACK s;
	Init(s);
	int chon, x;
	
	printf("\t\t\t\t\t      __________________________\n");
	printf("\t\t\t\t\t     | Name: Nguyen Ngoc Sang   |\n");
	printf("\t\t\t\t\t     |     MSSV: 2011068714     |\n");
	printf("\t\t\t\t\t     |      Class: 20DTHC1      |\n");
	printf("\t\t\t\t\t     |__________________________|\n");
	printf("--------------------------------------------------LOADING----------------------------------------------\n");
	
	
	do{
		menu(chon);
		switch(chon) 
		{	
			case 1:
				inputStack(s);
				printf("\n");
				break;
			case 2:
				printf("\n");
				printf("\n- Danh Sach vua nhap bang Stack: ");
				outputStack(s);
				printf("\n\n");
				break;
			case 3:
				addStack(s);
				printf("\n- Danh Sach Sau Khi Them dau: ");
				outputStack(s);
				printf("\n\n");
				break;
			case 4:
				printf("\n\n- Danh Sach Sau Khi Xoa dau : ");
				deleteHead(s);
				printf("\n\n");
				break;
			case 5:
				printf("\n\n");
				printf("\n- So Luong Stack Trong Danh Sach: %d", countStack(s));
				printf("\n\n");
				break;
			case 6:
					chuyenCoSo(x);	
				break;
			case 0:
				printf("\n\___________----AND----_______________ !");
			default:
				break;
		}
	} while(chon!=0);
	return 0;
}
