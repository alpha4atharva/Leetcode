class Solution {
public:
    string revinvert(string s)
    {
        string temp="";
        for(auto c:s)
        {
            if(c=='1')  temp+='0';
            else    temp+='1';
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
    string func(int i)
    {
        if(i==1)
            return "0";
        string prev=func(i-1);
        return prev+"1"+revinvert(prev);
    }
    char findKthBit(int n, int k) {
        string s=func(n);
        cout<<s;
        return s[k-1];
    }
};