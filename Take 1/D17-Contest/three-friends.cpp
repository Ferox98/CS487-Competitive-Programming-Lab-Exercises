#include <iostream>
#include <vector>
 
using namespace std;
 
int calcDist(vector<int>& vec) {
	return abs(vec[0] - vec[1]) + abs(vec[1] - vec[2]) + abs(vec[0] - vec[2]);
}
 
int minDist(vector<int>& vec) {
	int min_dist = INT_MAX;
	for (int i = 0; i < 3; i++) {
		if (i == 1) vec[0]++;
		else if (i == 2) vec[0] -= 2;
		int vec_1 = vec[1];
		for (int j = 0; j < 3; j++) {
			if (j == 1) vec[1]++;
			else if (j == 2) vec[1] -= 2;
			int vec_2 = vec[2];
			for (int k = 0; k < 3; k++) {	
				if (k == 1) vec[2]++;
				else if (k == 2) vec[2] -= 2;
				int dist = calcDist(vec);
				if (dist < min_dist) min_dist = dist;
			}
			vec[2] = vec_2;
		}
		vec[1] = vec_1;
	}
	return min_dist;
}
 
int main() {
	int q;
	cin >> q;
	int counter = 0;
	vector<int> res;
	while (counter < q) {
		int p1, p2, p3;
		cin >> p1 >> p2 >> p3;
		vector<int> vec = { p1, p2, p3 };
		cout << minDist(vec) << endl;
		counter++;
	}
	return 0;
}