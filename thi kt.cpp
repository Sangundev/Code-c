#include<stdio.h>
#include<conio.h>
#include<bits/stdc++.h>
#include <unistd.h>
typedef struct node
{ 
	int info; //// (data cung dc)
	node* pLeft;
	node* pRight;	/// p=pointer
}Node;
typedef Node* NODEPTR;

///===============================================================================
void init(Node* &pRoot)
{
	pRoot = NULL;
}
///=============================================================================
Node* createNode(int x)
{

	Node* p = new Node;
	if(p!= NULL)
	{
		p->info = x,
		p->pLeft = NULL;
		p->pRight = NULL;
	}
	return p;
}
////////////=====================================
void insert(Node* &pRoot, int x )
{
	if(pRoot == NULL )     pRoot = createNode(x);
	else
	{
		if( x== pRoot->info ) return;
		if(x < pRoot->info)         insert(pRoot->pLeft,x);
		else /*x> pRoot->info*/     insert(pRoot->pRight,x);
	}
}
void create_BST(Node* &pRoot, int a[],int n) {
	for(int i=0 ; i<n; i++)
		insert(pRoot,a[i]);
}


int chieucao(Node* pRoot){
   if(pRoot == NULL )
       return 0;

    int a = chieucao(pRoot->pLeft);
    int b = chieucao(pRoot->pRight);
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
		Nodek(pRoot->pLeft,k);
		if(k==0)   printf("%6d",pRoot->info);
		Nodek(pRoot->pRight,k);
	}	
}

Node* search(Node* pRoot, int x) {
	if (pRoot == NULL) {
		return NULL;
	} else {
		if(pRoot->info > x) {
			search(pRoot->pLeft, x);
		} else if(pRoot->info < x) {
			search(pRoot->pRight, x);
		} else {
			return pRoot;
		}
	}
}
void searchTree(Node* pRoot) {
	int x;
	printf("- Nhap Gia Tri Can Tim Kiem: ");
	scanf("%d", &x);
	Node* p = search(pRoot, x);
	if(p == NULL) {
		printf("\n- %d Khong Ton Tai Trong Cay", x);
	} else {
		printf("\n- %d Co Ton Tai Trong Cay", x);
	}
}
int timtuyentinh(int a[], int n, int x)
{
	for(int i = 0 ; i<n ;i++ ){
		if(x != a[i])
		return 1;
	}
	return 0;
}
void xuat(int a[], int n)
{
		for(int i=0 ;i<n;i++)
		{
			printf("%4d",a[i]);
		}
}
int main(){
	
	Node *root;
	init(root);
	int chon,c,i;
	int a[]= {12, 24, 14, 26, 10, 28, 16, 20, 22, 18};
	int n = 10;
	int x;
			xuat(a,n);
			printf("\n phan tu can tim kiem : ");
			scanf("%d",&x);
			int vt = timtuyentinh(a,n,x);
			if(vt == 0 ) {
			printf("\n (x=%d) khong ton tai ", x);
			}
			else {
			printf("\n (x=%d) tai vi tri [%d]",x,vt);
			}
	do {
		printf("\n 1. Xuat cay ");
		printf("\n 2. tim kiem cay ");
		printf(" \nchon CN: ");          scanf("%d",&chon);
		switch(chon) {
			
			case 1:	
				create_BST(root,a,n);
				c = chieucao(root);
				printf("chieu cao cua cay la : %d",c);
				for(i =1 ; i<= c ;i++){
					printf("\nLEVER %d :",i);
					Nodek(root,i);
				}
			break;    
		break; 
			case 2:
				searchTree(root);
				break;
			case 0:
				break;
			default:
				break;
		}
	} while(chon!=0);
	return 0;
	
}