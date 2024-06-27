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
    vector<int> postorderTraversal(TreeNode* root){
        stack<TreeNode*> st;
        st.push(root);
        vector<int> ans;
        if(root==NULL)
        {
            return ans;
        }
        while(!st.empty())
        {
            TreeNode* curr = st.top();
            st.pop();
            if(curr!=NULL)
            {
                ans.push_back(curr->val);
                if(curr->left)
                {
                    st.push(curr->left);
                }
                if(curr-> right)
                {
                    st.push(curr->right);
                }
            }
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};