class Solution {
public:
    int MOD=1e9+7;
    long long fact(long long n){
        if(n==1) return 1;
        return (n*(fact(n-1)%MOD))%MOD;
    }
    int countPermutations(vector<int>& complexity) {
        int n=complexity.size();
        for(int i=1;i<n;i++){
            if(complexity[0]>=complexity[i]) return 0;
        }

        return fact(n-1);
    }
};