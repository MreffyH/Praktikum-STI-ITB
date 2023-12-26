#include<stdio.h>
int main() {
    /*Dictionary*/
    int n, x;
    int i;
    int fisrtmax, secondmax;
    /*Algorithm*/
    secondmax = -9999;
    fisrtmax = -9999;
    
    
    scanf("%d", &n);
    
    for (i=0; i<n; i++) {
        printf("%d. ", i+1);
        scanf("%d", &x);
        if (x > fisrtmax) {
            secondmax = fisrtmax; 
            fisrtmax = x;
            printf("1max %d\n", fisrtmax);
        } else if (x > secondmax && x != fisrtmax) {
            secondmax = x;
            printf("%d\n", secondmax);
        }        
    }
    printf("=%d\n", secondmax);
    return 0;
}