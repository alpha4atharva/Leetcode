class Solution {
public:
    int bs(vector<int>&arr,long long target,int low,int high) {
        int result=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]>=target){
                result=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return result;
    }
    
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>ans;
        int n=potions.size();
        sort(potions.begin(),potions.end());
        for(int i=0;i<spells.size();i++)
        {
            long long a=(success+spells[i]-1)/spells[i];
            int j=bs(potions,a,0,n-1);
            if(j==-1)   ans.push_back(0);
            else ans.push_back(n-j);
        }
        return ans;
    }
};