class Solution {
public:
    // To return sum of digits
    int digitsum(int n){
        int sum=0;
        while(n>0){
            sum+=(n%10);
            n/=10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>> mp; // DigitSum->index
        for(int i=0;i<n;i++){
            mp[digitsum(nums[i])].push_back(i);
        }

        priority_queue<int> pq; //For maximum two elements of any digitSum
        int ans=-1;
        for(auto &it : mp){
            if(it.second.size()<2)  continue;
            for(auto &i : it.second){
                pq.push(nums[i]);
            }
            if(pq.size()>=2){
                int a=pq.top();
                pq.pop();
                int b=pq.top();
                ans=max(ans,a+b);
            }
            pq=priority_queue<int>();
        }

        return ans;
    }
};