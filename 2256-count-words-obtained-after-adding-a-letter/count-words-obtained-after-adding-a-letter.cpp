class Solution {
public:
    int wordCount(vector<string>& start, vector<string>& target) {
        set<vector<int>> s;
        for(int i=0;i<start.size();i++){
            vector<int> temp(26,0);
            for(auto c:start[i]){
                temp[c-'a']++;
            }
            s.insert(temp);
        }
        
        int ans=0;
        for(int i=0;i<target.size();i++){
            vector<int> temp(26,0);
            for(auto c:target[i]){
                temp[c-'a']++;
            }

            for(int j=0;j<26;j++){
                if(temp[j]==1){
                    temp[j]=0;
                    if(s.find(temp)!=s.end()){
                        ans++;
                        break;
                    }
                    temp[j]=1;
                }
            }
        }

        return ans;
    }
};