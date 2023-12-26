#include <stdio.h>

int main() {
    /* Dictionary */
    int n;
    int i, j;
    int spasi;
    int baris;

    /* Input n */
    scanf("%d", &n);

    /* Cetak segitiga sama sisi */
    for (baris = 1; baris <= n; baris++) {
        // Cetak spasi
        for (spasi = 1; spasi <= n - baris; spasi++) {
            printf(" ");
        }

        // Cetak tanda "*"
        for (i = 1; i <= 2 * baris - 1; i++) {
            printf("*");
        }

        // Pindah ke baris berikutnya
        printf("\n");
    }

    /* Cetak segitiga sama sisi yang terbalik */
    for (baris = n; baris >= 1; baris--) {
        // Cetak spasi
        for (spasi = 1; spasi <= n - baris; spasi++) {
            printf(" ");
        }

        // Cerak tanda "*"
        for (i = 1; i <= 2* baris - 1; i++) {
            printf("*");
        }

        // Pindah ke baris berikutnya
        printf("\n");
    }

    return 0;
}
