class Solution {
public:
    int ans=0;
    void recur(vector<int> &nums,int x,int idx){
        if(idx==nums.size()){
            ans+=x;
            return;
        }
        recur(nums,x,idx+1);
        x^=nums[idx];
        recur(nums,x,idx+1);
    }

    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        recur(nums,0,0);
        return ans;
    }
};