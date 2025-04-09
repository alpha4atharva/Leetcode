class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        if(nums[0]<k) return -1;
        int i=0;
        int ops=0;
        while(i<nums.size() && nums[i]==k) i++;
        while(i<nums.size())
        {
            if(nums[i]!=k)
            {
                k=nums[i];
                ops++;
            }
            i++;
        }
        return ops;
    }
};