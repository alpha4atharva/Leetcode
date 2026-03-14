class Solution {
public:
    bool check(long long mid,int height,vector<int>& times){
        long long removed=0;
        for(int t:times){
            long long k=mid/t;
            long long x=(-1+sqrt(1+8*k))/2;
            removed+=x;
            if(removed>=height) return true;
        }
        return false;
    }

    long long minNumberOfSeconds(int height, vector<int>& times) {
        long long l=0,r=1e18,ans=r;
        while(l<=r){
            long long mid=l+(r-l)/2;
            if(check(mid,height,times)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};