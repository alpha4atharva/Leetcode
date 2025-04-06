class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> deg(n,0),prev(n,-1);
        vector<vector<int>> adj(n);

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[j]%nums[i]==0){
                    deg[j]++;
                    adj[i].push_back(j);
                }
            }
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(deg[i]==0) q.push(i);
        }

        int maxi=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                deg[it]--;
                if(deg[it]==0){
                    q.push(it);
                    prev[it]=node;
                }
            }
            maxi=node;
        }

        vector<int> ans;
        for(int j=maxi;j!=-1;j=prev[j]){
            ans.push_back(nums[j]);
        }

        return ans;
    }
};