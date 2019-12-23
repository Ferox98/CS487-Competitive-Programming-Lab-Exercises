class Solution {
public:
   
    int hIndex(vector<int>& citations) {
        if(citations.empty()) return 0;
        for (int h = citations.size(); h > 0; h--) {
            int start_idx = citations.size() - h;
            if(citations[start_idx] >= h) return h;
        }   
        return 0;
    }
};