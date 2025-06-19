class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int ans=1;
        sort(nums.begin(),nums.end());
        int i=0;
        for(int j=1;j<nums.size();j++){
            if(nums[j]-nums[i]>k){
                ans++;
                i=j;
            }
        }

        return ans;
    }
};