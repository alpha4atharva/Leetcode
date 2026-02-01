class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int mini=INT_MAX,idx=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<mini){
                mini=nums[i];
                idx=i;
            }
        }
        int mini2=INT_MAX,idx2=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=mini2 && i!=idx){
                mini2=nums[i];
                idx2=i;
            }
        }
        return nums[0]+mini+mini2;
    }
};