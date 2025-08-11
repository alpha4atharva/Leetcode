class Solution {
public:
    bool rec(int n){
        if(n==1) return true;
        if(n%2!=0) return false;
        return rec(n/2);
    }

    bool isPowerOfTwo(int n) {
        if(n==0) return false;
        return rec(n);
    }
};