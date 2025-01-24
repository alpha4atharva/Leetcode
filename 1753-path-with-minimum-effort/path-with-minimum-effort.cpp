class Solution {
public:
    vector<pair<int,int>> dir={{0,-1},{-1,0},{1,0},{0,1}};
    int minimumEffortPath(vector<vector<int>>& h) {
        int n=h.size(),m=h[0].size();
        vector<vector<int>> effort(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>> ,vector<pair<int,pair<int,int>>>, greater<>> pq;
        pq.push({0,{0,0}});
        effort[0][0]=0;
        while(!pq.empty()){
            auto [ans,x]=pq.top();
            pq.pop();
            auto [row,col]=x;

            if(row==n-1 && col==m-1)    return ans;

            for(auto &it : dir){
                int nrow=row+it.first,ncol=col+it.second;
                if(nrow<0 || ncol<0 || nrow>=n || ncol>=m)  continue;
                int newEffort=abs(h[nrow][ncol]-h[row][col]);
                newEffort=max(newEffort,ans);
                if(newEffort<effort[nrow][ncol]){
                    effort[nrow][ncol]=newEffort;
                    pq.push({newEffort,{nrow,ncol}});
                }
            }
        }
        return -1;
    }
};