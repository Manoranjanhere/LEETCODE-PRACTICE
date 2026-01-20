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
    unordered_map<int,int> mp;
    int ind=0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i=0;i<n;i++)
        {
            mp[inorder[i]]=i;
        }
        return build (preorder,0,n-1);
    }
    TreeNode* build(vector<int>& preorder,int l,int r)
    {
        if(l>r)return NULL;
        int rootval= preorder[ind++];
        TreeNode* root= new TreeNode(rootval);
        int mid=mp[rootval];
        root->left=build(preorder,l,mid-1);
        root->right=build(preorder,mid+1,r);
        return root;
    }
};