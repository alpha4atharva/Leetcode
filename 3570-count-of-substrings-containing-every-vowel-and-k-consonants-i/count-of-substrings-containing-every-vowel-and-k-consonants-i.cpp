class Solution {
public:
    int atmost(string word,int k){
        if(k<0) return 0;

        unordered_map<char,int> mp;
        int vowel=0,tvowel=0,i=0,j=0,ans=0;
        int n=word.size();
        while(j<n){
            char c=word[j];
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
                tvowel++;
                if(mp.find(c)!=mp.end()){
                    if(mp[c]<i) vowel++;
                    mp[c]=j;
                }
                else{
                    mp[c]=j;
                    vowel++;
                }
            }
            while((j-i+1-tvowel)>k){
                char s=word[i];
                if(s=='a' || s=='e' || s=='i' || s=='o' || s=='u'){
                    if(mp[s]==i) vowel--;
                    tvowel--;
                }
                i++;
            }

            if(vowel==5){
                int x=min({mp['a'],mp['e'],mp['i'],mp['o'],mp['u']});
                ans+=(x-i+1);
            }
            j++;
        }

        return ans;
    }

    int countOfSubstrings(string word, int k) {
        return atmost(word,k)-atmost(word,k-1);
    }
};