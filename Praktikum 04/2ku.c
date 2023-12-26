#include <stdio.h>
#include "list.h"

/*Fungsi ini digunakan untuk mengubah nilai elemen array data pada indeks p menjadi x.*/
void Query0 (int *data, int p, int x) {
    data[p] = x;
}

/* fungsi ini digunakan untuk mencetak seluruh elemen array data ke layar dengan spasi sebagai pemisah dan newline pada akhir. */
void Query1 (int *data, int n) {
    if(n == 0) return;
    for(int i = 0; i < n-1; i++) {
        printf("%d ", data[i]);
    }
    printf("%d\n", data[n-1]);
}

/*Fungsi ini digunakan untuk menyisipkan elemen x pada indeks p dalam array data dan menginkrementasi nilai n, yang merupakan panjang array.*/
void Query2 (int *data, int p, int x, int *n) {
    for(int i = (*n)-1; i >= p; i--) {
        data[i+1] = data[i];
    }
    data[p] = x;
    (*n)++;
}

/*Fungsi ini digunakan untuk menghapus elemen pada indeks p dalam array data dan mengurangi nilai n*/
void Query3 (int *data, int p, int *n) {
    if (p >= (*n)) return;
    for (int i = p; i < (*n)-1; i++) {
        data[i] = data[i+1];
    }
    (*n)--;
}

/*Fungsi ini digunakan untuk mencari dan mencetak nilai maksimum dari subarray yang berurutan dengan elemen-elemen array data. Ini mengimplementasikan algoritma Maximum Subarray Sum (Kadane's Algorithm).*/
void Query4 (int *data, int n) {
    // Dictionary
    int maks;
    int cur_maks;
    int i;
    // Algorithm
    maks = 0;
    cur_maks = 0;

    for(i = 0; i < n; i++) {
        cur_maks += data[i];
        cur_maks = (cur_maks > 0)? cur_maks : 0;
        maks = (cur_maks > maks)? cur_maks : maks;
    }
    printf("%d\n", maks);
}

/* main program */
int main() {   
    // Input variabel N (banyak cabang) dan Q (banyak query)
    int n, q; scanf("%d %d", &n, &q);
    
    // Data dideclare dengan ukuran 2000 karena kita punya memory limit 64mb (sangat besar)
    // Sehingga tidak perlu alokasi memory tambahan, karena banyak maksimal cabang adalah 2000 (1000 di awal 1000 di query)
    int data[2000];

    // Input data
    for(int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    // Input query
    while(q--) {
        // Input query digit pertama
        int query; scanf("%d", &query);
        int p, x;

        switch(query) {
            case 0:
                scanf("%d %d", &p, &x);
                Query0(data, p, x);
                break;
            case 1:
                Query1(data, n);
                break;
            case 2:
                scanf("%d %d", &p, &x);
                Query2(data, p, x, &n);
                break;
            case 3:
                scanf("%d", &p);
                Query3(data, p, &n);
                break;
            case 4:
                Query4(data, n);
                break;
            default:
                break;
        }
    }
}