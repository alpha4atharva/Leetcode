class Solution {
public:
    vector<long long> distance(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,vector<long long>>mp;
        vector<long long>ans(n);
        for(int i=0;i<n;i++)    mp[arr[i]].push_back(i);
        
        for(auto it:mp)
        {
            auto a=it.second;
            int len=a.size();
            if(len==1)  ans[a[0]]=0;
            else
            {
                vector<long long>left(len+1,0);  
                vector<long long>right(len+1,0);
                for(int i=0;i<len;i++)
                {
                    left[i+1]=left[i]+a[i];
                    right[len-i-1]=right[len-i]+a[len-i-1];
                }
                for(int i=0;i<len;i++)
                {
                    ans[a[i]]=(a[i]*i)-left[i]+right[i]-(a[i]*(len-i));
                }
            }
        }
        return ans;
    }
};