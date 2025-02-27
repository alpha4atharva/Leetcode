class Solution {
    // vector<vector<int>> memo;
    unordered_map<int,int> mp;

    int rec(int a,int b){
        if(mp.find(a+b)==mp.end()) return 0;
        return 1+rec(b,a+b);
    }
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
        for(int i=0;i<n;i++) mp[arr[i]]++;
        // memo.resize(n+1,vector<int>(n+1,-1));

        int maxi=0;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n;j++){
                if(mp.find(arr[i]+arr[j])==mp.end()) continue;
                maxi=max(maxi,rec(arr[i],arr[j]));
            }
        }

        return maxi==0?maxi:maxi+2;
    }
};