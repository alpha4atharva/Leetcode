class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int,vector<int>> mp;
        int n=nums.size(); 
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        
        vector<int> ans;
        for(auto it:queries){
            int a=nums[it];
            auto& indices=mp[a];
            
            if(indices.size()==1){
                ans.push_back(-1);
                continue;
            }
            
            auto pos_itr=lower_bound(indices.begin(),indices.end(),it);
            int pos=distance(indices.begin(),pos_itr);
            // cout<<pos;
            int m=indices.size();
            int left_val=indices[(pos-1+m)%m];
            int right_val=indices[(pos+1)%m];
            int dist_left=min(abs(it-left_val),n-abs(it-left_val));
            int dist_right=min(abs(it-right_val),n-abs(it-right_val));  
            ans.push_back(min(dist_left,dist_right));
        }
        return ans;
    }
};