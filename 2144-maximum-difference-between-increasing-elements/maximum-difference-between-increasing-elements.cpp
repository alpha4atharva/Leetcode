class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans=-1,n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans=max(ans,nums[j]-nums[i]);
            }
        }
        return ans==0?-1:ans;
    }
};