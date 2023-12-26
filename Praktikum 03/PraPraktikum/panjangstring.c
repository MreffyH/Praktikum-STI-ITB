#include "panjangstring.h"
#include<stdio.h>

// menerima argumen pointer kepada karakter pertama dari sebuah string yang panjangnya tidak diketahui
// dan memberikan output berupa panjang string tersebut, dengan batasan string input memiliki karakter
// '\0' pada akhir string
int panjangString(char*c) {
    //DICTIONARY
    int lenght = 0;
    //ALGORITHM
    while (*c != '\0') {
        lenght++;
        c++;
    }
    return lenght;
}