class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int> lastSeen(32,-1);
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            for(int bit=0;bit<32;bit++){
                if(((nums[i]>>bit)&1)==1){
                    lastSeen[bit]=i;
                }
            }

            int idx=i;
            for(int bit=0;bit<32;bit++){
                idx=max(idx,lastSeen[bit]);
            }

            ans[i]=idx-i+1;
        }

        return ans;
    }
};