class Solution {
public:
    int lcs(string &s1, string &s2, int n, int m, vector<vector<int>> &dp){
        if(m==0 || n==0){
            return 0;
        }
        if(dp[n-1][m-1] != -1){
            return dp[n-1][m-1];
        }
        if(s1[n-1] == s2[m-1]){
            return dp[n-1][m-1]=1+lcs(s1,s2,n-1,m-1,dp);
        }
        else{
            return dp[n-1][m-1]=max(lcs(s1,s2,n-1,m,dp),lcs(s1,s2,n,m-1,dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return lcs(text1,text2,n,m,dp);
    }
};