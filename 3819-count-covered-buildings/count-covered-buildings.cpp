// class Solution {
// public:
//     int countCoveredBuildings(int n, vector<vector<int>>& build) {
//         unordered_map<int,vector<pair<int,int>>> x,y;
//         for(int i=0;i<build.size();i++){
//             int u=build[i][0];
//             int v=build[i][1];
//             x[u].push_back({v,i});
//             y[v].push_back({u,i});
//         }
        
//         vector<bool> a1(build.size(),false),a2(build.size(),false);
//         for(auto &[mp,it]:x){
//             sort(it.begin(),it.end());
//             for(int i=1;i<it.size()-1;i++){
//                 a1[it[i].second]=true;
//             }
//         }

//         for(auto &[mp,it]:y){
//             sort(it.begin(),it.end());
//             for(int i=1;i<it.size()-1;i++){
//                 a2[it[i].second]=true;
//             }
//         }

//         int ans=0;
//         for(int i=0;i<build.size();i++){
//             if(a1[i] && a2[i]) ans++;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& build) {
        int m=build.size();
        vector<int> top(n+1,INT_MAX),bottom(n+1,INT_MIN);
        vector<int> left(n+1,INT_MAX),right(n+1,INT_MIN);

        for(auto &it:build){
            int x=it[0],y=it[1];
            top[x]=min(top[x],y);
            bottom[x]=max(bottom[x],y);
            left[y]=min(left[y],x);
            right[y]=max(right[y],x);
        }

        int ans=0;
        for(auto &it:build){
            int x=it[0],y=it[1];
            if(top[x]<y && y<bottom[x] && left[y]<x && x<right[y]){
                ans++;
            }
        }
        return ans;
    }
};
