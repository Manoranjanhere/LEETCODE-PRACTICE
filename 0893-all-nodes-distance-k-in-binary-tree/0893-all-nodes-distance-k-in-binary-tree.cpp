/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        parentfind(root,parent);
        vector<int> ans;
        unordered_map<TreeNode*,bool> level;
        queue<TreeNode*> q;
        q.push(target);
        int l=0;
        level[target]=true;
       
        while(!q.empty())
        {
                if(l++==k)
                {
                    break;
                }
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                 TreeNode* curr=q.front();
                q.pop();
                if(curr->left&&!level[curr->left])
                {
                    level[curr->left]=true;
                    q.push(curr->left);
                }
            if(curr->right&&!level[curr->right])
            {
                level[curr->right]=true;
                q.push(curr->right);
            }
            if(parent[curr]&&!level[parent[curr]])
            {
                level[parent[curr]]=true;
                q.push(parent[curr]);
            }
            }
    }
            while(!q.empty())
            {
                TreeNode* curr=q.front();
                q.pop();
                ans.push_back(curr->val);
            }
            return ans;
    }
    void parentfind(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent)
    {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr=q.front();
            q.pop();
            
                if(curr->left)
                {
                    parent[curr->left]=curr;
                    q.push(curr->left);
                }
                if(curr->right)
                {
                    parent[curr->right]=curr;
                    q.push(curr->right);
                }
        }
    }
};