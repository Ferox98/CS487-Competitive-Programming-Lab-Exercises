class Solution {
public:
    vector<string> heap;
    map<string, int> counts;
    
    int parent(int i) {return (i - 1) / 2;}
    int left(int i) {return 2 * i + 1;}
    int right(int i) {return 2 * i + 2;}
    
    bool lessThan(string first, string second) {
        if (counts[first] < counts[second]) return true;
        if (counts[first] == counts[second] && first > second) return true;
        return false;
    }
    
    string extractMin() {
        string minimum = heap[0];
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        minHeapify(0);
        return minimum;
    }
    
    void minHeapify(int i) {
        int l = left(i), r = right(i);
        int smallest = i;
        if (l < heap.size() && lessThan(heap[l], heap[i]))
            smallest = l;
        if (r < heap.size() && lessThan(heap[r], heap[smallest]))
            smallest = r;
        if (smallest != i) {
            swap(heap[smallest], heap[i]);
            minHeapify(smallest);
        }
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        for(auto& i : words) counts[i]++;
        for(pair<string, int> key : counts) {
            string word = key.first;
            cout << "(" << word << " , " << key.second << ")" << endl;
            if (heap.size() >= k && lessThan(word, heap[0]))
                continue;
            else if (heap.size() >= k) {
                cout << "replacing " << heap[0] << " with " << word << endl;
                heap[0] = word;
                minHeapify(0);
            }
            else {
                heap.push_back(word);
                int i = heap.size() - 1;
                while (i > 0 && lessThan(heap[i], heap[parent(i)])) {
                    swap(heap[parent(i)], heap[i]);
                    i = parent(i);
                }
            }
        }
        vector<string> res(k);
        int i = k - 1;
        for(auto& j : heap) cout << j << " , ";
        cout << endl;
        while(heap.size() > 0) {
            res[i] = extractMin();
            cout << "extracting " << res[i] << endl;
            i--;
        }
        return res;
    }
};