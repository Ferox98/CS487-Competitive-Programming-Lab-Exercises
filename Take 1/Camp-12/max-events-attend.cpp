class Solution {
public:  
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](auto const& event_1, auto const& event_2) {
            if (event_1[0] != event_2[0])
                return event_1[0] < event_2[0];
            return event_1[1] < event_2[1];
        });
        priority_queue<int, vector<int>, greater<int>> pq;
        int today = 1, start_date = 0;
        int max_days = 0;
        int attended = 0;
        for(int i = 0; i < events.size(); i++)
            if(events[i][1] > max_days)
                max_days = events[i][1];
        while(today <= max_days) {
            for(int i = start_date; (i < events.size() && events[i][1] >= today && events[i][0] <= today); i++) {
                // insert the end dates of all events that can be attended today into the min-heap
                pq.push(events[i][1]);
                start_date++;
            }
            if(pq.empty()) {
                today++;
                continue;
            }
            int event = pq.top();
            pq.pop();
            attended++;
            // remove all events that have an end date equal to day
            while(!pq.empty() && pq.top() == today)
                pq.pop();
            today++;
        }
        return attended;
    }
};