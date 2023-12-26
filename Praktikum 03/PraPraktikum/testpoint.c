#include<stdio.h>
#include "point.h"
#include "point.c"

int main() {
    POINT P1, P2, P3, P4;
    P4 = MakePOINT(1.0, 2.0);
    TulisPOINT(P4);
    printf("\n");
    printf("Input the first x y: ");
    BacaPOINT(&P1);
    printf("The first coordinate (P1) is ");
    TulisPOINT(P1);
    printf("\n");
    printf("Input the second x y: ");
    BacaPOINT(&P2);
    printf("The second coordinate (P2) is ");
    TulisPOINT(P2);
    printf("\n");
    if (EQ(P1, P2)) {
        printf("P1 and P2 in the same coordinate\n");
    } else if (NEQ(P1, P2)){ 
        printf("P1 and P2 not in the same\n");
    }
    printf("The distance between P1 with 0,0 is %0.2f\n", Jarak0(P1));
    
    printf("The distance between P1 with P2 is %.2f\n", Panjang(P1, P2));
    
    if (IsOrigin(P1)) {
        printf("P1 is in the origin coordinate (0, 0)\n");
    } else if (IsOnSbX(P1)) {
        printf("P1 is in the x line\n");
    } else if (IsOnSbY(P1)) {
        printf("P1 is in the y line\n");
    }
    printf("P1 is in quadrant %d\n", Kuadran(P1));
    printf(" \n");
    printf("Now, we will add the P1 coordinate with P3 (1, 2) coordinate\n");
    P3 = PlusDelta(P1, 1, 2);
    printf("Now, the new coordinate is ");
    TulisPOINT(P3);
    printf(" \n");
    printf("Now, we will shift the P1 coordinate with P3 (1, 2) coordinate\n");
    Geser(&P1, 1, 2);
    printf("Now, the new coordinate is ");
    TulisPOINT(P1);

}