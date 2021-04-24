#include <iostream>
#define base 26
#define base_letter 'a'

using namespace std;

typedef struct Node {
    int flag;
    struct Node *next[base];
}Node;

Node *getNewNode() {
    Node *p = (Node *)calloc(sizeof(Node), 1);
    return p;
}

int code(char ch) {
    return ch - base_letter;
}

void insert(Node *root, char * str) {
    if (root == nullptr) return ;
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        if (p->next[code(str[i])] == nullptr) p->next[code(str[i])] = getNewNode();
        p = p->next[code(str[i])];
    }
    p->flag++;
    return ;
}

int search(Node *root, char * str) {
    if (root == nullptr) return 0;
    int ans = 0;
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        if (p->next[code(str[i])] && p->next[code(str[i])]->flag) ans += p->next[code(str[i])]->flag;
        else if (p->next[code(str[i])] == nullptr){
            break;
        }
        p = p->next[code(str[i])];
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    char temp[1000000]; 
    Node *root = new Node;
    for (int i = 0; i < n; i++) {
        scanf("%s", temp); 
        insert(root, temp);
    }
    for (int i = 0; i < m; i++) {
        scanf("%s", temp); 
        printf("%d\n", search(root, temp));
    }
    return 0;
}

