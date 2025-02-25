class Solution {
public:
    int MOD=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int odd=0,even=1,ans=0;
        long long sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum%2==0){               
                ans=(ans+odd)%MOD;
                even++;
            }
            else{                
                ans=(ans+even)%MOD;
                odd++;
            }
        }
        return ans;
    }
};