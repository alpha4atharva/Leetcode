class Solution {
public:
    int dfs(unordered_map<char,int> &mp){
        int count=0;
        for(auto &it : mp){
            if(it.second>0){
                it.second--;
                count+=1+dfs(mp);
                it.second++;
            }
        }
        return count;
    }

    int numTilePossibilities(string tiles) {
        unordered_map<char,int> mp;
        for(auto &c:tiles)  mp[c]++;

        return dfs(mp);
    }
};