class Solution {
    int ans=0,n,m,color;
public:
    void dfs(vector<vector<int>> &grid,int &curr,int i,int j,int color){
        curr++;
        grid[i][j]=color;
        if(i-1>=0 && grid[i-1][j]==1)   dfs(grid,curr,i-1,j,color);
        if(i+1<n && grid[i+1][j]==1)    dfs(grid,curr,i+1,j,color);
        if(j-1>=0 && grid[i][j-1]==1)   dfs(grid,curr,i,j-1,color);
        if(j+1<m && grid[i][j+1]==1)    dfs(grid,curr,i,j+1,color);
    }
    int largestIsland(vector<vector<int>>& grid) {
        n=grid.size(),m=grid[0].size();
        color=2;
        unordered_map<int,int> mp;
        mp[0]=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int curr=0;
                    dfs(grid,curr,i,j,color);
                    mp[color]=curr;
                    color++;
                    ans=max(ans,curr);
                }
            }
        } 

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    int curr=1;
                    set<int> st;
                    if(i-1>=0) st.insert(grid[i-1][j]); 
                    if(i+1<n) st.insert(grid[i+1][j]); 
                    if(j-1>=0) st.insert(grid[i][j-1]);   
                    if(j+1<m) st.insert(grid[i][j+1]); 
                    for(auto &it : st){
                        curr+=mp[it];
                    }
                    ans=max(ans,curr);
                }
            }
        }

        return ans;
    }
};