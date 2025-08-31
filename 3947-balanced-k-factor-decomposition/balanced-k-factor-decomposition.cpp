class Solution {
public:
    vector<int> ans;
    int mini=INT_MAX;
    void solve(int n, int k, int idx, vector<int>& inc, vector<int>& div) {
        if(n==1 && inc.size()==k){
            int c=inc[0]-inc.back();
            if(c<mini){
                mini=c;
                ans=inc;
            }
            return;
        }
        if(idx>=div.size() || inc.size()>k) return;

        // not take
        solve(n, k, idx+1, inc, div);

        // take
        if(n%div[idx]==0){
            inc.push_back(div[idx]);
            solve(n/div[idx], k, idx, inc, div);
            inc.pop_back();
        }
    }

    vector<int> minDifference(int n, int k) {
        vector<int> div;
        for(int i=1; i<=sqrt(n); ++i){
            if(n%i==0){
                div.push_back(i);
                if(i != n/i) div.push_back(n/i);
            }
        }

        sort(div.rbegin(), div.rend());
        vector<int> inc;
        solve(n, k, 0, inc, div);
        return ans;
    }
};
