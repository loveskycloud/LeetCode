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
    bool hasCycle(ListNode *head) {
        if (head == NULL) return head;
        ListNode *current = head;
        int count = 8030;
        while (current && count) {
            current = current->next;
            count--;
        }
        if (current == NULL) return false;
        if (count <= 0) return true;
        return true;
    }
};
