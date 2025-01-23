class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<int> row(n,0),col(m,0);
        //count
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    row[i]++,col[j]++;
                }
            }
        }

        // answer
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] && (row[i]>1 || col[j]>1))    ans++;
            }
        }

        return ans;
    }
};