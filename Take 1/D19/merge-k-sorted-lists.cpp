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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> big_list;
        for(auto& head : lists) {
           while(head != NULL) {
               big_list.push_back(head->val);
               head = head->next;
           }
        }
        sort(big_list.begin(), big_list.end());
        ListNode* head = NULL, *idx;
        for(auto& i : big_list) {
            if(head == NULL) {
                head = new ListNode(i);
                idx = head;
                continue;
            }
            else {
                idx->next = new ListNode(i);
                idx = idx->next;
            }
        }
        return head;
      } 
};