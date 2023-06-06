#include <stdio.h>
#include <stdlib.h>

struct node *root;

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(int val){
    struct node *newN;
    newN = malloc(sizeof(struct node));
    newN->data = val;
    newN->left = NULL;
    newN->right = NULL;

    return newN;
}

void insertLeft(struct node *p, int val){
    p->left = createNode(val);
}

void inserRight(struct node *p, int val){
    p->right = createNode(val);
}

int main(void){

    root = createNode(1);

    insertLeft(root, 2);
    inserRight(root, 3);
    insertLeft(root->left, 4);
    inserRight(root->left, 5);
    insertLeft(root->right, 6);
    inserRight(root->right, 7);
    

    return 0;
}