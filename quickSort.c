#include <stdio.h>

void quickSort(int arr[], int s, int e){
    if(s<e){
        int pivot = partition(arr, s, e);
        quickSort(arr, s, pivot-1);
        quickSort(arr, pivot+1, e);
    }
}

int partition(int arr[], int s, int e){
    int pivot = arr[e];
    int i = s-1;
    for(int j=s; j<e; j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i+1, e);

    return i+1;
}

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int main(void){
    int arr[] = {5,6,4,1,2,8,7,3,9};
    int n = sizeof(arr)/sizeof(arr[0]);

    quickSort(arr, 0, n-1);

    //printing sorted array
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}
