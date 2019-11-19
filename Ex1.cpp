/*
	Author: Kaleab Belete Belay
	This program takes in an integer input from the user and displays an isosceles right-angled triangle
*/

#include <iostream>

using namespace std;

void drawTriangle(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cout << "*";
		}
		cout << endl;
	}
}

int main() {
	cout << "Enter n: " << endl;
	int n;
	cin >> n;
	drawTriangle(n);
}