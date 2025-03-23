class Solution {
public:
    long long MOD=1e9+7;
    int bfs(vector<vector<pair<int,int>>>adj,int src,int des)
    {
        int n=adj.size();
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>>pq;
        vector<int>ways(n,0);
        vector<long long>dis(n,LLONG_MAX);
        ways[0]=1;
        dis[0]=0;
        pq.push({0,0});
        while(!pq.empty())
        {
            int v=pq.top().second;
            long long d=pq.top().first;
            pq.pop();
            for(auto it:adj[v])
            {
                long long newd=it.second+d;
                if(newd<dis[it.first])
                {
                    dis[it.first]=newd;
                    ways[it.first]=ways[v];
                    pq.push({newd,it.first});
                }
                else if(newd==dis[it.first])
                {
                    ways[it.first]=(ways[it.first]+ways[v])%MOD;
                }
            }
        }
        return ways[des];
    }
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        return bfs(adj,0,n-1);
    }
};