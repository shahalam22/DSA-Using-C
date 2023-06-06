#include <stdio.h>

void insertionSort(int arr[], int n){
    for(int i=1; i<n; i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0){
            if(arr[j]>key){
                arr[j+1] = arr[j];
            }
            if(arr[j]<key){
                arr[j+1] = key;
                break;
            }
            j--;
        }
        arr[j+1] = key;
    }
}

int main(void){
    int arr[] = {5,6,4,1,2,8,7,3,9};
    int n = sizeof(arr)/sizeof(arr[0]);

    insertionSort(arr, n);

    //printing sorted array
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}
