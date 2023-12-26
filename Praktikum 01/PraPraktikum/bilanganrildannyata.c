// NIM: 1822259
// Nama: Muhammad Reffy Haykal
// Tanggal: 07/09/2023
// Topik praktikum: Pra-Praktikum 01
// Deskripsi: Membuat program yang mengelurakan angka, "ril", dan "nyata"
#include<stdio.h>
int main() {
    /*Dictionary*/
    int i, n;
    /*Algorithm*/
    scanf("%d", &n);
    if (n>0) {
        for (i=1;i<=n;i++) {
            if (i % 15 == 0) { /*Jika habis dibagi 3 dan 5*/
                printf("RilNyata\n");
            } else if (i % 5 == 0) { /*Jika habis dibagi 5*/
                printf("Ril\n"); 
            } else if (i % 3 == 0) { /*Jika habis dibagi 3*/
                printf("Nyata\n");
            } else { /*Jika tidak habis dibagi 3 dan 5*/
                printf("%d\n", i);
            }
        }
    }
    return 0;
}