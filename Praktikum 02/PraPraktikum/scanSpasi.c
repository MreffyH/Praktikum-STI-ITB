// NIM: 1822259
// Nama: Muhammad Reffy Haykal
// Tanggal: 13/09/2023
// Topik praktikum: Pra-Praktikum 02
// Deskripsi: Membuat program yang mendeteksi spasi

#include<string.h>
#include<stdio.h>
int main() {
    /*Dictionary*/
    char state[100];
    int n, i;
    /*Algorithm*/
    n = 1;
    i = 0;
    scanf("%100[^\n]", &state);

    while (i <= strlen(state)) {
        if (state[i] == ' ') {
            n++;
        }
        i++;
    }
    printf("%d\n", n);
    return 0;
}