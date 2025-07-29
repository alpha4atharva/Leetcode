class Solution {
public:
    void bfs(unordered_map<int,vector<int>>&adj, unordered_map<int,vector<int>>&comp,vector<int>&vis,int src){
        queue<int>q;
        q.push(src);
        vis[src] = 1;
        comp[src].push_back(src);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto &nbr:adj[node]){
                if(vis[nbr]==0){
                    vis[nbr]=1;
                    comp[src].push_back(nbr);
                    q.push(nbr);
                }
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>vis(n,0);
        unordered_map<int,vector<int>>comp;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                bfs(adj,comp,vis,i);
                cnt++;
            }
        }
        
        // for(auto &it:comp){
        //     cout<<it.first<<"->";
        //     for(int i=0;i<it.second.size();i++){
        //         cout<<it.second[i]<<"-";
        //     }
        //     cout<<endl;
        // }

        int ans=0;
        for(auto &it:comp){
            vector<int>& nodes=it.second;
            int nodeCount=nodes.size();
            int edgeCount=0;
            for(auto &node:nodes){
                edgeCount+=adj[node].size();
            }
            edgeCount/=2; 
            if(edgeCount==(nodeCount*(nodeCount-1))/2){
                ans++;
            }
        }

        return ans;
    }
};