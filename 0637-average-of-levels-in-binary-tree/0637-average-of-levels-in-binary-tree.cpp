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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if(root==NULL)
        {
            return ans;
        }
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            int n = que.size();
            vector<int> v;
            double sum=0;
            for(int i=0;i<n;i++)
            {
                TreeNode* curr= que.front();
                sum+=curr->val;
                que.pop();
                if(curr->left)
                {
                    que.push(curr->left);

                }
                if(curr->right)
                {
                    que.push(curr->right);
                }
            }
            ans.push_back(sum/n);
             
        }
        return ans;
    }
};