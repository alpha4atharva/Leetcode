class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int total=accumulate(nums.begin(),nums.end(),0);
        vector<int> ans(nums.size(),0);
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            ans[i]=abs(total-sum);
            total-=nums[i];
        }
        return ans;
    }
};