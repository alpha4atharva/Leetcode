class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string ans="";
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            int x=strs[0].size();
            mini=min(x,mini);
        }

        string str=strs[0];
        for(int i=0;i<mini;i++){
            char c=str[i];
            bool flag=true;
            for(int j=1;j<n;j++){
                if(strs[j][i]!=c){
                    flag=false;
                    break;
                }
            }
            if(!flag)   break;
            ans+=c;
        }

        return ans;
    }
};