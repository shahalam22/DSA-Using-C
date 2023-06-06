#include <stdio.h>
#include <stdlib.h>

struct node *root;

struct node{
    int data;
    struct node *left;
    struct node *right;
};

//creating binary tree
//creating node
struct node* createNode(int val){
    struct node *newN;
    newN = malloc(sizeof(struct node));
    newN->data = val;
    newN->left = NULL;
    newN->right = NULL;

    return newN;
}
//inserting value at left of parent
void insertLeft(struct node *p, int val){
    p->left = createNode(val);
}
//inserting value at right of parent
void inserRight(struct node *p, int val){
    p->right = createNode(val);
}

//traversal
//inorder traversal
void inOrder(struct node *p){
    if(p == NULL){
        return;
    }
    inOrder(p->left);
    printf("%d\t", p->data);
    inOrder(p->right);
}
//preorder traversal
void preOrder(struct node *p){
    if(p == NULL){
        return;
    }
    printf("%d\t", p->data);
    preOrder(p->left);
    preOrder(p->right);
}
//postorder traversal
void postOrder(struct node *p){
    if(p == NULL){
        return;
    }
    postOrder(p->left);
    postOrder(p->right);
    printf("%d\t", p->data);
}

int main(void){

    root = createNode(1);

    insertLeft(root, 2);
    inserRight(root, 3);
    insertLeft(root->left, 4);
    inserRight(root->left, 5);
    insertLeft(root->right, 6);
    inserRight(root->right, 7);
    
    inOrder(root);
    printf("\n");
    preOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");

    return 0;
}