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
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode*j = head->next;
        while(j != NULL) {
            ListNode* i = head;
            int val = j->val;
            while(i->val < val)
                i = i->next;
        }
    }
};