class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int start = 0, end = m - 1;

        //step1- find the row consisting of peak element
        while (start < end) {
            int mid = (start + end) / 2;
            int max_col = 0;
            for (int j = 1; j < n; j++) {
                if (mat[mid][j] > mat[mid][max_col]) {
                    max_col = j;
                }
            }

            if (mat[mid][max_col] < mat[mid + 1][max_col]) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }

        //step2-find max in the final row
        int max_col = 0;
        for (int j = 1; j < n; j++) {
            if (mat[start][j] > mat[start][max_col]) {
                max_col = j;
            }
        }

        return {start, max_col};
    }
};
