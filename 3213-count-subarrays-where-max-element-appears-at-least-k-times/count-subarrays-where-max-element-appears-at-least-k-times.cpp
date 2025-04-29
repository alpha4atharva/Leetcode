class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        long long count=0,a=0;
        int maxi=*max_element(nums.begin(),nums.end());
        int left=0,right=0;
        while(right<n){
            if(nums[right]==maxi){
                a++;
            }
            while(a>=k){
                count+=(n-right);
                if(nums[left]==maxi){
                    a--;
                }
                left++;
            }
            right++;
        }

        return count;
    }
};