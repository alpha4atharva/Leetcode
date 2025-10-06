class Solution {
public:
    vector<pair<int,int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        //{time for that cell,t,i,j}
        priority_queue<tuple<int,int,int,int>,vector<tuple<int,int,int,int>>,greater<tuple<int,int,int,int>>>pq;
        pq.push({max(0,grid[0][0]),0,0,0});
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        while(!pq.empty()){
            auto tup=pq.top();
            pq.pop();
            int time=get<0>(tup);
            int t=get<1>(tup);
            int row=get<2>(tup);
            int col=get<3>(tup);

            if(vis[row][col]) continue;
            vis[row][col]=true;

            if(row==n-1 && col==n-1){
                return time;
            }
            
            for(auto it:dir){
                int r=row+it.first,c=col+it.second;
                if(r<0 || c<0 || r>=n || c>=n || vis[r][c]) continue;
                pq.push({max(max(grid[r][c],time),t+1),t+1,r,c});
            }
        }
        return -1;
    }
};