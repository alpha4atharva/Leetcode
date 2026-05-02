class Solution {
    int memo[4][2][2]; // position, isLess, isDiff
    string s;

    int recur(int pos, bool isLess, bool isDiff) {
        if (pos == s.size()) {
            return isDiff; // Only count if it's "different" (contains 2, 5, 6, or 9)
        }
        if (memo[pos][isLess][isDiff] != -1) {
            return memo[pos][isLess][isDiff];
        }

        int limit = isLess ? 9 : s[pos] - '0';
        int count = 0;

        for (int d = 0; d <= limit; ++d) {
            // Skip invalid digits
            if (d == 3 || d == 4 || d == 7) continue;

            bool nextIsLess = isLess || (d < limit);
            bool nextIsDiff = isDiff || (d == 2 || d == 5 || d == 6 || d == 9);
            
            count += recur(pos + 1, nextIsLess, nextIsDiff);
        }

        return memo[pos][isLess][isDiff] = count;
    }

public:
    int rotatedDigits(int n) {
        s = to_string(n);
        memset(memo, -1, sizeof(memo));
        return recur(0, false, false);
    }
};