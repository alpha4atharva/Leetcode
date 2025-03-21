class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n=recipes.size();
        unordered_set<string> st(supplies.begin(),supplies.end());
        unordered_map<string,vector<int>>adj;
        vector<int> deg(n,0);
        for(int i=0;i<n;i++){
            for(auto &s:ingredients[i]){
                if(!st.count(s)){
                    adj[s].push_back(i);
                    deg[i]++;
                }
            }
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(deg[i]==0) q.push(i);
        }

        vector<string> ans;
        while(!q.empty()){
            int i=q.front();
            q.pop();
            auto s=recipes[i];
            ans.push_back(s);
            for(auto j:adj[s]){
                deg[j]--;
                if(deg[j]==0) q.push(j);
            }
        }
        return ans;
    }
};