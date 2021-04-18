class Solution {
public:
    
    string findSmallestIndex(const string& name, map<string, bool>& exists) {
        for (int i = 1; i < 50000; i++) {
            string cur_str = name + "(" + to_string(i) + ")";
            if (!exists[cur_str]) {
                return cur_str;
            }
        }
        return "";
    }
    
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string,int> exists;
        vector<string> res(names.size());
        for(int i=0;i<names.size();i++)
        {
            if(exists.find(names[i]) != exists.end())
            {
                int count = exists[names[i]];
                while(exists.find(names[i] + "(" + to_string(count) + ")") != exists.end())
                {
                    count++;
                    exists[names[i]]++;
                }
                exists[names[i]]++;
                res[i] = names[i]+ "(" + to_string(count)+ ")";
            }
            else {
                res[i] = names[i];
            }
            exists[res[i]]=1;
        }
        return res;
    }
};