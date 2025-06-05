class DSU {
public:
    vector<int> parent;
 
    DSU(int n) {
        parent.resize(n);
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
 
    void unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
 
        if (rootU != rootV) {
            if (rootU < rootV) {
                parent[rootV] = rootU;
            } else {
                parent[rootU] = rootV;
            }
        }
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n=s1.length();
        DSU dsu(26);
        for(int i=0;i<n;i++){
            dsu.unite(s1[i]-'a',s2[i]-'a');
        }

        string ans="";
        for(auto &c:baseStr){
            int p=dsu.find(c-'a');
            ans+=char(p+'a');
        }

        return ans;
    }
};