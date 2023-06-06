//queue using LINKED LIST

#include <stdio.h>
#include <stdlib.h>

struct node *head;

struct node{
    int data;
    struct node *next;
};

//display the values of queue
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

//adding element in the last position
void push(int val){
    struct node *newN, *flag;
    flag = head;
    newN = malloc(sizeof(struct node));
    newN->data = val;
    if(head == NULL){
        newN->next = NULL;
        head = newN;
        return;
    }
    while(flag->next!=NULL){
        flag = flag->next;
    }
    flag->next = newN;
    newN->next = NULL;
}

//remove node from the first
void pool(){
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

    pool();
    pool();

    display(head);

    return 0;
}
