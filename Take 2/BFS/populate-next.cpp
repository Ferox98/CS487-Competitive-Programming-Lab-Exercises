/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    void connect(Node* node, Node* sibling, Node* uncle, bool left) {
        if (node == NULL) return;
        if (left) node->next = sibling;
        if (!left && uncle != NULL) node->next = uncle->left;
        else if (!left) node->next = NULL;
        if (uncle != NULL) uncle = uncle->left;
        connect(node->left, node->right, sibling, true);
        if (left)
            connect(node->right, NULL, sibling, false);
        else 
            connect(node->right, NULL, uncle, false);
    }
    
    Node* connect(Node* root) {
        connect(root, NULL, NULL, false);
        return root;
    }
};