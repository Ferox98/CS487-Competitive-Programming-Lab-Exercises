int partition(vector<int>& vec, int p, int r) {
	int i = p - 1;
	int key = vec[r];
	for (int j = p; j < r; j++) {
		if (vec[j] <= key) {
			i++;
			int temp = vec[i];
			vec[i] = vec[j];
			vec[j] = temp;
		}
	}
	int temp = vec[i + 1];
	vec[i + 1] = vec[r];
	vec[r] = temp;
	return i + 1;
}

void quickSort(vector<int>& vec, int p, int r) {
	if (p < r) {
		int q = partition(vec, p, r);
		quickSort(vec, p, q - 1);
		quickSort(vec, q + 1, r);
	}
}

class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        quickSort(A, 0, A.size() - 1);
        for(int i = A.size() - 1; i >= 2; i--) {
            // get the three last elements
            int elem_1 = A[i], elem_2 = A[i - 1], elem_3 = A[i - 2];
            if (elem_2 + elem_3 > elem_1)
                return (elem_1 + elem_2 + elem_3);
        }
        return 0;
    }
};