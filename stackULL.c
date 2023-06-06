//queue using LINKED LIST

#include <stdio.h>
#include <stdlib.h>

struct node *head;

struct node{
    int data;
    struct node *next;
};

//display the values of stack
void display(struct node *flag){
    // int count = 0;
    while(flag->next!=NULL){
        printf("%d->", flag->data);
        flag = flag->next;
        // count++;
    }
    printf("%d\n", flag->data);
    // printf("Total node is : %d.\n", count+1);
}

//adding elements in the first position.
void push(int val){
    struct node *newN;
    newN = malloc(sizeof(struct node));
    newN->data = val;
    newN->next = head;
    head = newN;
}

//remove node from the first
void pop(){
    struct node *flag;
    flag = head;
    head = head->next;
    printf("%d has been removed.\n", flag->data);
    free(flag);
}

int main(void){
    head = NULL;

    push(5);
    push(4);
    push(3);
    push(2);
    push(1);

    display(head);

    pop();
    pop();

    display(head);

    return 0;
}