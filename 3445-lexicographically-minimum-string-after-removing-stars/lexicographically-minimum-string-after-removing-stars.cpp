class Solution {
public:
    string clearStars(string s) {
        vector<stack<int>> freq(26);
        for(int i=0;i<s.size();i++){
            if(s[i]=='*'){
                for(int i=0;i<26;i++){
                    if(!freq[i].empty()){
                        s[freq[i].top()]='*';
                        freq[i].pop();
                        break;
                    }
                }
            }
            else{
                freq[s[i]-'a'].push(i);
            }
        }

        string ans="";
        for(auto &c:s){
            if(c!='*'){
                ans+=c;
            }
        }

        return ans;
    }
};