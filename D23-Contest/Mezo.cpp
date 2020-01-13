#include <iostream>
#include <string>
 
using namespace std;
 
int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int count_left = 0, count_right = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'L') count_left++;
		else count_right++;
	}
	cout << count_right + count_left + 1 << endl;
	return 0;
}