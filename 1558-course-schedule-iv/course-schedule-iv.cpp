class Solution {
public:
    void dfs(vector<vector<int>> &adj,int &parent,int &node,vector<vector<bool>> &isReachable,vector<bool> &vis){
        isReachable[parent][node]=true;
        vis[node]=true;
        for(auto &it : adj[node]){
            if(!vis[it]){
                dfs(adj,parent,it,isReachable,vis);
            }
        }
}
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for(auto &it : pre){
            int u=it[0],v=it[1];
            adj[u].push_back(v);
        }
        vector<vector<bool>> isReachable(n,vector<bool> (n,false));
        for(int i=0;i<n;i++){
            vector<bool> vis(n,false);
            dfs(adj,i,i,isReachable,vis);
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout << isReachable[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        vector<bool> ans;
        for(auto &it : queries){
            ans.push_back(isReachable[it[0]][it[1]]);
        }

        return ans;
    }
};