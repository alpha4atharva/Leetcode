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
    unordered_map<int,int> mp;
    TreeNode* build(int preStart,int preEnd,int postStart,vector<int> &preorder){
        if(preStart>preEnd) return NULL;
        if(preStart==preEnd) return new TreeNode(preorder[preStart]);

        int leftSubtreeRoot=preorder[preStart+1];
        int leftSubtreeSize=mp[leftSubtreeRoot]-postStart+1;

        TreeNode *root=new TreeNode(preorder[preStart]);
        root->left=build(preStart+1,preStart+leftSubtreeSize,postStart,preorder);
        root->right=build(preStart+leftSubtreeSize+1,preEnd,postStart+leftSubtreeSize,preorder);

        return root;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        for(int i=0;i<postorder.size();i++) mp[postorder[i]]=i;
        return build(0,preorder.size()-1,0,preorder);       
    }
};