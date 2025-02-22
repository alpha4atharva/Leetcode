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
class FindElements {
    unordered_map<int,int> mp;
    void dfs(TreeNode* root){
        if(root==NULL)  return;
        int v=root->val;
        if(root->left){
            root->left->val=2*v+1;
            mp[2*v+1]++;
            dfs(root->left);
        }
        if(root->right){
            root->right->val=2*v+2;
            mp[2*v+2]++;
            dfs(root->right);
        }
    }
public:
    FindElements(TreeNode* root) {
        root->val=0;
        mp[0]++;
        dfs(root);
    }
    
    bool find(int target) {
        if(mp.find(target)!=mp.end())   return true;
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */