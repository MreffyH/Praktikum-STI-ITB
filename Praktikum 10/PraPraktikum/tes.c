// NIM: 18222103
// Nama: Muhammad Reffy Haykal
// Tanggal: 14/11/2023
// Topik pra-praktikum: list double pointer dan list sirkuler
// Deskripsi: Program untuk menguji listdp.h

#include <stdio.h>
#include "listdp.c"

int main() {
    // Deklarasi variabel
    List L;
    address P;
    infotype X;

    // Inisialisasi list
    CreateEmpty(&L);

    // Pengujian IsEmpty
    if (IsEmpty(L)) {
        printf("List kosong\n");
    } else {
        printf("List tidak kosong\n");
    }

    // Pengujian InsVFirst dan PrintForward
    printf("Menambahkan 5 ke elemen pertama...\n");
    InsVFirst(&L, 5);
    PrintForward(L);

    // Pengujian InsVLast dan PrintForward
    printf("Menambahkan 10 ke elemen terakhir...\n");
    InsVLast(&L, 10);
    PrintForward(L);

    // Pengujian DelFirst dan PrintForward
    printf("Menghapus elemen pertama...\n");
    DelFirst(&L, &P);
    PrintForward(L);

    // Pengujian DelLast dan PrintForward
    printf("Menghapus elemen terakhir...\n");
    DelLast(&L, &P);
    PrintForward(L);

    // Pengujian DelVFirst dan PrintForward
    printf("Menambahkan 15 ke elemen pertama...\n");
    InsVFirst(&L, 15);
    PrintForward(L);

    // Pengujian DelVLast dan PrintForward
    printf("Menambahkan 20 ke elemen terakhir...\n");
    InsVLast(&L, 20);
    PrintForward(L);

    printf("Menghapus elemen pertama dengan nilai 15...\n");
    DelVFirst(&L, &X);
    PrintForward(L);

    printf("Menghapus elemen terakhir dengan nilai 20...\n");
    DelVLast(&L, &X);
    PrintForward(L);

    // Pengujian InsertAfter dan PrintForward
    printf("Menambahkan 25 setelah elemen pertama...\n");
    P = Alokasi(25);
    InsertAfter(&L, P, First(L));
    PrintForward(L);

    // Pengujian InsertBefore dan PrintForward
    printf("Menambahkan 30 sebelum elemen terakhir...\n");
    P = Alokasi(30);
    InsertBefore(&L, P, Last(L));
    PrintForward(L);

    // Pengujian DelP dan PrintForward
    printf("Menghapus elemen dengan nilai 25...\n");
    DelP(&L, 25);
    PrintForward(L);

    // Pengujian DelAfter dan PrintForward
    printf("Menghapus elemen setelah elemen pertama...\n");
    DelAfter(&L, &P, First(L));
    PrintForward(L);

    // Pengujian DelBefore dan PrintForward
    printf("Menghapus elemen sebelum elemen terakhir...\n");
    DelBefore(&L, &P, Last(L));
    PrintForward(L);

    return 0;
}
