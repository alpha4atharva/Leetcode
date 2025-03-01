class Solution {
public:
    int countSubstrings(string s) {
        int ans=0,n=s.length();
        vector<vector<bool>>palindrome(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            palindrome[i][i]=true;
            ans++;
        }

        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                palindrome[i][i+1]=true;
                ans++;
            }
        }

        for(int len=3;len<=n;len++){
            for(int i=0;i<n-len+1;i++){
                if(s[i]==s[i+len-1] && palindrome[i+1][i+len-2]){
                    palindrome[i][i+len-1]=true;
                    ans++;
                }
            }
        }

        return ans;
    }
};

// class Solution {
// public:
//     int palindromeCount(string &s,int i,int j){
//         int count=0;
//         while(i>=0 && j<s.length() && s[i]==s[j]){
//             i--,j++,count++;
//         }
//         return count;
//     }

//     int countSubstrings(string s) {
//         int ans=0,n=s.length();
//         for(int i=0;i<n;i++){
//             int even=palindromeCount(s,i,i+1);
//             int odd=palindromeCount(s,i,i);
//             ans+=even+odd;
//         }
//         return ans;
//     }
// };

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