#include <stdio.h>

int main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9}, i=0, j=0, a = 5;
    for(i=0; i<10; i++){
        if(arr[i]==a){
            printf("index is : %d.\n", i);
        }
    }
}
