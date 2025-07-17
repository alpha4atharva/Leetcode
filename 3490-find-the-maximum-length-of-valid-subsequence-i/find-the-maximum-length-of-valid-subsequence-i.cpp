class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        int a=0,b=0,c=1;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                a++;
            }
            else b++;
        }

        int f=nums[0]%2;
        for(int i=1;i<n;i++){
            if(nums[i]%2!=f){
                c++;
                f=nums[i]%2;
            }
        }

        return max(c,max(a,b));
    }
};