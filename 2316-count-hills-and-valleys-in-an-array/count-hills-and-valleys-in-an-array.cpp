class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int v=0,h=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]) continue;
            int l=nums[i],r=nums[i];
            for(int j=i-1;j>=0;j--){
                if(nums[j]<nums[i]){
                    l=nums[j];
                    break;
                }
                else if(nums[j]>nums[i]){
                    l=nums[j];
                    break;
                }
            }
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]<nums[i]){
                    r=nums[j];
                    break;
                }
                else if(nums[j]>nums[i]){
                    r=nums[j];
                    break;
                }
            }
            
            if(l<nums[i] && r<nums[i]) v++;
            else if(l>nums[i] && r>nums[i]) h++;
        }

        return v+h;
    }
};