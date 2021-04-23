class Solution {
public:
    int minSideJumpsHelper(vector<vector<int>>& dp, int pos, int i, int n, vector<int>&arr){
        if(arr[i] == pos)
            return INT_MAX;
        
        if(i + 1 == n)
            return 0;
        
        if(dp[pos][i] != INT_MAX)
            return dp[pos][i];
        
        if(pos == arr[i+1]){
            int x = (pos + 1) % 3;
            int y= (pos + 2) % 3;
            if (x == 0)
                x=3;
            if(y == 0)
                y=3;
            dp[pos][i]= 1 + min(minSideJumpsHelper(dp, x, i, n, arr), minSideJumpsHelper(dp, y, i, n, arr));
        }
        else dp[pos][i] = minSideJumpsHelper(dp, pos, i+1, n, arr); 
        
        return dp[pos][i];
    }
    int minSideJumps(vector<int>& arr) {
        vector<vector<int>> dp (4, vector<int>(arr.size()+2, INT_MAX));
        return minSideJumpsHelper(dp, 2, 0, arr.size(), arr);
    }
}; 