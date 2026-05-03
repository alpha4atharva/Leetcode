class Solution {
public:
    void rotate(string &s)
    {
        int n=s.length();
        char c=s[n-1];
        for(int i=n-1;i>0;i--)
            s[i]=s[i-1];
        s[0]=c;
    }
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length())   return false;
        for(int i=0;i<s.length();i++)
        {
            if(s==goal) return true;
            rotate(s);
        }
        return false;
    }
};