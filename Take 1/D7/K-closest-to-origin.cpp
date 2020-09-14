#include <math.h>

struct Coord {
    int x; 
    int y;
    int dist;
    
    Coord(int num1, int num2) {
        x = num1;
        y = num2;
        dist = pow(num1, 2) + pow(num2, 2);
    }
};

int partition(vector<Coord>& vec, int p, int r) {
	int pivot = vec[r].dist;
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (vec[j].dist < pivot) {
			i++;
			Coord temp = vec[i];
			vec[i] = vec[j];
			vec[j] = temp;
		}
	}
	Coord temp = vec[r];
	vec[r] = vec[i + 1];
	vec[i + 1] = temp;
	return i + 1;
	
}

void quickSort(vector<Coord>& vec, int p, int r) {
	if (p < r) {
		int q = partition(vec, p, r);
		quickSort(vec, p, q - 1);
		quickSort(vec, q + 1, r);
	}
}

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<Coord> coords;
        for(int i = 0; i < points.size(); i++) {
            Coord coord(points[i][0], points[i][1]);
            coords.push_back(coord);
        }
        quickSort(coords, 0, coords.size() - 1);
        vector<vector<int>> res;
        for(int i = 0; i < K; i++) {
            vector<int> c;
            c.push_back(coords[i].x);
            c.push_back(coords[i].y);
            res.push_back(c);
        }
        return res;
    }
};