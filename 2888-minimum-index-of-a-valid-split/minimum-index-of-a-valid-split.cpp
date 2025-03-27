class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int> mp,left;
        for(auto it:nums) mp[it]++;
        for(int i=0;i<nums.size();i++){
            left[nums[i]]++;
            mp[nums[i]]--;
            if(2*left[nums[i]]>(i+1) && 2*mp[nums[i]]>(nums.size()-i-1)) return i;
        }
        return -1;
    }
};