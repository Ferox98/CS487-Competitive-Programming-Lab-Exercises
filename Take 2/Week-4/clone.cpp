/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    vector<bool> discovered;
    map<int, Node*> mapper;
    
    Node* copyGraph(Node* original) {
        if (original == NULL) return NULL; 
        discovered[original->val] = true;
        Node* copy = new Node(original->val);
        mapper[original->val] = copy;
        for (int i = 0; i < original->neighbors.size(); i++) {
            Node* node = original->neighbors[i];
            if (discovered[node->val]) {
                Node* node_copy = mapper[node->val];
                copy->neighbors.push_back(node_copy);
            }
            else {
                Node* node_copy = copyGraph(node);
                copy->neighbors.push_back(node_copy);
                
            }
        }
        return copy;
    }
    
    Node* cloneGraph(Node* node) {
        discovered = vector<bool>(101, false);
        Node* new_node = copyGraph(node);
        return new_node;
    }
};