#include <iostream>

using namespace std;

#define RED 0
#define BLACK 1
#define DBLACK 2

typedef struct Node {
    int value, color;
    struct Node *lchild, *rchild;
}Node;

Node _NIL, * const NIL = &_NIL;

__attribute__((constructor))
    void init() {
        NIL->color = BLACK;
        NIL->value = 0;
        NIL->lchild = NIL->rchild = NIL;
        return ;
    }


Node *getNewNode(int value) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->value = value;
    p->color = RED;
    p->lchild = p->rchild = NIL;
    return p;
}

int hasRedChild(Node *root) {
    return root->lchild->color == RED || root->rchild->color == RED;
}

Node *right_rorate(Node *root) {
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    return root;
}

Node *left_rorate(Node *root) {
    Node *temp = root->rchild;
    root->rchild = temp->lchild; 
    temp->lchild = root;
    return root;
}

Node *erase_maintain(Node *root) {
    if (root->lchild->color != DBLACK && root->rchild->color != DBLACK) return root;
    if (root->lchild->color == DBLACK) {
        if (root->rchild->color == RED) {
            root->color = RED;
            root->rchild->color = BLACK; 
            root = left_rorate(root);
            root->lchild = erase_maintain(root->lchild);
            return root;
        } 
        if (!hasRedChild(root->rchild)) {
            root->color += 1;
            root->lchild->color -= 1;
            root->rchild->color -= 1;
            return root;
        }
        if (root->rchild->rchild != RED) {
             root->rchild->lchild->color = BLACK;
             root->rchild->color = RED;
             root->rchild = right_rorate(root->rchild);
        }
        root->lchild->color = root->color;
        root->lchild->color -= 1;
        root = left_rorate(root);
        root->lchild->color = root->rchild->color = BLACK;
            
    } else {
        if (root->lchild->color == RED) {
            root->color = RED;
            root->lchild->color = BLACK;
            root = right_rorate(root);
            root->rchild = erase_maintain(root->rchild);
            return root;
        }

        if (!hasRedChild(root->lchild)) {
            root->color += 1;    
            root->lchild->color -= 1;
            root->rchild->color -= 1;
            return root;
        }

        if (root->lchild->lchild->color != RED) {
            root->lchild->color = RED;
            root->lchild->rchild->color = BLACK;
            root->lchild = left_rorate(root->lchild);
        }
        root->lchild->color = root->color;
        root->rchild->color -= 1;
        root = right_rorate(root);
        root->lchild->color = root->rchild->color = BLACK;
    }

    return root;
}

Node *pre(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild != NIL) {
        temp = temp->rchild;
    }
    return temp;
}

Node *__erase(Node *root, int value) {
    if (root == NIL) return root;
    if (root->value > value) {
        root->lchild = __erase(root->lchild, value);
    } else if (root->value < value) {
        root->rchild = __erase(root->rchild, value);
    } else {
        if (root->lchild == NIL || root->rchild == NIL) {
            Node *temp = root->lchild == NIL ? root->rchild : root->lchild;
            temp->color += root->color;
            return root;
        } else {
            Node *temp = pre(root);
            temp->value = root->value;
            root->lchild = __erase(root->lchild, temp->value);
        }
    }

    return erase_maintain(root);
}

Node *erase(Node *root, int value) {
    root = __erase(root, value);
    root->color = BLACK;
    return root;
}


Node *insert_maintain(Node *root) {
    if (!hasRedChild(root)) return root;
    if (root->lchild->color == RED && root->rchild->color == RED) {
        if (!hasRedChild(root->lchild) && !hasRedChild(root->rchild));
        root->color = RED;
        root->lchild->color = root->rchild->color = BLACK;
        return root;
    }
    if (root->lchild->color == RED) {
        if (!hasRedChild(root->lchild)) return root;
        if (root->lchild->rchild->color == RED) {
            root->lchild = left_rorate(root->lchild);
        } 
        root = right_rorate(root);
    } else {
        if (!hasRedChild(root->rchild)) return root;
        if (root->rchild->lchild->color == RED) {
            root->rchild = right_rorate(root->rchild);
        }
        root = left_rorate(root);
    }

    root->color = RED;
    root->lchild->color = root->rchild->color = BLACK;
    return root;
}

/*
Node *insert_maintain(Node *root) { 
    if (!hasRedChild(root)) return root;
    if (root->lchild->color == RED && root->rchild->color == RED) {
        if (!hasRedChild(root->lchild) && !hasRedChild(root->rchild)) return root;
        goto insert_end;
    }
    if (root->lchild->color == RED) {
        if (!hasRedChild(root->lchild)) return root;
        if (root->lchild->rchild->color == RED) {
            root->lchild = left_rorate(root->lchild);
        }
        root = right_rorate(root);
    } else {
        if (!hasRedChild(root->rchild)) return root;
        if (root->rchild->lchild == RED) {
            root->rchild = right_rorate(root->rchild);
        } 
        root = left_rorate(root);
    }

insert_end:
    root->color = RED;
    root->lchild->color = root->rchild->color  = BLACK;
    return root;
}


*/
Node *__insert(Node *root, int value) {
    if (root == NIL) return getNewNode(value);
    if (root->value == value) return root;
    if (root->value > value) {
        root->lchild = __insert(root->lchild, value);
    } else if (root->value < value) {
        root->rchild = __insert(root->rchild, value);
    }
    return insert_maintain(root);
}

Node *insert(Node *root, int value) {
    root = insert(root, value);
    root->color = BLACK;
    return root;
}

void clear(Node *root) {
    if (root == NIL) return ;
}

int main()
{
    return 0;
}

