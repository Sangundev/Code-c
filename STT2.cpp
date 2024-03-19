#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct cuonsach{
	int masach;
	char tensach[51];
	float giasach;
	int SoTrang;
}Sach;

struct NODE {
	Sach data;
	NODE *pLeft;
	NODE *pRight;
};
void init(NODE* &root)
{
	root = NULL;
}
void nhap1Sach(Sach &x)
{
    printf("nhap ma cuon sach: ");
    scanf("%d",&x.masach);
    printf("nhap ten cuon sach: ");
    fflush(stdin);  gets(x.tensach);
    printf("nhap gia cuon sach: ");
    scanf("%f",&x.giasach);
    printf("nhap so trang sach: ");
    scanf("%d",&x.SoTrang);
}
void Xuat1Sach(Sach x){
      printf("\n|%8d|%-40s|%8.2f|%4d|", 
    x.masach ,x.tensach,x.giasach,x.SoTrang);
}

NODE* createNode(Sach x)
{

	NODE* p = new NODE;
	if(p!= NULL)
	{
		p->data = x,
		p->pLeft = NULL;
		p->pRight = NULL;
	}
	return p;
}

bool isLeafNode(NODE *root){
	return (root->pLeft == NULL && root->pRight == NULL);
}

void Insert(NODE* &root, Sach x )
{
	if(root == NULL )     root = createNode(x);
	else
	{
		if( x.masach== root->data.masach ) return;
		if(x.masach < root->data.masach)         Insert(root->pLeft,x);
		else 								      Insert(root->pRight,x);
	}
}

void nhapsl(int &n)
{
	do{
		printf("\n\t nhap so luong so nguen <100 : ");
		scanf("%d",&n);
		if(n<1 )  printf("nhap lai :" );
	}while (n<1 );
}
void input(NODE* &root)
{		
		int n; nhapsl(n);
		Sach x; 
		
		for(int i=0 ;i<n;i++)
		{
			printf(" nhap thong tin cuon sach thu %d:\n ",i+1);
			nhap1Sach(x);
			Insert(root, x);
		}
}
void LRN(NODE *root){
	if(root != NULL){
		LRN(root->pLeft);
		LRN(root->pRight);
		Xuat1Sach(root->data);
	}
}

int Cau_3(NODE *root){
	if(root == NULL)
		return 0;
	if(root->data.giasach>=75000 && root->data.giasach<=120000){
		return 1;
	}
	return Cau_3(root->pLeft) + Cau_3(root->pRight);
}

void Cau_4(NODE *root){
	if(root != NULL && (root->data.SoTrang<200 && root->data.giasach > 150000)){
		Cau_4(root->pLeft);
		Xuat1Sach(root->data);
		Cau_4(root->pRight);
	}
}

void Cau_5(NODE *root){
	if(root != NULL){
		if(isLeafNode(root) && (root->data.giasach<100000)){
			Cau_5(root->pLeft);
			Xuat1Sach(root->data);
			Cau_5(root->pRight);
		}
	}
}

NODE *NodeTheMang(NODE *p){
	while(p->pLeft) p = p->pLeft;
	return p;
}

void DeleteNODE(NODE *&root, int x){
	if(root == NULL) return;
	if(x<root->data.SoTrang) DeleteNODE(root->pLeft, x);
	else if(x>root->data.SoTrang) DeleteNODE(root->pRight, x);
	else{
		NODE *p = root;
		if(root->pLeft == NULL){
			p = root;
			root = root->pRight;
			delete p;
		}
		else if(root->pRight == NULL){
			p = root;
			root = root->pLeft;
			delete p;
		}
		else {
			NODE *q = NodeTheMang(root->pRight);
			root->data.SoTrang = q->data.SoTrang;
			DeleteNODE(root->pRight, q->data.SoTrang);
		}
	}
}

int DuyetSoTrang(NODE *root){
	if(root != NULL){
		DuyetSoTrang(root->pLeft);
		if(root->data.SoTrang>320){
			return root->data.SoTrang;
		}
		DuyetSoTrang(root->pRight);
	}
	return -1;
}
//=====================================================
void menu(){
	int chon;
	NODE *root;
	init(root);
do{	
		printf("\n\n=================QUAN LY THU VIEN==============\n\n");
		printf("1. Tao cay nhi phan tim kiem\n");
		printf("2. Liet ke thong tin cac sach theo thu tu 'LRN'\n");
		printf("3. Dem so luong sach co gia bia tu 75.000 -> 120.000\n");
		printf("4. Tim va in ra sach co so trang < 200 va co gia bia > 150.000\n");
		printf("5. Dem so node la co gia bia nho hon 100.000\n");
		printf("6. Xoa tat ca cac sach co so trang tren 320 \n");
		printf("0. ---------------------EXIT----------------------- \n");
		printf("\n\n================================================\n\n");
		printf("\nNhap lua chon: ");
		scanf("%d",&chon);
	switch (chon){
			case 1:
				input(root);
				break;
			case 2:
				if(root == NULL){
					printf("\nDanh sach hien dang trong\n");
				}
				else{
					printf("\nDanh hien co: \n");
					LRN(root);
				}
				break;
			case 3:
				int sl;
				sl = Cau_3(root);
				printf("\nSo luong sach co gia bia tu 75.000 -> 120.000 la: %d", sl);
				break;
			case 4:
				Cau_4(root);
				break;
			case 5:
				Cau_4(root);
				break;
			case 6:
				int sotrang;
				while(sotrang != -1){
					sotrang = DuyetSoTrang(root);
					DeleteNODE(root, sotrang);
				}
				break;
		}
	}while(chon!= 0);
}
int main() {
	menu();
}

