//queue using Array

#include <stdio.h>

int arr[10], i=0;

void push(int m){
    if(i==10){
        printf("You can't enter more than 10 value.");
        return;
    }
    arr[i] = m;
    i++;

    printf("You've pushed %d.\n", m);
}

int pop(){
    int x = arr[0], j;
    for(j=1; arr[j]!=0; j++){
        arr[j-1] = arr[j];
    }
    arr[j-1] = 0;
    printf("You've popped %d.\n", x);
}

void printQue(){
    printf("Queue is : ");
    for(int k=0; arr[k]!=0; k++){
        printf("%d  ", arr[k]);
    }
    printf("\n");
}

int main(void){

    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

    printQue();

    pop();
    pop();

    printQue();

    return 0;
}
