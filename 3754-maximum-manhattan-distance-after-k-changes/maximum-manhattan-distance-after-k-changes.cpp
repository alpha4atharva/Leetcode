class Solution {
public:
    int maxDistance(string s, int k) {
        int ans=0;
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
            int diff=abs(mp['N']-mp['S'])+abs(mp['E']-mp['W']);
            ans=max(ans,diff+min(2*k,i+1-diff));
        }

        return ans;
    }
};