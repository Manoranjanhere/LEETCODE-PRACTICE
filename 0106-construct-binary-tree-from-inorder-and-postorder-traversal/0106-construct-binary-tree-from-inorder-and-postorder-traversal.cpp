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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        return build(mp,inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
    }
    TreeNode*build(unordered_map<int,int>& mp,vector<int>& inorder, vector<int>& postorder,int is,int ie,int ps,int pe)
    {
        if(ps>pe||is>ie)
        {
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[pe]);
        int index=mp[postorder[pe]];
        int left=index-is;
        root->left=build(mp,inorder,postorder,is,index-1,ps,ps+left-1);
        root->right=build(mp,inorder,postorder,index+1,ie,ps+left,pe-1);
        return root;
    }
};