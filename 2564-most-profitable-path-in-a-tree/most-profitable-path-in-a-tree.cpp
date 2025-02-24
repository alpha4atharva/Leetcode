class Solution {
public:
    bool dfs(vector<vector<int>>&adj,vector<int>&path,int node,vector<bool> &vis){
        if(node==0)
            return true;

        for(int it:adj[node]){
            if(vis[it]) continue;
            path.push_back(it);
            vis[it]=true;
            if(dfs(adj,path,it,vis))    return true;
            path.pop_back();
        }
        return false;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=edges.size();
        vector<vector<int>> adj(n+1);
        for(auto &it : edges){
            int u=it[0],v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Alice distance from each node
        vector<int> dis(n+1,-1);
        vector<bool> vis(n+1,false);
        queue<int> qu;
        qu.push(0);
        vis[0]=true;
        int d=0;
        while(!qu.empty()){
            int size=qu.size();
            for(int i=0;i<size;i++){
                auto node=qu.front();
                qu.pop();
                dis[node]=d;
                for(auto it:adj[node]){
                    if(!vis[it]){
                        qu.push(it);
                        vis[it]=true;
                    }
                }
            }
            d++;
        }

        vector<int> path;
        path.push_back(bob);
        vis=vector<bool> (n+1,false);
        vis[bob]=true;
        dfs(adj,path,bob,vis);
        for(int i=0;i<path.size();i++){
            if(i==dis[path[i]]) amount[path[i]]/=2;
            else if(i<dis[path[i]]) amount[path[i]]=0;
        }
        
        vis=vector<bool>(n+1,false);
        int ans=INT_MIN;
        queue<pair<int,int>> q;
        q.push({0,amount[0]});
        vis[0]=true;
        while(!q.empty()){
            auto [node,dist]=q.front();
            q.pop();
            if(adj[node].size()==1 && node!=0) ans=max(ans,dist);
            else{
                for(auto &it:adj[node]){
                    if(!vis[it]){
                        vis[it]=true;
                        q.push({it,dist+amount[it]});
                    }
                }
            }
        }
        return ans;
    }
};