class Solution {
public:
    int maxDiff(int num) {
        string s=to_string(num);
        int n=s.length();
        char x='.';
        for(auto &c:s){
            if(c!='9'){
                x=c;
                break;
            }
        }

        if(x=='.'){
            string s1(n,'1');
            return stoi(s)-stoi(s1);
        }

        string s1="",s2="";
        for(auto &c:s){
            if(c==x){
                s1+='9';
            }
            else{
                s1+=c;
            }
        }

        char y='.';
        for(auto &c:s){
            if(c>'1'){
                y=c;
                break;
            }
        }

        if(y=='.'){
            return stoi(s1)-num;
        }

        for(auto &c:s){
            if(c==y){
                if(s[0]==y)
                    s2+='1';
                else
                    s2+='0';
            }
            else{
                s2+=c;
            }
        }

        cout<<s1<<" "<<s2;
        return stoi(s1)-stoi(s2);
    }
};