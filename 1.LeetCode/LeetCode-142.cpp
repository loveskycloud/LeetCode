/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *p = head, *q = head;
    while (p) {
        q = q->next;
        p = p->next;
        if (p == NULL) return NULL;
        p = p->next;
        if (p == q) break;
    }
    if (p == NULL) return NULL;
    p = head;
    while (p != q) {
        p = p->next;
        q = q->next;
    }
    return q;

}
