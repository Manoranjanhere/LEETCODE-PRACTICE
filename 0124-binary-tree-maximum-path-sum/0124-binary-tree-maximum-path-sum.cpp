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
    int maxx=INT_MIN;
    int maxPathSum(TreeNode* root) {
        maxPathSumm(root);
        return maxx;
    }
    int maxPathSumm(TreeNode* root) {
        if(root==NULL)return 0;
        int left = max(0,maxPathSumm(root->right));
        int right = max(0,maxPathSumm(root->left));
        maxx=max(maxx,root->val+left+right);
        return root->val+max(left,right);
    }
};