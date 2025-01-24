class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto &it : graph[i]){
                indegree[i]++;
                adj[it].push_back(i);
            }
        }
        vector<bool> vis(n,false);
        queue<int> q;    
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                vis[i]=true;
            }
        }

        while(!q.empty()){
            auto node=q.front();
            q.pop();
            for(auto &it : adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                    vis[it]=true;
                }
            }
        }

        vector<int> ans;
        for(int i=0;i<n;i++){
            if(vis[i]){
                ans.push_back(i);
            }
        }

        return ans;
    }
};