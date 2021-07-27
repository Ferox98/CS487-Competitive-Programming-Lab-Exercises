class Solution {
public:
    
    map<string, vector<string>> constructGraph(vector<vector<string>>& tickets, map<string, map<string, int>>& count) {
        map<string, vector<string>> adj_list;
        for (int i = 0; i < tickets.size(); i++) {
            string from = tickets[i][0];
            string to = tickets[i][1];
            adj_list[from].push_back(to);
            count[from][to]++;
        }
        for (auto iter = adj_list.begin(); iter != adj_list.end(); iter++) {
            sort(iter->second.begin(), iter->second.end());
        }
        return adj_list;
    }
    
    void dfs(map<string, vector<string>>& adj_list, vector<string> itinerary, map<string, map<string, int>>& count, string airport, int num_trips, vector<vector<string>>& solutions) {
        if (solutions.size() > 0) return;
        itinerary.push_back(airport);
        //for (auto& elem : itinerary) cout << elem << " , ";
        if (itinerary.size() - 1 == num_trips) {
            solutions.push_back(itinerary);
        }
        for (auto& destination : adj_list[airport]) {
            if (count[airport][destination] > 0) {
                count[airport][destination]--;
                dfs(adj_list, itinerary, count, destination, num_trips, solutions);
                count[airport][destination]++;
            }
        }
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, map<string, int>> count;
        map<string, vector<string>> adj_list = constructGraph(tickets, count);
        vector<string> itinerary;
        vector<vector<string>> solutions;
        dfs(adj_list, itinerary, count, "JFK", tickets.size(), solutions);
        return solutions[0];
    }
};