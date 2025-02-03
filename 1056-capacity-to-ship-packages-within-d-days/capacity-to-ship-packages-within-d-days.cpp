class Solution {
public:
    int func(vector<int> &a,int cap){
        int d=1,sum=0;
        for(int i=0;i<a.size();i++){
            if(sum+a[i]>cap){
                d++;
                sum=a[i];
            }
            else{
                sum+=a[i];
            }
        }
        return d;
    }
    int shipWithinDays(vector<int>& w, int days) {
        int low=*max_element(w.begin(),w.end());
        int high=accumulate(w.begin(),w.end(),0);
        int ans=low;
        while(low<=high){
            int mid=low+(high-low)/2;
            int d=func(w,mid);
            if(d<=days){
                ans=mid;
                high=mid-1;
            }
            else    low=mid+1;
        }

        return ans;
    }
};