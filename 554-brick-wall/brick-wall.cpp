class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n=wall.size();
        unordered_map<long long,long long> mp;
        
        for(int i=0;i<n;i++){
            long long len=0;
            for(int j=0;j<wall[i].size()-1;j++){
                len+=wall[i][j];
                mp[len]++;
            }
        }

        long long maxi=0;
        for(auto &it : mp){
            maxi=max(maxi,it.second);
        }

        return n-maxi;
    }
};