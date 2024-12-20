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
    TreeNode* reverseOddLevels(TreeNode* root) {
        int c=0;
        queue<TreeNode*> q;
        q.push(root);
        int n =0;
        while(!q.empty())
        {
            c++;
            n =q.size();
            vector<int>store;
            for(int i=0;i<n;i++)
            {
                TreeNode *curr=q.front();
                q.pop();
                if(curr->left)
                {
                    if(c%2!=0)
                    {
                        store.push_back(curr->left->val);
                    }
                    q.push(curr->left);
                }
                if(curr->right)
                {
                    if(c%2!=0)
                    {
                        store.push_back(curr->right->val);
                    }
                    q.push(curr->right);
                }
            }
            if(c%2!=0)
            {
                int index=store.size()-1;
                n=q.size();
                for(int i=0;i<n;i++)
                {
                    TreeNode *curr = q.front();
                    q.pop();
                    curr->val=store[index--];
                    q.push(curr);
                }
            }
        }
        return root;
    }
};