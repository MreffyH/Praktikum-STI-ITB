#include<stdlib.h>
#include<stdio.h>
#include "arraydin.h"

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran InitialSize
 */
ArrayDin MakeArrayDin() {
    // LOCAL DICTIONARY
    ArrayDin arr;
    // ALGORITHM
    arr.A = (ElType*) malloc(InitialSize * sizeof(ElType));
    arr.Capacity = InitialSize;
    arr.Neff = 0;
    return arr;
}

/**
 * Destruktor
 * I.S. ArrayDin terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateArrayDin(ArrayDin *array) {
    free(array->A);
    array->Neff = 0;
}

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmpty(ArrayDin array) {
    return(array.Neff = 0);
}

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length(ArrayDin array) {
    return (array.Neff);
}

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
ElType Get(ArrayDin array, IdxType i) {
    return (array.A[i]);
}

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacity(ArrayDin array) {
    return (array.Capacity);
}

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAt(ArrayDin *array, ElType el, IdxType i) {
    // LOCAL DICTIONARY
    ElType* temparr = (ElType*)malloc((*array).Capacity*sizeof(ElType));
    IdxType j;
    // ALGORITHM
    if ((*array).Neff < (*array).Capacity) {
        for (j = (*array).Neff; j > i; j--) {
            (*array).A[j] = (*array).A[j-1];
        }
        (*array).A[i] = el;
        (*array).Neff++;
    }
    else { 
        for (j = 0; j < (*array). Capacity; j++) {
            temparr[j] = (*array).A[j];
        }
        free(array->A);
        (*array).A = (ElType*)malloc((*array).Capacity*2*sizeof(ElType));
        for (j = 0; j < i; j++) {
            (*array).A[j] = temparr[j];
        }      
        (*array).A[i] = el;
        for (j = i; i <= (*array).Capacity; j++) {
            (*array).A[j+1] = temparr[j];
        } 
        free(temparr);
        (*array).Neff++;
        (*array).Capacity *= 2;
    }
} 

/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAt(ArrayDin *array, IdxType i) {
    // LOCAL DICTIONARY
    IdxType j=0;
    // ALGORITHM
    (*array).Neff--;
    for (j = i; j <= (*array).Neff; j++) {
        (*array).A[j] = (*array).A[j+1];
    }
}