class Solution {
public:
    vector<vector<pair<int,int>>> dirs={
        {{0,-1},{0,1}},  // 1: left, right
        {{-1,0},{1,0}},  // 2: up, down
        {{0,-1},{1,0}},  // 3: left, down
        {{0,1},{1,0}},   // 4: right, down
        {{0,-1},{-1,0}}, // 5: left, up
        {{0,1},{-1,0}}   // 6: right, up
    };

    bool dfs(int i,int j,vector<vector<bool>> &vis,vector<vector<int>>& grid){
        int m=grid.size(),n=grid[0].size();
        if(i==m-1 && j==n-1) return true;
        vis[i][j]=true;
        for(auto& dir:dirs[grid[i][j]-1]){
            int x=i+dir.first;
            int y=j+dir.second;
            if(x>=0 && x<m && y>=0 && y<n && !vis[x][y]){
                int nxt=grid[x][y]-1;
                for(auto& it:dirs[nxt]) {
                    if(x+it.first==i && y+it.second==j) {
                        if (dfs(x,y,vis,grid)) return true;
                    }
                }
            }
        }
        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        return dfs(0,0,vis,grid);
    }
};