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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) return head;
        ListNode *current = head;
        ListNode *p;
        int count = 0;
        while (current) {
            count++;
            current = current->next;
        }
        current = head;
        if ((count - n) == 0) {
            head = head->next;
        } else {
            for (int i = 0; i < count - n - 1; i++) {
                current = current->next;
            }
            current->next = current->next->next;
        }
        return head;
    }
};
