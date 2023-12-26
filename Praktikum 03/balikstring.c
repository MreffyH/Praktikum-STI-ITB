#include "balikstring.h"
#include<stdio.h>

// Menerima argumen pointer yang merupakan sebuah string
// Mengembalikan panjang string
int panjangString(char* ch) {
    int count = 0;
    while (*ch != '\0') {
        count++;
        ch++;
    }
    return count;
}

// Menerima argumen pointer yang merupakan sebuah string (diasumsikan tidak ada huruf kapital)
// Parameter str merupakan string yang akan dibalik
// Contoh : str adalah "slevel" maka akan terubah menjadi "levels"
void membalikString(char* str) {
    // Dictionary
    int lenght = panjangString(str);
    char* start = str;
    char* end = str + lenght - 1;
    char temp;
    // Algorithm
    while (start < end) {
        // start swapping
        temp = *start;
        *start = *end;
        *end = temp;

        // Move the pointer towards each other
        start++;
        end--;
    }
}