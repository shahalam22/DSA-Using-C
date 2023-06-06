//Deque is a type of queue which puts input and takes output from both side [front & rear]
//this is the code of Output Restricted Deque which gives permission to output from just one side. In this code we take the FRONT SIDE for output.

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

//adding elements in the first position.
void pushF(int val){
    struct node *newN;
    newN = malloc(sizeof(struct node));
    newN->data = val;
    newN->next = head;
    head = newN;
}

//adding element in the last position
void pushB(int val){
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
    
    pushF(5);
    pushF(4);
    pushF(3);
    pushF(2);
    pushF(1);
    pushB(6);
    pushB(7);
    pushB(8);
 
    display(head);

    pool();
    pool();

    display(head);

    return 0;
}