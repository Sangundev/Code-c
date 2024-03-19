#include <bits/stdc++.h>
#include <unistd.h>
typedef struct Node {
	int info;
	Node *Left;
	Node *Right;
	int height;
} Node;

void Init(Node *&root) {
	root = NULL;
}
Node *createNode(int x) {
	Node *p = new Node;
	if (p == NULL)
		return NULL;

	p->info = x;
	p->Left = NULL;
	p->Right = NULL;
	p->height = 1;
	return p;
}

bool isEmpty(Node *root) {
	if (root == NULL) {
		return true;
	}
	return false;
}
int getHight(Node *root) {
	if (isEmpty(root) == true)
		return 0;
	return root->height;
}

int balanceFactor(Node *&root) {
	if (isEmpty(root) == true)
		return 0;
	return getHight(root->Left) - getHight(root->Right);
}
int getMax(int a, int b) {
	return a > b ? a : b;
}
bool checkAVL(Node *root) {
	if(isEmpty(root) == true)
		return true;
	if(abs(balanceFactor(root)) > 1)
		return true;
	return false;
}
void getCheck(Node *root) {
	if(!isEmpty(root)) {
		if (!checkAVL(root)) {
			printf("- La Cay AVL !\n");
		} else {
			printf("- Khong Phai Cay AVL !\n");
		}
	} else {
		printf("- Danh Sach Rong !\n");
	}
}
Node *rotateLeft(Node *&root) {
	if (isEmpty(root) == true)
		return NULL;
	if (root->Right == NULL)
		return NULL;

	Node *pivot = root->Right;
	root->Right = pivot->Left;
	pivot->Left = root;
	root->height = 1 + getMax(getHight(root->Right), getHight(root->Left));
	pivot->height = 1 + getMax(getHight(pivot->Right), getHight(pivot->Left));
	return pivot;
}

Node *rotateRight(Node *&root) {
	if (isEmpty(root) == true)
		return NULL;
	if (root->Left == NULL)
		return NULL;

	Node *pivot = root->Left;
	root->Left = pivot->Right;
	pivot->Right = root;
	root->height = 1 + getMax(getHight(root->Right), getHight(root->Left));
	pivot->height = 1 + getMax(getHight(pivot->Right), getHight(pivot->Left));
	return pivot;
}

Node *balance(Node *&root) {
	if (balanceFactor(root) < -1) {
		if (balanceFactor(root->Right) > 0) {
			root->Right = rotateRight(root->Right);
		}
		root = rotateLeft(root);
	} else if (balanceFactor(root) > 1) {
		if (balanceFactor(root->Left) < 0) {
			root->Left = rotateLeft(root->Left);
		}
		root = rotateRight(root);
	}
	return root;
}

Node *Insert(Node *&root, int x) {
	if (isEmpty(root) == true) {
		Node *p = createNode(x);
		root = p;
	} else {
		if (x < root->info) {
			root->Left = Insert(root->Left, x);
		} else if (x > root->info) {
			root->Right = Insert(root->Right, x);
		}
	}
	root->height = 1 + getMax(getHight(root->Left), getHight(root->Right));
	return root;
}
Node *InsertAVL(Node *&root, int x) {
	Insert(root,x);
	return balance(root);
}
void Input(int a[], int &n) {
	printf("- Nhap SL: ");
	scanf("%d", &n);
	system("cls");
	for (int i = 0; i < n; i++) {
		printf("- Input (%d): ", i+1);
		scanf("%d", &a[i]);
		system("cls");
	}
}
void xuatArray(int a[], int n) {
	printf("- Array: ");
	for (int i = 0; i < n; i++) {
		printf("%d  ", a[i]);
	}
}
void makeAVL1(Node *&root, int a[], int n) {
	for (int i = 0; i < n; i++) {
		InsertAVL(root, a[i]);
	}
}
void makeAVL2(Node *&root, int a[], int n) {
	for (int i = 0; i < n; i++) {
		Insert(root, a[i]);
	}
}

