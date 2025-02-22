class Solution {
public:
    int count=0;
    void rec(string &ans,int idx,int n,int k){
    // Base case
    if(idx==n){
        count++;
        return;
    }

    // Put at idx
    for(char z='a';z<='c';z++){
        if(idx>0 && ans[idx-1]==z)   continue;
        ans[idx]=z;
        rec(ans,idx+1,n,k);
        if(count==k)    break;
    }
    }

    string getHappyString(int n, int k) {
        string ans(n,' ');
        rec(ans,0,n,k);
        if(k>count) return "";
        return ans;
    }
};