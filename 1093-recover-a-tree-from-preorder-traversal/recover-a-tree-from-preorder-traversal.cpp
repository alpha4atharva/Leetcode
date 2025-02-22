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
    int number(string &s,int &idx){
        int ans=0;
        while(idx<s.length() && s[idx]>='0' && s[idx]<='9'){
            ans=ans*10+(s[idx]-'0');
            idx++;
        }
        return ans;
    }

    TreeNode* recoverFromPreorder(string s) {
        int i=0,n=s.length();
        int v=number(s,i);
        TreeNode* root=new TreeNode(v);
        stack<TreeNode*> st;
        st.push(root);
        while(i<n){
            int count=0;
            while(s[i]=='-')    count++,i++;
            while(st.size()>count)  st.pop();
            int v=number(s,i);
            TreeNode* node=new TreeNode(v);
            if(!st.top()->left) st.top()->left=node;
            else st.top()->right=node;
            st.push(node);
        }
        return root;
    }
};