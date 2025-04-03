class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return 0; // Not enough elements to form a triplet

        vector<int> prefix(n,0),suffix(n,0);

        // Build prefix max array
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=max(prefix[i-1],nums[i]);
        }

        // Build suffix max array
        suffix[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]=max(suffix[i+1],nums[i]);
        }

        long long ans=0;

        // Iterate through the array and calculate the triplet value
        for(int i=1;i<n-1;i++){
            if(prefix[i-1]>nums[i]){  // Ensure valid (a > b)
                long long product=(long long)(prefix[i-1]-nums[i]) * suffix[i + 1];
                ans=max(ans,product);
            }
        }

        return ans;
    }
};
