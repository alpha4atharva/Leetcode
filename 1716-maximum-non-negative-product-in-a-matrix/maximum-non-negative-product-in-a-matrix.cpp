class Solution {
public:
    long long MOD = 1e9 + 7;

    void processPath(pair<long long,long long>& child,long long val,long long& cur_max,long long& cur_min){
        if(child.first!=LLONG_MIN){
            cur_max=max({cur_max,val*child.first,val*child.second});
            cur_min=min({cur_min,val*child.first,val*child.second});
        }
    }

    pair<long long,long long> recur(int i,int j,vector<vector<int>>&grid,vector<vector<pair<long long,long long>>>& memo){
        int m=grid.size(),n=grid[0].size();
        
        if(i>=m || j>=n) return {LLONG_MIN,LLONG_MAX};
        
        if(i==m-1 && j==n-1){
            return {grid[i][j],grid[i][j]};
        }
        
        if(memo[i][j].first!=LLONG_MIN){
            return memo[i][j];
        }
        
        auto down=recur(i+1,j,grid,memo);
        auto right=recur(i,j+1,grid,memo);
        
        long long cur_max=LLONG_MIN;
        long long cur_min=LLONG_MAX;
        long long val=grid[i][j];
        
        processPath(down,val,cur_max,cur_min);
        processPath(right,val,cur_max,cur_min);
        
        return memo[i][j]={cur_max,cur_min};
    }

    int maxProductPath(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();    
        vector<vector<pair<long long,long long>>>memo(m,vector<pair<long long,long long>>(n,{LLONG_MIN,LLONG_MAX}));   
        auto result=recur(0,0,grid,memo);    
        if(result.first<0) return -1;    
        return result.first%MOD;
    }
};