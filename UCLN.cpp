#include<stdio.h>
#include<math.h>

int main() {
    int i, so1, so2, min, ucln = 1;
 
    printf("nhap so1 : ");   scanf("%d",&so1);
    printf("nhap so2 : ");   scanf("%d",&so2);
    if(so1 == 0 && so2 == 0) {
        printf("2 so khong co UCLN");
    } else if (so1 != 0 && so2 == 0) {
        printf("UCLN cua %d va %d la : %d",so1,so2,so1);
    } else if (so1 == 0 && so2 != 0) {
        printf("UCLN cua %d va %d la : %d",so1,so2,so2);
    } else {
        if(so1 < so2) {
            min = so1;
        } else {
            min = so2;
        } 
        for(int i = 1; i <= min; i++) {
            if(so1%i == 0 && so2%i == 0) {
                ucln = i;
            }
        }
        printf("UCLN cua %d va %d la : %d",so1,so2,ucln);
    }
    return 0;
}