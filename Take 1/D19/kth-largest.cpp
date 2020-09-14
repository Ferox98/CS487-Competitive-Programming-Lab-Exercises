class KthLargest {
public:
    vector<int> heap;
    int heap_size, max_size;
    
    int parent(int i) {return (i - 1) / 2;}
    int left(int i) {return 2 * i + 1;}
    int right(int i) {return 2 * i + 2;}
    
    void minHeapify(int i) {
        int l = left(i), r = right(i);
        int smallest = i;
        if (l < heap_size && heap[l] < heap[i]) smallest = l;
        if (r < heap_size && heap[r] < heap[smallest]) smallest = r;
        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            minHeapify(smallest);
        }
    }
    
    void pop() {
        heap[0] = heap[heap_size - 1];
        heap_size--;
        heap.pop_back();
        minHeapify(0);
    }
    
    KthLargest(int k, vector<int>& nums) {        
        heap = nums;
        heap_size = heap.size();
        max_size = k;
        
        for(int i = heap.size() / 2; i >= 0; i--) {
            minHeapify(i);
        }
        
        while(heap_size > max_size) {
            pop();
        }
    }
    int add(int val) {
        if (heap_size >= max_size && val < heap[0]) return heap[0];
        else if (heap_size >= max_size) {
            heap[0] = val; 
            minHeapify(0);
        }
        else {
            heap.push_back(val);
            heap_size++;
            int i = heap_size - 1;
            while (i > 0 && parent(i) > val) {
                swap(heap[parent(i)], heap[i]);
                i = parent(i);
            }
        }
        return heap[0];
    }
};