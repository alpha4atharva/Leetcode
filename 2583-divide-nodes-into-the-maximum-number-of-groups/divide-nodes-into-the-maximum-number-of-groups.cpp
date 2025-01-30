class Solution {
public:
    void dfs(int node,vector<vector<int>> &adj,vector<int>&color,bool &isBipartite,vector<int> &cc,int currentColor=1){
        if(!isBipartite)    return;
        color[node]=currentColor;
        cc.push_back(node);
        for(auto &it : adj[node]){
            if(color[it]==0){
                dfs(it,adj,color,isBipartite,cc,3-currentColor);
            }
            else if(color[it]==currentColor){
                isBipartite=false;
            }
        }
    }

    int bfs(int node,vector<vector<int>> &adj,int n){
        vector<int> dis(n+1,-1);
        queue<int> q;
        q.push(node);
        dis[node]=1;
        int maxi=1;
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            for(auto &it : adj[x]){
                if(dis[it]==-1){
                    dis[it]=dis[x]+1;
                    q.push(it);
                    maxi=max(maxi,dis[it]);
                }
            }
        }

        return maxi;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n+1);
        for(auto &it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        // first check if bipartite graph than not possible
        // then perform bfs to find max number of groups
        vector<int> color(n+1,0);
        int ans=0;
        for(int i=1;i<=n;i++){
            if(color[i]==0){
                bool isBipartite=true;
                vector<int> connectedComponents;
                dfs(i,adj,color,isBipartite,connectedComponents);
                if(!isBipartite) return -1;
                int maxi=0;
                for(auto &it : connectedComponents){
                    maxi=max(maxi,bfs(it,adj,n));
                }
                ans+=maxi;
            }
        }

        return ans;      
    }
};