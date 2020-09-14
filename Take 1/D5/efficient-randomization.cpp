#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
	srand(time(0));
	vector<int> vec = { 2, 1, 3, 4, 6, 3, 2, 5, 2, 2 };
	random_shuffle(vec.begin(), vec.end());
	for (auto& i : vec) cout << i << " , ";
	cout << endl;
}