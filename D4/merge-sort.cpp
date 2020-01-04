#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

void merge(vector<int>& vec, int p, int q, int r) {
	vector<int> a1, a2;
	for (int i = p; i <= q; i++) 
		a1.push_back(vec[i]);
	for (int i = q + 1; i <= r; i++) 
		a2.push_back(vec[i]);
	a1.push_back(INT_MAX), a2.push_back(INT_MAX);
	int idx_1 = 0, idx_2 = 0;
	for (int i = p; i <= r; i++) {
		if (a1[idx_1] <= a2[idx_2]) {
			vec[i] = a1[idx_1];
			idx_1++;
		}
		else {
			vec[i] = a2[idx_2];
			idx_2++;
		}
	}
}

void mergeSort(vector<int>& vec, int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;
		mergeSort(vec, low, mid);
		mergeSort(vec, mid + 1, high);
		merge(vec, low, mid, high);
	}
}

int main() {
	vector<int> vec = { 2, 3, 1, 4 };
	mergeSort(vec, 0, 3);
	for (auto& i : vec) cout << i << " , ";
	cout << endl;
}