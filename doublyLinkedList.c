#include <stdio.h>
#include <stdlib.h>

struct node *head;
struct node *tail;

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

//display the values of linked-List
void displayForward(struct node *flag){
    int count = 0;
    while(flag->next!=NULL){
        printf("%d->", flag->data);
        flag = flag->next;
        count++;
    }
    printf("%d\n", flag->data);
    printf("Total node is : %d.\n", count+1);
}

void displayBackward(struct node *flag){
    int count = 0;
    while(flag->prev!=NULL){
        printf("%d->", flag->data);
        flag = flag->prev;
        count++;
    }
    printf("%d\n", flag->data);
    printf("Total node is : %d.\n", count+1);
}

//search an Item in the linked list
void searchItemF(int val){
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
    printf("Data found at %d no. node from front.\n", count);
}

void searchItemB(int val){
    struct node *p = tail;
    int count = 1;
    while(p->data != val){
        if(p->prev == NULL){
            printf("Sorry! Didn't find any data as your input.\n");
            return;
        }
        p = p->prev;
        count++;
    }
    printf("Data found at %d no. node from back.\n", count);
}

//adding elements in the first position.
void addFirst(int val){
    struct node *newN;
    newN = malloc(sizeof(struct node));
    newN->data = val;
    newN->next = head;
    newN->prev = NULL;
    if(head != NULL){
        head->prev = newN;
    }
    if(head == NULL){
        tail = newN;
    }
    head = newN;
}

//adding element in the last position
void addLast(int val){
    struct node *newN, *flag = tail;
    newN = malloc(sizeof(struct node));
    newN->data = val;
    newN->next = NULL;
    newN->prev = flag;
    flag->next = newN;
    tail = newN;
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
    newN->prev = p;
    p->next->prev = newN;
    p->next = newN;
}

//remove node from the first
void deleteFirst(){
    struct node *flag;
    flag = head;
    head->next->prev = NULL;
    head = head->next;
    printf("%d has been removed.\n", flag->data);
    free(flag);
}

//remove node from the last
void deleteLast(){
    struct node *flag = tail;
    tail->prev->next = NULL;
    tail = tail->prev;
    flag->next = NULL;
    flag->prev = NULL;
    printf("%d has been removed.\n", flag->data);
    free(flag);
}

//remove node from anywhere of that node
void deleteItem(int val){
    //if head is the suspect node
    if(head->data == val){
        deleteFirst();
        return;
    }
    if(tail->data == val){
        deleteLast();
        return;
    }
    struct node *temp = head, *tempO;
    while(temp->next->data !=val){
        temp = temp->next;
    }
    tempO = temp->next;
    tempO->next->prev = temp;
    temp->next = tempO->next;
    tempO->next = NULL;
    tempO->prev = NULL;
    printf("%d has been removed.\n", tempO->data);
    free(tempO);
}

int main(void){
    head = NULL;
    tail = NULL;

    addFirst(1);
    addFirst(2);
    addFirst(3);
    addFirst(5);
    addFirst(6);
    addFirst(7);
    addLast(8);
    addLast(9);
    addLast(10);

    addItem(5,4);

    deleteFirst();

    deleteLast();

    deleteItem(3);

    displayForward(head);
    displayBackward(tail);

    searchItemF(6);
    searchItemB(6);

    return 0;
}