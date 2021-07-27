class NestedIterator {
public:
    
    vector<int> flat_list;
    int idx;
    
    void flatten(vector<NestedInteger>& nestedList) {
        for (auto& elem : nestedList) {
            if (elem.isInteger()) {
                flat_list.push_back(elem.getInteger());
            }
            else {
                flatten(elem.getList());
            }
        }
    }
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        flatten(nestedList);
        idx = 0;
    }
    
    int next() {
        int res = flat_list[idx];
        idx++;
        return res;
    }
    
    bool hasNext() {
        return idx < flat_list.size();
    }
};
