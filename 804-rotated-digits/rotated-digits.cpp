class Solution {
public: 
    string s;
    int memo[4][2][2];
    int recur(int pos,bool isLess,bool isRot){
        if(pos==s.size()){
            return isRot;
        }

        if(memo[pos][isLess][isRot]!=-1) return memo[pos][isLess][isRot];

        int limit=isLess?9:s[pos]-'0';
        int count=0;
        for(int i=0;i<=limit;i++){
            if(i==3 || i==4 || i==7) continue;
            bool nxtLess=isLess||(i<limit);
            bool nxtRot=isRot||(i==2 || i==5 || i==6 || i==9);
            count+=recur(pos+1,nxtLess,nxtRot);
        }
        return memo[pos][isLess][isRot]=count;
    }

    int rotatedDigits(int n) {
        s=to_string(n);
        memset(memo,-1,sizeof(memo));
        return recur(0,false,false);
    }
};