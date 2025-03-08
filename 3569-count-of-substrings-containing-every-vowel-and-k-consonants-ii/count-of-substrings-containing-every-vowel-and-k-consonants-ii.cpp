class Solution {
public:
    bool isVowel(char c){
        string str="aeiou";
        if(str.find(c)!=string::npos) return true;
        return false;
    }

    long long atmost(string word,int k){
        if(k<0) return 0;
        unordered_map<char,int> mp;
        int vowel=0,tvowel=0,i=0,j=0;
        long long ans=0;
        int n=word.length();
        while(j<n){
            if(isVowel(word[j])){
                tvowel++;
                if(mp.find(word[j])!=mp.end()){
                    if(mp[word[j]]<i) vowel++;
                    mp[word[j]]=j;
                }
                else{
                    mp[word[j]]=j;
                    vowel++;
                }
            }

            while((j-i+1-tvowel)>k){
                if(isVowel(word[i])){
                    if(mp[word[i]]==i) vowel--;
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

    long long countOfSubstrings(string word, int k) {
        return atmost(word,k)-atmost(word,k-1);
    }
};