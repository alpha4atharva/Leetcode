class Solution {
public:
    int getPri(const string &s) {
        if (s == "electronics") return 1;
        if (s == "grocery")     return 2;
        if (s == "pharmacy")    return 3;
        // restaurant
        return 4;
    }

    bool isAlnum(const string &s) {
        if (s.empty()) return false;
        for (unsigned char c : s) {
            if (!std::isalnum(c) && c != '_') return false; 
        }
        return true;
    }

    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& bl,
                                   vector<bool>& isAct) {
        int n = code.size();
        struct Node {
            string code;
            int pri;
        };
        vector<Node> valid;
        valid.reserve(n);

        for (int i = 0; i < n; ++i) {
            if (!isAct[i]) continue;
            const string &b = bl[i];
            if (b != "electronics" && b != "grocery" &&
                b != "pharmacy"    && b != "restaurant") continue;
            if (!isAlnum(code[i])) continue;
            valid.push_back({code[i], getPri(b)});
        }

        sort(valid.begin(), valid.end(),
             [](const Node &x, const Node &y) {
                 if (x.pri != y.pri) return x.pri < y.pri;
                 return x.code < y.code;
             });

        vector<string> ans;
        ans.reserve(valid.size());
        for (auto &v : valid) ans.push_back(v.code);
        return ans;
    }
};
