class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        int maxi=INT_MIN,j=0;
        for(int i=0;i<n;i++){
            while(j<m && nums2[j]>=nums1[i]) j++;
            if(j-1>=i){
                maxi=max(maxi,(j-1)-i);
            }
        }

        return maxi==INT_MIN?0:maxi;
    }
};