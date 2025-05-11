class Solution {
public:
    bool check(vector<long long> &a){
        long long tsum=accumulate(a.begin(),a.end(),0LL);
        long long sum=0;
        for(int i=0;i<a.size()-1;i++){
            tsum-=a[i];
            sum+=a[i];
            if(tsum==sum) return true;
        }
        return false;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<long long> colsum(m,0),rowsum(n,0);
        for(int i=0;i<n;i++){
            long long sum=0;
            for(int j=0;j<m;j++){
                sum+=grid[i][j];
            }
            rowsum[i]=sum;
        }

        if(check(rowsum)) return true;

        for(int i=0;i<m;i++){
            long long sum=0;
            for(int j=0;j<n;j++){
                sum+=grid[j][i];
            }
            colsum[i]=sum;
        }

        if(check(colsum)) return true;

        return false;
    }
};