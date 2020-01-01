#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int	r, g, b;
		cin >> r >> g >> b;
		vector<int> vec = { r, g, b };
		sort(vec.begin(), vec.end());
		if (vec[2] - (vec[0] + vec[1]) > 1)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
}