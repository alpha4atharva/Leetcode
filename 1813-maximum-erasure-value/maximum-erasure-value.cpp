class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> s;
        int l=0,r=0,cursum=0,maxsum=0;
        while(r<n){
            s.insert(nums[r]);
            cursum+=nums[r];
            r++;

            while(r-l>s.size()){
                cursum-=nums[l];
                if(nums[r-1]!=nums[l]){
                    s.erase(nums[l]);
                }
                l++;
            }
            maxsum=max(cursum,maxsum);
        }
        return maxsum;
    }
};