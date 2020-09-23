/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    vector<TreeNode*> nodes;
    int index;
    
    void inorder(TreeNode* node) {
        if (node == NULL) return;
        if (node->left != NULL) inorder(node->left);
        nodes.push_back(node);
        if (node->right != NULL) inorder(node->right);
    }
    
    BSTIterator(TreeNode* root) {
        index = -1;
        inorder(root);
    }
    
    /** @return the next smallest number */
    int next() {
        index++;
        return nodes[index]->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        cout << index << " , " << nodes.size() << endl;
        if (index + 1 >= nodes.size()) {
            cout << "returning false " << (index + 1 >= nodes.size()) << endl;
            return false;
        }
        cout << "returning true" << endl;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */