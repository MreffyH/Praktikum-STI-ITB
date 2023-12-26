// NIM : 18222103
// Nama : Muhammad Reffy Haykal
// Tanggal : 29/11/2023
// Topik praktikum : variasi list linier
// Deskripsi : realisasi setlist.h

#include "setlist.h"

#include<stdio.h>
#include<stdlib.h>

/* ********* Prototype ********* */

address Alokasi (infotype Elmt)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=Elmt, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    address p = (address) malloc (sizeof(ElmtSet));
    Info(p) = Elmt;
    Next(p) = Nil;
    return p;
}

void Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(*P);
}


/* *** Konstruktor/Kreator *** */
void CreateEmpty(Set *S)
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong */
{
    First(*S) = Nil;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Set S)
/* Mengirim true jika Set S kosong*/
{
    return (First(S) == Nil);
}

/* ********** Operator Dasar Set ********* */
void Insert(Set *S, infotype Elmt)
/* Menambahkan Elmt sebagai elemen terakhir Set S. */
/* I.S. S mungkin kosong
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota terakhir dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */
{
    address p, temp;
    p = First(*S);
    temp = Alokasi(Elmt);

    if (!IsMember(*S, Elmt)) {
        if (IsEmpty(*S)) {
            First(*S) = temp;
        } else {
            while (Next(p) != Nil) 
            {
                p = Next(p);
            }
            Next(p) = temp;
            Next(temp) = Nil;
        }
    }
}

void Delete(Set *S, infotype Elmt)
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */
{
    address del, prev;
    del = First(*S);
    prev = Nil;

    if (IsMember(*S, Elmt)) {
        if (Info(del) == Elmt) {
            First(*S) = Next(del);
            Dealokasi (&del);
        } else {
            while (Info(del) != Elmt)
            {
                prev = del;
                del = Next(del);
            }
            Next(prev) = Next(del);
            Dealokasi(&del);
        }
    } 
}

boolean IsMember(Set S, infotype Elmt)
/* Mengembalikan true jika Elmt adalah member dari S */
{
    address p;
    boolean found = false;

    p = First(S);
    while (p != Nil && found == false)
    {
        if (Info(p) == Elmt) {
            found = true;
        } else {
            p = Next(p);
        }
    }
    return found;
}

int Count(Set S)
/* Mengembalikan jumlah elemen/anggota di dalam S*/
{
    int count = 0;
    address p;
    p = First(S);

    while (p != Nil)
    {
        count++;
        p = Next(p);
    }
    return count;
}