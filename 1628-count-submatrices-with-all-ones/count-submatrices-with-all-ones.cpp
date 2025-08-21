class Solution {
public:
    int func(int i,int j,vector<vector<int>>&dp,vector<vector<int>>& mat){
        int total=0;
        int mini=dp[i][j];
        for(int k=i;k>=0 && mat[k][j]==1;k--){
            mini=min(mini,dp[k][j]);
            total+=mini;
        }

        return total;
    }

    int numSubmat(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    dp[i][j]=(j==0)?1:dp[i][j-1]+1;
                }
            }
        }

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    ans+=func(i,j,dp,mat);
                }
            }
        }

        return ans;
    }
};