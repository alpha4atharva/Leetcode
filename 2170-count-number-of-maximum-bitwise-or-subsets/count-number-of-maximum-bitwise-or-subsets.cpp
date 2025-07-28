class Solution {
public:
    unordered_map<int,int> mp;
    void gen(vector<int>&nums,int val,int idx,int n){
        if(idx==n){
            mp[val]++;
            return;
        }
        gen(nums,val,idx+1,n);
        val=val|nums[idx];
        gen(nums,val,idx+1,n);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size();
        gen(nums,0,0,n);
        int ans=0,maxi=INT_MIN;
        for(auto it:mp){
            if(it.first>maxi){
                maxi=it.first;
                ans=it.second;
            }
        }
        return ans;
    }
};