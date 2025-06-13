class Solution {
public:
    bool isPossible(vector<int>&nums,int diff,int p){
        int count=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]<=diff){
                count++;
                i++;
            }
            if(count>=p) return true;
        }
        return false;
    }

    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0,left=0,right=1e9;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(isPossible(nums,mid,p)){
                ans=mid;
                right=mid-1;
            }
            else left=mid+1;
        }
        return ans;
    }
};