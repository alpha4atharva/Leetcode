class Solution {
public:
    bool flag=false;
    void rec(string &ans,set<string> &st,int idx,int &n){
        if(idx==n){
            if(st.find(ans)==st.end())  flag=true;
            return;
        }

        ans[idx]='0';
        rec(ans,st,idx+1,n);
        if(flag)    return;
        ans[idx]='1';
        rec(ans,st,idx+1,n);
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums[0].size();
        set<string> st;
        for(auto it : nums){
            st.insert(it);
        }
        string ans(n,' ');
        rec(ans,st,0,n);
        return ans;
    }
};