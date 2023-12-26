// NIM : 18222103
// Nama : Muhammad Reffy Haykal
// Tanggal : 01/12/2023
// Topik praktikum : queue
// Deskripsi : program simulasi pemutaran lagu

#include "circular_queue.h"

#include<stdio.h>

int main() {
    /* Dictionary */
    int n, m, i, j, k, input, val;
    boolean loop, valid;
    Queue lagu;
    /* Algortihm */
    CreateQueue(&lagu);
    scanf("%d %d", &n, &m);
    int playlist[m][3];

    for (i = 0; i < m; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &playlist[i][j]);
        }
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < 3; j++) {
            if (playlist[i][j] < 0 || playlist[i][j] > n-1) {
                valid = false;
            }
        }
    }

    if (valid == true) {
        while (valid == true) 
        {
            scanf("%d", &input);

            if (input == 0) {
                valid = false;
            } else if (input == 1) {
                if (IsEmpty(lagu)) {
                    printf("Tidak ada lagu\n");
                } else {
                    val = dequeue(&lagu);
                    printf("Play lagu %d\n", val);
                    if (loop == true)
                    {
                        enqueue(&lagu, val);
                    }
                }
            } else if (input == 2)  {
                if (loop == true)  {
                    printf("Tidak looping lagu\n");
                    loop = false;
                } else {
                    printf("Looping lagu\n");
                    loop = true;
                }
            } else if (input == 3) {
                scanf("%d", &val);

                if (IsFull(lagu)) {
                    printf("Queue penuh\n");
                } else {
                    if (val >= 0 && val < n) {
                        enqueue(&lagu, val);
                    } else {
                        printf("Lagu tidak valid\n");
                    }
                }
            } else if (input == 4) {
                scanf("%d", &k);

                if (k >= 0 && k < m) {
                    for (i = 0; i < 3; i++) {     
                        if (IsFull(lagu)) {
                            printf("Queue penuh\n");
                            break;
                        } else {
                            enqueue(&lagu, playlist[k][i]);
                        }
                    }
                } else {
                    printf("Playlist tidak valid\n");
                }
            }
        }
    } else {
        printf("Playlist tidak valid\n");
    }

    return 0;
}