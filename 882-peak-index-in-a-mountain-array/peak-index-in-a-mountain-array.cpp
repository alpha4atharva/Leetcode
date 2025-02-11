class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low=0,high=arr.size()-1;
        while(low<high){
            int mid=low+(high-low)/2;
            if(arr[mid-1]>arr[mid]){
                high=mid;
            }
            else low=mid+1;
        }
        // cout << low << " " << high;
        return  high-1;
    }
};