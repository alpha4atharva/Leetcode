class Solution {
public:
    void rec(string &ans,int idx,int &n,int &k){
        if(idx==n){
            k--;
            return;
        }

        for(char c='a';c<='c';c++){
            if(idx>0 && ans[idx-1]==c)  continue;
            if(k==0)    return;
            ans[idx]=c;        
            rec(ans,idx+1,n,k);
        }
    }

    string getHappyString(int n, int k) {
        string ans(n,' ');
        rec(ans,0,n,k);
        if(k>0) return "";
        return ans;
    }
};