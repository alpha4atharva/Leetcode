class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>> a(nums.size());
        for(int i=0;i<nums.size();i++){
            a[i].first=nums[i];
            a[i].second=i;
        }
        sort(a.rbegin(),a.rend());
        vector<pair<int,int>> b(k);
        for(int i=0;i<k;i++){
            b[i].first=a[i].second;
            b[i].second=a[i].first;
        }
        sort(b.begin(),b.end());
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(b[i].second);
        }
        return ans;
    }
};