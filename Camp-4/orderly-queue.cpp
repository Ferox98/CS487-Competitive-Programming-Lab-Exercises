class Solution {
public:
    string orderlyQueue(string S, int K) {
        if (K == 1) {    
            string s = S;
            string smallest = string(s.size(), 'z');
            for (int i = 0; i < S.size(); i++) {
                char temp = s[0];
                s.erase(s.begin());
                s.insert(s.end(), temp);
                if(smallest > s) smallest = s;    
            }
            return smallest;
        }
        string str = S;
        sort(str.begin(), str.end());
        return str;
    }
};