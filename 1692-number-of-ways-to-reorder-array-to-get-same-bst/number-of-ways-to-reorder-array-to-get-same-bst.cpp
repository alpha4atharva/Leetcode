class Solution {
public:
    long long ans=1;
    const int MOD=1e9+7;

    int helper(vector<int> &nums,vector<vector<long long>> &dp){
        int n=nums.size();
        if(n<=1)    return 1;
        vector<int> low,high;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[0])   low.push_back(nums[i]);
            else    high.push_back(nums[i]);
        }
        nums.clear();
        int b=high.size();
        return ((dp[n-1][b]*helper(low,dp))%MOD)*helper(high,dp)%MOD;
    }

    int numOfWays(vector<int>& nums) {
        int n=nums.size();
        vector<vector<long long>> dp(n+1,vector<long long>(n+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            dp[i][0]=1;
            for(int j=1;j<=i;j++){
                dp[i][j]=(dp[i-1][j-1] + dp[i-1][j])%MOD;
            }
        }
        ans=helper(nums,dp);
        return ans-1;
    }
};