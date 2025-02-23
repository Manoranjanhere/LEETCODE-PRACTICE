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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        TreeNode *root=nullptr;
        int n = preorder.size();
        if(n==0)return root;
        root=new TreeNode(preorder[0]);
        int ind=find(postorder.begin(),postorder.end(),preorder[0])-postorder.begin();
        vector<pair<int,TreeNode *>> store;
        store.push_back({ind,root});
        for(int i=1;i<n;i++)
        {
            int ele=preorder[i];
            int indpost=find(postorder.begin(),postorder.end(),ele)-postorder.begin();
            int c= store.size()-1;
            while(c>=0)
            {
                if(store[c].first>indpost)
                {
                    if(store[c].second->left==NULL)
                    {
                        store[c].second->left=new TreeNode(ele);
                    }
                    else
                    {
                        store[c].second->right=new TreeNode(ele);
                    }
                    store.push_back({indpost,store[c].second->right?store[c].second->right:store[c].second->left});
                    break;
                }
                else
                {
                    c--;
                }
            }

        }
        return root;

    }
};