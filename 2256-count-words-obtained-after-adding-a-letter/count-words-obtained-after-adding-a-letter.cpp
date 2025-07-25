class Solution {
public:
    int wordCount(vector<string>& start, vector<string>& target) {
        unordered_set<string> s;
        for(int i=0;i<start.size();i++){
            string str="00000000000000000000000000";
            for(auto c:start[i]){
                str[c-'a']++;
            }
            s.insert(str);
        }
        
        int ans=0;
        for(int i=0;i<target.size();i++){
            string str="00000000000000000000000000";
            for(auto c:target[i]){
                str[c-'a']++;
            }

            for(int j=0;j<26;j++){
                if(str[j]=='1'){
                    str[j]='0';
                    if(s.find(str)!=s.end()){
                        ans++;
                        break;
                    }
                    str[j]='1';
                }
            }
        }

        return ans;
    }
};