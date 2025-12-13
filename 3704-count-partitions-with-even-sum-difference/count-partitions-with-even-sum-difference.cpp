class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int ans=0;
        long long totalsum=accumulate(nums.begin(),nums.end(),0);
        long long currsum=0;
        for(int i=0;i<nums.size()-1;i++){
            currsum+=nums[i];
            if((totalsum-2*currsum)%2==0) ans++;
        }

        return ans;
    }
};