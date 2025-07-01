class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size();
        vector<pair<char,int>>groups;
        for (int i = 0; i < n;) {
            char currentChar=word[i];
            int count=0;
            while (i<n && word[i]==currentChar) {
                count++;
                i++;
            }
            groups.push_back({currentChar,count});
        }
        
        int totalWays=1;
        for (auto [ch,count] : groups) {
            if(count>1) {
                totalWays+=count-1;
            }
        }   
        return totalWays;
    }
};