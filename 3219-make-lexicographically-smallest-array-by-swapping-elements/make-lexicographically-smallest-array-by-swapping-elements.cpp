class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<int> a(nums.begin(),nums.end());
        sort(a.begin(),a.end());
        map<int,queue<int>> mp;    //level->element
        unordered_map<int,int> ump; // element->level

        int currlevel=0;
        mp[currlevel].push(a[0]);
        ump[a[0]]=currlevel;
        for(int i=1;i<n;i++){
            if(abs(a[i]-a[i-1])<=limit){
                mp[currlevel].push(a[i]);
            }
            else{
                currlevel++;
                mp[currlevel].push(a[i]);
            }
            ump[a[i]]=currlevel;
        }

        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int level=ump[nums[i]];
            ans[i]=mp[level].front();
            mp[level].pop();
        }

        return ans;
    }
};