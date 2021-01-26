#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->lchild = p->rchild = NULL;
    return p;
}

Node *insert(Node *root, int key) {
    if (root == NULL) return getNewNode(key);
    if (root->key < key) root->rchild = insert(root->rchild, key);
    if (root->key > key) root->lchild = insert(root->lchild, key);
    if (root->key == key) return root;
    return root;
}

Node *predeccessor(Node *root) {
    if (root == NULL) return root;
    if (root->rchild != NULL) {
        predeccessor(root->rchild);
    }
    return root;
}

Node *erase(Node *root, int key) {
    if (root == NULL) return root;
    if (root->key > key) {
        root->lchild = erase(root->lchild, key);
    } else if (root->key < key){
        root->rchild = erase(root->rchild, key);
    } else {
        /// this code is delete why ?
        if (root->lchild == NULL && root->rchild == NULL) {
            free(root);
            return NULL;
        } else if (root->lchild == NULL || root->rchild == NULL) {
            Node *temp = root->lchild ? root->lchild : root->rchild;
            free(root); 
            return temp;
        } else {
            Node *temp = predeccessor(root);
            root->key = temp->key;
            root->lchild = erase(root->lchild, temp->key); 
        }
    }

    return root;
}

void clear(Node *root) {
    if (root == NULL) return;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

void output(Node *root) {
    if (root == NULL) return ;
    output(root->lchild);
    printf("%d ", root->key);
    output(root->rchild);
    return ;
}

int main(int argc, char **argv)
{
#define MAX_OP 30
    srand(time(0));
    Node *root = NULL;
    for (int i = 0; i < MAX_OP; i++) {
        int op = rand() % 2, val = rand() % 20;
        switch(op) {
            case 0:
                printf("op = %d\n", op);
                root = insert(root, val);
                break;
            case 1:
                printf("op = %d\n", op);
                root = erase(root, val);
                break;
        }
        output(root);
        printf("\n");
    }
    return 0;
}

