// NIM: 18222103
// Nama: Muhammad Reffy Haykal
// Tanggal: 16/11/2023
// Topik pra-praktikum: list double pointer dan list sirkuler
// Deskripsi: Realisasi roundrobin.c


#include "listsirkuler.h"
#include <stdio.h>

void deleteRR (List *l, infotype tQ) {
    if (!IsEmpty(*l)) {
        address last = First(*l);

        while (Next(last) != First(*l)) 
        {
            last = Next(last);
        }

        if (Info(last) > tQ) {
            printf("%d\n", tQ);
            Info(last) -= tQ;
            First(*l) = last;
        } else {
            infotype x;
            DelVLast(l, &x);
            printf("%d\n", x);
        }
    } else {
        printf("List kosong\n");
    }
}
/* Jika l tidak kosong, "menghapus" elemen terakhir list l, misal last, sesuai aturan round robin, yaitu:
- jika Info(last)>tQ, maka last "diantrikan" kembali sebagai first elemen dengan Info(last)=Info(last)-tQ
- jika Info(last)<=tQ, maka DelVLast(l,x) dan menampilkan x ke layar */
/* Jika l kosong, cetak "List kosong" */
/* I.S. tQ terdefinisi sebagai nilai time slice pemrosesan.
L terdefinisi, mungkin kosong. */
/* F.S. Elemen terakhir l diproses sesuai aturan round-robin.
l mungkin menjadi kosong. */

float average (List l) {
    address P = First(l);
    float sum = 0;
    int count = 0;

    do {
        sum += Info(P);
        count++;
        P = Next(P);
    } while (P != First(l));

    return sum / count;
}
/* Menghasilkan nilai rata-rata elemen l. l tidak kosong. */

/* Pengerjaan Soal */
int main() {
    List l;
    CreateEmpty(&l);

    infotype tQ;
    scanf("%d", &tQ);

    while (1) 
    {
        char op;
        scanf(" %c", &op);

        if (op == 'A') {
            infotype waktu;
            scanf("%d", &waktu);

            if (waktu > 0) {
                InsVFirst(&l, waktu);
            }
        } else if (op == 'D') {
            deleteRR(&l, tQ);
        } else if (op == 'F') {
            break;
        } else {
            printf("Kode salah\n");
        }
    }

    if (!IsEmpty(l)) {
        printf("%.2f\n", average(l));
    } else {
        printf("Proses selesai\n");
    }

    return 0;
}