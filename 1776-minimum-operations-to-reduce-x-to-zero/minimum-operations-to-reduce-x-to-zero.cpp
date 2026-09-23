class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long sum = accumulate(nums.begin(),nums.end(),0);
        sum -= x;
        int i=0, j=0;
        long long currsum = 0;
        int maxi = INT_MIN;
        while(j<nums.size()){
            currsum += nums[j++];
            while(currsum>sum && i<j) currsum -=nums[i++];
            if(currsum == sum)  maxi = max(maxi,j-i);
        }
        if(maxi == INT_MIN) return -1;
        return nums.size()-maxi;
    }
};