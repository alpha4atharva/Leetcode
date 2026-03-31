class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> freqodd(26,0),freqeven(26,0);
        for(int i=0;i<s1.length();i++){
            if(i%2==0){
                freqeven[s1[i]-'a']++;
            }
            else{
                freqodd[s1[i]-'a']++;
            }
        }
        for(int i=0;i<s2.length();i++){
            if(i%2==0){
                freqeven[s2[i]-'a']--;
            }
            else{
                freqodd[s2[i]-'a']--;
            }
        }

        for(int i=0;i<26;i++){
            if(freqodd[i]!=0 || freqeven[i]!=0) return false;
        }
        return true;
    }
};