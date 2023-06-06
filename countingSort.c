#include <stdio.h>

int main(void){
    int a[8] = {2,5,3,0,2,3,0,3};
    int max = a[0], n;
    
    //updating max value and n value
    n = sizeof(a)/sizeof(a[0]);
    for(int i=1; i<n; i++){
        if(a[i]>max){
            max = a[i];
        }
    }

    // printf("%d", max);

    int c[max+1], b[n];

    //initializing c & b
    for(int i=0; i<=max; i++){
        c[i] = 0;
    }

    //updating c from a
    for(int j=0; j<n; j++){
        c[a[j]] = c[a[j]] + 1;
    }

    // //updating c from c
    for(int l=1; l<=max; l++){
        c[l] = c[l-1] + c[l];
    }

    for(int k=0; k<n; k++){
        b[c[a[k]]-1] = a[k];
        c[a[k]] = c[a[k]] - 1;
    }

    // //printing sorted array
    for(int m = 0; m<n; m++){
        printf("%d\t", b[m]);
    }

    return 0;
}