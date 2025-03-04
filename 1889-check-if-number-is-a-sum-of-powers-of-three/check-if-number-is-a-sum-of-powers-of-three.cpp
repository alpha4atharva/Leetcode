class Solution {
public:
    bool checkPowersOfThree(int n) {
        int a=pow(3,16);
        for(int i=16;i>=0;i--){
            if(n>=a)    n-=a;
            a/=3;
        }
        return n==0;
    }
};