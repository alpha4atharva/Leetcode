class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n=s.length();
        int one=0,zero=0;
        for(auto &c:s){
            if(c=='0') zero++;
        }

        long long pow=1,val=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1'){
                if(pow+val>k){
                    break;
                }
                val+=pow;
                one++;
            }
            pow*=2;
            if(pow>k) break;
        }

        return zero+one;
    }
};