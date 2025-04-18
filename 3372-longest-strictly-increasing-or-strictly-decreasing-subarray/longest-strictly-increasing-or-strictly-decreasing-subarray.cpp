class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans=1,low=1,high=1;
        for(int i = 1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                high++;
                low=1;
            }
            else if(nums[i]<nums[i-1]){
                low++;
                high=1;
            }
            else{
                low=1;
                high=1;
            }
            ans=max({ans,low,high});
        }
        return ans;
    }
};