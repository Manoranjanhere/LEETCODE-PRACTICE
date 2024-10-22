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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> ans;
        queue<TreeNode*> qu;
        qu.push(root);
        solve(qu,ans);
        if (k > ans.size()) return -1;
        sort(ans.rbegin(),ans.rend());
        return ans[k-1];
    }
    void solve(queue<TreeNode*> qu,vector<long long>& ans)
    {
        while(!qu.empty())
        {
            int level = qu.size();
            long long sum=0;
            for(int i=0;i<level;i++)
            {
                TreeNode* store = qu.front();
                qu.pop();
                sum+=store->val;
                if(store->left)
                {
                    qu.push(store->left);
                }
                if(store->right)
                {
                    qu.push(store->right);
                }
            }
            ans.push_back(sum);
        }
    }
};