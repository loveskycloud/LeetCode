#include <iostream>

using namespace std;

typedef struct Node {
    int *data;
    int cnt;
    int size;
}priority_queue;

priority_queue *init(int n) {
    priority_queue *p = (priority_queue *)malloc(sizeof(priority_queue));
    p->data = (int *)malloc(sizeof(int) * n + 1);
    p->cnt = 0;
    p->size = n;
    return p;
}

int empty(priority_queue *p) {
    if (p == NULL) return 0;
    return p->cnt == 0;
}

int top(priority_queue *p) {
    return p->data[1];
}

int push(priority_queue *p, int val) {
    if (p ==  NULL) return 0;
    if (p->cnt == p->size) return 0;
    p->cnt += 1;
    p->data[p->cnt] = val;
    int ind = p->cnt;
    while (ind >> 1 && p->data[ind] > p->data[ind >> 1]) {
        swap(p->data[ind], p->data[ind >> 1]);
        ind >>= 1;
    }
    return 1;
}

int pop(priority_queue *p) {
    if (p == NULL) return 0;
    if (empty(p)) return 0;
    p->data[1] = p->data[p->cnt];
    int ind = p->cnt;
    while (ind << 1 < p->cnt) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (p->data[temp] < p->data[l]) temp = l;
        if (r <= p->cnt && p->data[temp] < p->data[r]) temp = r;
        swap(p->data[ind], p->data[temp]);
        ind = temp;
    }
    return 1;
}

int pop1(priority_queue *p) {
    if (p == NULL) return 0;
    if (empty(p)) return 0;
    p->data[1] = p->data[p->cnt];
    p->cnt --;
    int ind = 1;
    while (ind << 1 < p->cnt) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (p->data[temp] > p->data[l]) temp = l;
        if (r <= p->cnt && p->data[temp] < p->data[r]) temp = r;
        swap(p->data[temp], p->data[ind]);
        ind = temp;
    }
    return 0;
}


int main()
{
    return 0;
}

