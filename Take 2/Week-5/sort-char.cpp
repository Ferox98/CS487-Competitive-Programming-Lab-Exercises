class Solution {
public:
    map<char, int> counts;
    
    int partition (vector<char>& arr, int low, int high) 
    { 
        int pivot = counts[arr[high]];    // pivot 
        int i = (low - 1);  // Index of smaller element 

        for (int j = low; j <= high- 1; j++) 
        { 
            // If current element is smaller than or 
            // equal to pivot 
            if (counts[arr[j]] >= pivot) 
            { 
                i++;    // increment index of smaller element 
                swap(arr[i], arr[j]); 
            } 
        } 
        swap(arr[i + 1], arr[high]); 
        return (i + 1); 
    } 
    
    void quickSort(vector<char>& arr, int low, int high) 
    { 
        if (low < high) 
        { 
            int pi = partition(arr, low, high); 

            quickSort(arr, low, pi - 1); 
            quickSort(arr, pi + 1, high); 
        } 
    }
    
    string frequencySort(string s) {
        for (char& c : s) {
            counts[c]++;
        }
        vector<char> chars;
        for (map<char, int>::const_iterator iter = counts.begin(); iter != counts.end(); iter++) {
            chars.push_back(iter->first);
        }
        quickSort(chars, 0, chars.size() - 1);
        string res = "";
        for (auto& c : chars) {
            for (int i = 0; i < counts[c]; i++) {
                res += c;
            }
        }
        cout << res << endl;
        return res;
    }
};