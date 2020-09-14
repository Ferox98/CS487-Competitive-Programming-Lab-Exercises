#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> matchString(vector<string>& strings, vector<string>& queries) {
	map<string, int> counts;
	for (auto& str : strings) {
		counts[str]++;
	}
	vector<int> res;
	for (auto& q : queries) {
		res.push_back(counts[q]);
	}
	return res;
}

int main() {
	vector<string> strings = {};
	vector<string> queries = {"aba", "xzxb", "ab"};
	vector<int> res = matchString(strings, queries);
	for(auto& r : res) cout << r << " , ";
	cout << endl;
}