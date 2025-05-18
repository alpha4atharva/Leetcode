class Solution {
public:
    long long MOD=1e9+7;
    int lengthAfterTransformations(string s, int t) {
        int ans=0;
        int n=s.length();
        long long arr[26]={0};
        for(char c:s)
            arr[c-'a']++;
        while(t--)
        {
            int newans=0;
            for(int i=0;i<25;i++)
            {
                newans=(newans+arr[i])%MOD;
            }
            newans=((newans)%MOD+((arr[25])%MOD)*2)%MOD;
            long long a=arr[25];
            for(int i =25;i>0;i--)
            {
                arr[i]=arr[i-1];
            }
            arr[0]=a;
            arr[1]=(arr[1]+a)%MOD;
            ans=newans;
        }
        return ans%MOD;
    }
};