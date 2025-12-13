class Solution {
public:
    static const int MOD=1e9+7;

    long long func(long long n){
        return n*(n-1)/2;
    }

    int countTrapezoids(vector<vector<int>>& points) {
        map<int,int> mp;
        for(auto &it:points){
            mp[it[1]]++;
        }

        long long sum=0,sumSq=0;
        for(auto &it : mp){
            int cnt=it.second;
            if(cnt>1){
                long long val=func(cnt)%MOD;   
                sum=(sum+val)%MOD;
                sumSq=(sumSq+val*val)%MOD;
            }
        }

        long long ans=(sum*sum)%MOD;
        ans=(ans-sumSq+MOD)%MOD;       
        long long inv2=(MOD+1)/2;
        ans=(ans*inv2)%MOD;

        return ans;
    }
};
