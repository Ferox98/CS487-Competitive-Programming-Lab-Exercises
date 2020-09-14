/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n == 0) return head;
        vector<ListNode*> pointers;
        int ll_length = 0;
        for (ListNode* iter = head; iter != NULL; iter = iter->next) {
            pointers.push_back(iter);
            ll_length++;
        }
        int idx = ll_length - n - 1;
        if (idx == -1) {
            // we want to remove the first element
            head = head->next;
            return head;
        }
        pointers[idx]->next = pointers[idx + 1]->next;
        return head;
    }
};