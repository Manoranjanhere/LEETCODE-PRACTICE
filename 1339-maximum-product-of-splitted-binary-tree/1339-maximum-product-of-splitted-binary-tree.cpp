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
    int maxProduct(TreeNode* root) {
        TreeNode *temp = root;
        maketree(temp);
        int total = root->val;
        long long max_sum =0;
        findmax(max_sum,total,root->left);
        findmax(max_sum,total,root->right);
        return max_sum%1000000007;
    }
    void findmax(long long& max_sum,int total, TreeNode* root)
    {
        if(!root)return;
        long long st = 1LL*(total-root->val)*root->val;
        max_sum= max(max_sum,st);
        findmax(max_sum,total,root->left);
        findmax(max_sum,total,root->right);
    }
    long long maketree(TreeNode* root)
    {
        if(!root)return 0;
        long long leftsum=maketree(root->left);
        long long rightsum=maketree(root->right);
        root->val+=leftsum+rightsum;
        return root->val;
    }
};