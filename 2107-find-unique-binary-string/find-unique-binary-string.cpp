class Solution {
    bool flag=false;
    unordered_map<string,int> mp;
public:
    void rec(string &ans,int idx,int &n){
        if(idx==n){
            if(mp.find(ans)==mp.end()){
                flag=true;
            }
            return;
        }

        ans[idx]='0';
        rec(ans,idx+1,n);
        if(flag)    return;;
        ans[idx]='1';
        rec(ans,idx+1,n);
    }

    string findDifferentBinaryString(vector<string>& nums) {
        for(auto &it:nums)  mp[it]++;

        int n=nums[0].length();
        string ans(n,' ');
        rec(ans,0,n);
        return ans;
    }
};