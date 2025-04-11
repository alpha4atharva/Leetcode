class Solution {
public:
    bool check(string &s){
        int n=s.length();
        int sum1=0,sum2=0;
        for(int i=0;i<n/2;i++){
            sum1+=(s[i]-'0');
        }
        for(int i=n-1;i>=n/2;i--){
            sum2+=(s[i]-'0');
        }

        return sum1==sum2;
    }

    int countSymmetricIntegers(int low, int high) {
        int ans=0;
        for(int i=low;i<=high;i++){
            string s=to_string(i);
            if(s.length()%2==1) continue;
            if(check(s)) ans++;
        }
        return ans;
    }
};