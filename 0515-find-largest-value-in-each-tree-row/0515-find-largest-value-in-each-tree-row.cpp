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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)return ans;
        queue<TreeNode*> q;
        q.push(root);
        ans.push_back(root->val);
        while(!q.empty())
        {
            int n = q.size();
            cout<<n;
            int m=INT_MIN;
            for(int i=0;i<n;i++)
            {
                cout<<"vh";
                auto top = q.front();
                q.pop();
                if(top->left)
                {
                    m=max(m,top->left->val);
                    q.push(top->left);
                }
                if(top->right)
                {
                    m=max(m,top->right->val);
                    q.push(top->right);
                }
            }
            if(!q.empty())
            {
                ans.push_back(m);
            }
        }
        return ans;
    }
};