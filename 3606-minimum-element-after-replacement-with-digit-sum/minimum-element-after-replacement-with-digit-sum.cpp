class Solution {
public:
    int calSum(int num){
        int sum=0;
        while(num>0){
            sum+=num%10;
            num/=10;
        }
        return sum;
    }

    int minElement(vector<int>& nums) {
        int mini=INT_MAX;
        for(auto num:nums){
            int sum=calSum(num);
            mini=min(mini,sum);
        }
        return mini;
    }
};