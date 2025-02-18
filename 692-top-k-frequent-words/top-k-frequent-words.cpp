class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>mp;
        for(auto it:words)
            mp[it]++;
        priority_queue<pair<int,string>>pq;
        for(auto it:mp)
        {
            pq.push({it.second,it.first});
        }
        vector<string>ans;
        int count;
        while(!pq.empty() && k)
        {
            priority_queue<string,vector<string>,greater<>> temp;
            count=pq.top().first;
            while(k && !pq.empty() && pq.top().first==count)
            {
                temp.push(pq.top().second);
                pq.pop();
            }
            while(!temp.empty() && k)
            {
                ans.push_back(temp.top());
                temp.pop();
                k--;
            }
        }
        return ans;
    }
};