class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0) mp[nums[i]]++;
        }
        if(mp.size()==0){
            int maxi=INT_MIN;
            for(int i=0;i<nums.size();i++){
                maxi=max(maxi,nums[i]);
            }
            return maxi;
        }
        int ans=0;
        for(auto it:mp){
            ans+=it.first;
        }

        return ans;
    }
};