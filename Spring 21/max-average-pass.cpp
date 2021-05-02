class Solution {
public:
    double mx(double a,double b)
    {
        return (a + 1)/(b + 1) - a / b;
    }
    
    double maxAverageRatio(vector<vector<int>>& cls, int extra) {
        priority_queue<pair<double, pair<double, double>>> pq;
        
        for(auto v:cls)
            pq.push({mx(v[0], v[1]),{v[0], v[1]}});
        
        while(extra--)
        {
            pair<double, pair<double, double>> p = pq.top();
            
            p.first = mx(p.second.first + 1, p.second.second + 1);
            pq.pop();
            p.second.first += 1;
            p.second.second += 1;
            pq.push(p);
        }
        double ans=0;
        while(!pq.empty())
        {
           pair<double, pair<double, double>> p = pq.top();
            pq.pop();
            ans += p.second.first/p.second.second;
        }
        
        return ans/cls.size();
        
    }
};