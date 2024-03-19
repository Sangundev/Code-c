#include<bits/stdc++.h>
#include <unistd.h>
#include <conio.h>
typedef struct Node {
	int info;
	Node *Left;
	Node *Right;
} Node;

Node *createNode(int x) {
	Node *p = new Node;
	if(p == NULL) {
		return NULL;
	}
	p->info = x;
	p->Left = NULL;
	p->Right = NULL;
	return p;
}

void Init(Node* &root) {
	root = NULL;
}

bool isEmpty(Node* root) {
	if (root == NULL) {
		return true;
	}
	return false;
}

void Insert(Node* &root, int x) {
	if(isEmpty(root) == true) {
		Node* p = createNode(x);
		root = p;
	} else {

		if (x == root->info)
			return;

		if (x < root->info)
			Insert(root->Left, x);

		else
			Insert(root->Right, x);
	}
}

void nhapMang(int a[], int &n) {
	printf("- Nhap SL: ");
	scanf("%d", &n);
	printf("\n");
	for(int i = 0; i < n; i++) {
		printf("- Input: ");
		scanf("%d", &a[i]);
	}
	system("cls");
}

void xuatMang(int a[], int n) {
	printf("- Output Array: ");
	for(int i = 0; i < n; i++)
		printf("%4d", a[i]);
	printf("\n");
}

void makeTree(Node* &root, int a[], int n) {
	for(int i = 0; i < n; i++) {
		Insert(root,a[i]);
	}
}

void NLR(Node* root) {
	if (!isEmpty(root)) {
		printf("%4d", root->info);
		NLR(root->Left);
		NLR(root->Right);
	}
}

void LNR(Node* root) {
	if (!isEmpty(root)) {
		LNR(root->Left);
		printf("%4d", root->info);
		LNR(root->Right);
	}
}
void LRN(Node* root) {
	if (!isEmpty(root)) {
		LRN(root->Left);
		LRN(root->Right);
		printf("%4d", root->info);
	}
}
Node* search(Node* root, int x) {
	if (isEmpty(root) == true) {
		return NULL;
	} else {
		if(root->info > x) {
			search(root->Left, x);
		} else if(root->info < x) {
			search(root->Right, x);
		} else {
			return root;
		}
	}
}
void searchTree(Node* root) {
	int x;
	printf("- Nhap Gia Tri Can Tim Kiem: ");
	scanf("%d", &x);
	Node* p = search(root, x);
	if(p == NULL) {
		printf("\n- %d Khong Ton Tai Trong Cay", x);
	} else {
		printf("\n- %d Co Ton Tai Trong Cay", x);
	}
}
int doSau(Node* root) {
	int a = 0;
	int b = 0;
	if(!isEmpty(root)) {
		for(Node *i = root->Left; i != NULL; i=i->Left) {
			a++;
		}
		for(Node *i = root->Right; i != NULL; i=i->Right) {
			b++;
		}
	}
	int count = a>b ? a:b;
	return count;
}



void menu() {
	Node* root;
	int a[100];
	int n;
	Init(root);
	int chon;
	do {
		printf("\n ____________________________________");
		printf("\n|              - MENU -              |");
		printf("\n|1. Nhap Du Lieu Vao Tree.           |");
		printf("\n|2. Xuat Danh Sach Mang.             |");
		printf("\n|3. Xuat Du Lieu Theo LNR, NLR, LRN. |");
		printf("\n|4. Tim Gia Tri Node Trong Tree.     |");
		printf("\n|5. Dem Muc Cua Tree.                |");
		printf("\n|0. Thoat Chuong Trinh.              |");
		printf("\n|____________________________________|\n");
		printf("- Case: ");
		scanf("%d", &chon);
		system("cls");
		switch(chon) {
			case 1:
				nhapMang(a,n);
				printf("\n");
				break;
			case 2:
				xuatMang(a,n);
				printf("\n");
				break;
			case 3:
				makeTree(root,a,n);
				printf("- LNR: ");
				LNR(root);
				printf("\n");
				printf("- NLR: ");
				NLR(root);
				printf("\n");
				printf("- LRN: ");
				makeTree(root,a,n);
				LRN(root);
				printf("\n");
				break;
			case 4:
				makeTree(root,a,n);
				searchTree(root);
				break;
			case 5:
				makeTree(root,a,n);
				printf("%d", doSau(root));
				break;
			default:
				printf("- Xin Vui Long Nhap Lai\n");
				break;
			case 0:
				break;
		}
	} while(chon!=0);
}

int main() {
	system("color 7C");
	menu();
	return 0;
}
