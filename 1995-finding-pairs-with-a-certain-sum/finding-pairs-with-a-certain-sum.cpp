class FindSumPairs {
    unordered_map<int,int> mp1,mp2;
    vector<int>a;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        a=nums2;
        for(auto it:nums1) mp1[it]++;
        for(auto it:nums2) mp2[it]++;
    }
    
    void add(int index, int val) {
        mp2[a[index]]--;
        a[index]+=val;
        mp2[a[index]]++;
    }
    
    int count(int tot) {
        int ans=0;
        for(auto it:mp1){
            int num=it.first,c=it.second;
            if(mp2.find(tot-num)!=mp2.end()){
                ans+=(c*mp2[tot-num]);
            }
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */