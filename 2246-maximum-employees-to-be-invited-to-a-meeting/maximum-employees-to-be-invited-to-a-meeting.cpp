class Solution {
public:
    int maximumInvitations(vector<int>& f) {
        // observations
        // 1-Each node will have only one outgoing edge.
        // 2-If there is cycle of len>2 only that can occur.
        // 3-If there is cycle of len=2, then branching possible.
        int n=f.size();
        vector<vector<int>> adj(n);
        vector<int> inDegree(n,0),depth(n,1);
        for(int i=0;i<n;i++){
            adj[i].push_back(f[i]);
            inDegree[f[i]]++;
        }
        // calculating branching depth
        queue<int> q;
        for(int i=0;i<n;i++){
            if(inDegree[i]==0)  q.push(i);
        }
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            int next=f[node];
            depth[next]=max(depth[next],depth[node]+1);
            inDegree[next]--;
            if(inDegree[next]==0){
                q.push(next);
            }
        }
        // calculating length of cycles
        int maxcycle=0,twocycles=0;
        for(int i=0;i<n;i++){
            if(inDegree[i]==0)  continue;
            int currlen=0,node=i;
            while(inDegree[node]>0){
                inDegree[node]--;
                node=f[node];
                currlen++;
            }
            if(currlen==2){
                twocycles+=depth[node]+depth[f[node]];
            }
            else{
                maxcycle=max(maxcycle,currlen);
            }
        }

        return max(maxcycle,twocycles);
    }
};