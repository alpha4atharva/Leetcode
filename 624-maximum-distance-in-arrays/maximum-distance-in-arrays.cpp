class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int ans=INT_MIN,mini=arrays[0][0],maxi=arrays[0][arrays[0].size()-1];
        for(int i=1;i<arrays.size();i++){
            int n=arrays[i].size();
            ans=max(ans,maxi-arrays[i][0]);
            ans=max(ans,arrays[i][n-1]-mini);
            mini=min(mini,arrays[i][0]);
            maxi=max(maxi,arrays[i][n-1]);
        }
        return ans;
    }
};