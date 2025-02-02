class Solution {
public:
    bool check(vector<int>& nums) {
        int flag=0;
        for(int i=1;i<nums.size();i++)
        {
             if(nums[i-1]>nums[i])
            {
                if(flag==1)
                    return false;
                else
                    flag=1;
            }
        }
        if(flag==1)
        {
            if(nums[0]<nums[nums.size()-1])
                return false;
        }
        return true;
    }
};