
// AVL : do Adelson Velski và Landis xây dung vào nam 1962.
#include <stdio.h>
#include <conio.h>
#include <math.h>
#define SPECIAL 9999
//====================================================
typedef int DataType;
struct Node
{
	DataType info;
	Node *pLeft, *pRight;
	int height;
}; 
typedef Node* NODEPTR;
//====================================================
void showAVL(NODEPTR pRoot);
int Max(int a,int b);
int ChieuCaoCay(Node* pRoot);
void Init_Build_Array(int build[], int n);
void DrawTree(NODEPTR pRoot);
void Build_Array(Node* pRoot, int build[], int begin, int end);
void InSoLuong_KT(int count, char kt);
void CacInfo_TangK( int h, int k, int build[]);
void CacCheo_TangK( int h, int k, int build[]);
//====================================================
void init(NODEPTR &pRoot) 
{
	pRoot = NULL;
}
//====================================================
NODEPTR createNode(DataType x) 
{
	NODEPTR p = new Node; 
	if(p != NULL)
	{
		p->info = x;
		p->pLeft = p->pRight = NULL;
		p->height = 1;
	}
	return p;
}
//====================================================
int getHeight(NODEPTR p)
{
	if(p == NULL) return 0;
	return p->height;
}
//====================================================
int balanceFactor(NODEPTR p)
{
	if (p == NULL)	return 0;
	return getHeight(p->pLeft) - getHeight(p->pRight);
}
//====================================================
int max(int a, int b)
{
	return (a>b) ? a : b;
}
//====================================================
NODEPTR rotateRight(NODEPTR p)
{
	if (p == NULL)	return NULL;
	if (p->pLeft == NULL) return NULL;
	
	NODEPTR pivot = p->pLeft;
	p->pLeft = pivot->pRight;
	pivot->pRight = p;  

	p->height = 1 + max(getHeight(p->pRight), getHeight(p->pLeft));
	pivot->height = 1 + max(getHeight(pivot->pRight), getHeight(pivot->pLeft));
	
	return pivot;
}
//====================================================
NODEPTR rotateLeft(NODEPTR p)
{
	if (p == NULL)	return NULL;
	if (p->pRight == NULL)	return NULL; 

	NODEPTR pivot = p->pRight;
	p->pRight = pivot->pLeft;
	pivot->pLeft = p;

	p->height = 1 + max(getHeight(p->pRight), getHeight(p->pLeft));
	pivot->height = 1 + max(getHeight(pivot->pRight), getHeight(pivot->pLeft));
	
	return pivot;
}
//====================================================
NODEPTR balance(NODEPTR p)
{
	if (balanceFactor(p) > 1) 
	{
		if (balanceFactor(p->pLeft) < 0)
			p->pLeft = rotateLeft(p->pLeft); 
		p = rotateRight(p);	
	}
	else if (balanceFactor(p) < -1)
	{
		if (balanceFactor(p->pRight) > 0)
			p->pRight = rotateRight(p->pRight);	
		p = rotateLeft(p); 
	}
	return p;
}
//====================================================
NODEPTR insert(NODEPTR p, DataType x)
{
	if(p == NULL)	return createNode(x);
	if(x < p->info) 	p->pLeft = insert(p->pLeft, x);
	else if(x > p->info) 	p->pRight = insert(p->pRight, x);

	p->height = 1 + max(getHeight(p->pLeft), getHeight(p->pRight));
	
	return balance(p);  
}
//====================================================
void createAVL(NODEPTR &pRoot, int a[], int n)
{
	printf("AVL RONG \n");
	for(int i=0; i<n; i++)
	{
		pRoot = insert(pRoot, a[i]);
		printf("\nChen them Node_Info: %d\n\n", a[i]);
		getch();
		DrawTree(pRoot);
	}
}
//===================================================
//====================================================
int main()
{
//	int a[]={9, 1,3,5,10,2, 4,8,20,15,11, 13};int n= 12;
//	int a[]={4,8,7,6,5,2}; int n=6;
	int 
	a[]={24, 26, 28, 10, 14, 16, 20, 18, 12, 22};
//	int a[]= {18, 24, 14, 28, 16, 20, 10, 22, 12, 26};
	int n = 10;
//	int a[]={8,4,1,2,6,20,14,13,15};	int n= 9;

	NODEPTR pRoot;
	init(pRoot);

	printf("\n\n\t\t================ AVL ==================\n\n");
	
	createAVL(pRoot, a, n);

	printf("\n\t\t ========= END ============");
	printf("\n\n\n\n");
	return 0;
}
//====================================================
int Max(int a,int b)
{
	return (a>b) ? a: b;
}
//====================================================
int ChieuCaoCay(Node* pRoot)
{
	if(pRoot==NULL) return 0;
	return Max(ChieuCaoCay(pRoot->pLeft),ChieuCaoCay(pRoot->pRight)) +1;
}
//====================================================
void Init_Build_Array(int build[], int n)
{
	for(int i=0; i<n; i++) build[i] = SPECIAL;
}
//====================================================
void DrawTree(NODEPTR pRoot)
{
	int build[500];
	int h, begin, end;
	h=ChieuCaoCay(pRoot); 
	begin =0; end = (int)pow(2,h);

	Init_Build_Array(build, end);
	Build_Array(pRoot, build, begin, end-1);
	
	for(int k=1;k<=h ; k++) 
	{
		if(k>1) CacCheo_TangK(h, k, build);	printf("\n");
		CacInfo_TangK( h,  k, build); printf("\n");
	}
}
//====================================================
void Build_Array(Node* pRoot, int build[], int begin, int end)
{
	int m = (begin+end)/2;
	if(pRoot!=NULL)
	{
		build[m] = pRoot->info;
		Build_Array(pRoot->pLeft, build, begin, m);
		Build_Array(pRoot->pRight, build, m, end);
	}
}
//====================================================
void InSoLuong_KT(int count, char kt)
{
	for (int i = 0; i < count; i++)	printf("%2c", kt);
}
//====================================================
void CacInfo_TangK( int h, int k, int build[])
{
	int sl = (int)pow(2,k-1);
	int step = (int)pow(2,h-k)-1;
	int sb = step;
	for(int i=0; i<sl; i++)
	{
		if(i%2==0)
		{
			InSoLuong_KT((int)pow(2,h-k+1)-1, ' '); // in F
			if(build[sb] == SPECIAL) InSoLuong_KT((int)pow(2,h-k+1), ' ');
			else
			{
				printf("%2d", build[sb]);
				InSoLuong_KT((int)pow(2,h-k+1)-1, ' ');
			} 
		}
		else // i le
		{
			if(build[sb] == SPECIAL) InSoLuong_KT((int)pow(2,h-k+1), ' ');
			else
			{
				InSoLuong_KT((int)pow(2,h-k+1)-1, ' ');
				printf("%2d", build[sb]);
			} 
			InSoLuong_KT((int)pow(2,h-k+1)-1, ' '); // in F
		}
		InSoLuong_KT(1, ' '); // in Tr
		sb = sb + 2*(step+1);
	}
}
//====================================================
void CacCheo_TangK( int h, int k, int build[])
{
	int sl = (int)pow(2,k-1);
	int step = (int)pow(2,h-k)-1;
	int sb = step;
	for(int i=0; i<sl; i++)
	{
		if(i%2==0) // node pLeft
		{
			InSoLuong_KT((int)pow(2,h-k+1)-1, ' '); // in F
			if(build[sb] == SPECIAL) InSoLuong_KT((int)pow(2,h-k+1), ' ');
			else InSoLuong_KT((int)pow(2,h-k+1), '='); 
		}
		else // node pRight
		{
			if(build[sb] == SPECIAL) InSoLuong_KT((int)pow(2,h-k+1), ' ');
			else InSoLuong_KT((int)pow(2,h-k+1), '=');
			InSoLuong_KT((int)pow(2,h-k+1)-1, ' '); // in F
		}
		InSoLuong_KT(1, ' '); // in Tr
		sb = sb + 2*(step+1);
	}
}
//====================================================
