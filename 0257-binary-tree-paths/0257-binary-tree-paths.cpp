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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string st="";
        rec(root,ans,st);
        return ans;
    }
    void rec(TreeNode* root,vector<string> &ans,string st)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->left==NULL&&root->right==NULL)
        {
            ans.emplace_back(st+to_string(root->val));
            return;
        }
        rec(root->left,ans,st+to_string(root->val)+"->");
        rec(root->right,ans,st+to_string(root->val)+"->");
    }
};