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

void enQueue( int x,QUEUE &p) {
	Node *i = createNode(x);
	if (isEmpty(p) == true) {
		p.pHead = p.pTail = i;
	} else {
		p.pTail->pNext = i;
		p.pTail = i;
	}

}

int deQueue(QUEUE &p,int &x) {
	if (isEmpty(p) == true) {
		return NULL;
	}
	Node *i = p.pHead;
	p.pHead = p.pHead->pNext;
	x=i->info;
	return 1;
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

void nhapn(int &n)
{
	do{
		printf("\n\t nhap n so ng duong DECIMAL <100 : ");
		scanf("%d",&n);
		if(n<1 )  printf("nhap lai :" );
	}while (n<1 );
}

void convert(int n, QUEUE &s , int coso)///////chuyen co so 
{
	while(n!= 0)
	{
		int sodu=n%coso;
		enQueue(sodu,s); /////////////////////////////n%2 ,s
		n=n/coso;
	}
	printf(" gia tri(GHI NGUOC LAI ) : ");
}
void output(QUEUE &s)
{
	int x;
	 while( !isEmpty(s) )
	 {
	 	deQueue(s,x);
	 	if(x>9)    printf("%c",'A'+x - 10);
		 else printf("%4d",x);
	 }	
}

int main() {
	QUEUE s;
	Init(s);
	
	int n,coso;
	nhapn(n);

	printf(" nhsp co so (2/8/16): ");     scanf("%d",&coso);
	convert(n,s,coso);
	output(s);
	return 0;
}
