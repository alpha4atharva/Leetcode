class Solution {
public:
    int mod=1e9+7;
    vector<vector<int>> dp;
    int dfs(int n, int x, int base){
        int val=pow(base,x);
        if(val>n) return 0;         // Exceeded target
        if(val==n) return 1;        // Exact match

        if(dp[n][base]!=-1) return dp[n][base];
        // Include OR skip this base
        int take=dfs(n-val,x,base+1);
        int skip=dfs(n,x,base+1);

        return dp[n][base]=(take+skip)%mod;
    }

    int numberOfWays(int n, int x) {
        int maxBase=1;
        while(pow(maxBase,x)<=n) maxBase++;
        dp.assign(n+1,vector<int>(maxBase+2,-1));
        return dfs(n,x,1);
    }
};
