class Solution {
public:
    void dfs(vector<int> &ans,int a,int n){
        if(a>n) return;
        ans.push_back(a);
        for(int i=0;i<10;i++){
            dfs(ans,a*10+i,n);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i=1;i<=9;i++){
            dfs(ans,i,n);
        }
        return ans;
    }
};