class Solution {
public:
    int minFlips(string target) {
        int ans=0;
        for(int i=1;i<target.size();i++){
            if(target[i-1]!=target[i]) ans++;
        }

        if(target[0]=='0') return ans;
        ans++;
        return ans;
    }
};