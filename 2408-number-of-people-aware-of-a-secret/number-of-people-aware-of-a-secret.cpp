class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;
        queue<pair<int, int>> q; // {day learned, count of people}
        q.push({1, 1}); // day 1, 1 person learns the secret
        int day = 1;

        while (!q.empty() && day <= n) {
            int size = (int)q.size();
            int cnt = 0; // count of people who can share today

            for (int i = 0; i < size; ++i) {
                auto node = q.front();
                q.pop();
                int learnDay = node.first;
                int peopleCount = node.second;

                if (learnDay + forget > day) { // still remembering
                    if (learnDay + delay <= day) { // can share today
                        cnt = (cnt + peopleCount) % MOD;
                    }
                    q.push(node); // keep in queue to process future days
                }
            }

            if (cnt > 0) {
                q.push({day, cnt}); // new people learned the secret today
            }
            ++day;
        }

        int ans = 0;
        while (!q.empty()) {
            ans = (ans + q.front().second) % MOD;
            q.pop();
        }
        return ans;
    }
};
