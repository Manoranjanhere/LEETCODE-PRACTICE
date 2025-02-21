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
class FindElements {
public:
    unordered_set<int> mp;
    FindElements(TreeNode* root) {
        if(root==NULL)
        {
            return;
        }
        root->val=0;
        stack<TreeNode*> st;
        st.push(root);
        mp.insert(0);
        while(!st.empty())
        {
            TreeNode *node = st.top();
            st.pop();
            if(node->left)
            {
                int k = 2*node->val+1;
                node->left->val=k;
                mp.insert(k);
                st.push(node->left);
            }
            if(node->right)
            {
                int k = 2*node->val+2;
                node->right->val=k;
                mp.insert(k);
                st.push(node->right);
            }
        }
    }
    
    bool find(int target) {
        if(mp.find(target)!=mp.end())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */