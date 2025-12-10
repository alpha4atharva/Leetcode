class Solution {
public:
    int countOdds(int low, int high) {
        int n=high-low+1;
        if(n%2==0) return n/2;
        if(high%2==1) n++;
        if(low%2==1) n++;
        return n/2;
    }
};