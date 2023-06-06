#include <stdio.h>

int size = 0, sizeForSort;

//swap method
void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

//heapify method for making heap
void heapify(int arr[], int size, int i){
    if(size==1){
        printf("This is a one element array!\n");
    }
    else {
        int val = i;
        int l = 2*i + 1;
        int r = 2*i + 2;
        if(l<size && arr[l]>arr[val]){
            val = l;
        }
        if(r<size && arr[r]>arr[val]){
            val = r;
        }
        if(val != i){
            swap(arr, i, val);
            heapify(arr, size, val);
        }
    }
}

//inserting value at heap
void insertValue(int arr[], int val){
    if(size == 0){
        arr[0] = val;
        size += 1;
    }
    else{
        arr[size] = val;
        size += 1;
        for(int i=(size/2)-1; i>=0; i--){
            heapify(arr, size, i);
        }
    }
}

//deleting value from heap
void deleteValue(int arr[], int num){
    int i;
    for(i=0; i<size; i++){
        if(arr[i]==num){
            break;
        }
    }
    swap(arr, i, size-1);
    arr[size-1] = 0;
    size -= 1;
    for(int j=(size/2)-1; j>=0; j--){
        heapify(arr, size, j);
    }
}

//printing heap array
void printHeap(int arr[]){
    for(int i=0; i<size; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

//heap maximum value
void heapMax(int arr[]){
    printf("Max value of the heap is - %d", arr[0]);
}

//sorting using heap
void heapSort(int arrE[]){
    int sizeForSort = size;
    int arrB[size], arrA[size];

    //we are using copy of our main array. Because as we run this sort our main array disappeares as we run deletevalue funtion till size reaches
    // we also update main size for not being any effect over the main size and main array. Later we could do other task with our main size and main array.
    for(int i=0; i<size; i++){
        arrA[i] = arrE[i];
    }

    //here another method has been called, HEAP-EXTRACT-MAX [which method returns max-value at every iteration]
    for(int i=0; i<sizeForSort; i++){
        arrB[sizeForSort-i-1] = arrA[0];
        deleteValue(arrA, arrA[0]);
    }
    
    printf("Sorted arr is - ");
    for(int i=0; i<sizeForSort; i++){
        printf("%d\t", arrB[i]);
    }
    printf("\n");

    //updating size as previous because size been reduced as we used deletevalue
    size = sizeForSort;
}

int main(void){
    int arr[10];

    insertValue(arr, 1);
    insertValue(arr, 2);
    insertValue(arr, 3);
    insertValue(arr, 4);
    insertValue(arr, 5);
    insertValue(arr, 6);
    insertValue(arr, 7);

    printHeap(arr);

    deleteValue(arr, 4);

    printHeap(arr);

    heapSort(arr);

    printHeap(arr);

    heapMax(arr);

    return 0;
}