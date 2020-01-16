class Solution {
public:
    void copyElems(set<int>& elems, vector<int>& results) {
        for (auto& elem : elems) results.push_back(elem);
    }
    
    vector<int> powerfulIntegers(int x, int y, int bound) {
        set<int> elems;
        vector<int> results;
        
        if (x == 1 && y == 1 && 2 <= bound) return {2};
        else if (x == 1 && y == 1 && 2 > bound) return {};
        
        for(int i = 0;; i++) {
            int x_i = pow(x, i);
            
            if (y == 1) {
                int pow = x_i + 1;
                if(pow < 0 || pow > bound) {
                    break;
                }
                elems.insert(pow);
                continue;
            } 
            
            for(int j = 0;; j++) {
                int y_j = pow(y, j);
                int pow = x_i + y_j;
                if (pow < 0 || pow > bound) {
                    if (j == 0) {
                        copyElems(elems, results);
                        return results;
                    }
                    else {
                        break;
                    }
                }
                elems.insert(pow);
            }
            if (x == 1) break;
        }
        copyElems(elems, results);
        return results;
    }
};