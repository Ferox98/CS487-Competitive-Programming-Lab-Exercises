#include <iostream>
#include <vector>

using namespace std;

vector<int> countingSort(vector<int>& vec) {
	vector<int> counts(vec.size() + 1, 0), res;
	for (int i = 0; i < vec.size(); i++) 
		counts[vec[i]]++;
	for (int i = 1; i <= vec.size(); i++) {
		for (int j = 0; j < counts[i]; j++) {
			res.push_back(i);
		}
	}
	return res;
}

int main() {
	vector<int> vec = { 2, 1, 3, 4 };
	vector<int> res = countingSort(vec);
	for (auto& i : res) cout << i << " , ";
	cout << endl;
}