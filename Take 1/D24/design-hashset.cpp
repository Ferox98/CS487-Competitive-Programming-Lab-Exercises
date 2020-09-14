class MyHashSet {
public:
    /** Initialize your data structure here. */
    vector<vector<int>> hash_set;
    MyHashSet() {
        hash_set = vector<vector<int>>(20000);
    }
    
    void add(int key) {
        int idx = key % hash_set.size();
        if(!contains(key))
            hash_set[idx].push_back(key);
    }
    
    void remove(int key) {
        int idx = key % hash_set.size();
        for(auto& val : hash_set[idx]) {
            if (val == key) 
                val = INT_MIN;
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int idx = key % hash_set.size();
        for (int i = 0; i < hash_set[idx].size(); i++) {
            if (hash_set[idx][i] == key && hash_set[idx][i] != INT_MIN)
                return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */