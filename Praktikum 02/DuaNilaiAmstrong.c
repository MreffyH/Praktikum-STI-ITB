// NIM: 1822259
// Nama: Muhammad Reffy Haykal
// Tanggal: 15/09/2023
// Topik praktikum: Pasca-Praktikum 02
// Deskripsi: Membuat program yang mencari bilangan amstrong di antara dua nilai
#include<stdio.h>
int isAmstrong(int a, int b) {
    /*Dictionary*/
    int i;
    int exponent = 0;
    int powereddigit;
    int temp = a;
    int sum = 0;
    int digit;
    /*Algorithm*/
    while (temp > 0) {  /*Untuk mengetahui ini angka satuan(pangkat 1), puluhan(pangkat 2), ratusan(pangkat 3), dll(pangkat n)*/
        exponent++;
        temp = temp / 10;
    }
    while (a > 0) {     /*Untuk melakukan perhitungan nilai amstrong-nya*/
        powereddigit = 1;
        digit = a % 10;
        for (i = 0; i < exponent; i++) {
            powereddigit = powereddigit * digit;
        }
        sum = sum + powereddigit;  /*Menyimpan total nilai supaya diketahui batas atas nya*/
        a = a /10;
    }
    if (sum == b) {
        printf("%d\n", sum);
    }
}

int main() {
    /*Dictionary*/
    int start, end;
    int i;
    /*Algorithm*/
    scanf("%d %d", &start, &end);
    for (i = start; i <= end; i++) {
        isAmstrong(i, i);
    }
    return 0;
}