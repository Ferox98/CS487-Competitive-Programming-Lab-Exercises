#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		long long s;
		cin >> n >> s;
		vector<long long> vec, sum(n);
		int idx = 0, breaking_point = 0, breaking_found = -1, max_before = 0, max_idx = 0;
		while (n--) {
			long long input;
			cin >> input;
			if (idx == 0) sum[idx] = input;
			else sum[idx] = input + sum[idx - 1];
			if (sum[idx] > s && breaking_found == -1) {
				breaking_point = idx;
				breaking_found = 0;
			}
			else if (sum[idx] <= s && input > max_before) {
				max_before = input;
				max_idx = idx;
			}
			vec.push_back(input);
			idx++;
		}
		if (sum[sum.size() - 1] <= s) {
			cout << 0 << endl;
			continue;
		}
		int temp = breaking_point;
		while (breaking_point < vec.size()) {
			sum[breaking_point] -= max_before;
			if (sum[breaking_point] > s) {
				sum[breaking_point] += max_before;
				break;
			}
			sum[breaking_point] += max_before;
			breaking_point++;
		}
		int max_count = breaking_point;
		breaking_point = temp;
		int elem = vec[breaking_point];
		while (breaking_point < vec.size()) {
			sum[breaking_point] -= elem;
			if (sum[breaking_point] > s) {
				sum[breaking_point] += elem;
				break;
			}
			sum[breaking_point] += elem;
			breaking_point++;
		}
		int elem_count = breaking_point;
		int skip;
		if (max_count > elem_count) skip = max_idx + 1;
		else skip = temp + 1;
		cout << skip << endl;
	}
}