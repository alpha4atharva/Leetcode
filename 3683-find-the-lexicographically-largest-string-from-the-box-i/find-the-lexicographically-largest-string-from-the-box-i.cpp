class Solution {
public:
    string answerString(string w, int k) {
        int n = w.size();
        char maxChar = *max_element(w.begin(), w.end());
        int maxlen = n - k + 1;
        if (k == 1){
            return w;
        }
        vector<int> pos;
        for (int i = 0; i < n; ++i) {
            if (w[i] == maxChar) pos.push_back(i);
        }
        
        vector<string> parts;
        for (int i = 0; i < pos.size(); i++) {
            int p = pos[i];
            int r = k - p - 1;
            if(r <= 0){
                r = 0;
            }
            // cout << r;
            int end = min(n - p - r,maxlen);
            // cout << " " << end << endl;
            parts.push_back(w.substr(p, end));
        }
        return *max_element(parts.begin(), parts.end());
    }
};