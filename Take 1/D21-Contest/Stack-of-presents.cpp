#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<int> a, b, pos(n + 1);
		int counter = 0;
		while (n--) {
			int input;
			cin >> input;
			pos[input] = counter;
			a.push_back(input);
			counter++;
		}
		while (m--) {
			int input;
			cin >> input;
			b.push_back(input);
		}
		int max_idx = 0;
		long long total = 0;
		for (int i = 0; i < b.size(); i++) {
			if (pos[b[i]] > max_idx) {
				max_idx = pos[b[i]];
				pos[b[i]] -= i;
			}
			else if (pos[b[i]] < max_idx) pos[b[i]] = 0;
			total += (long long)(2 * (long long)pos[b[i]] + 1);
		}
		cout << total << endl;
	}
}