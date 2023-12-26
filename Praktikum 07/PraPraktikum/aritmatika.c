// NIM: 18222103
// Nama: Muhammad Reffy Haykal
// Tanggal: 24/10/2023
// Topik pra-praktikum: stack
// Deskripsi: Realisasi aritmatika.h

#include<stdio.h>
#include"aritmatika.h"

boolean isOperator(char input) {
    return (input == '+' || input == '-' || input == '*' || input == '/');
}
/* Proses: Mengecek apakah input merupakan operator */
/*         input adalah operator jika input merupakan salah
           satu dari berikut:
                - +
                - -
                - *
                - /
*/

int hitung(int angka1, int angka2, char op) {
    if (op == '+') {
        return angka1 + angka2;
    } else if (op == '-') {
        return angka1 - angka2;
    } else if (op == '*') {
        return angka1 * angka2;
    } else if (op == '/') {
        return angka1 / angka2;
    }
}
/* Proses: Menghitung ekspresi */
/*
    Contoh input / output:
    angka1 : 2
    angka2 : 10
    op     : -

    return : -8 (penjelasan: 2 - 10 = 8)
*/

int eval(char *input, int length) {
    // Dictionary
    Stack arit;
    infotype val1, val2;
    int i;
    // Algoritm
    CreateEmpty(&arit);
    for (i = 0; i < length; i++) {
        if (isOperator(input[i])) {
            Pop(&arit, &val1);
            Pop(&arit, &val2);
            Push(&arit, hitung(val2, val1, input[i]));
        } else {
            Push(&arit, input[i] - '0');
        }
    }
    Pop(&arit, &val1);
    return val1;
}
/* Proses: Menghitung keseluruhan ekspresi */
/* I.S. input adalah string. setiap operand dipastikan < 10 */
/*
    Contoh input / output:
    input   : 23+
    output  : 5 (penjelasan: ekspresi ekuivalen dengan 2 + 3)

    input   : 9423+*5/-
    output  : 5 (penjelasan: ekspresi ekuivalen dengan 9-(4*(2+3))/5)

*/