#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value, hight;
    struct Node *lchild, *rchild;
}Node;

Node _NIL, *NIL = &_NIL;

__attribute__((constructor))
    void init_NIL() {
        NIL->value = 0;
        NIL->hight = 0;
        NIL->lchild = NIL->rchild = NIL;
        return ;
    }

Node *getNewNode(int value) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = value;
    node->lchild = node->rchild = NIL;
    node->hight = 1;
    return node;
}

void updatehight(Node *root) {
    int h1 = root->lchild->hight;
    int h2 = root->rchild->hight;
    root->hight = (h1 > h2 ? h1 : h2) + 1;
    return ;
}

Node *left_rorate(Node *root) {
    Node *right_node = root->rchild;
    root->rchild = right_node->lchild;
    right_node->lchild = root;
    updatehight(root);
    updatehight(right_node);
    return right_node;
}

Node *right_rorate(Node *root) {
    Node *left_node = root->lchild;
    root->lchild = left_node->rchild;
    left_node->rchild = root;
    updatehight(root);
    updatehight(left_node);
    return left_node;
}


Node *maintain(Node *root) {
    if (abs(root->lchild->hight - root->rchild->hight) <= 1)  return root;
    if (root->lchild->hight > root->rchild->hight) {
        if (root->lchild->rchild->hight > root->lchild->lchild->hight) {
            root->lchild = left_rorate(root->lchild);
        }
        root = right_rorate(root);
    } else {
        if (root->rchild->lchild->hight > root->rchild->rchild->hight) {
            root->rchild = right_rorate(root->rchild);
        }
        root = left_rorate(root);
    }
    return maintain(root);
}


Node *insert(Node *root, int key) {
    if (root == NIL) return getNewNode(key);
    if (root->value > key) {
        root->lchild = insert(root->lchild, key);
    } else if (root->value < key) {
        root->rchild = insert(root->rchild, key);
    } 
    updatehight(root);
    return root;
}


Node *proccess(Node *root) {
    if (root == NIL) return root;
    Node *temp;
    if (root->rchild != NIL) {
        temp = proccess(root->rchild);
    }     return temp;
}

Node *erase(Node *root, int key) {
    if (root == NIL) return root;
    if (root->value < key) {
        root->rchild = erase(root->rchild, key);
    } else if(root->value > key) {
        root->lchild = erase(root->lchild, key);
    } else {
        if (root->lchild == NIL || root->rchild == NIL) {
            Node *temp = root->lchild == NIL ? root->rchild : root->lchild;
            free(root);
            return temp;
        } else if (root->lchild != NIL && root->rchild != NIL) {
            Node *temp = proccess(root);
            root->value = temp->value;
            root->lchild = erase(root->lchild, temp->value);
        }
    }
    updatehight(root);
    return maintain(root);
}

void clear(Node *root) {
    if (root == NIL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

void output(Node *root) {
    if (root == NIL) return ;
    output(root->lchild);
    printf("%d ", root->value);
    output(root->rchild);
    return ;
}

int main(int argc, char **argv)
{
    Node *root = NIL;
    int val, op;
    while (~scanf("%d %d", &op, &val)) {
        switch(op) {
        case 1: root = insert(root, val); break;
        case 2: root = erase(root, val); break;
        }
        output(root);
        printf("\n");
    }
    
    return 0;
}

