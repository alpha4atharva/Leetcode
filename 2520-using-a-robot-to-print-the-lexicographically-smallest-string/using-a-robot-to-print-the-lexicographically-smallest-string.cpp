class Solution {
public:
    bool hasSmaller(int top,vector<int> &freq){
        for(int i=0;i<top;i++){
            if(freq[i]>0) return true;
        }
        return false;
    }

    string robotWithString(string s) {
        vector<int> freq(26,0);
        for(auto &c:s){
            freq[c-'a']++;
        }

        string ans="";
        stack<int> st;
        for(auto &c:s){
            st.push(c-'a');
            freq[c-'a']--;
            while(!st.empty() && !hasSmaller(st.top(),freq)){
                ans+=(char)(st.top()+'a');
                st.pop();
            }
        }
        return ans;
    }
};