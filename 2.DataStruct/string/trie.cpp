#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>

using namespace std;

const int BASE = 26;
#define BASE_LETTER 'a'

typedef struct Node {
    int flag;
    struct Node *next[BASE];
}Node;

Node *getNewNode() {
    Node *p = (Node *)calloc(sizeof(Node), 1);
    return p;
}

void clear(Node *root) {
    if (root == nullptr) return ;
    for (int i = 0; i < BASE; i++) {
        clear(root->next[i]);
    }
    clear(root);
}

inline int code(char ch) {
    return ch - BASE_LETTER;
}

int queary(Node *root, char *str) {
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        p = p->next[code(str[i])];
        if (p == nullptr) return 0;
    }
    return p->flag;
}

void insert(Node *root, char *str) {
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        if (p->next[code(str[i])] == nullptr) {
            p->next[code(str[i])] = getNewNode();
        }
        p = p->next[code(str[i])];
    }
    p->flag = 1;
    return ;
}

void output(Node *root, int k, char *buff) {
    if (root == nullptr) return ;
    if (root->flag) printf("%s\n", buff);
    for (int i = 0; i < BASE; i++) {
        buff[k] = BASE_LETTER + i;
        buff[k + 1] = '\0';
        output(root->next[i], k + 1, buff);
    }
    return ;
}

int main()
{
    char str[1000];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        
    }
    return 0;
}

