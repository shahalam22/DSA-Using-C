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
    while(flag->next!=head){
        printf("%d->", flag->data);
        flag = flag->next;
        count++;
    }
    printf("%d\n", flag->data);
    printf("Total node is : %d.\n", count+1);
}

//add node at random place
void addItem(int val){
    struct node *p = head, *newN;

    newN = malloc(sizeof(struct node));
    newN->data = val;

    if(head==NULL){
        head = newN;
        newN->next = head;
        return;
    }

    while(p->next!=head){
        p = p->next;
    }

    newN->next = p->next;
    p->next = newN;
}

//remove node from anywhere of that node
void deleteItem(int val){
    struct node *temp = head, *tempO;

    while(temp->next->data !=val){
        temp = temp->next;
    }

    tempO = temp->next;
    temp->next = temp->next->next;
    printf("%d has been removed.\n", tempO->data);
    free(tempO);
}

int main(void){
    head = NULL;

    addItem(1);
    addItem(2);
    addItem(3);
    addItem(5);
    addItem(6);
    addItem(7);
    
    display(head);

    deleteItem(2);
    deleteItem(6);
    
    display(head);
    
    return 0;
}