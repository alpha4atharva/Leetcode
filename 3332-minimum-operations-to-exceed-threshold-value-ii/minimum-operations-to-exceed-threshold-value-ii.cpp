class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<long long,vector<long long>,greater<>> pq;
        for(int i=0;i<n;i++){
            if(nums[i]<k)   pq.push(nums[i]);
        }

        int ans=0;
        while(pq.size()>=2){
            long long x=pq.top();
            pq.pop();
            long long y=pq.top();
            pq.pop();
            long long res=min(x,y)*2+max(x,y);
            if(res<k)   pq.push(res);
            ans++;
        }

        if(!pq.empty()) ans++;

        return ans;
    }
};