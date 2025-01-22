class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        // adj
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        //answer through bfs
        int ans=0;
        queue<int> q;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                q.push(i);
                vis[i]=true;
                while(!q.empty()){
                    auto node=q.front();
                    q.pop();
                    for(auto &it : adj[node]){
                        if(!vis[it]){
                            q.push(it);
                            vis[it]=true;
                        }
                    }
                }
            }
        }

        return ans;

    }
};