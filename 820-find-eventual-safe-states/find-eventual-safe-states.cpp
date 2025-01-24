class Solution {
public:
    bool dfs(vector<vector<int>> &adj,int i,vector<bool> &vis,vector<bool> &pathvis){
        vis[i]=true;
        pathvis[i]=true;
        for(auto &it : adj[i]){
            if(!vis[it]){
                if(dfs(adj,it,vis,pathvis)){
                    return true;
                }
            }
            else if(pathvis[it]){
                    return true;
            }
        }

        pathvis[i]=false;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool> vis(n,false),pathvis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(graph,i,vis,pathvis);
            }
        }

        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!pathvis[i]){
                ans.push_back(i);
            }
        }

        return ans;
    }
};