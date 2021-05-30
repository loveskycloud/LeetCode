/*************************************************************************
	> File Name: ac_trie.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 30 May 2021 11:52:18 AM CST
 ************************************************************************/
#include <iostream>
using namespace std;

#define BASE 26
#define BEGIN_LETTER 'a'

typedef struct Node {
	int flag;
	struct Node *fail, *next[BASE];
}Node;

typedef struct Queue {
	Node **data;
	int head, tail, size;
}Queue;

Node *getNewNode() {
	Node *p = (Node *)calloc(sizeof(Node), 1);
	return p;
}

Queue *init_queue(int n) {
	Queue *p = (Queue *)calloc(sizeof(Queue), 1);
	p->head = p->tail = 0;
	p->data = (Node **)malloc(sizeof(Node *) * n);
	p->size = n;
	return p;
}

bool empty(Queue *q) {
	return q->tail == q->head;
}

void push(Queue *que, Node *node) {
	que->data[++que->tail] = node;
	return ;
}

Node *front(Queue *q) {
	if (empty(q)) return nullptr;
	return q->data[q->head];
}

void pop(Queue *q) {
	if (empty(q)) return ;
	q->head++;
	return ;
}

int insert(Node *root, const char *str) {
	int cnt = 0;
	Node *p = root;
	for (int i = 0; str[i]; i++) {
		int ind = str[i] - BEGIN_LETTER;
		if (p->next[ind] == nullptr) p->next[ind] = getNewNode(), ++cnt;
		p = p->next[ind];
	}
	p->flag = 1;
	return cnt;
}

void build_ac(Node *root, int n) {
	Queue *q = init_queue(n + 10);
	push(q, root);
	
	while (empty(q)) {
		Node *now_node = front(q);
		pop(q);
		
		for (int i = 0; i < BASE; i++) {
			if (now_node->next[i] == nullptr) continue;
			Node *p = now_node->fail;
			while (p && p->next[i] == nullptr) p = p->fail;
			if (p == nullptr) now_node->next[i]->fail = root;
			else now_node->next[i]->fail = p->next[i];
			push(q, now_node->next[i]);
		}
	}
	return ;
}

int match(Node *root, const char *str) {
	int cnt = 0;
	Node *p = root;
	for (int i = 0; str[i]; i++) {
		int ind = str[i] - BEGIN_LETTER;
		while (p && p->next[ind] == nullptr) p = p->fail;
		if (p == nullptr) p = root;
		else p = p->next[ind];
		Node *q = p;
		while (q) cnt += q->flag, q = q->fail;
	}
	return cnt;
}

int main() {
	
	Node *root = getNewNode();
	int n, cnt = 0;
	cin >> n;
	build_ac(root, n + 10);
	char str[1000];
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		cnt += insert(root, str);
	}
	
	scanf("%s", str);
	
	int total = match(root, str);
	cout << total << endl;
}
