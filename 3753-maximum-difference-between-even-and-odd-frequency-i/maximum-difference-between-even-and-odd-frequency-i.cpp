class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26,0);
        for(auto c:s){
            freq[c-'a']++;
        }

        int maxi=INT_MIN,mini=INT_MAX;
        for(int i=0;i<26;i++){
            if(freq[i]%2) maxi=max(maxi,freq[i]);
            else if(freq[i]!=0) mini=min(mini,freq[i]);
        }
        return maxi-mini;
    }
};