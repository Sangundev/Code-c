#include<string.h>
#include<stdio.h>
int Dem_kt(char s[200],char x, char y);
int Dem_kt(char s[200],char x, char y){
             int l=strlen(s), d=0;
             for(int i=0;i<l;i++)
                    if (s[i]>=x &&s[i]<=y)
                              d++;
            return d;
}
int main(){
           int l,i;
           char s[200];
           printf("Nhap chuoi s = ");
           gets(s);
           printf("so ki tu in hoa la %d", Dem_kt(s,'A','Z'));
           printf("\nso ki  tu in thuong  la %d", Dem_kt(s,'a','z'));
           printf("\nso ki tu so la %d", Dem_kt(s,'0','9'));

           return 0;
}

