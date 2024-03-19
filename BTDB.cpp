// Tinh P(n) = 1-2+3-4+5+...+((-1)^(n+1))*n (n>0)
#include<stdio.h>
#include<stdio.h>>

int Nhap()
{
	int x;
	do
	{
		int x;
		if (x < 0)
			printf("nhap lai ");
	} while (x < 0);
	return x;
}

long Tinh(int n)
{
	long p = 0;
long tmp = 1;
	for (int i = 1; i <= n; i++)
{
		p += tmp*i;
		tmp *= -1;
}
	return p;
}

int main()
{
	int n; 

	printf("nha n :");   scanf("%d",&n);
	n = Nhap();
	printf("ket qua : %d",Tinh(n));
	return 0;
}