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
    vector<int> big_neighbor;

    int next_idx = 0;

    int findNearestBiggie(ListNode*& cur, int idx_counter) {
        if (big_neighbor[idx_counter] != -1) {
            if (cur->next != NULL) {
                cur = cur->next;
                next_idx++;
            }
            else {
                cur = NULL;
            }
            return big_neighbor[idx_counter];
        }
        ListNode* next = cur->next;
        if (next == NULL) {
            cur = NULL;
            big_neighbor[idx_counter] = 0;
            return 0;
        }
        if (next->val > cur->val) {
            big_neighbor[idx_counter] = next->val;
            next_idx++;
            cur = next;
            return next->val;
        }
        ListNode* idx = next;
        next_idx++;
        while (idx != NULL) {
            int next_idx_counter = next_idx;
            int biggie = findNearestBiggie(idx, next_idx_counter);
            if (biggie > cur->val) {
                cur = idx;
                big_neighbor[idx_counter] = biggie;
                return biggie;
            }
            if (idx == NULL) {
                break;
            }
            cout << "idx = " << idx->val << endl;
        }
        cur = NULL;
        big_neighbor[idx_counter] = 0;
        return 0;
    }
    
    vector<int> nextLargerNodes(ListNode* head) {
        if (head == NULL) return big_neighbor;
        big_neighbor = vector<int>(10000, -1);
        int idx_counter = 0;
        ListNode* next = head;
        while (head != NULL) {
            int biggie = findNearestBiggie(head, idx_counter);
            idx_counter = next_idx;
        }
        big_neighbor.resize(next_idx + 1);
        return big_neighbor;
    }
};