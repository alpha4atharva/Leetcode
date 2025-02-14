class Solution {
public:
    int atmost(vector<int>& nums,int k){
        unordered_map<int,int> mp;
        int n=nums.size(),sum=0,low=0,high=0,ans=0;
        while(high<n){
            mp[nums[high]]++;
            while(low<=high && mp.size()>k){
                mp[nums[low]]--;
                if(mp[nums[low]]==0)    mp.erase(nums[low]);
                low++;
            }
            ans+=high-low;
            high++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};