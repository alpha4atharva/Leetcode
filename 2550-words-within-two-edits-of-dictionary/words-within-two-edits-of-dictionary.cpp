class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for(auto &q:queries){
            for(auto &d:dictionary){
                // if(q.length()!=d.length()) continue;
                int edits=0;
                for(int i=0;i<q.length();i++){
                    if(q[i]!=d[i]){
                        edits++;
                    }
                    if(edits>2) break;
                }
                if(edits<=2){
                    ans.push_back(q);
                    break;
                }
            }
        }
        
        return ans;
    }
};