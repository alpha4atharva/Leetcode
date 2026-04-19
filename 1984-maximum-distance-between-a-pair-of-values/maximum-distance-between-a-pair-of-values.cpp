class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int max_dist=0;
        for(int i=0;i<nums1.size();i++){
            auto it=upper_bound(nums2.begin()+i,nums2.end(),nums1[i],greater<int>());
            int j=distance(nums2.begin(),it)-1;
            if(j>=i){
                max_dist=max(max_dist,j-i);
            }
        }
        return max_dist;
    }
};