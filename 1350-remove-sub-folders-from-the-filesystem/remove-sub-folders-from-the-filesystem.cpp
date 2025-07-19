class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n=folder.size();
        if(n==0)    return {};
        sort(folder.begin(),folder.end());
        vector<string>ans;
        ans.push_back(folder[0]);
        string prev=folder[0];
        for(int i=1;i<n;i++)
        {
            if(folder[i].substr(0,prev.size())!=prev || folder[i][prev.size()]!='/')
            {
                ans.push_back(folder[i]);
                prev=folder[i];
            }
        }
        return ans;
    }
};