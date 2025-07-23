class Solution {
public:
    int maximumGain(string s, int x, int y) {
        // Prioritize the higher score pattern
        char c1 = 'a', c2 = 'b';
        if (y > x) {
            swap(x, y);
            swap(c1, c2); // Now we always remove c1c2 (higher value) first
        }

        // First pass: remove all c1c2
        int total = 0;
        string t; // Acts as a stack

        for (char ch : s) {
            if (!t.empty() && t.back() == c1 && ch == c2) {
                t.pop_back();
                total += x;
            } else {
                t.push_back(ch);
            }
        }

        // Second pass: remove all c2c1 (the other pattern) from the remaining string
        string u;
        for (char ch : t) {
            if (!u.empty() && u.back() == c2 && ch == c1) {
                u.pop_back();
                total += y;
            } else {
                u.push_back(ch);
            }
        }

        return total;
    }
};
