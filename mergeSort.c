#include <stdio.h>

void mergeSort(int arr[], int s, int e){
    if(s>=e) return;
    int m = (s+e)/2;
    mergeSort(arr, s, m);
    mergeSort(arr, m+1, e);
    merge(arr, s, m, e);

    /*{5,6,4,1,2,8,7,3,9}*/

}

void merge(int arr[], int s, int mid, int e){
    int n1 = mid-s+1;
    int n2 = e-mid;

    int l[n1], r[n2];

    for(int i=0; i<n1; i++){
        l[i] = arr[s+i];
    }
    for(int j=0; j<n2; j++){
        r[j] = arr[mid+j+1];
    }

    int m = 0, n = 0, k = s;

    while(m<n1 && n<n2){
        if(l[m]<=r[n]){
            arr[k] = l[m];
            m++;
        } else{
            arr[k] = r[n];
            n++;
        }
        k++;
    }

    while(m<n1){
        arr[k] = l[m];
        m++;
        k++;
    }

    while(n<n2){
        arr[k] = r[n];
        n++;
        k++;
    }
}

int main(void){
    int arr[] = {5,6,4,1,2,8,7,3,9};
    int n = sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr, 0, n);

    //printing sorted array
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}
