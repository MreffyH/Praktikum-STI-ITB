// NIM: 1822259
// Nama: Muhammad Reffy Haykal
// Tanggal: 13/09/2023
// Topik praktikum: Pra-Praktikum 02
// Deskripsi: Membuat program yang mendeteksi digit genap
#include<stdio.h>
int countDigits(int num) {
    /*Dictionary*/
    int temp;
    /*Algorithm*/
    temp = 0;
    while (num != 0) {
        num = num / 10;
        temp++;
    } 
    return temp;
}

int main() {
    /*Dictionary*/
    int n, i; 
    int input;
    int fungsi; 
    int count;
    /*Algorithm*/
    count = 0;
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d", &input);
        fungsi = countDigits(input);
        if (fungsi % 2 == 0) {
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}