class Solution {
public:
    string func(string str){
        string ans="";
        char curr=str[0];
        int i=0,count=0;
        while(i<str.length()){
            if(curr==str[i]){
                count++;
            }
            else{
                ans+=to_string(count);
                ans+=str[i-1];
                curr=str[i];
                count=1;
            }
            i++;
        }
        ans+=to_string(count);
        ans+=str[i-1];

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