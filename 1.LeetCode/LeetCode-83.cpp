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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return head;
        ListNode *p, *q;
        p = head;
        while (p->next) {
            if (p->val == p->next->val) {
                q = p->next;
                p->next = q->next;
            } else {
                p = p->next;
            }
        }
        return head;
    }
};
