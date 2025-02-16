class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> a(n);
        for(int i=1;i<=n;i++){
            a[i-1]=i;
        }
        k--;
        while(k--){
            next_permutation(a.begin(),a.end());
        }
        string ans="";
        for(auto it:a){
            ans+=to_string(it);
        }
        return ans;
    }
};