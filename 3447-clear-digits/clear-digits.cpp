class Solution {
public:
    string clearDigits(string s) {
        int n=s.length();
        string ans="";
        int count=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]>='0' && s[i]<='9')  count++;
            else{
                if(count>0) count--;
                else ans+=s[i];
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};