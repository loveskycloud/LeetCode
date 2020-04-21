/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) return  head;
        ListNode *p, *q;
        if (head->next == NULL) return head;
        p = head, q = head->next;
        p->next = q->next;
        q->next = p;
        head = q;
        p = head->next;
        q = p->next;
        
        while (p && q && q->next) {
            p->next = q->next;
            q->next = q->next->next;
            p->next->next = q;
            q = p->next;
            if (p->next->next->next == NULL) return head;
            p = p->next->next;
            q = q->next->next;
        }
        
        return head;
    }
};
