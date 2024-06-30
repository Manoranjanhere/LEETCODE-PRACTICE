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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int ps=0;
        int pe=preorder.size()-1;
        int is=0;
        int ie = inorder.size()-1;
        TreeNode* ans;
        ans = build( preorder,inorder,ps,pe,is,ie);
        return ans;
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int ps,int pe, int is,int ie)
    {
        if(ps>pe||is>ie)
        {
            return NULL;
        }
        TreeNode*curr= new TreeNode(preorder[ps]);
        int index=0;
        for(int i=is;i<=ie;i++)
        {
            if(inorder[i]==preorder[ps])
            {
                index=i;
            }
        }
        int left =index-is;
        curr->left=build( preorder,inorder,ps+1,ps+left,is,index-1);
        curr->right=build( preorder,inorder,ps+left+1,pe,index+1,ie);
        return curr;
    }
};