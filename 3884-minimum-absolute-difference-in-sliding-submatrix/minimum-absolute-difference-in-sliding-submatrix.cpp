class Solution {
public:
    int calc(int i,int j,int k,vector<vector<int>> &grid){
        unordered_set<int> st;
        for(int a=i;a<i+k;a++){
            for(int b=j;b<j+k;b++) st.insert(grid[a][b]);
        }

        vector<int> arr;
        for(auto it:st) arr.push_back(it);
        
        int mindiff=INT_MAX;
        sort(arr.begin(),arr.end());
        for(int a=1;a<arr.size();a++){
            mindiff=min(mindiff,abs(arr[a]-arr[a-1]));
        }
        return mindiff==INT_MAX?0:mindiff;
    }

    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> ans(n-k+1,vector<int>(m-k+1));
        for(int i=0;i<n-k+1;i++){
            for(int j=0;j<m-k+1;j++){
                int mindiff=calc(i,j,k,grid);
                ans[i][j]=mindiff;
            }
        }

        return ans;
    }
};