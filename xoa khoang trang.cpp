#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int main(int argc, char *argv[]) 
{
	char s[100];
	int i,n,j,dem,lap=0;
	gets(s);
	dem=0;
	do
	{
		for(i=0;i<=strlen(s);i++)
		{
		if((s[i]==' ')&&(s[i+1]==' '))
		{
			dem++;
			for(j=i;j<n;j++)
			{
				s[j]=s[j+1];
			}
		}
		}
	}
	while(dem==0);
	printf("Chuoi sau khi cat:\n");
	for(i=0;i<(n-dem);i++)
	{
		printf("%c",s[i]);
	}
	return 0;
}