class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& build) {
        unordered_map<int,vector<pair<int,int>>> x,y;
        for(int i=0;i<build.size();i++){
            int u=build[i][0];
            int v=build[i][1];
            x[u].push_back({v,i});
            y[v].push_back({u,i});
        }
        
        vector<bool> a1(build.size(),false),a2(build.size(),false);
        for(auto &[mp,it]:x){
            sort(it.begin(),it.end());
            for(int i=1;i<it.size()-1;i++){
                a1[it[i].second]=true;
            }
        }

        for(auto &[mp,it]:y){
            sort(it.begin(),it.end());
            for(int i=1;i<it.size()-1;i++){
                a2[it[i].second]=true;
            }
        }

        int ans=0;
        for(int i=0;i<build.size();i++){
            if(a1[i] && a2[i]) ans++;
        }
        return ans;
    }
};