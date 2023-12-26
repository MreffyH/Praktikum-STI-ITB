// NIM: 1822259
// Nama: Muhammad Reffy Haykal
// Tanggal: 15/09/2023
// Topik praktikum: Pasca-Praktikum 02
// Deskripsi: Membuat program yang mencari angka terbesar kedua
#include<stdio.h>
int main() {
    /*Dictionary*/
    int n, x;
    int i;
    int fisrtmax, secondmax;
    /*Algorithm*/
    secondmax = -9999;
    fisrtmax = -9999;
    
    scanf("%d", &n);

    for (i=0; i<n; i++) {
        scanf("%d", &x);
        if (x > fisrtmax) {
            secondmax = fisrtmax; 
            fisrtmax = x;
        } else if (x > secondmax && x != fisrtmax) {
            secondmax = x;
        }        
    }
    printf("%d\n", secondmax);
    return 0;
}