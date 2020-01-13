#include <iostream>
#include <math.h>
#include <vector>
 
using namespace std;
 
int gcd(long long a, long long b) {
	if (a == 0)
		return b;
	return gcd(b % a, a);
}
 
long long lcm(long long a, long long b)
{
	return (a * b) / gcd(a, b);
}
 
int main() {
	long long x;
	cin >> x;
	vector<long long> factors;
	for (long long i = 1; i <= sqrt(x); i++) {
		if (x % i == 0) factors.push_back(i);
	}
 
	for (int idx = factors.size() - 1; idx >= 0; idx--) {
		long long factor = factors[idx], co_factor = x / factor;
		if (lcm(factor, co_factor) == x) {
			cout << factor << " " << co_factor << endl;
			break;
		}
	}
	return 0;
}