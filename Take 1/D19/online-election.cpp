#include <map>

class TopVotedCandidate {
public:

    map<int, int> leading;
    vector<int> times;

    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        this->times = times;
        vector<int> votes(5000, 0);
        int latest = 0;
        for (int i = 0; i < times.size(); i++) {
            votes[persons[i]]++;
            // get the index of the candidate with the most votes and put it in the map
            int largest = votes[latest], largest_idx = latest;
            for (int j = 0; j < votes.size(); j++) {
                if (votes[j] > largest) {
                    largest = votes[j];
                    largest_idx = j;
                }
            }
            if (votes[persons[i]] == largest) {
                largest_idx = persons[i];
                latest = persons[i];
            }
            
            leading[times[i]] = largest_idx;
        }
    }

    int bs(int low, int high, int t) {
        if (low > high) return times[high];
        int mid = (int)((low + high) / 2);
        if (t == times[mid]) return times[mid];
        else if (t < times[mid]) {
            return bs(low, mid - 1, t);
        }
        return bs(mid + 1, high, t);
    }

    int q(int t) {
        // do binary search to find slot
        int time = bs(0, times.size() - 1, t);
        return leading[time];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */