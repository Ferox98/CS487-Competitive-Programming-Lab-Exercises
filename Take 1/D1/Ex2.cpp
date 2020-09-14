/*
	Author: Kaleab Belete Belay
	This program takes in an integer input from the user and draws a symmetrical isosceles right-angled triangle
*/

#include <iostream>

using namespace std;

void printSpace(int len) {
	for (int j = 0; j < len; j++) {
		cout << " ";
	}
}

void printStars(int row) {
	int num_stars = 2 * row + 1;
	for (int j = 0; j < num_stars; j++) {
		cout << "*";
	}
	cout << "\n";
}

void drawTriangle2(int n) {
	// no. of stars in a specific row is 2 * i + 1 
	// start by determining the maximum number of stars
	int max_stars = 2 * n + 1;
	for (int i = 0; i < n; i++) {
		printSpace(n - i);

		int num_stars = 2 * i + 1;

		printStars(i);
	}
}

int main() {
	int n;
	cout << "Enter n: " << endl;
	cin >> n;
	drawTriangle(n);
}