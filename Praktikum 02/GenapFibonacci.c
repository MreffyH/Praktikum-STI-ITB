// NIM: 1822259
// Nama: Muhammad Reffy Haykal
// Tanggal: 15/09/2023
// Topik praktikum: Pasca-Praktikum 02
// Deskripsi: Membuat program yang menentukan jumlah bilangan genap dari deret fibonacci
#include<stdio.h>

int fibonanci(int x) {
    int first = 1;
    int second = 1;
    int third;
    int sum = 0;

    x = x-2;

    while (x > 0) {
        third = first + second;
        first = second;
        second = third;
        if (third % 2 == 0) {
            sum = sum + third;
        }
        x--;
    }
    return sum;
}

int main() {
    /*dictionary*/
    int n;
    /*algorithm*/
    scanf("%d", &n);
    if (n > 50 || n < 1) {
        printf("-1\n");
    } else if (n == 1) {
        printf("0\n");
    } else if (1 <= n && n <= 50) {
        printf("%d\n", fibonanci(n));
    }
    return 0;
}