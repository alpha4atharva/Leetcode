#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
public:
    // We use a 3D vector to ensure it handles larger constraints without stack overflow
    // memo[row][col][cost]
    vector<vector<vector<int>>> memo;

    int recur(int i, int j, int cost, int k, vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // 1. Base Case: Exceeded cost limit (already spent too many moves on non-zero cells)
        if (cost > k) return -1e9;

        // 2. Base Case: Out of bounds
        if (i >= m || j >= n) return -1e9;

        // 3. Base Case: Reached the bottom-right cell
        if (i == m - 1 && j == n - 1) {
            return grid[i][j];
        }

        // 4. Memoization check
        if (memo[i][j][cost] != -1) {
            return memo[i][j][cost];
        }

        // 5. Recursive calls (Right and Down)
        int down = -1e9;
        if (i + 1 < m) {
            int nextCost = cost + (grid[i + 1][j] != 0 ? 1 : 0);
            down = recur(i + 1, j, nextCost, k, grid);
        }

        int right = -1e9;
        if (j + 1 < n) {
            int nextCost = cost + (grid[i][j + 1] != 0 ? 1 : 0);
            right = recur(i, j + 1, nextCost, k, grid);
        }

        // 6. Result is the current cell value + the best possible score from neighbors
        int res = max(down, right);
        
        // If both paths returned -1e9, this path is impossible
        if (res <= -1e8) return memo[i][j][cost] = -1e9;
        
        return memo[i][j][cost] = grid[i][j] + res;
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        // Dynamically resize memo to fit the exact problem constraints
        // Size is [m][n][k+1]
        memo.assign(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));

        int startCost = (grid[0][0] != 0 ? 1 : 0);
        int ans = recur(0, 0, startCost, k, grid);

        return (ans <= -1e8) ? -1 : ans;
    }
};