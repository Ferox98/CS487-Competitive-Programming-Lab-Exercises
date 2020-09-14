#include <iostream>
#include <math.h>
 
using namespace std;
 
int main() {
	long long n, m, a;
	cin >> n >> m >> a;
	long long count_1 = ceil((double)n / a), count_2 = ceil((double)m / a);
	cout << count_1 * count_2 << endl;
}