class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        long long c=0;
        int i=0;
        while(i<n){
            while(i<n && nums[i]==0){
                c++,i++;
            }
            ans+=(c*(c+1))/2;
            c=0;
            i++;
        }
        return ans;
    }
};