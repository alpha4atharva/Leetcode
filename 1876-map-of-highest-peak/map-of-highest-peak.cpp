class Solution {
public:
    vector<pair<int,int>> dir={{-1,0},{0,-1},{1,0},{0,1}};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size(),m=isWater[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==1){
                    isWater[i][j]=0;
                    q.push({i,j});
                    vis[i][j]=true;
                }
            }
        }


        while(!q.empty()){
            auto [row,col]=q.front();
            q.pop();
            for(auto &it : dir){
                int nrow=row+it.first,ncol=col+it.second;
                if(nrow<0 || ncol<0 || nrow>=n || ncol>=m)  continue;
                if(!vis[nrow][ncol]){
                    isWater[nrow][ncol]=isWater[row][col]+1;
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=true;
                }
            }
        }
        
        return isWater;
    }
};