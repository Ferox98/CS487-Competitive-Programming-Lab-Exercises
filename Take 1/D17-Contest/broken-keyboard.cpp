#include <iostream>
#include <vector>
#include <set>
#include <string>
 
using namespace std;
 
int main() {
	int n, k;
	string s;
	set<char> chars;
	cin >> n >> k;
	cin >> s;
	for (int i = 0; i < k; i++) {
		char c;
		cin >> c;
		chars.insert(c);
	}
	
	long long elems = 0, substrings = 0;
	for (int i = 0; i < s.size(); i++) {
		if (chars.find(s[i]) == chars.end()) {
			if (i == 0) continue;
			substrings += (long long) (elems * (elems + 1)) / 2;
			elems = 0;
		}
		else
			elems++;
	}
	substrings += (long long)(elems * (elems + 1)) / 2;
	cout << substrings << endl;
}