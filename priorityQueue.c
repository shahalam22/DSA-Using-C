//Priority queue using LINKED LIST

#include <stdio.h>
#include <stdlib.h>

struct node *head;

struct node{
    int data;
    int prio;
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

//pushing values according to priority
void push(int val, int pVal){
    struct node *p = head, *newN;
    
    newN = malloc(sizeof(struct node));
    newN->data = val;
    newN->prio = pVal;

    if(head == NULL){
        newN->next = NULL;
        head = newN;
        return;
    }

    if(head->prio < pVal){
        newN->next = head;
        head = newN;
        return;
    }

    while(p->next != NULL){
        if(p->next->prio < pVal){
            newN->next = p->next;
            p->next = newN;
            return;
        }
        p = p->next;
    }

    newN->next = p->next;
    p->next = newN;
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

    push(5,5);
    push(4,6);
    push(3,7);
    push(2,8);
    push(1,3);
 
    display(head);

    pool();
    pool();

    display(head);

    return 0;
}