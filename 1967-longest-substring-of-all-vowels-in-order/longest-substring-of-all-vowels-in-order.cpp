class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int n=word.size();
        int ans=0,i=0,j=0;
        while(i<n){
            if(word[i]=='a'){
                j=i;
                while(j<n && word[j]=='a') j++;
                bool f1=false;
                while(j<n && word[j]=='e') j++,f1=true;
                bool f2=false;
                while(j<n && word[j]=='i') j++,f2=true;
                bool f3=false;
                while(j<n && word[j]=='o') j++,f3=true;
                while(j<n && word[j]=='u'){
                    if(f1 && f2 && f3)  ans=max(ans,j-i+1);
                    j++;
                }
                i=j;
            }
            else i++;
        }

        return ans;
    }
};