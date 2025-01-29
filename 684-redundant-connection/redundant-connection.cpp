class DSU {
public:
    vector<int> parent, rank;
 
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int node) {
        if (parent[node] != node) {
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }
 
    bool unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if(rootU == rootV)  return false;
        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DSU d(n+1);
        for(auto &it : edges){
            if(!d.unite(it[0],it[1])){
                return it;
            }
        }
        return {};
    }
};