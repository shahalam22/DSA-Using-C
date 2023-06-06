//Deque is a type of queue which puts input and takes output from both side [front & rear]
//this is the code of Input Restricted Deque which gives permission to put input in just one side. In this code we take the BACK SIDE for input.

#include <stdio.h>
#include <stdlib.h>

struct node *head;

struct node{
    int data;
    struct node *next;
};

//display the values of linked-List
void display(struct node *flag){
    int count = 0;
    while(flag->next!=NULL){
        printf("%d->", flag->data);
        flag = flag->next;
        count++;
    }
    printf("%d\n", flag->data);
    printf("Total node is : %d.\n", count+1);
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
void poolF(){
    struct node *flag;
    flag = head;
    head = head->next;
    printf("%d has been removed.\n", flag->data);
    free(flag);
}

//remove node from the last
void poolB(){
    struct node *flag = head;
    while(flag->next->next!=NULL){
        flag = flag->next;
    }
    printf("%d has been removed.\n", flag->next->data);
    free(flag->next);
    flag->next = NULL;
}

int main(void){
    head = NULL;
    
    push(5);
    push(4);
    push(3);
    push(2);
    push(1);
 
    display(head);

    poolF();

    display(head);

    poolB();

    display(head);
}