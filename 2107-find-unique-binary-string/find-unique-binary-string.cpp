class Solution {
public:
    bool flag=false;
    void rec(string &ans,int idx,int n,unordered_map<string,int> &mp){
    // Base case
    if(idx==n){
        // Check
        if(mp.find(ans)==mp.end()){
            flag=true;
        }
        return;
    }

    // Put 0 at idx
    ans[idx]='0';
    rec(ans,idx+1,n,mp);

    if(flag==true)  return;

    // Put 1 at idx
    ans[idx]='1';
    rec(ans,idx+1,n,mp);

    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        unordered_map<string,int> mp;
        for(auto &it:nums)  mp[it]++;

        string ans(n,' ');

        rec(ans,0,n,mp);

        return ans;
    }
};