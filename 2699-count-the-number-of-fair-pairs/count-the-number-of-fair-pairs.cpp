class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        long long count=0;
        int n=nums.size();
        int k=0;
        while(k<n){
            auto i=lower_bound(nums.begin()+k+1,nums.end(),lower-nums[k]);
            auto j=upper_bound(nums.begin()+k+1,nums.end(),upper-nums[k]);
            count+=j-i;
            k++;
        }
        return count;
    }
};