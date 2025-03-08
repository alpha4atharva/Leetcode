class Solution {
public:
    bool isVowel(char c){
        string str="aeiou";
        if(str.find(c)!=string::npos) return true;
        return false;
    }

    // long long atmost(string word,int k){
    //     if(k<0) return 0;
    //     unordered_map<char,int> mp;
    //     int vowel=0,tvowel=0,i=0,j=0;
    //     long long ans=0;
    //     int n=word.length();
    //     while(j<n){
    //         if(isVowel(word[j])){
    //             tvowel++;
    //             if(mp.find(word[j])!=mp.end()){
    //                 if(mp[word[j]]<i) vowel++;
    //                 mp[word[j]]=j;
    //             }
    //             else{
    //                 mp[word[j]]=j;
    //                 vowel++;
    //             }
    //         }

    //         while((j-i+1-tvowel)>k){
    //             if(isVowel(word[i])){
    //                 if(mp[word[i]]==i) vowel--;
    //                 tvowel--;
    //             }
    //             i++;
    //         }

    //         if(vowel==5){
    //             int x=min({mp['a'],mp['e'],mp['i'],mp['o'],mp['u']});
    //             ans+=(x-i+1);
    //         }
    //         j++;
    //     }
    //     return ans;
    // }

    long long countOfSubstrings(string word, int k) {
        int n=word.length();
        unordered_map<char,int> vowels;
        int c=0;
        long long ans=0;
        
        vector<int> nextConsonant(n);
        int lastConsonant=n;
        for(int i=n-1;i>=0;i--){
            nextConsonant[i]=lastConsonant;
            if(!isVowel(word[i])) lastConsonant=i;
        }

        int l=0,r=0;
        while(r<n){
            if(isVowel(word[r])) vowels[word[r]]++;
            else c++;

            while(l<=r && c>k){
                if(isVowel(word[l])){
                    vowels[word[l]]--;
                    if(vowels[word[l]]==0) vowels.erase(word[l]);
                }
                else c--;
                l++;
            }

            while(l<r && vowels.size()==5 && c==k){
                ans+=(nextConsonant[r]-r);
                if(isVowel(word[l])){
                    vowels[word[l]]--;
                    if(vowels[word[l]]==0) vowels.erase(word[l]);
                }
                else c--;
                l++;
            }
            r++;
        }

        return ans;
    }
};