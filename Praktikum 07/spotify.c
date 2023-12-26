// NIM : 18222103
// Nama : Muhammad Reffy Haykal
// Tanggal : 30/10/2023
// Topik praktikum : stack
// Deskripsi : membuat program pemutaran lagu

#include <stdio.h>
#include "stack.h"

int main() {
    // Dictionary
    int n, q, x, id, dump; 
    Stack lagu; 
    // Algorithm
    scanf("%d", &n);
    char data[n][20];
    for(int i = 0; i < n; i++)
    {
        scanf("%s", data[i]);
    }

    CreateEmpty(&lagu);
    scanf("%d", &q);
    while (q--)
    { 
        scanf("%d", &x);
        if(x == 1) {
            scanf("%d", &id);
            Push(&lagu, id);
            printf("Playing: %s\n", data[id]);
        } else {
            if(IsEmpty(lagu)) {
                printf("No music is played\n");
            } else { 
                Pop(&lagu, &dump);
                if(IsEmpty(lagu)) {
                    printf("No music is played\n");
                } else {
                    printf("Playing: %s\n", data[Top(lagu)]);
                }
            }
        }
    }
}