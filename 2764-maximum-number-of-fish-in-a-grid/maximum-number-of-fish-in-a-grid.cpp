class Solution {
public:
    void dfs(vector<vector<int>>&grid,int r,int c,int &curr)
    {
        int nr=grid.size();
        int nc=grid[0].size();
        curr=curr+grid[r][c];
        grid[r][c]=0;
        if(r-1>=0 && grid[r-1][c]>0) dfs(grid,r-1,c,curr);
        if(r+1<nr && grid[r+1][c]>0) dfs(grid,r+1,c,curr);
        if(c-1>=0 && grid[r][c-1]>0) dfs(grid,r,c-1,curr);
        if(c+1<nc && grid[r][c+1]>0) dfs(grid,r,c+1,curr);
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int nr=grid.size();
        int ans=0,curr=0;
        int nc=grid[0].size();
        for(int i=0;i<nr;i++)
        {
            for(int j=0;j<nc;j++)
            {
                curr=0;
                if(grid[i][j]>0)
                {
                    dfs(grid,i,j,curr);
                }
                ans=max(ans,curr);
            }
        }
        return ans;
    }
};