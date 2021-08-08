class ThroneInheritance {
public:
    
    struct TreeNode {
        string name;
        vector<TreeNode*> children;
        bool is_dead;
        
        TreeNode(string name_) {
            name = name_;
            is_dead = false;
        }
        
        void kill() {
            is_dead = true;
        }
        
        void birth(TreeNode* child) {
            children.push_back(child);
        }
    };
    
    TreeNode* root;
    map<string, TreeNode*> hashmap;
    
    ThroneInheritance(string kingName) {
        root = new TreeNode(kingName);
        hashmap[kingName] = root;
    }
    
    void birth(string parentName, string childName) {
        TreeNode* child = new TreeNode(childName);
        hashmap[childName] = child;
        hashmap[parentName]->birth(child);
    }
    
    void death(string name) {
        hashmap[name]->kill();
    }
    
    void preorder(TreeNode* cur_node, vector<string>& order) {
        if (!cur_node->is_dead) {
            order.push_back(cur_node->name);
        }
        for (auto& child : cur_node->children) {
            preorder(child, order);
        }
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> order;
        preorder(root, order);
        return order;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */