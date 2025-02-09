class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n=nums.size();
        unordered_map<int,int> mp;
        long long ans=0;
        for(int i=0;i<n;i++){
            nums[i]-=i;
            ans+=mp[nums[i]];
            mp[nums[i]]++;
        }
        long long total=n*(n-1);
        return total/2-ans;
    }
};