class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        stringstream str1(s1);
        stringstream str2(s2);
        vector<string> ans;
        unordered_map<string,int> mp;
        string word;
        while(str1>>word){
            mp[word]++;
        }
        while(str2>>word){
            mp[word]++;
        }

        for(auto it:mp){
            if(it.second==1) ans.push_back(it.first);
        }

        return ans;
    }
};