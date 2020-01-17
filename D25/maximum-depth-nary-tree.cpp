/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    
    void findLongestDepth(Node* node, int depth, int& longest_depth) {
        if (node == NULL) {
            return;
        }
        depth++;
        if (depth > longest_depth) {
            longest_depth = depth;
        }
        for(auto& child : node->children) {
            findLongestDepth(child, depth, longest_depth);
        }
    }
    
    int maxDepth(Node* root) {
        int longest_depth = 0;
        findLongestDepth(root, 0, longest_depth);
        return longest_depth;
    }
};