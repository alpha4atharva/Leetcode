class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        int ans=0,i=0,j=0;
        unordered_map<char,int> mp;
        // while(i<n){
        //     mp[s[i]]++;
        //     while(mp.size()==3){
        //         mp[s[j]]--;
        //         if(mp[s[j]]==0) mp.erase(s[j]);
        //         j++;
        //     }
        //     ans+=j;
        //     i++;
        // }

        for(i=0;i<n;i++){
            mp[s[i]]=i+1;
            ans+=min({mp['a'],mp['b'],mp['c']});
        }
        return ans;
    }
};