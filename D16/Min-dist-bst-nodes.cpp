#include <math.h>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int min_dif = INT_MAX;
    vector<int> nodes;
    void getElems(TreeNode* root) {
        if (root == NULL) return;
        nodes.push_back(root->val);
        getElems(root->left);
        getElems(root->right);
    }
    
    void merge(vector<int>& vec, int p, int q, int r) {
        // create a vector that stores the specific values
        vector<int> vec_1, vec_2;
        for (int i = p; i <= q; i++) 
            vec_1.push_back(vec[i]);
        for (int i = q + 1; i <= r; i++)
            vec_2.push_back(vec[i]);

        vec_1.push_back(INT_MAX);
        vec_2.push_back(INT_MAX);
        int idx_1 = 0, idx_2 = 0;

        for (int i = p; i <= r; i++) {
            if (vec_1[idx_1] <= vec_2[idx_2]) {
                vec[i] = vec_1[idx_1];
                idx_1++;
            }
            else {
                vec[i] = vec_2[idx_2];
                idx_2++;
            }
        }
    }

    void mergeSort(vector<int>& vec, int p, int r) {
        if (p < r) {
            // calculate q
            int q = (int) ((p + r) / 2);
            mergeSort(vec, p, q);
            mergeSort(vec, q + 1, r);
            merge(vec, p, q, r);
        }
    }
    int minDiffInBST(TreeNode* root) {
        // get all the elements in the array
        getElems(root);
        // sort them
        mergeSort(nodes, 0, nodes.size() - 1);
        // return minimum difference
        int min_dif = INT_MAX;
        for (int i = 0; i < nodes.size() - 1; i++) {
            if (abs(nodes[i] - nodes[i + 1]) < min_dif) {
                min_dif = abs(nodes[i] - nodes[i + 1]);
            }
        }
        return min_dif;
    }
};