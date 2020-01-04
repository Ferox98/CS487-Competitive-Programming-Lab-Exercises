#include <math.h>

struct Coordinate {
    int x; 
    int y;
    int dist;
    
    Coordinate(int x, int y, int r0, int c0) {
        this->x = x;
        this->y = y;
        this->dist = abs(x - r0) + abs(y - c0);
    }
};

int partition(vector<Coordinate>& vec, int p, int r) {
	int pivot = vec[r].dist;
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (vec[j].dist < pivot) {
			i++;
			Coordinate temp = vec[i];
			vec[i] = vec[j];
			vec[j] = temp;
		}
	}
	Coordinate temp = vec[r];
	vec[r] = vec[i + 1];
	vec[i + 1] = temp;
	return i + 1;
}

void quickSort(vector<Coordinate>& vec, int p, int r) {
	if (p < r) {
		int q = partition(vec, p, r);
		quickSort(vec, p, q - 1);
		quickSort(vec, q + 1, r);
	}
}

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<Coordinate> coordinates;
        for(int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                Coordinate coord(i, j, r0, c0);
                coordinates.push_back(coord);
            }
        }
        quickSort(coordinates, 0, coordinates.size() - 1);
        vector<vector<int>> res;
        for(auto& coord : coordinates) {
            vector<int> pos;
            pos.push_back(coord.x);
            pos.push_back(coord.y);
            res.push_back(pos);
        }
        return res;
    }
};