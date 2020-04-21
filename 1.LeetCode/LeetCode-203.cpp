/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode ret, *q;
    ret.next = head;
    q = &ret;

    while (q->next != NULL) {
        if (q->next->val == val) {
            struct ListNode *p = q->next;
            q->next = q->next->next; 
            free(p);
        } else {
            q = q->next;
        }
    }
    return ret.next;
}
