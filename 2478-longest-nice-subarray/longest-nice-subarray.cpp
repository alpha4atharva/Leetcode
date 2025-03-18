class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
        int maxi=1;
        int j=0,x=0;
        for(int i=0;i<n;i++){
            while((x&nums[i])!=0){
                x^=nums[j];
                j++;
            }
            x|=nums[i];
            maxi=max(maxi,i-j+1);
        }

        return maxi;
    }
};