/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int,vector<int>> graph;
    void makeGraph(TreeNode* root){
        if(root==NULL) return;

        if(root->left){
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
            makeGraph(root->left);
        }

        if(root->right){
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
            makeGraph(root->right);
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        // converting binary tree into undirected graph
        // dfs
        makeGraph(root);

        // apply bfs from start node to find maximum minutes
        unordered_set<int> vis;
        queue<int> q;
        q.push(start);
        int ans=-1;
        vis.insert(start);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                int node=q.front();
                q.pop();
                for(auto it:graph[node]){
                    if(vis.find(it)==vis.end()){
                        vis.insert(it);
                        q.push(it);
                    }
                }
            }
            ans++;
        }

        return ans;
    }
};