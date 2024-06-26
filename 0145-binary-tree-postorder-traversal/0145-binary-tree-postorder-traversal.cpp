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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> a;
        inorderTraversall(root,a);
        return a;
    }
     void inorderTraversall(TreeNode* root,vector<int> &a) {
        if(root!=NULL)
        {
            inorderTraversall(root->left,a);
            inorderTraversall(root->right,a);
            a.push_back(root->val);
        }
        
    }
};