class Solution {
public:
    int rob(vector<int>& arr) {
        int n=arr.size();
        if(n==1)    return arr[0];
        if(n==2)    return max(arr[1],arr[0]);
        vector<int> dp(n);
        dp[0]=arr[0];
        dp[1]=max(arr[0],arr[1]);
        for(int i=2;i<n-1;i++){
            dp[i]=max(dp[i-1],dp[i-2]+arr[i]);
        }
        int ans1=dp[n-2];

        dp[1]=arr[1];
        dp[2]=max(arr[1],arr[2]);
        for(int i=3;i<n;i++){
            dp[i]=max(dp[i-1],dp[i-2]+arr[i]);
        }

        return max(ans1,dp[n-1]);
    }
};