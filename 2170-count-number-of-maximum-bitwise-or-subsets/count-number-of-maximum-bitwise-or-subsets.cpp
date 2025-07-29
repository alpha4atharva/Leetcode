class Solution {
public:
    int maxi=0;
    int c=0;
    void gen(vector<int>&nums,int val,int idx,int n){
        if(idx==n){
            if(val==maxi){
                c++;
            }
            else if(val>maxi){
                maxi=val;
                c=1;
            }
            return;
        }
        gen(nums,val,idx+1,n);
        val=val|nums[idx];
        gen(nums,val,idx+1,n);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size();
        gen(nums,0,0,n);
        return c;
    }
};