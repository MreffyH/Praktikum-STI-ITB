#include<stdio.h>
#include "mesinkata.h"

int main() {
    // Dictionary
    Word kata1, kata2;
    int sum;

    // Algorithm
    STARTWORD();

    kata1 = currentWord;
    
    ADVWORD();
    while (!isEndWord()) 
    {
        ADVWORD();
    }

    kata2 = currentWord;

    sum = kata1.Length + kata2.Length;
    printf("%d\n", sum);
}