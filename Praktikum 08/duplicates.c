// NIM : 18222103
// Nama : Muhammad Reffy Haykal
// Tanggal : 04/11/2023
// Topik praktikum : set, map, dan hash
// Deskripsi : realisasi duplicate.h

#include"duplicates.h"

boolean hasDuplicate(int n, int *nums, int k) {
    int i, distance;
    HashMap data;
    CreateEmpty(&data);
    for (i = 0; i < n; i++) {
        if (Value(data, nums[i]) == Undefined) {
            Insert(&data, nums[i], i);
        } else {
            distance = i - Value(data, nums[i]);
            if (distance <= k) {
                return true;
            }
            data.Elements[Hash(nums[i])].Value = i;
        }
    }
    return false;
}
/* I.S Array nums bisa kosong, n merupakan panjang array nums, k merupakan integer positif */
/* F.S Mengembalikan boolean apabila terdapat duplicate number pada rentang k di array nums. 
Apabila nums kosong atau hanya 1 elemen maka mengembalikan nilai false */
/* 
  Contoh:
- nums: [5, 6, 8, 2, 4, 6, 9]
  k: 4

  return: true
  Penjelasan: Elemen 6 berulang dengan jarak 4 yang mana <= k

- nums: [5, 6, 8, 2, 4, 6, 9]
  k: 2

  return: false
  Penjelasan: Tidak ada elemen berulang dengan jarak k = 2
*/