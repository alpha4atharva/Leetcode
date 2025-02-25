class Solution {
public:
    int MOD=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        int ans=0;
        vector<int> dp1(n,0),dp2(n,0);
        if(arr[0]%2==0) dp1[0]=1;
        else dp2[0]=1,ans++;
        for(int i=1;i<n;i++){
            if(arr[i]%2==0){
                dp1[i]=dp1[i-1]+1;
                dp2[i]=dp2[i-1];
            }
            else{
                dp2[i]=dp1[i-1]+1;
                dp1[i]=dp2[i-1];
            }
            ans=(ans+dp2[i])%MOD;
        }

        return ans;
    }
};