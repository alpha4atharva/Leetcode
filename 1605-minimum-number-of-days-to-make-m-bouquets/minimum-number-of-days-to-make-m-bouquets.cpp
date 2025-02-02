class Solution {
public:
    bool func(vector<int> &a,int mid,int &m,int &k){
        int x=0,c=0;
        int i=0,n=a.size();
        while(i<n){
            if(a[i]>mid){
                c=0;
            }
            else{
                c++;
            }
            if(c==k){
                x++;
                c=0;
            }
            i++;
        }
        if(x>=m)    return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        int ans=-1,low=0,high=*max_element(bloomDay.begin(),bloomDay.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            if(func(bloomDay,mid,m,k)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return ans;
    }
};