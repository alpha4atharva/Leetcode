class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        long long sum=0,f=0;
        for(int i=0;i<n;i++){
            f+=i*nums[i];
            sum+=nums[i];
        }

        long long ans=f;
        for(int k=1;k<n;k++){
            f=f+sum-n*nums[n-k];
            ans=max(ans,f);
        }

        return ans;
    }
};