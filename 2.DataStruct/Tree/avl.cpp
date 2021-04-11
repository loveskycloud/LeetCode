#include <iostream>

using namespace std;

typedef struct node {
    int h;
    int value;
    struct node *lchild, *rchild;
}Node;

Node _NIL;
Node *NIL = &_NIL;
__attribute__((constructor)) 
    void init() {
        NIL->value = 0;
        NIL->h = 0;
        NIL->lchild = NIL->rchild = NIL;
    }

void updateHeight(Node *root) {
    if (root == NIL) return ;
    int len1 = root->lchild->h;
    int len2 = root->rchild->h;
    root->h = max(len1, len2) + 1;
}


Node *getNewNode(int value) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->h = 1;
    node->value = value;
    node->lchild = node->rchild = NIL;
    return node;
}

Node *right_rorate(Node *root) {
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    return temp;
}

Node *left_rorate(Node *root) {
    Node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    return temp;
}

Node *maintain(Node *root) {
    if (root == NIL) return root;
    if (abs(root->lchild->h - root->rchild->h) <= 1) return root;
    else {

        if (root->lchild->h > root->rchild->h) {
            if (root->lchild->lchild->h > root->lchild->rchild->h) {
                root = right_rorate(root);
            } else if (root->lchild->rchild->h > root->lchild->lchild->h) {
                root->lchild = left_rorate(root->lchild);
            }
        } else if (root->rchild->h > root->rchild->h) {
            if (root->rchild->lchild->h > root->rchild->rchild->h) {
                root->rchild = right_rorate(root->rchild);
            } else if (root->rchild->lchild->h < root->rchild->rchild->h) {
                root = left_rorate(root);
            }
        }
    }
    updateHeight(root);
    return root;
}

Node *insert(Node *root, int value) {
    if (root == NIL) return getNewNode(value);
    if (value < root->value) {
        root->lchild = insert(root->lchild, value);
    } else if (value > root->value) {
        root->rchild = insert(root->rchild, value);
    }
    updateHeight(root);
    return maintain(root);
}

Node *processor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild != NIL) {
        temp = temp->rchild;
    }
    return temp;
}

Node *erase(Node *root, int value) {
    if (root == NIL) return root;
    if (value < root->value) {
        root->lchild = erase(root->lchild, value);
    } else if (value > root->value) {
        root->rchild = erase(root->rchild, value);
    } else {
        if (root->lchild == NIL || root->rchild == NIL) {
            Node *temp = root->lchild == NIL ? root->rchild : root->lchild;
            free(root);
            return temp;
        } else if (root->rchild != NIL && root->lchild != NIL) {
            Node *temp = processor(root);
            root->value = temp->value;
            root->lchild = erase(root->lchild, temp->value);
        }
    }
    return maintain(root);
}

int main()
{
    Node *root = NIL;

    return 0;
}

