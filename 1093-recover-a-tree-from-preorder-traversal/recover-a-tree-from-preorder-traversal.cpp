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
    int number(string s,int &idx){
        int ans=0;
        while(idx<s.length() && s[idx]>='0' && s[idx]<='9'){
            ans=ans*10+(s[idx]-'0');
            idx++;
        }
        return ans;
    }

    TreeNode* recoverFromPreorder(string s) {
        TreeNode* root=new TreeNode();
        int i=0,n=s.length();
        int v=number(s,i);
        root->val=v;
        stack<TreeNode*> st;
        st.push(root);
        while(i<n){
            int count=0;
            while(s[i]=='-')    count++,i++;
            while(st.size()>count)  st.pop();
            TreeNode *node=st.top();
            if(!node->left){
                node->left=new TreeNode();
                int v=number(s,i);
                node->left->val=v;
                st.push(node->left);
            }
            else{
                node->right=new TreeNode();
                int v=number(s,i);
                node->right->val=v;
                st.push(node->right);
            }
        }
        return root;
    }
};