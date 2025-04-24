class Solution {
private:
    int count=0;
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> st;
        for(auto it:nums) st.insert(it);
        int s=st.size();
        for(int i=0;i<n;i++){
            unordered_set<int> temp;
            for(int j=i;j<n;j++){
                temp.insert(nums[j]);
                if(temp.size()==s){
                    count++;
                }
            }
        }
        return count;
    }
};