class Solution {
private:
    int bfs(const vector<vector<int>>& tree, int start, int k) {
        if (k < 0) return 0;
        int n = tree.size();
        vector<int> visited(n, 0);
        queue<pair<int, int>> q;
        q.push({start, k});
        visited[start] = 1;
        int reachable = 0;
        while (!q.empty()) {
            auto [node, dist] = q.front();
            q.pop();
            if (dist % 2 == 0)
                reachable++;
            for (int neighbor : tree[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = 1;
                    q.push({neighbor, dist + 1});
                }
            }
        }
        return reachable;
    }

    void func(const vector<vector<int>>& tree, int start, int a,vector<int>& answer) 
    {
        int n=tree.size();
        vector<int> visited(n, 0);
        queue<pair<int,int>> q;
        q.push({start,0});
        visited[start]=1;
        while (!q.empty()) {
            auto [node, dist] = q.front();
            q.pop();
            if (dist % 2 == 0)
                answer[node]=a;
            else
                answer[node]=n-a;
            for (int neighbor : tree[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = 1;
                    q.push({neighbor, dist+1});
                }
            }
        }
    }

public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = 0, m = 0;
        for (const auto& edge : edges1) {
            n = max(n, max(edge[0], edge[1]) + 1);
        }
        for (const auto& edge : edges2) {
            m = max(m, max(edge[0], edge[1]) + 1);
        }
        vector<vector<int>> tree1(n), tree2(m);
        for (const auto& edge : edges1) {
            tree1[edge[0]].push_back(edge[1]);
            tree1[edge[1]].push_back(edge[0]);
        }
        for (const auto& edge : edges2) {
            tree2[edge[0]].push_back(edge[1]);
            tree2[edge[1]].push_back(edge[0]);
        }
        int reachableTree2;
        reachableTree2=bfs(tree2, 0, 1);
        reachableTree2=max(reachableTree2,m-reachableTree2);

        int a=bfs(tree1,0,0);
        vector<int>answer(n);
        func(tree1,0,a,answer);
        for(int i=0;i<n;i++)
            answer[i]+=reachableTree2;
        return answer;
    }
};