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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode* idx_1 = l1, *idx_2 = l2;
       ListNode* head = NULL;
        
       int val_1 = 0, val_2 = 0, val_3 = 0, counter = 0;
       while(true) {
           if(idx_1 == NULL) {
               if(idx_2 == NULL) {
                   if(val_3 == 0) {
                       cout << "breaking 1" << endl;
                       break;
                   }
                   else
                       val_1 = 0;
               }
               val_1 = 0;     
           }
           else {
               val_1 = idx_1->val;  
           }
           if(idx_2 == NULL) {
               if(idx_1 == NULL) {
                   if(val_3 == 0) {
                       cout << "breaking-2" << endl;
                       break;
                   }
                   else
                       val_2 = 0;
               }
               val_2 = 0;
           }
           else {
               val_2 = idx_2->val;
           }
           int sum = val_1 + val_2 + val_3;
           cout << sum << endl;
           if (sum < 10) 
               val_3 = 0;
           else {
               val_3 = (int) (sum / 10);
               sum = sum % 10;           
           }
    
           if(counter == 0) {
               counter = 1;
               head = new ListNode(sum);
           }
           else {
               ListNode* iter = head;
               while(iter->next != NULL)
                   iter = iter->next;
               iter->next = new ListNode(sum);
           }
           if(idx_1 != NULL)
               idx_1 = idx_1->next;
           if(idx_2 != NULL)
               idx_2 = idx_2->next;
       }
       return head;
    }
};