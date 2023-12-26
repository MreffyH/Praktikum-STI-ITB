// NIM: 18222103
// Nama: Muhammad Reffy Haykal
// Tanggal: 24/10/2023
// Topik pra-praktikum: set & map
// Deskripsi: Realisasi set.h

#include "set.h"

/* Definisi Set S kosong : S.Count = Nil */
/* S.Count = jumlah element Set */
/* S.Elements = tempat penyimpanan element Set */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Set *S) {
    (*S).Count = Nil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Set S) {
    return S.Count == Nil;
}
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */

boolean IsFull(Set S) {
    return S.Count == MaxEl;
}
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */

/* ********** Operator Dasar Set ********* */
void Insert(Set *S, infotype Elmt) {
    if (IsMember(*S, Elmt)) {
        return ;
    }
    (*S).Elements[S->Count] = Elmt;
    S->Count++;
}
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

void Delete(Set *S, infotype Elmt) {
    boolean found = false;
    address idx = 0;
    address p;
    if (!IsMember(*S, Elmt)) {
        return;
    }
    while (found == false && idx < S->Count) 
    {
        if (S->Elements[idx] == Elmt) {
            found = true;
        }
        else {
            idx++;
        }
    }
    for (p = idx + 1; p < S->Count; p++) {
        S->Elements[p - 1] = S->Elements[p];
    }
    S->Count--;
}
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

boolean IsMember(Set S, infotype Elmt) {
    boolean found = false;
    address idx = 0;
    while (found == false && idx < S.Count) 
    {
        if (S.Elements[idx] == Elmt) {
            found = true;
        } else {
            idx++;
        }
    }
    return found;
}
/* Mengembalikan true jika Elmt adalah member dari S */