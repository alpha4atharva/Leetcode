class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }

    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int result = 0;
        sort(points.begin(),points.end(),cmp);

        // Count valid pairs
        for (int i = 0; i < n; ++i) {
            int maxY = INT_MIN;
            for (int j = i + 1; j < n; ++j) {
                // Check condition: y[i] >= y[j] and y[j] > maxY to count valid pairs
                if (points[i][1] >= points[j][1] && points[j][1] > maxY) {
                    ++result;
                    maxY = points[j][1];
                }
            }
        }

        return result;
    }
};