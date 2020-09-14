int max_h = 0;
vector<bool> visited;

void split(vector<int>& citations, int low, int high) {
	
	if (low > high) return;
	int mid = (int)((low + high) / 2);
	if (visited[mid]) return;
	// h is now high - mid + 1
	visited[mid] = true;
	if (citations[mid] >= (citations.size() - mid)) {
		// we've found the largest value for h yet
		max_h = citations.size() - mid;
		// there might be larger values for h yet, so keep searching to the left of mid
		split(citations, low, mid);
	}
	else {
		// value of h is too large, so minimize by recursively going to the right of mid
		split(citations, mid + 1, high);
	}
}

int hIndex(vector<int>& citations) {
	if (citations.size() == 0) return 0;
	visited = vector<bool>(citations.size(), false);
	split(citations, 0, citations.size() - 1);
	return max_h;
}