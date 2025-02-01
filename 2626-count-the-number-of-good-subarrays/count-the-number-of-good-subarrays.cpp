class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp; // for checking pairs count
        long long j=0,ans=0;// for checking minimum left index required
        for(int i=0;i<n;i++){
            k-=mp[nums[i]];
            mp[nums[i]]++;
            while(k<=0){// neccessary condition satisfied
                mp[nums[j]]--;
                k+=mp[nums[j]];
                j++;
            }
            ans+=j;// all subarrays at left from this position
        }
        return ans;
    }
};