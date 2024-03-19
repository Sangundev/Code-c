#include<stdio.h>
#include<conio.h>

typedef struct Node {
	int info;
	struct Node *pNext;
} Node;

typedef struct Queue {
	Node *pHead;
	Node *pTail;
} Queue;
typedef Queue QUEUE;

void Init(QUEUE &q)
{
	q.pHead = NULL;
	q.pTail = NULL;
}

Node* createNode(int x) {
	Node* p = new Node;
	if (p == NULL)
		return NULL;

	p->info = x;
	p->pNext = NULL;

	return p;
}

bool isEmpty(QUEUE p) {
	if (p.pHead == NULL) {
		return true;
	}
	return false;
}

void enQueue(QUEUE &p, int x) {
	Node *i = createNode(x);
	if (isEmpty(p) == true) {
		p.pHead = p.pTail = i;
	} else {
		p.pTail->pNext = i;
		p.pTail = i;
	}

}

Node* deQueue(QUEUE &p) {
	if (isEmpty(p) == true) {
		return NULL;
	}
	Node *i = p.pHead;
	p.pHead = p.pHead->pNext;
	return i;
}
void outputQueue(QUEUE p) {
	if(!isEmpty(p)) {
		for(Node *i = p.pHead; i != NULL; i=i->pNext) {
			printf("%d ", i->info);
		}
	} else {
		printf("- khong ton tai vui long chon lai !");
	}
}

void inputQueue(QUEUE &p)
{
		int x, stt=1;
			printf("\n Stop(_0_) \n");
		do
		{
			printf(" nhap so nguyen thu %d: ",stt++);
			scanf("%d", &x );
			if(x!=0){
				enQueue(p,x);
			}
		}while(x!=0);
}
void addQueue(QUEUE &p) {
	int x;
	printf("\n- nhap phan tu can them cuoi : ");
	scanf("%d", &x);
	enQueue(p,x);
}

void deleteHead(QUEUE &p) {
	deQueue(p);
	outputQueue(p);
}

int countQueue(QUEUE q) {
	int d = 0;
	if(!isEmpty(q)) {
		for(Node *i = q.pHead; i != NULL; i=i->pNext) {
			d++;
		}
	} else {
		printf("- khong ton tai vui long chon lai !");
	}
	return d;
}
void chuyenCoSo(int x) {
	
	QUEUE p;
	Init(p);
	printf("- Nhap So Thap Phan: ");
	scanf("%d", &x);
	while(x != 0) {
		int du = x % 2;
		enQueue(p,du);
		x = x / 2;
	}
	printf("- GT Nhi Phan:  ", x);
	outputQueue(p);
}
void menu(int &chon) {
	
		printf("\n ____________________________________\n");
		printf("|              \ MENU /               |\n");
		printf("|1. Nhap Danh Sach Queue             |\n");
		printf("|2. Xuat Danh Sach Queue             |\n");
		printf("|3. Them cuoi Mot Queue              |\n");
		printf("|4. Xoa Queue Dau Trong Danh Sach    |\n");
		printf("|5. Dem So Luong Phan Tu Trong Queue |\n");
		printf("|0.------------ ket thuc ------------|\n");
		printf("|____________________________________|\n");
		printf("Chon chuc nang : ");
		scanf("%d", &chon);

}

int main() {
	QUEUE q;
	Init(q);
	int chon ,x;
	printf("\t\t\t\t\t      __________________________\n");
	printf("\t\t\t\t\t     | Name: Nguyen Ngoc Sang   |\n");
	printf("\t\t\t\t\t     |     MSSV: 2011068714     |\n");
	printf("\t\t\t\t\t     |      Class: 20DTHC1      |\n");
	printf("\t\t\t\t\t     |__________________________|\n");
	printf("-================================================LOADING=================================================\n");

	do{
		menu(chon);
		switch(chon) {
			case 1:
				inputQueue(q);
				printf("\n");
				break;
			case 2:
				printf("\n");
				printf("\n- Xuat Danh Sach Queue: ");
				outputQueue(q);
				printf("\n\n");
				break;
			case 3:
				addQueue(q);
				printf("\n- Danh Sach Sau Khi Them cuoi : ");
				outputQueue(q);
				printf("\n\n");
				break;
			case 4:
				printf("\n\n- Danh Sach Sau Khi Xoa dau : ");
				deleteHead(q);
				printf("\n\n");
				break;
			case 5:
				printf("\n\n");
				printf("\n- So Luong phan tu Trong Danh Sach: %d", countQueue(q));
				printf("\n\n");
				break;
			case 0:
				printf("\n -------------- END ----------------!");
			default:
				break;

		}
	} while(chon!=0);
		
	return 0;
}
