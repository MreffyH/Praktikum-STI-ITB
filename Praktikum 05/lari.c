// NIM : 18222103
// Nama : Muhammad Reffy Haykal
// Tanggal : 30/11/2023
// Topik praktikum : mseinkata dan mesinkarakter
// Deskripsi : realisasi lari.h

#include"lari.h"

#include<stdio.h>
#include<stdlib.h>

int energy;
boolean punch = false;
boolean block = false;

void Running()
/*
Fungsi ini untuk menjalankan lari. Dalam fungsi ini akan menerima input energy dan menerima bentuk track.

Setelah mendapatkan track, dilakukan pengecekan tiap current character dan melakukan sesuai dengan instruksi hingga kondisi berahkir.

Ketika berakhir keluarkan output "FINISH" bila berhasil dan "FAIL" bila gagal. Selain itu keluarkan juga sisa ENERGY. "ENERGY 0"

Contoh output:
FAIL
ENERGY -1

NOTE:
1. Kondisi berakhir adalah:
  - Pelari sampai ke garis finish (current character berada di '.' atau EOP )
  - Pelari tidak bisa melewati BLOCK (energy = -1)
  - Pelari kehabisan energy
*/
{
    scanf("%d", &energy);
    START();

    while (!EOP)
    {
        if (currentChar == '-') {
            IsPath(currentChar);
        } else if (currentChar == '#') {
            IsBlock(currentChar);
        } else if (currentChar == '@') {
            IsPunch(currentChar);
        } else if (currentChar == '>') {
            IsPokari(currentChar);
        } 

        if ((block == false) && (energy > 0)) {
            ADV();
        } else {
            EOP = true;
        }
    }
    energy--;
    if (energy >= 0) {
        printf("FINISH\n");
        printf("ENERGY %d\n", energy);
    } else {
        if (block == false) {
            energy++;
            printf("FAIL\n");
            printf("ENERGY %d\n", energy);
        } else {
            printf("FAIL\n");
            printf("ENERGY %d\n", energy);
        }
    }
}

void IsBlock(char currentChar)
/*
Fungsi mengecek apakah current character '#'.
Apabila iya maka:
1. Jika memiliki skill PUNCH:
  - dapat melewati block dengan memukulnya
  - skill punch digunakan sehingga sudah tidak memiliki skill punch
  - energy berkurang 1
2. Jika tidak, energy menjadi -1.
*/
{
    if (punch == false) {
        block = true;
        energy = 0;
    } else {
        punch = false;
        energy--;
    }
}

void IsPunch(char currentChar)
/*
Fungsi mengecek apakah current character '@'.
Apabila iya maka:
1. mendapatkan skill punch
2. energy berkurang 1

NOTE:
PUNCH tidak stack.
*/
{
    if (punch == false) {
        punch = true;
        energy--;
    }
}

void IsPokari(char currentChar)
/*
Fungsi mengecek apakah current character '>'.
Jika iya, maka menambahkan energy 1.


CONTOH 1:
ENERGY 2
TRACK ->-.

EXPLAIN:
1. - Energy berkurang 1, current energy 1
2. > Energy bertambah 1, current energy 2
3. - Energy berkurang 1, current energy 1
4. . Energy berkurang 1, current energy 0


CONTOH 2:
ENERGY 2
TRACK ->>-.

EXPLAIN:
1. - Energy berkurang 1, current energy 1
2. > Energy bertambah 1, current energy 2
3. > Energy bertambah 1, current energy 3
4. - Energy berkurang 1, current energy 2
5. . Energy berkurang 1, current energy 1
*/
{
    energy++;
}

void IsPath(char currentChar)
/*
Fungsi mengecek apakah current character '-'
Jikya iya maka:
1. energy berkurang 1.
*/
{
    energy--;
}