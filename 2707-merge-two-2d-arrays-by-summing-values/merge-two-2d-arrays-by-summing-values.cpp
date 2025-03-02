class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int> freq;
        for(auto &it : nums1){
            freq[it[0]]+=it[1];
        }
        for(auto &it : nums2){
            freq[it[0]]+=it[1];
        }

        vector<vector<int>> ans;
        for(auto &it:freq){
                ans.push_back({it.first,it.second});
        }

        return ans;
    }
};