#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int>& vec) {
	for (int i = 0; i < vec.size(); i++) {
		int min = vec[i], min_idx = i;
		for (int j = i + 1; j < vec.size(); j++) {
			if (vec[j] < min) min = vec[j], min_idx = j;
		}
		vec[min_idx] = vec[i];
		vec[i] = min;
	}
}

int main() {
	vector<int> vec = { 2, 1, 3, 4 };
	selectionSort(vec);
	for (auto& i : vec) cout << i << " , ";
	cout << endl;
}