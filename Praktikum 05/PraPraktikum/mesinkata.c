#include "mesinkata.h"
#include<stdio.h>

boolean EndWord;
Word currentWord;

void IgnoreBlanks() {
    if (currentChar == BLANK) {
        ADV();
    }
}

void STARTWORD() {
    START();
    IgnoreBlanks();
    if (currentChar == MARK) {
        EndWord = true;
    } else {
        EndWord = false;
        ADVWORD();
    }
}

void ADVWORD() {
    IgnoreBlanks();
    if (currentChar == MARK) {
        EndWord = true;
    } else {
        EndWord = false;
        CopyWord();
    }
}

void CopyWord() {
    int i;
    i = 0;
    while (currentChar != BLANK && currentChar != MARK) {
        if (i < NMax) {
            currentWord.TabWord[i] = currentChar;
            i++;
        }
        ADV();
    }
    currentWord.Length = i;
    
}