#include<bits/stdc++.h>
#include <unistd.h>
#define MAX 100
#include<stdio.h>
#include<conio.h>
//==============================================================
typedef struct GRAPH
{	int n;
	int a[MAX][MAX];
}DOTHI;

int DocMaTranKe(const char* TenFile,DOTHI &g)
{	FILE* f;
	f = fopen(TenFile,"rt");
	if(f==NULL)
	{
		printf("Khong mo duoc file\n");
		return 0;
	}
	fscanf(f,"%d",&g.n);
	for(int i=0;i<g.n;i++)
		for(int j=0;j<g.n;j++)
			fscanf(f,"%d",&g.a[i][j]);
	fclose(f);
	return 1;
}
void XuatMaTranKe(DOTHI g,const char* TenFile)
{	printf("So dinh cua do thi = %d\n",g.n);
	printf("Ma tran ke cua do thi %s la:\n",TenFile);
	for(int i=0;i<g.n;i++)
	{	for(int j=0;j<g.n;j++)
			printf("%4d",g.a[i][j]);
		printf("\n");
	}
}
//======================================================================
void check() {
	int pass;
	char account[50];
ql:
	printf("\n");
	printf("account:");     scanf("%s",&account);
	printf("- Password: ");     scanf("%d", &pass);
	if(pass != 2002) {
		printf("\n- Fail !\n");
		goto ql;
	}
	system("cls");
	if(pass == 2002) {
		for(int i = 0; i <= 100; i) {
			printf("\nLoading...(%d%)\n", i);
			sleep(1);
			i=i+25;
			system("cls");
		}
		printf("\n");
		printf("hello %s",account);
		printf("\n I LOVE YOU FOR ME ");
		printf("\n");
	}
}
int main() {
	system("color 7C");
	check();
	return 0;
}

