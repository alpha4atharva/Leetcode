class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0")  return "0";
        int n1=num1.size(),n2=num2.size();
        vector<char> ans(n1+n2,'0');
        int k=n1+n2-1;
        for(int i=n2-1;i>=0;i--){
            int x=k,carry=0,y=num2[i]-'0';
            for(int j=n1-1;j>=0;j--){
                int res=(ans[x]-'0')+(num1[j]-'0')*y;
                carry=res/10;
                res%=10;
                ans[x]=(res+'0');
                x--;
                if(carry) ans[x]+=carry;
            }
            k--;
        }

        string a="";
        bool flag=false;
        for(char c:ans){
            if(c!='0')  flag=true;
            if(flag) a+=c;
        }

        return a;
    }
};