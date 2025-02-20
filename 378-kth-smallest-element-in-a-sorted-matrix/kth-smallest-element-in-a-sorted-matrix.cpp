class Solution {
    int n,m;
public:
    int lessOrEqual(int x,vector<vector<int>> &a){
        int count=0,c=n-1;
        for(int i=0;i<m;i++){
            while(c>=0 && a[i][c]>x)    c--;
            count+=(c+1);
        }
        return count;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        n=matrix.size(),m=matrix[0].size();
        int low=matrix[0][0],high=matrix[n-1][m-1],ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(lessOrEqual(mid,matrix)>=k){
                ans=mid;
                high=mid-1;
            }
            else    low=mid+1;
        }
        return ans;
    }
};