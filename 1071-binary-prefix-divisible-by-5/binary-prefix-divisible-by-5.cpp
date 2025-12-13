class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n=nums.size();
        long long num=0;
        vector<bool> ans(n,false);
        for(int i=0;i<n;i++){
            num=(num*2)%5;
            if(nums[i]==1) num++;
            if(num%5==0) ans[i]=true;
        }

        return ans;
    }
};