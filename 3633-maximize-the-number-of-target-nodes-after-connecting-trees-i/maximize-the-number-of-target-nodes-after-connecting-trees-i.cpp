class Solution {
private:
    int bfs(const vector<vector<int>>& tree,int start,int k) {
        if(k<0) return 0;
        int n = tree.size();
        vector<int> visited(n, 0);
        queue<pair<int,int>>q;
        q.push({start,0});
        visited[start]=1;
        int reachable=0;
        while (!q.empty()) {
            auto [node,dist] = q.front();
            q.pop();
            reachable++;
            if(dist<k) {
                for(int neighbor:tree[node]) {
                    if (!visited[neighbor]) {
                        visited[neighbor]=1;
                        q.push({neighbor,dist+1});
                    }
                }
            }
        }
        return reachable;
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = 0, m = 0;
        for (auto& edge : edges1) {
            n = max(n,max(edge[0],edge[1])+1);
        }
        for (auto& edge : edges2) {
            m = max(m,max(edge[0],edge[1])+1);
        }
        vector<vector<int>> tree1(n), tree2(m);
        for (auto& edge : edges1) {
            tree1[edge[0]].push_back(edge[1]);
            tree1[edge[1]].push_back(edge[0]);
        }
        for (auto& edge : edges2) {
            tree2[edge[0]].push_back(edge[1]);
            tree2[edge[1]].push_back(edge[0]);
        }

        vector<int>reachableTree2(m);
        for (int i=0;i<m;i++) {
            reachableTree2[i]=bfs(tree2,i,k-1);
            // cout<<reachableTree2[i]<<" ";
        }

        vector<int>answer(n);
        for(int i=0;i<n;i++) {
            int maxReach = 0;
            int a=bfs(tree1,i,k);
            for (int j=0;j<m;j++) {
                maxReach=max(maxReach,reachableTree2[j]);
            }
            answer[i]=maxReach+a;
        }

        return answer;
    }
};