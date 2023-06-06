#include <stdio.h>

int binarySearch(int arr[10], int a, int s, int e){
    int start = s;
    int end = e;
    int mid = (s+e)/2;
    if(arr[mid]==a) return mid;
    else if(arr[mid]>a){
        binarySearch(arr, a, s, mid-1);
    }
    else {
        binarySearch(arr, a, mid+1, e);
    }
}

int main(void){
    int arr[10] = {1,2,3,4,5,6,7,8,9};
    int ans = binarySearch(arr, 8, 0, 10);
    printf("%d\n", ans);
    return 0;
}
