#include "mesinKarakter.h"
#include<stdio.h>

int countFreq(char a) {
    // Dictionary
    int count;
    // Algorithm
    STARTKATA();
    while (currentChar != MARK) {
        if ((GetCC() == 'a' || GetCC() == 'A') && (currentChar != 'a' || currentChar != 'A')) {
            count++;
        }
    }

}
int main() {
    // Dictionary
    int freq;
    // Algorithm
    START();
}