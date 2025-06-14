class Solution {
public:
    int minMaxDifference(int num) {
        string s=to_string(num);
        char x='.';
        for(auto c:s){
            if(c!='9'){
                x=c;
                break;
            }
        }
        
        if(x=='.') return num;
        string s1="",s2="";
        for(auto &c:s){
            if(c==x){
                s1+='9';
            }
            else{
                s1+=c;
            }
            if(c==s[0]){
                s2+='0';
            }
            else{
                s2+=c;
            }
        }

        int a=stoi(s1),b=stoi(s2);
        return a-b;
    }
};