class Solution {
public:
    bool rec(int i, int j, string &s, string &p, vector<vector<int>> &memo) {
        //Base case:pattern end
        if(j==p.size()) return i==s.size();

        if(memo[i][j]!=-1) return memo[i][j];
        
        //Check if current characters match
        bool firstMatch=(i<s.size()) && (s[i]==p[j] || p[j]=='.');
        
        //If next character is '*', we have a "x*" pattern
        if(j+1<p.size() && p[j+1]=='*'){
            //Two choices:
            //1. Skip the "x*" pattern (zero matches)
            //2. Use the "x*" pattern if current chars match
            return memo[i][j]=rec(i,j+2,s,p,memo) || (firstMatch && rec(i+1,j,s,p,memo));
        } 
        else{
            //Regular character or '.' - must match exactly
            return memo[i][j]=firstMatch && rec(i+1,j+1,s,p,memo);
        }
    }
    
    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        vector<vector<int>> memo(n+1,vector<int>(m+1,-1));
        return rec(0,0,s,p,memo);
    }
};
