// NIM: 1822259
// Nama: Muhammad Reffy Haykal
// Tanggal: 07/09/2023
// Topik praktikum: Pra-Praktikum 01
// Deskripsi: Membuat program yang mengkali semua bilangan dan menghitung digit hasil perkalian yang bukan angka 0
#include<stdio.h>
int main() {
    /*Dictionary*/
    long int n;
    int zero;
    long int result;
    int digit;
    int temp;
    /*Algorithm*/
    result = 1;
    zero = 0;
    scanf("%ld", &n);
    
    if (n>0) {
        while(n != 0) { /*Akan melakukan looping sampai input adalah 0*/
            digit = n % 10; /*Mendapatkan digit terkecil*/
            if (digit !=0) {
                result *= digit;
            }
            n = n / 10; /*Mengubah, misal 100 jadi 10 lalu kembali ke atas*/
        }
    
        temp = result;
        while (temp != 0) {
            digit = temp % 10;
        if (digit != 0) {
            zero++;
        }
        temp = temp / 10;
        }
    }
    printf("%ld %d\n", result, zero);
    return 0;
}