void NLR(Node *root) {
	if (!isEmpty(root)) {
		printf("%d  ", root->info);
		NLR(root->Left);
		NLR(root->Right);
	}
}
void LNR(Node *root) {
	if (!isEmpty(root)) {
		LNR(root->Left);
		printf("%d  ", root->info);
		LNR(root->Right);
	}
}
void LRN(Node *root) {
	if (!isEmpty(root)) {
		LRN(root->Left);
		LRN(root->Right);
		printf("%d  ", root->info);
	}
}
void create_BTS(Node* &pRoot, int a[],int n)
{
	for(int i=0 ;i<n;i++)
	Insert(pRoot,a[i]);
}
int chieucao(Node* pRoot){
   if(pRoot == NULL )
       return 0;

    int a = chieucao(pRoot->Left);
    int b = chieucao(pRoot->Right);
    if(a > b)
        return 1 + a;
    return 1 + b;
}
///////================================================
void Nodek(Node*pRoot, int k)
{
	if(pRoot != NULL)
	{
		k--;
		Nodek(pRoot->Left,k);
		if(k==0)   printf("%6d",pRoot->info);
		Nodek(pRoot->Right,k);
	}	
}
/////===========================================================
Node * minValueNode(Node* p) {
	Node* current = p;
	while (current && current->Left != NULL)
		current = current->Left;
	return current;
}
///================================================
Node * removeNode(Node *&root, int x) {
	if (root == NULL)
		return root;
	if (root->info > x)
		root->Left = removeNode(root->Left, x);
	else if (root->info < x)
		root->Right = removeNode(root->Right, x);
	else {

		if (root->Left == NULL) {
			Node *temp = root->Right;
			delete root;
			return temp;
		} else if (root->Right == NULL) {
			Node *temp = root->Left;
			delete root;
			return temp;
		}
		Node *temp = minValueNode(root->Right);
		root->info = temp->info;
		root->Right = removeNode(root->Right, temp->info);
	}
	if (root == NULL)
		return root;
	root->height = 1 + getMax(getHight(root->Left), getHight(root->Right));
	return balance(root);
}
void menu() {
	Node *root;
//	int a[100];
	int a[]= {18, 24, 14, 28, 16, 20, 10, 22, 12, 26};
	int n = 10,c,i,x ;
	Init(root);
	int chon;
	do {
		printf("\n __________________________________");
		printf("\n|             - MENU -             |");
		printf("\n|1. Nhap Du Lieu                   |");
		printf("\n|2. Xuat Du Lieu Theo Array        |");
		printf("\n|3. Xuat Du Lieu Theo LNR, NLR, LRN|");
		printf("\n|4. Kiem Tra AVL                   |");
		printf("\n|5. xac dinh bat va ve cay         |");
		printf("\n|6. xoa node                       |");
		printf("\n|0. Thoat                          |");
		printf("\n|__________________________________|");
		printf("\n- Thuc Hien: ");
		scanf("%d", &chon);
		system("cls");
		switch (chon) {
			case 1:
				Input(a, n);
				break;
			case 2:
				xuatArray(a, n);
				printf("\n");
				break;
			case 3:
				makeAVL1(root, a, n);
				printf("- NLR: ");
				NLR(root);
				printf("\n");
				printf("- LNR: ");
				LNR(root);
				printf("\n");
				printf("- LRN: ");
				LRN(root);
				printf("\n");
				break;
			case 4:
				makeAVL2(root,a,n);
				getCheck(root);
				break;
			case 5://Chieu cao cua BST
				create_BTS(root,a,n);
				c = chieucao(root);
				printf("chieu cao cua cay la : %d",c);
				for(i =1 ; i<= c ;i++){
					printf("\nLEVEL %d :",i);
					Nodek(root,i);
				}
			break;
			case 6: /// xoa node
					create_BTS(root,a,n);
					printf("\nNhap node:");
					scanf("%d", &x);
					removeNode(root,x);
				for(i =1 ; i<= c ; i++) {
					printf("\nLEVER %d :",i);
					Nodek(root,i);
				}
			default:
				printf("\nVui Long Nhap Lai !\n");
				break;
			case 0:
				break;
		}
	} while (chon != 0);
}
int main() {
	menu();
	return 0;
}
