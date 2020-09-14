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
    bool isPalindrome(ListNode* head) {
        stack<int> rev_list;
        for (ListNode* iter = head; iter != NULL; iter = iter->next) {
            rev_list.push(iter->val);
        }
        for (ListNode* iter = head; iter != NULL; iter = iter->next) {
            if (iter->val != rev_list.top()) {
                return false;
            }
            rev_list.pop();
        }
        return true;
    }
};