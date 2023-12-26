// NIM: 18222103
// Nama: Muhammad Reffy Haykal
// Tanggal: 24/10/2023
// Topik pra-praktikum: set & map
// Deskripsi: Realisasi map.h

#include<stdio.h>
#include "map.h"

/* Definisi Map M kosong : M.Count = Nil */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Map *M) {
    M->Count = Nil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Map M) {
    return M.Count == Nil;
}
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

boolean IsFull(Map M) {
    return M.Count == MaxEl;
}
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

/* ********** Operator Dasar Map ********* */
valuetype Value(Map M, keytype k) {
    address idx;

    if (!IsMember(M, k)) {
        return Undefined;
    } else {
        for (idx = 0; idx < M.Count; idx++)
        {
            if (M.Elements[idx].Key == k) {
                return M.Elements[idx].Value;
            }
        }
    }
}
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void Insert(Map *M, keytype k, valuetype v) {
    if (!IsMember(*M, k)) {
        M->Elements[M->Count].Key = k;
        M->Elements[M->Count].Value = v;
        M->Count++;
    }
}
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void Delete(Map *M, keytype k) {
    address idx = 0;

    if (IsMember(*M, k)) {
        while (M->Elements[idx].Key != k) 
        {
            idx++;
        }
        while (idx < M->Count) {
            M->Elements[idx] = M->Elements[idx + 1];
            idx++;
        }
        M->Count--;
    }
}
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean IsMember(Map M, keytype k) {
    boolean found = false;
    address idx = 0;

    while (found == false && idx < M.Count) 
    {
        if (M.Elements[idx].Key == k) {
            found = true;
        } else {
            idx++;
        }
    }
    return found;
}
/* Mengembalikan true jika k adalah member dari M */