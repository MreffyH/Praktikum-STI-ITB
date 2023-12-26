#include "warehouse.h"

void manageWareHouse(Map *wareHouse) {
    int i;
    int operasi;
    int n, temp;
    operasi = 0;
    while (operasi != 4) 
    {
        scanf("%d\n", &operasi);
        if (operasi == 1) {
            for (i = 0; i < wareHouse->Count; i++) {
                printf("Bahan %d: %d\n", i+1, Value(*wareHouse, i));
            }
        } else if (operasi == 2) {
            int length = 0;
            scanf("%d\n", &n);
            temp = n;
            while (temp > 0)
            {
                temp /= 10;
                length++;
            }
            int number[length];
            for (i = length - 1; i >= 0; i--) {
                number[i] = n % 10;
                n = n / 10;
            }
            for (i = 0; i < length; i++) {
                keytype key = number[i];
                valuetype currentvalue = Value(*wareHouse, key);
                if (currentvalue - 1 < 0) {
                    printf("Stok bahan %d sudah habis\n", key);
                } else {
                    Delete(wareHouse, key);
                    Insert(wareHouse, key, currentvalue - 1);
                }
            }
        } else if (operasi == 3) {
            int length = 0;
            scanf("%d\n", &n);
            temp = n;
            while (temp > 0)
            {
                temp /= 10;
                length++;
            }
            int number[length];
            for (i = length - 1; i >= 0; i--) {
                number[i] = n % 10;
                n = n / 10;
            }
            for (i = 0; i < length; i++) {
                keytype key = number[i];
                valuetype currentvalue = Value(*wareHouse, key);
                Delete(wareHouse, key);
                Insert(wareHouse, key, currentvalue + 1);
                
            }
        }
    }
}
/*
I.S. variable wareHouse sudah terisi dengan bahan-bahan

Buatlah program yang melakukan pengelolaan terhadap gudang bahan makanan. Program akan menerima input sebuah integer antara angka 1 hingga 4. Program akan berhenti apabila input yang diterima bernilai 4.

Untuk keterangan input dan bagaimana proses pengelolaan, dapat dilihat dalam soal
*/