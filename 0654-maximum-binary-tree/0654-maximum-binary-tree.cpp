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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<int> st=nums;
	int n = nums.size();
	TreeNode* root = NULL;
	if(n==0)return root;
	sort(st.rbegin(),st.rend());
	unordered_map<int,int> mp;
	for(int i=0;i<n;i++)
	{
		mp[nums[i]]=i;
	}
	for(int i=0;i<n;i++)
	{
		TreeNode* temp=root;
		TreeNode* newnode = new TreeNode(st[i]);
        if(temp==NULL)
        {
            root=newnode;
            continue;
        }
		while(temp!=NULL)
		{
			if(mp[temp->val]>mp[st[i]])
			{
				if(temp->left==NULL)
				{
				temp->left=newnode;
				break;
				}			
				temp=temp->left;
			}
			else
			{
				if(temp->right==NULL)
				{
				temp->right=newnode;
				break;
				}
				temp=temp->right;
			}
		}
	}
	return root;
    }
};	