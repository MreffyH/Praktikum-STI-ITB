// NIM: 18222103
// Nama: Muhammad Reffy Haykal
// Tanggal: 08/11/2023
// Topik pra-praktikum: listlinier
// Deskripsi: Realisasi listlinier.h

#include "listlinier.h"
#include<stdio.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L) {
    return First(L) == Nil;
}
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L) {
    First(*L) = Nil;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X) {
    // Dictionary
    address p;
    // Algorithm
    p = (address) malloc(1 * sizeof(ElmtList));
    if (p != Nil) {
        Info(p) = X;
        Next(p) = Nil;
        return p;
    } else {
        return Nil;
    }
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void Dealokasi (address *P) {
    free(*P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X) {
    // Dictionaruy
    address p;
    boolean found = false;
    // Algorithm
    if (IsEmpty(L)) {
        return Nil;
    } else {
        p = First(L);
        while (found == false && p != Nil) 
        {
            if (X == Info(p)) {
                found = true;
            } else {
                p = Next(p);
            }
        }
        if (found == true) {
            return p;
        } else {
            return Nil;
        }
    }
    
}
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X) {
    // Dictionary
    address p = Alokasi(X);
    // Algorithm
    if (p != Nil) {
        InsertFirst(L, p);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */

void InsVLast (List *L, infotype X) {
    // Dictionary
    address p = Alokasi(X);
    // Algorithm
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
    address p = First(*L);
    // Algorithm
    *X = Info(p);
    First(*L) = Next(p);
    Dealokasi(&p);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */

void DelVLast (List *L, infotype *X) {
    // Dictionary
    address p = First(*L);
    address prec = Nil;
    // Algorithm
    while (Next(p) != Nil)
    {
        prec = p;
        p = Next(p);
    }
    *X = Info(p);
    if (prec != Nil) {
        Next(prec) = Nil;
    } else {
        First(*L) = Nil;
    }
    Dealokasi(&p);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P) {
    Next(P) = First(*L);
    First(*L) = P;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */

void InsertAfter (List *L, address P, address Prec) {
    Next(P) = Next(Prec);
    Next(Prec) = P;
}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */

void InsertLast (List *L, address P) {
    // Dictionary
    address last;
    // Algorithm
    if(IsEmpty(*L)) {
        InsertFirst(L, P);
    } else {
        last = First(*L);
        while (Next(last) != Nil)
        {
            last = Next(last);
        }
        InsertAfter(L, P, last);
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P) {
    *P = First(*L);
    First(*L) = Next(First(*L));
    Next(*P) = Nil;
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */

void DelP (List *L, infotype X) {
    // Dictionary
    address prec;
    address p;
    boolean found = false;
    // Algorithm
    if (!IsEmpty(*L)) {
        if (X == Info(First(*L))) {
            DelFirst(L, &p);
            Dealokasi(&p);
        } else {
            p = First(*L);
            while (found == false && p != Nil)
            {
                if (Info(p) == X) {
                    found = true;
                }
                else {
                    prec = p;
                    p = Next(p);
                }
            }
            if (found == true) {
                DelAfter(L, &p, prec);
                Dealokasi(&p);
            }
        }
    }
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */

void DelLast (List *L, address *P) {
    // Dictionary
    address last = First(*L);
    address preclast = Nil;
    // Algorithm
    while (Next(last) != Nil) 
    {
        preclast = last;
        last = Next(last);
    }

    *P = last;

    if (preclast == Nil) {
        First(*L) = Nil;
    } else {
        Next(preclast) = Nil;
    }
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */

void DelAfter (List *L, address *Pdel, address Prec) {
    *Pdel = Next(Prec);
    Next(Prec) = Next(Next(Prec));
    Next(*Pdel) = Nil;
}
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L) {
    // Dictionary
    address p;
    boolean cek = true;
    // Algorithm
    printf("[");
    if (!IsEmpty(L)) {
        p = First(L);
        while (p != Nil) 
        {
            if (cek == false) {
                printf(",");
            }
            printf("%d", Info(p));
            cek = false;
            p = Next(p);
        }
    }
    printf("]\n");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah terkecuali untuk newline di akhir output */

int NbElmt (List L) {
    // Dictionary
    address p;
    int count = 0;
    // Algorithm
    if(!IsEmpty(L)) {
        p = First(L);
        while (p != Nil) 
        {
            count++;
            p = Next(p);
        }
    }
    return count;
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L) {
    // Dictionary
    address p;
    infotype max;
    // Algorithm
    p = AdrMax(L);
    max = Info(p);
    return max;
}
/* Mengirimkan nilai info(P) yang maksimum */

address AdrMax (List L) {
    // Dictionary
    address p, max;
    // Algorithm
    max = First(L);
    p = Next(First(L));
    while (p != Nil)
    {
        if (Info(p) > Info(max)) {
            max = p;
        }
        p = Next(p);
    }
    return max;
}
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */

infotype Min (List L) {
    // Dictionary
    address p;
    infotype min;
    // Algorithm
    p = AdrMin(L);
    min = Info(p);
    return min;
    
}
/* Mengirimkan nilai info(P) yang minimum */

address AdrMin (List L) {
    // Dictionary
    address p, min;
    // Algorithm
    min = First(L);
    p = Next(First(L));
    while (p != Nil)
    {
        if (Info(p) < Info(min)) {
            min = p;
        }
        p = Next(p);
    }
    return min;
}
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */

float Average (List L) {
    // Dictionary
    int sum, count;
    address p;
    // Algorithm
    sum = 0;
    count = 0;
    p = First(L);
    while (p != Nil) 
    {
        sum += Info(p);
        count++;
        p = Next(p);
    }
    return sum * 1.0 / count;
}
/* Mengirimkan nilai rata-rata info(P) */

/****************** PROSES TERHADAP LIST ******************/

void InversList (List *L) {
    // Dictionary
    address p, prec, sucessor;
    // Algorithm
    prec = Nil;
    if (!IsEmpty(*L)) {
        p = First(*L);
        while (p != Nil)
        {
            sucessor = Next(p);
            Next(p) = prec;
            prec = p;
            p = sucessor;
        }
        First(*L) = prec;
    }
}
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */

void Konkat1 (List *L1, List *L2, List *L3) {
    // Dictionary
    address firstlast;
    // Algorithm
    CreateEmpty(L3);
    if (IsEmpty(*L1)) {
        First(*L3) = First(*L2);
    } else {
        First(*L3) = First(*L1);
        firstlast = First(*L1);
        while (Next(firstlast) != Nil)
        {
            firstlast = Next(firstlast);        
        }
        Next(firstlast) = First(*L2);
    }
    First(*L1) = Nil;
    First(*L2) = Nil;
}
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
