class Solution {
public:
    bool rec(vector<int> &ans,int n,vector<bool> &vis,int idx){
        while(idx<ans.size() && ans[idx]!=-1)  idx++;
        if(idx==ans.size()) return true;

        for(int i=n;i>=1;i--){
            if(!vis[i]){
                int j=(i==1?idx:idx+i);
                if(j<ans.size() && ans[j]==-1){
                    ans[idx]=ans[j]=i;
                    vis[i]=true;

                    if(rec(ans,n,vis,idx+1))   return true;

                    //Backtrack
                    ans[idx]=ans[j]=-1;
                    vis[i]=false;
                }
            }
        }
        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2*n-1,-1);
        vector<bool> vis(n+1,false);
        rec(ans,n,vis,0);
        return ans;
    }
};