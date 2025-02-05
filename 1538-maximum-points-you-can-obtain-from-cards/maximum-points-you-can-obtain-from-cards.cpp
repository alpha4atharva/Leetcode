class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        int n=c.size();
        int sum=accumulate(c.begin(),c.end(),0);
        if(k==n)    return sum;
        int ans=1e9,currsum=0;
        for(int i=0;i<n-k;i++){
            currsum+=c[i];
        }
        ans=currsum;
        for(int i=n-k;i<n;i++){
            currsum-=c[i-n+k];
            currsum+=c[i];
            ans=min(ans,currsum);
        }

        return sum-ans;
    }
};