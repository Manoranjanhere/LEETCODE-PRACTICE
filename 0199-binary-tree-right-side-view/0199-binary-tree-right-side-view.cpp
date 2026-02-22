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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> st;
        if(!root)return {};
        st.push(root);
        vector<int> ans;
        while(!st.empty())
        {
            int n = st.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* a = st.front();
                st.pop();
                if(i==n-1)ans.push_back(a->val);
                if(a->left)
                {
                    st.push(a->left);
                }
                if(a->right)
                {
                    st.push(a->right);
                }
            }
        }
        return ans;
    }
};