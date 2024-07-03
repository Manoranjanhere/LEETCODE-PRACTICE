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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int maxWidth=0;
        while(!q.empty())
        {
            unsigned long long left = q.front().second;
            unsigned long long right = left;
             int sz = q.size();
            for (int i = 0; i < sz; ++i) 
            {
                TreeNode* node = q.front().first;
                unsigned long long index = q.front().second;
                q.pop();

                if (i == sz - 1) {
                    right = index;
                }

                if (node->left) q.push({node->left, 2 * index});
                if (node->right) q.push({node->right, 2 * index + 1});
            }
             maxWidth = max(maxWidth, int(right - left + 1));
        }
        return maxWidth;
    }
};