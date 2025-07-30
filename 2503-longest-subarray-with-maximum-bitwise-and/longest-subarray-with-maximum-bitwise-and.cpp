class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int m=max_element(nums.begin(),nums.end())-nums.begin();
        int maxlen=0;
        for(int i=m;i<nums.size();i++)
        {
            int currlen=0;
            while(i<nums.size() && nums[i]==nums[m])
            {
                currlen++;
                i++;
            }
            maxlen=max(maxlen,currlen);
        }
        return maxlen;
    }
};