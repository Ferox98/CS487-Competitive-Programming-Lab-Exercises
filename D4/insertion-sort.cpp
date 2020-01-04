#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int>& vec) {
    for (int j = 1; j < vec.size(); j++) {
        int key = vec[j];
        int i = j - 1;
        while(i >= 0 && vec[i] > key) {
            vec[i + 1] = vec[i];
            i--;
        }
        vec[i + 1] = key;
    }
}