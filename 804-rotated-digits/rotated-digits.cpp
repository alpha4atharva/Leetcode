class Solution {
public: 
    string s;
    int recur(int pos,bool isLess,bool isRot){
        if(pos==s.size()){
            return isRot;
        }
        int limit=isLess?9:s[pos]-'0';
        int count=0;
        for(int i=0;i<=limit;i++){
            if(i==3 || i==4 || i==7) continue;
            bool nxtLess=isLess||(i<limit);
            bool nxtRot=isRot||(i==2 || i==5 || i==6 || i==9);
            count+=recur(pos+1,nxtLess,nxtRot);
        }
        return count;
    }

    int rotatedDigits(int n) {
        s=to_string(n);
        return recur(0,false,false);
    }
};