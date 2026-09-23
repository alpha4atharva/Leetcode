class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int freq[10] = {0};
        for (int d : digits) freq[d]++;

        int ans = 0;
        for (int a = 1; a <= 9; a++) {           // first digit: nonzero
            if (!freq[a]) continue;
            for (int c = 0; c <= 8; c += 2) {    // last digit: even
                if (!freq[c]) continue;
                for (int b = 0; b <= 9; b++) {   // middle digit: any
                    if (!freq[b]) continue;

                    int need[10] = {0};
                    need[a]++; need[b]++; need[c]++;

                    bool ok = true;
                    for (int v = 0; v < 10 && ok; v++)
                        if (need[v] > freq[v]) ok = false;

                    if (ok) ans++;
                }
            }
        }
        return ans;
    }
};