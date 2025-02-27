class Solution {
    vector<vector<int>> memo;
    unordered_map<int,int> mp;

    int rec(vector<int> &a,int i,int j){
        if(mp.find(a[i]+a[j])==mp.end()) return 0;
        if(memo[i][j]!=-1)  return memo[i][j];
        return memo[i][j]=1+rec(a,j,mp[a[i]+a[j]]);
    }
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
        for(int i=0;i<n;i++) mp[arr[i]]=i;
        memo.resize(n+1,vector<int>(n+1,-1));

        int maxi=0;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n;j++){
                if(mp.find(arr[i]+arr[j])==mp.end()) continue;
                maxi=max(maxi,rec(arr,i,j));
            }
        }

        return maxi==0?maxi:maxi+2;
    }
};