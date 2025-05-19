class Solution {
public:
    bool check(vector<int> &num){
        if(num[0]+num[1]<=num[2]) return false;
        return true;
    }

    string triangleType(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(!check(nums)) return "none";
        else if(nums[0]==nums[1] && nums[1]==nums[2]) return "equilateral";
        else if(nums[0]==nums[1] || nums[1]==nums[2]) return "isosceles";
        else return "scalene";
    }
};