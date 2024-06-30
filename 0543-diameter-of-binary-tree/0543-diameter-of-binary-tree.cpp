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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int dia=0;
        height(root,dia);
        return dia;
    }
        int height(TreeNode* node, int& diameter) {
            if(!node)
            {
                return 0;
            }
        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);
        diameter= max(diameter,lh+rh);
        return 1+max(lh,rh);
        }
};