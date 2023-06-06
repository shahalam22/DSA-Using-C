#include <stdio.h>

void selectionSort(int arr[], int n){
    for(int i=0; i<n; i++){
        int min = arr[i];
        int k = i;
        for(int j=i; j<n; j++){
            if(arr[j]<min){
                min = arr[j];
                k = j;
            }
        }
        swap(arr, i, k);
    }
}

void swap(int arr[], int i, int k){
    int temp = arr[i];
    arr[i] = arr[k];
    arr[k] = temp;
}

int main(void){
    int arr[] = {5,6,4,1,2,8,7,3,9};
    int n = sizeof(arr)/sizeof(arr[0]);

    selectionSort(arr, n);

    //printing sorted array
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}
