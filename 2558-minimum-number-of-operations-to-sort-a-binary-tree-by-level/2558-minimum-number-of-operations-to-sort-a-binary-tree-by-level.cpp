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
    int minimumOperations(TreeNode* root) 
    {
        queue<TreeNode*>q;
        q.push(root);
        int mis=0;
        while(!q.empty())
        {
            int n = q.size();
            vector<int> sortedvector;
            for(int i=0;i<n;i++)
            {
                auto curr = q.front();
                q.pop();
                if(curr->left)
                {
                    sortedvector.push_back(curr->left->val);
                    q.push(curr->left);
                }
                if(curr->right)
                {
                    sortedvector.push_back(curr->right->val);
                    q.push(curr->right);
                }
            }
            int vecsize = sortedvector.size();
            vector<int> sorted=sortedvector;
            sort(sorted.begin(),sorted.end());
            map<int,int>mp;
            for(int i=0;i<vecsize;i++)
            {
                mp[sortedvector[i]]=i;
            }
            for(int i=0;i<vecsize;i++)
            {
                if(sorted[i]!=sortedvector[i])
                {
                    mis++;
                    int pos =mp[sorted[i]];
                    mp[sortedvector[i]]=pos;
                    mp[sorted[i]]=i;
                    swap(sortedvector[i],sortedvector[pos]);
                }
            }
        }
        return mis;
    }
};