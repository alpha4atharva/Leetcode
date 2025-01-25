class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n + 1, 0); // dp[i]: Minimum cost from day i to the end
        
        for (int i = n - 1; i >= 0; --i) {
            int ans = INT_MAX;
            int d = days[i];
            int j = i;
            while (j < n && days[j] < d + 1) ++j;
            ans = min(ans, dp[j] + costs[0]);
            
            // Find the next day after `d + 7` for 7-day pass
            j = i;
            while (j < n && days[j] < d + 7) ++j;
            ans = min(ans, dp[j] + costs[1]);
            
            // Find the next day after `d + 30` for 30-day pass
            j = i;
            while (j < n && days[j] < d + 30) ++j;
            ans = min(ans, dp[j] + costs[2]);
            
            dp[i] = ans;
        }
        
        return dp[0]; // Minimum cost to travel from the first day
    }
};
