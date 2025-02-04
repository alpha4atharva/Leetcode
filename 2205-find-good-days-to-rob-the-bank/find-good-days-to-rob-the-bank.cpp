class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& sec, int time) {
        int n=sec.size();
        if(time==0){
            vector<int> ans(n);
            iota(ans.begin(),ans.end(),0);
            return ans;
        }
        // precomputation of days using prefix and suffix
        // prefix->number of days before ith day that is non-increasing
        // suffix->number of days after ith day that is non-decreasing
        vector<int> prefix(n,0),suffix(n,0);
        int count=1;
        prefix[0]=1;
        for(int i=1;i<n;i++){
            if(sec[i]<=sec[i-1])    count++;
            else    count=1;
            prefix[i]=count;
        }

        count=1,suffix[n-1]=1;
        for(int i=n-2;i>=0;i--){
            if(sec[i]<=sec[i+1])    count++;
            else    count=1;
            suffix[i]=count;
        }

        vector<int> ans;
        for(int i=0;i<n;i++){
            if(prefix[i]>time && suffix[i]>time){
                ans.push_back(i);
            }
        }

        return ans;
    }
};