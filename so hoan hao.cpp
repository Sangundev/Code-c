#include <stdio.h>
#include <conio.h>

bool ktSoHoanChinh(int n){
    int sum = 0;
    for(int i = 1; i < n; i++){
        if (n % i == 0)
            sum += i;
    }
    if(sum == n)
        return true;
    return false;
}
int main(){
    int n;
    printf("Nhap vao so nguyen duong n = ");
    scanf("%d", &n);	
    bool kiemTra = ktSoHoanChinh(n);
    if(kiemTra == true)
        printf("%d la so hoan hao.\n", n);
    else
        printf("%d khong phai la so hoan hao.\n", n);
}
