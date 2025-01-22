class Solution {
public:
    vector<pair<int,int>> dir={{-1,0},{0,-1},{1,0},{0,1}};
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        // solving using bfs
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    grid[i][j]='0';
                    while(!q.empty()){
                        auto [row,col]=q.front();
                        q.pop();
                        for(auto &it : dir){
                            int nrow=row+it.first , ncol=col+it.second;
                            if(nrow<0 || ncol<0 || nrow>=n || ncol>=m)  continue;
                            if(grid[nrow][ncol]=='1'){
                                q.push({nrow,ncol});
                                grid[nrow][ncol]='0';
                            }
                        }
                    }
                }
            }
        }

        return ans;
    }
};