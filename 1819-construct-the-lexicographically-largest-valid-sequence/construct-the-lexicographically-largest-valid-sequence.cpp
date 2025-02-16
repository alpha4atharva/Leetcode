class Solution {
public:
    bool rec(vector<int> &ans,int n,set<int> &placed,int idx){
        while(idx<ans.size() && ans[idx]!=-1)  idx++;
        if(idx==ans.size()) return true;

        for(int i=n;i>=1;i--){
            if(placed.find(i)==placed.end()){
                int j=(i==1?idx:idx+i);
                if(j<ans.size() && ans[j]==-1){
                    ans[idx]=ans[j]=i;
                    placed.insert(i); 

                    if(rec(ans,n,placed,idx+1))   return true;

                    //Backtrack
                    ans[idx]=ans[j]=-1;
                    placed.erase(i);
                }
            }
        }
        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2*n-1,-1);
        set<int> placed;
        rec(ans,n,placed,0);
        return ans;
    }
};