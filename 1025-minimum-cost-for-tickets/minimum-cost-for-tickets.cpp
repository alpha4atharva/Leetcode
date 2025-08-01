class Solution {
public:
    int solve(int i,vector<int>&days,vector<int>&costs,vector<int>&dp) {
        if(i>=days.size()) return 0; // Base case: all days covered

        if(dp[i]!=-1) return dp[i];

        int ans=INT_MAX;
        // Option 1: Buy 1-day pass
        int j=i;
        while(j<days.size() && days[j]<days[i]+1) j++;
        ans=min(ans,costs[0]+solve(j,days,costs,dp));

        // Option 2: Buy 7-day pass
        j=i;
        while(j<days.size() && days[j]<days[i]+7) j++;
        ans=min(ans,costs[1]+solve(j,days,costs,dp));

        // Option 3: Buy 30-day pass
        j=i;
        while(j<days.size() && days[j]<days[i]+30) j++;
        ans=min(ans,costs[2]+solve(j,days,costs,dp));

        return dp[i]=ans;
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int> dp(n,-1);
        return solve(0,days,costs,dp);
    }
};
