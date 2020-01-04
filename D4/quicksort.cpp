#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& vec, int low, int high) {
	int pivot = vec[high];
	int i = low;
	for (int j = low; j < high; j++) {
		if (vec[j] < pivot) {
			int temp = vec[i];
			vec[i] = vec[j];
			vec[j] = temp;
			i++;
		}
	}
	int temp = vec[i];
	vec[i] = vec[high];
	vec[high] = temp;
	return i;
}

void quicksort(vector<int>& vec, int low, int high) {
	if (low < high) {
		int mid = partition(vec, low, high);
		quicksort(vec, low, mid - 1);
		quicksort(vec, mid + 1, high);
	}
}

int main() {
	vector<int> vec = { 2, 1, 3, 4 };
	quicksort(vec, 0, 3);
	for (auto& i : vec) cout << i << " , ";
	cout << endl;
}