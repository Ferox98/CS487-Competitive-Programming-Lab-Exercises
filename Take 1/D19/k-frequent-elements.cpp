class Solution {
public:
    map<int, int> counts;
    vector<int> heap;
    
    int parent(int i) {return (i - 1) / 2;}
    int left(int i) {return 2 * i + 1;}
    int right(int i) {return 2* i + 2;}
    
    void minHeapify(int i) {
        int l = left(i), r = right(i);
        int smallest = i;
        if (l < heap.size() && counts[heap[l]] < counts[heap[i]]) smallest = l;
        if (r < heap.size() && counts[heap[r]] < counts[heap[smallest]]) smallest = r;
        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            minHeapify(smallest);
        }
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        for (auto& i : nums) counts[i]++;
        for (pair<const int, int>& i : counts) {
            int num = i.first, count = i.second;
            if(heap.size() >= k && counts[num] < counts[heap[0]]) continue;
            else if (heap.size() >= k) {
                heap[0] = num;
                minHeapify(0);
            }
            else {
                heap.push_back(num);
                int j = heap.size() - 1;
                while (j > 0 && counts[heap[j]] < counts[heap[parent(j)]]) {
                    swap(heap[j], heap[parent(j)]);
                    j = parent(j);
                }
            }
        }
        return heap;
    }
};