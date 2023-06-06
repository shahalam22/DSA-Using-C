#include<stdio.h>

void bubbleSort(int arr[], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i]<arr[j]){
                swap(arr, i, j);
            }
        }
    }
}

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int main(){
    int arr[] = {5,6,4,1,2,8,7,3,9};
    int n = sizeof(arr)/sizeof(arr[0]);

    bubbleSort(arr, n);

    //printing sorted array
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}
