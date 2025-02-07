static auto init = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> mp1; // ball->color
        unordered_map<int,set<int>> mp2; // color->>set of balls
        vector<int> ans;
        for(auto &it : queries){
            int x=it[0],y=it[1];
            if(mp1.count(x) && mp1[x]!=y){
                mp2[mp1[x]].erase(x);
                if(mp2[mp1[x]].size()==0){
                    mp2.erase(mp1[x]);
                }
                mp2[y].insert(x);
                mp1[x]=y;
            }
            else{
                mp1[x]=y;
                mp2[y].insert(x);
            }
            ans.push_back(mp2.size());
        }

        return ans;
    }
};