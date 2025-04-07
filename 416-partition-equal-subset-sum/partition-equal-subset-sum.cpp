class Solution {
public:
    bool recur(int idx,int target,vector<int>&nums,vector<vector<int>> &memo){
        if(target==0)   return true;

        if(idx==nums.size() || target<0) return false;
        
        if(memo[idx][target]!=-1)   return memo[idx][target];
        return memo[idx][target]=recur(idx+1,target-nums[idx],nums,memo)||recur(idx+1,target,nums,memo);
    }

    bool canPartition(vector<int>& nums) {
        int n=nums.size(); 
        int totalsum=accumulate(nums.begin(),nums.end(),0);
        if(totalsum%2==1)   return false; //can't divide odd sum into two parts

        int targetsum=totalsum/2;
        vector<vector<int>> memo(n,vector<int>(targetsum+1,-1));
        return recur(0,targetsum,nums,memo);
    }
};