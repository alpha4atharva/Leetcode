class Solution {
public:
    void dfs(vector<int> &edges, int node, vector<int> &dis, vector<bool>& vis, int d){
        if(node==-1 || vis[node]) return;
        vis[node]=true;
        dis[node]=d;
        dfs(edges,edges[node],dis,vis,d+1);
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2){
        int n=edges.size();
        vector<int> dis1(n,-1),dis2(n,-1);
        vector<bool> vis1(n,false),vis2(n,false);

        dfs(edges,node1,dis1,vis1,0);
        dfs(edges,node2,dis2,vis2,0);

        int ans=-1,mini=INT_MAX;
        for(int i=0;i<n;i++){
            if(dis1[i]!=-1 && dis2[i]!=-1){
                int maxi=max(dis1[i],dis2[i]);
                if(maxi<mini){
                    mini=maxi;
                    ans=i;
                }
            }
        }
        return ans;
    }
};
