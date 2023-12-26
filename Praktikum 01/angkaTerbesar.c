// NIM: 1822259
// Nama: Muhammad Reffy Haykal
// Tanggal: 12/09/2023
// Topik praktikum: Praktikum 01
// Deskripsi: Membuat program yang mengelurakan angka terbesar
#include<stdio.h>
int main() {
    /*Dictionary*/
    int a, b, c;
    /*Algorithm*/
    scanf("%d %d %d", &a, &b, &c);
    if (a > b && a > c) {
        printf("Diantara %d, %d, dan %d. Angka terbesar adalah %d\n", a, b, c, a);
    } else if (b > a && b > c) {
        printf("Diantara %d, %d, dan %d. Angka terbesar adalah %d\n", a, b, c, b);
    } else if (c > a && c > b) {
        printf("Diantara %d, %d, dan %d. Angka terbesar adalah %d\n", a, b, c, c);
    }
    return 0;
}