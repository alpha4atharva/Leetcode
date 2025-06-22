class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        for(int i=0;i<s.length()%k;i++){
            s+=fill;
        }
        for(int i=0;i<s.length();i+=k){
            string temp="";
            for(int j=i;j<i+k;j++){
                temp+=s[j];
            }
            ans.push_back(temp);
        }

        return ans;
    }
};