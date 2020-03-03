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
    void deleteNode(ListNode* node) {
        if (node == NULL) return ;
        ListNode * current = node;
        ListNode *temp;
        while (current->next != NULL) {
            current->val = current->next->val;
            temp = current;
            current = current->next;
        }
        temp->next = NULL;
        
    }
};
