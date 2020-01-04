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
        if (head == NULL || head->next == NULL) return head;
        ListNode* idx = head, *idx_2 = head->next;
        while (idx != NULL && idx_2 != NULL) {
            while(idx_2 != NULL && idx_2->val == idx->val)
                idx_2 = idx_2->next;
            idx->next = idx_2;
            idx = idx_2;
            if (idx_2 != NULL) idx_2 = idx_2->next;
        }
        return head;
    }
};