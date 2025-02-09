class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        // Diagonal map
        unordered_map<int,vector<int>> dmap;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dmap[i-j].push_back(grid[i][j]);
            }
        }
        // Sorting all the diagonals
        for(auto &it : dmap){
            vector<int> &temp=it.second;
            if(it.first<0)    sort(temp.rbegin(),temp.rend());
            else    sort(temp.begin(),temp.end());
        }
        // Updating values in grid
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                grid[i][j]=dmap[i-j].back();
                dmap[i-j].pop_back();
            }
        }

        return grid;
    }
};