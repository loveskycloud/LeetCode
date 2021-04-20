#include <iostream>
#include <string.h>

using namespace std;

#define swap(a, b) {\
    __typeof(a) __temp = a; \
    a = b; b = __temp; \
}

int arr[10000];
int n;

typedef struct heap {
    int *arr;
    int len;
    int size;
}Heap;

Heap *init(int value) {
    Heap *node = new Heap;
    node->arr = new int[value + 1];
    node->len = 0;
    node->size = value;
    return node;
}

void update(Heap *node, int ind) {
    while ((ind << 1) <= node->len) {
        int  temp = ind;
        int l = temp << 1, r = temp << 1 | 1;
        if (arr[l] > arr[ind]) temp = l;
        if (r <= n && arr[r] > arr[ind]) temp = r;
        if (temp == ind) break;
        swap(arr[temp], arr[ind]);
        ind = temp; 
    }
}

void build(Heap *node, int value) {
    for (int i = 1; i <= node->len; i++) {
        update(node, i);
    }
    for (int i = 1; i <= node->len; i++) {
        swap(arr[1], arr[node->len - i + 1]);
        update(node, 1);
    }
}



int main()
{
    int n;
    cin >> n;
    Heap *h = init(n);
    for (int i = 1; i <= n; i++) {
        cin >> h->arr[i];
    }
    build(h, n);
    for (int i = 1; i <= n; i++) {
        cout << h->arr[i] << " ";
    }

    return 0;
}

