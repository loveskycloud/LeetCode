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
        ListNode* q = head;
        if (head == nullptr) return nullptr;
        while (q->next != nullptr) {
            if (q->val == q->next->val) {
                q->next = q->next->next;
            } else {
                q = q->next;
            }
        }
        return head;
    }
};
