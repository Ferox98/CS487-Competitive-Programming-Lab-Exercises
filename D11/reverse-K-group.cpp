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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) return head;
        // go through the list once and determine the no. of elements in it
        int num_elems = 0;
        for (ListNode* idx = head; idx != NULL; idx = idx->next) 
            num_elems++;
        // calculate the maximum number of flip operations
        int max_flips = (int) (num_elems / k);
        int flips = 0;
        ListNode* start_idx = head, *tail = NULL;
        while (flips < max_flips) {
            ListNode* cur = start_idx, *prev = start_idx, *next = cur->next; 
            int reverse_counter = 1;
            while (reverse_counter < k) {
                cur = next;
                next = cur->next;
                cur->next = prev;
                prev = cur;
                reverse_counter++;
            }
            if (tail == NULL) {
                // first flip operation
                start_idx->next = next; // last element  of this portion points to...
                start_idx = next; // next element to be sorted is...
                tail = head; // last element of this portion of the reverse list
                head  = cur; // first element of the reversed list
            }
            else {
                tail->next = cur; 
                tail = start_idx;
                start_idx->next = next; // what does the last element point to 
                start_idx = next; // beginning of next sorting operation
            }
            for(ListNode* idx = head; idx != NULL; idx = idx->next)
                cout << idx->val << " , ";
            cout << endl;
            flips++;
        }
        return head;
    }
};