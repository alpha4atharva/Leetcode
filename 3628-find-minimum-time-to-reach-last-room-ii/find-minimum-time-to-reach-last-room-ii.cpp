class Solution {
public:
    vector<pair<int,int>> dir={{-1,0},{0,-1},{0,1},{1,0}};
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n=moveTime.size(),m=moveTime[0].size();
        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,0,0});
        moveTime[0][0]=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int ct=it[0];
            int cr=it[1];
            int cc=it[2];
            if(cr==n-1 && cc==m-1) return ct;
            if(ct>=dp[cr][cc]) continue;
            dp[cr][cc]=ct;
            for(auto it:dir){
                int r=cr+it.first,c=cc+it.second;
                if(r<0 || c<0 || r>=n || c>=m) continue;
                int cost=(cr+cc)%2+1;
                int newTime=max(moveTime[r][c],ct)+cost;
                if(dp[r][c]>newTime){
                    pq.push({newTime,r,c});
                }
            }
        }
        return -1;
    }
};