#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node{
    int key;
    struct Node *lchild, *rchild;
}Node;

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->lchild = p->rchild = NULL;
    return p;
}

Node *insert(Node *root, int key) {
    if (root == NULL) return getNewNode(key);
    if (root->key == key) return root;
    if (root->key > key) root->lchild = insert(root->lchild, key);
    else root->rchild = insert(root->rchild, key);
    return root;
    
}

Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild) temp = temp->rchild;
    return temp;
}

Node *erase(Node *root, int key) {
    if (root == NULL) return root;
    if (root->key > key) {
        root->lchild = erase(root->lchild, key);
    } else if (root->key < key){
        root->rchild = erase(root->rchild, key);
    } else {
        if (root->lchild == NULL && root->rchild == NULL) {
            free(root);
            return NULL;
        } else if (root->lchild == NULL || root->rchild == NULL) {
            Node *temp = root->lchild ? root->rchild : root->rchild;
            free(root);
            return temp;
        } else {
            Node *temp = predecessor(root);
            root->key = temp->key;
            root->lchild = erase(root->lchild, temp->key);
        }
    }
    return root;
}
void clear(Node *root) {
    if (root == NULL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
}

void output(Node *root) {
    if (root == NULL) return ;
    output(root->lchild);
    printf("%d ", root->key);
    output(root->rchild);
}
int main()
{
    srand(time(0));
    Node *root = NULL;
    #define MAX_OP 30
    for (int i = 0; i < MAX_OP; i++) {
        int op = rand() % 2, val = rand() % 20;
        switch(op) {
        case  0:{
                printf("insert %d to bianry search tree\n", val);
                root = insert(root, val);
                }break;
        case 1:{
                   printf("earse %d from binary search tree\n", val);
                   root = erase(root, val);
               }break;
        }
        output(root);
        printf("\n");
    }

    return 0;
}

