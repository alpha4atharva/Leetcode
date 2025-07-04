class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n=shifts.size();
        shifts[n-1]=shifts[n-1]%26;
        for(int i=n-2;i>=0;i--){
            shifts[i]=(shifts[i]+shifts[i+1])%26;
        }

        for(int i=0;i<n;i++){
            if(shifts[i]+(s[i]-'a')>=26){
                s[i]-=(26-shifts[i]);
            }
            else s[i]+=shifts[i];
        }
        return s;
    }
};