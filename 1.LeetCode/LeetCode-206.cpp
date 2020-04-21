/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
   struct ListNode ret, *p, *q;
   ret.next = NULL;
   p = head;
   while (p) {
       q = p->next;
       p->next = ret.next;
       ret.next = p;
       p = q;
   }
   return ret.next;
}
