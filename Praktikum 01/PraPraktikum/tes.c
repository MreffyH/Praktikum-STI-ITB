#include<stdio.h>
int main() {
    int n, digit, result, kali;
    scanf("%d", &n);
    // digit = n % 10;
    // n = n / 10;
    // printf("%d %d", digit, n);
    kali = 1;
    while (n != 0) {
        digit = n % 10;
        printf("%d \n", digit);
        if (digit != 0){
            kali = kali * digit;
            printf("%d\n", kali);
        }
        n = n / 10;
        printf("%d\n", n);
    }
}