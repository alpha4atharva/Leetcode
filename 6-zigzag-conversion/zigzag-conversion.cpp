class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.length();
        if(numRows==1 || numRows>=n)  return s;
        vector<string> str(numRows,"");
        bool goingDown=true;
        int r=-2;
        for(int i=0;i<n;i++){
            if(r<=-1)    goingDown=true,r+=2;
            if(r==numRows)  goingDown=false,r-=2;
            str[r]+=s[i];
            if(goingDown)   r++;
            else r--;
        }
        string ans="";
        for(auto &it : str){
            ans+=it;
        }
        return ans;
    }
};