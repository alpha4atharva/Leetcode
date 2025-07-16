class Solution {
public:
    bool isValid(string word) {
        int n=word.length();
        if(n<3) return false;

        bool v=false,c=false,f=true;
        for(int i=0;i<n;i++){
            if((word[i]>='a' && word[i]<='z') || (word[i]>='A' && word[i]<='Z')){
                if(word[i]=='a' || word[i]=='e' || word[i]=='i' || word[i]=='o' || word[i]=='u' || word[i]=='A' || word[i]=='E' || word[i]=='I' || word[i]=='O' || word[i]=='U'){
                    v=true;
                }
                else c=true;
            }
            else if(word[i]<'0' || word[i]>'9') f=false;
        }

        return c&&v&&f;
    }
};