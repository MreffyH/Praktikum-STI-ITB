#include<stdio.h>
#include "dividestack.c"
#include "stack.c"

int main() {
    Stack s, oddS, evenS;
    int i;

    CreateEmpty(&s);
    CreateEmpty(&oddS);
    CreateEmpty(&evenS);
    Push(&s,1);
    Push(&s,2);
    Push(&s,3);
    Push(&s,4);
    Push(&s,5);
    Push(&s,6);

    for (i = 0; i <= (s).TOP; i++) {
        printf("%d", s.T[i]);
    }

    printf("\n");

    divideStack(&s, &oddS, &evenS);

    for (i = 0; i <= (s).TOP; i++) {
        printf("%d", s.T[i]);
    }
    printf("\n");
    for (i = 0; i <= (oddS).TOP; i++) {
        printf("%d", oddS.T[i]);
    }
    printf("\n");
    for (i = 0; i <= (evenS).TOP; i++) {
        printf("%d", evenS.T[i]);
    }

    return 0;
}