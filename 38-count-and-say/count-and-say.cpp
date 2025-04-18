class Solution {
public:
    string func(string str){
        string ans="";
        char curr=str[0];
        int count=1;
        for(int i=1;i<str.length();i++){
            if(str[i]==str[i-1]){
                count++;
            }
            else{
                ans+=to_string(count);
                ans+=str[i-1];
                count=1;
            }
        }
        ans+=to_string(count);
        ans+=str.back();

        return ans;
    }

    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        string s=countAndSay(n-1);
        return func(s);
    }
};