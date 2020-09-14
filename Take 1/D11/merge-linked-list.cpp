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
    ListNode* append(ListNode* head, int val) {
        if (head == NULL) {
            head = new ListNode(val);
            return head;
        }
        ListNode* idx = head;
        while(idx->next != NULL)
            idx = idx->next;
        idx->next = new ListNode(val);
        return head;
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* res = NULL;
        while(l1 != NULL || l2 != NULL) {
            if (l1 == NULL) {
                res = append(res, l2->val);
                l2 = l2->next;
            }
            else if (l2 == NULL) {
                res = append(res, l1->val);
                l1 = l1->next;
            }
            else {
                if (l1->val <= l2->val) {
                    res = append(res, l1->val);
                    l1 = l1->next;
                }
                else {
                    res = append(res, l2->val);
                    l2 = l2->next;
                }
            }
        }
        return res;
    }
};