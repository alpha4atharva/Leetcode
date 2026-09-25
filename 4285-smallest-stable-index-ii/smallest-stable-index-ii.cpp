class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> mini(n), maxi(n);
        int val = INT_MIN;
        for(int i=0;i<n;i++){
            maxi[i] = max(val, nums[i]);
            val = max(val, nums[i]);
        }

        val = INT_MAX;
        for(int i=n-1;i>=0;i--){
            mini[i] = min(val, nums[i]);
            val = min(val, nums[i]);
        }

        for(int i = 0; i<n; i++){
            if(maxi[i]-mini[i]<=k) return i;
        }

        return -1;
    }
};