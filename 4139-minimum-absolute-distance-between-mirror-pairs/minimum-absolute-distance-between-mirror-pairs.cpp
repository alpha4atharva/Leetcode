class Solution {
public:
    int rev(int n){
        string str=to_string(n);
        reverse(str.begin(),str.end());
        n=stoi(str);
        return n;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            if(mp.find(nums[i])!=mp.end()){
                mini=min(mini,abs(i-mp[nums[i]]));
            }
            int val=rev(nums[i]);
            mp[val]=i;
        }
        return mini==INT_MAX?-1:mini;
        
    }
};