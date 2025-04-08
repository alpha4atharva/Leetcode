class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans=0;
        while(true){
            unordered_set<int> st(nums.begin(), nums.end());
            if(st.size()==nums.size())  break;
            
            nums.erase(nums.begin(),nums.begin()+min(3,(int)nums.size()));
            ans++;
        }
        
        return ans;
    }
};