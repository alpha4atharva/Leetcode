class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1=0,sum2=0,c1=0,c2=0;
        for(auto &it:nums1){
            sum1+=it;
            if(it==0) c1++;
        }
        for(auto &it:nums2){
            sum2+=it;
            if(it==0) c2++;
        }

        //case:no zeroes in both arrays
        if(c1==0 && c2==0){
            return sum1==sum2?sum1:-1;
        } //case:no zeroes in second array
        else if(c2==0){
            return sum1+c1>sum2?-1:sum2;
        } //case:no zeroes in first array
        else if(c1==0){
            return sum2+c2>sum1?-1:sum1;
        } //case:zeroes in both arrays
        return max(sum1+c1,sum2+c2);
    }
};