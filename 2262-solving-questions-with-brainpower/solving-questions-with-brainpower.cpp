class Solution {
public:
    long long rec(vector<vector<int>> &q, int idx, vector<long long> &memo) {
        if(idx>=q.size()) return 0;
        if(memo[idx]!=-1) return memo[idx];

        // Take the current question
        long long take=q[idx][0]+rec(q,idx+q[idx][1]+1,memo);
        // Skip the current question
        long long skip=rec(q,idx+1,memo);

        return memo[idx]=max(take,skip);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long> memo(n,-1);
        return rec(questions,0,memo);
    }
};
