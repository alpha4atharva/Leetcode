class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n=s.length(),m=part.size();
        // Using stack based approach
        // Using ans as stack
        string ans;
        char last=part.back();
        for(int i=0;i<n;i++){
            ans.push_back(s[i]);
            if(s[i]==last && ans.size()>=m){
                if(ans.substr(ans.size()-m)==part){
                    ans.erase(ans.size()-m);
                }
            }
        }

        return ans;
    }
};