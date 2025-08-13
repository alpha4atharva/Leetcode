class Solution {
public:
    int MOD=1e9+7;
    long long modPow(long long base, long long exp) {
        long long res = 1;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<long long> powers;
        powers.push_back(1);
        for(int i=0;i<31;i++){
            if((1<<i)&n){
                powers.push_back((powers.back()*(1<<i))%MOD);
            }
        }
        
        vector<int> ans;
        for(auto it:queries){
            ans.push_back((powers[it[1]+1]*modPow(powers[it[0]],MOD-2))%MOD);
        }

        return ans;
    }
};