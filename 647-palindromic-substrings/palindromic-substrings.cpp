class Solution {
public:
    int palindromeCount(string &s,int i,int j){
        int count=0;
        while(i>=0 && j<s.length() && s[i]==s[j]){
            i--,j++,count++;
        }
        return count;
    }

    int countSubstrings(string s) {
        int ans=0,n=s.length();
        for(int i=0;i<n;i++){
            int even=palindromeCount(s,i,i+1);
            int odd=palindromeCount(s,i,i);
            ans+=even+odd;
        }
        return ans;
    }
};

// class Solution {
// public:
//     bool isPalindrome(string &s,int i,int j){
//         while(i<j){
//             if(s[i]!=s[j]) return false;
//             i++,j--;
//         }
//         return true;
//     }
//     int countSubstrings(string s) {
//         int ans=0,n=s.length();
//         for(int i=0;i<n;i++){
//             for(int j=i;j<n;j++){
//                 if(isPalindrome(s,i,j)) ans++;
//             }
//         }
//         return ans;
//     }
// };