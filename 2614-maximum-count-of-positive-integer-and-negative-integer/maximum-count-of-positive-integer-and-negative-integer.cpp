class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        int low=0,high=n-1,idx=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]<0){
                idx=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        int neg=idx+1,pos=n-idx-1;
        while(idx+1<n && nums[idx+1]==0) pos--,idx++;
        return max(neg,pos);
    }
};