class Solution {
public:
    int atmost(vector<int> &nums,int goal){
        int sum=0,low=0,high=0,ans=0;
        while(high<nums.size()){
            sum+=nums[high];
            while(low<=high && sum>goal) sum-=nums[low++];
            ans+=(high-low);
            high++;
        }
        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums,goal)-atmost(nums,goal-1);
    }
};