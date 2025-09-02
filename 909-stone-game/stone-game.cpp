// class Solution {
// public:
//     // vector<vector<int>> memo;
    
//     // int dfs(vector<int>& piles, int left, int right) {
//     //     if (left > right) return 0;
//     //     if (memo[left][right] != INT_MIN) return memo[left][right];
        
//     //     int leftPick = piles[left] - dfs(piles, left + 1, right);
//     //     int rightPick = piles[right] - dfs(piles, left, right - 1);
        
//     //     return memo[left][right] = max(leftPick, rightPick);
//     // }
    
//     bool stoneGame(vector<int>& piles) {
//         // int n = piles.size();
//         // memo.assign(n, vector<int>(n, INT_MIN));
//         // return dfs(piles, 0, n - 1) > 0;
//     }
// };
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base case: when i == j, only one pile, current player takes it
        for (int i = 0; i < n; i++) {
            dp[i][i] = piles[i];
        }

        // Fill dp for subarrays of increasing length
        for (int length = 2; length <= n; length++) {
            for (int i = 0; i <= n - length; i++) {
                int j = i + length - 1;
                int leftPick = piles[i] - dp[i + 1][j];
                int rightPick = piles[j] - dp[i][j - 1];
                dp[i][j] = max(leftPick, rightPick);
            }
        }

        return dp[0][n - 1] > 0;
    }
};
