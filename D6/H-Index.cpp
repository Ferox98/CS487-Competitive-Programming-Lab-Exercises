class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size() == 0)
            return 0;
        int h = 0;
        vector<int> solutions;
        int largest = citations[0];
        for(auto& i : citations)
            if(largest < i)
                largest = i;
        
        while(h <= largest) {
            int h_check = 0, others = 0; 
            for (int i = 0; i < citations.size(); i++) {
                if(citations[i] >= h)
                    h_check++;
                else
                    others++;
            }
            if(h_check == h && others == citations.size() - h)
                solutions.push_back(h);
            h++;
        }
        if(solutions.size() == 0) return 0;
        return solutions[solutions.size() - 1];
    }
};