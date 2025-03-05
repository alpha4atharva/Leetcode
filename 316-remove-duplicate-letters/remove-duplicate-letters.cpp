class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> last;
        for(int i=0;i<s.length();i++) last[s[i]]=i;

        stack<char> st;
        unordered_set<char> vis;
        for(int i=0;i<s.length();i++){
            if(vis.find(s[i])!=vis.end()) continue;
            while(!st.empty() && s[i]<st.top() && i<last[st.top()]){
                vis.erase(st.top());
                st.pop();
            }
            st.push(s[i]);
            vis.insert(s[i]);
        }

        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};