// NIM: 18222103
// Nama: Muhammad Reffy Haykal
// Tanggal: 14/11/2023
// Topik pra-praktikum: list double pointer dan list sirkuler
// Deskripsi: Realisasi listsp.h

#include<stdio.h>
#include<stdlib.h>
#include"listdp.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L) {
    return (First(L) == Nil && Last(L) == Nil);
}
/* List kosong : First(L) = Nil dan Last(L) = Nil */
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L) {
    First(*L) = Nil;
    Last(*L) = Nil;
}
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X) {
    // Dictionary
    address p;
    // Algorithm
    p = (address) malloc (sizeof(ElmtList));
    if (p != Nil) {
        Info(p) = X;
        Prev(p) = Nil;
        Next(p) = Nil;
    }
    return p;
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */

void Dealokasi (address P) {
    free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X){
    // Dictionary
    address p;
    // Algorithm
    p = First(L);
    while (p != Nil && Info(p) != X)
    {
        p = Next(p);
    }
    return p;
}
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X) {
    // Dictionary
    address p;
    // Algorithm
    p = Alokasi(X);
    if (p != Nil) {
        InsertFirst(L, p);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */

void InsVLast (List *L, infotype X) {
    // Dictionary
    address p;
    // Algorithm
    p = Alokasi(X);
    if (p != Nil) {
        InsertLast(L, p);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X) {
    // Dictionary
    address p;
    // Algorithm
    p = Search(*L, *X);
    DelFirst(L, &p);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */

void DelVLast (List *L, infotype *X) {
    // Dictionary
    address p;
    // Algorithm
    p = Search(*L, *X);
    DelLast(L, &p);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P) {
    // Dictionary
    
    // Algorithm
    Next(P) = First(*L);
    if (IsEmpty(*L)) {
        Last(*L) = P;
    } else {
        Prev(First(*L)) = P;
    }
    First(*L) = P;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertLast (List *L, address P) {
    // Dictionary
    
    // Algorithm
    Prev(P) = Last(*L);
    if (IsEmpty(*L)) {
        First(*L) = P;
    } else {
        Next(Last(*L)) = P;
    }
    Last(*L) = P;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfter (List *L, address P, address Prec) {
    // Dictionary
    
    // Algorithm
    if (Next(Prec) != Nil) {
        Prev(Next(Prec)) = P;
    } else {
        Last(*L) = P;
    }
    Next(Prec) = P;
}
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertBefore (List *L, address P, address Succ) {
    // Dictionary
    
    // Algorithm
    if (Prev(Succ) != Nil) {
        Next(Prev(Succ)) = P;
    } else {
        First(*L) = P;
    }
    Prev(Succ) = P;
}
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P) {
    // Dictionary
    
    // Algorithm
    (*P) = First(*L);
    if ((*P) == Last(*L)) {
        Last(*L) = Nil;
    } else {
        Prev(Next(*P)) = Nil;
    }
    First(*L) = Next(*P);
    Dealokasi(*P);
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */

void DelLast (List *L, address *P) {
    // Dictionary
    
    // Algorithm
    (*P) = Last(*L);
    if ((*P) == First(*L)) {
        First(*L) = Nil;
    } else {
        Next(Prev(*P)) = Nil;
    }
    Last(*L) = Prev(*P);
    Dealokasi(*P);
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */

void DelP (List *L, infotype X) {
    // Dictionary
    address p;
    // Algorithm
    p = Search(*L, X);
    if (p != Nil) {
        if (Prev(p) != Nil) {
            Next(Prev(p)) = Next(p);
        } else {
            First(*L) = Next(p);
        }

        if (Next(p) != Nil) {
            Prev(Next(p)) = Prev(p);
        } else {
            Last(*L) = Prev(p);
        }
        Dealokasi(p);
    }
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */

void DelAfter (List *L, address *Pdel, address Prec) {
    // Dictionaryi
    
    // Algorithm
    (*Pdel) = Next(Prec);
    if (Next(Prec) != Nil) {
        Next(Prec) = Next(*Pdel);
        if (Next(Prec) != Nil) {
            Prev(Next(Prec)) = Prec;
        }
    }
    Dealokasi(*Pdel);
}
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

void DelBefore (List *L, address *Pdel, address Succ) {
    // Dictionaryi
    
    // Algorithm
    (*Pdel) = Prev(Succ);
    if (Prev(Succ) != Nil) {
        Prev(Succ) = Prev(*Pdel);
        if (Prev(Succ) != Nil) {
            Next(Prev(Succ)) = Succ;
        }
    } 
    Dealokasi(*Pdel);
}
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward (List L) {
    // Dictionary
    address p;
    // Algorithm
    p = First(L);
    printf("[");
    while (p != Nil) 
    {
        printf("%d", Info(p));
        if (Next(p) != Nil) {
            printf(",");
        }
        p = Next(p);
    }
    printf("]\n");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
/* Terdapat newline di akhir setelah tutup kurung */

void PrintBackward (List L) {
    // Dictionary
    address p;
    // Algorithm
    p = Last(L);
    printf("[");
    while (p != Nil)
    {
        printf("%d", Info(p));
        if (Prev(p) != Nil) {
            printf(",");
        }
        p = Prev(p);
    }
    printf("]\n");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
/* Terdapat newline di akhir setelah tutup kurung */