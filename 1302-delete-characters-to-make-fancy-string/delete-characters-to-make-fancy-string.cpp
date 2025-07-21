class Solution {
public:
    string makeFancyString(string s) {
        int count=0;
        string ans;
        for(int i=0;i<s.length();i++)
        {
            if(i>0 && s[i-1]==s[i])
            {
                count++;
                if(count<=2)
                    ans+=s[i];
            }
            else
            {
                count=1;
                ans+=s[i];
            }
        }
        return ans;
    }
};