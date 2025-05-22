class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<vector<int>>arr(n);
        for(auto &it:queries)
            arr[it[0]].push_back(it[1]);
        priority_queue<int>pq;
        vector<int>b(n+1);
        int x=0,ans=queries.size();
        for(int i=0;i<n;i++)
        {
            x+=b[i];
            for(auto it:arr[i]) pq.push(it);
            while(x<nums[i] && !pq.empty())
            {
                auto j=pq.top();
                pq.pop();
                if(j<i)   continue;
                x++;
                b[j+1]--;
                ans--;
            }
            if(x<nums[i])   return -1;
        }
        return ans;
    }
};