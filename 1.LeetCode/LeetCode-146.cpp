#include <iostream>
#include <unordered_map>
#include <string.h>

using namespace std;


class LRUCache {
public:

    typedef struct Node {
        int first, second;
        struct Node *pre, *next;
        Node() : first(0), second(0), pre(nullptr), next(nullptr) {}
        Node(int first, int second) : first(first), second(second), pre(nullptr), next(nullptr) {}
    }Node;

    unordered_map<int, Node *> hash;
    Node *head, *tail;
    int capacity;
    int size;

    void AddHead(Node *node) {
        node->next = head->next;
        node->next->pre = node;
        node->pre = head;
        head->next = node;
    }

    Node *DeleteNode(Node *node) {
        node->next->pre = node->pre;
        node->pre->next = node->next;
        return node;
    }

    Node *DeleteTail() {
        Node *temp = tail->pre;
        temp->next->pre = temp->pre;
        temp->pre->next = temp->next;
        return temp;
    }

    LRUCache(int capacity) : capacity(capacity), size(0) {
        head = new Node;
        tail = new Node;
        tail->pre = head;
        head->next = tail;
        head->pre = nullptr;
        tail->next = nullptr;
    }

    int get(int key) {
        if (!hash.count(key)) {
            return -1;
        }
        Node *temp = DeleteNode(hash[key]);
        AddHead(temp);
        return temp->second;
    }

    void put(int key, int value) {
        if (!hash.count(key)) {
            Node *temp = new Node(key, value);
            hash[key] = temp;
            AddHead(temp);
            size++;
        } else {
            Node *temp = DeleteNode(hash[key]);
            temp->second = value;
            AddHead(temp);
        }
        if (size > capacity) {
            Node *temp = DeleteTail();
            hash.erase(temp->first);
            delete temp;
            size--;
        }
    }
};
/*
class LRUCache {
public:

struct DNode {
        int first, second;
        struct DNode *pre, *next;
        DNode() : first(0), second(0), pre(nullptr), next(nullptr) {}
        DNode(int first, int second) : first(first), second(second), pre(nullptr), next(nullptr) {}
};

    int capacity;
    unordered_map<int, DNode *> hash;
    DNode *tail, *head;
    int size;
    
    void AddHead(DNode *node) {
        node->next = head->next;
        node->next->pre = node;
        node->pre = head;
        head->next = node;
    }

    void DeleteNode(DNode *node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
        delete  node;
    }

    DNode* DeleteTail() {
        DNode *temp = tail->pre;
        temp->pre->next = tail;
        tail->pre = temp->pre;
        return temp;
    }

    LRUCache(int capacity) : capacity(capacity) {
        tail = new DNode();
        head = new DNode();
        tail->pre = head;
        head->next = tail;
        size = 0;
    }
    
    ~LRUCache() {
        DNode *p = head;
        while (p) {
            DNode *temp = p;
            p = p->next;
            delete temp;
        }
    }

    int get(int key) {
        if (!hash.count(key)) {
            return -1;
        } 
        DNode *temp = hash[key];
        DNode *newnode = new DNode(temp->first, temp->second);
        DeleteNode(temp);
        AddHead(newnode);
        hash[key] = newnode;
        return newnode->second;
    }
    
    void put(int key, int value) {
        if (!hash.count(key)) {
            DNode *node = new DNode(key, value);
            AddHead(node);
            hash[key] = node;
            size++;
        } else {
            DNode *temp = hash[key];
            DNode *newnode = new DNode(temp->first, value);
            AddHead(newnode);
            DeleteNode(temp);
            hash[key] = newnode;
        }
        if (size > capacity) {
            DNode *temp = DeleteTail();
            auto e = hash.find(temp->first);
            hash.erase(e);
            delete temp;
            size--;
        }
    }
};

*/
int main() {

    LRUCache *a = new LRUCache(2);
    a->put(1, 1);
    a->put(2, 2);
    cout << a->get(1) << endl;
    a->put(3, 3);
    cout << a->get(2) << endl;
    a->put(4, 4);
    cout << a->get(1) << endl;
    cout << a->get(3) << endl;
    cout << a->get(4) << endl;
    cout << a->hash.size() << endl;
    return 0;
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
