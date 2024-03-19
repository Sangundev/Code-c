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

bool isEmpty(QUEUE q) {
	if (q.pHead == NULL) {
		return true;
	}
	return false;
}

void enQueue(QUEUE &q, int x) {
	Node *p = createNode(x);
	if (isEmpty(q) == true) {
		q.pHead = q.pTail = p;
	} else {
		q.pTail->pNext = p;
		q.pTail = p;
	}

}

Node* deQueue(QUEUE &q) {
	if (isEmpty(q) == true) {
		return NULL;
	}
	Node *p = q.pHead;
	q.pHead = q.pHead->pNext;
	return p;
}
void outputQueue(QUEUE q) {
	if(!isEmpty(q)) {
		for(Node *i = q.pHead; i != NULL; i=i->pNext) {
			printf("%d ", i->info);
		}
	} else {
		printf("- khong ton tai vui long chon lai !");
	}
}

void inputQueue(QUEUE &q)
{
		int x, stt=1;
			printf("\n Stop(_0_) \n");
		do
		{
			printf(" nhap so nguyen thu %d: ",stt++);
			scanf("%d", &x );
			if(x!=0){
				enQueue(q,x);
			}
		}while(x!=0);
}
void addQueue(QUEUE &q) {
	int x;
	printf("\n- nhap phan tu can them cuoi : ");
	scanf("%d", &x);
	enQueue(q,x);
}

void deleteHead(QUEUE &q) {
	deQueue(q);
	outputQueue(q);
}

int countQueue(QUEUE q) {
	int d = 0;
	if(!isEmpty(q)) {
		for(Node *p = q.pHead; p != NULL; p=p->pNext) {
			d++;
		}
	} else {
		printf("- khong ton tai vui long chon lai !");
	}
	return d;
}
void menu() {
	QUEUE q;
	Init(q);
	int chon;
	do {
		printf("\n ____________________________________\n");
		printf("|              - MENU -              |\n");
		printf("|1. Nhap Danh Sach Queue             |\n");
		printf("|2. Xuat Danh Sach Queue             |\n");
		printf("|3. Them cuoi Mot Queue              |\n");
		printf("|4. Xoa Queue Dau Trong Danh Sach    |\n");
		printf("|5. Dem So Luong Phan Tu Trong Queue |\n");
		printf("|0.------------ ket thuc ------------|\n");
		printf("|____________________________________|\n");
		printf("Chon chuc nang : ");
		scanf("%d", &chon);
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
}
void tt() {
	printf("\t\t\t\t\t      __________________________\n");
	printf("\t\t\t\t\t     | Name:  |\n");
	printf("\t\t\t\t\t     |     MSSV:      |\n");
	printf("\t\t\t\t\t     |      Class: 20DTHC1      |\n");
	printf("\t\t\t\t\t     |__________________________|\n");
	printf("-================================================LOADING=================================================\n");
}
int main() {
	tt();
	menu();
	return 0;
}
