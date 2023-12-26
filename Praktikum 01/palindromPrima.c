// NIM: 1822259
// Nama: Muhammad Reffy Haykal
// Tanggal: 12/09/2023
// Topik praktikum: Praktikum 01
// Deskripsi: Membuat program yang mengelurakan bilangan palindrom prima

#include<stdio.h>
int isPrime(int num) { /*Fungsi mencari bilangan prima*/
    /*Dictionary*/
    int i;
    /*Algorithm*/
    if (num < 2) {
        return 0;
    }
    for (i=2; i<num; i++) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int isPalindrome(int num) { /*Fungsi mencari bilangan palindrom*/
    /*Dictionary*/
    int original; 
    int reversed;
    int digit;
    /*Algorithm*/
    original = num;
    reversed = 0;
    while (num > 0) {
        digit = num % 10;
        reversed = reversed * 10 + digit;
        num = num / 10;
    }
    return reversed == original;
}

int nthPrimePalindrome(int n) { /*Fungsi yang membuat outputnya*/
    /*Dictionary*/
    int count;
    int num;
    /*algorithm*/
    count = 0;
    num = 2;
    while (count < n) {
        if (isPrime(num) && isPalindrome(num)) {
            count++;
        }
        num++;
    }
    return num - 1;
}

int main() {
    /*Dictionary*/
    int n, result;
    /*Algorithm*/
    scanf("%d", &n);
    result = nthPrimePalindrome(n);
    printf("%d\n", result);
    return 0;
}