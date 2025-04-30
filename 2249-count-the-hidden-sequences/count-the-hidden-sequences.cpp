class Solution {
public:
    int numberOfArrays(vector<int>& diff, int lower, int upper) {
        int n=diff.size();
        vector<long long> prefix(n);
        prefix[0]=diff[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+diff[i];
        }

        long long mini=0,maxi=0;
        for(int i=0;i<n;i++){
            mini=min(mini,prefix[i]);
            maxi=max(maxi,prefix[i]);
        }
        //cout<<upper-(maxi+(lower-mini));
        return max(upper-lower-maxi+mini+1,0LL);
    }
};