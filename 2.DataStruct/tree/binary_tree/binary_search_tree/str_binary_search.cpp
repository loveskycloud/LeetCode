#include <iostream>

using namespace std;

typedef struct Node {
    int value;
    struct Node *lchild, *rchild;
}Node;

typedef struct stack{
    Node  **data;
    int size;
    int top;
}Stack;

Stack *init(int cnt) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (Node **)malloc(sizeof(Node *) * cnt);
    s->top = -1;
    s->size = cnt;
    return s;
}

void push(Stack *s, Node *value) {
    if (s == NULL) return ;
    if (s->top == s->size) return ;
    s->data[++s->top] = value;
    return ;

}

Node *top(Stack *s) {
    if (s->top == -1) return NULL;
    return s->data[s->top];
}

Node *build(string str) {
    int len = str.size();
    Stack *s = init(len);
    Node *temp = NULL, *p = NULL;
    int flag = 0;
    while (str[0]) {
        switch(str[0]) {
            case '(':
                push(s, temp);
                temp = NULL;
                flag = 0;
                break;
            case ')':
                p = top(s);
                pop();
                
                break;
            case ',':
                flag = 1;
                break;
            case  ' ':
                break;
            default:
                temp = getNewNode();
                if (!empty() && flag == 0) {
                    top(s)->lchild = temp;
                } else if (!empty() && flag == 1) {
                    top(s)->rchild = temp;
                }


        }
        str.substr(1, str.size());
    }
    clear(stack);
    if (temp && !p) p = temp;
    return p;
}


int main()
{
    return 0;
}

