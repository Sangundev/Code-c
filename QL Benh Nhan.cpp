#include<stdio.h>
#include<conio.h>

typedef struct BenhNhan {
	int stt;
	char hoten[40];
	int tuoi;
} BN;

typedef struct Node {
	BN info;
	struct Node *pNext;
} Node;
typedef Node NODE;

typedef struct Queue {
	Node *pHead;
	Node *pTail;
	int dem;
} Queue;
typedef Queue QUEUE;

void Init(QUEUE &p) {
	p.pHead = p.pTail= NULL;
	p.dem = 0;
}

Node* createNode(BN x) {
	Node* p = new Node;
	if (p == NULL)
		return NULL;

	p->info = x;
	p->pNext = NULL;
	return p;
}

void enQueue(QUEUE &p, BN x) {
	Node *i = createNode(x);
	if (p.pHead == NULL ) {
		p.pHead = p.pTail = i;
	} else {
		p.pTail->pNext = i;
		p.pTail = i;
	}
}


Node* deQueue(QUEUE &p) {
	if (p.pHead == NULL) {
		return NULL;
	}
	Node *i = p.pHead;
	p.pHead = p.pHead->pNext;
	p.dem+=1;
		
	return i;
}

int dem(QUEUE p) {
	return p.dem;
}
void nhap1BN(BN &x) {
	printf("\n");
	printf("- Nhap stt: ");
	scanf("%d",&x.stt);
	printf("- Nhap ho va ten: ");
	fflush(stdin); 	gets(x.hoten);
	printf("- Nhap tuoi: ");
	scanf("%d",&x.tuoi);
}
void xuat1BN(BN x) {
	printf("\n| %8d | %-40s | %.2d | ", x.stt, x.hoten, x.tuoi);
}
void Input(QUEUE &p) {
	BN x;
	nhap1BN(x);
	Node *i = createNode(x);
	enQueue(p,x);
}

void xuatDS(QUEUE p) {
	if(p.pHead != NULL ) {
		for(Node* i = p.pHead ; i != NULL; i=i->pNext ) {
			xuat1BN(i->info);
		}
	}	else {
		printf("\n- rong !");
	}
	printf("\n");
}
void pTop(QUEUE p) {
	if(p.pHead != NULL) {
		Node *i = p.pHead;
		xuat1BN(i->info);
	}	else {
		printf("\n- rong !");
	}
}

int BNchuakham(QUEUE p) {
	int d = 0;
	if(p.pHead != 0 ) {
		for(Node* i = p.pHead ; i != NULL; i=i->pNext ) {
			d++;
		}
	}
	printf("\n");
	return d;
}

void tt(Queue &p) {
	if(p.pHead != NULL ) {
		pTop(p);
		deQueue(p);
	}	else {
		printf("\n- rong !\n");
	}
}

void Auto_input(QUEUE &p , BN a[], int n)
{
	
		BN x; 
		for(int i=0 ;i<n;i++){
			enQueue(p , a[i]);
		}
}

void menu(int &chon) {

		printf("\n============MENU=================== ");
		printf("\n1. Nhap 1 Benh Nhan.               ");
		printf("\n2. Benh Nhan Kham Tiep Theo        "); 
		printf("\n3. Benh Nhan Da Kham Roi.          ");
		printf("\n4. Benh Nhan Chua Kham.            ");
		printf("\n5. Danh Sach Benh Nhan Chua Kham.  ");
		printf("\n0. ============exit================\n");
		printf("- nhap su lua chon : ");
		scanf("%d", &chon);
}

int main(){
	
	QUEUE p;
	Init(p);
	BN a[10] =
		{
		{1, "Nguyen Van A ", 		25},
		{2, "Le Thi B", 	        57},
		{3, "Do Hieu H", 	        32},
		{4, "Pham Thi T", 	        86},
		{5, "Nguyen Ngoc Z",     	24},
		{6, "Nguyen Ngoc K", 	 	18},
		{7, "Doan Xuan N",      	82},
		{8, "Pham Hoai L", 		    42},
		{9, "Nguyen Tan Q", 	    96},
		{10, "Do Thi WE", 	        64}
	}; 
	int n = 10;
	
	Auto_input(p,a,n);
	xuatDS(p);
		
		
	int chon; 
	do{
		menu(chon);
		switch(chon)
		{
			case 1:
				printf("\n NHAP BENH NHAN :\n ");
				Input(p);
					xuatDS(p);
				break;
			case 2:
				printf("\n  - BENH NHAN KHAM TIEP THEO -");
				tt(p);
				break;
			case 3:
				printf("\n- So BN  Da Kham la:\n %d Benh Nhan.\n", dem(p));
				break;
			case 4:
				printf("- So BN Chua Kham : %d\n Benh Nhan.\n", BNchuakham(p));
				break;
			case 5:
				printf("\n- DANH SACH BENH NHAN CHUA KHAM -\n");
				xuatDS(p);
				break;
			case 0:
				printf("\n- exit !\n");
				break;
		}
			} while(chon!=0);
	
	return 0;
}

