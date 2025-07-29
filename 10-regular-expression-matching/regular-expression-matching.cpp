class Solution {
public:
    bool rec(int i, int j, string &s, string &p) {
        //Base case:pattern end
        if(j==p.size()) return i==s.size();
        
        //Check if current characters match
        bool firstMatch=(i<s.size()) && (s[i]==p[j] || p[j]=='.');
        
        //If next character is '*', we have a "x*" pattern
        if(j+1<p.size() && p[j+1]=='*'){
            //Two choices:
            //1. Skip the "x*" pattern (zero matches)
            //2. Use the "x*" pattern if current chars match
            return rec(i,j+2,s,p) || (firstMatch && rec(i+1,j,s,p));
        } 
        else{
            //Regular character or '.' - must match exactly
            return firstMatch && rec(i+1,j+1,s,p);
        }
    }
    
    bool isMatch(string s, string p) {
        return rec(0,0,s,p);
    }
};
