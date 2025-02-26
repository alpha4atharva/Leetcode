class Solution {
public:
    int kadanePositive(vector<int> &a){
        int n=a.size();
        int maxsum=0,currsum=0;
        for(int i=0;i<n;i++){
            currsum+=a[i];
            if(currsum<0)   currsum=0;
            maxsum=max(currsum,maxsum);
        }
        return maxsum;
    }
    
    int kadaneNegative(vector<int> &a){
        int n=a.size();
        int minsum=0,currsum=0;
        for(int i=0;i<n;i++){
            currsum+=a[i];
            if(currsum>0)   currsum=0;
            minsum=min(currsum,minsum);
        }
        return minsum;
    }

    int maxAbsoluteSum(vector<int>& nums) {
        return max(kadanePositive(nums),abs(kadaneNegative(nums)));
    }
};