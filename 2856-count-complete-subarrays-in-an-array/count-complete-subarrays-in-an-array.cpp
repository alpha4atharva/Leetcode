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
            unordered_map<int,int> mp;
            for(int j=i;j<n;j++){
                mp[nums[j]]++;
                if(mp.size()==s){
                    count++;
                }
            }
        }
        return count;
    }
};