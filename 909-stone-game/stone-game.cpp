class Solution {
public:
    vector<vector<int>> memo;
    
    int dfs(vector<int>& piles, int left, int right) {
        if (left > right) return 0;
        if (memo[left][right] != INT_MIN) return memo[left][right];
        
        int leftPick = piles[left] - dfs(piles, left + 1, right);
        int rightPick = piles[right] - dfs(piles, left, right - 1);
        
        return memo[left][right] = max(leftPick, rightPick);
    }
    
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        memo.assign(n, vector<int>(n, INT_MIN));
        return dfs(piles, 0, n - 1) > 0;
    }
};
