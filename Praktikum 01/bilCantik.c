// NIM: 1822259
// Nama: Muhammad Reffy Haykal
// Tanggal: 12/09/2023
// Topik praktikum: Praktikum 01
// Deskripsi: Membuat program yang mengelurakan bilangan cantik atau tidak
#include<stdio.h>
int main() {
    /*Dictionary*/
    int a, b;
    int sum, times;
    /*Algorithm*/
    scanf("%d %d", &a, &b);
    sum = a + b;
    times = a * b;
    if (a > 0 && b > 0) {
        if (sum % 4 == 0 || times % 4 == 0) {
            printf("Y\n");
        } else if (sum % 4 != 0 || times % 4 != 0) {
            printf("N\n");
        }
    }
    return 0;
}