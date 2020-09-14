class MyHashMap {
public:
    /** Initialize your data structure here. */
    vector<vector<pair<int, int>>> hash_map;
    MyHashMap() {
        hash_map = vector<vector<pair<int, int>>>(20001);        
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int idx = key % hash_map.size();
        for(int i = 0; i < hash_map[key % hash_map.size()].size(); i++) {
            if(hash_map[idx][i].first == key) {
                hash_map[idx][i].second = value;
                return;
            }
        }
        hash_map[idx].push_back(pair<int, int>(key, value));
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int idx = key % hash_map.size();
        for(int i = 0; i < hash_map[key % hash_map.size()].size(); i++) {
            if(hash_map[idx][i].first == key && hash_map[idx][i].second != INT_MIN)
                return hash_map[idx][i].second;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int idx = key % hash_map.size();
        for(int i = 0; i < hash_map[key % hash_map.size()].size(); i++) {
            if (hash_map[idx][i].first == key) {
                hash_map[idx][i].second = INT_MIN;
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */