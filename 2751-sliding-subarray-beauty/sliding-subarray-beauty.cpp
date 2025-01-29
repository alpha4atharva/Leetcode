class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n=nums.size();
        multiset<int> st;
        for(int i=0;i<k-1;i++){
            if(nums[i]<0)   st.insert(nums[i]);
        }
        
        vector<int> ans;
        for(int i=k-1;i<n;i++){
            if(nums[i]<0)   st.insert(nums[i]);
            if(st.size()<x) ans.push_back(0);
            else{
                auto it=next(st.begin(),x-1);
                ans.push_back(*it);
            }
            auto it=st.find(nums[i-k+1]);
            if (it != st.end()) {
                st.erase(it); 
            }
        }

        return ans;
    }
};