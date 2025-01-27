class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &it : flights){
            int u=it[0],v=it[1],w=it[2];
            adj[u].push_back({v,w});
        }
        vector<int> dist(n,INT_MAX);
        queue<pair<int,int>> q;
        q.push({src,0});
        dist[src]=0;
        int stops=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto [node,d]=q.front();
                q.pop();
                if(stops>k) continue;
                for(auto &it : adj[node]){
                    int u=it.first,w=it.second;
                    if(dist[u]>d+w){
                        dist[u]=d+w;
                        q.push({u,d+w});
                    }
                }
            }
            stops++;
        }

        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};