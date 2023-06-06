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

//search an Item in the linked list
void searchItem(int val){
    struct node *p = head;
    int count = 1;
    while(p->data != val){
        if(p->next == NULL){
            printf("Sorry! Didn't find any data as your input.\n");
            return;
        }
        p = p->next;
        count++;
    }
    printf("Data found at %d no. node.\n", count);
}

//adding elements in the first position.
void addFirst(int val){
    struct node *newN;
    newN = malloc(sizeof(struct node));
    newN->data = val;
    newN->next = head;
    head = newN;
}

//adding element in the last position
void addLast(int val){
    struct node *newN, *flag;
    flag = head;
    newN = malloc(sizeof(struct node));
    newN->data = val;
    
    while(flag->next!=NULL){
        flag = flag->next;
    }
    flag->next = newN;
    newN->next = NULL;
}

//add node at random place
void addItem(int pVal, int val){
    struct node *p = head, *newN;
    while(p->data!=pVal){
        p = p->next;
    }

    newN = malloc(sizeof(struct node));
    newN->data = val;
    newN->next = p->next;
    p->next = newN;
}

//remove node from the first
void deleteFirst(){
    struct node *flag;
    flag = head;
    head = head->next;
    printf("%d has been removed.\n", flag->data);
    free(flag);
}

//remove node from the last
void deleteLast(){
    struct node *flag = head;
    while(flag->next->next!=NULL){
        flag = flag->next;
    }
    printf("%d has been removed.\n", flag->next->data);
    free(flag->next);
    flag->next = NULL;
}

//remove node from anywhere of that node
void deleteItem(int val){
    //if head is the suspect node
    if(head->data == val){
        deleteFirst();
    }
    struct node *temp = head, *tempO;
    while(temp->next->data !=val){
        temp = temp->next;
    }
    //if temp->next->next is NULL then deleteLast
    //if(te)
    tempO = temp->next;
    temp->next = temp->next->next;
    printf("%d has been removed.\n", tempO->data);
    free(tempO);
}

int main(void){
    head = NULL;

    addFirst(1);
    addFirst(2);
    addFirst(3);
    addFirst(5);
    addFirst(6);
    addFirst(7);

    deleteFirst();
    deleteLast();
    addItem(5, 4);
    deleteItem(4);
    deleteItem(2);

    display(head);
    searchItem(5);

    return 0;
}