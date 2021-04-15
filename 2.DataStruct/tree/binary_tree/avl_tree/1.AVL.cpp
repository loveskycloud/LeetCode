#include <iostream>

using namespace std;

typedef struct Node {
    int value;
    int h;
    struct Node *lchild, *rchild;
}Node;

Node _NIL, * const NIL = &_NIL;

__attribute__((constructor))
    void init() {
        NIL->value = 0;
        NIL->h = 0;
        NIL->lchild = NIL->rchild = NIL;
        return ;
    }

Node *getNewNode(int value) {
    Node *p = (Node *)malloc(sizeof(Node ));
    p->h = 1;
    p->value = value;
    p->lchild = p->rchild = NIL;
    return p;
}

Node *insert(Node *root, int value) {
    if (root == NIL) return getNewNode(value);
    if (root->value == value) return root;
    if (root->value > value) {
        root->lchild = insert(root->lchild, value);
    } else if (root->value < value) {
        root->rchild = insert(root->rchild, value);
    } 
    return root;
}

Node *erase(Node *root, int value) {
    if (root == NIL) return NIL;
    if (root->value > value) {
        root->lchild = erase(root->lchild, value);
    } else if (root->value < value) {
        root->rchild = erase(root->rchild, value);
    } else {
        if (root->lchild == NIL || root->rchild == NIL) {
            Node *temp = root->lchild == NIL ? root->rchild : root->lchild;
            free(root);
            return temp;
        } else if (root->lchild == NIL && root->rchild == NIL) {
            Node *temp = pre(root);
            root->value = temp->value;
            root->lchild = erase(root->lchild, temp->value);
        }
    }
    return root;
}

int main()
{
    return 0;
}

